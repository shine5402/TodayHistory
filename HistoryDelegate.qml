import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11

ItemDelegate {
    id: root
    width: parent.width
    checkable: true

    onClicked: Qt.openUrlExternally(model.url)

    contentItem: RowLayout {

        ColumnLayout{
            id: texts
            Text {
                id: title
                text: model.title
                Layout.margins: 4
                font.family: "Noto Sans CJK SC Medium"
                Layout.preferredWidth: contentWidth
            }
            RowLayout{
                Label {
                    id: yearText
                    text: model.year
                    font.family: "Noto Sans CJK SC Medium"
                    background: Rectangle{
                        radius: 8
                        color: Material.accent
                    }
                    color: "white"
                    Layout.preferredWidth: implicitWidth + 8
                    Layout.preferredHeight: implicitHeight + 4
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                id: description
                text: model.des
                elide: Text.ElideRight
                Layout.fillWidth: parent
            }
            }
        }
//        Item{
//            Layout.fillWidth: parent
//            Layout.fillHeight: parent
//            Layout.minimumWidth: 0
//        }
        Image {
            id: picture
            source: model.pic
            asynchronous: true
            Layout.preferredHeight: title.contentHeight + 4 + description.contentHeight
            Layout.preferredWidth: sourceSize.width * (Layout.preferredHeight / sourceSize.height)
            fillMode: Image.PreserveAspectFit
            Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            Layout.leftMargin: 8
        }
    }



}
