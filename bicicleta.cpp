#include <iostream>
#include <string>

using namespace std;

class Bicicleta
{
private:
	string producator;
	float greutate;
	int nrViteze;
	int* distante = nullptr;
	int nrExcursii = 0;

public:

	//constructor cu parametri ce joaca si rol de constructor default
	Bicicleta(string _producator = "Necunoscut", float _greutate = 3)
	{
		producator = _producator;
		greutate = _greutate;
		nrViteze = 1;
	}

	//initializare atribute in antet
	Bicicleta(string _producator, float _greutate, int nrViteze) : producator(_producator),
		greutate(_greutate), nrViteze(nrViteze)
	{

	}

	Bicicleta(string producator, int* distante, int nrExcursii)
	{
		this->producator = producator;
		if (distante != nullptr && nrExcursii > 0) {
			this->distante = new int[nrExcursii];
			for (int i = 0; i < nrExcursii; i++)
			{
				this->distante[i] = distante[i];
			}
			this->nrExcursii = nrExcursii;
		}
	}

	//constructor de copiere
	Bicicleta(const Bicicleta& b)
	{
		producator = b.producator;
		nrViteze = b.nrViteze;
		greutate = b.greutate;
		if (b.distante != nullptr && b.nrExcursii > 0) {
			this->distante = new int[b.nrExcursii];
			for (int i = 0; i < b.nrExcursii; i++)
			{
				this->distante[i] = b.distante[i];
			}
			this->nrExcursii = b.nrExcursii;
		}

	}

	//destructor
	~Bicicleta()
	{
		if (distante != nullptr) {
			delete[] distante;
			distante = nullptr;
		}

	}

	//getter
	string getProducator() {
		return producator;
	}

	//setter
	void setProducator(string _producator) {
		if (_producator.length() > 0)
		{
			producator = _producator;
		}
	}

	float getGreutate() {
		return greutate;
	}
	void setGreutate(float _greutate) {
		if (_greutate > 0)
		{
			greutate = _greutate;
		}
	}
};

int main() {

	Bicicleta b1;
	Bicicleta b2("Pegas", 12);


	cout << b1.getProducator() << endl;
	b2.setProducator("RockRider");
	cout << b2.getProducator() << endl;
	cout << b2.getGreutate() << endl;

	//declararea unui vector de obiecte
	//va declansa apelul constructorului implicit
	//pentru fiecare obiect (element)
	Bicicleta v[3];
	cout << v[0].getProducator() << endl;

	Bicicleta* pb;
	//alocare obiect in heap folosind constructor default
	pb = new Bicicleta();
	//stergere obiect din heap
	delete pb;
	pb = nullptr;

	//alocare obiect in heap folosind constructorr cu parametri
	pb = new Bicicleta("B'twin", 14);
	cout << pb->getProducator() << endl;
	delete pb;
	pb = nullptr;

	Bicicleta b3("Pegas", 10, 18);
	int d[3] = { 5,2,7 };
	Bicicleta b4("Romet", d, 3);
	d[0] = 99;
	Bicicleta b5 = b4;
	Bicicleta b6(b5);
}