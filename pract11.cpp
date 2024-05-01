#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void addstudent()
{
ofstream f;
f.open("Studentinfo.txt",ios::app);
string name,div,add;
string roll;
cout<<"Enter student Roll number :";
cin>>roll;
cout<<"Enter student Name :";
cin>>name;
cout<<"Enter student Division :";
cin>>div;
cout<<"Enter student Address :";
cin>>add;
f<<left<<setw(20)<<roll<<setw(20)<<name<<setw(20)<<div<<setw(20)<<add<<endl;
cout<<"\nStudent details added succesfully !!";
f.close();
}
void deletestudent()
{
ifstream f;
f.open("Studentinfo.txt",ios::app);
string line;
string fdata;
cout<<"Enter the roll number to Delete :";
string roll;
cin>>roll;
while(getline(f,line)){
if(line.find(roll) == string::npos){
fdata+=line;
fdata+="\n";
}
}
f.close();
ofstream f1;
f1.open("Studentinfo.txt",ios::out);
f1<<fdata;
f1.close();
cout<<"\nStudent deleted successfully !!";
}
void searchstudent()
{
ifstream f;
f.open("Studentinfo.txt",ios::app);
string line;
cout<<"Enter the roll number to search :";
string roll;
cin>>roll;
bool found = false;
while(getline(f,line)){
if(line.find(roll)!= string::npos){
cout<<"Student Found\n";
cout<<"Student details\n";
cout<<line<<endl;
found=true;
}
}
f.close();
if(!found){
cout<<"\nStudent not found !!";
}
}
void printdata()
{
ifstream f;
string line;
f.open("Studentinfo.txt",ios::app);
cout<<"\n---------Printing details of the students----------"<<endl;
while(getline(f,line)){
cout<<line<<endl;
}
cout<<"\n---------------Printing completed---------------"<<endl;
f.close();
}
int main()
{
ofstream f;
f.open("Studentinfo.txt",ios::out);
f<<left<<setw(20)<<"Roll Number"<<setw(20)<<"Name"<<setw(20)<<"Dvision"<<setw(20)<<"Address"<<endl;
f.close();
int ch;
while(ch !=-1){
cout<<"\n----------------------------";
cout<<"\nEnter your choice :\n1)Add student \n2)Delete student \n3)Search student \n4)Print data \n5)Exit(-1)\n---------------------------->";
cin>>ch;
switch(ch){
case 1:
addstudent();
break;
case 2:
deletestudent();
break;
case 3:
searchstudent();
break;
case 4:
printdata();
break;
}
}
}
