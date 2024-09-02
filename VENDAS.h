
void vendas_compras_menu_tela()
{
    do
    {
        if(*ptr_total_carrinho == 0) // se o total do carrinho for 0, zera também o total temporário, para assim evitar lixo de memória
        {
            for(int i = 0; i < contador_produtos; i++)
            {
                produtos_carrinho[i].total_temporario = 0;
            }
        }

        system ("cls");
        printf ("\n\n\t======================================================================================================\n"); //menu de itens de materiais de limpeza
        printf ("\t|                                                                                                    |\n");
        printf ("\t|                                           2.1 Nova Venda                                           |\n");
        printf ("\t|                                                                                                    |\n");
        printf ("\t|                                                                                                    |\n");
        printf ("\t|    Item (código) |     Nome do Item      |       Categoria       |  Valor (Unidade)  |  Estoque    |\n");
        printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
        lista_de_produtos_func();
        printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
        printf ("\t|                                                                                                    |\n");
        printf ("\t|          8 Voltar ao Menu Principal                                                                |\n");
        printf ("\t|                                                                                                    |\n");
        printf ("\t======================================================================================================\n");
        if(*ptr_total_carrinho >= 1) //se tiver algum item no carrinho, então ele aparecerá
        {
            printf ("\t|                                                                                                    |\n");
            printf ("\t|                                        Carrinho de compras                                         |\n");
            printf ("\t|                                                                                                    |\n");
            printf ("\t|                                                                                                    |\n");
            printf ("\t|      Quantidade  |     Nome do Item      |       Categoria       |  Valor (Unidade)  |   TOTAL     |\n");
            printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
            carrinho_func();   //função de carrinho, presente no arquivo CALCULOS
            printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
            printf ("\t|                                                                                 TOTAL:    %.2f      \n", *ptr_total_carrinho);
            printf ("\t|                                                                                                    |\n");
            printf ("\t======================================================================================================\n");
        }
        printf ("\t..::: Digite o código de um produto:  ");
        fflush(stdin);
        fgets(codigo_de_produtos, 5, stdin);

        for(int i = 0; i<contador_produtos; i++)
        {
            if(strcmp(codigo_de_produtos, produtos_salvos[i].codigo) == 0)  //inicia um for de todos os produtos, se o produto tiver o código igual ao digitado, então ele aparecerá e os outros não
            {
                printf ("\n\n\t========================================\n");
                printf ("\t|                                      |\n");
                printf ("\t|  Produto selecionado:%11s     |\n", produtos_salvos[i].descricao);
                printf ("\t|                                      |\n");
                printf ("\t========================================\n");
                printf ("\t..::: Digite a quantidade: ");
                scanf ("%i", ptr_temp_quant);
                getchar();

                if( *ptr_temp_quant > (produtos_salvos[i].estoque_atual - produtos_salvos[i].estoque_minimo) )  //se a quantidade requerida for maior que o estoque ou maior que o estoque minimo, então a compra não acontecerá
                {
                    int op;
                    tela_nao_ha_estoque();
                    scanf("%i", &op);
                    if(op==2)
                        break;
                }

                printf ("\n\n\t============================\n");
                printf ("\t|                          |\n");
                printf ("\t|     Confirmar venda?     |\n");
                printf ("\t|                          |\n");
                printf ("\t|    1 - Sim    2 - Não    |\n");
                printf ("\t|                          |\n");
                printf ("\t============================\n\n\n");
                printf ("\t..::: Digite a resposta:  ");
                scanf ("%i", &operador[13]);
                getchar();

                if(operador[13]==1) //se a venda for confirmada, isso acontece
                {
                    if(strcmp (produtos_carrinho[i].codigo, produtos_salvos[i].codigo) != 0)  //se o produto escolhido não foi comprado ainda, isso acontece
                    {
                        produtos_salvos[i].quantidade = 0; //a quantidade está bugada, por isso é necessário zerar.
                        produtos_carrinho[i] = produtos_salvos[i];  //o produto escolhido é salvo no carrinho
                    }

                    produtos_carrinho[i].quantidade += *ptr_temp_quant;  //a quantidade escolhida também é salva

                    produtos_salvos[i].estoque_atual -= *ptr_temp_quant;  //o estoque é diminuido

                    produtos_carrinho[i].total = produtos_carrinho[i].quantidade * produtos_carrinho[i].preco_de_venda;  //o total é calculado

                    produtos_carrinho[i].total_temporario = produtos_carrinho[i].total; //o total temporário recebe o total

                    *ptr_total_carrinho = 0;  //o total do carrinho é zerado para evitar número indevidos

                    for(int i = 0; i < contador_produtos; i++)
                    {
                        *ptr_total_carrinho += produtos_carrinho[i].total_temporario; //e o total é salvo
                    }

                }
            }
        }
    }
    while(codigo_de_produtos[0] != '8');
}



void cancelar_compra_menu_tela()
{
    do
    {
        system("cls");
        printf ("\n\n\t================================================\n");
        printf ("\t|                                              |\n");
        printf ("\t|               2.3 Cancelamento               |\n");
        printf ("\t|                                              |\n");
        printf ("\t|          Deseja cancelar a compra?           |\n");
        printf ("\t|                                              |\n");
        printf ("\t|          1- Sim             2- Não           |\n");
        printf ("\t|                                              |\n");
        printf ("\t================================================\n\n\n");
        printf ("\t..::: Escolha uma das opções:  ");
        scanf("%i", &operador[15]);
        getchar();

        if(operador[15] == 1)
        {
            for(int i = 0; i<contador_produtos; i++)  //cancelamento de compra, que zera o carrinho e retorna o estoque antigo
            {
                produtos_salvos[i].estoque_atual += produtos_carrinho[i].quantidade;
                produtos_carrinho[i] = esvaziar_carrinho;
            }
            *ptr_total_carrinho = 0; // o total do carrinho é zerado
            printfcompracancelada ();  //e a tela de cancelamento aparece
        }
        break;
    }
    while(operador[15] != 2);
}



void zerar_vendidos() //zera o carrinho para não bugar o arquivamento de vendas
{
    for(int i = 0; i < n; i++)
    {
        strcpy(produtos_carrinho[i].codigo, "n");
        strcpy(produtos_carrinho[i].descricao,"n");
        produtos_carrinho[i].cod_cliente = 0;
        produtos_carrinho[i].quantidade = 0;
        produtos_carrinho[i].preco_de_venda = 0;
        strcpy(produtos_carrinho[i].categoria,"n");
        produtos_carrinho[i].hora = 0;
        produtos_carrinho[i].minuto = 0;
        produtos_carrinho[i].segundo = 0;
        produtos_carrinho[i].ano = 0;
        produtos_carrinho[i].mes = 0;
        produtos_carrinho[i].dia = 0;
    }
}




void salvar_contador_de_vendas()
{
    FILE *arq = fopen ("vendas.txt", "w");//salva as vendas em arquivo .txt
    if(arq)
    {
        for(int ii = 0; ii<contador_vendas; ii++)
        {
            fprintf(arq, "%i\n", contador_vendas);
            for(int i = 0; i < contador_produtos; i++)
            {
                fprintf(arq, "%i\n", produtos_vendidos[ii][i].cod_venda);
                fprintf(arq, "%i\n", produtos_vendidos[ii][i].cod_cliente);
                fprintf(arq, "%i\n", produtos_vendidos[ii][i].tipo_de_pagamento);
                fprintf(arq, "%s\n", produtos_vendidos[ii][i].descricao);
                fprintf(arq, "%i\n", produtos_vendidos[ii][i].quantidade);
                fprintf(arq, "%.2f\n", produtos_vendidos[ii][i].preco_de_venda);
                fprintf(arq, "%s\n", produtos_vendidos[ii][i].categoria);
                fprintf(arq, "%02i\n", produtos_vendidos[ii][i].hora);
                fprintf(arq, "%02i\n", produtos_vendidos[ii][i].minuto);
                fprintf(arq, "%02i\n", produtos_vendidos[ii][i].segundo);
                fprintf(arq, "%02i\n", produtos_vendidos[ii][i].ano);
                fprintf(arq, "%02i\n", produtos_vendidos[ii][i].mes);
                fprintf(arq, "%02i\n", produtos_vendidos[ii][i].dia);
                fprintf(arq, "%.2f\n", produtos_vendidos[ii][i].total);
            }
        }
        fclose(arq);
    }
    else
    {
        printf("\n\tErro ao salvar vendas! (ERRO 4)\n");
        system("pause");
    }
}


void ler_contador_de_vendas()
{
    setlocale(LC_ALL, "Portuguese");
    FILE *arq = fopen ("vendas.txt", "r"); //le o arquivo .txt de vendas
    if(arq)
    {
        for(int ii = 0; ii <= contador_vendas; ii++)
        {
            fscanf(arq, "%i\n", &contador_vendas);
            for(int i = 0; i < contador_produtos; i++)
            {
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].cod_venda);
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].cod_cliente);
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].tipo_de_pagamento);
                fgets(produtos_vendidos[ii][i].descricao,12,arq);
                produtos_vendidos[ii][i].descricao[strcspn(produtos_vendidos[ii][i].descricao, "\n")] = 0; //linha de código para tirar o ENTER (\n) depois da string
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].quantidade);
                fscanf(arq, "%f\n", &produtos_vendidos[ii][i].preco_de_venda);
                fgets(produtos_vendidos[ii][i].categoria, 12, arq);
                produtos_vendidos[ii][i].categoria[strcspn(produtos_vendidos[ii][i].categoria, "\n")] = 0; //linha de código para tirar o ENTER (\n) depois da string
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].hora);
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].minuto);
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].segundo);
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].ano);
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].mes);
                fscanf(arq, "%i\n", &produtos_vendidos[ii][i].dia);
                fscanf(arq, "%f\n", &produtos_vendidos[ii][i].total);
            }
        }
        fclose(arq);
    }
}



void historico_de_vendas() //mostra vendas antigas, por um sistema catalogado pela data e horário
{
    int op, op2, op3, op4;
    system("cls");
    printf ("\n\n\t=========================================\n");
    printf ("\t|                                       |\n");
    printf ("\t|          Histórico de vendas          |\n");
    printf ("\t|                                       |\n");
    printf ("\t=========================================\n\n");
    printf ("\t..::: Selecione um ano abaixo :::..\n");

    printf("\n\n\t..::: %04i", produtos_vendidos[0][0].ano);

    for(int ii = 0; ii<contador_vendas; ii++)
    {
        for(int i = 0; i<contador_produtos; i++)
        {
            if(produtos_vendidos[ii][i].quantidade != 0)
            {
                if(produtos_vendidos[ii][i].ano == produtos_vendidos[0][0].ano)
                {
                    break;
                }
                else
                {
                    printf("\n\n\t..::: %04i", produtos_vendidos[ii][i].ano);
                }
            }
        }
    }
    printf("\n\n\n\t..::: Digite sua resposta:  ");
    scanf("%i", &op);

    system("cls");
    printf ("\n\n\t..::: Selecione um mês abaixo :::..\n");
    for(int ii = 0; ii < contador_vendas; ii++)
    {
        for(int i = 0; i < contador_produtos; i++)
        {
            if(op == produtos_vendidos[ii][i].ano)
            {
                if(produtos_vendidos[ii][i].mes != produtos_vendidos[ii][i-1].mes)
                    if(produtos_vendidos[ii][i].mes != produtos_vendidos[ii-1][i].mes)
                        printf("\n\n\t..::: %02i", produtos_vendidos[ii][i].mes);
            }
        }
    }
    printf("\n\n\n\t..::: Digite sua resposta:  ");
    scanf("%i", &op2);

    system("cls");
    printf ("\n\n\t..::: Selecione um dia abaixo :::..\n");

    for(int ii = 0; ii < contador_vendas; ii++)
    {
        for(int i = 0; i < contador_produtos; i++)
        {
            if(op == produtos_vendidos[ii][i].ano && op2 == produtos_vendidos[ii][i].mes)
            {
                if(produtos_vendidos[ii][i].dia != produtos_vendidos[ii][i-1].dia)
                    if(produtos_vendidos[ii][i].dia != produtos_vendidos[ii-1][i].dia)
                        if(produtos_vendidos[ii][i].dia != produtos_vendidos[ii-1][i-1].dia)
                            printf("\n\n\t..::: %02i", produtos_vendidos[ii][i].dia);
            }
        }
    }
    printf("\n\n\n\t..::: Digite sua resposta:  ");
    scanf("%i", &op3);

    system("cls");
    printf ("\n\n\t..::: Vendas efetuadas na data selecionada :::..\n");
    for(int ii = 0; ii < contador_vendas; ii++)
    {
        for(int i = 0; i < contador_produtos; i++)
        {
            if(op == produtos_vendidos[ii][i].ano && op2 == produtos_vendidos[ii][i].mes && op3 == produtos_vendidos[ii][i].dia)
            {
                if(produtos_vendidos[ii][i].segundo != produtos_vendidos[ii][i-1].segundo)
                    printf("\n\n\t..::: [%i] Horário: %02i:%02i:%02i | Valor:  R$ %.2f", produtos_vendidos[ii][i].cod_venda, produtos_vendidos[ii][i].hora, produtos_vendidos[ii][i].minuto, produtos_vendidos[ii][i].segundo, produtos_vendidos[ii][i].total);
            }
        }
    }
    printf("\n\n\n\t..::: Selecione uma venda:  ");
    scanf("%i", &op4);

    system("cls");
    printf ("\n\n\t..::: Venda selecionada :::..\n");
    for(int ii = 0; ii < contador_vendas; ii++)
    {
        if(op4 == produtos_vendidos[ii][0].cod_venda)
        {
            printf("\n\n\t..::: Horário: %02i:%02i:%02i", produtos_vendidos[ii][0].hora, produtos_vendidos[ii][0].minuto, produtos_vendidos[ii][0].segundo);

            for(int i = 0; i <contador_clientes; i++)
            {
                if(produtos_vendidos[ii][0].cod_cliente == clientes_salvos[i].id)
                {
                    clientes_salvos[i].nome_completo[strcspn(clientes_salvos[i].nome_completo, "\n")] = 0;  //tira o ENTER do nome do cliente, para não bugar o menu
                    printf("\n\n\t..::: Cliente: [%i] %s", clientes_salvos[i].id, clientes_salvos[i].nome_completo);
                }
            }

            for(int i = 0; i < contador_produtos; i++)
            {
                if(produtos_vendidos[ii][i].preco_de_venda != 0)
                {
                    printf("\n\n\t..::: %s (Quant: %i, Valor: R$%.2f)", produtos_vendidos[ii][i].descricao, produtos_vendidos[ii][i].quantidade, produtos_vendidos[ii][i].preco_de_venda);
                }
            }

            if(produtos_vendidos[ii][0].tipo_de_pagamento == 1)
            {
                printf("\n\n\t..::: Tipo de Pagamento: Dinheiro");
            }

            if(produtos_vendidos[ii][0].tipo_de_pagamento == 2)
            {
                printf("\n\n\t..::: Tipo de Pagamento: Cartão");
            }

            if(produtos_vendidos[ii][0].tipo_de_pagamento == 3)
            {
                printf("\n\n\t..::: Tipo de Pagamento: Dinheiro + Cartão");
            }

            printf("\n\n\t..::: Total: R$%.2f\n\n\n\t", produtos_vendidos[ii][0].total);
        }
    }
    system("pause");
}



