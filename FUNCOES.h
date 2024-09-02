

void compra_finalizada_func() //função de compra finalizada, utilizada sempre que a compra finaliza
{
    time(&tempo); //pega o tempo atual e armanazena na variavel tempo
    struct tm *tempo0 = localtime(&tempo); //converte o tempo em uma struct tm contendo informações detalhadas data e hora
    tempo0->tm_year = tempo0->tm_year + 1900; //ajusta o ano para o formato correto, a partir de 1900
    tempo0->tm_mon = tempo0->tm_mon +1;  //ajusta o mês (0-11) para o formato correto (1-12)

    quantidade_total_vendida = 0; //a quantidade total vendida recebe o valor 0, para depois receber a quantidade vendida TOTAL

    for(int i = 0; i<contador_produtos; i++)
    {
        if(produtos_carrinho[i].categoria) //checagem de categoria, se o produto EXISTE, não é um lixo de memória da struct
        {
            //os produtos do carrinho vão para os produtos vendidos, assim salvando todos os que foram vendidos dentro de uma nova struct
            produtos_vendidos[contador_vendas][i].cod_venda = contador_vendas + 1;
            produtos_vendidos[contador_vendas][i].cod_cliente = produtos_carrinho[i].cod_cliente;
            produtos_vendidos[contador_vendas][i].tipo_de_pagamento = tipo_de_pagamento;
            strcpy(produtos_vendidos[contador_vendas][i].descricao, produtos_carrinho[i].descricao);
            produtos_vendidos[contador_vendas][i].quantidade += produtos_carrinho[i].quantidade; //salva a quantidade total vendida de cada produto
            produtos_vendidos[contador_vendas][i].preco_de_venda = produtos_carrinho[i].preco_de_venda;
            strcpy(produtos_vendidos[contador_vendas][i].categoria, produtos_carrinho[i].categoria);
            produtos_carrinho[i] = esvaziar_carrinho; //após salvar os arquivos vendidos, o carrinho é esvaziado, sendo igualado a uma struct zerada
            produtos_vendidos[contador_vendas][i].hora = tempo0->tm_hour;
            produtos_vendidos[contador_vendas][i].minuto = tempo0->tm_min;
            produtos_vendidos[contador_vendas][i].segundo = tempo0->tm_sec;
            produtos_vendidos[contador_vendas][i].ano = tempo0->tm_year;
            produtos_vendidos[contador_vendas][i].mes = tempo0->tm_mon;
            produtos_vendidos[contador_vendas][i].dia = tempo0->tm_mday;
            produtos_vendidos[contador_vendas][i].total = *ptr_total_carrinho;
        }

        if(produtos_vendidos[contador_vendas][i].categoria) //checagem de categoria, se for um desses numeros, então o produto EXISTE, e não é um lixo de memória da struct
        {
            quantidade_total_vendida += produtos_vendidos[contador_vendas][i].quantidade; //salva a quantidade total vendida de todos os produtos
        }
    }
    contador_vendas++; //aumenta o contador de vendas, necessário para controlar o sistema de arquivo de vendas
    salvar_contador_de_vendas(); //salva as vendas em arquivo .txt
    produtos_salvar_em_arquivo(); //salva os estoques no arquivo
    zerar_vendidos(); //zera o carrinho, para não bugar o arquivo
    quantidade_vendas_na_sessao++; //contagem de vendas na sessão
    ptr_dinheiros->TOTAL += *ptr_total_carrinho; //o dinheiro total que entrou com as vendas é armazenado
    *ptr_total_carrinho = 0; //o total no carrinho é zerado
}


void carrinho_func() //função de menu do carrinho, mostra todos os produtos do carrinho, e utiliza diversas checagens para saber a quantidade de digitos que cada valor dentro do menu tem
{
    for(int i = 0; i<contador_produtos; i++)
    {
        if(produtos_carrinho[i].total>0) //o carrinho só aparecerá caso tiver algum item dentro do carrinho
        {
            if(produtos_carrinho[i].preco_de_venda<10)
            {
                if(produtos_carrinho[i].total<10)
                {
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f        |    %.2f     |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao, produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }              //se você perceber, a quantidade de espaços difere em cada uma das categorias de valor, isso acontece por causa da quantidade de digitos de cada valor
                if(produtos_carrinho[i].total>9 && produtos_carrinho[i].total<100)
                {
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f        |    %.2f    |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao,  produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }
                if(produtos_carrinho[i].total>99)
                {
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f        |    %.2f   |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao, produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }
            }
            if(produtos_carrinho[i].preco_de_venda>9 && produtos_carrinho[i].preco_de_venda<100)
            {
                if(produtos_carrinho[i].total<10)
                {
                    //assim, com essas checagens, o menu do carrinho fica extremamente alinhado e bonito, não tendo que ter espaços não preenchidos e lacunas vazias
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f       |    %.2f     |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao, produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }
                if(produtos_carrinho[i].total>9 && produtos_carrinho[i].total<100)
                {
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f       |    %.2f    |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao, produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }
                if(produtos_carrinho[i].total>99)
                {
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f       |    %.2f   |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao, produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }
            }
            if(produtos_carrinho[i].preco_de_venda>99)
            {
                if(produtos_carrinho[i].total<10)
                {
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f      |    %.2f     |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao, produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }
                if(produtos_carrinho[i].total>9 && produtos_carrinho[i].total<100)
                {
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f      |    %.2f    |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao, produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }
                if(produtos_carrinho[i].total>99)
                {
                    printf ("\t|         (%02i)     |    %11s        |    %11s        |       %.2f      |    %.2f   |\n", produtos_carrinho[i].quantidade, produtos_carrinho[i].descricao, produtos_carrinho[i].categoria, produtos_carrinho[i].preco_de_venda, produtos_carrinho[i].total);
                }
            }
        }
    }
}

void lista_de_produtos_func()
{
    for(int i = 0; i<contador_produtos; i++)
    {
        if(produtos_salvos[i].preco_de_venda<10)
        {
            if(produtos_salvos[i].estoque_atual<10) //contador de digitos de cada número, conta a quantidade de digitos de cada número, para assim ficar com o menu organizado
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f        |     %i       |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }
            if(produtos_salvos[i].estoque_atual>9 && produtos_salvos[i].estoque_atual<100)
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f        |     %i      |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }           //se você perceber, a quantidade de espaços difere em cada uma das categorias de valor, isso acontece por causa da quantidade de digitos de cada valor
            if(produtos_salvos[i].estoque_atual>99)
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f        |     %i     |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }          //assim, com essas checagens, o menu do carrinho fica extremamente alinhado e bonito, não tendo que ter espaços não preenchidos e lacunas vazias
        }
        if(produtos_salvos[i].preco_de_venda>9 && produtos_salvos[i].preco_de_venda<100)
        {
            if(produtos_salvos[i].estoque_atual<10)
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f       |     %i       |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }
            if(produtos_salvos[i].estoque_atual>9 && produtos_salvos[i].estoque_atual<100)
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f       |     %i      |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }
            if(produtos_salvos[i].estoque_atual>99)
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f       |     %i     |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }
        }
        if(produtos_salvos[i].preco_de_venda>99)
        {
            if(produtos_salvos[i].estoque_atual<10)
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f      |     %i       |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }
            if(produtos_salvos[i].estoque_atual>9 && produtos_salvos[i].estoque_atual<100)
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f      |     %i      |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }
            if(produtos_salvos[i].estoque_atual>99)
            {
                printf ("\t|        %4s      |    %11s        |    %11s        |       %.2f      |     %i     |\n", produtos_salvos[i].codigo, produtos_salvos[i].descricao, produtos_salvos[i].categoria, produtos_salvos[i].preco_de_venda, produtos_salvos[i].estoque_atual);
            }
        }
    }
}
