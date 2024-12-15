number = [1,2,3]

'''
배열 전용 함수들
number.append()
number.insert
extend([])
pop(index)
remove(x)
clear()
count(x)
index(x)
sort()
'''

print(20 in number)

print(1 in number)

if(2 in number) :
    print("asdfasdf")

sum = 0
for i in number:
    sum += i

print(f"Avg = {sum/len(number)}")

food = {'춘천':'닭갈비','횡성':'한우','부산':'밀면','전주':'비빔밥'}
print(food['부산'])
print(food)
del food['부산']
print(food)

'''
get(key, value=None)
pop(key)
keys()
values()
items()
update(d)
clear()
'''

menus = {'커피':3000,'유자차':3500}
menus.update({'아메리카노':3000})

for key,item in menus.items():
    print(f"{key}:{item}")

print(menus.get('커피'))
print('커피' in menus)

'''
입출력 관련 내장함수: input(),print()
자료형 관련 내장함수: type(), str(), int(), float(), complex(), bool()
리스트 관련 내장함수: len(), sorted(), sum(),max(),min()
반복문 관련 내장함수: range()
'''

import math

print(math.log(4))
print(math.pow(2,100))
print(math.sqrt(160))

import random

print(random.random())
print(random.randint(0,9))  ## 0이상 9이하
print(random.randrange(9)) ## 0이상 9미만
print(random.sample(range(0,10),10)) ## 난수 sample 생성기

import datetime

tdy = datetime.datetime.now()
print(f"{tdy.year}년 {tdy.month}월 {tdy.day}일")

'''
from google.colab import files
files.upload()
files.download()
'''

'''
f = open(경로,모드)
f.close()
f.write('hello')
f.writelines(strList)

data = f.read()
line = f.readline()
lines = f.readlines()
'''

f = open('temp.txt','r',encoding='utf-8')
lines = f.readlines()
for line in lines:
    print(line)
f.close()

import csv

f = open("학생정보.csv",'r',encoding='utf-8')
rdr = csv.reader(f)
for line in rdr:
    print(line)
f.close()

from urllib.request import urlopen
from bs4 import BeautifulSoup as bs

url = 'https://www.naver.com/'
htmlData = urlopen(url).read()
htmlData = htmlData.decode()
print(type(htmlData))

## ac_banner_a > img.alt 를 얻어야함

html = bs(htmlData,'html.parser')
img = html.select(".blind")
print(img)

import pandas as pd

itk = ['1월','2월','3월','4월','5월','6월']
it = [4.1,5.5,9.0,15.0,19.0,21.3]
sr = pd.Series(it,index = itk)
print(setattr)










