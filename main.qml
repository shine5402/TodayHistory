import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3
import "Icon.js" as MdiFont

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 720
    title: qsTr("历史上的今天")
    minimumWidth: 480
    minimumHeight: 680
    property QtObject currentDay: QtObject {
        property int day : HistoryDataGetter.day
        property int month: HistoryDataGetter.month
    }
    Binding{
        target: HistoryDataGetter
        property: "day"
        value: currentDay.day
    }
    Binding{
        target: HistoryDataGetter
        property: "month"
        value: currentDay.month
    }

    Pane {
        anchors.fill: parent
        padding: 16
        height: title.height
        width: parent ? parent.width : 0
        background:
            Rectangle {
            id: upBack
            height:  header.height + parent.padding + 16
            width: mainWindow.width
            color: Material.primary
        }
        ColumnLayout{
            anchors.fill: parent

            RowLayout {

                id :header
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
                    color: "white"
                }

                Item{
                    Layout.fillWidth: parent
                }
                Text{
                    text: qsTr("%1月%2日").arg(currentDay.month).arg(currentDay.day)
                    color: "white"
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
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
                    Material.background: Material.accent
                    highlighted: true
                    onClicked: chooseDayDialog.open()
                }
                RoundButton{
                    id : aboutButton
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                    Material.background: Material.accent
                    highlighted: true
                    font.family: "Material Design Icons"
                    text: MdiFont.Icon.information
                    font.pointSize: 16
                    onClicked: aboutDialog.open()
                }

            }
            Item{
                height: 16}
            ScrollView{
                Layout.fillHeight: parent
                Layout.fillWidth: parent
                clip: true
                ScrollBar.horizontal.policy : ScrollBar.AsNeeded
                ScrollBar.vertical.policy : ScrollBar.AsNeeded
                ListView{
                    id : historyListView
                    model : HistoryItemEntries
                    delegate : HistoryDelegate{}
                    visible: count !== 0
                }

            }


        }
        Text {
            id: noData
            visible: historyListView.count === 0
            text: "程序没有在数据中找到给定日期的历史信息。"
            anchors.centerIn: parent
        }
    }
    AboutDialog{
        id : aboutDialog
        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height) / 2)
    }
    ChooseDayDialog{
        id : chooseDayDialog
        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height) / 2)
        currentDay: mainWindow.currentDay
    }
}

