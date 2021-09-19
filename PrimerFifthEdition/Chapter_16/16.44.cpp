template <typename T>
void g(T val);

template <typename T>
void g1(const T& val);

int i = 0;
const int ci = i;

int main()
{
    g(i);      // T:int  val:int
    g(ci);     // T:int  val:int
    g(i * ci); // T:int  val:int

    g1(i);      // T:int  val:const int&
    g1(ci);     // T:int  val:const int&
    g1(i * ci); // T:int  val:const int&

    return 0;
}
