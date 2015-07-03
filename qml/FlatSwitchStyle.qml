import QtQuick 2.5
import QtQuick.Controls.Styles 1.3
import com.iktwo.components 1.0

SwitchStyle {
    id: switchStyle

    property color backgroundColor: Theme.backgroundColor
    property color activeSwitchColor: Theme.activeSwitchColor
    property color inactiveSwitchColor: Theme.inactiveSwitchColor

    handle: Rectangle {
        implicitWidth: height
        implicitHeight: Math.round(20 * ScreenValues.dp)

        radius: height / 2
        color: control.checked ? switchStyle.activeSwitchColor : switchStyle.backgroundColor
        border {
            color: control.checked ? switchStyle.activeSwitchColor : switchStyle.inactiveSwitchColor
            width: Math.round(2 * ScreenValues.dp)
        }
    }

    groove: Item {
        implicitWidth: Math.round(40 * ScreenValues.dp)
        implicitHeight: Math.round(20 * ScreenValues.dp)

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            height: Math.round(2 * ScreenValues.dp)
            color: control.checked ? switchStyle.activeSwitchColor : switchStyle.inactiveSwitchColor
            width: parent.width
        }
    }
}
