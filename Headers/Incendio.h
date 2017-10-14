#ifndef INCENDIO_H_
#define INCENDIO_H_
#include <string>
#include "Acidente.h"

class Incendio : public Acidente{
private:
	const unsigned int numCarrosNecess;
	const unsigned int numAutotanquesNecess;
public:
	Incendio(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess);
	const unsigned int getNumCarrosNecess() const;
	const unsigned int getNumAutotanquesNecess() const;
	virtual ~Incendio();
	virtual std::string getTipoAcidente() const = 0;	// TODO
	virtual void printInfoAcidente() const = 0;			// TODO
};

#endif /* INCENDIO_H_ */
