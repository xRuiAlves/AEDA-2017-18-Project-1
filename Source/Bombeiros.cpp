#include "Bombeiros.h"

Bombeiros::Bombeiros(const Local* local, unsigned int numSocorristas, unsigned int numAutotanques, unsigned int numAmbulancias)
	: Posto(local,numSocorristas,numAutotanques+numAmbulancias) , numAutotanques(numAutotanques) , numAmbulancias(numAmbulancias) {}


Bombeiros::~Bombeiros() {
	// TODO Auto-generated destructor stub
}

void Bombeiros::addAutotanques(unsigned int num){
	numAutotanques += num;
	numVeiculos += num;		// Ao acrescentar Autotanques estamos também a acrescentar veículos ao posto!
}

void Bombeiros::addAmbulancias(unsigned int num){
	numAmbulancias += num;
	numVeiculos += num;		// Ao acrescentar Ambulancias estamos também a acrescentar veículos ao posto!
}

bool Bombeiros::rmAutotanques(unsigned int num){
	if (numAutotanques >= num){	// Ha autotanques suficientes
		numAutotanques -= num;
		return true;
	}
	else						// Nao ha autotanques suficientes
		return false;
}

bool Bombeiros::rmAmbulancias(unsigned int num){
	if (numAmbulancias >= num){	// Ha Ambulancias suficientes
		numAmbulancias -= num;
		return true;
	}
	else						// Nao ha Ambulancias suficientes
		return false;
}

unsigned int Bombeiros::getNumAutotanques() const{
	return numAutotanques;
}

unsigned int Bombeiros::getNumAmbulancias() const{
	return numAmbulancias;
}
