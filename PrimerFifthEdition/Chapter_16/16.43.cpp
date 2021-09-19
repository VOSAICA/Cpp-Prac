template <typename T>
void g(T&& val);

int i = 0;
const int ci = i;

int main()
{
    g(i = ci); // T:int&  val:int& && collapsing to int&

    return 0;
}
