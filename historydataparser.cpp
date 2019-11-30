#include "historydataparser.h"

HistoryItemRef HistoryDataParser::fromJsonObject(QJsonObject obj, QObject* parent)
{
    return new HistoryItem(obj.value("day").toInt(),
                           obj.value("des").toString(),
                           obj.value("hits").toInt(),
                           obj.value("id").toInt(),
                           obj.value("month").toInt(),
                           obj.value("pic").toString(),
                           obj.value("title").toString(),
                           obj.value("url").toString(),
                           obj.value("year").toInt(),
                           parent);
}

HistoryItemRefList HistoryDataParser::fromJsonArray(QJsonArray array, QObject* parent)
{
    HistoryItemRefList result;
    for (auto item : array)
    {
        auto obj = item.toObject();
        result.append(fromJsonObject(obj,parent));
    }
    return result;
}

HistoryItemRefList HistoryDataParser::fromJsonDocument(QJsonDocument doc, QObject* parent)
{
    if (doc.isArray())
        return fromJsonArray(doc.array(),parent);
    else if (doc.isObject())
        return HistoryItemRefList{fromJsonObject(doc.object(),parent)};
    return HistoryItemRefList{};
}

HistoryItemRefList HistoryDataParser::fromJsonString(QString str, QObject* parent)
{
    return fromJsonDocument(QJsonDocument::fromJson(str.toUtf8()),parent);
}

HistoryItemRefList HistoryDataParser::fromJsonFile(QString fileName, QObject* parent)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    auto data = file.readAll();
    QJsonParseError error;
    auto result = fromJsonDocument(QJsonDocument::fromJson(data,&error),parent);
    return result;
}


