#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("thunderbug1");
    MainWindow w;
    w.setWindowTitle("Spherebot control");
    w.show();

    return app.exec();
}
