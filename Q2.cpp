# include<iostream>
using namespace std;

class String
{
    char* data;
    int len;
public:

    String() // default constructor
    {}
    String (char* str) // constructor String(char *str) initializes the string with constant cstring
    {

        int count =0;
        for (int i=0; str[i]; i++)
            count++;
        len =count;
        data= new char [len+1];
        for (int i=0; str[i];  i++)
        {
            data[i]=str[i];
        }
        data[len]='\0';
    }
    String(const String &str) // copy constructor to initialize the string from existing string
    {
        len= str.len;
        data= new char [len+1];
        data[len] = '\0';
        for (int i=0; str.data[i];  i++)
        {
            data[i]=str.data[i];
        }
    }
    String(int x) // initializes a string of pre-defined size
    {
        len=x;
        data= new char[len] ;
        data[0]='\0';
    }

    char* getdata()
    {
        return data;
    }
    char getChar(int i) // returns the character at index [x] in a string
    {
        return data[i];
    }

    bool isEmpty() // returns true if string is empty..
    {
        if (data[0])
            return 0;
        else
            return 1;
    }


    String append_string(const String &str) // appends a String at the end of the String
    {
        String s;
        int count =0;
        s.data= new char[len+str.len+1];
        int i;
        for (i=0; data[i]; i++)
        {
                s.data[i]=data[i];
        }
        for (i, count=0; str.data[count]; i++, count++)
        {
            s.data[i]=str.data[count];
        }
        s.data[len+str.len]='\0';
        s.len=len+str.len+1;
        delete [] data;
        data= new char[s.len];
        for (int i=0; i<s.len;  i++)
        {
            data[i]=s.data[i];
        }
        len =s.len;
    return s;}
    String append_string(const char &str) // appends a char at the end of the String
    {
        String s;
        s.data= new char[len+1];
        int i;
        for (i=0; data[i]; i++)
        {
                s.data[i]=data[i];
        }
        s.data[i]=str;
        s.len=len+1;
        delete [] data;
        data= new char[s.len];
        for (int i=0; s.data[i];  i++)
        {
            data[i]=s.data[i];
        }
        len =s.len;
    return s;
    }
    String append_string(char *&str) // appends a String at the end of the String
    {
        String s;
        int count =0;
        for (int i=0; str[i]; i++)
            count++;
        s.data= new char[len+count+1];
        for (int i=0; i<len+count+1; i++)
        {
            if (i<len)
                s.data[i]=data[i];
            else if (i<len+count)
                s.data[i]=str[i-len];
            else
                s.data[i]='\0';
        }
        s.len=len+count;
        delete [] data;
        data= new char[s.len];
        for (int i=0; s.data[i];  i++)
        {
            data[i]=s.data[i];
        }
        len =s.len;
    return s;}
    String append_string(string& str) // appends a String at the end of the String
    {
        String s;
        int i,j,count;
        for (int i=0; str[i]; i++)
            count++;
        s.data= new char[len+count+1];
        for (i=0; data[i]; i++)
        {
            s.data[i]=data[i];
        }
        for (i,j=0; str[j]; i++,j++)
        {
            s.data[i]=str[j];
        }
        s.len=len+count+1;
        s.data[len+count]='\0';
        delete [] data;
        data= new char[s.len];
        for (int i=0; s.data[i];  i++)
        {
            data[i]=s.data[i];
        }
        len =s.len;
    return s;
    }



   // String remove_string(const String &substr) //removes the substr from the String
    // {
    //     cout<<"1\n";
    //     bool flag=0;
    //     int i;
    //     for (i=0; i<len; i++)
    //     {
    //         if (data[i]==*(substr.data))
    //         {   
    //             flag=1;
    //             for (int j=i,k=0; k<substr.len; j++,k++)
    //             {
    //                 if (data[j]!=substr.data[k]) 
    //                 {
    //                     flag=0;
    //                     break;
    //                 }
    //             }
    //         }
    //         if (flag==1)
    //             break;
    //     }

    //     if (flag==1)
    //     {
    //         for (i; i<len-substr.len; i++)
    //         {
    //             data[i]=data[i+substr.len];
    //         }
    //         len-=substr.len;
    //         data[len]='\0';
    //     }
    // return *this;}
    String remove_string(string &substr) //removes the substr from the String
    {    
        cout<<"2\n";
        bool flag=0;
        int i,count=0;
        while(substr[count])
            count++;
        for (i=0; data[i]; i++)
        {
            if (data[i]==substr[0])
            {   
                flag=1;
                for (int j=i,k=0; substr[k]; j++,k++)
                {
                    if (data[j]!=substr[k]) 
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if (flag==1)
                break;
        }

        if (flag==1)
        {
            for (i; i<len-count; i++)
            {
                data[i]=data[i+count];
            }
            len-=count;
            data[len]='\0';
        }
    return *this;}
    String remove_string(char *&substr) //removes the substr from the String
    {
        cout<<"Mohib";
        bool flag=false;
        int counter=0,counter2=0;
        int point;
        while(substr[counter])
        {
            counter++;

        }

        while(this->data[counter2])
        {
            counter2++;

        }
        char *n2=new char[counter2-counter+1];
        for(int i=0;i<counter2;i++)
        {
            if(this->data[i]==substr[0])
            {
                flag=true;
                
            }
            int pos = 0;
            while(flag == true && pos < counter)
            {
                    for(int j=0; j < counter;j++)
                    {
                        if(*(this->data + i + j) != substr[j])
                        { 
                            flag = 0;
                            break;
                        }
                    }
                pos++;
            }
            if(flag==true)
            {
                point=i;
                break;
            }
        }
        for(int i=0;i<point;i++)
        {
            n2[i]=this->data[i];
        }
        for(int i=point;i<counter2-counter;i++)
        {
            n2[i]=this->data[i+counter];
            point++;
        }
        n2[counter2-counter]='\0';
        (*this).data=n2;
        return *this;
    }
    String remove_string(const char &alph) //removes the substr from the String
    {    
        cout<<"4\n";
        for (int i=0; i<len; i++)
        {
            if (data[i]==alph)
            {   
                for (i; i<len-1; i++)
                {
                    data[i]=data[i+1];
                }
                data[i]='\0';
                len-=1;
                break;
            }
        }

    return *this;}

    
    String& assign_string(const String& org) // copies one String to another
    {
        delete [] data;
        data = new char[org.len+1];
        for (int i=0; org.data[i];  i++)
        {
            data[i]=org.data[i];
        }
        data[org.len+1]='\0';
        len =org.len;

    return *this;}
    String& assign_string(char* org) // copies one c-string to another
    {
        int count=0;
        for (int i=0; org[i];  i++)
        {
            count++;
        }
        delete [] data;
        data = new char[count+1];
        for (int i=0; org[i];  i++)
        {
            data[i]=org[i];
        }
        data[count]='\0';
        len =count;
    return *this;}

    String& assign_string(const string& org) // copies one string to another
    {
        int count=0;
        for (int i=0; org[i];  i++)
        {
            count++;
        }
        delete [] data;
        data = new char[count+1];
        for (int i=0; org[i];  i++)
        {
            data[i]=org[i];
        }
        data[count]='\0';
        len =count;
    return *this;}

    bool isEqual(const String& given)const //returns true if two Strings are equal
    {
        bool flag=0;
        int width= len;
        if ( width == given.len)
        {
            flag=1;
            for (int i=0; i<width; i++)
            {
                if (data[i] != given.data[i])
                {
                    flag=0;
                }
            }
        }
    return flag;}

    bool isEqual(const string& given)const //returns true if two strings are equal
    {
        int lengthgiven=0;
        for (int i=0; given[i]; i++)
        {
            lengthgiven++;
        }
        bool flag=0;
        if (len == lengthgiven )
        {
            flag=1;
            for (int i=0; i<len; i++)
            {
                if (data[i] != given[i])
                {
                    flag=0;
                }
            }
        }
    return flag;}
    bool isEqual(char * given)const //returns true if two strings are equal
    {
        int lengthgiven=0;
        for (int i=0; given[i]; i++)
        {
            lengthgiven++;
        }
        bool flag=0;
        if (len == lengthgiven )
        {
            flag=1;
            for (int i=0; i<len; i++)
            {
                if (data[i] != given[i])
                {
                    flag=0;
                }
            }
        }
    return flag;}

    int index_at (char a) const // returns the index of the character being searched
    {
        for (int i=0; i<len; i++)
        {
            if (data[i]== a)
            {
                return i;
            }
        }
    return -1;}
    int index_at (const String& str) const // returns the start index of the String being searched
    {
        int count=0;
        while (str.data[count])
        {
            count++;
        }
        for ( int i=0; i<len; i++)
        {
            if ( data[i]== *(str.data))
            {
                bool flag=1;
                for (int j=i,k=0 ; k<count; k++,j++)
                {
                    if (data[j] != str.data[k])
                    {
                        flag=0;
                    }
                }
                if (flag==1)
                {
                    return i;
                }
            }
        }
    return -1;}
    int index_at (const string& str) const // returns the start index of the string being searched
    {
        int count=0;
        while (str[count])
        {
            count++;
        }
        for ( int i=0; i<len; i++)
        {
            if ( data[i]== str[0])
            {
                bool flag=1;
                for (int j=i,k=0 ; k<count; k++,j++)
                {
                    if (data[j] != str[k])
                    {
                        flag=0;
                    }
                }
                if (flag==1)
                {
                    return i;
                }
            }
        }
    return -1;
    }
    int index_at (char* str) const // returns the start index of the c-string being searched
    {
        int count=0;
        while (str[count])
        {
            count++;
        }
        for ( int i=0; i<len; i++)
        {
            if ( data[i]== *str)
            {
                bool flag=1;
                for (int j=i,k=0 ; k<count; k++,j++)
                {
                    if (data[j] != str[k])
                    {
                        flag=0;
                    }
                }
                if (flag==1)
                {
                    return i;
                }
            }
        }
    return -1;
    }

    int length() // returns the length of string
    {
        if (!isEmpty())
            return len;
    return 0;}

    ~String() // destructor...
    {
        delete[] data;
    }
};

int main()
{
    String s1("Spring2023");
    char t1[]="ring";
    cout<<s1.remove_string(t1);
    

}