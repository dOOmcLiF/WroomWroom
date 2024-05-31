#include "entrywindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("WroomWroom");
    w.show();
    return a.exec();
}
