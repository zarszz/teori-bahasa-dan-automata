#include "header_file.h"

vector <int> token;

int main(){

    string formula_from_input;

    while(true){
        token.clear();

        cout << "masukkan formula : ";
        getline(cin, formula_from_input);

        lexical_analyzer(formula_from_input, token);

        cout << endl << "token : ";

		print_all_token(token);
		token_validation(token);
    }
}
