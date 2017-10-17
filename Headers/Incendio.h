#ifndef INCENDIO_H_
#define INCENDIO_H_
#include <string>
#include "Acidente.h"

class Incendio : public Acidente{
private:
	const unsigned int numBombeirosNecess;
	const unsigned int numAutotanquesNecess;
public:
	Incendio(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numBombeirosNecess, unsigned int numAutotanquesNecess);
	const unsigned int getNumBombeirosNecess() const;
	const unsigned int getNumAutotanquesNecess() const;
	virtual ~Incendio();
	virtual std::string getTipoAcidente() const = 0;
	virtual void printInfoAcidente() const = 0;
};

#endif /* INCENDIO_H_ */
