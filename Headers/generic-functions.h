#ifndef GENERIC_FUNCTIONS_H_
#define GENERIC_FUNCTIONS_H_

/**
 * @param min - O valor mínimo que o utilizador pode introduzir.
 * @param max - O valor máximo que o utilizador pode introduzir.
 * @brief Recebe do utilizador um número no intervalo [min,max]. Se o utilizador introduzir um número fora do intervalo / input errado, lança um exceção (objeto Erro).
 * @return Retorna o numero que o utilizador introduziu, se o número estiver dentro do intrevalo / se não tiver ocorrido erro de input.
 */
int getOption(int min, int max);

/**
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar.
 * @brief Permite ao utilizador declarar um acidente que tenha decorrido, bem como todas as suas especificações.
 */
void declararOcorrencia(ProtecaoCivil &protecaoCivil);

/**
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar.
 * @brief Permite ao utilizador dar por terminada um ocorrência que esteja em decurso.
 */
void terminarOcorrencia(ProtecaoCivil &protecaoCivil);

/**
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar.
 * @brief Permite ao utilizador pesquisar sobre as várias ocorrências em aberto, utilizando diversos critérios de procura diferentes.
 */
void infoOcorrencia(ProtecaoCivil &protecaoCivil);

/**
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar.
 * @brief Permite ao utilizador pesquisar sobre os vários postos da Proteção Civil, utilizando diversos critério de procura diferentes.
 */
void pesquisarPostos(ProtecaoCivil &protecaoCivil);

/**
 * @param p1 - Apontador para um posto genérico.
 * @param p2 - Apontador para um posto genérico.
 * @brief Permite comparar dois postos pelo local (ordem alfabética) em que estão. Esta função é utilizada com "função auxiliar" em algorítmos de ordenação.
 * @return Retorna true se o local do posto p1 for menor que o local do posto p2 (ordem alfabética) e false caso contrário.
 */
bool compararPostosLocal(Posto* p1, Posto* p2);

/**
 * @param p1 - Apontador para um posto genérico.
 * @param p2 - Apontador para um posto genérico.
 * @brief Permite comparar dois postos pelo tipo de posto (ordem alfabética). Esta função é utilizada com "função auxiliar" em algorítmos de ordenação.
 * @return Retorna true se o tipo de posto p1 for menor que o tipo de posto p2 (ordem alfabética) e false caso contrário.
 */
bool compararPostosTipo(Posto* p1, Posto* p2);

/**
 * @param a1 - Apontador para um acidente genérico.
 * @param a2 - Apontador para um acidente genérico.
 * @brief Permite comparar dois acidentes pelo local (ordem alfabética) em que estão. Esta função é utilizada com "função auxiliar" em algorítmos de ordenação.
 * @return Retorna true se o local do acidente a1 for menor que o local do acidente a2 (ordem alfabética) e false caso contrário.
 */
bool compararAcidentesLocal(Acidente* a1, Acidente* a2);

/**
 * @param a1 - Apontador para um acidente genérico.
 * @param a2 - Apontador para um acidente genérico.
 * @brief Permite comparar dois acidentes pelo tipo de acidente (ordem alfabética). Esta função é utilizada com "função auxiliar" em algorítmos de ordenação.
 * @return Retorna true se o tipo de acidente do acidente a1 for menor que o tipo de acidente do acidente a2 (ordem alfabética) e false caso contrário.
 */
bool compararAcidentesTipo(Acidente* a1, Acidente* a2);

/**
 * @param a1 - Apontador para um acidente genérico.
 * @param a2 - Apontador para um acidente genérico.
 * @brief Permite comparar dois acidentes pela data em que decorreram (ordem cronológica). Esta função é utilizada com "função auxiliar" em algorítmos de ordenação.
 * @return Retorna true se a data do acidente a1 for menor a data do acidente a2 (ordem cronológica) e false caso contrário.
 */
bool compararAcidentesData(Acidente* a1, Acidente* a2);

/**
 * @brief Imprime no ecrã o menu principal
 */
void printMainMenu();

/*
 * @brief Imprime no ecrã o submenu de pesquisa de postos
 */
void printPesquisarPostosMenu();

/*
 * @brief Imprime no ecrã o submenu de informações sobre ocorrências
 */
void printInfoOcorrenciasMenu();

/*
 * @param header - nome do menu para qual este cabeçalho é usado
 * @brief Imprime no ecrã o cabeçalho de um menu
 */
void printHeader(const std::string &header);

/*
 * @brief Lê do utilizador uma data no formato DD-MM-AAAA, lançando um exceção (Erro) caso a data não esteja no formato especificado / erro de input.
 * @return retorna a data lida do utilizador, caso tenha havido sucesso na leitura
 */
std::string lerData();

/**
 * @brief Makes a pause, asking for the user to press the Enter key to continue.
 */
void pause();



#endif /* GENERIC_FUNCTIONS_H_ */
