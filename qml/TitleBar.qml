import QtQuick 2.4
import QtQuick.Controls 1.3
import com.iktwo.components 1.0
import "."

Item {
    id: root

    property alias color: container.color
    property alias title: titleLabel.text
    property alias titleLabel: titleLabel
    property alias titleColor: titleLabel.color
    property string iconSource
    property bool isScreenPortrait: parent.parent.objectName === "Page" ? (parent.parent.height > parent.parent.width) : false

    objectName: "titleBar"

    width: parent.width
    height: Math.ceil(ScreenValues.dp * (ScreenValues.isTablet ? 56 : (isScreenPortrait ? (ApplicationInfo.OSVersion >= 21 ? 56 : 48) : (ApplicationInfo.OSVersion >= 21 ? 48 : 40))))

    anchors.top: parent.top

    Rectangle {
        id: container

        anchors.fill: parent
        color: Theme.titleBarColor

        Item {
            id: iconImage

            anchors {
                left: parent.left; leftMargin: 4 * ScreenValues.dp
            }

            height: parent.height
            width: ScreenValues.dp * 48

            Image {
                anchors.centerIn: parent
                height: 32 * ScreenValues.dp
                width: 32 * ScreenValues.dp
                source: iconSource != "" ? iconSource : ""
            }
        }


        Label {
            id: titleLabel

            anchors {
                left: iconSource != "" ? iconImage.right : parent.left; leftMargin: ScreenValues.dp * (iconSource != "" ? 0 : 8)
                verticalCenter: parent.verticalCenter
            }

            font {
                pixelSize: 18 * ScreenValues.dp
                family: Theme.fontFamily
            }

            color: Theme.titleBarTextColor
        }
    }
}
