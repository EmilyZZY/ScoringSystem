#ifndef WIDGET_H
#define WIDGET_H

#include "show.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class showScreen;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_lineEdit_1_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_3_returnPressed();

    void on_lineEdit_4_returnPressed();

    void on_lineEdit_5_returnPressed();

    void on_lineEdit_6_returnPressed();

    void on_pushButtonShow_clicked();

signals:
    scoreChange(int [], QString []);

private:
    Ui::Widget *ui;
    showScreen *s;
    int score[6];
    int sortScore[6];
    QString team[6];
    QString sortTeam[6];
    QString roundName[6]= {"抢答道具题", "必答连环题", "同词对抗题", "全员车轮战", "视频改错题", "风险分配题"};
    int round = 1;
    init();
    sorting(int score[], QString name[], int length);
};

#endif // WIDGET_H
