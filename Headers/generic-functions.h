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
 * @brief Imprime no ecrã um menu de boas vindas
 */
void printWelcomeMenu();

/**
 * @brief Imprime no ecrã o menu principal
 */
void printMainMenu();

/**
 * @brief Imprime no ecrã o submenu de pesquisa de postos
 */
void printPesquisarPostosMenu();

/**
 * @brief Imprime no ecrã o submenu de informações sobre ocorrências
 */
void printInfoOcorrenciasMenu();

/**
 * @param header - Nome do menu para qual este cabeçalho é usado
 * @brief Imprime no ecrã o cabeçalho de um menu
 */
void printHeader(const std::string &header);

/**
 * @brief Lê do utilizador uma data no formato DD-MM-AAAA, lançando um exceção (Erro) caso a data não esteja no formato especificado / erro de input.
 * @return Retorna a data lida do utilizador, caso tenha havido sucesso na leitura
 */
std::string lerData();

/**
 * @brief Lê do utilizador uma localidade, lançando um exceção (Erro) caso o local não seja encontrado na 'base de dados' da protecao civil
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar
 * @return Retorna o local lido do utilizador, caso tenha havido sucesso na leitura
 */
std::string obterLocalidade(ProtecaoCivil &protecaoCivil);

/**
 * @brief Obtem o tipo de acidente que o utilizador quer declarar. Pode ser 1 (Assalto), 2 (Acidente de Viação), 3 (Incêndio Florestal) ou 4 (Incêndio Doméstico), lançando uma exceção (Erro) caso o input seja invalido
 * @return Retorna o tipo de Acidente que o utilizador escolheu declarar ( [1,4] )
 */
int obterTipoAcidente();

/**
 * @brief Lê do utilizador o tipo de casa onde decorreu um assalto, lançando uma exceção (Erro) se for diferente de "Particular" ou "Comercial"
 * @return Retorna "Particular" ou "Comercial", caso a leitura seja bem sucedida
 */
std::string assaltoObterTipoCasa();

/**
 * @brief Lê do utilizador se houve feridos num assalto, lançando uma exceção (Erro) se a resposta for diferente de "Sim" ou "Nao"
 * @return Retorna true ou false, caso a leitura seja bem sucedida
 */
bool assaltoObterExistenciaFeridos();

/**
 * @brief Lê do utilizador o tipo de estrada onde decorreu um acidente de viação, lançando uma exceção (Erro) se for diferente de "Estrada Nacional" ou "Auto-Estrada"
 * @return Retorna "Estrada Nacional" ou "Auto-Estrada", caso a leitura seja bem sucedida
 */
std::string viacaoObterTipoEstrada();

/**
 * @brief Lê do utilizador o número de feridos envolvidos num acidente de viação, lançando um exceção (Erro) se o input for invalido/absurdo (nulo ou inferior a 0)
 * @return Retorna o número de feridos envolvidos num acidente de viação, se a leitura for bem sucedida
 */
unsigned int viacaoObterNumFeridos();

/**
 * @brief Lê do utilizador o número de veículos envolvidos num acidente de viação, lançando um exceção (Erro) se o input for inválido/absurdo (nulo ou inferior a 0)
 * @return Retorna o número de veículos envolvidos num acidente de viação, se a leitura for bem sucedida
 */
unsigned int viacaoObterNumVeiculos();

/**
 * @brief Lê do utilizador a área ocupada pelas chamas num incêndio florestal, lançando uma exceção (Erro) se o input for inválido/absurdo (nulo ou inferior a 0)
 * @return Retorna a área ocupada pelas chamas num incêndio florestal, se a leitura for bem sucedida
 */
unsigned int incendioObterAreaChamas();

/**
 * @brief Lê do utilizador o tipo de casa onde decorreu um incêndio, lançando uma exceção (Erro) se for diferente de "Apartamento" ou "Moradia"
 * @return Retorna "Apartamento" ou "Moradia", caso a leitura seja bem sucedida
 */
std::string incendioObterTipoCasa();

/**
 * @brief Lê do utilizador um numero de ocorrencia referente a um acidente, lançando uma exceção (Erro) se o input for inválido/absurdo ( menor ou igual a 0 )
 * @return Retorna o numero de ocorrencia que o utilizador introduziu, caso a leitura seja bem sucedida
 */
unsigned int obterNumOcorrencia();

/**
 * @brief Lê do utilizador o Número de Identificação de um Posto, lançando uma exceção (Erro) se o input for inválido/absurdo (nulo ou inferior a 0)
 * @return Retorna um número de identificação de um posto, se a leitura for bem sucedida
 */
unsigned int obterIdPosto();

/**
 * @brief Lê do utilizador o Número de Identificação de um Acidente, lançando uma exceção (Erro) se o input for inválido/absurdo (nulo ou inferior a 0)
 * @return Retorna um número de identificação de um acidente, se a leitura for bem sucedida
 */
unsigned int obterIdAcidente();

/**
 * @brief Lê do utilizador um ficheiro de postos
 * @return Retorna o ficheiro de postos lido do utilizador
 */
std::string lerFicheiroPostos();

/**
 * @brief Lê do utilizador um ficheiro de acidentes
 * @return Retorna o ficheiro de acidentes lido do utilizador
 */
std::string lerFicheiroAcidentes();

/**
 * @brief Lê do utilizador um ficheiro de locais
 * @return Retorna o ficheiro de locais lido do utilizador
 */
std::string lerFicheiroLocais();

/**
 * @brief Faz uma pausa, pedindo ao utilizador que prima enter para continuar.
 */
void pause();



#endif /* GENERIC_FUNCTIONS_H_ */
