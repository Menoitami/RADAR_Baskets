#include "basketwidget.h"
#include "./ui_basketwidget.h"

BasketWidget::BasketWidget(QWidget *parent,unsigned int red,unsigned int blue, QString title)
    : QWidget{parent}, ui(new Ui::BasketWidget), basket(Basket(red,blue)) , info(basket.getInfo())
{
    ui->setupUi(this);
    connect(this, &BasketWidget::updateUi_sig, this, &BasketWidget::updateUi_slot);
    ui->basketBox->setTitle(title);

   emit updateUi_sig();
}

BasketWidget::~BasketWidget(){

    delete ui;

}


void BasketWidget::updateUi_slot(){

    info = basket.getInfo();
    ui->sum->setText(QString::number(info.allBallsCount));
    ui->blueSum->setText(QString::number(info.blueBallsCount));
    ui->redSum->setText(QString::number(info.redBallsCount));

    if (info.allBallsCount){
        double redChance = static_cast<double>(info.redBallsCount) / static_cast<double>(info.allBallsCount)*100;
        double blueChance = static_cast<double>(info.blueBallsCount) / static_cast<double>(info.allBallsCount)*100;
        ui->redChance->setText(QString::number(redChance, 'f', 2) + "%");
        ui->blueChance->setText(QString::number(blueChance, 'f', 2) + "%");
    }
    else {
        ui->redChance->setText("0.00%");
        ui->blueChance->setText("0.00%");
    }
}

Ball BasketWidget::getRandomBall(){

    Ball color = basket.getRandomBall();
    emit updateUi_sig();

    switch(color){
        case RED:
            ui->lastAction->append("red ball taken");
            break;
        case BLUE:
            ui->lastAction->append("blue ball taken");
            break;
        case NO:
            ui->lastAction->append("ball isn't taken");
            break;
    }
    return color;

}

void BasketWidget::putBall(Ball color){

    basket.putBall(color,1);
    emit updateUi_sig();

    switch(color){
        case RED:
            ui->lastAction->append("put a red ball");
            break;
        case BLUE:
            ui->lastAction->append("put a blue ball");
            break;
        case NO:
            break;
    }

}

BasketInfo BasketWidget::getInfo(){

    return info;

}








