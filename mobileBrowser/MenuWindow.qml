import QtQuick 2.15
import QtQuick.Window 2.15
import QtWebView 1.1
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import page 1.0
import history 1.0

GridLayout{
    rows:2
    columns:1

    Button{
        font.pointSize: height/2.5

        text: qsTr("history")

        Layout.preferredHeight: parent.height/18
        Layout.fillWidth: true

        Layout.column: 0
        Layout.row: 0

        background: Rectangle{
            color: "#E0FFFF"
            radius: 8
        }

        onClicked: {
            searchEngine.loadHistory();
            appEngine.history()
        }
    }
    Button{
        font.pointSize: height/2.5

        text: qsTr("home")

        Layout.preferredHeight: parent.height/18
        Layout.fillWidth: true

        Layout.column: 0
        Layout.row: 1

        background: Rectangle{
            color: "#E0FFFF"
            radius: 8
        }

        onClicked: {
            appEngine.mainWindow()
        }
    }
}
