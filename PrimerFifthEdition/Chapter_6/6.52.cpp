void manip(int, int){};
double dobj;

int main()
{
    manip('a', 'z');   //三级，类型提升
    manip(55.4, dobj); //四级，算数类型转换

    return 0;
}
