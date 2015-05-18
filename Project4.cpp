//Project 4 reads in number of judges and scores and returns averages
//Daniel Edelstein
#include<iostream>
#include<fstream>

using namespace std;


	int main(){
		int j = 0, k = 0;
		int playID[10];
		int judges[10];
		double scores[10];
		double scoreSum[10];
		double sum = 0;
		double highScore = 0, lowScore = 100;

		ofstream output;
		output.open("Project4-output.txt");

		while(true){
			cout << "Please enter the player ID: (-1 to stop)";
			output << "Please enter the player ID: (-1 to stop)";
			cin >> k;
			output << k << endl;
			if(k == -1) break;
			else playID[j] = k;

			cout << "How many judges? (Between 4 and 10): ";
			output << "How many judges? (Between 4 and 10): ";	
			cin >> judges[j];
			output << judges[j] << endl;
			//verify valid input
			while(judges[j] < 1 || judges[j] > 9){
				cout << "Invalid input" << endl;
				output << "Invalid input" << endl;
				cout << "How many judges? (Between 4 and 10): ";
				output << "How many judges? (Between 4 and 10): ";
				cin >> judges[j];
				output << judges[j];
			}
		
			
			//read in scores
			for(int i = 0; i < judges[j]; i++){
				cout << "Score " << i << ": ";
				output << "Score " << i << ": ";
				cin >> scores[i];
				output << scores[i] << endl;
				sum += scores[i];
				
				if(scores[i] > highScore) highScore = scores[i];
				if(scores[i] < lowScore) lowScore = scores[i];
			}
			//remove highest and lowest score from average calculation
			sum -= highScore;
			sum -= lowScore;
			//add sum to array then reset sum to 0
			scoreSum[j] = sum;
			sum = 0;

			cout << "\nPlayerID: " << playID[j] << " \nNumber of Judges: " << judges[j] << " \nAverage Score: " << scoreSum[j] / (judges[j] - 2) << endl;
			output << "\nPlayerID: " << playID[j] << " \nNumber of Judges: " << judges[j] << " \nAverage Score: " << scoreSum[j] / (judges[j] - 2) << endl;
			j++;
		}

		cout << "\nID - " << "Judges" << " - AVG Score " << endl;
		for(int i = 0; i < j; i++){
			cout << playID[i] << " \t" << judges[i] << " \t" << scoreSum[i] / (judges[i] - 2) << endl;
			output << playID[i] << " \t" << judges[i] << " \t" << scoreSum[i] / (judges[i] - 2) << endl;
		}
		output.close();
		return 0;
	}