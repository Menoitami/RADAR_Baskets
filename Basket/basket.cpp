#include "basket.h"

Basket::Basket() : red(0), blue(0),
    qrand(QRandomGenerator(std::chrono::steady_clock::now().time_since_epoch().count()))
{

}

Basket::Basket(unsigned int _red,unsigned int _blue) : red(_red), blue(_blue),
                qrand(QRandomGenerator(std::chrono::steady_clock::now().time_since_epoch().count()))
{
}

Ball Basket::getRandomBall(){

    if (qrand.bounded(0,2)){
        if (red!=0){
            --red;
            return RED;
        }
        if (blue!=0){
            --blue;
            return BLUE;
        }
        return NO;
    }
    else{
        if (blue!=0){
            --blue;
            return BLUE;
        }
        if (red!=0){
            --red;
            return RED;
        }
        return NO;

    }
}

Ball Basket::getBall(Ball ball){

    switch(ball){
        case NO:
            break;
        case RED:
            if (red!=0){
                --red;
                return RED;
            }
            break;
        case BLUE:
            if (blue!=0){
                --blue;
                return BLUE;
            }
            break;
    }
    return NO;
}

void Basket::putBall(Ball ball, unsigned int count) {

    switch (ball) {
        case BLUE:
            if (blue + count > maxUnsignedValue) {
                throw std::overflow_error("Overflow when adding blue balls.");
            }
            blue += count;
            break;
        case RED:
            if (red + count > maxUnsignedValue) {
                throw std::overflow_error("Overflow when adding red balls.");
            }
            red += count;
            break;
        case NO:
            break;
    }
}



BasketInfo Basket::getInfo(){

    return BasketInfo(red, blue, red+blue);
}
