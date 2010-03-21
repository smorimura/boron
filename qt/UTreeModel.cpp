

#include "UTreeModel.h"
#include "boron-qt.h"


extern QString qstring( const UCell* cell );


UTreeModel::UTreeModel( QObject* parent, const UCell* hdr, const UCell* data )
    : QAbstractItemModel( parent ) 
{
    UBlockIter bi;
    UThread* ut = qEnv.ut;

    _cols = 1;

    if( ur_is(hdr, UT_BLOCK ) )
    {
        ur_blkSlice( ut, &bi, hdr );
        ur_foreach( bi )
        {
            _hdr.append( qstring( bi.it ) );
        }
        if( _hdr.size() )
            _cols = _hdr.size();
    }

    if( ur_is(data, UT_BLOCK ) )
    {
        _blkN = data->series.buf;
        _hold = ur_hold( _blkN );

        const UBuffer* blk = ur_buffer( _blkN );
        _rows = blk->used / _cols;
    }
    else
    {
        _blkN = UR_INVALID_BUF;
        _hold = UR_INVALID_HOLD;
        _rows = 0;
    }
}


UTreeModel::~UTreeModel()
{
    if( _hold != UR_INVALID_HOLD )
    {
        UThread* ut = qEnv.ut;
        ur_release( _hold );
    }
}


static QVariant cellToVariant( const UCell* cell )
{
    switch( ur_type(cell) )
    {
        case UT_CHAR:
            return QChar( ur_int(cell) );
        case UT_INT:
            return ur_int(cell);
        case UT_DECIMAL:
            return ur_decimal(cell);
        default:
            return qstring( cell );
    }
}


QVariant UTreeModel::data( const QModelIndex& index, int role ) const
{
    if( index.isValid() )
    {
        if( role == Qt::DisplayRole )
        {
            UThread* ut = qEnv.ut;
            const UBuffer* blk = ur_buffer( _blkN );
            int i = (_cols * index.row()) + index.column();
            if( i < blk->used )
                return cellToVariant( blk->ptr.cell + i );
        }
    }
    return QVariant();
}


QVariant UTreeModel::headerData( int section, Qt::Orientation /*orientation*/,
                                 int role ) const
{
    switch( role )
    {
        case Qt::DisplayRole:
            return _hdr.value( section );
    }
    return QVariant();
}


QModelIndex UTreeModel::index( int row, int column,
                               const QModelIndex& /*parent*/ ) const
{
    return createIndex( row, column );
}


QModelIndex UTreeModel::parent( const QModelIndex& /*index*/ ) const
{
    return QModelIndex();
}


int UTreeModel::rowCount( const QModelIndex& parent ) const
{
    if( parent.isValid() )
        return 0;
    return _rows;
}


int UTreeModel::columnCount( const QModelIndex& parent ) const
{
    if( parent.isValid() )
        return 0;
    return _cols;
}


void UTreeModel::blockSlice( const QModelIndex& index, UCell* res )
{
    if( index.isValid() )
    {
        //UThread* ut = qEnv.ut;
        //const UBuffer* blk = ur_buffer( _blkN );
        int i = (_cols * index.row()) + index.column();
        //if( i < blk->used )
        {
            ur_setId(res, UT_BLOCK);
            ur_setSlice(res, _blkN, i, i + _cols );
        }
    }
    else
    {
        ur_setId(res, UT_NONE);
    }
}


//EOF