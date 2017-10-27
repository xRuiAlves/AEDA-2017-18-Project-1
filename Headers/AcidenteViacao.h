#ifndef ACIDENTEVIACAO_H_
#define ACIDENTEVIACAO_H_
#include <string>
#include "Acidente.h"

/**
 * Acidente do tipo Acidente de Viação. Classe derivada da classe Acidente.
 */
class AcidenteViacao : public Acidente {
private:
	const std::string tipoEstrada;			/** Tipo de estrada em que ocorreu o acidente. Pode ser "Estrada Nacional" ou "Auto-Estrada" 	*/
	const unsigned int numFeridos;			/** Número de feridos envolvidos no acidente													*/
	const unsigned int numVeiculos;			/** Número de veículos envolvidos no acidente													*/
public:
	/**
	 * @brief Construtor da classe AcidenteViacao
	 * @param data - Data da ocorrência no formato DD-MM-AAAA
	 * @param local - Apontador para o local onde teve lugar o acidente
	 * @param numOcorrencia - Numero atribuído à ocorrência
	 * @param tipoEstrada - Tipo de estrada em que ocorreu o acidente
	 * @param numFeridos - Número de feridos envolvidos no acidente
	 * @param numVeiculos - Número de veículos envolvidos no acidente
	 */
	AcidenteViacao(const std::string &data, const Local* local, unsigned int numOcorrencia, const std::string &tipoEstrada, unsigned int numFeridos, unsigned int numVeiculos);

	/**
	 * @brief Destrutor da classe AcidenteViacao
	 */
	~AcidenteViacao();

	/**
	 * @brief Permite obter o tipo de estrada em que ocorreu o acidente. Pode ser "Estrada Nacional" ou "Auto-Estrada"
	 * @return Retorna "Estrada Nacional" ou "Auto-Estrada", consoante o tipo de estrada em que ocorreu o Acidente de Viação.
	 */
	const std::string getTipoEstrada() const;

	/**
	 * @brief Permite obter o número de feridos envolvidos no acidente.
	 * @return Retorna o número de feridos envolvidos no acidente.
	 */
	const unsigned int getNumFeridos() const;

	/**
	 * @brief Permite obter o veículos de feridos envolvidos no acidente.
	 * @return Retorna o número de veículos envolvidos no acidente.
	 */
	const unsigned int getNumVeiculos() const;

	/**
	 * @brief Permite obter o tipo de acidente em questão.
	 * @return Retorna "Acidente de Viacao"
	 */
	std::string getTipoAcidente() const;

	/**
	 * @brief Imprime no ecrã toda a informação relativa a este Acidente de Viação.
	 */
	void printInfoAcidente() const;		

	/**
	 * @brief Imprime numa stream o conteudo simplificado de um Acidente de Viação
	 * @param os - Stream para a qual o conteúdo do Acidente de Viação é impresso
	 */
	void printSimplifiedInfo(std::ostream & os) const;
};

#endif /* ACIDENTEVIACAO_H_ */
