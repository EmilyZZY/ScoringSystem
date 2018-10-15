#ifndef SHOW_H
#define SHOW_H

#include "widget.h"
#include <QWidget>

namespace Ui {
class show;
}

class Widget;
class showScreen : public QWidget
{
    Q_OBJECT

public:
    explicit showScreen(QWidget *parent = 0);
    ~showScreen();


private slots:
    change(int [], QString []);
private:
    Ui::show *ui;
    Widget *widget;
    init();
    int score[6];
    int sortScore[6];
    QString team[6];
    QString sortTeam[6];
};

#endif // SHOW_H
