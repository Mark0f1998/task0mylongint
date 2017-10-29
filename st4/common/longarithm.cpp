#include "longarithm.hpp"
//#define DEBUG
using st=std::size_t;
char* skip_zeros(char* str)
{
    char* wtf=new char[2];
    wtf[0]='0';
    wtf[1]='\0';
    st zeros_value=0;
    st len=std::strlen(str);
    if(str[0]=='0')
    {
        zeros_value++;
    }
    else
    {
        delete [] wtf;
        return str;
    }
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
    if(zeros_value==len) { delete [] without_zeros; return wtf; }
    delete [] wtf;
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
        n=0;
        capacity=0;
        p=nullptr;
    }
    mylonginteger::mylonginteger(const char* str)
    {
        std::size_t len=std::strlen(str);
        p=new char[len];
        for(st i=0;i<=len;i++)
        {
            p[i]=str[i];
        }
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
    void mylonginteger::operator +=(const mylonginteger& right)
    {
        std::size_t ln=n;
        int ost=0;
        std::size_t rn=right.n;
        std::size_t maxlen=std::max(ln,rn);
        if(capacity>=maxlen+1)
        {          
                for(st i=1;i<=rn;i++)
                {
                    p[capacity-i-1]+=right.p[rn-i]-48+ost;
                    if(p[capacity-i-1]>=58)
                    {
                        ost=1;
                        p[capacity-i-1]-=10;
                    }
                    else ost=0;
                }
                for(st i=rn+1;i<=ln;i++)
                {

                    p[capacity-i-1]=p[capacity-i-1]+ost;
                    if(p[capacity-i-1]>=58)
                    {
                        ost=1;
                        p[capacity-i-1]=p[capacity-i-1]-10;
                    }
                    else ost=0;
                }
                if(ost==1)
                {
                    char* buf=new char[capacity+1];
                    buf[0]='0';
                    buf[1]='1';
                    for(st i=2;i<capacity+1;i++)
                    {
                        buf[i]=p[i-2];
                    }
                    delete [] p;
                    p=new char[capacity+1];
                    for(st i=0;i<capacity+1;i++)
                    {
                        p[i]=buf[i];
                    }
                    capacity++;
                    delete [] buf;
                }     \
        }
        else if(capacity<maxlen+1)
        {
            ost=0;
            int j=0;
            char* buf=new char[rn+1];
            capacity=rn+1;
            for(st i=0;i<=rn-ln;i++)
            {
                buf[i]='0';
            }
            for(st i=rn-ln+1;i<rn+1;i++)
            {
                buf[i]=p[j];
                j++;
            }
            delete [] p;
            p=new char[rn+1];
            for(st i=0;i<rn+1;i++)
            {
                p[i]=buf[i];
            }
            delete [] buf;
            for(st i=0;i<rn+1;i++)
            {
                p[rn+1-i]+=right.p[rn-i]-48+ost;
                if(p[capacity-i]>=58)
                {
                    p[capacity-i]-=10;
                    ost=1;
                }
                else ost=0;
            }
            if(ost)
                p[0]='1';
            else
                p[0]='0';
            p[rn+1]='\0';
        }
    }

    mylonginteger::~mylonginteger()
    {
        delete [] p;
        n=0;
        capacity=0;
    }
    void mylonginteger::write_longinteger()
    {
        char *new_p=skip_zeros(p);
        for(std::size_t i =0;i<capacity;i++)
        {
            std::cout<<new_p[i];
        }
        if(new_p!=nullptr&&new_p!=p) delete [] new_p;
        std::cout<<'\n';
    }
    bool mylonginteger::IsEqual(const mylonginteger *right)
    {
        char* a=skip_zeros(p);
        char* b=skip_zeros(right->p);
        if(std::strcmp(a,b)) return false;
        else return true;
    }
    void mylonginteger::read_longinteger()
    {
        char* inp=get_string();
        inp=skip_zeros(inp);
        std::size_t length=std::strlen(inp);
        if(length<=capacity)
        {
            n=length;
            //capacity=n+1;
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
