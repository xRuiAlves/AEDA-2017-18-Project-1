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

std::string AcidenteViacao::getTipoAcidente() const{
	return "Acidente de Viacao";
}

void AcidenteViacao::printInfoAcidente() const {
	std::cout << "***  ACIDENTE DE VIAÇÃO  ***" << std::endl;
	std::cout << "Tipo de Estrada: " << tipoEstrada << std::endl;
	std::cout << "Número de Feridos: " << numFeridos << std::endl;
	std::cout << "Número Veículos: " << numVeiculos << std::endl;
}
