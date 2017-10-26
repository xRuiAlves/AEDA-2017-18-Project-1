#ifndef INEM_H_
#define INEM_H_
#include "Posto.h"

/**
 * Posto do Inem da Proteção Civil, classe derivada da classe Posto.
 */
class Inem : public Posto {
private:
	const std::string tipoVeiculo;			/**< Tipo de Veículo utilizado neste posto do Inem. Pode ser "Ambulancia", "Carro" ou "Moto" */
public:
	/**
	 * @brief Construtor da classe Inem
	 * @param id - Numero de identificação do Posto
	 * @param local - Apontador para o local onde o posto se encontra
	 * @param numSocorristas - Número de Socorristas do Posto
	 * @param numVeiculos - Número de Veículos do Posto
	 * @param tipoVeiculo - Tipo de Veículo utilizado neste Posto
	 */
	Inem(const unsigned int id, const Local* local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo);

	/**
	 * @brief Destrutor da classe Inem
	 */
	~Inem();

	/**
	 * @brief Permite obter o tipo de veículo utilizado neste posto
	 * @return Retorna "Ambulancia", "Carro" ou "Moto", consoante o tipo de veículo do posto.
	 */
	const std::string getTipoVeiculo() const;

	/**
	 * @brief Permite obter o tipo deste posto.
	 * @return Retorna "Inem"
	 */
	std::string getTipoPosto() const;

	/**
	 * @brief Imprime no ecrã toda a informação sobre este posto do Inem
	 */
	void printInfoPosto() const;

	/**
	 * @brief Imprime numa stream o conteudo simplificado de um posto do Inem
	 * @param os - Stream para a qual o conteúdo do posto do Inem é impresso
	 */
	void printSimplifiedInfo(std::ostream & os) const;
};

#endif /* INEM_H_ */
