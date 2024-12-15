#include <iostream>
#include <string>

using namespace std;

class tren{

private:

    float capacitate;
    int serie;
    char* nume;
    int vagoane;

public:
 
 //constructor implicit

 tren(): capacitate(0), serie(0), vagoane(0), nume(nullptr) {}

//constructor cu parametri

tren (const char* nume, float capacitate, int serie, int vagoane)

:capacitate(capacitate), serie(serie), vagoane(vagoane){
    this->nume = new char [strlen (nume)+1];
    strcpy (this->nume, nume);

}

~ tren() {
    if (this->nume != nullptr);
    delete[] this->nume;

}
//constructor de copiere
tren(const tren&altElicopter){
    if(altElicopter.nume != nullptr){
        this->nume = new char[strlen(altElicopter.nume)+1];
        strcpy(this->nume, altElicopter.nume);
        }else {
            this->nume = nullptr;
        }
        this->capacitate=altElicopter.capacitate;
        this->serie=altElicopter.serie;
        this->vagoane=altElicopter.vagoane;
    }

    friend ostream& operator<<(ostream& os, const tren& a) {
        os << "trenul \"" << a.capacitate << "\"; ID: " << a.serie << "; Capacitate: " << a.vagoane << "; Persoane îmbarcate: " << a.nume;
        return os;
    }
};

int main (){

tren tren1("IR", 4.0f, 4566, 19);

}
