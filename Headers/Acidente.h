#ifndef ACIDENTE_H_
#define ACIDENTE_H_
#include <iostream>
#include <string>
#include <vector>
#include "Local.h"
#include "Date.h"
#include "Atribuicao.h"

/**
 * Acidente que foi declarado à Proteção Civil
 */
class Acidente {
protected:
	const Date data;						/**< Data em que decorreu o acidente 						*/
	const Local* local;						/**< Apontador para o local em que decorreu o acidentes 	*/
	const unsigned int numOcorrencia;		/**< Número atribuído à ocorrência							*/
	std::vector<Atribuicao> atribuicoes;	/**< Vetor de Atribuições de meios a esta ocorrência		*/
public:
	/**
	 * @brief Construtor da classe Acidente
	 * @param data - Data da ocorrência no formato DD-MM-AAAA
	 * @param local - Apontador para o local onde teve lugar o acidente
	 * @param numOcorrencia - Numero atribuído à ocorrência
	 */
	Acidente(const std::string &data, const Local* local, unsigned int numOcorrencia);

	/**
	 * @brief Destrutor da classe Acidente
	 */
	virtual ~Acidente();

	/**
	 * @brief Permite obter a data em que occoreu o acidente
	 * @return Retorna a data em que decorreu o acidente
	 */
	const Date getData() const;

	/**
	 * @brief Permite obter o local em que teve lugar o acidente
	 * @return Retorna o apontador para o local em que o acidente teve lugar
	 */
	const Local* getLocal() const;

	/**
	 * @brief Permite obter o número da ocorrencia
	 * @return Retorna o número atribuído a esta ocorrência
	 */
	const unsigned int getNumOcorrencia() const;

	/**
	 * @brief Método puramente virtual que permite obter o tipo de acidente em questão. A implementação encontra-se nas classes derivadas: AcidenteViacao, Assalto, IncendioFloretal e IncendioDomestico
	 * @return Retorna "Acidente de Viacao", "Assalto", "Incendio Florestal" ou "Incendio Domestico" consoante o tipo de acidente em questão
	 */
	virtual std::string getTipoAcidente() const = 0;

	/**
	 * @brief Método puramente virtual que imprime no ecrã toda a informação relativa ao acidete em questão. A implementação encontra-se nas classes derivadas: AcidenteViacao, Assalto, IncendioFlorestal e IncendioDomestico
	 */
	virtual void printInfoAcidente() const = 0;

	/**
	 * @brief Método puramente virtual que imprime numa stream o conteudo simplificado de um acidente. A implementação encontra-se nas classes derivadas: Assalto, AcidenteViacao, IncendioDomestico e IncendioFlorestal
	 * @param os - Stream para a qual o conteúdo do acidente é impresso
	 */
	virtual void printSimplifiedInfo(std::ostream & os) const = 0;

	/**
	 * @brief Adiciona uma atribuicao ao vetor de atribuicoes
	 * @param atribuicao - Atribuição a adicionar ao vetor de atribuicoes deste acidente
	 */
	void addAtribuicao(const Atribuicao & atribuicao);

	/**
	 * @brief Imprime todas as atribuicoes relativas a este acidente de uma forma legível para o utilizador
	 */
	void printAtribuicoes() const;

	/**
	 * @brief Permite obter todas as atribuicoes efetuadas a este acidente
	 * @return Retorna um vetor que contém todas as atribuicoes efetuadas a este acidente
	 */
	std::vector<Atribuicao> getAtribuicoes() const;
};

#endif /* ACIDENTE_H_ */
