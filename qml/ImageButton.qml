import QtQuick 2.2
import com.iktwo.components 1.0

Item {
    id: root

    property alias source: image.source
    property alias icon: image
    property double pressedOpacity: 0.5
    property alias highlighterColor: highlighter.color

    signal clicked

    height: parent.objectName === "titleBar" ? parent.height : 48 * ScreenValues.dpMultiplier
    width: 48 * ScreenValues.dpMultiplier

    Rectangle {
        id: highlighter

        anchors.fill: parent
        opacity: mouseArea.pressed && mouseArea.containsMouse ? pressedOpacity : 0
        color: root.parent.objectName === "titleBar" ? Theme.getContrastYIQ(root.parent.color) : "#ffffff"
    }

    Image {
        id: image

        anchors.centerIn: parent

        height: 32 * ScreenValues.dpMultiplier
        width: 32 * ScreenValues.dpMultiplier

        fillMode: Image.PreserveAspectFit
        antialiasing: true
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        enabled: parent.enabled

        onClicked: root.clicked()
    }
}
