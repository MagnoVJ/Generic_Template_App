import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Dialogs

ApplicationWindow {

    visible: true
    width: 400
    height: 300
    title: "Customizable LineEdit Example"
    color: "#f5f5f5" // Light background

    onClosing: {
        interfaceHelper.windowClosing()
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        TextField {
            id: lineEdit1
            placeholderText: "Entre com o primeiro valor"
            Layout.fillWidth: true
            font.pixelSize: 16
            background: Rectangle {
                color: "#ffffff"
                radius: 5
                border.color: "#cccccc"
            }
        }

        TextField {
            id: lineEdit2
            placeholderText: "Entre com o segundo valor"
            Layout.fillWidth: true
            font.pixelSize: 16
            background: Rectangle {
                color: "#ffffff"
                radius: 5
                border.color: "#cccccc"
            }
        }

        Button {
            text: "Confirmar"
            Layout.fillWidth: true
            onClicked: {
                interfaceHelper.processInput(lineEdit1.text, lineEdit2.text)
                //console.log("LineEdit 1: ", lineEdit1.text)
                //console.log("LineEdit 2: ", lineEdit2.text)
                //Qt.callLater(function() {
                    //Custom JS logic
                    //messageDialog.text = `Você entrou:\n1.${lineEdit1.text}\n2.${lineEdit2.text}`
                    //messageDialog.open()
                //})
            }
        }
    }

    MessageDialog {
        id:messageDialog
        title: "Resultado da Entrada"
        text: ""
        buttons: MessageDialog.Ok
    }
}
