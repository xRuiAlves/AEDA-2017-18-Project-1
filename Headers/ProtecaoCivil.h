#ifndef PROTECAOCIVIL_H_
#define PROTECAOCIVIL_H_
#include <string>
#include <vector>
#include <fstream>
#include "Posto.h"
#include "Policia.h"
#include "Inem.h"
#include "Bombeiros.h"
#include "Acidente.h"
#include "AcidenteViacao.h"
#include "Incendio.h"
#include "IncendioDomestico.h"
#include "IncendioFlorestal.h"
#include "Assalto.h"
#include "Local.h"
#include "Erro.h"


class ProtecaoCivil {
private:
	std::vector<Posto*> postos;
	std::vector<Acidente*> acidentes;
	std::vector<Local> locais;
	const std::string ficheiroPostos;
	const std::string ficheiroAcidentes;
	const std::string ficheiroLocais;
	void gravar() const;
	unsigned int findLocal(const std::string &nomeLocal) const;
public:
	ProtecaoCivil(const std::string &ficheiroPostos, const std::string &ficheiroAcidentes, const std::string &ficheiroLocais);
	~ProtecaoCivil();
	bool addAcidente(/*TODO parametros*/);
	bool rmAcidente(/*TODO parametros*/);
	void openFiles();

	////////////////////////////////////////////////////////
	////////// TODO: Erase this method!!! //////////////////
	////////////////////////////////////////////////////////

	void print() const{
		for(unsigned int i=0 ; i<postos.size() ; i++){
			std::cout << postos.at(i)->getLocal()->getNome() << '/' << postos.at(i)->getLocal()->getXcoord() << '/' << postos.at(i)->getLocal()->getYcoord()
					<< '/' << postos.at(i)->getNumSocorristas()<< '/' << postos.at(i)->getNumVeiculos() << std::endl;
		}
		std::cout << "\n\n";
		for(unsigned int i=0 ; i<locais.size() ; i++){
			std::cout << locais.at(i).getNome() << '/' << locais.at(i).getXcoord() << '/' << locais.at(i).getYcoord() << std::endl;
		}
	}

	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////
};

#endif /* PROTECAOCIVIL_H_ */
