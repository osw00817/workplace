# Mysql

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

연산자 우선순위 AND > OR

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

WHERE A NOT IN (1,2,3,4,5,6,7,8,9)







