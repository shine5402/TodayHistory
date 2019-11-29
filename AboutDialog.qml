import QtQuick 2.0

import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11

Dialog {
    id: aboutDialog
    title: "关于"
    modal: true
    standardButtons: DialogButtonBox.Ok
    onAccepted: aboutDialog.close()
    width: parent.width
    height: parent.height * 0.75
    font.family: "Noto Sans CJK SC Regular"

    contentItem: ScrollView{
        width:parent.width
        height: parent.height
        clip: true
        ColumnLayout{
            width: aboutDialog.width - 48
            spacing: 4
            anchors.centerIn: parent

            Label{
                text: "历史上的今天"
                font.family:  "Noto Sans CJK SC Medium"
                font.pointSize: 16
            }
            Label{
                Layout.topMargin: 4
                text: "版权所有 2019 shine_5402"
            }

            Text{
                Layout.topMargin: 8

                text:"查看历史上过去在某一天发生了什么的工具。"
                wrapMode: TextEdit.Wrap
            }

            Text{
                Layout.topMargin: 16
                text: "数据源"
                font.family:  "Noto Sans CJK SC Medium"
            }

            TextArea{
                text: "www.todayonhistory.com，更新于2019年11月23日。"
                wrapMode: TextEdit.Wrap
                Layout.fillWidth: parent
                readOnly: true
            }
            Text{
                Layout.topMargin: 12
                text: "许可"
                font.family:  "Noto Sans CJK SC Medium"
            }

            TextArea{
                Layout.fillWidth: parent
                text: "本程序以MIT LICENSE分发：\nCopyright 2019 shine_5402\nPermission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\nThe above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE."
                readOnly : true
                wrapMode: TextEdit.Wrap

            }
        }
    }

}
