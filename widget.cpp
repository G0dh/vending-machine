#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();

    MsgBox.setWindowTitle("거스름돈");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin){
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl(){
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}


void Widget::resetChange(){
    coin500=money/500;
    money -= 500*coin500;
    coin100=money/100;
    money -= 100*coin100;
    coin50=money/50;
    money -= 50*coin50;
    coin10=money/10;
    money -= 10*coin10;
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
       changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
       changeMoney(-100);
}


void Widget::on_pbReset_clicked()
{
    resetChange();
    MsgBox.information(this, "거스름돈",QString("500원: %1 | 100원: %2 | 50원: %3 | 10원: %4").arg(coin500).arg(coin100).arg(coin50).arg(coin10));
    ui->lcdNumber->display(money);
    setControl();
    coin500 = coin100 = coin50 = coin10 = 0;

}

