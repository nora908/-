#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Set the app style sheet
    /*QFile styleSheetFile("./Toolery.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    qApp->setStyleSheet(styleSheet);*/


    MainWindow w;
    w.show();
    return a.exec();
}
