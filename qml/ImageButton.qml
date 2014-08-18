import QtQuick 2.2
import com.iktwo.components 1.0

Item {
    id: root

    function getContrastYIQ(color){
        var colorStr = color.toString().substr(1)
        var r = parseInt(colorStr.substr(0,2),16)
        var g = parseInt(colorStr.substr(2,2),16)
        var b = parseInt(colorStr.substr(4,2),16)
        var yiq = ((r * 299) + (g * 587) + (b * 114)) / 1000
        return (yiq >= 128) ? 'black' : 'white'
    }

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
        color: root.parent.objectName === "titleBar" ? getContrastYIQ(root.parent.color) : "#ffffff"
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
