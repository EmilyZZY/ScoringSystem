#include "show.h"
#include "ui_show.h"
#include<QDebug>
#include<QFile>
showScreen::showScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::show)
{
    ui->setupUi(this);

    init();

    widget = new Widget();
    widget->show();
    connect(widget, &Widget::scoreChange, this, &showScreen::change);
}

showScreen::~showScreen()
{
    delete ui;
}
showScreen::init()
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
ui->labelScore_1->setText(QString::number(score[0],10));
ui->labelScore_2->setText(QString::number(score[1],10));
ui->labelScore_3->setText(QString::number(score[2],10));
ui->labelScore_4->setText(QString::number(score[3],10));
ui->labelScore_5->setText(QString::number(score[4],10));
ui->labelScore_6->setText(QString::number(score[5],10));
}
showScreen::change(int s[], QString t[])
{
    ui->label_1->setText(t[0]);
    ui->labelScore_1->setText(QString::number(s[0],10));
    ui->label_2->setText(t[1]);
    ui->labelScore_2->setText(QString::number(s[1],10));
    ui->label_3->setText(t[2]);
    ui->labelScore_3->setText(QString::number(s[2],10));
    ui->label_4->setText(t[3]);
    ui->labelScore_4->setText(QString::number(s[3],10));
    ui->label_5->setText(t[4]);
    ui->labelScore_5->setText(QString::number(s[4],10));
    ui->label_6->setText(t[5]);
    ui->labelScore_6->setText(QString::number(s[5],10));
}


