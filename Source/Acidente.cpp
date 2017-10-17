#include "Acidente.h"


Acidente::Acidente(const std::string &data, const Local* local, unsigned int numOcorrencia)
	: data(Date(data)) , local(local) , numOcorrencia(numOcorrencia) {}

const Date Acidente::getData() const {
	return data;
}

const Local* Acidente::getLocal() const {
	return local;
}


const unsigned int Acidente::getNumOcorrencia() const {
	return numOcorrencia;
}


Acidente::~Acidente() {
	// TODO Auto-generated destructor stub
}

