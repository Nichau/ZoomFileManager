import QtQuick 1.0

Rectangle {
    id: main
    width: 900
    height: 700
    color: "grey"
    gradient: Gradient {
             GradientStop { position: 0.0; color: "black" }
             GradientStop { position: 1.0; color: "grey" }
    }
    Rectangle {
        id: topmenu
        width: 880
        height: 100
        radius: 3
        anchors.horizontalCenter: main.horizontalCenter
        anchors.top: main.top
        anchors.topMargin: 10
        color: "#cccccc"
        Image {
             source: "images/play.png"
             width: 80
             height: 80
             smooth: true
             anchors.verticalCenter: topmenu.verticalCenter
             anchors.left: topmenu.left
             anchors.leftMargin: 10
             MouseArea {
                      anchors.fill: parent
                      onPressed: { parent.opacity = 0.5 }
                      onReleased: { parent.opacity = 1 }
                  }
         }
        Text {
            text: "Task manager"
            font.family: "Arial"
            font.pointSize: 48
            anchors.verticalCenter: topmenu.verticalCenter
            anchors.horizontalCenter: topmenu.horizontalCenter
        }
        Image {
             source: "images/settings.png"
             width: 80
             height: 80
             smooth: true
             anchors.verticalCenter: topmenu.verticalCenter
             anchors.right: topmenu.right
             anchors.rightMargin:10
             MouseArea {
                      anchors.fill: parent
                      onPressed: { parent.opacity = 0.5 }
                      onReleased: { parent.opacity = 1 }
                  }
         }
    }
    Rectangle {
        id: content
        width: 880
        height: 570
        radius: 3
        anchors.horizontalCenter: main.horizontalCenter
        anchors.top: topmenu.bottom
        anchors.topMargin: 10
        color: "#cccccc"
        Grid {
            columns:  3
            spacing: 2
        }
        ListView {
             width: 180; height: 300
             model: sqlModel
             delegate: Text { text: active + " " + description + " " + commands }
             anchors.top: content.top
             anchors.left: content.left
             anchors.margins: 10
         }

    }
}
