#include "Incendio.h"

Incendio::Incendio(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numBombeirosNecess, unsigned int numAutotanquesNecess)
	: Acidente(data,local,numOcorrencia) , numBombeirosNecess(numBombeirosNecess) , numAutotanquesNecess(numAutotanquesNecess) {}

const unsigned int Incendio::getNumBombeirosNecess() const{
	return numBombeirosNecess;
}

const unsigned int Incendio::getNumAutotanquesNecess() const{
	return numAutotanquesNecess;
}

Incendio::~Incendio() {
	// TODO Auto-generated destructor stub
}
