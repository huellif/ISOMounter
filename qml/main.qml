import QtQuick 1.1;
import com.nokia.symbian 1.1;

PageStackWindow{
    initialPage:Page{
        id: mp
        tools:ToolBarLayout{
            ToolButton{
                iconSource:"toolbar-back";
                onClicked:Qt.quit();
            }
            ToolButton{
                iconSource:"toolbar-menu";
                onClicked: Qt.createComponent("MainSubMenuhuellif.qml").createObject(mp);
            }
        }
        Text{
            id:current;
            horizontalAlignment: Text.AlignHCenter;
            text: loadCurrentFile();
            anchors.right: parent.right;
            anchors.left: parent.left;
            anchors.topMargin: 5;
            font.italic: true;
            font.pixelSize: platformStyle.fontSizeMedium;
            color: "LightSeaGreen";
            elide: Text.ElideRight;
            wrapMode: Text.WordWrap;
            textFormat: Text.PlainText
            maximumLineCount: 5
        }
        Button{
            id: b1;
            text :qsTr("Use phone as modem (default)");
            anchors.right: parent.right;
            anchors.left: parent.left;
            anchors.top: current.bottom;
            anchors.topMargin: 15;
            onClicked:if(Helper.reset("0x2000fda8","0x1")){
                          Helper.success();
                          loadCurrentFile();
                        }
        }
        Button{
            id:b2;
            text:qsTr("Choose an .iso file");
            anchors.right: parent.right;
            anchors.left: parent.left;
            anchors.top: b1.bottom;
            anchors.topMargin: 15;
            onClicked:if(Helper.setiso()){
                          Helper.success();
                          loadCurrentFile();
                      }
        }
        Text{
            horizontalAlignment: Text.AlignHCenter;
            text: qsTr("Changing this while using Phone As Modem USB-Mode doesn't work!");
            anchors.right: parent.right;
            anchors.left: parent.left;
            anchors.top: b2.bottom;
            anchors.topMargin: 20;
            font.pixelSize: platformStyle.fontSizeMedium;
            color: "#FFFFFF";
            elide: Text.ElideRight;
            wrapMode: Text.WordWrap;
            textFormat: Text.PlainText
            maximumLineCount: 3
        }
    }
    function loadCurrentFile() {
        current.text=qsTr("Current file:\n")+Helper.getiso();
    }
}
