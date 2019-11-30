#include "historydataparser.h"

HistoryDataParser::HistoryDataParser(QObject *parent) : QObject(parent)
{

}

HistoryItem HistoryDataParser::fromJsonObject(QJsonObject obj)
{
    return HistoryItem(obj.value("day").toInt(),
                       obj.value("des").toString(),
                       obj.value("hits").toInt(),
                       obj.value("id").toInt(),
                       obj.value("month").toInt(),
                       obj.value("pic").toString(),
                       obj.value("title").toString(),
                       obj.value("url").toString(),
                       obj.value("year").toInt());
}

HistoryItemList HistoryDataParser::fromJsonArray(QJsonArray array)
{
    HistoryItemList result;
    for (auto item : array)
    {
        auto obj = item.toObject();
        result.append(fromJsonObject(obj));
    }
    return result;
}

HistoryItemList HistoryDataParser::fromJsonDocument(QJsonDocument doc)
{
    if (doc.isArray())
        return fromJsonArray(doc.array());
    else if (doc.isObject())
        return HistoryItemList{fromJsonObject(doc.object())};
    return HistoryItemList{};
}

HistoryItemList HistoryDataParser::fromJsonString(QString str)
{
    return fromJsonDocument(QJsonDocument::fromJson(str.toUtf8()));
}

HistoryItemList HistoryDataParser::fromJsonFile(QString fileName)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    auto data = file.readAll();
    QJsonParseError error;
    auto result = fromJsonDocument(QJsonDocument::fromJson(data,&error));
    return result;
}


