import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import com.iktwo.components 1.0

Dialog {
    id: root

    property UpdateChecker updateCheckerElement

    buttons: [
        Button {
            anchors {
                horizontalCenter: parent.horizontalCenter
            }

            text: qsTr("Update")
            height: 40 * ScreenValues.dp
            Layout.preferredHeight: 40 * ScreenValues.dp
            width: Math.min(root.width / 2.5, 220 * ScreenValues.dp)
            Layout.preferredWidth: Math.min(root.width / 2.5, 220 * ScreenValues.dp)
            style: FlatButtonStyle { }
            enabled: root.opacity
            onClicked: updateCheckerElement.openPackageOnGooglePlay()
        },
        Button {
            anchors {
                horizontalCenter: parent.horizontalCenter
            }

            text: qsTr("Skip")
            height: 40 * ScreenValues.dp
            Layout.preferredHeight: 40 * ScreenValues.dp
            width: Math.min(root.width / 2.5, 220 * ScreenValues.dp)
            Layout.preferredWidth: Math.min(root.width / 2.5, 220 * ScreenValues.dp)
            style: FlatButtonStyle { backgroundColor: "#cccccc"; fontColor: "#757575" }
            enabled: root.opacity
            onClicked: root.close()
        },
        Button {
            anchors {
                horizontalCenter: parent.horizontalCenter
            }

            text: qsTr("Skip until next")
            height: 40 * ScreenValues.dp
            Layout.preferredHeight: 40 * ScreenValues.dp
            width: Math.min(root.width / 2.5, 220 * ScreenValues.dp)
            Layout.preferredWidth: Math.min(root.width / 2.5, 220 * ScreenValues.dp)
            style: FlatButtonStyle { backgroundColor: "#cccccc"; fontColor: "#757575" }
            enabled: root.opacity

            onClicked: {
                updateCheckerElement.skipLatestVersion()
                root.close()
            }
        }
    ]
}
