--1--
--ADDCOLUMN
CREATE OR ALTER PROCEDURE addcolumn
(
	@tableName NVARCHAR(50),
    @columnName NVARCHAR(50),
	@type NVARCHAR(50)
   
)
AS
BEGIN
    DECLARE @query  AS NVARCHAR(MAX);
    SET @query = 'ALTER TABLE ' + @tableName + ' ADD ' + @columnName + ' ' + @type;
	PRINT 'Execute the following query: ' + @query;
    EXEC sp_executesql @query;
	
	
	
END;

CREATE OR ALTER PROCEDURE rollbackaddcolumn(
	@tableName NVARCHAR(50),
	@columnName NVARCHAR(50),
	@type NVARCHAR(50)
	
	
	

)
AS
BEGIN
	DECLARE @query NVARCHAR(MAX);
	SET @query=' ALTER TABLE ' + @tableName+ ' DROP COLUMN '+ @columnName;
	PRINT 'Execute the following query: ' + @query;
    EXEC sp_executesql @query;
END;

EXEC addcolumn @tableName='[ORDER]', @columnName='DiscountApplied', @type='BIT';
EXEC rollbackaddcolumn @tableName='[ORDER]', @columnName='DiscountApplied',@type='BIT';

--ADDFOREIGNKEY
CREATE OR ALTER PROCEDURE addforeignkey
(
	@tableName NVARCHAR(50),
    @columnName NVARCHAR(50),
	@tableReferences NVARCHAR(50),
	@columnReferences NVARCHAR(50)
   
)
AS
BEGIN
	 DECLARE @ConstraintName NVARCHAR(50);
    DECLARE @query NVARCHAR(MAX);
	SET @ConstraintName = 'FK_' + @tableName + '_' + @tableReferences;
    SET @query = 'ALTER TABLE ' + @tableName + 
                 ' ADD CONSTRAINT ' + @ConstraintName + 
                 ' FOREIGN KEY (' + @columnName + ') REFERENCES ' + @tableReferences + '(' + @columnReferences + ')';

    PRINT 'Execute the following query: ' + @query;
    EXEC sp_executesql @query;
	
	
	
END;

CREATE OR ALTER PROCEDURE rollbackaddforeignkey(
	@tableName NVARCHAR(50),
	@columnName NVARCHAR(50),
	@tableReferences NVARCHAR(50),
	@columnReferences NVARCHAR(50)
	
)
AS
BEGIN
	DECLARE @ConstraintName NVARCHAR(50);
	DECLARE @query NVARCHAR(MAX);
	SET @ConstraintName = 'FK_' + @tableName + '_' + @tableReferences
	SET @query=' ALTER TABLE ' + @tableName + ' DROP CONSTRAINT '+ @constraintName;
	PRINT 'Execute the following query: ' + @query;
	EXEC sp_executesql @query;
END;

EXEC addforeignkey @tableName='GAME', @columnName='genreid', @tableReferences='GENRE',@columnReferences='GenreID';
EXEC rollbackaddforeignkey @tableName='GAME', @columnName='genreid', @tableReferences='GENRE',@columnReferences='GenreID';

--CREATETABLE
CREATE OR ALTER PROCEDURE createtable
(
	@tableName NVARCHAR(50),
    @columnName NVARCHAR(MAX)
   
)
AS
BEGIN
    DECLARE @query AS NVARCHAR(MAX);
    SET @query = 'CREATE TABLE ' + @tableName + ' (' + @columnName + ')';
	PRINT 'Execute the following query: ' + @query;
    EXEC sp_executesql @query;
END;

CREATE OR ALTER PROCEDURE rollbackcreatetable(
	@tableName NVARCHAR(50),
	@columnName NVARCHAR(MAX)
	
	

)
AS
BEGIN
	DECLARE @query NVARCHAR(MAX);
	SET @query=' DROP TABLE ' + @tableName;
	PRINT 'Execute the following query: ' + @query;
    EXEC sp_executesql @query;
END;

EXEC createtable @tableName='Discounts', @columnName='DiscountID INT PRIMARY KEY, DiscountName VARCHAR(100)';
EXEC rollbackcreatetable  @tableName='Discounts', @columnName='DiscountID INT PRIMARY KEY, DiscountName VARCHAR(100)';

--DEFAULTCONSTRAINT
CREATE OR ALTER PROCEDURE defaultconstraint
(
	@tableName NVARCHAR(50),
    @columnName NVARCHAR(50),
    @implicitValue NVARCHAR(50)
)
AS
BEGIN
    DECLARE @query AS NVARCHAR(MAX);
    SET @query = 'ALTER TABLE ' + @tableName + 
                 ' ADD CONSTRAINT DF_' + @tableName + '_' + @columnName+
                 ' DEFAULT ' + @implicitValue + ' FOR ' + @columnName;
	PRINT 'Execute the following query: ' + @query;
    EXEC sp_executesql @query;
	
	

END;

CREATE OR ALTER PROCEDURE rollbackdefaultconstraint(
	@tableName  NVARCHAR(50),
	@columnName  NVARCHAR(50),
	@implicitValue NVARCHAR(50)
	

)
AS
BEGIN
	DECLARE @query  AS NVARCHAR(MAX);
	SET @query=' ALTER TABLE ' + @tableName + 
                 ' DROP CONSTRAINT DF_' + @tableName + '_' + @columnName;
	PRINT 'Execute the following query: ' + @query;
    EXEC sp_executesql @query;
END;

EXEC defaultconstraint @tableName='GAME', @columnName='Price', @implicitValue='10';
EXEC rollbackdefaultconstraint @tableName='GAME', @columnName='Price', @implicitValue='10';

--MODIFYTYPECOLUMN
CREATE OR ALTER PROCEDURE modifytypecolumn
(
		@tableName  NVARCHAR(50),
		@columnName NVARCHAR(50),
		@newType  NVARCHAR(50),
		@oldType NVARCHAR(50)
)
AS
BEGIN
	DECLARE @query AS NVARCHAR(MAX);
	SET @query=' ALTER TABLE ' + @tableName + 
                 ' ALTER COLUMN ' + @columnName + ' ' + @newType;
	PRINT 'Execute the following query: ' + @query;
	EXEC sp_executesql @query;
	

END;

CREATE OR ALTER PROCEDURE rollbackmodifytypecolumn(
	@tableName  NVARCHAR(50),
	@columnName  NVARCHAR(50),
	@newType NVARCHAR(50),
	@oldType  NVARCHAR(50)

)
AS
BEGIN
	DECLARE @query  NVARCHAR(MAX);
	SET @query=' ALTER TABLE '+ @tableName + ' ALTER COLUMN '+ @columnName+ ' '+ @oldType;
	PRINT 'Execute the following query: ' + @query;
	EXEC sp_executesql @query;

END;

EXEC modifytypecolumn @tableName='GAME', @columnName='Price', @newType='float', @oldType='int';
EXEC rollbackmodifytypecolumn @tableName='GAME', @columnName='Price', @newType='float', @oldType='int';

--2--
--CREATE TABLE CurrentVersion(
--	VersionNumber INT PRIMARY KEY
--);

--CREATE TABLE VersionHistory(
--	VersionNumber INT PRIMARY KEY,
--	ProcedureName VARCHAR(250),	
--	ProcedureParameters VARCHAR(250)
--);

--INSERT INTO CurrentVersion 
--VALUES(0);

UPDATE CurrentVersion
SET VersionNumber=0;



CREATE OR ALTER PROCEDURE UpdateVersion
    @ProcedureName NVARCHAR(255),
    @ProcedureParameters NVARCHAR(MAX)
AS
BEGIN
    DECLARE @currentVersion INT;

    SELECT @currentVersion = VersionNumber FROM CurrentVersion;

    SET @currentVersion = @currentVersion + 1;
	UPDATE CurrentVersion SET VersionNumber = @currentVersion;
	INSERT INTO VersionHistory (VersionNumber, ProcedureName, ProcedureParameters)
    VALUES (@currentVersion, @ProcedureName, @ProcedureParameters);

    
END;

------------------------------------
CREATE OR ALTER PROCEDURE UpdateToVersion
    @TargetVersion INT
AS
BEGIN
    DECLARE @CurrentVersion INT;
    
   
    SELECT @CurrentVersion = VersionNumber FROM CurrentVersion;

   
    IF @CurrentVersion > @TargetVersion
    BEGIN
        DECLARE @VersionToRollback INT = @CurrentVersion;
        
        
        WHILE @VersionToRollback > @TargetVersion
        BEGIN
          
            DECLARE @ProcedureName NVARCHAR(100);
            DECLARE @ProcedureParameters NVARCHAR(MAX);
            
            SELECT @ProcedureName = ProcedureName, @ProcedureParameters = ProcedureParameters
            FROM VersionHistory
            WHERE VersionNumber = @VersionToRollback;

            
            DECLARE @RollbackQuery NVARCHAR(MAX) = 'EXEC rollback' + @ProcedureName + ' ' + @ProcedureParameters;
            EXEC sp_executesql @RollbackQuery;

            
            SET @VersionToRollback = @VersionToRollback - 1;
        END
    END

    
    ELSE IF @CurrentVersion < @TargetVersion
    BEGIN
        DECLARE @VersionToApply INT = @CurrentVersion + 1;
        
        
        WHILE @VersionToApply <= @TargetVersion
        BEGIN
            
            DECLARE @ProcedureName1 NVARCHAR(100);
            DECLARE @ProcedureParameters1 NVARCHAR(MAX);
            
            SELECT @ProcedureName1 = ProcedureName, @ProcedureParameters1 = ProcedureParameters
            FROM VersionHistory
            WHERE VersionNumber = @VersionToApply;

            
            DECLARE @ApplyQuery NVARCHAR(MAX) = 'EXEC ' + @ProcedureName1 + ' ' + @ProcedureParameters1;
            EXEC sp_executesql @ApplyQuery;

            
            SET @VersionToApply = @VersionToApply + 1;
        END
    END

    
    UPDATE CurrentVersion SET VersionNumber = @TargetVersion;

    PRINT 'The DataBase is at version ' + CAST(@TargetVersion AS NVARCHAR(10));
END;




EXEC UpdateVersion 
    @ProcedureName = 'modifytypecolumn', 
    @ProcedureParameters = '@tableName = ''GAME'', @columnName = ''Price'', @newType = ''float'', @oldType = ''int''';


EXEC UpdateVersion 
    @ProcedureName = 'defaultconstraint', 
    @ProcedureParameters = '@tableName = ''GAME'', @columnName = ''Stock'', @implicitValue = ''10''';


EXEC UpdateVersion 
    @ProcedureName = 'createtable', 
    @ProcedureParameters = '@tableName = ''Discounts'', @columnName = ''DiscountID INT PRIMARY KEY, DiscountName VARCHAR(100)''';


EXEC UpdateVersion 
    @ProcedureName = 'addcolumn', 
    @ProcedureParameters = '@tableName = ''[ORDER]'', @columnName = ''DiscountApplied'', @type = ''BIT''';


EXEC UpdateVersion 
    @ProcedureName = 'addforeignkey', 
    @ProcedureParameters = '@tableName = ''GAME'', @columnName = ''genreid'', @tableReferences = ''GENRE'', @columnReferences = ''GenreID''';

EXEC UpdateVersion 
    @ProcedureName = 'createtable', 
    @ProcedureParameters = '@tableName = ''Test3'', @columnName = ''ID INT ''';

EXEC UpdateVersion 
    @ProcedureName = 'addcolumn', 
    @ProcedureParameters = '@tableName = ''Discounts'', @columnName = ''locatie'', @type = ''nvarchar(100)''';



EXEC UpdateToVersion @TargetVersion=7;

select * from CurrentVersion;

select * from VersionHistory;


EXEC UpdateVersion 
    @ProcedureName = 'modifytypecolumn', 
    @ProcedureParameters = '@tableName = ''CLIENT'', @columnName = ''Phone'', @newType = ''varchar(100)'', @oldType = ''varchar(20)''';


EXEC UpdateVersion 
    @ProcedureName = 'defaultconstraint', 
    @ProcedureParameters = '@tableName = ''REVIEW'', @columnName = ''Rating'', @implicitValue = ''5''';


