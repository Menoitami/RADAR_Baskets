#ifndef ADDTIONAL_H
#define ADDTIONAL_H

enum Ball{
    NO=0,
    RED,
    BLUE,
};

struct BasketInfo{
    BasketInfo(): redBallsCount(0), blueBallsCount(0), allBallsCount(0){};

    BasketInfo(unsigned int red,unsigned int blue,unsigned int all)
        : redBallsCount(red), blueBallsCount(blue), allBallsCount(all){};

    unsigned int redBallsCount;
    unsigned int blueBallsCount;
    unsigned int allBallsCount;

};



#endif // ADDTIONAL_H
