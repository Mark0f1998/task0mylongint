#include "../common/longarithm.hpp"
using namespace mli;
int main()
{
    mylonginteger a;
    for(int i=0;i<5;i++)
    {
        std::cout<<"enter new longint\n";
        a.read_longinteger();
        std::cout<<"a= ";
        a.write_longinteger();
        std::cout<<'\n';
    }
}
