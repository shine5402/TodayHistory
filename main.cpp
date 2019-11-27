#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QFontDatabase::addApplicationFont("qrc:/font/NotoSansCJKsc-Black.otf");
    QFontDatabase::addApplicationFont("qrc:/font/NotoSansCJKsc-Bold.otf");
    QFontDatabase::addApplicationFont("qrc:/font/NotoSansCJKsc-Light.otf");
    QFontDatabase::addApplicationFont("qrc:/font/NotoSansCJKsc-Medium.otf");
    QFontDatabase::addApplicationFont("qrc:/font/NotoSansCJKsc-Regular.otf");
    QFontDatabase::addApplicationFont("qrc:/font/NotoSansCJKsc-Thin.otf");

    QGuiApplication::setFont(QFont("Noto Sans CJK SC"));

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
