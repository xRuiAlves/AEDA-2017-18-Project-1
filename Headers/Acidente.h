#ifndef ACIDENTE_H_
#define ACIDENTE_H_
#include <string>

class Acidente {
protected:
	const std::string data;
	const std::string local;
	const unsigned int numOcorrencia;
public:
	Acidente(const std::string &data, const std::string &local, unsigned int numOcorrencia);
	virtual ~Acidente();
	const std::string getData() const;
	const std::string getLocal() const;
	const unsigned int getNuMOcorrencia() const;
};

#endif /* ACIDENTE_H_ */
