//Project 2 reads in data from text file and computes employee pay and tax
//Daniel Edelstein
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

	class Payroll{
		public:
			double empID[10];
			double hours[10];
			double rate[10];
			double age[10];
	};

	int main(){
		int i = 0, j = 0, age = 0, oldestEmpID = 0, highTaxID = 0;
		double overtime, basePay, tax, highestTax;
		Payroll pay; //create an instance of Payroll
		ifstream output("Project2.txt"); //open file to read in data
		if(output.is_open()){//check if file exists
			while(!output.eof()){//read data from file while not end of file - this prevents errors
				output >> pay.empID[i] >> pay.hours[i] >> pay.rate[i] >> pay.age[i];
				cout << pay.empID[i]  << " \t" << pay.hours[i] << " \t" << pay.rate[i] << " \t" << pay.age[i] << " \t" << " \n";
				i++;
			}
		}
		else{
			cout << "File Not Found." << endl;
			return 0;
		}

		while(j < 10){
			
			//calculate overtime pay
			if(pay.hours[j] > 40){
				overtime = pay.hours[j] - 40;
				basePay = (40 * pay.rate[j]) + (overtime * 1.5);
				cout << "Base pay for Employee "  << pay.empID[j] << " is $"  << basePay << " \n";
			}
			else{
				basePay = pay.hours[j] * pay.rate[j];
				cout << "Base pay for Employee "  << pay.empID[j]  << " is $" << basePay << " \n";	
			}

			//calculate tax rate
			if(pay.age[j] >= 55){
				tax = basePay * 0.2;
				cout << "Tax Paid: $" << tax << " \n";
				if(tax > highestTax){
					highestTax = tax;
					highTaxID = pay.empID[j];
				}
			}
			else{
				tax = basePay * 0.1;
				cout << "Tax Paid $" << tax << "\n";
				if(tax > highestTax){
					highestTax = tax;
					highTaxID = pay.empID[j];
				}
			}
			cout << "Net Pay: $" << basePay - tax << endl << endl;
			if(pay.age[j] > age){
				age = pay.age[j];
				oldestEmpID = pay.empID[j];
			}

			j++;
		}
		cout << "Oldest employee is " << oldestEmpID << " age " << age << endl;
		cout << "Employee paying the most tax is " << highTaxID << " with total taxes of $" << highestTax << endl << endl;
		cout << "The payroll program is complete";
		

		output.close();
		return 0;
	}