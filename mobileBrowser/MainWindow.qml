import QtQuick 2.15
import QtQuick.Window 2.15
import QtWebView 1.1
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

GridLayout{
    id:mainGrid
    columns: 4
    rows:4

    property int _activeId : 0

    Connections{
        target: searchEngine
        function onChangeActiveId(activeId){
            _activeId = activeId
        }
    }



    Button{
        font.pointSize: height/2.5

        text: qsTr("<")

        Layout.preferredHeight: browser.height/20
        Layout.preferredWidth: height

        Layout.column: 0
        Layout.row: 0

        background: Rectangle{
            color: "#d9ffe8"
            radius: 8
        }

        onClicked: {
            mainWebView.goBack()
        }
    }

    Button{
        font.pointSize: height/2.5

        text: qsTr(">")

        Layout.preferredHeight: browser.height/20
        Layout.preferredWidth: height

        Layout.column: 1
        Layout.row: 0

        background: Rectangle{
            color: "#d9ffe8"
            radius: 8
        }

        onClicked: {
            mainWebView.goForward()
        }
    }

    TextField{
        id:searchTextField
        font.pointSize: height/2.5

        placeholderText: qsTr("гугл")
        horizontalAlignment: Text.AlignHCenter

        color: "#000000"

        Layout.preferredHeight: browser.height/20
        Layout.fillWidth: true

        Layout.column: 2
        Layout.row: 0

        background: Rectangle{
            color: "#d9ffe8"
            radius: 8
        }

    }

    Button{
        font.pointSize: height/2.5

        Layout.preferredHeight: browser.height/20
        Layout.preferredWidth: height

        Layout.column: 3
        Layout.row: 0

        background: Rectangle{
            color: "#d9ffe8"
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
            searchEngine.compliteAddress(searchTextField.text);
        }
    }


    ProgressBar{
        value: mainWebView.loadProgress/100
        Layout.preferredHeight: browser.height/80
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
            searchEngine.savePage(mainWebView.url,_activeId,mainWebView.title)
            searchEngine.saveHistory(mainWebView.url);
            //console.log(mainWebView.title)
        }
        onTitleChanged: {
            searchEngine.savePage(mainWebView.url,_activeId,mainWebView.title)
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

        Layout.preferredHeight: browser.height/20
        Layout.preferredWidth: height

        Layout.column: 3
        Layout.row: 3

        background: Rectangle{
            color: "#d9ffe8"
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
        id:menuButton
        font.pointSize: height/2.5

        text: qsTr("menu")

        Layout.preferredHeight: browser.height/20
        Layout.fillWidth: true

        Layout.column: 1
        Layout.row: 3
        Layout.columnSpan: 2

        background: Rectangle{
            color: "#d9ffe8"
            radius: 8
        }

        onClicked: {
            appEngine.menu()
        }
    }

    Button{
        id:pagesButton
        font.pointSize: height/2.5

        text: qsTr("1")

        Layout.preferredHeight: browser.height/20
        Layout.preferredWidth: height

        Layout.column: 0
        Layout.row: 3

        background: Rectangle{
            color: "#d9ffe8"
            radius: 8
        }

        Image {
            source: "qrc:/res/square.png"
            fillMode: Image.PreserveAspectFit

            width: parent.width/1.8
            height: parent.height/1.8

            anchors.centerIn: parent
        }

        onClicked: {
            appEngine.pages()
        }

        Connections{
            target: searchEngine
            function onGetNumberPages(numberPages){
                pagesButton.text = numberPages
            }
        }
    }

}
