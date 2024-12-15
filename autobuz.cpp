#include <iostream>
#include <string>

using namespace std;

class Autobuz {
private:
    static int nrAutobuze;   
    const int idAutobuz;     
    int capacitate;          
    int nrPersoaneImbarcate; 
    char* producator;        

public:
    // Constructor implicit
   Autobuz() : idAutobuz(++nrAutobuze), capacitate(0), nrPersoaneImbarcate(0) {
        this->producator = new char[strlen("Necunoscut") + 1];
        strcpy(this->producator, "Necunoscut");
    }

    // Constructor cu parametru
  Autobuz(const char* _producator, int _capacitate) 
        : idAutobuz(++nrAutobuze) {
        this->capacitate = _capacitate;
        this->nrPersoaneImbarcate = 0;
        this->producator = new char[strlen(_producator) + 1];
        strcpy(this->producator, _producator);
    }
    
    // Destructor
    //cout << endl << "S-a apelat destructorul!";
    ~Autobuz() {
        delete[] producator;
    }
   
   // Constructor de copiere
    Autobuz(const Autobuz& Microbuz) 
        : idAutobuz(++nrAutobuze) {
        this->capacitate = Microbuz.capacitate;
        this->nrPersoaneImbarcate = Microbuz.nrPersoaneImbarcate;
        this->producator = new char[strlen(Microbuz.producator) + 1];
        strcpy(this->producator, Microbuz.producator);
    }
    // Getter pentru capacitate
    int getCapacitate() const {
        return this->capacitate;
    }

    // Setter pentru capacitate
    void setCapacitate(int _capacitate) {
        if (_capacitate >= 0) {
            this->capacitate = _capacitate;
        } else {
            cout << "Capacitatea nu poate fi negativă.\n";
        }
    }

    // Getter pentru nrPersoaneImbarcate
    int getNrPersoaneImbarcate() const {
        return this->nrPersoaneImbarcate;
    }

    // Setter pentru nrPersoaneImbarcate
    void setNrPersoaneImbarcate(int _nrPersoaneImbarcate) {
        if (_nrPersoaneImbarcate < 0) {
            cout << "Numărul de persoane îmbarcate nu poate fi negativ.\n";
        } else if (_nrPersoaneImbarcate > this->capacitate) {
            cout << "Numărul de persoane îmbarcate depășește capacitatea autobuzului.\n";
        } else {
            this->nrPersoaneImbarcate = _nrPersoaneImbarcate;
        }
    }


    // Operator de atribuire
    Autobuz& operator=(const Autobuz& Microbuz) {
        if (this != &Microbuz) {
            delete[] producator;
            capacitate = Microbuz.capacitate;
            nrPersoaneImbarcate = Microbuz.nrPersoaneImbarcate;

            producator = new char[strlen(Microbuz.producator) + 1];
            strcpy(producator, Microbuz.producator);
        }
        return *this;
    }

    // Suprascriere operator <<
    friend ostream& operator<<(ostream& os, const Autobuz& a) {
        os << "Autobuzul \"" << a.producator << "\"; ID: " << a.idAutobuz << "; Capacitate: " << a.capacitate << "; Persoane îmbarcate: " << a.nrPersoaneImbarcate;
        return os;
    }
    // Metoda pentru calcularea numărului de locuri libere
    int getNumarLocuriLibere() const {
        return capacitate - nrPersoaneImbarcate;
    }
     // Operator de conversie la int
    operator int() const {
        return nrPersoaneImbarcate;
    }
    // Suprascriere operator >
    bool operator>(const Autobuz& other) const {
        return this->capacitate > other.capacitate;
    }
      // Metoda pentru afisarea detaliilor
    void afiseazaDetalii() const {
        cout << *this << "\nLocuri libere: " << getNumarLocuriLibere() << endl;
    }
};

int Autobuz::nrAutobuze = 0;

int main() {

    Autobuz autobuz1("Mercedes", 40);
    Autobuz autobuz2("Renault", 50);
    Autobuz autobuz3("MAN", 70);

    autobuz1.setNrPersoaneImbarcate(35);
    autobuz2.setNrPersoaneImbarcate(40);
    autobuz3.setNrPersoaneImbarcate(67);

    cout << "\nDetalii Autobuz 1:\n";
    autobuz1.afiseazaDetalii();

    cout << "\nDetalii Autobuz 2:\n";
    autobuz2.afiseazaDetalii();

    cout << "\nDetalii Autobuz 3:\n";
    autobuz3.afiseazaDetalii();

     // Testarea operatorului de cast
    int nrPersoaneAutobuz1 = autobuz1; // Convertem autobuz1 la int
    cout << "\nNumărul de persoane îmbarcate în autobuzul 1: " << nrPersoaneAutobuz1 << endl;


    Autobuz autobuz5 = autobuz3;
    cout << "\nDetalii Autobuz 5; \n";
    autobuz5.afiseazaDetalii();

    Autobuz autobuz6; 
    autobuz6 = autobuz2;
    cout << "\n Detalii Autobuz 6 (atribuit din Autobuz 2):\n";
    autobuz6.afiseazaDetalii();

    // Testarea operatorului de comparare (>)
    if (autobuz1 > autobuz2) {
        cout << "\nAutobuzul 1 are o capacitate mai mare decat autobuzul 2.\n";
    } else {
        cout << "\nAutobuzul 1 nu are o capacitate mai mare decat autobuzul 2.\n";
    }

    return 0;
}