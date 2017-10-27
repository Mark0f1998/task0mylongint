#include "../common/longarithm.hpp"
int main()
{
    //test 1
    {
        mli::mylonginteger* a=mli::init();
        mli::mylonginteger* b=mli::init("0");
        //mli::write_longinteger(a);
        assert(mli::IsEqual(a,b));
        std::cout<<"test №1 completed\n";
        mli::destroy(a);
        mli::destroy(b);
    }

    //test 2
    {
        mli::mylonginteger* a=mli::init("0000000000123");
        mli::mylonginteger* b=mli::init("123");
        assert(mli::IsEqual(a,b));
        std::cout<<"test №2 completed\n";
        mli::destroy(a);
        mli::destroy(b);
    }

    //test 3
    {
        mli::mylonginteger* a=mli::init("123");
        mli::mylonginteger* b=mli::init("00");
        mli::mylonginteger* c=mli::init("123");
        mli::summ(a,b);
        assert(mli::IsEqual(a,c));
        std::cout<<"test №3 completed\n";
        mli::destroy(a);
        mli::destroy(b);
        mli::destroy(c);
    }

    //test 4
    {
        mli::mylonginteger* a=mli::init("90");
        mli::mylonginteger* b=mli::init("33");
        mli::mylonginteger* c=mli::init("123");
        mli::summ(a,b);
        assert(mli::IsEqual(a,c));
        std::cout<<"test №4 completed\n";
        mli::destroy(a);
        mli::destroy(b);
        mli::destroy(c);
    }

    //test 5
    {
        mli::mylonginteger* a=mli::init("999");
        mli::mylonginteger* b=mli::init("33");
        mli::mylonginteger* c=mli::init("1032");
        mli::summ(a,b);
        assert(mli::IsEqual(a,c));
        std::cout<<"test №5 completed\n";
        mli::destroy(a);
        mli::destroy(b);
        mli::destroy(c);
    }

    //test 6
    {
        mli::mylonginteger* a=mli::init("99");
        mli::mylonginteger* b=mli::init("999");
        mli::mylonginteger* c=mli::init("1098");
        mli::summ(a,b);
        assert(mli::IsEqual(a,c));
        std::cout<<"test №6 completed\n";
        mli::destroy(a);
        mli::destroy(b);
        mli::destroy(c);
    }
}
