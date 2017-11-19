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
        std::size_t get_n() const
        {
            return n;
        }
        std::size_t get_capacity() const
        {
            return capacity;
        }
        mylonginteger();
        mylonginteger(const char* str);
        ~mylonginteger();
        void write_longinteger();
        bool IsEqual(const mylonginteger& right);
        void summ(mylonginteger* right);
        void read_longinteger();
        mylonginteger(const mylonginteger& right);
        mylonginteger(mylonginteger&& right);
        mylonginteger& operator = (const mylonginteger& right);
        mylonginteger& operator = (mylonginteger&& right);
        void operator +=(const mylonginteger& right);
        friend std::ostream& operator << (std::ostream& os,const mylonginteger& mli);
        friend std::ostream& operator >> (std::istream& is,const mylonginteger& mli);
        char& operator [](int i) const;
    };
}
#endif // LONGARITHM_HPP
