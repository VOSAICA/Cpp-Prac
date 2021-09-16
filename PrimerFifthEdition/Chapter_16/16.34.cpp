template <class T>
int compare(const T&, const T&);

int main()
{
    char ar[5] = "abcd";
    compare("hi", "world"); // char[3]和char[6]
    compare("bye", "dad");
}
