#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<string> get_input_file(){
    vector<string> input_file;
    string data;
    ifstream inFile;

    inFile.open("proposional_logic_formula_data.txt");
    while(getline(inFile, data)){
        input_file.push_back(data);
    }
    inFile.close();
    return input_file;
}

void print_all_token(vector<int> token_list){
    for(auto i = token_list.begin(); i != token_list.end(); i++){
        if(*i != 999){
            cout << *i << " ";
        } else {
            cout << "error" << " ";
        }
    }
}

string remove_space_from_string(string input){
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    return input;
}

int main(){
    //vector<int> token1, token2, token3;
    //map<int, vector<int>> token_list;
    //token_list.insert(token1)
    //string formula1 = "(p and q) or r";
    //cout << formula1 << endl;

    // TODO make code more clean
    // TODO create map of vector

    vector<int> token;
    
    string formula = remove_space_from_string("iff then or xor p q r if s ( ) not");
    cout << "iff then or xor p q r if s ( ) not" << endl;
    
    for (int i = 0; i < formula.size(); i++){
        
        // parsing untuk token p v q v r
        if(formula[i] == 'p' || 
           formula[i] == 'q' || 
           formula[i] == 'r' || 
           formula[i] == 's'){
               token.push_back(1);
           }
        // parsing untuk token not
        else if (formula[i] == 'n'){
            i++;
            if(formula[i] == 'o'){
                i++;
                if(formula[i] == 't'){
                    token.push_back(2);
                } else {
                    // error
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
                if(formula[i] == 'd'){
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
            if(formula[i] == 'r'){
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
                if(formula[i] == 'r'){
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
            if(formula[j] == 'f' && (formula[j+1] == 'p' || 
                                     formula[j+1] == 'q' || 
                                     formula[j+1] == 'r' || 
                                     formula[j+1] == 's' ||
                                     formula[j+1] == '(' ||
                                     formula[j+1] == 'n')){
                token.push_back(6);
            } else if(formula[j] == 'f' && formula[j + 1] == 'f'){
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
                    if (formula[i] == 'n'){
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

    cout << endl;
    print_all_token(token);    
}