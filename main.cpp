#include "notepad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notepad w;
    w.setArg(argc,argv);
    w.show();
    return a.exec();
}
