#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const string token_dictionary = "p,q,r,s = 1 \\
                                 not     = 2 \\
                                 and     = 3 \\
                                 or      = 4 \\
                                 xor     = 5 \\
                                 if      = 6 \\
                                 then    = 7 \\
                                 iff     = 8 \\
                                 (       = 9 \\
                                 )       = 10 \\";

void print_all_token(vector<int> token_list){
    for(auto i = token_list.begin(); i != token_list.end(); i++){
        cout << *i << " ";
    }
}

string remove_space_from_string(string input){
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    return input;
}

int main(){
    
    vector<int> token_list;

    string proposional_logic = remove_space_from_string("p and q");
    cout << proposional_logic << endl;
    cout << proposional_logic.size();
    
    for (int i = 0; i < proposional_logic.size(); i++){
        
        // parsing untuk token p v q v r
        if(proposional_logic[i] == 'p' || 
           proposional_logic[i] == 'q' || 
           proposional_logic[i] == 'r' || 
           proposional_logic[i] == 's'){
               token_list.push_back(1);
           }
        // parsing untuk token or
        else if (proposional_logic[i] == 'n'){
            i++;
            if(proposional_logic[i] == 'o'){
                i++;
                if(proposional_logic[i] == 't'){
                    token_list.push_back(2);
                } else {
                    cout << "error";
                }
            } else {
                cout << "error";
            }
        }

        // parsing untuk token and
        else if (proposional_logic[i] == 'a'){
            i++;
            if(proposional_logic[i] == 'n'){
                i++;
                if(proposional_logic[i] == 'd'){
                    token_list.push_back(3);
                } else {
                    cout << "error";
                }
            }  else {
                cout << "error";
            }
        }

        // parsing untuk token or 
        else if (proposional_logic[i] == 'o'){
            i++;
            if(proposional_logic[i] == 'r'){
                token_list.push_back(4);
            } else {
                cout << "error";
            }
        }

        // parsing untuk token xor
        else if (proposional_logic[i] == 'x'){
            i++;
            if(proposional_logic[i] == 'o'){
                i++;
                if(proposional_logic[i] == 'r'){
                    token_list.push_back(5);
                } else {
                    cout << "error";
                }
            } else {
                cout << "error";
            }
        }

        // parsing untuk token if dan iff
        else if (proposional_logic[i] == 'i'){
            i++;
            if(proposional_logic[i] == 'f'){
                token_list.push_back(6);
                i++;
                if(proposional_logic[i] == 'f'){
                    token_list.push_back(7);
                } else {
                    cout << "error";
                }
            } else {
                cout << "error";
            }
        }

        // parsing untuk token (
        else if (proposional_logic[i] == '('){
            token_list.push_back(8);
        }
        
        // parsing untuk token )
        else if (proposional_logic[i] == ')'){
            token_list.push_back(9);
        }
    }

    cout << endl;
    print_all_token(token_list);    
}
