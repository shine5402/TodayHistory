import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3
import "Icon.js" as MdiFont

Window {
    visible: true
    width: 480
    height: 720
    title: qsTr("历史上的今天")
    minimumWidth: 480
    minimumHeight: 680

    property int currentDay : 1
    property int currentMonth: 1

    Pane {
        anchors.fill: parent
        padding: 16
        anchors.left: parent.left
        anchors.right: parent.right
        height: title.height
        anchors.top: parent.top
        width: parent ? parent.width : 0
        ColumnLayout{
            anchors.fill: parent
            RowLayout {
                Layout.preferredWidth:parent.width
                Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                Text {
                    id: title
                    text: qsTr("历史上的今天")
                    font.family: "Noto Sans CJK SC Bold"
                    font.pointSize: 16
                    Layout.topMargin: 8
                    Layout.leftMargin: 8
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                }

                Item{
                    Layout.fillWidth: parent
                }
                BusyIndicator{
                    Layout.preferredWidth: 48
                    visible: false
                }
                Text{
                    text: qsTr("%1月%2日").arg(currentMonth).arg(currentDay)
                }
                Item{
                    Layout.preferredWidth: 16
                }

                RoundButton{
                    id : chooseDayButton
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                    font.family: "Material Design Icons"
                    text: MdiFont.Icon.history
                    font.pointSize: 16
                }
                RoundButton{
                    id : aboutButton
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                    font.family: "Material Design Icons"
                    text: MdiFont.Icon.information
                    font.pointSize: 16
                    onClicked: aboutDialog.open()
                }

            }
            ScrollView{
                Layout.fillHeight: parent
                Layout.fillWidth: parent
                clip: true
                ScrollBar.horizontal.policy : ScrollBar.AsNeeded
                ScrollBar.vertical.policy : ScrollBar.AsNeeded
                ListView{
                    id : historyListView
                    model : HistoryModel {}
                    delegate : HistoryDelegate {}


                }
            }
        }
    }
    AboutDialog{
        id : aboutDialog
        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height) / 2)

    }
}

