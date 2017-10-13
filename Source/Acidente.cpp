#include "Acidente.h"


Acidente::Acidente(const std::string &data, const Local* local, unsigned int numOcorrencia)
	: data(data) , local(local) , numOcorrencia(numOcorrencia) {}


Acidente::~Acidente() {
	// TODO Auto-generated destructor stub
}

