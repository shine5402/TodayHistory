#ifndef HISTORYDATAPARSER_H
#define HISTORYDATAPARSER_H

#include <QObject>
#include "historyitem.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>



class HistoryDataParser
{
public:
    HistoryDataParser() = delete;

public:
    static HistoryItemRef fromJsonObject(QJsonObject obj, QObject* parent = nullptr);
    static HistoryItemRefList fromJsonArray(QJsonArray array, QObject* parent = nullptr);
    static HistoryItemRefList fromJsonDocument(QJsonDocument doc, QObject* parent = nullptr);
    static HistoryItemRefList fromJsonString(QString str, QObject* parent = nullptr);
    static HistoryItemRefList fromJsonFile(QString fileName, QObject* parent = nullptr);
};

#endif // HISTORYDATAPARSER_H
