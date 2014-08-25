pragma Singleton
import QtQuick 2.3

QtObject {
    property color titleBarColor: "#738a95"
    property color titleBarTextColor: "#ffffff"
    property color backgroundColor: "#e5e5e5"

    function getContrastColor(color){
        var colorStr = color.toString().substr(1)
        var r = parseInt(colorStr.substr(0,2),16)
        var g = parseInt(colorStr.substr(2,2),16)
        var b = parseInt(colorStr.substr(4,2),16)
        var yiq = ((r * 299) + (g * 587) + (b * 114)) / 1000
        return (yiq >= 128) ? 'black' : 'white'
    }

    function getBestIconSize(height) {
        if (height < 42)
            return "ldpi/"
        else if (height < 60)
            return "mdpi/"
        else if (height < 84)
            return "hdpi/"
        else if (height < 120)
            return "xhdpi/"
        else if (height < 168)
            return "xxhdpi/"
        else if (height < 216)
            return "xxxhdpi/"
        else
            return "";
    }
}
