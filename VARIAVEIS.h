#define n 500

    typedef struct  //struct que possuí dados de dinheiros (dinheiro cartão sangria etc)
    {
        float abertura_de_caixa;
        float dinheiro;
        float dinheiro_para_sangria;
        float dinheiro_pago;
        float dinheiro_cartao_restante;
        float cartao_pago;
        float cartao;
        float sangria;
        float troco;
        float TOTAL;
        float desconto;
    } d_dinheiros; //( dados_dinheiros )

    typedef struct  //struct que possuí os dados de produtos (nome, código, preços, etc)
    {
        char codigo[5];
        char descricao[12];
        float preco_de_compra;
        int margem_de_lucro;
        float preco_de_venda;
        int estoque_atual;
        int estoque_minimo;
        char categoria[12];
        int quantidade;
        float total;
        float total_temporario;
        int hora;
        int minuto;
        int segundo;
        int dia;
        int mes;
        int ano;
        int cod_venda;
        int cod_cliente;
        int tipo_de_pagamento;
    } d_produtos;

    typedef struct  //struct que possuí dados dos clientes
    {
        int id;
        char nome_completo[200];
        char nome_social[50];
        char cpf[15];
        char rua[200];
        int numero_da_casa;
        char bairro[200];
        long long int numero_para_contato;
        char codigoCliente[5];
    } d_clientes;

    d_produtos *produtos_salvos;    //criação de ponteiros da struct de produtos, alocada dinamicamente no arquivo ARQUIVOS
    d_produtos *produtos_temp;

    d_clientes *clientes_salvos;   //criação de ponteiros da struct de produtos, alocada dinamicamente no arquivo ARQUIVOS
    d_clientes *clientes_temp;

    // os produtos_salvos serão onde todos os produtos utilizados durante o código ficarão salvos, sendo passados para arquivos depois (mesma coisa para os clientes_salvos)
    // os produtos_carregados é uma struct utilizada somente durante a leitura de arquivo, passando seus dados para os produtos_salvos (mesma coisa pra os clientes_carregados)

    //  (os ponteiros produtos_salvos e clientes_salvos, são ponteiros de vetores de struct alocados dinamicamente dentro do arquivo ARQUIVOS)

    d_dinheiros dinheiros;
    d_dinheiros *ptr_dinheiros = &dinheiros; //ponteiro simples de uma struct

    float desconto;

    // a struct d_dinheiros é utilizada para armazenar todos os dados entrados que referem a um valor em dinheiro, sendo ele para a abertura de caixa, troco, e todo o resto

    d_produtos produtos_carrinho[n]; //vetor de struct, armazena os produtos em carrinho
    d_produtos produtos_vendidos[n][n]; //vetor de struct, armazena os produtos vendidos
    d_produtos esvaziar_carrinho;    //struct de d_produtos vazia, serve para zerar os produtos do carrinho

    int quantidade_total_vendida;   //variável comum, serve para armazenar a quantidade total vendida e ser mostrada mais tarde em relatórios
    int caixa_fechado = 1;              //serve para o programa saber se o caixa ta fechado ou n
    int quantidade_vendas_na_sessao = 0;

    int contador_produtos = 0, contador_clientes = 0;  //contadores de produtos e clientes, ditam grande parte do cadastro e salvamento dos dados em arquivos, alem do cadastro, contam a quantidade de itens está dentro do programa
    int contador_vendas = 0;

    float total_carrinho = 0;
    float *ptr_total_carrinho = &total_carrinho;  //ponteiro simples, mostra o valor total a ser pago dentro do carrinho

    int temp_quant;
    int *ptr_temp_quant = &temp_quant;   //quantidade temporária


    char codigo_de_produtos[10];

    int operador[17];   //vetor, opera opções simples dentro do menu

    int escolha_categoria;   //variável comum, presente na escolha de categoria

    int tipo_de_pagamento;
    //1 = dinheiro
    //2 = cartão
    //3 = cartão + dinheiro

    time_t tempo;
