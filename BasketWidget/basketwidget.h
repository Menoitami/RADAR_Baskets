#ifndef BASKETWIDGET_H
#define BASKETWIDGET_H

#include <QWidget>
#include <basket.h>
#include <QString>
#include <additional.h>

namespace Ui {
class BasketWidget;
}

class BasketWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BasketWidget(QWidget *parent,unsigned int red,unsigned int blue,  QString title);
     ~BasketWidget();

    Ball getRandomBall();
    void putBall(Ball color);
    BasketInfo getInfo();



private:
    Ui::BasketWidget *ui;
    Basket basket;
    BasketInfo info;


signals:
    void updateUi_sig();

private slots:
    void updateUi_slot();
};

#endif // BASKETWIDGET_H
