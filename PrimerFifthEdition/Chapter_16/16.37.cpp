#include <algorithm>

/*
template< class T >
const T& max( const T& a, const T& b );
*/

int main()
{
    std::max(3, 1l); // 不可以

    return 0;
}
