# include<iostream>
using namespace std;

bool checkfun(char* ptr1, char* ptr2)
{
    bool flag=1;
    int  i=0;
    
    while ( ptr1[i] && ptr2[i])
    {
        if ( ptr1[i] != ptr2[i])
        {
            flag=0;
            break;
        } 
        i++;
    }
return flag;}
class BinaryStore
{
    char** adress;
    char** binary;
    int length;
    
    public:
    BinaryStore()
    {
        adress= NULL;
        binary= NULL;
        length=0;
    }
    
    BinaryStore (int len) // constructor which creates the store of length len.
    {
        adress= new char*[len];
        binary= new char*[len];
        length=len;
        for(int i=0 ; i<len ; i++)
        {
        	adress[i] = NULL;
        	binary[i] = NULL;
        }

    }
    int getlen()
    {
        return length;
    }
    void add_Address(char* s) // add a new address in the list of Binary store.
    {
        int location=-1;
        for (int i=0; i<length; i++)
        {
            if (!adress[i])
            {
                location=i;
                adress[i] =new char [5];
                adress[i][4] = '\0';
                for (int j=0; j<4; j++)
                {
                    adress[i][j]=s[j];
                }
                break;
            }
        }
        if (location==-1)
        {
            char** ptr= new char* [length+1];
            for (int i=0; i<length; i++)
            {
                ptr[i]=adress[i];
            }
            ptr[length] =new char [5];
            ptr[length][4] = '\0';
            binary[length] = NULL;
            for (int j=0; j<4; j++)
            {
                ptr[length][j]=s[j];
            }
            length++;
            adress=ptr;
        }    
    }
    void set_Byte(char* address, char* value) // add the byte at newly added address
    // here the first parameter is address and second is byte
    // Similarly the following code adds byte address and later byte // if address not found add address and byte both 
    // function also overrides the data given at particular byte address.
    {
        int location=-1;
        for (int i=0; i<length; i++)
        {
            if (checkfun(adress[i], address))
            {
                location =i;
                binary[i]=new char [9];
                binary[i][8] = '\0';
                for (int j=0; j<8; j++)
                {
                    binary[i][j]=value[j];
                }
                break;
            }
        }
        if (location == -1)
        {
            char** ptr= new char* [length+1];
            char** ptr1= new char* [length+1];
            for (int i=0; i<length; i++)
            {
                ptr[i]=adress[i];
            }
            for (int i=0; i<length; i++)
            {
                ptr1[i]=binary[i];
            }
            ptr[length]= new char[5];
            ptr[length][4] = '\0';
            for (int j=0; j<4; j++)
            {
                ptr[length][j]=address[j];
            }
            ptr1[length]= new char[9];
            ptr1[length][8] = '\0';
            for (int j=0; j<8; j++)
            {
                ptr1[length][j]=value[j];
            }
            length++;
            adress=ptr;
            binary=ptr1;
        }
    }
    char* Get(char* address) //Get function will retrieve the byte at a given address ,
    {
        for (int i=0; i<length; i++)
        {
            if ( checkfun(adress[i], address))
            {
                return binary[i];
            }
        }
        
    return nullptr;}
    char* ToString(); //return the BinaryStore as character dynamic array.
    char* Add(char* a, char* b)
    {
        char* answer = new char[9];
        int carry = 0;

        for (int i = 7; i >= 0; i--) 
        {
            int first, second;
            
            if (a[i]=='0')
                first = 0;
            else
                first=1;
            
            if (b[i]=='0')
                second = 0;
            else
                second=1;    
            
            int sum = first + second + carry;
            
            if (sum%2)
                answer[i]='1';
            else
                answer[i]='0';    
            
            carry = sum / 2;
        }

        answer[8] = '\0';
        return answer;
    }
    
    // parameters and given the binary equivalent in form of string.
    bool comp_EQUAL(char* a, char* b)
    {
        return (checkfun(a,b));
    }
    char* comp_AND(char* a, char* b)
    {
        char* answer = new char[9];
        answer[8]='\0';

        for ( int i=0; i<8; i++)
        {
            if ( a[i]=='1' && b[i]=='1')
                answer[i]='1';
            else
                answer[i]='0';    
        }
    return answer;}

    char* comp_OR(char* a, char* b )
    {
        char* answer = new char[9];
        answer[8]='\0';

        for ( int i=0; i<8; i++)
        {
            if ( a[i]=='1' || b[i]=='1')
                answer[i]='1';
            else
                answer[i]='0';    
        }
    return answer;}

    char* comp_NOT(char* a)
    {
        char* answer = new char[9];
        answer[8]='\0';

        for ( int i=0; i<8; i++)
        {
            switch(a[i])
            {
                case '1':
                    answer[i]='0';
                    break;
                case '0':
                    answer[i]='1';   
                    break;     
            }   
        }
    return answer;}
    
    ~BinaryStore(){}

};

