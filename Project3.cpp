//Project 3 reads in data from text file and computes sports stats
//Daniel Edelstein
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class Teams{
	public:
		double teamID[10];
		double wins[10];
		double losses[10];
};

	int main(){
		int i = 0;
		Teams team; //create an instance of Teams
		ifstream output("Project3.txt"); //open file to read in data
		if(output.is_open()){//check if file exists
			while(i < 10){//read data from file while not end of file
				output >> team.teamID[i] >> team.wins[i] >> team.losses[i];
				cout << "Team " << team.teamID[i] << endl 
				<< team.wins[i] << " Wins\t" << team.losses[i] << " losses" << endl
				<< "Total number of games played is " << team.wins[i] + team.losses[i] << endl;
				if(team.wins[i] + team.losses[i] == 20)
					cout << "The season is finished" << endl;
				else
					cout << 20 - (team.wins[i] + team.losses[i]) << " games remaining" << endl;
				cout << "The winning percentage is " << fixed << setprecision(5) << team.wins[i] / (team.wins[i] + team.losses[i]) << setprecision(0) << endl;
				if(team.wins[i]>team.losses[i])
					cout << "The team is " << team.wins[i] - team.losses[i] << " games above 0.50000" << endl << endl;
				else
					cout << "The team is " << team.losses[i] - team.wins[i] << " games below 0.50000" << endl << endl;
				i++;
			}
		}
		else{
			cout << "File Not Found." << endl;
			return 0;
		}

	
		

		output.close();
		return 0;
	}