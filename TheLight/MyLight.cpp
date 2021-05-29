#include "MyLight.h"

MyLight::MyLight(QObject *parent) : QObject(parent)
{
  m_visibleApp = true;
  m_isOn = false;
}
