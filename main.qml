import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import IT.Hello.MyCppClass 1.0


ApplicationWindow {
    title: qsTr("Hello")
    width: 640
    height: 480
    visible: true
    visibility: "Maximized"

    MyCppClass {id: myCppClass}

    TabView {
        anchors.fill: parent
        anchors.margins: 8

        Tab {
            id: tab01Page
            title: "Tab01"
            Tab01 {}

        }
    }
}
