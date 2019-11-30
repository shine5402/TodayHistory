import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11

ItemDelegate {
    id: root
    width: parent.width
    checkable: true

    onClicked: Qt.openUrlExternally(model.modelData.url)

    contentItem: RowLayout {

        ColumnLayout{
            id: texts
            Text {
                id: title
                text: model.modelData.title
                Layout.margins: 4
                font.family: "Noto Sans CJK SC Medium"
                Layout.preferredWidth: contentWidth
            }
            RowLayout{
                Label {
                    id: yearText
                    text: model.modelData.year
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
                text: model.modelData.des
                elide: Text.ElideRight
                Layout.fillWidth: parent
            }
            }
        }
        Image {
            id: picture
            source: model.modelData.pic
            asynchronous: true
            Layout.preferredHeight: title.contentHeight + 4 + description.contentHeight
            Layout.preferredWidth: sourceSize.width * (Layout.preferredHeight / sourceSize.height)
            fillMode: Image.PreserveAspectFit
            Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            Layout.leftMargin: 8
        }
    }



}
