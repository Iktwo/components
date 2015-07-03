import QtQuick 2.5

FocusScope {
    id: root

    default property alias content: contentItem.data
    property alias titleBar: titleBarContainer.data
    property bool active: false

    signal activated
    signal currentItemChanged

    objectName: "Page"

    Component.onCompleted: {
        if (root.parent === null || root.parent.toString().substring(0, 9) !== "StackView") {
            root.activated()
            root.active = true
            root.focus = true
        }
    }

    Connections {
        target: root.parent !== null && root.parent.toString().substring(0, 9) === "StackView" ? root.parent : root

        onCurrentItemChanged: {
            if (root.parent.currentItem === root) {
                root.active = true
                root.activated()
                root.focus = true
            } else {
                root.active = false
            }
        }
    }

    FocusScope {
        id: titleBarContainer

        height: childrenRect.height
        width: parent.width
        focus: true
    }

    FocusScope {
        id: contentItem

        anchors {
            top: titleBarContainer.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        focus: true
    }
}
