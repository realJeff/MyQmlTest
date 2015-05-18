import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1


ScrollView {
    id:page
    width: 800
    height: 600

    Item{
        SystemPalette { id: palette }
        clip: true
        width: page.viewport.width
        height: page.viewport.height
        anchors.fill: parent

        GroupBox{
            Layout.fillHeight: true
            Layout.fillWidth: true

            Column{
                anchors.fill: parent
                TableView{
                    id: tableView
                    width: 200
                    TableViewColumn{ role: "id"; title: "Id"}
                    TableViewColumn{ role: "name"; title: "Name"}
                    TableViewColumn{ role: "author"; title: "Author"}
                    TableViewColumn{ role: "year"; title: "Year"}
                    model:myCppClass.model()
                }

                Button{
                    text: "Delete"
                }
            }
        }
    }
}

