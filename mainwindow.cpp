#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), qrand(QRandomGenerator(std::chrono::steady_clock::now().time_since_epoch().count()))
{
    ui->setupUi(this);

    basket1 = new BasketWidget(this, 10,30,"Basket 1");
    basket2= new BasketWidget(this, 30,10,"Basket 2");

    basket1->setObjectName(QString::fromUtf8("Basket1"));
    basket1->setGeometry(QRect(10, 10, 400, 280));
    basket2->setObjectName(QString::fromUtf8("Basket2"));
    basket2->setGeometry(QRect(410, 10, 400, 280));

    connect(this, &MainWindow::updateUi_sig, this, &MainWindow::updateUi_slot);

    emit updateUi_sig();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete basket1;
    delete basket2;
}

void MainWindow::on_Basket1Button_clicked()
{
    Ball color = basket1->getRandomBall();
    basket2->putBall(color);
}

void MainWindow::on_Basket2Button_clicked()
{
    Ball color = basket2->getRandomBall();
    basket1->putBall(color);
}

void MainWindow::updateUi_slot(){

    basket1Info = basket1->getInfo();
    basket2Info = basket2->getInfo();

    double  blueSum = (basket1Info.blueBallsCount + basket2Info.blueBallsCount);
    double  redSum = (basket1Info.redBallsCount + basket2Info.redBallsCount);
    double allSum = blueSum+redSum;

    if(allSum>1){
        double chance2Blue = blueSum/(allSum)*(blueSum-1)/(allSum-1);
        double chance2Red = redSum/(allSum)*(redSum-1)/(allSum-1);
        double chanceBlueNRed = 1-chance2Blue-chance2Red;

        ui->chance2Blue->setText(QString::number(chance2Blue*100, 'f', 2) + "%");
        ui->chance2Red->setText(QString::number(chance2Red*100, 'f', 2) + "%");
        ui->chanceBlueNRed->setText(QString::number(chanceBlueNRed*100, 'f', 2) + "%");
    }

    else{
        ui->chance2Blue->setText("0.00%");
        ui->chance2Red->setText("0.00%");
        ui->chanceBlueNRed->setText("0.00%");
    }
}



void MainWindow::on_randomBasketButton_clicked()
{
    for (size_t _ = 0; _<2; ++_){

        if(qrand.bounded(0,2)){

            Ball color = basket1->getRandomBall();
            if(!color){
                basket2->getRandomBall();
            }
        }
        else {

            Ball color = basket2->getRandomBall();
            if(!color){
                basket1->getRandomBall();
            }
        }
    }

    emit updateUi_sig();
}

