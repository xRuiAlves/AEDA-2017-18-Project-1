#include "Policia.h"

Policia::Policia(const Local* local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo)
	: Posto(local,numSocorristas,numVeiculos) , tipoVeiculo(tipoVeiculo) {}


Policia::~Policia() {
	// TODO Auto-generated destructor stub
}

const std::string Policia::getTipoVeiculo() const{
	return tipoVeiculo;
}
