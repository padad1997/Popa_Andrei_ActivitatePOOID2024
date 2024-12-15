#include <iostream>
#include <cstring> // Pentru strcpy și strlen

using namespace std;

class Avion {
private:
    char* nume;
    int capacitate;
    bool tip; // True = pasageri, False = cargo

public:
    // Constructor implicit
    Avion() : nume(nullptr), capacitate(0), tip(true) {}

    // Constructor cu parametri
    Avion(const char* nume, int capacitate, bool tip)
        : capacitate(capacitate), tip(tip) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    // Constructor de copiere
    Avion(const Avion& altAvion) {
        if (altAvion.nume != nullptr) {
            this->nume = new char[strlen(altAvion.nume) + 1];
            strcpy(this->nume, altAvion.nume);
        } else {
            this->nume = nullptr;
        }
        this->capacitate = altAvion.capacitate;
        this->tip = altAvion.tip;
    }

    // Destructor
    ~Avion() {
        if (this->nume != nullptr) {
            delete[] this->nume;
        }
    }

    // Operator de atribuire (supraincarcat)
    Avion& operator=(const Avion& altAvion) {
        if (this != &altAvion) {
            if (this->nume != nullptr) {
                delete[] this->nume;
            }

            if (altAvion.nume != nullptr) {
                this->nume = new char[strlen(altAvion.nume) + 1];
                strcpy(this->nume, altAvion.nume);
            } else {
                this->nume = nullptr;
            }
            this->capacitate = altAvion.capacitate;
            this->tip = altAvion.tip;
        }
        return *this;
    }

    // Operator de adunare (capacitățile a două avioane)
    Avion operator+(const Avion& altAvion) const {
        char newName[100] = "Combined "; // Prefix pentru numele nou
        strcat(newName, this->nume ? this->nume : "Unknown");
        Avion rezultat(newName, this->capacitate + altAvion.capacitate, this->tip);
        return rezultat;
    }

    // Operator de scădere (reduce capacitatea cu cea a altui avion)
    Avion operator-(const Avion& altAvion) const {
        Avion rezultat(this->nume ? this->nume : "Unknown",
                       this->capacitate - altAvion.capacitate,
                       this->tip);
        return rezultat;
    }

    // Operator de incrementare (prefix)
    Avion& operator++() {
        this->capacitate += 1;
        return *this;
    }

    // Operator de incrementare (postfix)
    Avion operator++(int) {
        Avion copie = *this;
        this->capacitate += 1;
        return copie;
    }

    // Operator de decrementare (prefix)
    Avion& operator--() {
        this->capacitate -= 1;
        return *this;
    }

    // Operator de decrementare (postfix)
    Avion operator--(int) {
        Avion copie = *this;
        this->capacitate -= 1;
        return copie;
    }

    // Operator de comparație egalitate
    bool operator==(const Avion& altAvion) const {
        return (this->capacitate == altAvion.capacitate &&
                this->tip == altAvion.tip &&
                strcmp(this->nume, altAvion.nume) == 0);
    }

    // Operator de comparație diferit
    bool operator!=(const Avion& altAvion) const {
        return !(*this == altAvion);
    }

    // Operator mai mare
    bool operator>(const Avion& altAvion) const {
        return this->capacitate > altAvion.capacitate;
    }

    // Operator mai mic
    bool operator<(const Avion& altAvion) const {
        return this->capacitate < altAvion.capacitate;
    }

    // Operator de acces direct la nume (indexare)
    char& operator[](int index) {
        if (index >= 0 && index < strlen(this->nume)) {
            return this->nume[index];
        } else {
            throw out_of_range("Index invalid!");
        }
    }

    // Operator de afișare (supraincarcă <<)
    friend ostream& operator<<(ostream& os, const Avion& avion) {
        os << "Avion: " << (avion.nume ? avion.nume : "Necunoscut")
           << ", Capacitate: " << avion.capacitate
           << ", Tip: " << (avion.tip ? "Pasageri" : "Cargo");
        return os;
    }

    // Operator de citire (supraincarcă >>)
    friend istream& operator>>(istream& is, Avion& avion) {
        char buffer[100];
        cout << "Introduceți numele avionului: ";
        is >> buffer;
        if (avion.nume != nullptr) {
            delete[] avion.nume;
        }
        avion.nume = new char[strlen(buffer) + 1];
        strcpy(avion.nume, buffer);
        cout << "Introduceți capacitatea: ";
        is >> avion.capacitate;
        cout << "Introduceți tipul (1 pentru pasageri, 0 pentru cargo): ";
        is >> avion.tip;
        return is;
    }

    // Metodă pentru afișare
    void afisare() const {
        cout << *this << endl;
    }
};

int main() {
    Avion avion1("Boeing 747", 416, true);
    Avion avion2("Airbus A320", 180, true);

    // Afișare folosind operatorul <<
    cout << "Avion 1: " << avion1 << endl;
    cout << "Avion 2: " << avion2 << endl;

    // Adunare capacități
    Avion avion3 = avion1 + avion2;
    cout << "Avion combinat: " << avion3 << endl;

    // Scădere capacități
    Avion avion4 = avion1 - avion2;
    cout << "Avion rezultat după scădere: " << avion4 << endl;

    // Comparare
    cout << "Avion 1 > Avion 2? " << (avion1 > avion2) << endl;

    // Incrementare
    cout << "Capacitate înainte de incrementare: " << avion1 << endl;
    ++avion1;
    cout << "Capacitate după incrementare: " << avion1 << endl;

    // Indexare
    try {
        cout << "Prima literă a numelui avionului 1: " << avion1[0] << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    // Citire de la tastatură
    Avion avion5;
    cin >> avion5;
    cout << "Avion citit: " << avion5 << endl;

    return 0;
}
