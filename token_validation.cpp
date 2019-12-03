#include "header_file.h";

vector<string> stack_validator;

void token_validation(vector<int> token){
	stack_validator.clear();

	string is_valid = "TIDAK VALID";
	int i = 0;
	
	stack_validator.push_back("#");
	
	while(i < token.size()){
		if(token[i] == 1){
			i++;
			if(i == token.size() && stack_validator[stack_validator.size() - 1] == "#"){
				stack_validator.clear();
			} else if(token[i] != 3 && token[i] != 4 && token[i] != 5 && token[i] != 7 && token[i] != 8 && token[i] != 10){
				break;
			}
		} else if(token[i] == 2){
			i++;
			if(token[i] != 1 && token[i] != 9){
				break;
			}
		} else if(token[i] == 3){
			i++;
			if(token[i] != 1 && token[i] != 2 && token[i] != 9){
				break;
			}
		} else if(token[i] == 4){			
			i++;
			if(token[i] != 1 && token[i] != 2 && token[i] != 9){
					break;
				}
		
		} else if(token[i] == 5){	
			i++;
		    if(token[i] != 1 && token[i] != 2 && token[i] != 9){
				break;
			}
		} else if(token[i] == 6){
			i++;
			if(token[i] != 1 && token[i] != 2 && token[i] != 9){
				break;
			} else {
				stack_validator.push_back("if");
			}
		} else if(token[i] == 7){			
			i++;
			if(token[i] != 1 && token[i] != 2 && token[i] != 9){
				break;
			} else {
				bool is_if_operator = false;
				while(stack_validator[stack_validator.size() - 1] != "#" && !is_if_operator){
					if(stack_validator[stack_validator.size() - 1] == "if"){
						is_if_operator = true;
					}
					stack_validator.pop_back();
				}
				if(!is_if_operator){
					break;
				}
			}
		} else if(token[i] == 8){			
			i++;
			if(token[i] != 1 && token[i] != 2 && token[i] != 9){
				break;
			}
		} else if(token[i] == 9){		
			i++;
			if(token[i] != 1 && token[i] != 2 && token[i] != 9){
				break;
			} else {
				stack_validator.push_back("(");
			}
		} else if(token[i] == 10){
			// <TODO> fix here for perfect program
			i++;

			if(i != token.size() && (token[i] != 3 && token[i] != 4 && token[i] != 5 && token[i] != 7 && token[i] != 8 && token[i] != 10)){
				break;		
			} else {
				bool is_close_bracket = false;
				while(stack_validator[stack_validator.size() - 1] != "#" && !is_close_bracket){
					if(stack_validator[stack_validator.size() - 1] == "("){
						is_close_bracket = true;
					}
					stack_validator.pop_back();
				}
				if(!is_close_bracket){
					break;
				} else if(i == token.size() && stack_validator[stack_validator.size() - 1] == "#"){
					stack_validator.clear();
				}
			}
		} else {			
			cout << "error" << endl;
			break;
		}		
	}
	
	cout << "isi stack : ";
	if(!stack_validator.empty()){
		for(auto i = stack_validator.begin(); i != stack_validator.end(); i++){
			cout << " " << *i;		
		}
	} else {
		cout << "kosong";
	}
	cout << endl;

	if(stack_validator.empty()){
		is_valid = "\nVALID";
	}
	cout << is_valid << endl;
}
