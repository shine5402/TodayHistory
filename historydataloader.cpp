#include "historydataloader.h"

HistoryDataLoader::HistoryDataLoader(QObject *parent) : QObject(parent)
{

}

bool HistoryDataLoader::isReady() const
{
    return m_isReady;
}

void HistoryDataLoader::loadData()
{
    auto thread = QThread::create(&HistoryDataLoader::loadDataPrivate,this);
    thread->start();
}

void HistoryDataLoader::loadDataPrivate()
{
    historyDataGetter = new HistoryDataGetter(HistoryDataParser::fromJsonFile(":/data.json"),this);
    m_isReady = true;
    emit isReadyChanged();
}
