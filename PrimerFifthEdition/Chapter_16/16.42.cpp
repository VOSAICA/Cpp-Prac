template <typename T>
void g(T&& val);

int i = 0;
const int ci = i;

int main()
{
    g(i);      // T:int&        val:int& && collapsing to int&
    g(ci);     // T:const int&  val:const int& && collapsing to const int&
    g(i * ci); // T:int         val:int&& && collapsing to int&&

    return 0;
}
