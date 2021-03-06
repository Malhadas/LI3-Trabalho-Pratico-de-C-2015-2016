#ifndef GESTAO_H
#define	GESTAO_H
#include "../modulos_auxiliares/apresentacao/apresentacao.h"
#include "../modulos_auxiliares/capsula/capsula.h"
#include "../modulos_auxiliares/avl/avl.h" /*http://adtinfo.org/index.html*/
#include "../../tipos/tipos.h"

/*
 * Gestão de filial: módulo de dados que, a partir dos ficheiros lidos, conterá as
 * estruturas de dados adequadas à representação dos relacionamentos,
 * fundamentais para a aplicação, entre produtos e clientes, ou seja, para cada
 * produto, saber quais os clientes que o compraram, quantas unidades cada um
 * comprou, em que mês e em que filial.
 * Para a estruturação optimizada dos dados deste módulo de dados será crucial
 * analisar as queries que a aplicação deverá implementar, tendo sempre em
 * atenção que pretendemos ter o histórico de vendas organizado por filiais para
 * uma melhor análise, não esquecendo que existem 3 filiais nesta cadeia. 
 */

#define N_FILIAIS 3 /*Número máximo de filiais*/
#define N_REGIMES 2 /*Número máximo de regimes*/
#define N_MESES  12 /* Número máximo de meses 
		     * pode ser aumentado caso se queira guardar dados ao longo de vários anos
		     * pode ser diminuído para um espaço de tempo mais pequeno
                     */

typedef struct gestao *Gestao; /*Tipo opaco de gestao*/


/*Modulo***********************************************************************/

/*Inicializar a gestao*/
Gestao init_gestao            ();

/*Inserir compra na gestão*/
Gestao inserir_compra_gestao  (Gestao g, CLIENTE cl, PRODUTO pr, int mes, int tipo, int filial, int quant, double preco);

/*Inserir cliente na gestão, o cliente é inserido com os seus valores inicializados a zero*/
Gestao inserir_cliente_gestao (Gestao g, CLIENTE cod);

/*Inserir produto na gestao, o produto é inserido com os seus valores inicializados a zero*/
Gestao inserir_produto_gestao (Gestao g, PRODUTO cod);

/*Libertar espaço alocado para a gestão*/
void   libertar_gestao        (Gestao g);

/*Obter número de produtos e clientes presente na gestão*/
int    num_elementos_gestao   (Gestao g);

/******************************************************************************/

/*Queries**********************************************************************/

/*Obter uma apresentação dos N produtos em que o cliente argumento gastou mais dinheiro*/ 
Apresentacao top_cliente               (Gestao g, CLIENTE cod, int N);

/* Obter uma apresentacao dos produtos que o cliente argumento comprou no mês argumento
 * por ordem descendente de quantidade.*/
Apresentacao top_mes_descendente       (Gestao g, CLIENTE cod, int mes);

/*Obter uma apresentação dos clientes que compraram o produto argumento*/
Apresentacao clientes_produto          (Gestao g, PRODUTO cod);

/* Devolve uma cápsula com as quantidades compradas em cada mês, para cada filial
 * pelo cliente argumeento. A capsula contêm 12*N_FILIAIS inteiros sendo os primeiros
 * 12 a quantidade em cada mês (do 1 ao 12) na filial 1, os segundos 12 o mesmo na
 * filial 2 e os terceiros o mesmo na filial 3. 
 * Consultar a API da capsula para entender como aceder a estes valores.*/
Capsula      dados_cliente             (Gestao g, CLIENTE cod);

/*Obter uma apresentacao dos N produtos que venderam mais em quantidade.*/
Apresentacao top_produtos              (Gestao g, int N);

/*Obter uma apresentacao dos clientes que compraram em todas as filiais*/
Apresentacao compradores_todas_filiais (Gestao g);

/*Obter o número de clientes na gestao que são compradores*/
int          num_clientes_gestao       (Gestao g);

/******************************************************************************/

/*Apresentacao*****************************************************************/
/*Funções para utilização do modulo importado: apresentacao.*/

/* Obter o elemento da apresentação que está na pagina e na linha argumentos.
 * Devolve NULL se esse elemento não esxistir.*/
char*  apresenta_elemento_gestao   (Apresentacao a, int pagina, int linha);

/*Obter a página argumento da apresentação. Devolve NULL se essa página não existir*/
char** get_pagina_gesta           (Apresentacao a, int pagina);

/*Obter o número de elementos por página da apresentacao*/
int    get_elem_por_pagina_gestao  (Apresentacao a);

/*Obter o numero de paginas da apresentacao*/
int    get_paginas_gestao          (Apresentacao a);

/*Obter o número de elementos na apresentacao*/
int    get_elem_total_gestao       (Apresentacao a);

/*Eliminar espaço alocado para a apresentacao*/
void   elimina_apresentacao_gestao (Apresentacao a);

/******************************************************************************/

/*Capsula**********************************************************************/
/*Funcoes para utilizacao do modulo importado: capsula*/

/*Obter o inteiro do indice argumento presente na capsula*/
int     get_int_capsula_gestao    (Capsula c, int indice);

/*Obter o double do indice argumento presente na capsula*/
double  get_double_capsula_gestao (Capsula c, int indice);

/*Libertar espaço alocado para a capsula*/
void    libertar_capsula_gestao   (Capsula c);

/*obter o tipo da última inserção na cápsula*/
int     get_tipo_capsula_gestao   (Capsula c);

/*obter a quantidade de inteiros presente na capsula*/
int     get_q1_capsula_gestao     (Capsula c);

/*obter a quantidade de doubles presente na capsula*/
int     get_q2_capsula_gestao     (Capsula c);

/******************************************************************************/

#endif

