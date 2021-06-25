struct LongDouble{
    LongDouble(double=0.0);
    operator double();
    operator float();
};

LongDouble ldObj;
int ex1 = ldObj; // 可能从double到int，也可能从float到int
float ex2 = ldObj;
