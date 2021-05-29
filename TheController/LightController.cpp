#include "LightController.h"

LightController::LightController(QObject *parent) : QObject(parent)
{
    m_visibleApp = false;
//    theLight = new local::MyLight("son.service.light", "/light",
//                                  QDBusConnection::sessionBus(), this);
}

void LightController::turnOn()
{
//    theLight->turnOn();
}

void LightController::turnOff()
{
//    theLight->turnOff();
}
