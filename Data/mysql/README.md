# Mysql
메타코드 강의 수강중
---

## DataType

### 문자형
- char: 고정길이 문자형
- varchar: 가변길이 문자형
- text: text 데이터 값 (잘 안씀)

### 숫자형(정수형)
- TINYINT
- SMALLINT
- MEDIUMINT
- INT 
- BIGINT

### 숫자형(실수형)
- DECIMAL(n,d)
    - n : 전체 자릿수
    - d : 소숫점 뒷자리수
    - DECIMAL(4,1): -999.9 ~ 999.9

### 날짜형
- DATE : YYYY-MM-DD
- DATETIME : YYYY-MM-DD HH:MM:SS
- TIME : HH:MM:SS
- YEAR : YYYY

---

## DATABASE

CREATE DATABASE 디비이름
DROP DATABASE 디비이름

CREATE TABLE 테이블이름 (
    컬럼명 데이터타입 옵션(EX: NOT NULL),
    컬렴명 데이터타입 옵션,
);

- INSERT INTO 테이블이름 (컬럼명1,컬럼명2,컬럼명3) VALUES (DATA1,DATA2,DATA3);

- DELETE : 데이터 삭제
    - DELETE FROM 테이블이름 WHERE

- TRUNCATE : 테이블 초기화

- UPDATE : 테이블 내용 변경
    - UPDATE 테이블 이름 SET 컬럼명1 = DATA1,컬렴명2 = DATA2 WHERE 조건~~;

- ALTER : TABLE의 내용 외적인 부분 변경
    - ALTER TABLE 테이블이름 rename 새로운이름;
    - ALTER TABLE 테이블이름 ADD 컬럼명 타입;
    - ALTER TABLE 테이블이름 MODIFY 컬려명 타입;
    - ALTER TABLE 테이블이름 CHANGE 기존컬럼명 새컬럼명 데이터타입;
    - ALTER TABLE 테이블이름 DROP 컬럼명;

- SELECT * FROM 'customers'

## 연산자

### 비교 연산자: = > <

- where (조건)

where height = 170 
where height >= 180
where height < 190

### 논리연산자: AND OR NOT

- 연산자 우선순위 AND > OR

WHERE A = 17 AND B = 17
WHERE A = 18 OR A = 19
WHERE NOT A = 17;

### LIKE/BETWEEN/NNOT BETWEEN

WHERE A LIKE "%CARS%" 
WHERE A LIKE "%CARS"
WHERE A LIKE "CARS%"

WHERE A BETWEEN 10 AND 20
WHERE A >= 10 and A <= 20
WHERE A NOT BETWEEN 10 AND 20

### IN/NOT IN/IS NULL

WHERE orderdate IN ('2003-02-11','2003-02-17')
WHERE a IN (1,2,3,4,5,6,7,8,9)

WHERE A NOT IN (1,2,3)
HWERE A <> 1 AND A <> 2 AND A <> 3
<> : NOT

WHERE A IS NULL
WHERE A IS NOT NULL

### ORDER BY

- 기본 오름차순 ASC 
- 내림차순으로 정렬하려면 DESC

ORDER BY 컬럼명1 DESC, 컬렴명2 ASC, ...
(오름차순 생략가능)

ORDER BY A
ORDER BY A DESC

ORDERBY A DESC, B ASC
A 먼저 내림차순 정렬 후 같은 B에 한하여 ASC 정렬

### GROUP BY

- 한개 이상의 컬럼을 기준으로 결과를 그룹화
- SUM, AVG, COUNT, MAX, MIN

SELECT SUM(컬럼명) , AVG(컬럼명) FROM 테이블 GROUP BY 그룹 칼럼

select * from customers;
select city, avg(creditLimit) as averageCreditLimit 
from customers 
group by city 
order by averageCreditLimit desc
limit 5;

### HAVING

- 그룹화 조건 확인
- 항상 group by 뒤에 위치하며 group by 이후 그룹화 된 테이블에 조건 적용

select 컬럼
from 테이블
where 조건
group by 조건
having 조건
order by 조건

### IF / CASE

- IF (condition, value_if_true, value_if_false)

SELECT checkNumber, amount IF(amount > 50000, 'Large', 'Small') AS orderSize 
From payments

CASE 
when value1 THEN result1
when value2 Then result2
...
ELSE result
END AS ~

SELECT productName, buyPrice,
CASE
WHEN buyPirce < 20 THEN 'Cheap'
WHEN buyPirce BETWEEN 20 AND 50
THEN 'Moderate'
ELSE 'Expensive'
END AS priceCatergory
FROM products;

SELECT firstName, lastName, jobTitle,
CASE jobTitle
when '홍길동' then '홍동길'
when '홍동동' then '홍길동'
ELSE '홍길길'
END AS NAME
FROM employees;

### JOIN

- SELECT * FROM TABLE A JOIN B ON 조건 ~

ex3 
id,name,age
ex4
id,region

SELECT * FROM ex3 JOIN ex4 ON ex3.id = ex4.id;

#### LEFT JOIN

SELECT * FROM ex3 LEFT JOIN ex4 ON ex3.id = ex4.id;

SELECT * FROM ex3 LEFT JOIN ex4 ON ex3.id = ex4.id WHERE ex4.id IS null;

#### RIGHT JOIN

SELECT * FROM ex3 RIGHT JOIN ex4 ON ex3.id = ex4.id;

SELECT * FROM ex3 RIGHT JOIN ex4 ON ex3.id = ex4.id WHERE ex3.id IS   NULL;

#### INNER JOIN

SELECT * FROM ex3 join ex4 ib ex3.id = ex4.id

### UNION

- 두 테이블의 데이터를 ㅔㅅ로로 쭉 나열하는 역할
- 컬럼 수가 같아야 하며, 중복은 제거 된다.

SELECT id FROM ex3 
UNION
SELECT id FROM ex4;

SELECT id FROM ex3
UNION ALL
SELECT id FROM ex4;

- FULL OUTER JOIN

SELECT ex3.id, ex3.name, ex3.age, ex4.id, ex4.region
FROM ex3
LEFT JOIN ex4 ON ex3.id = ex4.id
union
SELECT ex3.id, ex3.name, ex3.age, ex4.,id, ex4.region 
FROM ex3
RIGHT JOIN ex4 ON ex3.id = ex4.id
WHERE ex3.id IS NULL;

## WINDOW 함수

### SELECT 구문에서 사용되며 분석 구간을 변동시키는 역할

- SUM(과학점수) OVER(PARTITION BY 반 ORDER BY 출석번호) AS 새컬럼명
GROUP BY와 비슷하지만, 함축적으로 나오지않고 그대로 테이블이 나옴.

- EX 누적합
SELECT customernumber, paymentdate, amout,
sum(amount) OVER(PARTITION BY CUSTOMERNUMBER ORDER BY PAYMENTDATE) AS total_amount FROM payments;






























