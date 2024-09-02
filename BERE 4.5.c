//sistema da berenice

//bibliotecas
#include <stdio.h> //biblioteca que contém funções de entrada e saída padrão
#include <stdlib.h> //biblioteca que contém os comandos system, que no caso desse código pausam o sistema e limpam a tela
#include <string.h> //biblioteca para uso complexo de strings
#include <locale.h> //biblioteca usada para colocar a lingua portuguesa no código, podendo usar acentos
#include <time.h>  //biblioteca usada para colocar horário no sistema
#include "VARIAVEIS.h" //arquivo variaveis, que contem as variaveis usadas na bere
#include "VENDAS.h" //arquivo de vendas, necessário para arquivar vendas antigas,
#include "USUARIOS.h" //arquivo de usuários, presente para controlar o sistema de usuários
#include "CLIENTES.h" //arquivo de clientes, que contem as funções usadas para arquivar e usar os clientes no sistema
#include "PRODUTOS.h" //arquivo de produtos, que contem as funções necessárias para arquivar e usar os produtos no sistema
#include "FUNCOES.h" //arquivo FUNCOES, que contém funções importantes para o funcionamento do sistema
#include "TELA.h" //arquivo TELA, que contém grande parte dos códigos que fazem a bere rodar, além de ter todos os menus que aparecerem na tela




//código main
int main ()
{

//linguagem
    setlocale(LC_ALL, "Portuguese");

    zerar_vendidos(); //zera o carrinho, para não bugar o arquivo de vendas

    lerUsuarios(); //le os usuários do arquivo

    menu_usuarios(); //abre o menu de login, necessário para entrar no sistema da bere (funções de usuários estão no arquivo de usuarios)

    clientes_ler_do_arquivo(); //função responsável pela leitura do arquivo que contém os dados dos clientes, presente no arquivo ARQUIVOS

    produtos_ler_do_arquivo(); //função responsável pela leitura do arqueivo que contém os dados dos produtos, presente no arquivo ARQUIVOS

    ler_contador_de_vendas(); //le as vendas antigas presentes no arquivo .txt (as fuções de vendas estão no arquivo de vendas)

    telabemvindo(); //tela de bem vindo, presente no arquivo TELA

    do
    {
main_rep:

        sistema_da_bere_tela(); //menu inicial da bere

        scanf ("%i", &operador[0]); //scanf que determina qual opção do menu inicial foi escolhido

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
                        cadastros_clientes_menu_tela();  //menu de cadastro de clientes (confirmação de cadastro)
                        scanf ("%i", &operador[4]);
                        getchar();

                        if(operador[4] == 1)
                        {
                            cadastros_clientes_menu2_tela(); //colocação de cadastro de clientes (presente no arquivo CLIENTES)
                        }
                    }
                    while(operador[4] != 2);
                    break;

                case 2:
                    if(*ptr_total_carrinho == 0) //caso não tenha nada no carrinho, é possível cadastrar novos produtos
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
                    if(*ptr_total_carrinho == 0) //caso não tenha nada no carrinho, é possível cadastrar novos produtos
                    {
                        alterar_produtos_menu_tela(); //menu de alterar produtos, presente no arquivo PRODUTOS
                    }
                    else
                    {
                        tela_impedir_cadastro(); //caso tenha itens no carrinho, esta tela aparece
                    }
                    break;

                case 4:
                    if(*ptr_total_carrinho == 0) //caso não tenha nada no carrinho, é possível cadastrar novos produtos
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

            if(caixa_fechado != 1) //caso o caixa não estiver fechado, é possível vender (1- para fecahdo, 2 para aberto)
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
                            ja_tem_item_no_carrinho_tela(); //caso ja tenha itens no carrinho, o sistema pergunta se é pra mesma venda
                        }
                        break;


                    case 2:
                        if(usuario_atual.nivel_de_controle == 1)
                        {
                            sangria_menu_tela(); //menu de sangria (presente no arquivo TELA)
                        }
                        else
                        {
                            acesso_negado(); //se o usuário for comum, não é possível entrar na sangria
                        }
                        break;

                    case 3:

                        if(*ptr_total_carrinho > 0) //caso tenha algo no carrinho, é possível cancelar a compra
                        {
                            cancelar_compra_menu_tela(); //menu de cancelamento
                        }
                        else
                        {
                            tela_nadafoicomprado(); //caso não tenha algo no carrinho, aparece esta tela
                        }
                        break;

                    case 4:
                        if(*ptr_total_carrinho > 0) //se tiver algo no carrinho, é possível fazer o pagamento
                        {
                            do
                            {
                                pagamento_tela(); //tela de pagamento, escolha de opção de pagamento (cartão, dinheiro, etc)

                                scanf ("%i", &operador[8]);
                                getchar();

                                switch(operador[8])
                                {

                                case 1:

                                    dinheiro_tela(); //pagamento em dinheiro (escolha se precisa de troco ou não)

                                    scanf("%i", &operador[9]);
                                    getchar();

                                    if(operador[9] == 1)
                                    {
                                        dinheiro_pago_tela(); //caso precise de troco

                                        scanf ("%f", &ptr_dinheiros->dinheiro_pago); //inserir o dinheiro
                                        getchar();

                                        if(ptr_dinheiros->dinheiro_pago > *ptr_total_carrinho) //se o dinheiro dado for maior que o devido, então é necessário troco
                                        {
                                            ptr_dinheiros->troco = ptr_dinheiros->dinheiro_pago - *ptr_total_carrinho; //calculo do troco

                                            troco_tela(); //tela que mostra o troco

                                            ptr_dinheiros->dinheiro += ptr_dinheiros->dinheiro_pago - ptr_dinheiros->troco; //adicionando o dinheiro pago na quantidade de dinheiro em caixa

                                            printfcomprafinalizada (); //tela que mostra que a venda foi finalizada

                                            tipo_de_pagamento = 1; //o tipo de pagamento recebe o valor 1, ou seja, o 1 vai ser lido depois como pagamento no dinheiro

                                            compra_finalizada_func(); //função utilizada quando uma venda é finalizada (presente no arquivo FUNCOES)

                                            system ("pause");
                                            system ("cls");

                                            goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                        }
                                    }

                                    if(operador[9] == 2)
                                    {

                                        printfcomprafinalizada(); //caso não precise de troco, a compra é finalizada na hora

                                        tipo_de_pagamento = 1; //o tipo de pagamento recebe o valor 1, ou seja, o 1 vai ser lido depois como pagamento no dinheiro

                                        ptr_dinheiros->dinheiro += *ptr_total_carrinho; //o dinheiro pago é inserio no dinheiro em caixa

                                        compra_finalizada_func(); //função utilizada quando uma venda é finalizada (presente no arquivo FUNCOES)

                                        system ("pause");
                                        system ("cls");

                                        goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                    }

                                    break;

                                case 2:

                                    pagamento_cartao_tela(); //tela que aparece caso a compra for em cartão

                                    scanf("%i", &operador[9]);
                                    getchar();

                                    if(operador[9] == 1)
                                    {
                                        printfcomprafinalizada(); //caso não haja erros no cartão, a compra é finalizada

                                        tipo_de_pagamento = 2; //o tipo de pagamento recebe o valor 2, ou seja, o 2 vai ser lido depois como pagamento no cartão

                                        ptr_dinheiros->cartao += *ptr_total_carrinho; // o dinheiro é adicionado na variável cartão, para ser mostrada depois

                                        compra_finalizada_func(); //função que finaliza a comrpa, presente no arquivo FUNCOES

                                        system ("pause");
                                        system ("cls");

                                        goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                    }

                                    if(operador[9] == 2)
                                    {
                                        voltandoparaomenu(); //caso o cartão dê um erro, é possível voltar para o menu inicial

                                        system ("pause");
                                        system ("cls");
                                    }
                                    break;

                                case 3:

                                    pagamento_cartao_e_dinheiro_tela(); //caso a pagamento seja misto (em dinheiro e cartão), está opção é a certa a ser escolhida

                                    scanf("%i", &operador[10]);
                                    getchar();

                                    if(operador[10] == 1)
                                    {

                                        digite_valor_cartao_tela(); //caso o primeiro pagamento seja em cartão, é necessário inserir o valor pago em cartão

                                        scanf ("%f", &ptr_dinheiros->cartao_pago); //a bere coloca o valor pago em cartão
                                        getchar();

                                        compra_bem_sucedida_tela();
                                        int op;
                                        scanf("%i", &op);

                                        if(op==1)
                                        {

                                            if(ptr_dinheiros->cartao_pago >= *ptr_total_carrinho) //se esse valor for maior que o devido, então não será necessário pagar o resto em dinheiro
                                            {
                                                ptr_dinheiros->troco = ptr_dinheiros->cartao_pago - *ptr_total_carrinho;

                                                troco_tela(); //então o cliente necessitara de troco
                                                system("pause");

                                                ptr_dinheiros->cartao += ptr_dinheiros->cartao_pago; //o dinheiro pago em cartão é inserido na variável que consta todos os valores recebidos em cartão

                                                ptr_dinheiros->dinheiro -= ptr_dinheiros->troco;

                                                tipo_de_pagamento = 2; // e o tipo de pagamento recebe o valor 2, ou seja, o 2 vai ser lido depois como pagamento no cartão

                                                printfcomprafinalizada();
                                                compra_finalizada_func();
                                                system("pause");
                                                goto main_rep;
                                            }
                                            //caso o dinheiro entregue no cartão não seja a quantia necessária, o resto será no dinheiro

                                            ptr_dinheiros->cartao += ptr_dinheiros->cartao_pago; //o dinheiro pago em cartão é inserido na variável que consta todos os valores recebidos em cartão

                                            ptr_dinheiros->dinheiro_cartao_restante = *ptr_total_carrinho - ptr_dinheiros->cartao_pago; //o dinheiro restante é calculado

                                            ptr_dinheiros->dinheiro += ptr_dinheiros->dinheiro_cartao_restante; //o restante, pago em dinheiro, é incerido na variavel que consta os valores pago em dinheiro

                                            restante_dinheiro_tela(); //aparece então, na tela, o restante do dinheiro a ser pago

                                            tipo_de_pagamento = 3; //o tipo de pagamento recebe o valor 3, que depois vai ser convertido para pagamento em Cartão + Dinheiro

                                            printfcomprafinalizada(); //tela que mostra que a compra foi finalizada

                                            compra_finalizada_func(); //função presente para finalizar a compra, presente no arquivo FUNCOES

                                            system ("pause");
                                            system ("cls");

                                            goto main_rep; //depois de finalizar a venda, volta para o menu inicial
                                        }
                                        else
                                        {
                                            voltandoparaomenu();
                                            system("pause");//caso a compra não seja bem sucedida, o pagamento é cancelado e volta para o menu de pagamento
                                            break;
                                        }

                                    }

                                    if(operador[10] == 2)
                                    {
                                        int op;
                                        digite_valor_dinheiro_tela(); //caso o primeiro pagamento for em dinheiro, é necessário inserir a quantia de dinheiro paga

                                        scanf ("%f", &ptr_dinheiros->dinheiro_pago);
                                        getchar();

                                        if(ptr_dinheiros->dinheiro_pago >= *ptr_total_carrinho) //se o dinheiro dado for maior que o devido, então não é necessário pagar o restante no cartão
                                        {
                                            ptr_dinheiros->troco = ptr_dinheiros->dinheiro_pago - *ptr_total_carrinho;

                                            troco_tela(); //o troco é calculado e mostrado na tela
                                            system("pause");

                                            ptr_dinheiros->dinheiro += ptr_dinheiros->dinheiro_pago - ptr_dinheiros->troco;

                                            tipo_de_pagamento = 1; //o tipo de pagamento recebe o valor 1, ou seja, o 1 vai ser lido depois como pagamento no dinheiro

                                            printfcomprafinalizada();
                                            compra_finalizada_func();
                                            system ("pause");
                                            goto main_rep;
                                        }
                                        //caso não seja o suficiente, o restante vai ser pago em cartão
                                        ptr_dinheiros->dinheiro_cartao_restante = *ptr_total_carrinho - ptr_dinheiros->dinheiro_pago; // o restante vai para a variável que calculara o restante a ser pago em cartão

                                        restante_cartao_tela(); //aparece na tela o restante a ser pago em cartão, e pergunta se a compra foi bem sucedida

                                        scanf("%i", &op);
                                        if(op==2)
                                        {
                                            voltandoparaomenu();
                                            system("pause");//caso a compra não seja bem sucedida, o pagamento é cancelado e volta para o menu de pagamento
                                            break;
                                        }


                                        ptr_dinheiros->dinheiro += ptr_dinheiros->dinheiro_pago; // o dinheiro pago então é constado na variável que conta o dinheiro em caixa

                                        ptr_dinheiros->cartao += ptr_dinheiros->dinheiro_cartao_restante; // o restante a ser pago em cartão é inserido na variável que conta a quantia de dinheiro paga em cartão

                                        printfcomprafinalizada(); //tela que mostra que a compra foi finalizada

                                        tipo_de_pagamento = 3; //o tipo de pagamento recebe o valor 3, que vai ser convertido depois para pagamento em dinheiro + cartão

                                        compra_finalizada_func(); //função presente sempre que a compra é finalizada

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
                                    //caso o desconto seja confirmado o calculo é feito e o total é descontado
                                    break;

                                case 5:
                                    lista_clientes_para_atribuicao();//se a bere quiser atribuir a venda a um cliente, está tela aparece (presente no arquivo clientes)
                                    break;
                                }
                            }
                            while(operador[8] != 6);
                        }
                        else
                        {
                            tela_nadafoicomprado(); //se nada estiver no carrinho, não é possível fazer o pagamento
                        }
                        break;
                    }
                }
                while(operador[2] != 5);
            }
            else
            {
                caixa_fechado_tela(); //se o caixa estiver fechado, não é possível entrar no menu de vendas
            }

            break;

        case 3:

            if(usuario_atual.nivel_de_controle == 1) //se o usuário atual for comum, não é possível abrir o caixa
            {
                if(caixa_fechado == 1) //se o caixa estiver fechado, é possível abrir ele
                {
                    tela_abertura_de_caixa(); //tela de abertura de caixa

                    caixa_fechado = 2; //após o caixa abrir, a variável "caixa_fechado" recebe o valor 2, que indica que o caixa está aberto
                }
                else
                {
                    caixa_ja_aberto_tela(); // se o caixa ja estiver aberto, não é possível abrir de novo
                }
            }
            else
            {
                acesso_negado();
            }
            break;

        case 4:

            if(usuario_atual.nivel_de_controle == 1) //se o usuário atual for comum, não é possível fechar o caixa
            {
                if(caixa_fechado != 1) // se o caixa estiver fechado, não é possível fechar ele
                {
                    fechamento_de_caixa_menu_tela(); //menu de fechamento de caixa, presente no arquivo TELA

                    if(caixa_fechado==1) //se o caixa foi fechado, uma confirmação aparecera na tela
                    {
                        confirmado_caixa_fechado(); //confimação de caixa fechado, presente no menu tela
                        goto main_rep;
                    }
                }
                else
                {
                    caixa_fechado_tela(); //se o caixa estiver fechado, esta tela aparecera, não deixando fecha-lo novamente
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
                relatorios_menu_tela(); //menu de relatórios

                scanf ("%i", &operador[6]);
                getchar();

                switch(operador[6])
                {
                case 1:
                    if(produtos_vendidos[0][0].ano != 0)//só entra no histórico se ja tiver vendido algo
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

