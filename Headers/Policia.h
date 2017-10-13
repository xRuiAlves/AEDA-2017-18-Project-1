#ifndef POLICIA_H_
#define POLICIA_H_
#include <string>
#include "Posto.h"

class Policia : public Posto {
private:
	const std::string tipoVeiculo;
public:
	Policia(const std::string &local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo);
	~Policia();
	const std::string getTipoVeiculo() const;
};

#endif /* POLICIA_H_ */
