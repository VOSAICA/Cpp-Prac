struct LongDouble
{
    LongDouble(double = 0.0);
    operator double();
    operator float();
};

void calc(int);
void calc(LongDouble);

int main()
{
    double dval;
    calc(dval); // dval到int，或者dval到LongDouble

    return 0;
}

/*
考虑优先度
exact match
const conversion
promotion
arithmetic or pointer conversion
class-type conversion
*/
