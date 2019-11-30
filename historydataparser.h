#ifndef HISTORYDATAPARSER_H
#define HISTORYDATAPARSER_H

#include <QObject>
#include "historyitem.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>

class HistoryDataParser : public QObject
{
    Q_OBJECT
public:
    explicit HistoryDataParser(QObject *parent = nullptr);

signals:

public slots:
    static HistoryItem fromJsonObject(QJsonObject obj);
    static HistoryItemList fromJsonArray(QJsonArray array);
    static HistoryItemList fromJsonDocument(QJsonDocument doc);
    static HistoryItemList fromJsonString(QString str);
    static HistoryItemList fromJsonFile(QString fileName);
};

#endif // HISTORYDATAPARSER_H
