#include <iostream>
using namespace std;

struct Adress{
    string city;
    int no;
};

struct Employee{
    int id;
    string name;
    string department;
    Adress adress;
};

void show( Employee emp ){
    emp.id = 100;
    cout << "id    : " << emp.id << endl;
    cout << "name  : " << emp.name << endl;
    cout << "dep   : " << emp.department << endl;
    cout << "adres : " << emp.adress.city << endl;
    cout << "no    : " << emp.adress.no << endl;
}

struct EmployeePtr{
    int id;
    string name;
    string department;
    Adress *adress;
};

void show_ptr( EmployeePtr *emp_ptr ){
    emp_ptr->id = 100;
    cout << "\nid  : " << emp_ptr->id << endl;
    cout << "name  : " << emp_ptr->name << endl;
    cout << "dep   : " << emp_ptr->department << endl;
    cout << "adres : " << emp_ptr->adress->city << endl;
    cout << "no    : " << emp_ptr->adress->no << endl;
}

int main(){

    Employee employee = { 12, "CGR", "RD", { "ANKARA", 5 } };
    cout << employee.adress.city << endl;
    cout << employee.adress.no << endl << endl;

    employee.adress.city = "SELANIK";

    show( employee );
    cout << "id in main : " << employee.id << endl << endl;

    EmployeePtr emp = { 12, "MRB", "RD" };
    EmployeePtr *employee_ptr = &emp;
    Adress adr = { "IZMIR", 5 };
    employee_ptr->adress = &adr;                            // emp.adress = &adr

    cout << employee_ptr->adress->city << endl;
    cout << employee_ptr->adress->no << endl;

    employee_ptr->adress->city = "ISTANBUL";                // emp.adress->city = &adr

    show_ptr( employee_ptr );                               // show( &emp )
    cout << "id in main : " << employee_ptr->id << endl;    // emp.id

    return 0;
}
