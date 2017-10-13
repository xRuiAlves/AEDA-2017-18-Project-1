#ifndef PROTECAOCIVIL_H_
#define PROTECAOCIVIL_H_
#include <string>
#include <vector>
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


class ProtecaoCivil {
private:
	std::vector<Posto*> postos;
	std::vector<Acidente*> acidentes;
	std::vector<std::string> locais;
	const std::string ficheiroPostos;
	const std::string ficheiroAcidentes;
	const std::string ficheiroLocais;
public:
	ProtecaoCivil(const std::string &ficheiroPostos, const std::string &ficheiroAcidentes, const std::string &ficheiroLocais);
	~ProtecaoCivil();
	bool addAcidente(/*TODO parametros*/);
	bool rmAcidente(/*TODO parametros*/);
	void gravar() const;
};

#endif /* PROTECAOCIVIL_H_ */
