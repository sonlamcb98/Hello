#ifndef MYLIGHT_H
#define MYLIGHT_H

#include <QObject>

class MyLight : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isOn READ getIsOn WRITE setIsOn NOTIFY lightChanged)
    Q_PROPERTY(bool visibleApp READ getVisibleApp WRITE setVisibleApp NOTIFY visibleAppChanged)
private:
    bool m_isOn;

    bool m_visibleApp;

public:
    explicit MyLight(QObject *parent = nullptr);

bool getIsOn() const
{
    return m_isOn;
}

void setIsOn(bool isOn)
{
    if (m_isOn == isOn)
        return;

    m_isOn = isOn;
    emit lightChanged(m_isOn);
}

bool getVisibleApp() const
{
    return m_visibleApp;
}

signals:

void lightChanged(bool isOn);

void visibleAppChanged(bool visibleApp);

public slots:

void turnOn(){
    setIsOn(true);
}
void turnOff(){
    setIsOn(false);
}

void setVisibleApp(bool visibleApp)
{
    if (m_visibleApp == visibleApp)
        return;

    m_visibleApp = visibleApp;
    emit visibleAppChanged(m_visibleApp);
}
};

#endif // MYLIGHT_H
