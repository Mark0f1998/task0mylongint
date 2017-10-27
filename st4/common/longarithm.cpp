#include "longarithm.hpp"
//#define DEBUG
using st=std::size_t;
char* get_string()
    {
        constexpr std::size_t initial_size = 4;
        char* buf = new char[initial_size];
        std::size_t used = 0,allocated = initial_size;
        std::cin >> std::noskipws;
        char c;
        while((std::cin>>c)&&c!='\n')
            {
                assert(!(c<47||c>58));
                if(used+2>allocated)
                    {
                        allocated = allocated*3/2;
                        char* new_buf = new char[allocated];
                        for(std::size_t i=0;i<used;++i)
                            {
                                new_buf[i] = buf[i];
                            }
                        delete[] buf;
                        buf = new_buf;

                    }
                buf[used++] = c;
            }
        std::cin >> std::skipws;
        if(!std::cin)
        {
            delete[] buf;
            buf = nullptr;
        }
        else
            buf[used] = '\0';


        return buf;
    }
namespace mli 
{
    mylonginteger::mylonginteger()
    {
        n=1;
        capacity=2;
        p=new char[2];
        p[0]='0';
        p[1]='\n';
    }
    mylonginteger::mylonginteger(const char* str)
    {
        std::size_t len=std::strlen(str);
        p=new char[len];
        std::strcpy(p,str);
        n=len;
        capacity=n+1;
    }
    mylonginteger::mylonginteger(const mylonginteger& right)
    \:
     mylonginteger()
    {
        p=new char[right.capacity];
        if(this==&right) return;
        n=right.n;
        capacity=right.capacity;
        for(int i=0;i<n;i++)
        {
            p[i]=right[i];
        }
    }
    mylonginteger::mylonginteger(mylonginteger&& right)
        :
             mylonginteger()
    {
        if(this==right) return;
        n=right.n;
        capacity=right.capacity;
        p=right.p;
        right.n=0;
        right.capacity=0;
        right.p=nullptr;
    }
    mylonginteger& mylonginteger::operator = (const mylonginteger& right)
    {
        if(this=&right) return *this;
        n=right.n;
        capacity=right.capacity;
        for(int i=0;i<n;i++)
        {
            p[i]=right[i];
        }
        return *this;
    }
    mylonginteger& mylonginteger::operator = (mylonginteger&& right)
    {
        if(this==&right) return *this;
        n=right.n;
        capacity=right.capacity;
        p=right.p;
        right.n=0;
        right.capacity=0;
        right.p=nullptr;
    }
    /*mylonginteger mylonginteger::operator +=(const mylonginteger& right)
    {
        std::size_t ln=n;
        std::size_t rn=right.n;
    }
*/
    mylonginteger::~mylonginteger()
    {
        delete [] p;
        n=0;
        capacity=0;
    }
    void mylonginteger::write_longinteger()
    {
        for(std::size_t i =0;i<n;i++)
        {
            std::cout<<p[i];
        }
        std::cout<<'\n';
    }
    bool mylonginteger::IsEqual(const mylonginteger *right)
    {
        if (n!=right->get_n()) return false;
        for(std::size_t i=0;i<n;i++)
        {
            if(p[i]!=right[i]) return false;
        }
        return true;
    }
    int mylonginteger::read_longinteger()
    {
        char* inp=get_string();
        std::size_t length=std::strlen(inp);
        if(length<=capacity)
        {
            n=capacity;
            for(std::size_t i=0;i<capacity-length;i++)
            {
                p[i]='0';
            }
            for(std::size_t j=capacity-length;j<capacity;j++)
            {
                p[i]=inp[j-(capacity-length)];
            }
        }
        else
        {
            delete [] p;
            p= new char[length+1];
            capacity=length+1;
            n=length;
            for(std::size_t i=0;i<n;i++)
            {
                p[i]=inp[i];
            }
        }
        delete [] input;
    }
}
