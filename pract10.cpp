#include<iostream>
#define sizee 30
using namespace std;
int Pqueue[sizee]={},r=-1,f=-1,no,ch;
string name[sizee],nname;
string serious[sizee];
string nonserious[sizee];
string general[sizee];
void enqueue()
{
if(r==sizee-1){
cout<<"Queue is full";
}
for(int i=0;i<no;i++)
{
cout<<"\nEnter the name of the patient :";
cin>>nname;
cout<<"\n1)Serious patient\n2)Not Serious\n3)General CheckUp";
cout<<"\nEnter condition of patient :";
cin>>ch;
if(f==-1)
{
f=0;
r++;
Pqueue[r]=ch;
name[r]=nname;
}
else
{
f=0;
r++;
Pqueue[r]=ch;
name[r]=nname;
}
}
for(int i=0;i<no;i++)
{
for(int j=0;j<no;j++)
{
if(Pqueue[i]<Pqueue[j])
{
int temp=Pqueue[i];
Pqueue[i]=Pqueue[j];
Pqueue[j]=temp;
string newname=name[i];
name[i]=name[j];
name[j]=newname;
}
}
}
}
void listwise()
{
for(int i=0;i<no;i++)
{
if(Pqueue[i]==1)
{
serious[i]=name[i];
}
else if(Pqueue[i]==2)
{
nonserious[i]=name[i];
}
else if(Pqueue[i]==3)
{
general[i]=name[i];
}
}
cout<<"\n------------------------------------------------------------------------------------";
cout<<"\nSerious Patients are : ";
for(int i=0;i<no;i++){
cout<<serious[i]<<" ";
}
cout<<"\nNon Serious Patients are : ";
for(int i=0;i<no;i++){
cout<<nonserious[i]<<" ";
}
cout<<"\nGeneral checkUp Patients are :";
for(int i=0;i<no;i++){
cout<<general[i]<<" ";
}
cout<<"\n-------------------------------------------------------------------------------------";
}
void display()
{
cout<<"\n-------------------------------------------------------------------------------------";
for(int i=0;i<no;i++)
{
cout<<"\n[ Name of the patient is :"<<name[i]<<" And has Priority :"<<Pqueue[i]<<" ]"<<endl;
}
cout<<"\n-------------------------------------------------------------------------------------";
}
int main()
{
cout<<"Enter the total no of patients :";
cin>>no;
enqueue();
while(1)
{
cout<<"\n1)List of Patients priority wise\n2)List of Patients Separate\n3)Exit";
cout<<"\nEnter your choice :";
int ch;
cin>>ch;
if(ch==1)
{
display();
}
else if(ch==2)
{
listwise();
}
else if(ch==3){
break;
}
else{
cout<<"Wrong choice !!";
}
}
}
