import QtQuick 2.3

Item {
    property alias color: bakground.color
    property color borderColor: "#3498db"
    property alias highlightOpacity: effect.opacity
    property Item highlightedItem
    property Item mapFrom
    property bool blockMouseInput: false

    property int mappedX: getAbsoluteX(highlightedItem)
    property int mappedY: getAbsoluteY(highlightedItem)

    function getAbsoluteX(item) {
        if (item !== undefined && mapFrom !== undefined)
            return mapFrom.mapFromItem(item, 0, 0).x
        else
            return 0
    }

    function getAbsoluteY(item) {
        if (item !== undefined && mapFrom !== undefined)
            return mapFrom.mapFromItem(item, 0, 0).y
        else
            return 0
    }

    anchors.fill: parent

    onHighlightedItemChanged: {
        mappedX = getAbsoluteX(highlightedItem)
        mappedY = getAbsoluteY(highlightedItem)
    }

    Connections {
        target: highlightedItem

        onXChanged: mappedX = getAbsoluteX(highlightedItem)
        onYChanged: mappedY = getAbsoluteY(highlightedItem)

        onHeightChanged: {
            mappedX = getAbsoluteX(highlightedItem)
            mappedY = getAbsoluteY(highlightedItem)
        }

        onWidthChanged: {
            mappedX = getAbsoluteX(highlightedItem)
            mappedY = getAbsoluteY(highlightedItem)
        }
    }

    Rectangle {
        id: bakground
        anchors.fill: parent
        color: "#2c3e50"
        visible: false
    }

    Rectangle {
        id: maskItem

        anchors.fill: parent
        color: "transparent"
        visible: false

        Rectangle {
            x: highlightedItem !== undefined ? mappedX + highlightedItem.width / 2 - width / 2 : 0
            y: highlightedItem !== undefined ? mappedY + highlightedItem.height / 2 - height / 2 : 0
            width: highlightedItem !== undefined ? highlightedItem.width * 1.2 : 0
            height: highlightedItem !== undefined ? highlightedItem.height * 1.2 : 0
            radius: height / 2
        }
    }

    SubtractMask {
        id: effect
        source: bakground
        mask: maskItem
        anchors.fill: parent
        opacity: 0.5
    }

    Rectangle {
        id: borderHighlighter
        x: highlightedItem !== undefined ? mappedX + highlightedItem.width / 2 - width / 2 : 0
        y: highlightedItem !== undefined ? mappedY + highlightedItem.height / 2 - height / 2 : 0
        width: highlightedItem !== undefined ? highlightedItem.width * 1.2 : 0
        height: highlightedItem !== undefined ? highlightedItem.height * 1.2 : 0
        radius: Math.min(height, width) / 2
        color: "transparent"
        border {
            width: 3 * ui.dpMultiplier
            color: borderColor
        }
    }

    MouseArea {
        anchors {
            top: borderHighlighter.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        enabled: blockMouseInput
    }

    MouseArea {
        anchors {
            top: parent.top
            bottom: borderHighlighter.top
            left: parent.left
            right: parent.right
        }

        enabled: blockMouseInput
    }

    MouseArea {
        anchors {
            top: parent.top
            bottom: bottom.top
            left: borderHighlighter.right
            right: parent.right
        }

        enabled: blockMouseInput
    }

    MouseArea {
        anchors {
            top: parent.top
            bottom: bottom.top
            left: parent.left
            right: borderHighlighter.left
        }

        enabled: blockMouseInput
    }
}
