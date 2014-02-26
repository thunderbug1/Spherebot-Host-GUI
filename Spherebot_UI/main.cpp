#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("thunderbug1");

    MainWindow w;
    w.setWindowTitle("Spherebot control 2.0");

    QFile stylesheet(":/new/stylesheet/stylesheet.txt");
    stylesheet.open(QFile::ReadOnly);
    QString setSheet = QLatin1String(stylesheet.readAll());
    qDebug()<<setSheet;
    w.setStyleSheet(setSheet);

    w.show();

    return app.exec();
}
