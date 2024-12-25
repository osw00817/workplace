const add = (a=1,b=2) => a+b;
const square = x => x*x;

console.log(add());
console.log(square(2));

const {name,age} = {name:"jane",age:5};
console.log(name,age);

const sum = (...numbers) => numbers.reduce((acc,num) => acc + num,0);
console.log(sum(1,2,3,4));

class Person {
    constructor(name,age) {
        this.name = name;
        this.age = age;
    }

    greet() {
        return `Hi, I'm ${this.name}`;
    }
}

const person = new Person("jane",25);
console.log(person.greet());

import {hi} from './module.js';
console.log(hi(1,2));

const fetchData = () => new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve("data fetched");
    }, 1000);
})

fetchData()
.then(data => console.log(data))
.catch(err => console.log(err));

const fetch = async() => {
    const data = await new Promise(resolve => setTimeout(() => resolve("data fetched!"),1000));
    console.log(data);
}

fetch();

const sym1 = Symbol("id");
const sym2 = Symbol("id");

console.log(sym1,sym2,sym1==sym2,sym1===sym2)

const map = new Map();
map.set("key","value");
map.set({obj:true},"object value");
console.log(map.get("key"));
console.log(map.size);
console.log(map);

const set = new Set([1,2,3,3,3,4,4,4,5]);
console.log(set);
set.add(6);
console.log(set.has(3));

const array = [10,20,30];
for(const val of array) {
    console.log(val);
}

function* generateNumbers() {
    yield 1;
    yield 2;
    return 3;
}

const generator = generateNumbers();
console.log(generator.next());
console.log(generator.next());
console.log(generator.next());
console.log(generator.next());

// proxy,reflect 쓸때있을때 쓰는걸로..

const promises = [Promise.resolve("Success"),Promise.reject("Error")];
Promise.allSettled(promises).then(results => console.log(results));