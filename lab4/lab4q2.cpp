#include <iostream>
#include <iomanip>

int N = 3; 

using namespace std;

class Employee{
public:
  string name;
  int employeedYears;
  double salary, bonus;

  void setName(string);
  void setEmployeedYears(int);
  void setSalary(double);

  void calculateBonus();
  void print();
};

void Employee::setName(string inpName){
  this->name = inpName;
}

void Employee::setEmployeedYears(int inpYear){
  this->employeedYears = inpYear;
}

void Employee::setSalary(double inpSalary){
  this->salary = inpSalary;
}

void Employee::calculateBonus(){
  float coff;

  if(employeedYears <= 5)
      coff = 0;
  else if(employeedYears <= 10)
      coff = 0.05;
  else if(employeedYears <= 15)
      coff = 0.1;
  else if(employeedYears <= 20)
      coff = 0.15;
  else 
      coff = 0.2;
    this->bonus = (this->salary)*coff;
}
void Employee::print(){
  cout << setw(10) << left << name << setw(10) << left << employeedYears << setw(10) << left << salary << setw(10) << left << bonus << endl;
}

int main(){
  
  string tempName;
  int tempYear;
  double tempSalary;
  
  Employee employees[N];
  
  for(int i = 0; i < N; ++i){
      cout << "Enter employee name, employed years and salary: ";
      cin >> tempName >> tempYear >> tempSalary;
      employees[i].setName(tempName);
      employees[i].setEmployeedYears(tempYear);
      employees[i].setSalary(tempSalary);
      employees[i].calculateBonus();
  }
  cout << setw(10) << left << "Name" << setw(10) << left << "Years" << setw(10) << left << "Salary" << setw(10) << left << "Bonus" << endl;
  
  for(int i = 0; i < N; ++i){
    employees[i].print();
  }

  return 0;
}