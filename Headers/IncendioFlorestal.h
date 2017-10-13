#ifndef INCENDIOFLORESTAL_H_
#define INCENDIOFLORESTAL_H_
#include "Incendio.h"

class IncendioFlorestal : public Incendio {
private:
	const unsigned int areaChamas;
public:
	IncendioFlorestal(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess, unsigned int areaChamas);
	~IncendioFlorestal();
	const unsigned int getAreaChamas() const;
};

#endif /* INCENDIOFLORESTAL_H_ */
