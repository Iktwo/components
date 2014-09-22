import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import com.iktwo.components 1.0

ButtonStyle {
    id: buttonStyle

    property color backgroundColor: Theme.titleBarColor
    property color fontColor: Theme.titleBarTextColor

    background: Rectangle {
        height: buttonStyle.control.height
        width: buttonStyle.control.width
        color: control.pressed ? Qt.darker(backgroundColor) : backgroundColor
    }

    label: Label {
        elide: "ElideRight"
        color: control.pressed ? Qt.darker(fontColor) : fontColor
        text: buttonStyle.control.text
        font.pixelSize: 14 * ScreenValues.dp
        renderType: "NativeRendering"
        verticalAlignment: "AlignVCenter"
        horizontalAlignment: "AlignHCenter"
    }
}
