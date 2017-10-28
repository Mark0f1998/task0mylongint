//Zalmanov Dmitry Task#0 arithmetic of long integers
#ifndef LONGARITHM_HPP
#define LONGARITHM_HPP
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
namespace mli
{
    class mylonginteger
    {
    private:
        char* p;
        std::size_t n,capacity;
    public:
        std::size_t get_n()
        {
            return n;
        }
        std::size_t get_capacity()
        {
            return capacity;
        }
        mylonginteger();
        mylonginteger(const char* str);
        ~mylonginteger();
        void write_longinteger();
        bool IsEqual(const mylonginteger* right);// compares two mylongintegers NEEED TO FIXXXXX WITH [] PRIVATE
        void summ(mylonginteger* right);
        void read_longinteger();
        mylonginteger(const mylonginteger& right);
        mylonginteger(mylonginteger&& right);
        mylonginteger& operator = (const mylonginteger& right);
        mylonginteger& operator = (mylonginteger&& right);
        void operator +=(const mylonginteger& right);

    };
}
#endif // LONGARITHM_HPP
