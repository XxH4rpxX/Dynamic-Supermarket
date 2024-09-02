
//arquivo TELA, neste arquivo se encontram todas as telas dos menus, e grande parte das linhas de código que fazer o programa rodar


void tela_abertura_de_caixa() //abertura de caixa, necessário para fazer vendas e fechamentos, mas não necessário para fazer cadastros de checagens de relatórios
{
    system ("cls");
    printf ("\n\n\t=================================================\n");
    printf ("\t|                                               |\n");
    printf ("\t|               Abertura de caixa               |\n");
    printf ("\t|                                               |\n");
    printf ("\t|    Informe o valor que a BERÊ tem no caixa    |\n");
    printf ("\t|                                               |\n");
    printf ("\t=================================================\n");
    printf ("\t..::: Digite um valor:  ");
    scanf  ("%f", &ptr_dinheiros->abertura_de_caixa);
    getchar();

    if(ptr_dinheiros->abertura_de_caixa < 0) //função que não deixa ser posto valores negativos na abertura de caixa
    {
        printf ("\n\n\t=========================\n");
        printf ("\t|                       |\n");
        printf ("\t|    Valor inválido!    |\n");
        printf ("\t|                       |\n");
        printf ("\t=========================\n\n\n");
        system("pause");
        system("cls");

        tela_abertura_de_caixa();
    }
    ptr_dinheiros->dinheiro = ptr_dinheiros->abertura_de_caixa; //o valor é inserido dentro da variável de dinheiro, assim sendo contado todo o dinheiro que possuí dentro do caixa até então
}


void telabemvindo()
{
    printf("\n\n\t======================================================================================\n");
    printf("\t|                                                                                    |\n");
    printf("\t|                                                                                    |\n");
    printf("\t|                              Bem vindo ao sistema da                               |\n");
    printf("\t|                                                                                    |\n");
    printf("\t|                                                                                    |\n");
    printf("\t|            8 888888888o   8 888888888888 8 888888888o.   8 888888888888            |\n");
    printf("\t|            8 8888    `88. 8 8888         8 8888    `88.  8 8888                    |\n");
    printf("\t|            8 8888     `88 8 8888         8 8888     `88  8 8888                    |\n");
    printf("\t|            8 8888     ,88 8 8888         8 8888     ,88  8 8888                    |\n");
    printf("\t|            8 8888.   ,88' 8 888888888888 8 8888.   ,88'  8 888888888888            |\n");
    printf("\t|            8 8888888888   8 8888         8 888888888P'   8 8888                    |\n");
    printf("\t|            8 8888    `88. 8 8888         8 8888`8b       8 8888                    |\n");
    printf("\t|            8 8888      88 8 8888         8 8888 `8b.     8 8888                    |\n");
    printf("\t|            8 8888    ,88' 8 8888         8 8888   `8b.   8 8888                    |\n");
    printf("\t|            8 888888888P   8 888888888888 8 8888     `88. 8 888888888888            |\n");
    printf("\t|                                                                                    |\n");
    printf("\t|                                                                                    |\n");
    printf("\t|                                                                                    |\n");
    printf("\t|                                    VERSÃO 4.5                                      |\n");
    printf("\t|                                by lojashavandevs                                   |\n");
    printf("\t======================================================================================\n\n\n");
    system ("pause");
    system ("cls");

}


void sistema_da_bere_tela()
{
    system ("cls");
    printf ("\n\n\t=========================================\n"); //menu inicial berenice 3.X
    printf ("\t|                                       |\n");
    printf ("\t|            SISTEMA DA BERÊ            |\n");
    printf ("\t|                                       |\n");
    printf ("\t|                                       |\n");
    printf ("\t|          1 Cadastros                  |\n");
    printf ("\t|                                       |\n");
    printf ("\t|          2 Vendas                     |\n");
    printf ("\t|                                       |\n");
    printf ("\t|          3 Abrir caixa                |\n");
    printf ("\t|                                       |\n");
    printf ("\t|          4 Fechar caixa               |\n");
    printf ("\t|                                       |\n");
    printf ("\t|          5 Relatórios                 |\n");
    printf ("\t|                                       |\n");
    printf ("\t|                                       |\n");
    printf ("\t|          6 Sair                       |\n");
    printf ("\t|                                       |\n");
    printf ("\t=========================================\n\n\n");
    printf ("\t..::: Escolha uma das opções:  ");
}


void cadastros_menu_tela()
{

    system ("cls");
    printf ("\n\n\t================================================\n"); //tela de cadastro
    printf ("\t|                                              |\n");
    printf ("\t|                 1  Cadastros                 |\n");
    printf ("\t|                                              |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         1 Cadastro de clientes               |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         2 Cadastro de produtos               |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         3 Alterar dados de produtos          |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         4 Alterar estoque de produtos        |\n");
    printf ("\t|                                              |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         5 Voltar ao menu principal           |\n");
    printf ("\t|                                              |\n");
    printf ("\t================================================\n\n");
    printf ("\t..::: Escolha uma das opções:  ");
}

void busca_tela()
{

    system ("cls");
    printf ("\n\n\t================================================\n"); //tela de cadastro
    printf ("\t|                                              |\n");
    printf ("\t|                 Buscar                       |\n");
    printf ("\t|                                              |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         1 Clientes por codigo                |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         2 Clientes por ordem alfabética      |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         3 Produtos por codigo                |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         4 Produtos por ordem alfabética      |\n");
    printf ("\t|                                              |\n");
    printf ("\t|                                              |\n");
    printf ("\t|         5 Voltar ao menu principal           |\n");
    printf ("\t|                                              |\n");
    printf ("\t================================================\n\n");
    printf ("\t..::: Escolha uma das opções:  ");
}

void vendas_menu_tela()
{
    system ("cls");
    printf ("\n\n\t============================================\n"); //menu de vendas
    printf ("\t|                                          |\n");
    printf ("\t|                 2 Vendas                 |\n");
    printf ("\t|                                          |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        1 Nova venda                      |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        2 Retirada do caixa (Sangria)     |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        3 Cancelar venda                  |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        4 Pagamento                       |\n");
    printf ("\t|                                          |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        5 Voltar ao menu principal        |\n");
    printf ("\t|                                          |\n");
    printf ("\t============================================\n\n\n");
    printf ("\t..::: Escolha uma das opções:  ");
}




void sangria_erro_tela()
{
    system("cls");
    printf ("\n\n\t======================================================\n");
    printf ("\t|                                                    |\n");
    printf ("\t|      É necessário deixar 50 reais para troco!      |\n");
    printf ("\t|                                                    |\n");
    printf ("\t======================================================\n\n\n");
    system("pause");
    system("cls");
}

void sangria_confirmado_tela()
{
    system("cls");
    printf ("\n\n\t============================================\n");
    printf ("\t|                                          |\n");
    printf ("\t|      Dinheiro retirado com sucesso!      |\n");
    printf ("\t|                                          |\n");
    printf ("\t============================================\n\n\n");
    system("pause");
    system("cls");
}

void sangria_menu2_tela()
{
    system("cls");  //menu de sangria (retirada de dinheiro do caixa)
    printf ("\n\n\t================================================\n");
    printf ("\t|                                              |\n");
    printf ("\t|                  2.2 Sangria                 |\n");
    printf ("\t|                                              |\n");
    if(ptr_dinheiros->dinheiro_para_sangria < 10)
    {
        printf ("\t|           Valor disponível: R$%.2f           |\n", ptr_dinheiros->dinheiro_para_sangria);
    }      // IF`s para deixar o menu organizado
    if(ptr_dinheiros->dinheiro_para_sangria > 9 && ptr_dinheiros->dinheiro_para_sangria < 100)
    {
        printf ("\t|           Valor disponível: R$%.2f          |\n", ptr_dinheiros->dinheiro_para_sangria);
    }
    if(ptr_dinheiros->dinheiro_para_sangria > 99)
    {
        printf ("\t|           Valor disponível: R$%.2f         |\n", ptr_dinheiros->dinheiro_para_sangria);
    }
    printf ("\t|                                              |\n");
    printf ("\t|            Quantos deseja retirar?           |\n");
    printf ("\t|                                              |\n");
    printf ("\t|   (É necessário deixar R$50,00 para troco)   |\n");
    printf ("\t|                                              |\n");
    printf ("\t================================================\n\n\n");
    printf ("\t..::: Digite o valor:  ");
    scanf("%f", &ptr_dinheiros->sangria);
    getchar();

    ptr_dinheiros->dinheiro_para_sangria = ptr_dinheiros->dinheiro - ptr_dinheiros->sangria;  //calculos da sangria
    ptr_dinheiros->dinheiro -= ptr_dinheiros->sangria; // tirar o dinheiro total que tem em caixa

    if(ptr_dinheiros->dinheiro < 50) //caso o dinheiro restante for menor que 50, então a sangria é cancelada
    {
        ptr_dinheiros->dinheiro_para_sangria = ptr_dinheiros->dinheiro + ptr_dinheiros->sangria;
        ptr_dinheiros->dinheiro += ptr_dinheiros->sangria;
        sangria_erro_tela();
    }
    else
    {
        sangria_confirmado_tela();
    }
    ptr_dinheiros->sangria = 0; //a variável é zerada para evitar conflitos
}


void sangria_menu_tela()
{
    ptr_dinheiros->dinheiro_para_sangria = ptr_dinheiros->dinheiro - ptr_dinheiros->sangria; //calculo para mostrar o total disponível para sangria
    do
    {
        system("cls");
        printf ("\n\n\t================================================\n");
        printf ("\t|                                              |\n");
        printf ("\t|                  2.2 Sangria                 |\n");
        printf ("\t|                                              |\n");
        if(ptr_dinheiros->dinheiro_para_sangria < 10)
        {
            printf ("\t|            Valor disponível: R$%.2f          |\n", ptr_dinheiros->dinheiro_para_sangria);
        }    //IF`s para deixar o menu organizado
        if(ptr_dinheiros->dinheiro_para_sangria > 9 && ptr_dinheiros->dinheiro_para_sangria < 100)
        {
            printf ("\t|           Valor disponível: R$%.2f          |\n", ptr_dinheiros->dinheiro_para_sangria);
        }
        if(ptr_dinheiros->dinheiro_para_sangria > 99)
        {
            printf ("\t|          Valor disponível: R$%.2f          |\n", ptr_dinheiros->dinheiro_para_sangria);
        }
        printf ("\t|                                              |\n");
        printf ("\t|           Deseja retirar dinheiro?           |\n");
        printf ("\t|                                              |\n");
        printf ("\t|               1- Sim   2- Não                |\n");
        printf ("\t|                                              |\n");
        printf ("\t|   (É necessário deixar R$50,00 para troco)   |\n");
        printf ("\t|                                              |\n");
        printf ("\t================================================\n\n\n");
        printf ("\t..::: Digite a resposta:  ");
        scanf("%i", &operador[14]);
        getchar();

        if(operador[14] == 1) //se a sangria for confirmado, é aberto a tela 2
        {
            sangria_menu2_tela();
        }
        break;
    }
    while(operador[14] != 2);
}



void pagamento_tela()
{
    system("cls");
    printf ("\n\n\t======================================================================================================\n"); //menu de pagamento
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                            2.4 Pagamento                                           |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                         Carrinho de compras                                        |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|      Quantidade  |     Nome do Item      |       Categoria       |  Valor (Unidade)  |   TOTAL     |\n");
    printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
    carrinho_func();   //função de carrinho, presente no arquivo CALCULOS
    printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
    printf ("\t|                                                                                                    |\n");
    if(ptr_dinheiros->desconto > 0)
    {
        printf ("\t|                                                                              Desconto:    %.0f %%    \n", desconto);
        printf ("\t|                                                                                 TOTAL:    %.2f     \n", *ptr_total_carrinho);
    }
    else
    {
        printf ("\t|                                                                                 TOTAL:    %.2f     \n", *ptr_total_carrinho);
    }
    if(produtos_carrinho->cod_cliente)
    {
        printf ("\t|                                                                                                    |\n");
        printf ("\t|                                                                          Cód. cliente:    %i       \n", produtos_carrinho->cod_cliente);
    }
    printf ("\t|                                                                                                    |\n");
    printf ("\t======================================================================================================\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                 1 - Pagamento no dinheiro                                          |\n");
    printf ("\t|                                 2 - Pagamento no cartão                                            |\n");
    printf ("\t|                                 3 - Pagamento no dinheiro + cartão                                 |\n");
    printf ("\t|                                 4 - Dar desconto                                                   |\n");
    printf ("\t|                                 5 - Atribuir a um cliente                                          |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                 6 - Voltar ao Menu Principal                                       |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t======================================================================================================\n\n\n");
    printf ("\t..::: Escolha uma das opções:  ");

}

void confirmado_caixa_fechado()
{
    system("cls");
    printf ("\t==============================================\n");
    printf ("\t|                                            |\n");
    printf ("\t|      O caixa foi fechado com sucesso!      |\n");
    printf ("\t|                                            |\n");
    printf ("\t==============================================\n\n\n");
    system("pause");
    system("cls");
}

void fechamento_de_caixa_menu_tela()
{
    system ("cls");
    printf("\n\n\t================================================================\n"); //fechamento de caixa
    printf("\t|                                                              |\n");
    printf("\t|                    4. Fechamento de caixa                    |\n");
    printf("\t|                                                              |\n");
    printf("\t|                                                              |\n");
    printf("\t|            Quantidade de vendas:         %i                   \n", quantidade_vendas_na_sessao);
    printf("\t|                                                              |\n");
    printf("\t|                     Faturamento:       R$%.2f                 \n", (ptr_dinheiros->TOTAL - ptr_dinheiros->abertura_de_caixa) );
    printf("\t|                                                              |\n");
    printf("\t|      Valor na abertura de caixa:       R$%.2f                 \n", ptr_dinheiros->abertura_de_caixa);
    printf("\t|                                                              |\n");
    printf("\t|            Valor em caixa agora:       R$%.2f                 \n", ptr_dinheiros->dinheiro);
    printf("\t|                                                              |\n");
    printf("\t|            Valor pago em cartão:       R$%.2f                 \n", ptr_dinheiros->cartao);
    printf("\t|                                                              |\n");
    printf("\t|             Valor vendido total:       R$%.2f                 \n", ptr_dinheiros->TOTAL);
    printf("\t|                                                              |\n");
    printf("\t================================================================\n");
    printf("\t|                                                              |\n");
    printf("\t|                    Deseja fechar o caixa?                    |\n");
    printf("\t|                                                              |\n");
    printf("\t|                  1- Sim              2- Não                  |\n");
    printf("\t|                                                              |\n");
    printf("\t================================================================\n\n\n");
    printf ("\t..::: Escolha uma das opções:  ");
    scanf("%i", &caixa_fechado);
    getchar();

}

void relatorios_menu_tela()
{
    system ("cls");
    printf ("\n\n\t============================================\n"); //relatórios
    printf ("\t|                                          |\n");
    printf ("\t|              5. Relatórios               |\n");
    printf ("\t|                                          |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        1 Histórico de Vendas             |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        2 Lista de Clientes               |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        3 Lista de Produtos               |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        4 Busca                           |\n");
    printf ("\t|                                          |\n");
    printf ("\t|                                          |\n");
    printf ("\t|        5 Voltar ao menu principal        |\n");
    printf ("\t|                                          |\n");
    printf ("\t============================================\n\n\n");
    printf ("\t..::: Escolha uma das opções:  ");
}




void dinheiro_tela()
{
    system("cls");
    printf ("\n\n\t===========================================\n");
    printf ("\t|                                         |\n");
    printf ("\t|           Compra no dinheiro!           |\n");
    printf ("\t|                                         |\n");
    printf ("\t|             TOTAL: R$ %.2f               \n", *ptr_total_carrinho);
    printf ("\t|                                         |\n");
    printf ("\t===========================================\n");
    printf ("\t|            Precisa de troco ?           |\n");
    printf ("\t|                 1. Sim                  |\n");
    printf ("\t|                 2. Não                  |\n");
    printf ("\t===========================================\n\n");
    printf ("\t..::: Digite sua resposta:  ");
}

void dinheiro_pago_tela()
{
    system("cls");
    printf ("\n\n\t================================================\n");
    printf ("\t|                                              |\n");
    printf ("\t|      Informe o valor do dinheiro pago        |\n");
    printf ("\t|                                              |\n");
    printf ("\t================================================\n");
    printf ("\t..::: Digite o valor:  ");
}

void troco_tela()
{
    system("cls");
    printf ("\n\n\t===========================================\n");
    printf ("\t|                                         |\n");
    printf ("\t|        O valor de troco é: R$%.2f        \n", ptr_dinheiros->troco);
    printf ("\t|                                         |\n");
    printf ("\t===========================================\n\n\n\t");
    system("pause");
}

void pagamento_cartao_tela()
{
    system("cls");
    printf ("\n\n\t====================================================\n");
    printf ("\t|                                                  |\n");
    printf ("\t|              Pagamento no cartão!                |\n");
    printf ("\t|                                                  |\n");
    printf ("\t|                TOTAL: R$ %.2f                    \n", *ptr_total_carrinho);
    printf ("\t|                                                  |\n");
    printf ("\t====================================================\n");
    printf ("\t|              Compra bem sucedida?                |\n");
    printf ("\t|                    1. Sim                        |\n");
    printf ("\t|                    2. Não                        |\n");
    printf ("\t====================================================\n\n");
    printf ("\t..::: Digite sua resposta:  ");
}

void pagamento_cartao_e_dinheiro_tela()
{
    system("cls");
    printf ("\n\n\t=================================================\n");
    printf ("\t|                                               |\n");
    printf ("\t|        Pagamento no cartão + dinheiro         |\n");
    printf ("\t|                                               |\n");
    printf ("\t|                TOTAL: R$ %.2f                 \n", *ptr_total_carrinho);
    printf ("\t|                                               |\n");
    printf ("\t=================================================\n");
    printf ("\t|             Primeiro pagamento em:            |\n");
    printf ("\t|                   1. Cartão                   |\n");
    printf ("\t|                   2. Dinheiro                 |\n");
    printf ("\t=================================================\n\n");
    printf ("\t..::: Digite sua resposta:  ");
}

void digite_valor_cartao_tela()
{
    system ("cls");
    printf ("\n\n\t=================================================\n");
    printf ("\t|                                               |\n");
    printf ("\t|        Digite o valor pago em cartão:         |\n");
    printf ("\t|                                               |\n");
    printf ("\t=================================================\n\n");
    printf ("\t..:::  ");
}

void restante_dinheiro_tela()
{
    int op;
    system("cls");
    printf ("\n\n\t=================================================\n");
    printf ("\t|                                               |\n");
    printf ("\t|   O restante a ser pago em dinheiro é: %.2f   \n", ptr_dinheiros->dinheiro_cartao_restante);
    printf ("\t|                                               |\n");
    printf ("\t=================================================\n");
    printf ("\t|               Precisa de troco ?              |\n");
    printf ("\t|                    1. Sim                     |\n");
    printf ("\t|                    2. Não                     |\n");
    printf ("\t=================================================\n\n");
    printf("\t..::: Digite sua resposta:  ");
    scanf ("%i", &op);
    if(op == 1)
    {
        dinheiro_pago_tela();
        scanf ("%f", &ptr_dinheiros->dinheiro_pago);
        getchar();
        if(ptr_dinheiros->dinheiro_pago > ptr_dinheiros->dinheiro_cartao_restante)
        {
            ptr_dinheiros->troco = ptr_dinheiros->dinheiro_pago - ptr_dinheiros->dinheiro_cartao_restante;
            troco_tela();
            ptr_dinheiros->dinheiro = ptr_dinheiros->dinheiro - ptr_dinheiros->troco;
            system("pause");
        }
        else
        {
            restante_dinheiro_tela();
        }
    }
}

void digite_valor_dinheiro_tela()
{
    system ("cls");
    printf ("\n\n\t=================================================\n");
    printf ("\t|                                               |\n");
    printf ("\t|        Digite o valor pago em dinheiro:       |\n");
    printf ("\t|                                               |\n");
    printf ("\t=================================================\n\n");
    printf ("\t..:::  ");
}

void restante_cartao_tela()
{
    system ("cls");
    printf ("\n\n\t==================================================\n");
    printf ("\t|                                                |\n");
    printf ("\t|    O restante a ser pago em cartao é: %.2f      \n", ptr_dinheiros->dinheiro_cartao_restante);
    printf ("\t|                                                |\n");
    printf ("\t==================================================\n");
    printf ("\t|              Compra bem sucedida?              |\n");
    printf ("\t|                    1. Sim                      |\n");
    printf ("\t|                    2. Não                      |\n");
    printf ("\t==================================================\n\n");
    printf ("\t..::: Digite sua resposta:  ");
}


void printfcomprafinalizada ()
{
    system("cls");
    printf ("\n\n\t===========================================\n");
    printf ("\t|                                         |\n");
    printf ("\t|             Compra finalizada!          |\n");
    printf ("\t|                                         |\n");
    printf ("\t===========================================\n\n\n\t");
}


void printfcompracancelada ()
{
    system ("cls");
    printf ("\n\n\t=======================================\n");
    printf ("\t|                                     |\n");
    printf ("\t|          Compra cancelada!          |\n");
    printf ("\t|                                     |\n");
    printf ("\t=======================================\n\n\n\t");
    system ("pause");
}

void voltandoparaomenu()
{
    system("cls");
    printf ("\n\n\t==========================================\n");
    printf ("\t|                                        |\n");
    printf ("\t|   Voltando para o menu de pagamento!   |\n");
    printf ("\t|                                        |\n");
    printf ("\t==========================================\n\n\n\t");
}

void tela_nadafoicomprado()
{
    system("cls");
    printf ("\n\n\t==========================================\n");
    printf ("\t|                                        |\n");
    printf ("\t|           Nada foi comprado!           |\n");
    printf ("\t|                                        |\n");
    printf ("\t==========================================\n\n\n\t");
    system("pause");
    system("cls");
}



void tela_nao_ha_estoque()
{
    printf ("\n\n\t================================\n");
    printf ("\t|                              |\n");
    printf ("\t|        Não há estoque!       |\n");
    printf ("\t|                              |\n");
    printf ("\t|                              |\n");
    printf ("\t|  Deseja continuar a compra?  |\n");
    printf ("\t|                              |\n");
    printf ("\t|     1 - Sim      2 - Não     |\n");
    printf ("\t|                              |\n");
    printf ("\t================================\n\n");
    printf ("\t..::: Digite a resposta:  ");
}

void tela_impedir_cadastro()
{
    system("cls");
    printf ("\n\n\t============================================\n");
    printf ("\t|                                          |\n");
    printf ("\t|      Não é possível cadastrar itens      |\n");
    printf ("\t|         com produtos no carrinho!        |\n");
    printf ("\t|                                          |\n");
    printf ("\t============================================\n\n\n");
    system("pause");
    system("cls");
}

void ja_tem_item_no_carrinho_tela()
{
    int op;
    system("cls");
    printf ("\n\n\t============================================\n");
    printf ("\t|                                          |\n");
    printf ("\t|      Uma venda já está em andamento!     |\n");
    printf ("\t|                                          |\n");
    printf ("\t|       Gostaria de cancelar ela para      |\n");
    printf ("\t|              iniciar outra?              |\n");
    printf ("\t|                                          |\n");
    printf ("\t|                                          |\n");
    printf ("\t|          1 - Sim          2 - Não        |\n");
    printf ("\t|                                          |\n");
    printf ("\t============================================\n\n\n");
    scanf("%i", &op);
    if(op==1)
    {
        cancelar_compra_menu_tela();
    }
    else
    {
        vendas_compras_menu_tela();
    }
}


void caixa_fechado_tela()
{
    system("cls");
    printf ("\n\n\t================================\n");
    printf ("\t|                              |\n");
    printf ("\t|        Caixa fechado!        |\n");
    printf ("\t|                              |\n");
    printf ("\t================================\n\n\n");
    system("pause");
    system("cls");
}

void caixa_ja_aberto_tela()
{
    system("cls");
    printf ("\n\n\t=================================\n");
    printf ("\t|                               |\n");
    printf ("\t|    O Caixa ja está aberto!    |\n");
    printf ("\t|                               |\n");
    printf ("\t=================================\n\n\n");
    system("pause");
    system("cls");
}

void confirmar_desconto_tela()
{
    printf ("\n\n\t=================================\n");
    printf ("\t|                               |\n");
    printf ("\t|      Confirmar desconto?      |\n");
    printf ("\t|                               |\n");
    printf ("\t|      1 - Sim     2 - Não      |\n");
    printf ("\t|                               |\n");
    printf ("\t=================================\n\n");
    printf ("\t..::: Digite a resposta:  ");
}


void desconto_tela()
{
    system("cls");
    printf ("\n\n\t=================================\n");
    printf ("\t|                               |\n");
    printf ("\t|    Digite a %% de desconto     |\n");
    printf ("\t|                               |\n");
    printf ("\t=================================\n");
    printf ("\t..:::  ");
}

void compra_bem_sucedida_tela()
{
    printf ("\n\n\t==================================================\n");
    printf ("\t|              Compra bem sucedida?              |\n");
    printf ("\t|                    1. Sim                      |\n");
    printf ("\t|                    2. Não                      |\n");
    printf ("\t==================================================\n\n");
    printf ("\t..::: Digite sua resposta:  ");
}


