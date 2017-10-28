#include "../common/longarithm.hpp"
using namespace mli;
int main()
{
    mylonginteger a,b;
    a.read_longinteger();
    b.read_longinteger();
    a+=b;
    a.write_longinteger();
}
