#ifndef ACIDENTE_H_
#define ACIDENTE_H_
#include <string>
#include "Local.h"

class Acidente {
protected:
	const std::string data;
	const Local* local;
	const unsigned int numOcorrencia;
public:
	Acidente(const std::string &data, const Local* local, unsigned int numOcorrencia);
	virtual ~Acidente();
	const std::string getData() const;
	const Local* getLocal() const;
	const unsigned int getNuMOcorrencia() const;
};

#endif /* ACIDENTE_H_ */
