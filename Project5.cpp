//Project5 - Daniel Edelstein
//reads in 2 ints and displays results
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

double Continue(int);
string Outcome(int, int);
string ContinueOutcome(int, int, int);

	int main(){
		int dice1, dice2;
		string outcome;

		ofstream output;
		output.open("Project5-output.txt");

		while(true){
			cout << "Enter number between 1 and 6: (-1 to exit)";
			output << "Enter number between 1 and 6: (-1 to exit)";
			cin >> dice1;
			output << dice1;
			if (dice1 == -1) return 0;
			while (dice1 != 1 && dice1 != 2 && dice1 != 3 && dice1 != 4 && dice1 != 5 && dice1 != 6){
				cout << "Invalid Input" << endl;
				output << "Invalid Input" << endl;
				cout << "Enter number between 1 and 6: (-1 to exit)";
				output << "Enter number between 1 and 6: (-1 to exit)";
				cin >> dice1;
				output << dice1;
				if (dice1 == -1) return 0;
			}
			cout << "die1 entered" << endl;
			output << "die1 entered" << endl;
			cout << "Enter number between 1 and 6: (-1 to exit)" << endl;
			output << "Enter number between 1 and 6: (-1 to exit)" << endl;
			cin >> dice2;
			output << dice2;
			if (dice2 == -1) return 0;
			while(dice2 != 1 && dice2 != 2 && dice2 != 3 && dice2 != 4 && dice2 != 5 && dice2 != 6){
				cout << "Invalid Input" << endl;
				output << "Invalid Input" << endl;
				cout << "Enter number between 1 and 6: (-1 to exit)" << endl;
				output << "Enter number between 1 and 6: (-1 to exit)" << endl;
				cin >> dice2;
				output << dice2;
				if (dice2 == -1) return 0;
			}
			cout << "die2 entered" << endl;
			output << "die2 entered" << endl;
			cout << dice1 + dice2 << endl;
			output << dice1 + dice2 << endl;
			outcome = Outcome(dice1, dice2);
			cout << outcome << endl;
			output << outcome << endl;
			if (outcome == "Roll again") Continue(dice1 + dice2);

			continue;
		}


		return 0;
	}

	//function takes 2 ints and returns a string
	string Outcome(int dice1, int dice2){
		if(dice1 + dice2 == 7 || dice1 + dice2 == 11){
			return "Player wins";
		}
		else if((dice1 + dice2 == 2 || dice1 + dice2 == 12)){
			return "Player losses";
			}
		else{
			return "Roll again";
			Continue(dice1 + dice2);
		}
	}

	//this function checks the continue outcome
	string ContinueOutcome(int dice1, int dice2, int sum){
		if(dice1 + dice2 == sum){
			return "Player wins";
		}
		else if((dice1 + dice2 == 7)){
			return "Player losses";
			}
		else{
			return "Roll again";
			Continue(dice1 + dice2);
		}
	}

	//this is the continue function
	double Continue(int sum){

		int dice1, dice2;
		while(true){
			cout << "Enter number between 1 and 6: ";
			cin >> dice1;
			while (dice1 != 1 && dice1 != 2 && dice1 != 3 && dice1 != 4 && dice1 != 5 && dice1 != 6){
				cout << "Invalid Input" << endl;
				cout << "Enter number between 1 and 6: ";
				cin >> dice1;
			}
			cout << "die1 entered" << endl;
			cout << "Enter number between 1 and 6: " << endl;
			cin >> dice2;
			while(dice2 != 1 && dice2 != 2 && dice2 != 3 && dice2 != 4 && dice2 != 5 && dice2 != 6){
				cout << "Invalid Input" << endl;
				cout << "Enter number between 1 and 6: " << endl;
				cin >> dice2;
			}
			cout << "die2 entered" << endl;
			cout << ContinueOutcome(dice1, dice2, sum) << endl;
			break;
		}
	}
