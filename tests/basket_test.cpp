#include <cassert>
#include <iostream>
#include <limits>
#include "basket.h"
#include "additional.h"


void constructorTests(){
    Basket basket;
    assert(basket.getInfo().allBallsCount == 0);
    assert(Basket(2, 3).getInfo().allBallsCount == 5);
    assert(Basket(2, 3).getInfo().redBallsCount == 2);
    assert(Basket(2, 3).getInfo().blueBallsCount == 3);
}

void getBallTests(){

     Basket basket;
     assert(basket.getBall(RED) == NO);
     assert(basket.getBall(BLUE) == NO);

     Basket basket2(3,2);
     assert(basket2.getBall(RED) == RED);
     assert(basket2.getBall(BLUE) == BLUE);
     assert(basket2.getBall(NO) == NO);
     assert(basket2.getInfo().allBallsCount == 3);
     assert(basket2.getInfo().redBallsCount == 2);
     assert(basket2.getInfo().blueBallsCount == 1);

     Basket basket3(1,1);

     assert(basket3.getRandomBall() !=NO);
     assert(basket3.getInfo().allBallsCount == 1);
     assert(basket3.getRandomBall() !=NO);
     assert(basket3.getInfo().allBallsCount == 0);
     assert(basket3.getRandomBall() ==NO);
     assert(basket3.getInfo().allBallsCount == 0);
}

void putBallTest(){

    Basket basket;
    basket.putBall(RED,3);
    assert(basket.getInfo().allBallsCount == 3);
    assert(basket.getInfo().redBallsCount == 3);
    assert(basket.getInfo().blueBallsCount == 0);
    basket.putBall(BLUE,5);
    assert(basket.getInfo().allBallsCount == 8);
    assert(basket.getInfo().redBallsCount == 3);
    assert(basket.getInfo().blueBallsCount == 5);
    basket.putBall(NO,10);
    assert(basket.getInfo().allBallsCount == 8);
    assert(basket.getInfo().redBallsCount == 3);
    assert(basket.getInfo().blueBallsCount == 5);
}

void runTests() {
    constructorTests();
    getBallTests();
    putBallTest();

}

int main() {
    try {
        runTests();
        std::cerr << "Tests successfully passed"<< std::endl;
    } catch (const std::exception& e) {
        std::cerr << "One or more tests failed: " << e.what() << std::endl;
    }
    return 0;
}
