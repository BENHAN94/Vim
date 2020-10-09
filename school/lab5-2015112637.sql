
-- CHECK WHETHER TABLES EXIST AND DROP IF EXIST

DROP TABLE EMPLOYEE CASCADE CONSTRAINTS;
DROP TABLE DEPARTMENT CASCADE CONSTRAINTS; 
DROP TABLE DEPT_LOCATION CASCADE CONSTRAINTS;
DROP TABLE PROJECT CASCADE CONSTRAINTS;
DROP TABLE WORKS_ON CASCADE CONSTRAINTS;
DROP TABLE DEPENDENT CASCADE CONSTRAINTS;

-- Lab#5-1
-- CREATING TABLES

CREATE TABLE EMPLOYEE( 
	Fname VARCHAR(15) NOT NULL,
	Minit CHAR, 
	Lname VARCHAR(15) NOT NULL,
	Ssn CHAR(9) NOT NULL,
	Bdate DATE,
	Address VARCHAR(30),
	Sex CHAR,
	Salary DECIMAL(10,2),
	Super_ssn CHAR(9),
	Dno NUMBER NOT NULL,
	PRIMARY KEY (Ssn)
);

CREATE TABLE DEPARTMENT(
	Dname VARCHAR(15) NOT NULL,
	Dnumber NUMBER NOT NULL,
	Mgr_ssn CHAR(9) DEFAULT '000000000' NOT NULL,
	Mgr_start_date DATE,
	PRIMARY KEY (Dnumber),
	UNIQUE (Dname)
);

CREATE TABLE DEPT_LOCATION(
	Dnumber NUMBER NOT NULL,
	Dlocation VARCHAR(15) NOT NULL,
	PRIMARY KEY (Dnumber, Dlocation)
);

CREATE TABLE PROJECT(
	Pname VARCHAR(15) NOT NULL,
	Pnumber NUMBER NOT NULL,
	Plocation VARCHAR(15),
	Dnum NUMBER NOT NULL,
	PRIMARY KEY (Pnumber),
	UNIQUE(Pname)
);

CREATE TABLE WORKS_ON(
	Essn CHAR(9) NOT NULL,
	Pno NUMBER NOT NULL,
	Hours DECIMAL(3,1),
	PRIMARY KEY (Essn, Pno)
);

CREATE TABLE DEPENDENT(
	Essn CHAR(9) NOT NULL,
	Dependent_name VARCHAR(15) NOT NULL,
	Sex CHAR,
	Bdate DATE,
	Relationship VARCHAR(8),
	PRIMARY KEY (Essn, Dependent_name)
);

-- Lab#5-2
-- POPULATING TABLES

INSERT INTO EMPLOYEE VALUES(
	'John', 'B', 'Smith', '123456789', to_date('1965-01-09', 'YYYY-MM-DD'), '731 Fondern, Houston, TX', 'M', 30000, '333445555', 5
);

INSERT INTO EMPLOYEE VALUES(
	'Franklin', 'T', 'Wong', '333445555', to_date('1955-12-08', 'YYYY-MM-DD'), '638 Voss, Houston, TX', 'M', 40000, '888665555', 5
);

INSERT INTO EMPLOYEE VALUES(
	'Alicia', 'J', 'Zelaya', '999887777', to_date('1968-01-19', 'YYYY-MM-DD'), '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4
);

INSERT INTO EMPLOYEE VALUES(
	'Jennifer', 'S', 'Wallace', '987654321', to_date('1941-06-20', 'YYYY-MM-DD'), '291 Berry, Bellaire, TX', 'F', 43000, '888665555', 4
);

INSERT INTO EMPLOYEE VALUES(
	'Ramesh', 'K', 'Narayan', '666884444', to_date('1962-09-15', 'YYYY-MM-DD'), '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5
);

INSERT INTO EMPLOYEE VALUES(
	'Joyce', 'A', 'English', '453453453', to_date('1972-07-31', 'YYYY-MM-DD'), '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5
);

INSERT INTO EMPLOYEE VALUES(
	'Ahmad', 'V', 'Jabbar', '987987987', to_date('1969-03-29', 'YYYY-MM-DD'), '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4
);

INSERT INTO EMPLOYEE VALUES(
	'James', 'E', 'Borg', '888665555', to_date('1937-11-10', 'YYYY-MM-DD'), '450 Stone, Houston, TX', 'M', 55000, NULL, 1
);

INSERT INTO DEPARTMENT VALUES(
	'Research', 5, '333445555', to_date('1988-05-22', 'YYYY-MM-DD') 
);

INSERT INTO DEPARTMENT VALUES(
	'Administration', 4, '987654321', to_date('1995-01-01', 'YYYY-MM-DD') 
);

INSERT INTO DEPARTMENT VALUES(
	'Headquarters', 1, '888665555', to_date('1981-06-19', 'YYYY-MM-DD') 
);

INSERT INTO DEPT_LOCATION VALUES(
	1, 'Houston'
);

INSERT INTO DEPT_LOCATION VALUES(
	4, 'Stafford'
);

INSERT INTO DEPT_LOCATION VALUES(
	5, 'Belaire'
);

INSERT INTO DEPT_LOCATION VALUES(
	5, 'Sugarland'
);

INSERT INTO DEPT_LOCATION VALUES(
	5, 'Houston'
);

INSERT INTO WORKS_ON VALUES(
	'123456789', 1, 32.5
);

INSERT INTO WORKS_ON VALUES(
	'123456789', 2, 7.5
);

INSERT INTO WORKS_ON VALUES(
	'666884444', 3, 40.0
);

INSERT INTO WORKS_ON VALUES(
	'453453453', 1, 20.0
);

INSERT INTO WORKS_ON VALUES(
	'453453453', 2, 10.0
);

INSERT INTO WORKS_ON VALUES(
	'333445555', 2, 10.0
);

INSERT INTO WORKS_ON VALUES(
	'333445555', 3, 10.0
);

INSERT INTO WORKS_ON VALUES(
	'333445555', 10, 10.0
);

INSERT INTO WORKS_ON VALUES(
	'333445555', 20, 10.0
);

INSERT INTO WORKS_ON VALUES(
	'999887777', 30, 30.0
);

INSERT INTO WORKS_ON VALUES(
	'999887777', 10, 10.0
);

INSERT INTO WORKS_ON VALUES(
	'987987987', 10, 35.0
);

INSERT INTO WORKS_ON VALUES(
	'987987987', 30, 5.0
);

INSERT INTO WORKS_ON VALUES(
	'987654321', 30, 20.0
);

INSERT INTO WORKS_ON VALUES(
	'987654321', 20, 15.0
);

INSERT INTO WORKS_ON VALUES(
	'888665555', 20, NULL
);

INSERT INTO PROJECT VALUES(
	'ProductX', 1, 'Bellaire', 5
);

INSERT INTO PROJECT VALUES(
	'ProductY', 2, 'Sungarland', 5
);

INSERT INTO PROJECT VALUES(
	'ProductZ', 3, 'Houston', 5
);

INSERT INTO PROJECT VALUES(
	'Computerization', 10, 'Stafford', 4
);

INSERT INTO PROJECT VALUES(
	'Reorganization', 20, 'Houston', 1
);

INSERT INTO PROJECT VALUES(
	'Newbenefits', 30, 'Stafford', 4
);

INSERT INTO DEPENDENT VALUES(
	'333445555', 'Alice', 'F', to_date('1986-04-05', 'YYYY-MM-DD'), 'Daughter'
);

INSERT INTO DEPENDENT VALUES(
	'333445555', 'Theodore', 'M', to_date('1983-10-25', 'YYYY-MM-DD'), 'Son'
);

INSERT INTO DEPENDENT VALUES(
	'333445555', 'Joy', 'F', to_date('1958-05-03', 'YYYY-MM-DD'), 'Spouse'
);

INSERT INTO DEPENDENT VALUES(
	'987654321', 'Abner', 'M', to_date('1942-02-28', 'YYYY-MM-DD'), 'Spouse'
);

INSERT INTO DEPENDENT VALUES(
	'123456789', 'Michael', 'M', to_date('1988-01-04', 'YYYY-MM-DD'), 'Son'
);

INSERT INTO DEPENDENT VALUES(
	'123456789', 'Alice', 'F', to_date('1988-12-30', 'YYYY-MM-DD'), 'Daughter'
);

INSERT INTO DEPENDENT VALUES(
	'123456789', 'Elizabeth', 'F', to_date('1967-05-05', 'YYYY-MM-DD'), 'Spouse'
);

-- Lab#5-1(Cont'd)
-- ADDING CONSTRAINTS (FOREIGN KEYS)

ALTER TABLE DEPARTMENT ADD CONSTRAINT DEP_MANAGER FOREIGN KEY (Mgr_ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE SET NULL;

ALTER TABLE DEPT_LOCATION ADD CONSTRAINT LOC_DEP_NUM FOREIGN KEY (Dnumber) REFERENCES DEPARTMENT(Dnumber) ON DELETE CASCADE;

ALTER TABLE PROJECT ADD CONSTRAINT PRO_DEP_NUM FOREIGN KEY (Dnum) REFERENCES DEPARTMENT(Dnumber) ON DELETE CASCADE; 

ALTER TABLE WORKS_ON ADD CONSTRAINT WORK_EMP FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE;

ALTER TABLE WORKS_ON ADD CONSTRAINT WORK_PRO FOREIGN KEY (Pno) REFERENCES PROJECT(Pnumber) ON DELETE CASCADE;

ALTER TABLE DEPENDENT ADD CONSTRAINT DEPEN_EMP FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE;

COMMIT;

-- Lab #5-3
-- TASKS
-- Q1) Retrieve the first name, initial middle name, last name of all employees in department 5 who earns greater than or equal to 10000 and works on ‘ProductZ’ project and order by their last names in ascending order.

SELECT Fname, Minit, Lname FROM EMPLOYEE, WORKS_ON, PROJECT WHERE Ssn=Essn AND Pno=Pnumber AND Dno=5 AND Salary >= 10000 AND Pname='ProductZ' ORDER BY Lname ASC;

-- Q2) List the department name, ssn, and last name of all employees who are from “Dallas” and works under the manager with his/her Ssn = ‘987654321’.

SELECT Dname, Ssn, Lname FROM EMPLOYEE, DEPARTMENT WHERE Dno=Dnumber AND Address LIKE '%Dallas%' AND Super_ssn='987654321';

-- Q3) Find the last name and working hours of all employees who are working in the project ‘ProductX’ and order by their working hours in descending order.

SELECT Lname, Hours FROM EMPLOYEE, WORKS_ON, PROJECT WHERE Ssn=Essn AND Pno=Pnumber AND Pname='ProductX' ORDER BY Hours DESC;

-- Q4) List the last name(s), first name(s), and working hour(s) of an employee(s) working on Project ‘Computerization’ for greater than or equal to 10 hours in ascending order of their working hours.

SELECT Lname, Fname, Hours FROM EMPLOYEE, WORKS_ON, PROJECT WHERE Ssn=Essn AND Pno=Pnumber AND Pname='Computerization' AND Hours>=10 ORDER BY Hours ASC;


-- Q5) List the first name and relationship(s) of a dependent of a supervisee(s) whose supervisor has Ssn = ‘333445555’;

SELECT Dependent_name, Relationship FROM EMPLOYEE, DEPENDENT WHERE Ssn=Essn AND Super_ssn='333445555';

--Lab #5-4
--D1) Delete the DEPENDENT tuple(s) associated with Essn = ‘333445555’;

DELETE FROM DEPENDENT WHERE Essn='333445555';
ROLLBACK;

--D2) Delete the DEPARTMENT tuples with Dnumber = 5.

DELETE FROM DEPARTMENT WHERE Dnumber=5;
ROLLBACK:

--D3) Delete the WORKS_ON tuples with Pno = 30.

DELETE FROM WORKS_ON WHERE pno=30;
ROLLBACK;

--Lab#5-5 
-- U1) Update to ‘Houston’ the Plocation of the PROJECT tuples with Dnum = 5, respectively.
-- Run ‘select * from PROJECT where Dnum = 5’

UPDATE PROJECT SET Plocation = 'Houston' WHERE Dnum=5;
SELECT * FROM PROJECT WHERE Dnum=5;
ROLLBACK:


-- U2) Update the Super_ssn attribute of the EMPLOYEE tuple with Ssn = ‘123456789’ to null.
-- Run ‘select * from EMPLOYEE where Ssn = ‘123456789’

UPDATE EMPLOYEE SET Super_ssn = NULL WHERE Ssn='123456789';
SELECT * FROM EMPLOYEE WHERE Ssn='123456789';
ROLLBACK;

-- U3) Update the Dname attribute of the DEPARTMENT tuple with Dnumber = 5 to ‘Design’.
-- Run ‘select * from DEPARTMENT where Dnumber = 5’

UPDATE DEPARTMENT SET Dname = 'Design' WHERE Dnumber=5;
SELECT * FROM DEPARTMENT WHERE Dnumber=5;
ROLLBACK;

