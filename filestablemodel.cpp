#include "filestablemodel.h"

FilesTableModel::FilesTableModel(QObject* parent):
    QAbstractTableModel(parent)
{

}


QVariant FilesTableModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (index.column())
        {
            case 0:
                return QString::fromStdWString(filesList.at(index.row()).getName());
                break;
            case 1:
                return SystemTimeToQDateTime(filesList.at(index.row()).getDate()).toString();
                break;
            case 2:
                return filesList.at(index.row()).getSize();
                break;
            case 3:
                return QString::fromStdWString(filesList.at(index.row()).getPath());
                break;
            default:
                break;
        }
    }
    return QVariant();
}

int FilesTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return filesList.size();
}

int FilesTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant FilesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch (section) {
            case 0:
                return QString("Name");
                break;
            case 1:
                return QString("Date");
                break;
            case 2:
                return QString("Size");
                break;
            case 3:
                return QString("Path");
                break;
            default:
                break;
            }
        }
    }
    return QVariant();
}
