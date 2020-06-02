//Função para ler o arquivo com112_entrada.txt, onde estão os elementos a serem ordenados
//Jogando esses elementos para um vetor
void fileLeitura(int *V2, int n);

//Registrar os resultados obtidos em Bubble Sort no arquivo com112_relatorio.txt
void fileRelatorio(double tempo, int n_compara, int n_movimento, char metodoNome[100]);

//Registra os elementos desordenados em com112_entrada.txt
void fileEntrada(int *V, int n);

//Registra os elementos depois de terem sidos ordenados no arquivo com112_saida.txt
void fileSaida(int *V2, int n);

//Registra os resultados obtidos em Bubble Sort no arquivo com112_relatorio_crescente.txt
void fileCrescente(double tempo, int n_compara, int n_movimento, char nomeMetodo[]);

//Registra os resultados obtidos nos metodos no arquivo com112_relatorio_decrescente.txt
void fileDecrescente(double tempo, int n_compara, int n_movimento, char nomeMetodo[]);
