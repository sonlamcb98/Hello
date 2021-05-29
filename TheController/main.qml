import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2

Window {
    id: appController
    //property alias visibleApp: true
    visible: controller.visibleApp
    width: 320
    height: 480
    title: qsTr("Light Controller")

    Button {
        id: btON
        x: 43
        y: 205
        text: qsTr("ON")
        onClicked: controller.turnOn()
    }

    Button {
        id: btOFF
        x: 175
        y: 205
        text: qsTr("OFF")
        onClicked: controller.turnOff()
    }
    Button {
        id: btBack
        x: 175
        y: 205
        text: qsTr("OFF")
        onClicked: {
            controller.setVisibleApp(false);
            myLight.setVisibleApp(true);
        }
    }
}
