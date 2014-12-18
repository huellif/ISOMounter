import QtQuick 1.1;
import com.nokia.symbian 1.1;

ContextMenu {
    MenuLayout {
        MenuItem {
            text: qsTr("ISOMounter v1.0.0 by Fabian")
            onClicked: Helper.loadPage("https://github.com/huellif");
        }

        MenuItem {
            text: qsTr("Email huellif@gmail.com");
            onClicked: Qt.openUrlExternally("mailto:huellif@gmail.com?subject=ISOMounter v1.0.0");
        }
        MenuItem {
            text: qsTr("Twitter @huellif");
            onClicked: Helper.loadPage("https://mobile.twitter.com/huellif");
        }
        MenuItem {
            text: qsTr("Donate via PayPal");
            onClicked: Helper.loadPage("https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=HJ62F4CEATR2N");
        }
    }
    Component.onCompleted: open();
    onStatusChanged: if(status===DialogStatus.Closing) destroy();
}
