#include<iostream>
using namespace std;

	int fan(int &, int &, int);

	int main(){
		
		int x = 7, y = 10, z = 12, w = 15;

		w = fan(x,y,z);
		cout << "in main:" << endl;
		cout << x << " " << y << endl
			 << z << " " << w << endl;	

		return 0;
	}

	int fan(int &p, int &q, int r){

		int s;
		r++;
		if(p < q){
			s = p + 1;
			p = q + 1;
			q = s + 1;
		}
		else{
			s = q + 1;
			q = p + 1;
			p = s + 1;
		}

		cout << "in fan: ";
		cout << s << " " << p << " " << q << " " << r << endl;


		return s;
	}