import QtQuick 2.15
import QtQuick.Window 2.15
import QtWebView 1.1
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import page 1.0



GridLayout{
    columns: 2
    rows: 2

    Rectangle{
        id:pageZone
        Layout.fillHeight: true
        Layout.fillWidth: true

        Layout.column: 0
        Layout.row: 0
        Layout.columnSpan: 2

        ScrollView{
            anchors.fill: parent
            ListView{
                anchors.fill: parent
                //verticalLayoutDirection: ListView.BottomToTop
                model: Pagemodel{
                    list: pagelist
                }
                spacing: parent.height/50
                delegate: Rectangle{
                    width: pageZone.width
                    height: pageZone.height/17
                    GridLayout{
                        width: parent.width/1.2
                        height: parent.height

                        anchors.centerIn: parent

                        columns:2
                        rows: 1

                        Button{
                            Layout.fillHeight: true
                            Layout.preferredWidth: parent.width/4 * 3
                            text: model.title != "" ? model.title : "GOOGLE"
                            background: Rectangle{
                                color: "#d9ffe8"
                                radius: 8
                            }

                            onClicked: {
                                searchEngine.compliteAddress(model.addr,model.id);
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
                                color: "#d9ffe8"
                                radius: 8
                            }

                            onClicked: {
                                searchEngine.deletePage(model.id)
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
        Layout.fillWidth: true

        Layout.column: 0
        Layout.row: 1
        Layout.columnSpan: 2

        background: Rectangle{
            color: "#d9ffe8"
            radius: 8
        }


        Image {
            source: "qrc:/res/plus.png"
            fillMode: Image.PreserveAspectFit

            width: parent.width/1.4
            height: parent.height/1.4

            anchors.centerIn: parent
        }

        onClicked: {
            searchEngine.createPage(searchEngine.getActiveSearcher());
        }
    }
}
