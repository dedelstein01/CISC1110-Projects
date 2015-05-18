//Project 7 - Daniel Edelstein
//Analyzes profit for items over 4 quarters
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


	struct ReturnValues{
		int bestNumber;
		string bestNumberName;
		int ups, downs, zeros;

	} values;

	class Product{
	public:
		string name[20];
		int q1[20], q2[20], q3[20], q4[20], sum[20], avg[20];
		int totalProfit;

		int TotalProfit(int j){
			totalProfit = 0;
			for(int i = 0; i < j; i++){
				totalProfit += sum[i];
			}
			return totalProfit;
		}

	};

	//function prototypes
	int Welcome();
	void BestQuarter(int quarter[], string quarterName[], int j);
	void UpsAndDowns(int quarter[], string quarterName[], int j);
	string IncreaseOrDecrease(int, int, int, int, int);

	int main(){
		Welcome();

		return 0;
	}


	int Welcome(){
		int i = 0, j = 0;
		cout << "Welcome" << endl;
		Product record;//create an instance of Product
		ifstream output("Project7.txt"); //open file to read in data
		if(output.is_open()){//check if file exists
			while(!output.eof()){//read data from file while not end of file
				output >> record.name[i] >> record.q1[i] >> record.q2[i] >> record.q3[i] >> record.q4[i];
				cout << record.name[i]  << " \t" << record.q1[i] << " \t" << record.q2[i] 
					 << " \t" << record.q3[i] << " \t" << record.q4[i] << " \t" 
					 << IncreaseOrDecrease(record.q1[i], record.q2[i], record.q3[i], record.q4[i], i) << " \n";
				record.sum[i] = record.q1[i] + record.q2[i] + record.q3[i] + record.q4[i];
				record.avg[i] = record.sum[i] / 4;
				cout << "Yearly Total: " << record.sum[i] << endl;
				cout << "Avg quarterly profit: " << record.avg[i] << endl << endl;
				i++;
			}
			cout << "***********************************";
			cout << "\nTotal Profit: " << record.TotalProfit(i);
			BestQuarter(record.q1, record.name, i);
			cout << "\nQ1 - Best item: '" << values.bestNumberName << "' with profit of: " << values.bestNumber; 
			BestQuarter(record.q2, record.name, i);
			cout << "\nQ2 - Best item: '" << values.bestNumberName << "' with profit of: " << values.bestNumber; 
			BestQuarter(record.q3, record.name, i);
			cout << "\nQ3 - Best item: '" << values.bestNumberName << "' with profit of: " << values.bestNumber; 
			BestQuarter(record.q4, record.name, i);
			cout << "\nQ4 - Best item: '" << values.bestNumberName << "' with profit of: " << values.bestNumber; 
			UpsAndDowns(record.q1, record.name, i);
			cout << "\n\nQ1 - Ups: " << values.ups << " downs: " << values.downs << " zeros: " << values.zeros;
			UpsAndDowns(record.q2, record.name, i);
			cout << "\nQ2 - Ups: " << values.ups << " downs: " << values.downs << " zeros: " << values.zeros;
			UpsAndDowns(record.q3, record.name, i);
			cout << "\nQ3 - Ups: " << values.ups << " downs: " << values.downs << " zeros: " << values.zeros;
			UpsAndDowns(record.q4, record.name, i);
			cout << "\nQ4 - Ups: " << values.ups << " downs: " << values.downs << " zeros: " << values.zeros;
			
		}
		else{
			cout << "File Not Found." << endl;

			output.close();
			return 0;
		}
	}

	//finds best quarter and stores it in bestNumber
	void BestQuarter(int quarter[], string quarterName[], int j){
		int bestNumber = 0;
		string bestNumberName;
		for(int i = 0; i < j; i++){
			if(quarter[i] > bestNumber){
				bestNumber = quarter[i];
				bestNumberName = quarterName[i];
			}
		}
		values.bestNumber = bestNumber;
		values.bestNumberName = bestNumberName;
		
	}

	//determine how many products made or lost profit or broke even
	void UpsAndDowns(int quarter[], string quarterName[], int j){
		values.ups = 0;
		values.downs = 0;
		values.zeros = 0;
		for(int i = 0; i < j; i++){
			if(quarter[i] > 0)
				values.ups++;
			else if(quarter[i] < 0)
				values.downs++;
			else
				values.zeros++;
		}

	}

	//determine if revenue is increasing or decreasing or mixed
	string IncreaseOrDecrease(int q1, int q2, int q3, int q4, int j){
		if(q1 < q2 && q2 < q3 && q3 < q4)
			return "Revenue Increasing\n";
		else if(q1 > q2 && q2 > q3 && q3 > q4)
			return "Revenue Decreasing\n";
		else
			return "Revenue is Mixed\n";

	}