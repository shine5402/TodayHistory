import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3

Window {
    visible: true
    width: 480
    height: 640
    title: qsTr("历史上的今天")
    StackView{
        id: stack
        initialItem: mainView
        anchors.fill: parent
        anchors.margins: 16
    }
    Component {
              id: mainView
              Column{
                  Text {
                      id: title
                      text: qsTr("历史上的今天")
                  }
              }
          }
}

/*##^## Designer {
    D{i:2;anchors_x:247;anchors_y:184}D{i:1;anchors_height:200;anchors_width:200;anchors_x:195;anchors_y:128}
}
 ##^##*/
