#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QFile>
#include <QResource>
#include <QDir>
#include "historydatagetter.h"
#include "historydataparser.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    auto dir = QDir(qApp->applicationDirPath(),"*.ttf *.otf");
    if (dir.cd("font")){
        dir.setNameFilters({"*.ttf","*.otf"});
        auto fontFiles = dir.entryInfoList();
        for (auto i : fontFiles)
            QFontDatabase::addApplicationFont(i.filePath());
    }

    QGuiApplication::setFont(QFont("Noto Sans CJK SC Regular"));

    QQmlApplicationEngine engine;

    HistoryDataGetter historyDataGetter(HistoryDataParser::fromJsonFile(":/data.json"),engine.rootContext());
    engine.rootContext()->setContextProperty("HistoryDataGetter",&historyDataGetter);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}
