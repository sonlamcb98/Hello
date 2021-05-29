#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "LightController.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    LightController controller;

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    engine.rootContext()->setContextProperty("controller", &controller);
    engine.load(url);

    return app.exec();
}
