#ifndef ERRO_H_
#define ERRO_H_
#include <string>

/**
 * Classe Erro utilizada para tratamento de exceções no decorrer do programa.
 */
class Erro {
private:
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

class DataInvalida : public Erro {
public:
	DataInvalida(const std::string &info) : Erro(info) { }
};

class LocalidadeInexistente : public Erro {
public:
	LocalidadeInexistente(const std::string &info) : Erro(info) { }
};

class InputInvalido : public Erro {
public:
	InputInvalido(const std::string &info) : Erro(info) { }
};

class TipoAcidenteInvalido : public Erro {
public:
	TipoAcidenteInvalido(const std::string &info) : Erro(info) { }
};

class TipoCasaInvalido : public Erro {
public:
	TipoCasaInvalido(const std::string &info) : Erro(info) { }
};

class FicheiroNaoEncontrado : public Erro {
public:
	FicheiroNaoEncontrado(const std::string &info) : Erro(info) { }
};

class MeiosInsuficientes : public Erro {
public:
	MeiosInsuficientes(const std::string &info) : Erro(info) { }
};

class MeiosInexistentes : public Erro {
public:
	MeiosInexistentes(const std::string &info) : Erro(info) { }
};

#endif /* ERRO_H_ */
