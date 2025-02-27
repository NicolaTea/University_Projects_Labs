--1 suma totala clienti intre perioada precizata+ cheltuiala>100
SELECT C.FirstName,C.LastName, SUM(O.OrderTotal) AS 'Total'
FROM Client C
JOIN [Order] O ON C.ClientID=O.clientid
WHERE O.OrderDate BETWEEN '2024-04-04'AND '2024-10-10'
GROUP BY C.FirstName,C.LastName
HAVING SUM(O.OrderTotal)>100.00;

--2  cantitate vanduta per joc
--daca foloseam inner join erau ascunse jocurile nevandute 
SELECT G.Title, SUM(OGD.Quantity) AS 'TotalSoldQuantity'
FROM GAME G
LEFT JOIN Order_Game_Details OGD ON G.GameID = OGD.gameid
GROUP BY G.Title;

--3 metodele de plata care au suma mai mare decat toate platile efectuate cu cardul
SELECT DISTINCT P.payment_method
FROM Payment P
WHERE P.total_payment > ALL (SELECT P2.total_payment FROM Payment P2 WHERE P2.payment_method = 'card' )
AND P.payment_method NOT LIKE 'Pending';

--4 platformele cu pret total de comenzi mai mari de 60
SELECT DISTINCT  P.PlatformName
FROM Platform P
JOIN Game_Platform GP ON P.PlatformID=GP.platformid
JOIN GAME G ON GP.gameid=G.GameID
JOIN  Order_Game_Details OGD ON G.GameID=OGD.gameid
WHERE OGD.UnitPrice*OGD.Quantity>60;

--5 nr comenzi+cantitea comandata pt fiecare client cu minim 3 comenzi
SELECT C.FirstName, C.LastName, COUNT(O.OrderID) AS 'NrOrder', SUM(OGD.Quantity) AS 'TotalSoldQuantity'
FROM CLIENT C
JOIN [ORDER] O ON C.ClientID = O.clientid
JOIN Order_Game_Details OGD ON O.OrderID = OGD.orderid
GROUP BY C.FirstName, C.LastName
HAVING COUNT(O.OrderID) >= 3;

--6 nume publisher care au publicat si joc si dlc
SELECT P.NamePublisher
FROM Publisher P
JOIN GAME G ON P.PublisherID=G.publisherid
INTERSECT
SELECT P.NamePublisher
FROM Publisher P
JOIN GAME G ON P.PublisherID=G.publisherid
JOIN DLC D ON G.GameID=D.gameid;

--7 jocuri care sunt in promotie sau au stocul <40
SELECT G.Title
FROM Game G
JOIN Game_Promotion GP ON G.GameID=GP.gameid
WHERE GP.IsActive=1
UNION
SELECT G.TITLE
FROM GAME G
WHERE G.Stock<40;

--8 jocurile care nu au promotie
SELECT G.Title
FROM Game G
EXCEPT
SELECT G.Title
FROM Game G
JOIN Game_Promotion GP ON G.GameID=GP.gameid
WHERE GP.IsActive=1;

--9 jocurile favorite care au rating >=7.5
SELECT G.Title
FROM Game G
WHERE G.GameID = ANY (SELECT F.gameid FROM Favorite_Game_List F JOIN Review R ON F.gameid = R.gameid WHERE R.Rating >= 7.5);

--10 top 5 jocuri cu cele mai multe comenzi sau pretul peste 50
SELECT TOP 5 G.Title, SUM(OGD.Quantity) AS 'TotalQuantity'
FROM Game G
JOIN Order_Game_Details OGD ON G.GameID = OGD.gameid
GROUP BY G.Title
HAVING SUM(OGD.Quantity) >= 3 OR MAX(OGD.UnitPrice) > 50  
ORDER BY SUM(OGD.Quantity) DESC;

--11 clienti cu comenzi >85.50 + jocuri sub 28 fara promotie
SELECT  C.FirstName, G.Title
FROM Client C
JOIN [Order] O ON C.ClientID = O.clientid
JOIN Order_Game_Details OGD ON O.OrderID = OGD.orderid
JOIN Game G ON OGD.gameid = G.GameID
WHERE C.ClientID IN (SELECT O.clientid FROM [Order] O WHERE O.OrderTotal > 85.50)
AND G.Price < 28.00 
AND G.GameID NOT IN (SELECT GP.gameid FROM Game_Promotion GP WHERE GP.IsActive = 1);

--12 rating maxim joc+stoc mic, rating maxim per joc
SELECT G.Title, MAX(R.Rating) AS 'MaxRating', G.Stock
FROM GAME G
JOIN REVIEW R ON G.GameID = R.gameid
WHERE R.Rating > 8 AND G.Stock < 50
GROUP BY G.Title, G.Stock;