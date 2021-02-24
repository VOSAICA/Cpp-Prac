class Y;

class X
{
public:
    Y* Y_ptr;
};

class Y
{
public:
    X X_item;
};

int main()
{
    Y y;
    X x;
    x.Y_ptr = &y;
    y.X_item = x;

    return 0;
}
