//Project1 - Daniel Edelstein
//Program that computes algebraic equation using
//inputs from -4 to 3 and increments by 0.5
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

	int main() {

		double x, y;
		double xClosestToOne = 100.0;
		double yClosestToOne = 100.0;
		int pos = 0, neg = 0, z = 0;

		for(x = -4; x <= 3; x += 0.5){ // x = x + 0.5

			y = ( pow(x,4) - pow(x,3) - 7 * pow(x,2) + x + 6 ) 
			/ (abs(x - 3) + sqrt(5 - x));
			cout << setprecision(4) << x << " \t" << y << " \t";

			if (y == 0) {
				cout << " Y IS ZERO\n";
				z++;
			}
			else if (y > 0) {
				cout << " Y IS POSITIVE\n";
				pos++;
			}
			else if (y < 0) {
				cout << " Y IS NEGATIVE\n";
				neg++;
			}
			if(abs(1 - y) < yClosestToOne ){
				yClosestToOne = abs(1 - y);
				xClosestToOne = x;
			}
		}
		cout << "\nx value closest to 1 = " << xClosestToOne << "\n";
		cout << "y value closest to 1 = " << yClosestToOne + 1 << "\n";
		cout << "y is "<< yClosestToOne << " away from 1" << "\n";
		cout << "# of positive y = " << pos << "\n";
		cout << "# of negative y = " << neg << "\n";
		cout << "# of zero = " << z << "\n";

	
		cout << "\nProgram Halted";

		return 0;
	}