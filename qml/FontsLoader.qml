import QtQuick 2.5

Item {
    id: root

    property var fonts: []
    property var families: []

    signal loaded

    Repeater {
        id: repeater

        model: fonts

        Item {
            FontLoader {
                source: modelData
                onStatusChanged: {
                    if (status === FontLoader.Ready) {
                        if (families.indexOf(name) === -1) {
                            var fam = families
                            fam.push(name)
                            families = fam
                        }

                        if (index === fonts.length - 1)
                            root.loaded()
                    }
                }
            }
        }
    }
}

