#include <iostream>
#include <string>

using namespace std;

class Elicopter {
protected:

int capacitate;
bool rezervor;
char* nume;

public:
//constructor implicit

Elicopter(): nume(nullptr), capacitate(0), rezervor(true) {}

//constructor cu parametri
Elicopter(const char* nume, int capacitate, bool rezervor)
        : capacitate(capacitate), rezervor (rezervor) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
}

//constructor de copiere
Elicopter(const Elicopter&altElicopter){
    if(altElicopter.nume != nullptr){
        this->nume = new char[strlen(altElicopter.nume)+1];
        strcpy(this->nume, altElicopter.nume);
        }else {
            this->nume = nullptr;
        }
        this->capacitate=altElicopter.capacitate;
        this->rezervor=altElicopter.rezervor;

    }

// destructor
~Elicopter (){
 if (this->nume != nullptr) {
            delete[] this->nume;
        }}
};
int main
