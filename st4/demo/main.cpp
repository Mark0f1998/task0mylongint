#include "../common/longarithm.hpp"
int main()
{
    //std::cin>>n;
    mli::mylonginteger* a, *b;
    a=mli::init();
    b=mli::init();
    //std::cout<<"current capacity= "<<mli::get_capac(a)<<'\n';
    int p=mli::read_longinteger(a);
    if(p<0) { std::cout<< "input fail\n"; return 0; }
    //mli::write_longinteger(a);
    std::cout<<p;
    while(1)
    {
        //b=mli::init();
        //std::cout<<"current capacity= "<<mli::get_capac(a)<<'\n';
        int p=mli::read_longinteger(b);
        if(p<0) { std::cout<< "input fail\n"; return 0; }
        mli::summ(a,b);
        //mli::destroy(b);
        std::cout<<"current summ= ";
        mli::write_longinteger(a);
    }
    mli::destroy(a);
}
