#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeEngine>
#include <QDeclarativeContext>

#include "helper.h"

int main(int argc, char *argv[]) noexcept {
    QApplication app(argc, argv);
    QDeclarativeView viewer;
    Helper helper;
    viewer.rootContext()->setContextProperty("Helper", &helper);
    viewer.setAttribute(Qt::WA_OpaquePaintEvent);
    viewer.setAttribute(Qt::WA_NoSystemBackground);
    viewer.viewport()->setAttribute(Qt::WA_OpaquePaintEvent);
    viewer.viewport()->setAttribute(Qt::WA_NoSystemBackground);
    viewer.setContextMenuPolicy(Qt::NoContextMenu);
    viewer.setSource(QUrl(QLatin1String("qrc:/qml/main.qml")));
    viewer.showFullScreen();
    return app.exec();
}
