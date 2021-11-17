import QtQuick 2.15
import QtQuick.Window 2.15
import QtWebView 1.1
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import page 1.0


ApplicationWindow {
    id:root
    width: 720/2
    height: 1080/2
    visible: true
    title: qsTr("Hello World")


    property int _activeId : 0

    Connections{
        target: searchEngine
        function onChangeActiveId(activeId){
            _activeId = activeId
        }
    }

    /*
    menuBar: MenuBar{
        Menu{
            title: qsTr("main")

            MenuItem{
                text:qsTr("go to home")
                onClicked: {
                    mainWebView.url = "https://www.google.ru/"
                    searchTextField.clear()
                }
            }
        }
    }
    */

    StackView{
        id:mainStackView
        initialItem: browser
        anchors.fill: parent

        Connections{
            target: appEngine
            function onGoToPages(){
                mainStackView.push(pages)
            }
            function onGoToMainWindow(){
                mainStackView.pop();
            }
        }
    }


    Page{
        id:browser
        anchors.fill: parent
        GridLayout{
            id:mainGrid
            anchors.fill: parent
            columns: 4
            rows:4


            Button{
                font.pointSize: height/2.5

                text: qsTr("<")

                Layout.preferredHeight: root.height/18
                Layout.preferredWidth: height

                Layout.column: 0
                Layout.row: 0

                background: Rectangle{
                    color: "#E0FFFF"
                    radius: 8
                }
                /*
            Image {
                source: "qrc:/res/searchIcon.png"
                fillMode: Image.PreserveAspectFit

                width: parent.width/1.4
                height: parent.height/1.4

                anchors.centerIn: parent
            }
            */

                onClicked: {
                    mainWebView.goBack()
                }
            }

            Button{
                font.pointSize: height/2.5

                text: qsTr(">")

                Layout.preferredHeight: root.height/18
                Layout.preferredWidth: height

                Layout.column: 1
                Layout.row: 0

                background: Rectangle{
                    color: "#E0FFFF"
                    radius: 8
                }
                /*
            Image {
                source: "qrc:/res/searchIcon.png"
                fillMode: Image.PreserveAspectFit

                width: parent.width/1.4
                height: parent.height/1.4

                anchors.centerIn: parent
            }
            */

                onClicked: {
                    mainWebView.goForward()
                }
            }


            TextField{
                id:searchTextField
                font.pointSize: height/2.5

                //placeholderText: qsTr("эта хуита адресная строка а не поисковик")
                horizontalAlignment: Text.AlignHCenter

                color: "#000000"

                Layout.preferredHeight: root.height/20
                Layout.fillWidth: true

                Layout.column: 2
                Layout.row: 0

                background: Rectangle{
                    color: "#E0FFFF"
                    radius: 8
                }

            }

            Button{
                font.pointSize: height/2.5

                //text: qsTr("S")

                Layout.preferredHeight: root.height/18
                Layout.preferredWidth: height

                Layout.column: 3
                Layout.row: 0

                background: Rectangle{
                    color: "#E0FFFF"
                    radius: 8
                }
                Image {
                    source: "qrc:/res/searchIcon.png"
                    fillMode: Image.PreserveAspectFit

                    width: parent.width/1.4
                    height: parent.height/1.4

                    anchors.centerIn: parent
                }

                onClicked: {
                    //mainWebView.url = searchTextField.text
                    searchEngine.compliteAddress(searchTextField.text);
                }
            }


            ProgressBar{
                value: mainWebView.loadProgress/100
                Layout.preferredHeight: root.height/80
                Layout.fillWidth: true

                Layout.column: 0
                Layout.row: 1
                Layout.columnSpan: 4
            }

            WebView{
                id:mainWebView
                url: "https://www.google.ru/"

                Layout.fillWidth: true
                Layout.fillHeight: true

                Layout.column: 0
                Layout.row: 2
                Layout.columnSpan: 4

                onUrlChanged: {
                    searchTextField.text = mainWebView.url
                    searchEngine.savePage(mainWebView.url,_activeId)
                }

                Connections{
                    target: searchEngine
                    function onSearch(addr){
                        mainWebView.url = addr
                    }
                }
            }

            Button{
                font.pointSize: height/2.5

                //text: qsTr("h")

                Layout.preferredHeight: root.height/18
                Layout.preferredWidth: height

                Layout.column: 3
                Layout.row: 3

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
                    mainWebView.url = "https://www.google.ru/"
                    searchTextField.clear()
                }
            }

            Button{
                font.pointSize: height/2.5

                //text: qsTr("h")

                Layout.preferredHeight: root.height/18
                Layout.preferredWidth: height

                Layout.column: 0
                Layout.row: 3

                background: Rectangle{
                    color: "#E0FFFF"
                    radius: 8
                }

                Image {
                    source: "qrc:/res/page.png"
                    fillMode: Image.PreserveAspectFit

                    width: parent.width/1.4
                    height: parent.height/1.4

                    anchors.centerIn: parent
                }


                onClicked: {
                    appEngine.pages()
                }
            }

        }
    }
    Page{
        id:pages
        anchors.fill: parent
        visible: false

        GridLayout{
            anchors.fill: parent
            columns: 2
            rows: 2

            Rectangle{
                id:pageZone
                Layout.fillHeight: true
                Layout.fillWidth: true

                Layout.column: 0
                Layout.row: 0
                Layout.columnSpan: 2

                ListView{
                    anchors.fill: parent
                    model: Pagemodel{
                        list: pagelist
                    }
                    spacing: parent.height/50
                    delegate: Rectangle{
                        width: pageZone.width
                        height: pageZone.height/20
                        GridLayout{
                            width: parent.width/1.2
                            height: parent.height

                            anchors.centerIn: parent

                            columns:2
                            rows: 1

                            Button{
                                Layout.fillHeight: true
                                Layout.preferredWidth: parent.width/4 * 3
                                text:model.addr
                                background: Rectangle{
                                    color: "#D3D3D3"
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
                                    color: "#D3D3D3"
                                    radius: 8
                                }

                                onClicked: {
                                    searchEngine.deletePage(model.id)
                                }
                            }
                        }
                    }
                }


                //color: "#800000"
            }

            Button{
                font.pointSize: height/2.5

                //text: qsTr("+")

                Layout.preferredHeight: root.height/18
                Layout.fillWidth: true

                Layout.column: 0
                Layout.row: 1
                Layout.columnSpan: 2

                background: Rectangle{
                    color: "#E0FFFF"
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
                    searchEngine.createPage();
                }
            }

            /*
            Button{
                font.pointSize: height/2.5

                Layout.preferredHeight: root.height/18
                Layout.fillWidth: true

                Layout.column: 1
                Layout.row: 1

                background: Rectangle{
                    color: "#E0FFFF"
                    radius: 8
                }


                Image {
                    source: "qrc:/res/home.png"
                    fillMode: Image.PreserveAspectFit

                    width: height
                    height: parent.height/1.4

                    anchors.centerIn: parent
                }



                onClicked: {
                    appEngine.mainWindow();
                }
            }*/
        }
    }
}
