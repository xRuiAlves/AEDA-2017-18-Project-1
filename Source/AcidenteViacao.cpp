#include "AcidenteViacao.h"

AcidenteViacao::AcidenteViacao(const std::string &data, const std::string &local, unsigned int numOcorrencia, const std::string &tipoEstrada, unsigned int numFeridos, unsigned int numVeiculos)
	: Acidente(data,local,numOcorrencia) , tipoEstrada(tipoEstrada) , numFeridos(numFeridos) , numVeiculos(numVeiculos) {}


AcidenteViacao::~AcidenteViacao() {
	// TODO Auto-generated destructor stub
}

