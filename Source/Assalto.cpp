#include "Assalto.h"

Assalto::Assalto(const std::string &data, const std::string &local, unsigned int numOcorrencia, const std::string &tipoCasa, bool haFeridos)
	: Acidente(data,local,numOcorrencia) , tipoCasa(tipoCasa) , haFeridos(haFeridos) {}


Assalto::~Assalto() {
	// TODO Auto-generated destructor stub
}

