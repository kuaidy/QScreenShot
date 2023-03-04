import QtQuick 2.0

Item {
    id:aboutItme
    Column {
        id: column
        spacing: 2
        width: parent.width
        anchors.verticalCenter: parent.verticalCenter
        Text {
            text: qsTr("QScreenShot");
            font.bold: true
            font.pointSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            text: qsTr("版本 V1.0");
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            text: "copyright@2022";
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            text: qsTr("邮箱：kuaidongyi@gmail.com");
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            text: "<a href='https://github.com/kuaidy/QScreenShot'>Github：https://github.com/kuaidy/QScreenShot</a>"
            anchors.horizontalCenter: parent.horizontalCenter
            onLinkActivated: Qt.openUrlExternally(link);
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.9;height:480;width:640}
}
##^##*/
