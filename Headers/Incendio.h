#ifndef INCENDIO_H_
#define INCENDIO_H_
#include <string>
#include "Acidente.h"

/**
 * Acidente do tipo incêncdio. Classe derivada da classe Acidente.
 */
class Incendio : public Acidente{
protected:
	const unsigned int numBombeirosNecess;			/**< Número de bombeiros necessários para tratar deste incêndio 	*/
	const unsigned int numAutotanquesNecess;		/**< Número de autotanques necessários para tratar deste incêndio 	*/
public:
	/**
	 * @brief Construtor da classe Incendio
	 * @param data - Data da ocorrência no formato DD-MM-AAAA
	 * @param local - Apontador para o local onde teve lugar o acidente
	 * @param numOcorrencia - Numero atribuído à ocorrência
	 * @param numBombeirosNecess - Número de bombeiros necessários para tratar da ocorrência
	 * @param numAutotanquesNecess - Número de autotanques necessários para tratar da ocorrência
	 */
	Incendio(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numBombeirosNecess, unsigned int numAutotanquesNecess);

	/**
	 * @brief Permite obter o número de bombeiros necessários para tratar do incêndio
	 * @return Retorna o número de bombeiros necessários para tratar do incêndio
	 */
	const unsigned int getNumBombeirosNecess() const;

	/**
	 * @brief Permite obter o número de autotanques necessários para tratar do incêndio
	 * @return Retorna o número de autotanques necessários para tratar do incêndio
	 */
	const unsigned int getNumAutotanquesNecess() const;

	/**
	 * @brief Destrutor da classe Incendio
	 */
	virtual ~Incendio();

	/**
	 * @brief Método puramente virtual que permite obter o tipo de incêndio em questão. A implementação encontra-se nas classes derivadas: IncendioFloretal e IncendioDomestico
	 * @return Retorna "Incendio Florestal" ou "Incendio Domestico" consoante o tipo de incêndio em questão
	 */
	virtual std::string getTipoAcidente() const = 0;

	/**
	 * @brief Método puramente virtual que imprime no ecrã toda a informação relativa ao incêndio em questão. A implementação encontra-se nas classes derivadas: IncendioFlorestal e IncendioDomestico
	 */
	virtual void printInfoAcidente() const = 0;

	/**
	 * @brief Método puramente virtual que imprime numa stream o conteudo simplificado de um incendio. A implementação encontra-se nas classes derivadas: IncendioDomestico e IncendioFlorestal
	 * @param os - Stream para a qual o conteúdo do incendio é impresso
	 */
	virtual void printSimplifiedInfo(std::ostream & os) const = 0;
};

#endif /* INCENDIO_H_ */
