#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Employee
{
    typedef struct emp
    {
        int id;
        char name[50];
        char designation[50];
        double salary;
    }emp;
    emp rec;
public:
    void create();
    void display();
    int search();
    void Delete();
};

void Employee::create()
{
    char ans;
    ofstream fout;
    fout.open("emp.dat",ios::out|ios::binary);
    do
    {
        cout<<"\n\tEnter ID of Employee: ";
        cin>>rec.id;
        cout<<"\n\tEnter Name of Employee: ";
        cin>>rec.name;
        cout<<"\n\tEnter Designation of Employee: ";
        cin>>rec.designation;
        cout<<"\n\tEnter Salary of Employee: ";
        cin>>rec.salary;
        fout.write((char *)&rec,sizeof(emp))<<flush;
        cout<<"\n\tDo You Want to Add More Records: ";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    fout.close();
}

void Employee::display()
{
    ifstream fin;
    fin.open("emp.dat",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\n\tThe Content of File are:\n";
    cout<<"\n\tID\tName\tDesignation\tSalary";
    while(fin.read((char *)&rec,sizeof(emp)))
    {
        if(rec.id!=-1)
            cout<<"\n\t"<<rec.id<<"\t"<<rec.name<<"\t"<<rec.designation<<"\t"<<rec.salary;
    }
    fin.close();
}

int Employee::search()
{
    int r,i=0;
    ifstream fin;
    fin.open("emp.dat",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\n\tEnter an ID: ";
    cin>>r;
    while(fin.read((char *)&rec,sizeof(emp)))
    {
        if(rec.id==r)
        {
            cout<<"\n\tRecord Found...\n";
            cout<<"\n\tID\tName\tDesignation\tSalary";
            cout<<"\n\t"<<rec.id<<"\t"<<rec.name<<"\t"<<rec.designation<<"\t"<<rec.salary;
            return i;
        }
        i++;
    }
    fin.close();
    return 0;
}

void Employee::Delete()
{
    int pos;
    pos=search();
    fstream f;
    f.open("emp.dat",ios::in|ios::out|ios::binary);
    f.seekg(0,ios::beg);
    if(pos==0)
    {
        cout<<"\n\tRecord Not Found";
        return;
    }
    int offset=pos*sizeof(emp);
    f.seekp(offset);
    rec.id=-1;
    strcpy(rec.name,"NULL");
    strcpy(rec.designation,"NULL");
    rec.salary=0;
    f.write((char *)&rec,sizeof(emp));
    f.seekg(0);
    f.close();
    cout<<"\n\tRecord Deleted";
}

int main()
{
    Employee obj;
    int ch,key;
    char ans;
    do
    {
        cout<<"\n\t***** Employee Information *****";
        cout<<"\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout<<"\n\t..... Enter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: obj.create();
                break;
            case 2: obj.display();
                break;
            case 3: obj.Delete();
                break;
            case 4: key=obj.search();
                if(key==0)
                    cout<<"\n\tRecord Not Found...\n";
                break;
            case 5:
                break;
        }
        cout<<"\n\t..... Do You Want to Continue in Main Menu: ";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    return 1;
}
