import QtQuick 2.0

import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11
import Qt.labs.calendar 1.0
import QtQuick.Controls.Material 2.3
import "Icon.js" as MdiFont

Dialog {
    id : chooseDayDialog
    modal: true
    standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel
    font.family: "Noto Sans CJK SC Regular"
    property QtObject currentDay: QtObject {
        property int day : 1
        property int month: 1
    }

    onAccepted: {
        currentDay.day = parseInt(dayComboBox.currentText)
        currentDay.month = parseInt(monthComboBox.currentText)
    }


    function dayOfMonth(m)
    {
        switch (m)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 29;
        }
    }
    function modelForNum(n)
    {
        var a = []
        for (var i = 1;i <= n; i++)
        {
            a[i - 1] = i
        }
        return a
    }

    contentItem: ColumnLayout{
        RowLayout{
            Layout.alignment: Qt.AlignHCenter
            ComboBox{
                id : monthComboBox
                model: modelForNum(12)
                displayText: currentText + " 月"

            }
            ComboBox{
                id : dayComboBox
                displayText: currentText + " 日"
                model: modelForNum(dayOfMonth(parseInt(monthComboBox.currentText)))

            }
            RoundButton{
                font.family: "Material Design Icons"
                text: MdiFont.Icon.calendarToday
                Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                font.pointSize: 16
                Material.foreground: Material.accent
                Material.background: "white"
                onClicked: {
                    monthComboBox.currentIndex = new Date().getMonth();
                    dayComboBox.currentIndex = new Date().getDate() - 1;

                }

            }
        }
        GridLayout {

            columns: 2

            DayOfWeekRow {
                locale: grid.locale

                Layout.column: 1
                Layout.fillWidth: true
            }

            WeekNumberColumn {
                month: grid.month
                year: grid.year
                locale: grid.locale

                Layout.fillHeight: true
            }

            MonthGrid {
                id: grid
                month: (parseInt(monthComboBox.currentText) - 1) > 0 ? parseInt(monthComboBox.currentText) - 1 : 1
                year: 2016
                property int day: parseInt(dayComboBox.currentText) > 0? parseInt(dayComboBox.currentText) : 1
                locale: Qt.locale("zh_CN")
                delegate: Label {
                    height: width
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    opacity: model.month === grid.month ? 1 : 0
                    color: (model.day === parent.parent.day) ? "white" : "dark"

                    text: model.day
                    font.family : (model.day === parent.parent.day) ? "Noto Sans CJK SC Medium" : "Noto Sans CJK SC Regular"
                    background: Rectangle{
                        color: "#03A9F4"
                        radius: width * 0.5
                        opacity: (model.day === parent.parent.parent.day) ? 1 : 0
                    }
                }
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: {
                    dayComboBox.currentIndex = date.getDate() - 1
                }
            }
        }
        Label{
            text: "为了显示2月29日，此处日历的年份为2016年。"
        }
    }
}
