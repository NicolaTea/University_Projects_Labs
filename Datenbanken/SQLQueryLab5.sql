--CREATE TABLE Ta(
--	idA INT PRIMARY KEY,
--	a2 INT UNIQUE,
--	a3 INT
--);

--CREATE TABLE Tb(
--	idB INT PRIMARY KEY,
--	b2 INT,
--	b3 INT
--);

--CREATE TABLE Tc(
--	idC INT PRIMARY KEY,
--	idA INT,
--	idB INT,
--	FOREIGN KEY (idA) REFERENCES Ta(idA),
--	FOREIGN KEY (idB) REFERENCES Tb(idB)
--);

--ubung1
CREATE OR ALTER PROCEDURE sp_InsertTables
AS
BEGIN
	DECLARE @counter INT;
	SET @counter=1;
	--pt tabela Ta
	WHILE @counter<=10000
	BEGIN
		INSERT INTO Ta(idA,a2,a3)
		VALUES(@counter,@counter+10000,FLOOR(RAND()*1000));
		SET @counter=@counter+1;
	END;
	--pt tabela Tb
	SET @counter=1;
	WHILE @counter<=3000
	BEGIN
		INSERT INTO Tb (idB, b2, b3)
        VALUES (@counter, @counter*3, @counter*4);
        SET @counter = @counter + 1;
	END;
	--pt tabela Tc
	SET @counter = 1;
	WHILE @counter <= 30000
    BEGIN
        DECLARE @idA INT, @idB INT;
		SELECT TOP 1 @idA = idA FROM Ta ORDER BY NEWID();
        SELECT TOP 1 @idB = idB FROM Tb ORDER BY NEWID();
		INSERT INTO Tc (idC, idA, idB)
        VALUES (@counter, @idA, @idB);
		SET @counter = @counter + 1;
	END;
END;

--DELETE FROM Tc;
--DELETE FROM Tb;
--DELETE FROM Ta;
--exec sp_InsertTables;
--SELECT COUNT(*) From Ta;
--SELECT COUNT(*) From Tb;
--SELECT COUNT(*) From Tc;
--SELECT * FROM Ta;
--SELECT * FROM Tb;
--SELECT * FROM Tc;

--ubung2
--a)
SELECT * 
FROM sys.indexes 
WHERE object_id = OBJECT_ID('Ta');
--Clustered Index Scan
SELECT idA, a2 
FROM Ta 
WHERE a3 BETWEEN 100 AND 500;

--Clustered Index Seek
SELECT idA, a2, a3 
FROM Ta 
WHERE idA >= 500 AND idA <= 1000;

--NonClustered Index Scan
--CREATE NONCLUSTERED INDEX idx_a3 ON Ta(a3);
--DROP INDEX idx_a3 ON Ta;
SELECT a2
FROM Ta
WHERE a2+1 > 10;

--NonClustered Index Seek
SELECT idA, a2 
FROM Ta 
WHERE a2 = 10003;

--b)
--CREATE NONCLUSTERED INDEX idx_a2 ON Ta(a2);
--DROP index idx_a2 ON Ta;
SELECT idA,a3
FROM Ta
WHERE a2=10020;

--c)
SELECT * FROM sys.indexes WHERE object_id = OBJECT_ID('Tb');
--CREATE NONCLUSTERED INDEX idx_b2 on Tb(b2);
--DROP INDEX idx_b2 on Tb;
SELECT idB, b2 
FROM Tb 
WHERE b2 = 2010;

--d)
SELECT * FROM sys.indexes WHERE object_id = OBJECT_ID('Tc');
SELECT Tc.idC, Ta.a2 
FROM Tc 
INNER JOIN Ta ON Tc.idA = Ta.idA
WHERE Tc.idA = 999;

SELECT Tc.idC, Tb.b2 
FROM Tc 
INNER JOIN Tb ON Tc.idB = Tb.idB
WHERE Tb.idB = 300;

--CREATE NONCLUSTERED INDEX idx_Tc_idA ON Tc(idA);
--CREATE NONCLUSTERED INDEX idx_Tc_idB ON Tc(idB);
--DROP INDEX idx_Tc_idA on Tc;
--DROP INDEX idx_Tc_idB on Tc;

