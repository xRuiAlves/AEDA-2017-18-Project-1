#ifndef POLICIA_H_
#define POLICIA_H_
#include "Posto.h"

class Policia : public Posto {
private:
	const std::string tipoVeiculo;
public:
	Policia(const unsigned int id, const Local* local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo);
	~Policia();
	const std::string getTipoVeiculo() const;
	std::string getTipoPosto() const;
	void printInfoPosto() const;
};

#endif /* POLICIA_H_ */
