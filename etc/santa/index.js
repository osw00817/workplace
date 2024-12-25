// === 크리스마스 마을 시뮬레이션 구현 목표 ===

// 1. Santa 클래스
// - 속성:
//   - name: 산타의 이름.
//   - sled: 연결된 썰매 객체.
//   - energy: 산타의 체력 (기본값 100).
//   - location: 산타의 현재 위치 {x, y}.
// - 메서드:
//   - deliverGift(house): 선물을 특정 집에 배달하고 sled의 적재량 감소.
//   - rest(): 체력을 100으로 회복.

// 2. Elf 클래스
// - 속성:
//   - name: 엘프 이름.
//   - workSpeed: 선물 제작 속도.
//   - giftStock: 현재 제작된 선물의 수.
// - 메서드:
//   - makeGift(): 선물 1개 제작 후 giftStock 증가.

// 3. House 클래스
// - 속성:
//   - location: 집의 위치 {x, y}.
//   - hasGift: 선물을 받았는지 여부 (기본값 false).

// 4. Sled 객체 (Santa의 속성으로 포함)
// - 속성:
//   - currentLoad: 썰매에 적재된 선물의 개수.
// - 메서드:
//   - removeGift(): 적재된 선물을 하나 감소시킴.

// 5. 시뮬레이션 기본 흐름
// - 엘프가 일정 속도로 선물을 제작하여 giftStock을 증가.
// - 썰매(Sled)에 선물을 로드.
// - 산타(Santa)가 썰매를 끌고 마을의 집(House)을 순회하며 선물을 배달.
// - 모든 집에 선물이 배달되면 시뮬레이션 종료.

// === 확장 가능 기능 ===
// 1. 날씨 시뮬레이션: 눈보라가 배달 속도에 영향을 줌.
// 2. 상태 관리:
//   - 산타와 사슴의 체력과 썰매 적재량 관리.
//   - 체력이 낮아지면 산타는 쉬어야 함.
// 3. 지도 시각화: 마을 위치를 표시하고 객체 이동을 표현.


class Santa {
    constructor(name,sled) {
        this.name = name;
        this.sled = sled;
        this.energy = 100;
        this.location = {x:0,y:0};
    }

    deliverGift(house) {
        if(this.sled.currentLoad > 0) {
            house.hasGift = true;
            this.sled.removeGift();
            console.log(`${this.name} delivered a gift to house at ${house.location.x},${house.location.y}`);
        } else {
            console.log("No gifts to deliver!");
        }
    }

    rest() {
        this.energy = 100;
        console.log(`${this.name} is resting to recover energy`);
    }
}

class Elf {
    constructor(name,workSpeed) {
        this.name = name;
        this.workSpeed = workSpeed;
        this.giftStock = 0;
    }

    makeGift() {
        this.giftStock +=  1;
        console.log(`${this.name} made a gift, Total stock: ${this.giftStock}`);
    }
}

class House {
    constructor(location) {
        this.location = location;
        this.hasGift = false;
    }
}

const santa = new Santa("Santa Claus",{ currentLoad: 5, removeGift: () => --santa.sled.currentLoad });
const elf = new Elf("Buddy",10);
const house1 = new House({X:5,y:10});

elf.makeGift();
santa.deliverGift(house1);
console.log(house1);

// 아 만들기 귀찮노 하
