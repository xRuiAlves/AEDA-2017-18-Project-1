#ifndef POLICIA_H_
#define POLICIA_H_
#include "Posto.h"

/**
 * Posto da Polícia da Proteção Civil, classe derivada da classe Posto.
 */
class Policia : public Posto {
private:
	const std::string tipoVeiculo;			/**< Tipo de Veículo utilizado neste posto da Polícia. Pode ser "Carro" ou "Moto" */
public:
	/**
	 * @brief Construtor da classe Policia
	 * @param id - Numero de identificação do Posto
	 * @param local - Apontador para o local onde o posto se encontra
	 * @param numSocorristas - Número de Socorristas do Posto
	 * @param numVeiculos - Número de Veículos do Posto
	 * @param tipoVeiculo - Tipo de Veículo utilizado neste Posto
	 */
	Policia(const unsigned int id, const Local* local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo);

	/**
	 * @brief Destrutor da classe Policia
	 */
	~Policia();

	/**
	 * @brief Permite obter o tipo de veículo utilizado neste posto
	 * @return Retorna "Carro" ou "Moto", consoante o tipo de veículo do posto.
	 */
	const std::string getTipoVeiculo() const;

	/**
	 * @brief Permite obter o tipo deste posto.
	 * @return Retorna "Policia"
	 */
	std::string getTipoPosto() const;

	/**
	 * @brief Imprime no ecrã toda a informação sobre este posto da Polícia
	 */
	void printInfoPosto() const;

	/**
	 * @brief Imprime numa stream o conteudo simplificado de um posto da Policia
	 * @param os - Stream para a qual o conteúdo do posto da Policia é impresso
	 */
	void printSimplifiedInfo(std::ostream & os) const;
};

#endif /* POLICIA_H_ */
