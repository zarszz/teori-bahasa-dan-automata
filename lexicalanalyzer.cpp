#include <iostream>
#include <list>

using namespace std;

void lexical_analyzer(string formula, list<int> &token);
void print_all_token(list<int> token_list);

list<int> token;

int main(){
    // TODO make code more clean

    string formula_from_input;

    while(true){

        token.clear();
        cout << "masukkan formula : ";
        getline(cin, formula_from_input);
        
        lexical_analyzer(formula_from_input, token);

        cout << endl << "token : ";
        print_all_token(token);
    }
}

void lexical_analyzer(string formula, list<int> &token){

    for (int i = 0; i < formula.size(); i++){
        
        // parsing untuk token p v q v r
        if(formula[i] == 'p' || formula[i] == 'q' || formula[i] == 'r' || formula[i] == 's'){
            if((
                (formula[i+1] == ' ' || 
                (formula[i+1] == '(' || formula[i+1] == ')')) || 
                i == (formula.length()-1)
              )){
            token.push_back(1);
           } else {
           token.push_back(999);
               break;
           }
       }
        // parsing untuk token not
        else if (formula[i] == 'n'){
            i++;
            if(formula[i] == 'o'){
                i++;
                if((formula[i] == 't' && (formula[i+1] == ' ' || formula[i+1] == '(')) || i == (formula.length()-1)){
                    token.push_back(2);
                } else {
                    token.push_back(999);
                    break;
                }
            } else {
                token.push_back(999);
                break;
            }
        }
        // parsing untuk token and
        else if (formula[i] == 'a'){
            i++;
            if(formula[i] == 'n'){
                i++;
                if(((formula[i] == 'd') && (formula[i+1] == ' ' || formula[i+1] == '(')) || i == (formula.length()-1)){
                    token.push_back(3);
                } else {
                    token.push_back(999);
                    break;
                }
            }  else {
                token.push_back(999);
                break;
            }
        }
        // parsing untuk token or 
        else if (formula[i] == 'o'){
            i++;
            if((formula[i] == 'r'  && (formula[i+1] == '(' || formula[i+1] == ' ')) || i == (formula.length()-1)){
                token.push_back(4);
            } else {
                token.push_back(999);
                break;
            }
        }
        // parsing untuk token xor
        else if (formula[i] == 'x'){
            i++;
            if(formula[i] == 'o'){
                i++;
                if((formula[i] == 'r' && (formula[i+1] == ' ' || formula[i+1] == '(')) || i == (formula.length()-1)){
                    token.push_back(5);
                } else {
                    token.push_back(999);
                    break;
                }
            } else {
                token.push_back(999);
                break;
            }
        }
        // parsing untuk token if atau iff
        else if (formula[i] == 'i'){
            int j = i + 1;
            if((formula[j] == 'f' && (formula[j+1] == '(' || formula[j+1] == ' ')) || i == (formula.length()-1)){
                token.push_back(6);
            } else if((formula[j] == 'f' && formula[j + 1] == 'f' && (formula[j + 2] == '(' || formula[j+2] == ' ')) || i == (formula.length()-1)){
                token.push_back(8);
            } else {
                token.push_back(999);
                break;
            }
        }
        // parsing untk token then
        else if (formula[i] == 't'){
            i++;
            if(formula[i] == 'h'){
                i++;
                if(formula[i] == 'e'){
                    i++;
                    if ((formula[i] == 'n'  && (formula[i+1] == ' ' || formula[i+1] == '(')) || i == (formula.length()-1)){
                        token.push_back(7);
                    } else {
                        token.push_back(999);
                        break;
                    }
                } else {
                    token.push_back(999);
                    break;
                }
            } else {
                token.push_back(999);
                break;
            }
        }
        // parsing untuk token (
        else if (formula[i] == '('){
            token.push_back(9);
        }
        
        // parsing untuk token )
        else if (formula[i] == ')'){
            token.push_back(10);
        }
    }

}

void print_all_token(list<int> token_list){
    for(auto i = token_list.begin(); i != token_list.end(); i++){
        if(*i != 999){
            cout << *i << " ";
        } else {
            cout << "error" << " ";
        }
    }
    cout << endl << endl;    
}