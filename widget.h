#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money = 0;
    void changeMoney(int coin);
    void setControl();
    void calChange();
    void resetChange();
    int coin500 =0;
    int coin100 =0;
    int coin50 =0;
    int coin10 =0;

private slots:
    void on_pbCoin500_clicked();

    void on_pbCoin100_clicked();

    void on_pbCoin50_clicked();

    void on_pbCoin10_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbMilk_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
    QMessageBox MsgBox;
};
#endif // WIDGET_H
