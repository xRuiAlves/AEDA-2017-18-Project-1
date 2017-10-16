#ifndef ASSALTO_H_
#define ASSALTO_H_
#include <string>
#include "Acidente.h"

class Assalto : public Acidente {
private:
	const std::string tipoCasa;
	const bool haferidos;
public:
	Assalto(const std::string &data, const Local* local, unsigned int numOcorrencia, const std::string &tipoCasa, bool haferidos);
	~Assalto();
	const std::string getTipoCasa() const;
	bool haFeridos() const;
	std::string getTipoAcidente() const;
	//void printInfoAcidente() const;			// TODO print todos os dados deste acidente
};

#endif /* ASSALTO_H_ */
