#include <QtGui>

template <class L, class F, class iterator>
inline void map( F f, iterator first, iterator last, L& result )
{
    for ( iterator i = first, j = last; i != j; i++ )
        result << f(*i);
}

template <class L, class F>
inline L map( F f, const L& list )
{
    L result;
    map( f, list.begin(), list.end(), result );
    return result;
}

struct sum {
    sum( int i ) : i_v( i ){}
    int operator()( int i ){ return i_v + i; }
    int i_v;
};

int main( int argc, char** argv )
{
    QVector<int> vec;
    vec << 0 << 1 << 2 << 3 << 4 << 5;
    qDebug() << map( sum(2), vec );
    return 0;
}

