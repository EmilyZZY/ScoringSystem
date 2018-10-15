#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

Widget::init()
{
    QFile file("name.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"====================fail=======================";
    }
    else
    {
        QTextStream in(&file);
        in>>team[0];
        ui->label_1->setText(team[0]);
        in>>team[1];
        ui->label_2->setText(team[1]);
        in>>team[2];
        ui->label_3->setText(team[2]);
        in>>team[3];
        ui->label_4->setText(team[3]);
        in>>team[4];
        ui->label_5->setText(team[4]);
        in>>team[5];
        ui->label_6->setText(team[5]);
    }

    score[0] = score[1] = score[2] = score[3] =  score[4] =  score[5] = 100;
    ui->lineEdit_1->setText(QString::number(score[0],10));
    ui->lineEdit_2->setText(QString::number(score[1],10));
    ui->lineEdit_3->setText(QString::number(score[2],10));
    ui->lineEdit_4->setText(QString::number(score[3],10));
    ui->lineEdit_5->setText(QString::number(score[4],10));
    ui->lineEdit_6->setText(QString::number(score[5],10));
}
Widget::~Widget()
{
    delete ui;
}
Widget::sorting(int score[], QString name[], int length)
{
    for(int i = 0; i < length; i++)
    {
        sortScore[i] = score[i];
        sortTeam[i] = name[i];
    }

    int iMax,iTem;
    QString temp;
    for (int i = 0;i < length;i++)
    {
        iMax = i;
        for (int j = i + 1;j <length;j++)
        {
            if (sortScore[iMax] < sortScore[j])
            {
                iMax = j;//如果比score[iMax]大就记录下标
            }
        }

        if (iMax != i)//如果iMax的值变了就说明有比他大的数字 就进行交换
        {
            iTem = sortScore[i];
            sortScore[i] = sortScore[iMax];
            sortScore[iMax] = iTem;

            temp = sortTeam[i];
            sortTeam[i] = sortTeam[iMax];
            sortTeam[iMax] = temp;

        }
    }
}
void Widget::on_lineEdit_1_returnPressed()
{
    score[0] = ui->lineEdit_1->text().toInt();
    qDebug()<<team[0]<<score[0];
    sorting(score, team, 6);
    emit scoreChange(sortScore, sortTeam);
}

void Widget::on_lineEdit_2_returnPressed()
{
    score[1] = ui->lineEdit_2->text().toInt();
    qDebug()<<team[1]<<score[1];
    sorting(score, team, 6);
    emit scoreChange(sortScore, sortTeam);
}

void Widget::on_lineEdit_3_returnPressed()
{
    score[2] = ui->lineEdit_3->text().toInt();
    qDebug()<<team[2]<<score[2];
    sorting(score, team, 6);
    emit scoreChange(sortScore, sortTeam);
}

void Widget::on_lineEdit_4_returnPressed()
{
    score[3] = ui->lineEdit_4->text().toInt();
    qDebug()<<team[3]<<score[3];
    sorting(score, team, 6);
    emit scoreChange(sortScore, sortTeam);
}

void Widget::on_lineEdit_5_returnPressed()
{
    score[4] = ui->lineEdit_5->text().toInt();
    qDebug()<<team[4]<<score[4];
    sorting(score, team, 6);
    emit scoreChange(sortScore, sortTeam);
}

void Widget::on_lineEdit_6_returnPressed()
{
    score[5] = ui->lineEdit_6->text().toInt();
    qDebug()<<team[5]<<score[5];
    sorting(score, team, 6);
    emit scoreChange(sortScore, sortTeam);
}

