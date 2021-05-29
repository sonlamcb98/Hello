import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
Window {
    visible: myLight.visibleApp
    width: 320
    height: 480
    title: qsTr("My Light")
    property string _on: "qrc:/figure/light_on.jpg"
    property string _off: "qrc:/figure/light_off.jpg"

    Image {
        id: light
        width: Math.min(parent.height, parent.width) * 0.8
        height: width
        anchors.centerIn: parent
        state: myLight.isOn ? "ON" : "OFF"
        states: [
            State {
                name: "ON"
                PropertyChanges { target: light; source: _on }
            },
            State {
                name: "OFF"
                PropertyChanges { target: light; source: _off }
            }
        ]
    }
    Button {
        id: chooseApp
        x: 175
        y: 205
        text: qsTr("chooseApp")
        onClicked: {
            controller.setVisibleApp(true);
        }
    }
}
