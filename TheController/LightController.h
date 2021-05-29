#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H
//#include "light_interface.h"
#include <QObject>

class LightController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool visibleApp READ visibleApp WRITE setVisibleApp NOTIFY visibleAppChanged)
private:
//    local::MyLight *theLight;
    bool m_visibleApp;

public:
    explicit LightController(QObject *parent = nullptr);

bool visibleApp() const
{
    return m_visibleApp;
}

signals:

void visibleAppChanged(bool visibleApp);

public slots:
    void turnOn();
    void turnOff();
    void setVisibleApp(bool visibleApp)
    {
        if (m_visibleApp == visibleApp)
            return;

        m_visibleApp = visibleApp;
        emit visibleAppChanged(m_visibleApp);
    }
};

#endif // LIGHTCONTROLLER_H
