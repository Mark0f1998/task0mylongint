#include "../common/longarithm.hpp"
using namespace mli;
int main()
{
    mylonginteger *a=new mylonginteger;
    a->read_longinteger();
    a->write_longinteger();
    delete a;
}
