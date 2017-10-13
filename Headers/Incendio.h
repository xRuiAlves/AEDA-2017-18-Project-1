#ifndef INCENDIO_H_
#define INCENDIO_H_
#include <string>
#include "Acidente.h"

class Incendio : public Acidente{
private:
	const unsigned int numCarrosNecess;
	const unsigned int numAutotanquesNecess;
public:
	Incendio(const std::string &data, const std::string &local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess);
	virtual ~Incendio();
};

#endif /* INCENDIO_H_ */
