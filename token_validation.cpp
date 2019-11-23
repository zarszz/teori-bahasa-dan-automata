#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<string> stack_validator;

string check_token_string(int token_item){
	
}

void token_validation(vector<int> token){
	int i = 0;
	while(i < token.size()){
		switch (token[i]) {
			case 1 :
				cout << "1" << endl;
			case 2 : 
				cout << "2" << endl;
			case 3 : 
				cout << "3" << endl;
			case 4 : 
				cout << "4" << endl;
			case 5 : 
				cout << "5" << endl;
			case 6 : 
				cout << "6" << endl;
			case 7 :
				cout << "7" << endl;
			case 8 : 
				cout << "8" << endl;
			case 9 : 
				cout << "9" << endl;
			case 10 : 
				cout << "10" << endl;
			default : 
				cout << "error" << endl;
		}
		i++;
	}
}


