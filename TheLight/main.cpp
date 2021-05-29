#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MyLight.h"
#include <QtDBus>
#include <QtQml>
#include <QQmlContext>
#include "light_adaptor.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MyLight myLight;
    myLight.turnOn();
    // Create interface adaptor
    new MyLightAdaptor(&myLight);

    // Connect to session bus
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/light", &myLight);
    connection.registerService("son.service.light");


    const QUrl url(QStringLiteral("qrc:/main.qml"));

    engine.rootContext()->setContextProperty("myLight",&myLight);

    engine.load(url);

    return app.exec();
}
