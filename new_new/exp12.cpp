//Student Name : Aniruddha Avinash Joshi

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Employee
{
    int id;
    string name;
    string designation;
    double salary;
};
void addEmployee()
{
    Employee employee;
    cout << "Enter employee ID: ";
    cin >> employee.id;
    cout << "Enter employee name: ";
    cin >> employee.name;
    cout << "Enter employee designation: ";
    cin >> employee.designation;
    cout << "Enter employee salary: ";
    cin >> employee.salary;
    ofstream file("employees.txt", ios::app);
    file << employee.id << " " << employee.name << " " << employee.designation << " "<<employee.salary<<endl;
    file.close();
}
void deleteEmployee()
{
    int id;
    cout << "Enter the ID of the employee to delete: ";
    cin >> id;
    ifstream file("employees.txt");
    ofstream temp("temp.txt");
    Employee employee;
    bool found = false;
    while (file >> employee.id >> employee.name >> employee.designation >> employee.salary)
    {
        if (employee.id != id)
        {
            temp << employee.id << " " << employee.name << " " << employee.designation << " "<<employee.salary<<endl;
        }
        else
        {
            found = true;
        }
    }
    file.close();
    temp.close();
    remove("employees.txt");
    rename("temp.txt", "employees.txt");
    if (found)
    {
        cout << "Employee deleted successfully." << endl;
    }
    else
    {
        cout << "Employee not found." << endl;
    }
}
void displayEmployee()
{
    int id;
    cout << "Enter the ID of the employee to display: ";
    cin >> id;
    ifstream file("employees.txt");
    Employee employee;
    bool found = false;
    while (file >> employee.id >> employee.name >> employee.designation >> employee.salary)
    {
        if (employee.id == id)
        {
            found = true;
            cout << "ID: " << employee.id << endl;
            cout << "Name: " << employee.name << endl;
            cout << "Designation: " << employee.designation << endl;
            cout << "Salary: " << employee.salary << endl;
            break;
        }
    }
    file.close();
    if (!found)
    {
        cout << "Employee not found." << endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "1. Add employee" << endl;
        cout << "2. Delete employee" << endl;
        cout << "3. Display employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            displayEmployee();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}
