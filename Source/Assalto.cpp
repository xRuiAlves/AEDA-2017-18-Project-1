#include "Assalto.h"

Assalto::Assalto(const std::string &data, const Local* local, unsigned int numOcorrencia, const std::string &tipoCasa, bool haferidos)
	: Acidente(data,local,numOcorrencia) , tipoCasa(tipoCasa) , haferidos(haferidos) {}

Assalto::~Assalto() {
	// TODO Auto-generated destructor stub
}

const std::string Assalto::getTipoCasa() const{
	return tipoCasa;
}
bool Assalto::haFeridos() const {
	return haferidos;

}

