import QtQuick 2.15
import QtQuick.Window 2.15
import QtWebView 1.1
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import history 1.0

GridLayout{
    columns: 2
    rows:2
    Rectangle{
        id:historyZone
        Layout.fillHeight: true
        Layout.fillWidth: true

        Layout.column: 0
        Layout.row: 0
        Layout.columnSpan: 2

        ScrollView{
            anchors.fill: parent
            ListView{
                anchors.fill:parent
                verticalLayoutDirection: ListView.BottomToTop
                model: Historymodel{
                    list: historylist
                }
                spacing: parent.height/50
                delegate: Rectangle{
                    width: historyZone.width
                    height: historyZone.height/20
                    GridLayout{
                        width: parent.width/1.2
                        height: parent.height
                        anchors.centerIn: parent
                        columns: 2
                        rows:1
                        Button{
                            Layout.fillHeight: true
                            Layout.preferredWidth: parent.width/4 * 3

                            text:model.addr
                            background: Rectangle{
                                color: "#D3D3D3"
                                radius: 8
                            }

                            onClicked: {
                                searchEngine.createPage(model.addr)
                                searchEngine.compliteAddress();
                            }
                        }
                        Button{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Text{
                                text: qsTr("del")

                                font.pointSize: parent.height/2.5

                                anchors.centerIn: parent
                            }
                            background: Rectangle{
                                color: "#D3D3D3"
                                radius: 8
                            }

                            onClicked: {
                                searchEngine.deleteSelectedAddrHistory(model.id);
                            }
                        }
                    }
                }
            }
        }
    }
    Button{
        font.pointSize: height/2.5

        Layout.preferredHeight: pages.height/18
        Layout.preferredWidth: parent.width/2

        Layout.column: 0
        Layout.row: 1

        background: Rectangle{
            color: "#E0FFFF"
            radius: 8
        }


        Image {
            source: "qrc:/res/home.png"
            fillMode: Image.PreserveAspectFit

            width: parent.width/1.4
            height: parent.height/1.4

            anchors.centerIn: parent
        }

        onClicked: {
            appEngine.mainWindow()
        }
    }
    Button{
        font.pointSize: height/2.5
        text: qsTr("clear all")

        Layout.preferredHeight: pages.height/18
        Layout.fillWidth: true

        Layout.column: 1
        Layout.row: 1

        background: Rectangle{
            color: "#E0FFFF"
            radius: 8
        }

        onClicked: {
            searchEngine.clearAllHistory();
        }
    }
}

