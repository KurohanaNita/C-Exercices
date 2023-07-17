/*
 Ex - camel to snake / snake to camel
But : le but est de convertir un nom de variable de la notation de type camel case à snake case, et vice versa.
Auteur(-e-s) : Elbunita Halimi
Date création : 17.07.2023
mise à jour : 17.07.2023
Remarque(s) :.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// version compliquée...
void to_camel_case(string& text) {
    for (int i = 0; i <= text.length(); i++) {
        int pos1 = text.find('_');
        int pos2 = text.find('-');

        if (pos1 > 0 ) {
            text[pos1 + 1] = toupper(text[pos1 + 1]);
            text.erase(pos1, 1);
        } else if (pos2 > 0 ) {
            text[pos2 + 1] = toupper(text[pos2 + 1]);
            text.erase(pos2, 1);
        } else {
            break;
        }

        pos1 = pos2 = 0;

    }

}

// version un peu moins compliquée =D
void toCamelCase(string& text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '-' || text[i] == '_') {
            text[i + 1] = toupper(text[i + 1]);
            text.erase(i, 1);
        }
    }
}

//droit au but cette fois!
void toSnakeCase(string& text) {
    for (int i = 0; i < text.length(); i++ ) {
        bool upper = isupper(text[i]);
        if (upper) {
            text[i] = tolower(text[i]);
            text.insert(i, "_");
        }
    }

}

int main() {
    string snakeCase = "this_is-a_test-for-real_just_a-test";
    string snakeCase2 = "lets_do-it-cleaner_this_time";
    string camelCase = "okLetsTryAgainButThisTimeTheOtherWayAround";



    to_camel_case(snakeCase);
    toCamelCase(snakeCase2);
    toSnakeCase(camelCase);


    cout << snakeCase << endl << snakeCase2 << endl << camelCase;



    return 0;
}
