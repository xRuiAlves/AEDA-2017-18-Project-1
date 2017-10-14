#ifndef PROTECAOCIVIL_H_
#define PROTECAOCIVIL_H_
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
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
	void ordernarPostos(bool compareFunction(Posto* p1, Posto*p2));
	void printTodosPostos() const;
};

#endif /* PROTECAOCIVIL_H_ */
