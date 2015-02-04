import QtQuick 2.4
import QtGraphicalEffects 1.0

Item {
    id: root

    property variant source
    property variant mask

    ShaderEffectSource {
        id: maskSource
        sourceItem: root.mask
    }

    ShaderEffect {
        id: shaderItem

        property variant source: root.source
        property variant mask: maskSource

        anchors.fill: parent

        fragmentShader: "
            varying highp vec2 qt_TexCoord0;
            uniform highp float qt_Opacity;
            uniform lowp sampler2D source;
            uniform lowp sampler2D mask;
            void main() {
                highp vec4 source_frag = texture2D(source, qt_TexCoord0.st);
                highp vec4 mask_frag = texture2D(mask, qt_TexCoord0.st);
                source_frag.a -= mask_frag.a;
                gl_FragColor =  source_frag * qt_Opacity;
            }"
    }
}
