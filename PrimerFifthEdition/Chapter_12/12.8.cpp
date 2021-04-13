bool b()
{
    int* p = new int;
    return p;
}

int main()
{
    auto a = b();
    delete a;
    // int*被转换成了bool，这里delete不了了

    return 0;
}
