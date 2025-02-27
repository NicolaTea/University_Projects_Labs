--Ubung1
CREATE OR ALTER FUNCTION fn_GameNameValid(@Title varchar(100))
RETURNS BIT
AS
BEGIN
	IF LEN(@Title)>=3 AND @Title NOT LIKE '%[^a-zA-Z0-9 _-]%'
		RETURN 1
	RETURN 0
END;


CREATE OR ALTER FUNCTION fn_GamePriceValid(@Price decimal(10,2))
RETURNS BIT
AS
BEGIN
		IF @Price>0 AND @Price BETWEEN 1 AND 300
			RETURN 1
		RETURN 0
END;

CREATE OR ALTER PROCEDURE sp_AddNewGame
	@GameID INT,
	@Title VARCHAR(100),
	@genreid INT,
	@Price DECIMAL(10,2),
	@Stock INT,
	@publisherid INT

AS
BEGIN
	 IF dbo.fn_GameNameValid(@Title)=0
		THROW 50001, 'The name is not valid.',1;

	 IF dbo.fn_GamePriceValid(@Price)=0
		THROW 50002,'The price is not valid',1;
	 
	  INSERT INTO Game(GameID,Title,genreid,Price,Stock,publisherid)
	  VALUES(@GameID,@Title,@genreid,@Price,@Stock,@publisherid);
END;

EXEC sp_AddNewGame @GameID=26,@Title='Dark Souls III',@genreid=9,@Price=59.99,@Stock=34,@publisherid=19;
EXEC sp_AddNewGame @GameID=27,@Title='Call@Duty%Warfare',@genreid=3,@Price=20.89,@Stock=17,@publisherid=6;
EXEC sp_AddNewGame @GameID=28,@Title='Somegamestuff',@genreid=1,@Price=1000,@Stock=16,@publisherid=1;

--Ubung2
CREATE VIEW vw_StockAnalysis
AS
WITH StockPerGenre AS (
	SELECT G.genreid, Gen.GenreName, SUM(G.Stock) AS 'TotalStock'
	FROM Game G
	JOIN Genre Gen ON G.genreid=Gen.GenreID
	GROUP BY G.genreid,Gen.GenreName
)
SELECT * FROM StockPerGenre;


CREATE OR ALTER FUNCTION fn_GameByPrice(@MaxPrice decimal(10,2))
RETURNS TABLE
AS
RETURN 
SELECT G.GameID,G.Title,G.genreid,G.Price,MAX(G.Stock) OVER (PARTITION BY G.genreid) AS MaxStockPerGenre
FROM Game G
WHERE G.Price<=@MaxPrice;

SELECT * FROM vw_StockAnalysis;

SELECT vw_SA.GenreName,  vw_SA.TotalStock, COUNT(fn_GP.GameID) AS 'CheapGame'
FROM vw_StockAnalysis vw_SA
JOIN fn_GameByPrice(49.99) fn_GP ON vw_SA.genreid=fn_GP.genreid 
GROUP BY vw_SA.GenreName, vw_SA.TotalStock;


--Ubung3
CREATE TABLE GameLog(
	LogID INT IDENTITY(1,1) PRIMARY KEY,
	ActionTime DATETIME,
	ActionType CHAR(1),
	TableName VARCHAR(100),
	AffectedRows INT
);

CREATE OR ALTER TRIGGER trg_GameChanges
ON Game
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    DECLARE @actiontype CHAR(1);
    DECLARE @affectedrows INT;
    DECLARE @tablename VARCHAR(100) = 'Game';

    
    IF EXISTS (SELECT 1 FROM INSERTED) AND EXISTS (SELECT 1 FROM DELETED)
        SET @actiontype = 'U';
    ELSE IF EXISTS (SELECT 1 FROM INSERTED)
        SET @actiontype = 'I';
    ELSE
        SET @actiontype = 'D';

    
    SET @affectedrows = 
        CASE 
            WHEN @actiontype = 'U' THEN (SELECT COUNT(*) FROM INSERTED)
            WHEN @actiontype = 'I' THEN (SELECT COUNT(*) FROM INSERTED)
            WHEN @actiontype = 'D' THEN (SELECT COUNT(*) FROM DELETED)
        END;

    
    INSERT INTO GameLog (ActionTime, ActionType, TableName, AffectedRows)
    VALUES (GETDATE(), @actiontype, @tablename, @affectedrows);
END;



INSERT INTO Game(GameID,Title,genreid,Price,Stock,publisherid)
VALUES(27,'Far Cry 6',2,30.78,100,3);
UPDATE Game
SET Price=33.00
WHERE GameID=27
DELETE FROM Game
WHERE GameID=27

SELECT * FROM GameLog

--Ubung4
CREATE OR ALTER PROCEDURE sp_NotifyPriceChange
    @GameID INT,
    @OldPrice DECIMAL(10, 2),
    @NewPrice DECIMAL(10, 2)
AS
BEGIN
    PRINT 'The Price of the Game with the  ID ' + CAST(@GameID AS VARCHAR) + 
          ' was reduced from  ' + CAST(@OldPrice AS VARCHAR) +
          ' to ' + CAST(@NewPrice AS VARCHAR) + '.';
END;


DECLARE @GameID INT;             
DECLARE @OldPrice DECIMAL(10, 2);
DECLARE @NewPrice DECIMAL(10, 2); 
DECLARE @GenreName VARCHAR(50);   
DECLARE @DiscountRate DECIMAL(5, 2); 


DECLARE PriceCursor CURSOR FOR
SELECT G.GameID, G.Price, Ge.GenreName
FROM GAME G
JOIN GENRE Ge ON G.genreid = Ge.GenreID;


OPEN PriceCursor;


FETCH NEXT FROM PriceCursor INTO @GameID, @OldPrice, @GenreName;

WHILE @@FETCH_STATUS = 0
BEGIN
    
    IF @GenreName = 'Indie'
        SET @DiscountRate = 0.10;
    ELSE IF @GenreName = 'Open World'
        SET @DiscountRate = 0.15;
    ELSE IF @GenreName = 'soulsborne'
        SET @DiscountRate = 0.05;
    ELSE
        SET @DiscountRate = 0.02;
	SET @NewPrice = @OldPrice * (1 - @DiscountRate);
	UPDATE GAME
    SET Price = @NewPrice
    WHERE GameID = @GameID;
	EXEC sp_NotifyPriceChange @GameID, @OldPrice, @NewPrice;
	FETCH NEXT FROM PriceCursor INTO @GameID, @OldPrice, @GenreName;
END;

CLOSE PriceCursor;
DEALLOCATE PriceCursor;



