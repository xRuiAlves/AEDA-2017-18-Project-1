#ifndef ERRO_H_
#define ERRO_H_
#include <string>

/**
 * Classe Erro utilizada para tratamento de exceções no decorrer do programa.
 */
class Erro {
	const std::string info;		/**< Informação do erro que ocorreu aquando uma exceção */
public:
	/**
	 * @brief Construtor da classe Erro
	 * @param info - Descrição do tipo de erro que aconteceu aquando o lancamento de uma exceção
	 */
	Erro(const std::string &info) : info(info) {}

	/**
	 * @brief Permite obter a descrição do Erro
	 * @return Retorna a descrição do Erro
	 */
	const std::string getInfo() const { return info; }
};

class DataInvalida : public Erro { } ;

class LocalidadeInexistente : public Erro { } ;

class InputInvalido : public Erro { } ;

class TipoAcidenteInvalido : public Erro { } ;

class TipoCasaInvalido : public Erro { } ;

class FicheiroNaoEncontrado : public Erro { } ;

class MeiosInsuficientes : public Erro { } ;

class MeiosInexistentes : public Erro { } ;

#endif /* ERRO_H_ */
