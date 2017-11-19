 #include "../common/longarithm.hpp"
using namespace mli;
int main()
{
    //test 1
    {
        mylonginteger a("000000");
        mylonginteger b("00");
        assert(a.IsEqual(b));
    }

    //test 2
    {
        mylonginteger a("000000123");
        mylonginteger b("123");
        assert(a.IsEqual(b));
    }

    //test 3
    {
        mylonginteger a("123");
        mylonginteger b("00");
        mylonginteger c("123");
        a+=b;
        assert(a.IsEqual(c));
    }

    //test 4
    {
        mylonginteger a("93");
        mylonginteger b("100");
        mylonginteger c("193");
        a+=b;
        assert(a.IsEqual(c));
    }

    //test 5
    {
        mylonginteger a("999");
        mylonginteger b("33");
        mylonginteger c("1032");
        a+=b;
        assert(a.IsEqual(c));
    }

    //test 6
    {
        mylonginteger a("999");
        mylonginteger b("999");
        mylonginteger c("1998");
        a+=b;
        assert(a.IsEqual(c));
    }
    //test 7
    {
        mylonginteger a("1234");
        mylonginteger b=a;
        assert(a.IsEqual(b));
    }
    std::cout<<"all tests was passed! Congrats\n";
}
    /*mylonginteger a("0000123");
    mylonginteger b("123");
    a.write_longinteger();
    b.write_longinteger();
}*/
