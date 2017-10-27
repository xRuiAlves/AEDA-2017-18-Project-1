#ifndef INCENDIODOMESTICO_H_
#define INCENDIODOMESTICO_H_
#include <string>
#include "Incendio.h"

/**
 * Incêndio do tipo Doméstico. Classe derivada da classe Incêndio.
 */
class IncendioDomestico : public Incendio {
private:
	const std::string tipoCasa;			/**< Tipo de casa em que tem lugar a ocorrência. Pode ser "Apartamento" ou "Moradia". */
public:
	/**
	 * @brief Construtor da classe IncendioDomestico
	 * @param data - Data da ocorrência no formato DD-MM-AAAA
	 * @param local - Apontador para o local onde teve lugar o acidente
	 * @param numOcorrencia - Numero atribuído à ocorrência
	 * @param numBombeirosNecess - Número de bombeiros necessários para tratar da ocorrência
	 * @param numAutotanquesNecess - Número de autotanques necessários para tratar da ocorrência
	 * @param tipoCasa - Tipo de casa em que tem lugar a ocorrência
	 */
	IncendioDomestico(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numBombeirosNecess, unsigned int numAutotanquesNecess, const std::string &tipoCasa);

	/**
	 * @brief Destrutor da classe IncendioDomestico
	 */
	~IncendioDomestico();

	/**
	 * @brief Permite obter o tipo de casa em que tem lugar a ocorrência. Pode ser "Apartamento" ou "Moradia"
	 * @return Retorna "Apartamento" ou "Moradia", consoante o tipo de casa.
	 */
	const std::string getTipoCasa() const;

	/**
	 * @brief Permite obter o tipo de incêndio em questão.
	 * @return Retorna "Incendio Domestico"
	 */
	std::string getTipoAcidente() const;

	/**
	 * @brief Imprime no ecrã toda a informação relativa a este Incêndio Doméstico.
	 */
	void printInfoAcidente() const;

	/**
	 * @brief Imprime numa stream o conteudo simplificado de um Incêndio Doméstico
	 * @param os - Stream para a qual o conteúdo do Incêndio Doméstico é impresso
	 */
	void printSimplifiedInfo(std::ostream & os) const;
};

#endif /* INCENDIODOMESTICO_H_ */
