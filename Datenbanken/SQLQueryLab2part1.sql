CREATE TABLE Promotion(
    PromoID INT PRIMARY KEY,
	Description_promo VARCHAR(50),
	Discount DECIMAL(18,2),
	Date_begin DATE,
	Date_end DATE

);


CREATE TABLE Game_Promotion(
	gameid INT,
	promoid INT,
	PRIMARY KEY(gameid,promoid),
	FOREIGN KEY(gameid) REFERENCES Game(GameID),
	FOREIGN KEY(promoid) REFERENCES Promotion(PromoID)

);

INSERT INTO Publisher
VALUES(14,'Tarsier Studios','Sweden'),
(15,'ConcernedApe','USA'),
(16,'Kojima','Japan'),
(17,'Hello Games','UK');

INSERT INTO Game
VALUES 
(18,'Little Nighmares',1,19.99,300,14),
(19,'Stardew Valley',6,13.99,10,15),
(20,'Death Stranding',8,10,49.99,16),
(21,'No Man Sky',8,15,12.78,17),
(22,'Sea of Thieves',8,13,10.00,3);

Insert INTO DLC
VALUES 
(8,18,'The Residence',3.99,'2018-02-23'),
(9,18,'The Depths',3.99,'2017-07-07'),
(10,18,'The Hideaway',3.99,'2017-11-10');

INSERT INTO Promotion
VALUES (1,'Winter Sale',15.00,'2024-12-01','2024-12-31'),
(2,'Spring Breakthrough',10.00,'2024-03-01','2024-04-04'),
(3,'Summer Sale',12.00,'2024-06-01','2024'),
(4,'Autumn Time',16.00,'2024-09-09','2024-10-10'),
(5,'Halloween Freak',30.00,'2024-10-29','2024-11-02'),
(6,'Black Friday',50.00,'2024-11-11','2024-12-12');

Alter Table Game_Promotion
ADD IsActive BIT;

INSERT INTO GAME_PROMOTION 
VALUES 
(1,1,1),
(2, 2,0),
(1,3,1),
(16,4,0);

--DELETE
DELETE FROM Game_Promotion
WHERE IsActive=0;


INSERT INTO Client
VALUES
(13,'Vasile','Radu','v.radu@telero.com',NULL),
(14,'Andi','Georgescu','andrei.georgescu@gmail.com','0723456789'),
(15,'Elena','Lungu','e.lungu@yahoo.com','0756789012'),
(16,'Andra','Mihai','	a.mihai@telero.com','0767890123');

DELETE FROM CLIENT
WHERE Email LIKE '%@telero.com';

DELETE FROM [Order]
WHERE OrderDate BETWEEN '2023-01-01' AND '2023-01-04'
AND OrderTotal IS NOT NULL;

DELETE FROM Publisher
WHERE Country IN ('South Korea', 'China');



--SELECT
SELECT NamePublisher
FROM Publisher
WHERE Country LIKE 'S%';

SELECT Game.Title
FROM Game,Genre
WHERE Game.GameID=Genre.GenreID AND Game.genreid IN (1,2);

SELECT NameDLC
FROM DLC
WHERE Price BETWEEN 10.00 AND 30.00;

SELECT FirstName,LastName
FROM Client
WHERE Email LIKE '%@gmail.com';

SELECT FirstName,LastName
FROM Client
WHERE Phone IS NULL;


--UPDATE
UPDATE Game
SET Price=30.67
WHERE Stock<20 AND genreid=8;

UPDATE Payment
SET payment_method = 'Pending'
WHERE payment_method LIKE 'b%';

UPDATE GAME
SET Stock = Stock - 5
WHERE Stock BETWEEN 80 AND 100;

UPDATE CLIENT
SET Phone = '+40000000000'
WHERE Phone IS NULL;


--nu exista orderid pt a adauga aceasta comanda la details
INSERT INTO Order_Game_Details(orderid,gameid,Quantity,UnitPrice)
VALUES('1abjxe',45,3,38.99);
