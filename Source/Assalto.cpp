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

std::string Assalto::getTipoAcidente() const{
	return "Assalto";
}

void Assalto::printInfoAcidente() const{
	std::cout << "***  ASSALTO  ***" << std::endl;
	std::cout << "Local: " << local->getNome() << std::endl;
	std::cout << "Data: " << data.getData() << std::endl;
	std::cout << "Numero da Ocorrencia: " << numOcorrencia << std::endl;
	std::cout << "Tipo de Casa: " << tipoCasa << std::endl;
	std::cout << "Feridos: " << ((haferidos == true) ? "Existem" : "Nao Existem") << std::endl;;
}
