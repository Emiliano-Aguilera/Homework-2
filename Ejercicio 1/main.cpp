#include <iostream>
#include <string>

#include "time.hpp"

using namespace std;

int getInput();

int main(){
    int option;
    Time moment;
    do{
        try {
            cout << "Opcion: ";
            option = getInput();
            switch (option) {
                case 0:
                    
            }
        }
        catch (...) {
            cout << "Valor invalido." << endl;
        }
    } while (option > 0 && option < 9);

}

int getInput(){
    string input;
    std::getline(cin, input);
    int intInput;
    
    try{
        intInput = stoi(input);
    }
    catch (invalid_argument const& ex){
        throw ex;
    }
    catch(out_of_range const& ey){
        throw ey;
    }
    
    return intInput;
}


