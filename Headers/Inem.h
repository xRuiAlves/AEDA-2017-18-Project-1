#ifndef INEM_H_
#define INEM_H_
#include "Posto.h"

class Inem : public Posto {
private:
	const std::string tipoVeiculo;
public:
	Inem(const Local* local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo);
	~Inem();
	const std::string getTipoVeiculo() const;
	std::string getTipoPosto() const;
};

#endif /* INEM_H_ */
