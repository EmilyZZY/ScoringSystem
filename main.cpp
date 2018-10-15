#include "widget.h"
#include "show.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    showScreen s;
    s.show();

    return a.exec();
}
