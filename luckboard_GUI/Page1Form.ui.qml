import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {

    width: 720
    property alias grid: grid
    property string ctext: ""

    Image {
        id: image1
        width: 720
        height: 480
        source: "wall.jpg"

        Image {
            id: image2
            x: 8
            y: 8
            width: 704
            height: 75
            source: "sheep.png"
        }
    }

    Image {
        id: image
        x: 0
        y: 67
        width: 720
        height: 413
        source: "blackboard.png"

        Text {
            id: text2
            x: 80
            y: 94
            width: 59
            height: 38
            color: "#c2c2c2"
            text: qsTr("第:")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        Text {
            id: text3
            x: 310
            y: 94
            width: 56
            height: 38
            color: "#c2c2c2"
            text: qsTr("组")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        Switch {
            id: model
            x: 506
            y: 316
            checked: false
        }

        Text {
            id: text1
            x: 80
            y: 48
            width: 588
            height: 26
            color: "#f20000"
            font.pointSize: 15
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
    }

    Text {
        id: column
        x: 145
        y: 162
        width: 162
        height: 38
        color: "#c2c2c2"
        text: ctext
        styleColor: "#bebebe"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 20
    }

    Grid {
        id: grid
        x: 66
        y: 223
        width: 319
        height: 195
        spacing: 5
        rows: 4
        columns: 3
        transformOrigin: Item.Center

        Button {
            id: one
            text: qsTr("1")
            font.family: "Yahei"
            font.pointSize: 20
            onClicked: {
                ctext = ctext + one.text
            }
        }

        Button {
            id: two
            text: qsTr("2")
            font.pointSize: 20
            onClicked: {
                ctext += two.text
            }
        }

        Button {
            id: three
            text: qsTr("3")
            font.pointSize: 20
            onClicked: {
                ctext += three.text
            }
        }

        Button {
            id: four
            text: qsTr("4")
            font.pointSize: 20
            onClicked: {
                ctext += four.text
            }
        }

        Button {
            id: five
            text: qsTr("5")
            font.pointSize: 20
            onClicked: {
                ctext += five.text
            }
        }

        Button {
            id: six
            text: qsTr("6")
            font.pointSize: 20
            onClicked: {
                ctext += six.text
            }
        }

        Button {
            id: seven
            text: qsTr("7")
            font.pointSize: 20
            onClicked: {
                ctext += seven.text
            }
        }

        Button {
            id: eight
            text: qsTr("8")
            font.pointSize: 20
            onClicked: {
                ctext += eight.text
            }
        }

        Button {
            id: nine
            text: qsTr("9")
            font.pointSize: 20
            onClicked: {
                ctext += nine.text
            }
        }

        Button {
            id: zero
            x: 50
            text: qsTr("0")
            font.pointSize: 20
            onClicked: {
                ctext += zero.text
            }
        }

        Button {
            id: del
            text: qsTr("删 除")
            font.pointSize: 15
            onClicked: {
                ctext = ""
            }
        }
    }

    Text {
        id: a
        x: 427
        y: 162
        width: 239
        height: 83
        color: "#c2c2c2"
        text: qsTr("NULL")
        styleColor: "#bebebe"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 30
    }

    Text {
        id: model1
        x: 450
        y: 393
        width: 61
        height: 27
        color: "#c2c2c2"
        text: qsTr("组模式")
        styleColor: "#bebebe"
        font.pointSize: 10
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: model2
        x: 574
        y: 395
        width: 61
        height: 23
        color: "#c2c2c2"
        text: qsTr("班模式")
        styleColor: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 10
    }

    Button {
        id: start
        x: 475
        y: 275
        width: 145
        height: 59
        text: qsTr("开 始(〃'▽'〃)~")
        font.pointSize: 10
        onClicked: {
            if (model.checked === false) {
                a.text = mymod.luckg(column.text)
            } else
                a.text = mymod.luckc()
        }
    }
}
