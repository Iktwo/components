import QtQuick 2.1
import QtQuick.Controls 1.1
import com.iktwo.components 1.0
import "."

Item {
    id: root

    property alias color: container.color
    property alias title: titleLabel.text
    property alias titleColor: titleLabel.color
    property string iconSource

    objectName: "titleBar"

    width: parent.width
    height: Math.ceil(ScreenValues.dpMultiplier * (ScreenValues.isTablet ? 56 : (isScreenPortrait ? 48 : 40)))

    anchors.top: parent.top

    Rectangle {
        id: container

        anchors.fill: parent
        color: Theme.titleBarColor

        Item {
            id: iconImage

            anchors {
                left: parent.left; leftMargin: 4 * ScreenValues.dpMultiplier
            }

            height: parent.height
            width: ScreenValues.dpMultiplier * 48

            Image {
                anchors.centerIn: parent
                height: 32 * ScreenValues.dpMultiplier
                width: 32 * ScreenValues.dpMultiplier
                source: iconSource != "" ? "qrc:/images/" + ScreenValues.getBestIconSize(height) + iconSource : ""
            }
        }


        Label {
            id: titleLabel

            anchors {
                left: iconSource != "" ? iconImage.right : parent.left; leftMargin: ScreenValues.dpMultiplier * (iconSource != "" ? 8 : 2)
                verticalCenter: parent.verticalCenter
            }

            font {
                pixelSize: 18 * ScreenValues.dpMultiplier
                weight: Font.Light
            }

            color: Theme.titleBarTextColor
        }
    }
}
