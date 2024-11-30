#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <additional.h>
#include <QRandomGenerator>
#include "basketwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    BasketWidget* basket1;
    BasketWidget* basket2;

    BasketInfo basket1Info;
    BasketInfo basket2Info;

    QRandomGenerator qrand;

signals:
    void updateUi_sig();

private slots:
    void on_Basket1Button_clicked();
    void on_Basket2Button_clicked();
    void on_randomBasketButton_clicked();
    void updateUi_slot();
};
#endif // MAINWINDOW_H
