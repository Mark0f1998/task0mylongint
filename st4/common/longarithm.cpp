#include "longarithm.hpp"
//#define DEBUG
using st=std::size_t;
char* skip_zeros(char* str)
{
    int zeros_value=0;
    st len=std::strlen(str);
    if(str[0]=='0')
    {
        zeros_value++;
    }
    else return str;
    for(st i=1;i<len;i++)
    {
        if(str[i]=='0') zeros_value++;
        else break;
    }
    char* without_zeros=new char[len-zeros_value+1];
    for(st i=0;i<len-zeros_value;i++)
    {
        without_zeros[i]=str[i+zeros_value];
    }
    without_zeros[len-zeros_value]='\0';
    return without_zeros;
}

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
    :
     mylonginteger()
    {
        p=new char[right.capacity];
        if(this==&right) return;
        n=right.n;
        capacity=right.capacity;
        for(std::size_t i=0;i<n;i++)
        {
            p[i]=right.p[i];
        }
    }
    mylonginteger::mylonginteger(mylonginteger&& right)
        :
             mylonginteger()
    {
        if(this==&right) return;
        n=right.n;
        capacity=right.capacity;
        p=right.p;
        right.n=0;
        right.capacity=0;
        right.p=nullptr;
    }
    mylonginteger& mylonginteger::operator = (const mylonginteger& right)
    {
        std::cout<<"called lvalue\n";
        if(this==&right) return *this;
        n=right.n;
        capacity=right.capacity;
        for(std::size_t i=0;i<n;i++)
        {
            p[i]=right.p[i];
        }
        return *this;
    }
    mylonginteger& mylonginteger::operator = (mylonginteger&& right)
    {
        std::cout << "called rvalue\n";
        if(this==&right) return *this;
        n=right.n;
        capacity=right.capacity;
        p=right.p;
        right.n=0;
        right.capacity=0;
        right.p=nullptr;
        return *this;
    }
    /*mylonginteger mylonginteger::operator +=(const mylonginteger& right)
    {
        std::size_t ln=n;
        std::size_t rn=right.n;

    }*/

    mylonginteger::~mylonginteger()
    {
        delete [] p;
        n=0;
        capacity=0;
    }
    void mylonginteger::write_longinteger()
    {
        char *new_p=skip_zeros(p);
        for(std::size_t i =0;i<n;i++)
        {
            std::cout<<new_p[i];
        }
        std::cout<<'\n';
    }
    bool mylonginteger::IsEqual(const mylonginteger *right)
    {
        if (n!=right->n) { std::cout<<"Not Equal\n"; return false; }

        for(std::size_t i=0;i<n;i++)
        {
            if(p[i]!=right->p[i]) { std::cout<<"Not Equal\n"; return false; }
        }
        std::cout <<"Equal\n";
        return true;
    }
    void mylonginteger::read_longinteger()
    {
        char* inp=get_string();
        inp=skip_zeros(inp);
        std::size_t length=std::strlen(inp);
        if(length<=capacity)
        {
            n=length;
            for(std::size_t i=0;i<capacity-length;i++)
            {
                p[i]='0';
            }
            for(std::size_t j=capacity-length;j<capacity;j++)
            {
                p[j]=inp[j-(capacity-length)];
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
        delete [] inp;
    }
}
