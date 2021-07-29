class Base
{
public:
    virtual int fcn();
};

class D1 : public Base
{
public:
    int fcn() override;
    virtual void f2();
};

class D2 : public D1
{
public:
    int fcn(int);
    int fcn() override;
    void f2() override;
};

int main()
{
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base* bp1 = &bobj;
    Base* bp2 = &d1obj;
    Base* bp3 = &d2obj;

    bp1->fcn(); // Base::fcn()
    bp2->fcn(); // D1::fcn()
    bp3->fcn(); // D2::fcn()

    D1* d1p = &d1obj;
    D2* d2p = &d2obj;

    d1p->f2(); // D1::f2()
    d2p->f2(); // D2::f2()

    Base* p1 = &d2obj;
    D1* p2 = &d2obj;
    D2* p3 = &d2obj;

    p1->fcn();   // Base::fcn()
    p2->fcn();   // D1::fcn()
    p3->fcn(42); // D2::fcn(int) 非虚函数，静态绑定

    return 0;
}
