//sistema da berenice

//bibliotecas
#include <stdio.h> //biblioteca que cont�m fun��es de entrada e sa�da padr�o
#include <stdlib.h> //biblioteca que cont�m os comandos system, que no caso desse c�digo pausam o sistema e limpam a tela
#include <string.h> //biblioteca para uso complexo de strings
#include <locale.h> //biblioteca usada para colocar a lingua portuguesa no c�digo, podendo usar acentos
#include <time.h>  //biblioteca usada para colocar hor�rio no sistema
#include "VARIAVEIS.h" //arquivo variaveis, que contem as variaveis usadas na bere
#include "VENDAS.h" //arquivo de vendas, necess�rio para arquivar vendas antigas,
#include "USUARIOS.h" //arquivo de usu�rios, presente para controlar o sistema de usu�rios
#include "CLIENTES.h" //arquivo de clientes, que contem as fun��es usadas para arquivar e usar os clientes no sistema
#include "PRODUTOS.h" //arquivo de produtos, que contem as fun��es necess�rias para arquivar e usar os produtos no sistema
#include "FUNCOES.h" //arquivo FUNCOES, que cont�m fun��es importantes para o funcionamento do sistema
#include "TELA.h" //arquivo TELA, que cont�m grande parte dos c�digos que fazem a bere rodar, al�m de ter todos os menus que aparecerem na tela




//c�digo main
int main ()
{

//linguagem
    setlocale(LC_ALL, "Portuguese");

    zerar_vendidos(); //zera o carrinho, para n�o bugar o arquivo de vendas

    lerUsuarios(); //le os usu�rios do arquivo

    menu_usuarios(); //abre o menu de login, necess�rio para entrar no sistema da bere (fun��es de usu�rios est�o no arquivo de usuarios)

    clientes_ler_do_arquivo(); //fun��o respons�vel pela leitura do arquivo que cont�m os dados dos clientes, presente no arquivo ARQUIVOS

    produtos_ler_do_arquivo(); //fun��o respons�vel pela leitura do arqueivo que cont�m os dados dos produtos, presente no arquivo ARQUIVOS

    ler_contador_de_vendas(); //le as vendas antigas presentes no arquivo .txt (as fu��es de vendas est�o no arquivo de vendas)

    telabemvindo(); //tela de bem vindo, presente no arquivo TELA

    do
    {
main_rep:

        sistema_da_bere_tela(); //menu inicial da bere

        scanf ("%i", &operador[0]); //scanf que determina qual op��o do menu inicial foi escolhido

        getchar();


        switch(operador[0])
        {
        case 1:

            do
            {
                cadastros_menu_tela(); //menu de cadastro de produtos e clientes

                scanf ("%i", &operador[1]);
                getchar();

                switch(operador[1])
                {

                case 1:
                    do
                    {
                        cadastros_clientes_menu_tela();  //menu de cadastro de clientes (confirma��o de cadastro)
                        scanf ("%i", &operador[4]);
                        getchar();

                        if(operador[4] == 1)
                        {
                            cadastros_clientes_menu2_tela(); //coloca��o de cadastro de clientes (presente no arquivo CLIENTES)
                        }
                    }
                    while(operador[4] != 2);
                    break;

                case 2:
                    if(*ptr_total_carrinho == 0) //caso n�o tenha nada no carrinho, � poss�vel cadastrar novos produtos
                    {
                        do
                        {
                            cadastros_produtos_menu_tela(); //menu de cadastro de produtos (confirmar se quer realmente cadastrar produtos)
                            scanf ("%i", &operador[5]);
                            getchar();

                            if(operador[5] == 1)
                            {
                                cadastros_produtos_menu2_tela(); //cadastro de produtos (presente no arquivo PRODUTOS)
                            }

                        }
                        while(operador[5] != 2);
                    }
                    else
                    {
                        tela_impedir_cadastro(); //caso tenha itens no carrinho, esta tela aparece
                    }
                    break;

                case 3:
                    if(*ptr_total_carrinho == 0) //caso n�o tenha nada no carrinho, � poss�vel cadastrar novos produtos
                    {
                        alterar_produtos_menu_tela(); //menu de alterar produtos, presente no arquivo PRODUTOS
                    }
                    else
                    {
                        tela_impedir_cadastro(); //caso tenha itens no carrinho, esta tela aparece
                    }
                    break;

                case 4:
                    if(*ptr_total_carrinho == 0) //caso n�o tenha nada no carrinho, � poss�vel cadastrar novos produtos
                    {
                        alterar_estoque_menu_tela(); //menu de alterar estoque de produtos, presente no arquivo PRODUTOS
                    }
                    else
                    {
                        tela_impedir_cadastro(); //caso tenha itens no carrinho, esta tela aparece
                    }
                    break;
                }

            }
            while(operador[1] != 5);
            break;

        case 2:

            if(caixa_fechado != 1) //caso o caixa n�o estiver fechado, � poss�vel vender (1- para fecahdo, 2 para aberto)
            {

                do
                {
                    vendas_menu_tela(); //menu de vendas (vendas, sangria, cancelamento, pagamento)

                    scanf ("%i", &operador[2]);
                    getchar();

                    switch(operador[2])
                    {
                    case 1:
                        if(*ptr_total_carrinho == 0)
                        {
                            vendas_compras_menu_tela(); //menu de vendas de itens (escolha da categoria vendida)
                        }
                        else
                        {
                            ja_tem_item_no_carrinho_tela(); //caso ja tenha itens no carrinho, o sistema pergunta se � pra mesma venda
                        }
                        break;


                    case 2:
                        if(usuario_atual.nivel_de_controle == 1)
                        {
                            sangria_menu_tela(); //menu de sangria (presente no arquivo TELA)
                        }
                        else
                        {
                            acesso_negado(); //se o usu�rio for comum, n�o � poss�vel entrar na sangria
                        }
                        break;

                    case 3:

                        if(*ptr_total_carrinho > 0) //caso tenha algo no carrinho, � poss�vel cancelar a compra
                        {
                            cancelar_compra_menu_tela(); //menu de cancelamento
                        }
                        else
                        {
                            tela_nadafoicomprado(); //caso n�o tenha algo no carrinho, aparece esta tela
                        }
                        break;

                    case 4:
                        if(*ptr_total_carrinho > 0) //se tiver algo no carrinho, � poss�vel fazer o pagamento
                        {
                            do
                            {
                                pagamento_tela(); //tela de pagamento, escolha de op��o de pagamento (cart�o, dinheiro, etc)

                                scanf ("%i", &operador[8]);
                                getchar();

                                switch(operador[8])
                                {

                                case 1:

                                    dinheiro_tela(); //pagamento em dinheiro (escolha se precisa de troco ou n�o)

                                    scanf("%i", &operador[9]);
                                    getchar();

                                    if(operador[9] == 1)
                                    {
                                        dinheiro_pago_tela(); //caso precise de troco

                                        scanf ("%f", &ptr_dinheiros->dinheiro_pago); //inserir o dinheiro
                                        getchar();

                                        if(ptr_dinheiros->dinheiro_pago > *ptr_total_carrinho) //se o dinheiro dado for maior que o devido, ent�o � necess�rio troco
                                        {
                                            ptr_dinheiros->troco = ptr_dinheiros->dinheiro_pago - *ptr_total_carrinho; //calculo do troco

                                            troco_tela(); //tela que mostra o troco

                                            ptr_dinheiros->dinheiro += ptr_dinheiros->dinheiro_pago - ptr_dinheiros->troco; //adicionando o dinheiro pago na quantidade de dinheiro em caixa

                                            printfcomprafinalizada (); //tela que mostra que a venda foi finalizada

                                            tipo_de_pagamento = 1; //o tipo de pagamento recebe o valor 1, ou seja, o 1 vai ser lido depois como pagamento no dinheiro

                                            compra_finalizada_func(); //fun��o utilizada quando uma venda � finalizada (presente no arquivo FUNCOES)

                                            system ("pause");
                                            system ("cls");

                                            goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                        }
                                    }

                                    if(operador[9] == 2)
                                    {

                                        printfcomprafinalizada(); //caso n�o precise de troco, a compra � finalizada na hora

                                        tipo_de_pagamento = 1; //o tipo de pagamento recebe o valor 1, ou seja, o 1 vai ser lido depois como pagamento no dinheiro

                                        ptr_dinheiros->dinheiro += *ptr_total_carrinho; //o dinheiro pago � inserio no dinheiro em caixa

                                        compra_finalizada_func(); //fun��o utilizada quando uma venda � finalizada (presente no arquivo FUNCOES)

                                        system ("pause");
                                        system ("cls");

                                        goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                    }

                                    break;

                                case 2:

                                    pagamento_cartao_tela(); //tela que aparece caso a compra for em cart�o

                                    scanf("%i", &operador[9]);
                                    getchar();

                                    if(operador[9] == 1)
                                    {
                                        printfcomprafinalizada(); //caso n�o haja erros no cart�o, a compra � finalizada

                                        tipo_de_pagamento = 2; //o tipo de pagamento recebe o valor 2, ou seja, o 2 vai ser lido depois como pagamento no cart�o

                                        ptr_dinheiros->cartao += *ptr_total_carrinho; // o dinheiro � adicionado na vari�vel cart�o, para ser mostrada depois

                                        compra_finalizada_func(); //fun��o que finaliza a comrpa, presente no arquivo FUNCOES

                                        system ("pause");
                                        system ("cls");

                                        goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                    }

                                    if(operador[9] == 2)
                                    {
                                        voltandoparaomenu(); //caso o cart�o d� um erro, � poss�vel voltar para o menu inicial

                                        system ("pause");
                                        system ("cls");
                                    }
                                    break;

                                case 3:

                                    pagamento_cartao_e_dinheiro_tela(); //caso a pagamento seja misto (em dinheiro e cart�o), est� op��o � a certa a ser escolhida

                                    scanf("%i", &operador[10]);
                                    getchar();

                                    if(operador[10] == 1)
                                    {

                                        digite_valor_cartao_tela(); //caso o primeiro pagamento seja em cart�o, � necess�rio inserir o valor pago em cart�o

                                        scanf ("%f", &ptr_dinheiros->cartao_pago); //a bere coloca o valor pago em cart�o
                                        getchar();

                                        compra_bem_sucedida_tela();
                                        int op;
                                        scanf("%i", &op);

                                        if(op==1)
                                        {

                                            if(ptr_dinheiros->cartao_pago >= *ptr_total_carrinho) //se esse valor for maior que o devido, ent�o n�o ser� necess�rio pagar o resto em dinheiro
                                            {
                                                ptr_dinheiros->troco = ptr_dinheiros->cartao_pago - *ptr_total_carrinho;

                                                troco_tela(); //ent�o o cliente necessitara de troco
                                                system("pause");

                                                ptr_dinheiros->cartao += ptr_dinheiros->cartao_pago; //o dinheiro pago em cart�o � inserido na vari�vel que consta todos os valores recebidos em cart�o

                                                ptr_dinheiros->dinheiro -= ptr_dinheiros->troco;

                                                tipo_de_pagamento = 2; // e o tipo de pagamento recebe o valor 2, ou seja, o 2 vai ser lido depois como pagamento no cart�o

                                                printfcomprafinalizada();
                                                compra_finalizada_func();
                                                system("pause");
                                                goto main_rep;
                                            }
                                            //caso o dinheiro entregue no cart�o n�o seja a quantia necess�ria, o resto ser� no dinheiro

                                            ptr_dinheiros->cartao += ptr_dinheiros->cartao_pago; //o dinheiro pago em cart�o � inserido na vari�vel que consta todos os valores recebidos em cart�o

                                            ptr_dinheiros->dinheiro_cartao_restante = *ptr_total_carrinho - ptr_dinheiros->cartao_pago; //o dinheiro restante � calculado

                                            ptr_dinheiros->dinheiro += ptr_dinheiros->dinheiro_cartao_restante; //o restante, pago em dinheiro, � incerido na variavel que consta os valores pago em dinheiro

                                            restante_dinheiro_tela(); //aparece ent�o, na tela, o restante do dinheiro a ser pago

                                            tipo_de_pagamento = 3; //o tipo de pagamento recebe o valor 3, que depois vai ser convertido para pagamento em Cart�o + Dinheiro

                                            printfcomprafinalizada(); //tela que mostra que a compra foi finalizada

                                            compra_finalizada_func(); //fun��o presente para finalizar a compra, presente no arquivo FUNCOES

                                            system ("pause");
                                            system ("cls");

                                            goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                        }
                                        else
                                        {
                                            voltandoparaomenu();
                                            system("pause");//caso a compra n�o seja bem sucedida, o pagamento � cancelado e volta para o menu de pagamento
                                            break;
                                        }

                                    }

                                    if(operador[10] == 2)
                                    {
                                        int op;
                                        digite_valor_dinheiro_tela(); //caso o primeiro pagamento for em dinheiro, � necess�rio inserir a quantia de dinheiro paga

                                        scanf ("%f", &ptr_dinheiros->dinheiro_pago);
                                        getchar();

                                        if(ptr_dinheiros->dinheiro_pago >= *ptr_total_carrinho) //se o dinheiro dado for maior que o devido, ent�o n�o � necess�rio pagar o restante no cart�o
                                        {
                                            ptr_dinheiros->troco = ptr_dinheiros->dinheiro_pago - *ptr_total_carrinho;

                                            troco_tela(); //o troco � calculado e mostrado na tela
                                            system("pause");

                                            ptr_dinheiros->dinheiro += ptr_dinheiros->dinheiro_pago - ptr_dinheiros->troco;

                                            tipo_de_pagamento = 1; //o tipo de pagamento recebe o valor 1, ou seja, o 1 vai ser lido depois como pagamento no dinheiro

                                            printfcomprafinalizada();
                                            compra_finalizada_func();
                                            system ("pause");
                                            goto main_rep;
                                        }
                                        //caso n�o seja o suficiente, o restante vai ser pago em cart�o
                                        ptr_dinheiros->dinheiro_cartao_restante = *ptr_total_carrinho - ptr_dinheiros->dinheiro_pago; // o restante vai para a vari�vel que calculara o restante a ser pago em cart�o

                                        restante_cartao_tela(); //aparece na tela o restante a ser pago em cart�o, e pergunta se a compra foi bem sucedida

                                        scanf("%i", &op);
                                        if(op==2)
                                        {
                                            voltandoparaomenu();
                                            system("pause");//caso a compra n�o seja bem sucedida, o pagamento � cancelado e volta para o menu de pagamento
                                            break;
                                        }


                                        ptr_dinheiros->dinheiro += ptr_dinheiros->dinheiro_pago; // o dinheiro pago ent�o � constado na vari�vel que conta o dinheiro em caixa

                                        ptr_dinheiros->cartao += ptr_dinheiros->dinheiro_cartao_restante; // o restante a ser pago em cart�o � inserido na vari�vel que conta a quantia de dinheiro paga em cart�o

                                        printfcomprafinalizada(); //tela que mostra que a compra foi finalizada

                                        tipo_de_pagamento = 3; //o tipo de pagamento recebe o valor 3, que vai ser convertido depois para pagamento em dinheiro + cart�o

                                        compra_finalizada_func(); //fun��o presente sempre que a compra � finalizada

                                        system ("pause");
                                        system ("cls");

                                        goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                    }
                                    break;

                                case 4:
                                    desconto_tela(); //tela para dar desconto
                                    scanf("%f", &desconto);
                                    getchar();
                                    confirmar_desconto_tela(); //tela para confirmar o desconto
                                    scanf("%i", &operador[16]);
                                    getchar();

                                    ptr_dinheiros->desconto = desconto/100;
                                    *ptr_total_carrinho = *ptr_total_carrinho - (*ptr_total_carrinho * ptr_dinheiros->desconto);
                                    //caso o desconto seja confirmado o calculo � feito e o total � descontado
                                    break;

                                case 5:
                                    lista_clientes_para_atribuicao();//se a bere quiser atribuir a venda a um cliente, est� tela aparece (presente no arquivo clientes)
                                    break;
                                }
                            }
                            while(operador[8] != 6);
                        }
                        else
                        {
                            tela_nadafoicomprado(); //se nada estiver no carrinho, n�o � poss�vel fazer o pagamento
                        }
                        break;
                    }
                }
                while(operador[2] != 5);
            }
            else
            {
                caixa_fechado_tela(); //se o caixa estiver fechado, n�o � poss�vel entrar no menu de vendas
            }

            break;

        case 3:

            if(usuario_atual.nivel_de_controle == 1) //se o usu�rio atual for comum, n�o � poss�vel abrir o caixa
            {
                if(caixa_fechado == 1) //se o caixa estiver fechado, � poss�vel abrir ele
                {
                    tela_abertura_de_caixa(); //tela de abertura de caixa

                    caixa_fechado = 2; //ap�s o caixa abrir, a vari�vel "caixa_fechado" recebe o valor 2, que indica que o caixa est� aberto
                }
                else
                {
                    caixa_ja_aberto_tela(); // se o caixa ja estiver aberto, n�o � poss�vel abrir de novo
                }
            }
            else
            {
                acesso_negado();
            }
            break;

        case 4:

            if(usuario_atual.nivel_de_controle == 1) //se o usu�rio atual for comum, n�o � poss�vel fechar o caixa
            {
                if(caixa_fechado != 1) // se o caixa estiver fechado, n�o � poss�vel fechar ele
                {
                    fechamento_de_caixa_menu_tela(); //menu de fechamento de caixa, presente no arquivo TELA

                    if(caixa_fechado==1) //se o caixa foi fechado, uma confirma��o aparecera na tela
                    {
                        confirmado_caixa_fechado(); //confima��o de caixa fechado, presente no menu tela
                        goto main_rep;
                    }
                }
                else
                {
                    caixa_fechado_tela(); //se o caixa estiver fechado, esta tela aparecera, n�o deixando fecha-lo novamente
                }
            }
            else
            {
                acesso_negado();
            }
            break;


        case 5:

            do
            {
                relatorios_menu_tela(); //menu de relat�rios

                scanf ("%i", &operador[6]);
                getchar();

                switch(operador[6])
                {
                case 1:
                    if(produtos_vendidos[0][0].ano != 0)//s� entra no hist�rico se ja tiver vendido algo
                    {
                        historico_de_vendas(); //historico de vendas, presente no arquivo VENDAS
                    }
                    else
                    {
                        tela_nadafoicomprado();
                    }
                    break;

                case 2:
                    lista_clientes_tela(); //lista de clientes cadastrados (presente no arquivo TELA)
                    break;

                case 3:
                    lista_produtos_tela(); //lista de produtos cadastrados (presnete no arquivo TELA)
                    break;

repetirbuscatela:

                case 4:
                    busca_tela(); //tela de busca
                    scanf("%i",&operador[7]);
                    getchar();
                    do
                    {
                        switch(operador[7])
                        {
                        case 1:
                            if(contador_clientes>0)
                            {
                                pesquisarClienteCodigo();
                                goto repetirbuscatela;
                            }
                            else
                                nao_ha_clientes_cadastrados_tela();
                            goto repetirbuscatela;
                            break;
                        case 2:
                            if(contador_clientes>0)
                            {
                                listarClientesOrdemAlfabetica(clientes_salvos,contador_clientes);
                                goto repetirbuscatela;
                            }
                            else
                                nao_ha_clientes_cadastrados_tela();
                            goto repetirbuscatela;
                            break;
                        case 3:
                            if(contador_produtos>0)
                            {
                                pesquisarProdutoCodigo();
                                goto repetirbuscatela;
                            }
                            else
                                nao_ha_produtos_cadastrados_tela();
                            goto repetirbuscatela;
                            break;
                        case 4:
                            if(contador_produtos>0)
                            {
                                listarProdutosOrdemAlfabetica(produtos_salvos, contador_produtos);
                                goto repetirbuscatela;
                            }
                            else
                                nao_ha_produtos_cadastrados_tela();
                            goto repetirbuscatela;
                            break;
                        }
                    }
                    while(operador[7]!=5);

                    break;

                }
                break;
            }
            while (operador[6] != 5);

        }
    }
    while (operador[0] != 6);
    exit(1);
    return 1;
}

