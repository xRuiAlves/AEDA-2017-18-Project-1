#include "Incendio.h"

Incendio::Incendio(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess)
	: Acidente(data,local,numOcorrencia) , numCarrosNecess(numCarrosNecess) , numAutotanquesNecess(numAutotanquesNecess) {}


Incendio::~Incendio() {
	// TODO Auto-generated destructor stub
}

