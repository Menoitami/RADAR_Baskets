#ifndef BASKET_H
#define BASKET_H

#include <additional.h>
#include <limits>
#include <stdexcept>
#include <chrono>
#include <QRandomGenerator>
#include <QDebug>


class Basket
{
public:
    Basket();
    Basket(int seed);
    Basket(unsigned int _red,unsigned int _blue);

    Ball getRandomBall();
    Ball getBall(Ball ball);

    void putBall(Ball ball, unsigned int count);

    BasketInfo getInfo();

private:

    unsigned int red;
    unsigned int blue;

    QRandomGenerator qrand;
    const unsigned int maxUnsignedValue = std::numeric_limits<unsigned int>::max();


};

#endif // BASKET_H
