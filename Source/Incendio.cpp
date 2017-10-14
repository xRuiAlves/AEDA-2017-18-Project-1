#include "Incendio.h"

Incendio::Incendio(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess)
	: Acidente(data,local,numOcorrencia) , numCarrosNecess(numCarrosNecess) , numAutotanquesNecess(numAutotanquesNecess) {}

const unsigned int Incendio::getNumCarrosNecess() const{
	return numCarrosNecess;
}

const unsigned int Incendio::getNumAutotanquesNecess() const{
	return numAutotanquesNecess;
}

Incendio::~Incendio() {
	// TODO Auto-generated destructor stub
}

