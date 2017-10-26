#include "Posto.h"

Posto::Posto(const unsigned int id, const Local* local, unsigned int numSocorristas, unsigned int numVeiculos)
	: id(id) , local(local) , numSocorristas(numSocorristas) , numVeiculos(numVeiculos) {}

Posto::~Posto() {
	// TODO Auto-generated destructor stub
}

void Posto::addVeiculos(unsigned int num){
	numVeiculos += num;
}

void Posto::addSocorristas(unsigned int num){
	numSocorristas += num;
}

bool Posto::rmVeiculos(unsigned int num){
	if (numVeiculos >= num){	// Ha veiculos suficientes para poder remover "num" veiculos.
		numVeiculos -= num;
		return true;
	}
	else					// Nao ha veiculos suficientes para poder remover "num" veiculos.
		return false;
}

bool Posto::rmSocorristas(unsigned int num){

	if (numSocorristas >= num){	// Ha socorristas suficientes para poder remover "num" socorristas.
		numSocorristas -= num;
		return true;
	}
	else					// Nao ha socorristas suficientes para poder remover "num" socorristas.
		return false;
}

unsigned int Posto::getNumVeiculos() const{
	return numVeiculos;
}

unsigned int Posto::getNumSocorristas() const{
	return numSocorristas;
}

const Local* Posto::getLocal() const{
	return local;
}

const unsigned int Posto::getId() const{
	return id;
}
