#ifndef INCENDIOFLORESTAL_H_
#define INCENDIOFLORESTAL_H_
#include "Incendio.h"


/**
 * Incêndio do tipo Florestal. Classe derivada da classe Incêndio.
 */
class IncendioFlorestal : public Incendio {
private:
	const unsigned int areaChamas;		/**< Área das chamas neste Incêndio Florestal */
public:
	/**
	 * @brief Construtor da classe IncendioFlorestal
	 * @param data - Data da ocorrência no formato DD-MM-AAAA
	 * @param local - Apontador para o local onde teve lugar o acidente
	 * @param numOcorrencia - Numero atribuído à ocorrência
	 * @param numBombeirosNecess - Número de bombeiros necessários para tratar da ocorrência
	 * @param numAutotanquesNecess - Número de autotanques necessários para tratar da ocorrência
	 * @param areaChamas - Área das chamas no incêndio
	 */
	IncendioFlorestal(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numBombeirosNecess, unsigned int numAutotanquesNecess, unsigned int areaChamas);

	/**
	 * Destrutor da classe IncendioFlorestal
	 */
	~IncendioFlorestal();

	/**
	 * @brief Permite obter a área das chamas no incêndio
	 * @return Retorna a área das chamas no incêndio
	 */
	const unsigned int getAreaChamas() const;

	/**
	 * @brief Permite obter o tipo de incêndio em questão.
	 * @return Retorna "Incendio Florestal"
	 */
	std::string getTipoAcidente() const;

	/**
	 * @brief Imprime no ecrã toda a informação relativa a este Incêndio Florestal.
	 */
	void printInfoAcidente() const;

	/**
	 * @brief Imprime numa stream o conteudo simplificado de um Incêndio Florestal
	 * @param os - Stream para a qual o conteúdo do Incêndio Florestal é impresso
	 */
	void printSimplifiedInfo(std::ostream & os) const;
};

#endif /* INCENDIOFLORESTAL_H_ */
