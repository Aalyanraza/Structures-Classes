#include <iostream>
#include <fstream>
using namespace std;
class Record
{
private :
    char* fileName;
public :
    Record (char* str)    //constructor will create the file with the given file name.
    {
        int strlen=0;
        while (str[strlen])
            strlen++;
        fileName=new char[strlen+1];    
        for (int i=0; str[i]; i++)
            fileName[i]=str[i];
        fileName[strlen]='\0';        
    }
    int record_Input()    // input function will get the multiple data (name ,address ,age and CGPA )from the user and adds to the file,
    {
        fstream file;
        file.open(fileName, ios_base::out );
        if (!file.is_open()) 
            cout << "File could not be opened!" << endl;
        int input=0;
        bool open=1;
        while(open)
        {
            if (open==1)
                input++;       
            string name, address;
            int age;
            float CGPA;
            cout<<"Enter Age: ";
            cin>>age;
            cout<<"Enter CGPA: ";
            cin>>CGPA;
            cin.ignore();
            cout<<"Enter Name: ";
            getline(cin,name);
            cout<<"Enter Address: ";
            getline(cin,address);

            file<<"********"<<input<<"********"<<endl<<name<<endl<<address<<endl<<age<<endl<<CGPA<<endl<<endl<<endl;

            cout<<"\n\nDo you want more inputs??(1 for yes,, 0 for no)";
            cin>>open;
        }    
        file.close();
        
    return input;}
    void record_Display() // the function will display the all the data store in file.
    {
        fstream file;
        file.open(fileName, ios_base::in );
        string line;
        while (getline(file,line))
            cout<<line<<endl;
        file.close();
    }
    int delete_Record()/// function will delete the complete record that is data (name ,address ,age and CGPA ) of person with given name.
    {
        fstream file;
        file.open(fileName, ios_base::out );
        string input,line;
        bool flag=0, flag1=0;
        cout<<"Name of Record to delete: ";
        cin.ignore();
        getline(cin,input);
        while(getline(file,line))
        {
            if (line==input)
            {
                line="";
                flag=1;
                break;
            }        
        }
        if (flag=1)
        {
            getline(file,line);
            line="";
            getline(file,line);
            line="";
            getline(file,line);
            line="";
            file.close();
            return 1;
        }
        else
        {
            cout<<"Record not found";
            file.close();
            return 0;
        }
        
    }
    int record_Count();//function will count the total records stored in the file.
    int record_Search(); // Allows to search the file with a particular name
    int record_Insert();//it will allow the user to insert the data (name ,address ,age and CGPA ) after some name in the file
    void record_Replace();//it will allow the user to replace the data (name ,address ,age and CGPA ) of given name in the file
    //~Record();
} ;

int main()
{
    Record s("aala.txt");
    cout<<s.record_Input();
    s.record_Display();
    //s.delete_Record();
}