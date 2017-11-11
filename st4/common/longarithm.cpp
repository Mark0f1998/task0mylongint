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
        :n(0),
         capacity(0),
         p(nullptr)
    {}


    mylonginteger::mylonginteger(const char* str)
    {
        std::size_t len=std::strlen(str);
        p=new char[len+1];
        std::memcpy(p,str,len+1);
        p[len]='\0';
        /*for(st i=0;i<=len;i++)
        {
            p[i]=str[i];
        }*/
        n=len;
        capacity=n;
    }
    mylonginteger::mylonginteger(const mylonginteger& right)
    {
        p=new char[right.capacity];
        n=right.n;
        capacity=right.capacity;
        /*for(std::size_t i=0;i<n;i++)
        {
            p[i]=right.p[i];
        }*/
        std::memcpy(p,right.p,n);
    }
    mylonginteger::mylonginteger(mylonginteger&& right)
    {
        n=right.n;
        capacity=right.capacity;
        p=right.p;
        right.n=0;
        right.capacity=0;
        right.p=nullptr;
    }
    mylonginteger& mylonginteger::operator = (const mylonginteger& right)
    {
        n=right.n;
        if(capacity<right.n)
        {
            delete [] p;
            p=new char[right.n+1];
        }
        capacity=right.capacity;
        /*for(std::size_t i=0;i<n;i++)
        {
            p[i]=right.p[i];
        }*/
        std::memcpy(p,right.p,n);
        return *this;
    }
    mylonginteger& mylonginteger::operator = (mylonginteger&& right)
    {
        if(this==&right) return *this;
        n=right.n;
        capacity=right.capacity;
        delete [] p;
        p=right.p;
        right.n=0;
        right.capacity=0;
        right.p=nullptr;
        return *this;
    }
    void mylonginteger::operator +=(const mylonginteger& right)
    {
        st ln=n;
        int ost=0;
        st rn=right.n;
        if(rn<=ln)
        {
            for(st i=1;i<rn+1;i++)
            {
                p[ln-i]+=right.p[rn-i]+ost-48;
                if(p[ln-i]>=58)
                {
                    ost=1;
                    p[ln-i]-=10;
                }
                else
                {
                    ost=0;
                }
            }
            for(st i=rn+1;i<=ln;i++)
            {
                p[ln-i]+=ost;
                if(p[ln-i]>=58)
                {
                    ost=1;
                    p[ln-i]-=10;
                }
                else
                {
                    ost=0;
                }
            }
            if(ost)
            {
                if(capacity!=n)
                {
                    for(st i=n+1;i>0;i--)
                        p[i]=p[i-1];
                    p[0]='1';
                    n++;
                }
                else
                {
                    capacity++;
                    n++;
                    char* buf=new char[n];
                    buf[0]='1';
                    for(st i=1;i<n;i++)
                        buf[i]=p[i-1];
                    delete [] p;
                    p=new char[n];
                    for(st i=0;i<n;i++)
                        p[i]=buf[i];
                    delete [] buf;
                }
            }
        }
        else
        {
            int j=0;
            ost=0;
            char* buf=new char[rn+1];
            for(st i=0;i<rn-ln+1;i++)
            {
                buf[i]='0';
            }
            for(st i=rn-ln+1;i<rn+1;i++)
            {
                buf[i]=p[j];
                j++;
            }
            for(st i=0;i<rn;i++)
            {
                buf[rn-i]+=right.p[rn-i-1]+ost-48;
                if(buf[rn-i]>=58)
                {
                    ost=1;
                    buf[rn-i]-=10;
                }
                else ost=0;
            }

            if(ost)
            {
                buf[0]='1';
                n++;
                capacity++;
                delete [] p;
                p=new char[rn+1];
                for(st i=0;i<rn+1;i++)
                    p[i]=buf[i];
                delete [] buf;
            }
            else
            {
                delete [] p;
                p=new char[rn];
                n=rn;
                capacity=rn;
                for(st i=1;i<rn+1;i++)
                {
                    p[i-1]=buf[i];
                }
                delete [] buf;
            }

        }
    }

    mylonginteger::~mylonginteger()
    {
        delete [] p;
    }
    /*void mylonginteger::write_longinteger()
    {
        char *new_p=skip_zeros(p);
        for(std::size_t i =0;i<n;i++)
        {
            std::cout<<new_p[i];
        }
        if(new_p!=nullptr&&new_p!=p) delete [] new_p;
        std::cout<<'\n';
    }*/
    bool mylonginteger::IsEqual(const mylonginteger *right)
    {

        return !std::strcmp(p,right->p);
    }
    void mylonginteger::read_longinteger()
    {
        char* inp=get_string();
        inp=skip_zeros(inp);
        std::size_t length=std::strlen(inp);
        if(length<capacity)
        {
            n=length;
            for(st i=0;i<n;i++)
                p[i]=inp[i];
            p[n]='\0';
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
            p[n]='\0';
        }
        delete [] inp;
    }
    /*std::istream& operator >> (std::istream& is, mylonginteger& mli)
    {
        char* inp=get_string();
        inp=skip_zeros(inp);
        std::size_t length=std::strlen(inp);
        if(length<mli.capacity)
        {
            mli.n=length;
            for(st i=0;i<mli.n;i++)
                mli.p[i]=inp[i];
            mli.p[mli.n]='\0';
        }
        else
        {
            delete [] mli.p;
            mli.p= new char[length+1];
            mli.capacity=length+1;
            mli.n=length;
            for(std::size_t i=0;i<mli.n;i++)
            {
                mli.p[i]=inp[i];
            }
            mli.p[n]='\0';
        }
        delete [] inp;
        return is;
    }*/

    char& mylonginteger::operator [](int i) const
    {
        return p[i];
    }

    std::ostream& operator <<(std::ostream& os, const mylonginteger& mli)
    {
        for(st i=0;i<mli.n;i++)
        {
            os<<mli.p[i];
        }
        std::cout<<'\n';
        return os;
    }
}
