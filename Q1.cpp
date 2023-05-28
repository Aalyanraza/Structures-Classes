# include<iostream>
using namespace std;

// Question 1
struct ZooCage
{
    char *name;
    int cageNumber;
    ZooCage* link;
};

class ZooChain 
{
    public:
    ZooCage* start;
    
    ZooChain() { start = NULL; }
    void add_Cage(char* name, int cageNumber)
    {
        ZooCage* cage1 = new ZooCage {name, cageNumber, NULL};

        if (!start)
        {
            start = cage1;
        } 
        else 
        {
            ZooCage* cage2 = start;
            while ((*cage2).link) 
            {
                cage2 = (*cage2).link;
            }
            (*cage2).link = cage1;
            //delete cage2;
        }
        //delete cage1;
        cage1=NULL;
    }

    void print_Chain()
    {
            ZooCage* ptr=start; 
            while (ptr)
            {
                cout<<"Name: "<<(*ptr).name<<'\n'<<"Cage#: "<<(*ptr).cageNumber<<endl;
                ptr=(*ptr).link;
            }
            //delete ptr;
            ptr=NULL;  
    }

    void delete_Chain( int cageNumber)
    {
        ZooCage* ptr=start, *ptr1=ptr; 
        while ((*ptr).cageNumber!=cageNumber && ptr!= NULL)
        {
            ptr1=ptr;
            ptr=(*ptr).link;
        }
        if (ptr == NULL)
        {
        return;
        }
        if (ptr == start)   // node to delete is the first node
        {    
            start = ptr->link;
        } 
        else 
        {
            ptr1->link = ptr->link;
        }
        //delete ptr1,ptr;
        ptr1=NULL;
        ptr=NULL;
    }
    
    void Sort_Chain()
    {
        int count=0;
        ZooCage* ptr=start;
        ZooCage* ptr1 = ptr->link;
        while (ptr)
        {
            count++;
            ptr=(*ptr).link;
        }

        for (int j=0; j<count; j++)
        {
            ptr=start;
            ptr1 = ptr->link;
            for ( int i=1; i<=(count-1); i++)
            {
                if ( (ptr->cageNumber) > (ptr1->cageNumber))
                {
                    char** naam= new char*;
                    *naam = ptr->name;
                    ptr->name = ptr1-> name;
                    ptr1-> name = *naam;
                    delete naam;
                    naam = NULL;

                    int temp;
                    temp= ptr->cageNumber;
                    ptr->cageNumber = ptr1-> cageNumber;
                    ptr1-> cageNumber = temp;
                }
                ptr= ptr->link;
                ptr1=ptr1->link;
            }
        }   
    }    

    void update_name_at_cageNumber(int cageNumber, char * name)
    {
        ZooCage* ptr=start; 
        while ((*ptr).cageNumber!=cageNumber && ptr!= NULL)
        {
            ptr=(*ptr).link;
        }
        (*ptr).name=name;
        //delete ptr;
        ptr=NULL;
    }

    void remove_Duplicate()
    {
        int count = 0;
        ZooCage* ptr = start;
        while (ptr)
        {
            count++;
            ptr = ptr->link;
        }
        ptr = start;
        for (int i = 0; i < count; i++)
        {
            ZooCage* ptr1 = ptr->link;
            ZooCage* prev = ptr;
            for (int j = i + 1; j < count; j++)
            {
                if (ptr->cageNumber == ptr1->cageNumber)
                {
                    prev->link = ptr1->link;
                    delete ptr1;
                    ptr1 = prev->link;
                    count--;
                    j--;
                }
                else
                {
                    prev = ptr1;
                    ptr1 = ptr1->link;
                }
            }
            ptr = ptr->link;
        }
    }

    ~ZooChain()
    {
        delete[] start;
    }
};
