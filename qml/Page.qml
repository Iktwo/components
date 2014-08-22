import QtQuick 2.3

FocusScope {
    id: root

    default property alias content: contentItem.data
    property alias titleBar: titleBarContainer.data

    signal activated
    signal currentItemChanged

    Component.onCompleted: {
        if (root.parent === null || root.parent.toString().substring(0, 9) !== "StackView")
            root.activated()
    }

    Connections {
        target: root.parent !== null && root.parent.toString().substring(0, 9) === "StackView" ? root.parent : root

        onCurrentItemChanged: {
            if (root.parent.currentItem === root)
                root.activated()
        }
    }

    FocusScope {
        id: titleBarContainer

        height: childrenRect.height
        width: parent.width
    }

    FocusScope {
        id: contentItem

        anchors {
            top: titleBarContainer.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
    }
}
