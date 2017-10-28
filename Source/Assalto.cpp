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

void Assalto::printSimplifiedInfo(std::ostream & os) const{
	// Imprimir os dados do assalto propriamente dito
	os << local->getNome() << '/' << data.getData() << "/Assalto/" << tipoCasa << '/' << ((haferidos == true) ? '1' : '0') << '/' << atribuicoes.size();

	// Imprimir info sob atribuições relativas a esta ocorrência
	for (unsigned int i=0 ; i<atribuicoes.size() ; i++){
		// Mudar de linha, fazer um tab para indexar e imprimir informação da atribuição
		os << "\n\t" << atribuicoes.at(i);
	}
}
