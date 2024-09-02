
void cadastros_produtos_menu_tela() //tela de cadastro de novos produtos
{
    system ("cls");
    printf ("\n\n\t======================================================\n");  //tela que confirma se vai ter cadastro ou n
    printf ("\t|                                                    |\n");
    printf ("\t|              1.2 Cadastro de produtos              |\n");
    printf ("\t|                                                    |\n");
    printf ("\t|                                                    |\n");
    printf ("\t|          Deseja cadastrar um novo produto?         |\n");
    printf ("\t|                                                    |\n");
    printf ("\t|                1- Sim         2- N�o               |\n");
    printf ("\t|                                                    |\n");
    printf ("\t======================================================\n\n");
    printf ("\t..::: Escolha uma das op��es:  ");

}


void cadastros_produtos_menu2_tela()
{
    int tamanhoCodigoDoProduto;
    setlocale(LC_ALL, "Portuguese");
    system ("cls");
    printf ("\n\n\t======================================================\n"); //tela onde ser� feito o cadastro dos dados de clientes
    printf ("\t|                                                    |\n");
    printf ("\t|              1.2 Cadastro de produtos              |\n");
    printf ("\t|                                                    |\n");
    printf ("\t======================================================\n\n");

repeticao_de_codigo:  //repeti��o da coloca��o de c�digo

    printf ("\t..::: C�DIGO:  ");
    fflush(stdin);
    scanf("%s",&produtos_salvos[contador_produtos].codigo);
    tamanhoCodigoDoProduto=strlen(produtos_salvos[contador_produtos].codigo);

    if(tamanhoCodigoDoProduto<4 || tamanhoCodigoDoProduto>4)
    {
        printf("\n\n\t..::: C�DIGO INCORRETO! Insira um c�digo de 4 digitos!\n\n\n");
        goto repeticao_de_codigo; //comando goto, presente para repetir
    }

    if( produtos_salvos[contador_produtos].codigo[0] != '1' )
    {
        printf("\n\n\t..::: O codigo do produto deve inicializar com o numero 1!\n\n\n");
        goto repeticao_de_codigo; //comando goto, presente para repetir
    }

    for(int i = 0; i < contador_produtos; i ++)
    {
        if (strcmp(produtos_salvos[contador_produtos].codigo, produtos_salvos[i].codigo) == 0)  //n�o deixa o atual codigo ser igual a de outro produto
        {
            printf("\n\n\t..::: C�DIGO INCORRETO! Mesmo c�digo que outro produto!\n\n\n");
            goto repeticao_de_codigo;  //comando goto, presente para repetir
        }
    }

    printf ("\n\n\t..::: DESCRI��O:  ");
    fflush(stdin);
    fgets(produtos_salvos[contador_produtos].descricao, 11, stdin);

    printf ("\n\n\t..::: CATEGORIA:  ");
    fflush(stdin);
    fgets(produtos_salvos[contador_produtos].categoria, 11, stdin);

    printf ("\n\n\t..::: PRE�O DE COMPRA:  ");
    fflush(stdin);
    scanf("%f", &produtos_salvos[contador_produtos].preco_de_compra);
    getchar();

    printf ("\n\n\t..::: MARGEM DE LUCRO (%%):  ");
    scanf("%i", &produtos_salvos[contador_produtos].margem_de_lucro);
    getchar();

    produtos_salvos[contador_produtos].preco_de_venda=produtos_salvos[contador_produtos].preco_de_compra+(produtos_salvos[contador_produtos].preco_de_compra*produtos_salvos[contador_produtos].margem_de_lucro/100);
    printf ("\n\n\t..::: PRE�O DE VENDA: %.2f \n",produtos_salvos[contador_produtos].preco_de_venda);

    printf ("\n\n\t..::: QUANTIDADE EM ESTOQUE:  ");
    scanf("%i", &produtos_salvos[contador_produtos].estoque_atual);
    getchar();

    printf ("\n\n\t..::: ESTOQUE M�NIMO:  ");
    scanf("%i", &produtos_salvos[contador_produtos].estoque_minimo);
    getchar();

    printf ("\n\n\t===============================================\n"); //comando de texto, inicio do menu
    printf ("\t|                                             |\n");
    printf ("\t|             Confirmar cadastro?             |\n");
    printf ("\t|                                             |\n");
    printf ("\t|            1- Sim         2- N�o            |\n");
    printf ("\t|                                             |\n");
    printf ("\t===============================================\n\n\n");
    printf ("\t..::: Escolha uma das op��es:  ");

    scanf("%i", &operador[12]);
    getchar();

    if(operador[12]==1)
    {
        produtos_salvos[contador_produtos].codigo[strcspn(produtos_salvos[contador_produtos].codigo, "\n")] = 0; //tira o ENTER do nome do produto, assim n�o bugando o menu de relat�rio -> lista de produtos
        produtos_salvos[contador_produtos].descricao[strcspn(produtos_salvos[contador_produtos].descricao, "\n")] = 0; //tira o ENTER do nome do produto, assim n�o bugando o menu de relat�rio -> lista de produtos
        produtos_salvos[contador_produtos].categoria[strcspn(produtos_salvos[contador_produtos].categoria, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu
        contador_produtos++; //aumenta a contagem de contador de produtos, para assim, no pr�ximo cadastro, cadastrar em outra posi��o do vetor
        produtos_salvar_em_arquivo(); //salva os dados em arquivo (fun��o presente no arquivo ARQUIVOS)
        produtos_salvos = (d_produtos *) realloc (produtos_salvos, ( (contador_produtos + 1) * sizeof(*produtos_salvos) ) ); //realoca a mem�ria do produtos salvos para assim conseguir salvar outro produto
        zerar_vendidos();
    }
}


void nao_ha_produtos_cadastrados_tela()
{
    system("cls");
    printf ("\n\n\t========================================\n");
    printf ("\t|                                      |\n");
    printf ("\t|     N�o h� produtos cadastrados!     |\n");
    printf ("\t|                                      |\n");
    printf ("\t========================================\n\n\n\t");
    system ("pause");
    system ("cls");
}



void lista_produtos_tela()
{
    if(contador_produtos >= 1)
    {
        system("cls");
        printf ("\n\n\t======================================\n");  //menu de lista de produtos cadastrados
        printf ("\t|                                    |\n");
        printf ("\t|        Produtos cadastrados        |\n");
        printf ("\t|                                    |\n");
        printf ("\t======================================");

        for(int i = 0; i < contador_produtos; i++)
        {
            produtos_salvos[i].codigo[strcspn(produtos_salvos[i].codigo, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu

            produtos_salvos[i].descricao[strcspn(produtos_salvos[i].descricao, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu

            produtos_salvos[i].categoria[strcspn(produtos_salvos[i].categoria, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu

            printf("\n\n\n\t..::: %s :::..", produtos_salvos[i].descricao);

            printf("\n\n\t..::: Categoria: %s", produtos_salvos[i].categoria);

            printf("\n\n\t..::: C�digo: %s", produtos_salvos[i].codigo);

            printf("\n\n\t..::: Pre�o de compra: %.2f ", produtos_salvos[i].preco_de_compra);

            printf("\n\n\t..::: Margem de lucro: %i%%", produtos_salvos[i].margem_de_lucro);

            printf("\n\n\t..::: Pre�o de venda: %.2f", produtos_salvos[i].preco_de_venda);

            printf("\n\n\t..::: Estoque atual: %i", produtos_salvos[i].estoque_atual);

            printf("\n\n\t..::: Estoque m�nimo: %i\n\n\n", produtos_salvos[i].estoque_minimo);

            system("pause");
        }
    }
    else
    {
        nao_ha_produtos_cadastrados_tela();
    }
}

void produtos_ler_do_arquivo() //fun��o de ler o arquivo para utilizar produtos ja salvos antes, utilizado sempre que a bere for aberta
{
    setlocale(LC_ALL, "Portuguese");
    FILE *arq = fopen ("produtos.txt", "r");                          //FILE: fun��o de arquivo          //fopen: file open (abrir arquivo)
    if(arq) //se o arq existir (se o produtos.txt existir)            //*arq: referencia o local da mem�ria onde vai ser armazenado o aquivo,  produtos.txt: nome do arquivo
    {
        //r: read (ler), fun��o de ler o arquivo e passar as informa��es dele para as vari�veis do programa

        produtos_temp = (d_produtos *) malloc (sizeof(*produtos_salvos)); //aloca��o de mem�ria para os produtos carregados
        contador_produtos = 1; //contador de produtos recebe o valor 1, para o for conseguir rodar
        produtos_salvos = (d_produtos *) malloc ( (contador_produtos + 1) * sizeof(*produtos_salvos)); //aloca��o de mem�ria para os produtos salvos (aonde ser�o inseridos todos os produtos)

        for(int i=0; i<=contador_produtos; i++)
        {
            fscanf(arq, "%i\n", &contador_produtos);
            fscanf(arq, "%4s\n", &produtos_temp->codigo);             //fscanf: FILE scanf, fun��o de ler dados do arquivo e colocalos dentro de uma var�avel do programa
            fgets(produtos_temp->descricao, 12, arq);         //(arq (de onde est� sendo lido), "%i" (tipo de dado lido), produtos_temp (qual dado ser� gravado))
            fscanf(arq, "%f\n", &produtos_temp->preco_de_compra);
            fscanf(arq, "%i\n", &produtos_temp->margem_de_lucro);
            fscanf(arq, "%f\n", &produtos_temp->preco_de_venda);
            fscanf(arq, "%i\n", &produtos_temp->estoque_atual);
            fscanf(arq, "%i\n", &produtos_temp->estoque_minimo);
            fgets(produtos_temp->categoria, 12, arq);         //(arq (de onde est� sendo lido), "%i" (tipo de dado lido), produtos_temp (qual dado ser� gravado))
            produtos_temp->codigo[strcspn(produtos_temp->codigo, "\n")] = 0; //linha de c�digo para tirar o ENTER (\n) depois da string
            produtos_temp->descricao[strcspn(produtos_temp->descricao, "\n")] = 0; //linha de c�digo para tirar o ENTER (\n) depois da string
            produtos_temp->categoria[strcspn(produtos_temp->categoria, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu
            produtos_salvos[i] = *produtos_temp; //os produtos carregados s�o posicionados dentro da vari�vel de produtos salvos, assim salvando os dados de produtos
            produtos_salvos = (d_produtos *) realloc (produtos_salvos, ( (contador_produtos + 1) * sizeof(*produtos_salvos) ) );
            //ap�s salvar os produtos, � realocado mais uma posi��o de mem�ria para salvar mais produtos
        }
        fclose(arq); //fclose: FILEclose (fechar arquivo), � necess�rio fechar um arquivo sempre ap�s que ele for aberto
    }
    else //se o produto.txt n�o existir, isso acontece
    {
        produtos_temp = (d_produtos *) malloc (sizeof(*produtos_salvos));  //� alocada mem�ria para os produtos carregados
        produtos_salvos = (d_produtos *) malloc ( 1 * sizeof(*produtos_salvos)); //� alocada mem�ria para os produtos salvos (para assim conseguir salvar novos produtos)
    }
}

void produtos_salvar_em_arquivo() //fun��o de salvar dados no arquivo, usada sempre que um novo arquivo for inserido no c�digo
{
    setlocale(LC_ALL,"Portuguese");
    FILE *arq = fopen ("produtos.txt", "w");   //FILE: fun��o de arquivo          //fopen: file open (abrir arquivo)
    if(arq)                                    //*arq: referencia o local da mem�ria onde vai ser armazenado o aquivo,  produtos.txt: nome do arquivo
    {
        //w: write (escrever), escrever no arquivo (w apaga tudo oque est� escrito e escreve de novo)
        for(int i = 0; i<=contador_produtos; i++)
        {
            fprintf(arq, "%i\n", contador_produtos);
            fprintf(arq, "%4s\n", produtos_salvos[i].codigo);
            fprintf(arq, "%s\n", produtos_salvos[i].descricao);
            fprintf(arq, "%.2f\n", produtos_salvos[i].preco_de_compra);  //fprintf: FILEprintf, utilizado para escrever dentro do arquivo
            fprintf(arq, "%i\n", produtos_salvos[i].margem_de_lucro);
            fprintf(arq, "%.2f\n", produtos_salvos[i].preco_de_venda);
            fprintf(arq, "%i\n", produtos_salvos[i].estoque_atual);
            fprintf(arq, "%i\n", produtos_salvos[i].estoque_minimo);
            fprintf(arq, "%s\n", produtos_salvos[i].categoria);
        }
        fclose(arq); //fclose: FILEclose (fechar arquivo), � necess�rio fechar um arquivo sempre ap�s que ele for aberto
    }
    else //caso n�o for poss�vel criar o arquivo ou salvar dentro do arquivo, este erro aparece
    {
        printf("\n\tErro ao salvar produtos! (ERRO 2)\n");
        system("pause");
    }
}

void alterar_produtos_confirmar(int i)
{
    printf ("\n\n\t===============================================\n"); //comando de texto, inicio do menu
    printf ("\t|                                             |\n");
    printf ("\t|            Confirmar altera��o?             |\n");
    printf ("\t|                                             |\n");
    printf ("\t|            1- Sim         2- N�o            |\n");
    printf ("\t|                                             |\n");
    printf ("\t===============================================\n\n\n");
    printf ("\t..::: Escolha uma das op��es:  ");

    scanf("%i", &operador[12]);
    getchar();

    if(operador[12]==1)
    {
        produtos_salvos[i] = *produtos_temp;
        produtos_salvar_em_arquivo(); //salva os dados em arquivo (fun��o presente no arquivo ARQUIVOS)
    }
}


void alterar_produtos_menu2_tela() //tela de altera��o de produtos
{
    int tamanhoCodigoDoProduto;
    int op;
    system ("cls");
    printf ("\n\n\t======================================================================================================\n");  //tela que confirma se vai ter cadastro ou n
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                    1.3 Alterar dados de produtos                                   |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|    Item (c�digo) |     Nome do Item      |       Categoria       |  Valor (Unidade)  |  Estoque    |\n");
    printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
    lista_de_produtos_func();
    printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|          8 Voltar ao Menu Principal                                                                |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t======================================================================================================\n");
    printf ("\n\t..::: Insira o c�digo de um produto para alterar seus dados:  ");
    fflush(stdin);
    scanf("%s", &codigo_de_produtos);

    for(int i = 0; i<contador_produtos; i++)
    {
        if(strcmp(codigo_de_produtos, produtos_salvos[i].codigo)==0)  //inicia um for de todos os produtos, se o produto tiver o c�digo igual ao digitado, ent�o ele aparecer� e os outros n�o
        {
            *produtos_temp = produtos_salvos[i];
            int op;
            printf ("\n\n\t========================================\n");
            printf ("\t|                                      |\n");
            printf ("\t|  Produto selecionado:%11s     |\n", produtos_salvos[i].descricao);
            printf ("\t|                                      |\n");
            printf ("\t========================================\n");
            printf ("\t|                                      |\n");
            printf ("\t|   Qual dado ser� alterado?           |\n");
            printf ("\t|                                      |\n");
            printf ("\t|   1 - C�digo                         |\n");
            printf ("\t|                                      |\n");
            printf ("\t|   2 - Descri��o                      |\n");
            printf ("\t|                                      |\n");
            printf ("\t|   3 - Categoria                      |\n");
            printf ("\t|                                      |\n");
            printf ("\t|   4 - Margem de lucro (%i %%)        \n", produtos_salvos[i].margem_de_lucro);
            printf ("\t|                                      |\n");
            printf ("\t|   5 - Pre�o de compra (R$ %.2f)      \n", produtos_salvos[i].preco_de_compra);
            printf ("\t|                                      |\n");
            printf ("\t|   7 - Estoque m�nimo (%i)            \n", produtos_salvos[i].estoque_minimo);
            printf ("\t|                                      |\n");
            printf ("\t========================================\n");
            scanf("%i", &op);
            getchar();

            switch(op)
            {

            case 1:

repeticao_de_codigo:  //repeti��o da coloca��o de c�digo

                printf ("\t..::: C�DIGO:  ");
                fflush(stdin);
                fgets(produtos_salvos[contador_produtos].codigo, 5, stdin);
                tamanhoCodigoDoProduto=strlen(produtos_salvos[contador_produtos].codigo);

                if(tamanhoCodigoDoProduto<4 || tamanhoCodigoDoProduto>4)
                {
                    printf("\n\n\t..::: C�DIGO INCORRETO! Insira um c�digo de 4 digitos!\n\n\n");
                    goto repeticao_de_codigo; //comando goto, presente para repetir
                }

                if( produtos_salvos[contador_produtos].codigo[0] != '1' )
                {
                    printf("\n\n\t..::: O codigo do produto deve inicializar com o numero 1!\n\n\n");
                    goto repeticao_de_codigo; //comando goto, presente para repetir
                }

                for(int i = 0; i < contador_produtos; i ++)
                {
                    if (strcmp(produtos_salvos[contador_produtos].codigo, produtos_salvos[i].codigo) == 0)  //n�o deixa o atual codigo ser igual a de outro produto
                    {
                        printf("\n\n\t..::: C�DIGO INCORRETO! Mesmo c�digo que outro produto!\n\n\n");
                        goto repeticao_de_codigo;  //comando goto, presente para repetir
                    }
                }
                produtos_salvos[i].codigo[strcspn(produtos_salvos[i].codigo, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu
                alterar_produtos_confirmar(i);
                break;

            case 2:
                printf ("\n\n\t..::: DESCRI��O:  ");
                fflush(stdin);
                fgets(produtos_temp->descricao, 11, stdin);
                produtos_temp->descricao[strcspn(produtos_temp->descricao, "\n")] = 0; //tira o ENTER do nome do produto, assim n�o bugando o menu de relat�rio -> lista de produtos
                alterar_produtos_confirmar(i);
                break;

            case 3:
                printf ("\n\n\t..::: CATEGORIA:  ");
                fflush(stdin);
                fgets(produtos_temp->categoria, 11, stdin);
                produtos_temp->categoria[strcspn(produtos_temp->categoria, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu
                alterar_produtos_confirmar(i);
                break;

            case 5:
                printf ("\n\n\t..::: PRE�O DE COMPRA:  ");
                fflush(stdin);
                scanf("%f", &produtos_temp->preco_de_compra);
                getchar();
                produtos_temp->preco_de_venda = produtos_temp->preco_de_compra + (produtos_temp->preco_de_compra*produtos_salvos[i].margem_de_lucro/100);
                alterar_produtos_confirmar(i);
                break;

            case 4:
                printf ("\n\n\t..::: MARGEM DE LUCRO:  ");
                scanf("%i", &produtos_temp->margem_de_lucro);
                getchar();
                produtos_temp->preco_de_venda = produtos_salvos[i].preco_de_compra + (produtos_salvos[i].preco_de_compra*produtos_temp->margem_de_lucro/100);
                alterar_produtos_confirmar(i);
                break;


            case 7:
                printf ("\n\n\t..::: ESTOQUE M�NIMO:  ");
                scanf("%i", &produtos_temp->estoque_minimo);
                getchar();
                alterar_produtos_confirmar(i);
                break;

            }
        }
    }
}



void alterar_produtos_menu_tela()
{
    int op;
    system ("cls");
    printf ("\n\n\t=======================================================\n");  //tela que confirma se vai ter cadastro ou n
    printf ("\t|                                                     |\n");
    printf ("\t|            1.3 Alterar dados de produtos            |\n");
    printf ("\t|                                                     |\n");
    printf ("\t|                                                     |\n");
    printf ("\t|        Deseja alterar os dados de um produto?       |\n");
    printf ("\t|                                                     |\n");
    printf ("\t|                1- Sim         2- N�o                |\n");
    printf ("\t|                                                     |\n");
    printf ("\t=======================================================\n\n");
    printf ("\t..::: Escolha uma das op��es:  ");
    scanf("%i", &op);
    getchar();

    if(op == 1)
    {
        alterar_produtos_menu2_tela();
    }
}

void alterar_estoque_menu_tela()
{

    system ("cls");
    printf ("\n\n\t======================================================================================================\n");  //tela que confirma se vai ter cadastro ou n
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                   1.4 Alterar estoque de produtos                                  |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|    Item (c�digo) |     Nome do Item      |       Categoria       |  Valor (Unidade)  |  Estoque    |\n");
    printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
    lista_de_produtos_func();
    printf ("\t|   ---------------|-----------------------|-----------------------|-------------------|----------   |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t|          8 Voltar ao Menu Principal                                                                |\n");
    printf ("\t|                                                                                                    |\n");
    printf ("\t======================================================================================================\n");
    printf ("\n\t..::: Insira o c�digo de um produto para alterar seus dados:  ");
    fflush(stdin);
    scanf("%s", &codigo_de_produtos);

    for(int i = 0; i<contador_produtos; i++)
    {
        if(strcmp(codigo_de_produtos, produtos_salvos[i].codigo)==0)  //inicia um for de todos os produtos, se o produto tiver o c�digo igual ao digitado, ent�o ele aparecer� e os outros n�o
        {
            *produtos_temp = produtos_salvos[i];
            int op;
            printf ("\n\n\t========================================\n");
            printf ("\t|                                      |\n");
            printf ("\t|  Produto selecionado:%11s     |\n", produtos_salvos[i].descricao);
            printf ("\t|                                      |\n");
            printf ("\t========================================\n");
            printf ("\t|                                      |\n");
            printf ("\t|      Deseja alterar seu estoque?     |\n");
            printf ("\t|                                      |\n");
            printf ("\t|       1 - Sim          2 - N�o       |\n");
            printf ("\t|                                      |\n");
            printf ("\t========================================\n");
            printf ("\t..:::Digite sua resposta:  ");
            scanf("%i", &op);
            getchar();

            if(op==2)
            {
            break;
            }

            printf("\n\n\t..::: Novo estoque:  ");
            scanf("%i", &produtos_temp->estoque_atual);
            getchar();
            alterar_produtos_confirmar(i);
        }
    }
}

void pesquisarProdutoCodigo(){
int codigoEncontradoProduto=0;
char procuraCodigoProduto[5];
int tamanhoprocuraCodigoProduto;
system("cls");
repeticao_procuraCodigoProduto:
printf("..::: Informe o codigo do produto desejado : ");
scanf("%s",&procuraCodigoProduto);
tamanhoprocuraCodigoProduto=strlen(procuraCodigoProduto);
if(tamanhoprocuraCodigoProduto<4 || tamanhoprocuraCodigoProduto>4){
    printf("\n\n..::: C�DIGO INCORRETO! Insira um c�digo de 4 digitos!\n\n\n");
    goto repeticao_procuraCodigoProduto; //comando goto, presente para repetir
    system("pause");
}
if(procuraCodigoProduto[0]!='1'){
    printf("\n\n..::: O codigo do produto deve inicializar com o numero 1!\n\n\n");
    goto repeticao_procuraCodigoProduto; //comando goto, presente para repetir
    system("pause");
}

for(int i = 0; i < contador_produtos; i ++){
    if(strcmp(produtos_salvos[i].codigo, procuraCodigoProduto) == 0){
            codigoEncontradoProduto=1;
            printf("\n..::: Produto encontrado!\n");
            produtos_salvos[i].codigo[strcspn(produtos_salvos[i].codigo, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu
            produtos_salvos[i].descricao[strcspn(produtos_salvos[i].descricao, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu
            produtos_salvos[i].categoria[strcspn(produtos_salvos[i].categoria, "\n")] = 0; //tira o ENTER do nome do produto para n�o bugar o menu
            printf("\n\n..::: %s :::..", produtos_salvos[i].descricao);
            printf("\n\n..::: Categoria: %s", produtos_salvos[i].categoria);
            printf("\n\n..::: C�digo: %s", produtos_salvos[i].codigo);
            printf("\n\n..::: Pre�o de compra: %.2f ", produtos_salvos[i].preco_de_compra);
            printf("\n\n..::: Margem de lucro: %i%%", produtos_salvos[i].margem_de_lucro);
            printf("\n\n..::: Pre�o de venda: %.2f", produtos_salvos[i].preco_de_venda);
            printf("\n\n..::: Estoque atual: %i", produtos_salvos[i].estoque_atual);
            printf("\n\n..::: Estoque m�nimo: %i\n\n\n", produtos_salvos[i].estoque_minimo);
            system("pause");
            break;
    }
}
if(!codigoEncontradoProduto){
    printf("\n..::: Nao existem produtos com esse codigo!\n\n\n");
    system("pause");
}

}

int compararProdutos(const void *a, const void *b) {
    d_produtos *produtoA = (d_produtos *)a;
    d_produtos *produtoB = (d_produtos *)b;
    return strcmp(produtoA->descricao, produtoB->descricao);
}

void listarProdutosOrdemAlfabetica(d_produtos produtos[], int numProdutos) {
    qsort(produtos, numProdutos, sizeof(d_produtos), compararProdutos);
    system("cls");
    printf("\t..::: Lista de produtos em ordem alfabetica:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("\n..::: Codigo: %s\n", produtos[i].codigo);
        printf("..::: Descricao: %s\n", produtos[i].descricao);
        printf("..::: Preco de Compra: %.2f\n", produtos[i].preco_de_compra);
        printf("..::: Margem de Lucro: %d\n", produtos[i].margem_de_lucro);
        printf("..::: Preco de Venda: %.2f\n", produtos[i].preco_de_venda);
        printf("..::: Estoque Atual: %d\n", produtos[i].estoque_atual);
        printf("..::: Estoque Minimo: %d\n", produtos[i].estoque_minimo);
        printf("..::: Categoria: %s\n", produtos[i].categoria);
        printf("\n\n");
        system("pause");
    }
}
