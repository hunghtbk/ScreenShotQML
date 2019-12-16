import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        anchors.centerIn: parent
        width: 200
        height: 50
        border.color: "black"
        Text {
            id: name
            anchors.centerIn: parent
            text: qsTr(UIBridge.buttonName())
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                UIBridge.captureScreen();
            }
        }
    }
}
