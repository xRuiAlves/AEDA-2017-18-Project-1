#ifndef ACIDENTEVIACAO_H_
#define ACIDENTEVIACAO_H_
#include <string>
#include "Acidente.h"

class AcidenteViacao : public Acidente {
private:
	const std::string tipoEstrada;
	const unsigned int numFeridos;
	const unsigned int numVeiculos;
public:
	AcidenteViacao(const std::string &data, const Local* local, unsigned int numOcorrencia, const std::string &tipoEstrada, unsigned int numFeridos, unsigned int numVeiculos);
	~AcidenteViacao();
	const std::string getTipoEstrada() const;
	const unsigned int getNumFeridos() const;
	const unsigned int getNumVeiculos() const;
};

#endif /* ACIDENTEVIACAO_H_ */
