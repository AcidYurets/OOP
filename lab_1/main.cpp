#include "mainwindow.h"
#include <QApplication>
#include <qfile.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("./style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();

    return a.exec();
}
