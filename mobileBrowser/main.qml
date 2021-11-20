import QtQuick 2.15
import QtQuick.Window 2.15
import QtWebView 1.1
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import page 1.0
import history 1.0

ApplicationWindow {
    id:root
    width: 720/2
    height: 1080/2
    visible: true
    title: qsTr("Hello World")

    onActiveChanged: {
        searchEngine.startApp();
    }


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
                mainStackView.pop(null);
            }
            function onGoToMenu(){
                mainStackView.push(menuPage)
            }
            function onGoToHistory(){
                mainStackView.push(historyPage)
            }
        }
    }


    Page{
        id:browser
        anchors.fill: parent

        MainWindow {
            anchors.fill: parent
        }
    }
    Page{
        id:pages
        anchors.fill: parent
        visible: false

        Pages {
            anchors.fill: parent
        }
    }
    Page{
        id:menuPage
        anchors.fill: parent
        visible: false

        MenuWindow {
            anchors.fill: parent
        }
    }
    Page{
        id:historyPage
        anchors.fill: parent
        visible: false

        HistoryWindow {
            anchors.fill: parent
        }
    }
}
