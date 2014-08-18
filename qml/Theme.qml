pragma Singleton
import QtQuick 2.2

QtObject {
    property color titleBarColor: "#738a95"
    property color titleBarTextColor: "#ffffff"

    function getContrastYIQ(color){
        var colorStr = color.toString().substr(1)
        var r = parseInt(colorStr.substr(0,2),16)
        var g = parseInt(colorStr.substr(2,2),16)
        var b = parseInt(colorStr.substr(4,2),16)
        var yiq = ((r * 299) + (g * 587) + (b * 114)) / 1000
        return (yiq >= 128) ? 'black' : 'white'
    }
}
