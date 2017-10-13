#ifndef INCENDIODOMESTICO_H_
#define INCENDIODOMESTICO_H_
#include <string>
#include "Incendio.h"

class IncendioDomestico : public Incendio {
private:
	const std::string tipoCasa;
public:
	IncendioDomestico(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess, const std::string &tipoCasa);
	~IncendioDomestico();
	const std::string getTipoCasa() const;
};

#endif /* INCENDIODOMESTICO_H_ */
