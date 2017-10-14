#include "AcidenteViacao.h"

AcidenteViacao::AcidenteViacao(const std::string &data, const Local* local, unsigned int numOcorrencia, const std::string &tipoEstrada, unsigned int numFeridos, unsigned int numVeiculos)
	: Acidente(data,local,numOcorrencia) , tipoEstrada(tipoEstrada) , numFeridos(numFeridos) , numVeiculos(numVeiculos) {}

const std::string AcidenteViacao::getTipoEstrada() const{
	return tipoEstrada;
}
const unsigned int AcidenteViacao::getNumFeridos() const{
	return numFeridos;
}
const unsigned int AcidenteViacao::getNumVeiculos() const {
	return numVeiculos;
}

AcidenteViacao::~AcidenteViacao() {
	// TODO Auto-generated destructor stub
}

