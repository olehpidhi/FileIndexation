#ifndef FILESTABLEMODEL_H
#define FILESTABLEMODEL_H
#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <deque>
#include "FileInfo.h"
#include <QVariant>
#include <QString>


class FilesTableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit FilesTableModel(QObject* parent = 0);

    std::deque<FileInfo> filesList;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    int rowCount ( const QModelIndex& parent = QModelIndex()) const;
    QVariant headerData(int section,Qt::Orientation orientation, int role = Qt::DisplayRole) const;

};

#endif // FILESTABLEMODEL_H
