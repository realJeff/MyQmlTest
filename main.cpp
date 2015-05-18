#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "mycppclass.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<MyCppClass>("IT.Hello.MyCppClass", 1, 0, "MyCppClass");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
