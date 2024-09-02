


void cadastros_clientes_menu_tela()
{
    system ("cls");
    printf ("\n\n\t======================================================\n"); //tela que confirma se vai ter cadastro ou n
    printf ("\t|                                                    |\n");
    printf ("\t|              1.1 Cadastro de clientes              |\n");
    printf ("\t|                                                    |\n");
    printf ("\t|                                                    |\n");
    printf ("\t|          Deseja cadastrar um novo cliente?         |\n");
    printf ("\t|                                                    |\n");
    printf ("\t|                1- Sim         2- Não               |\n");
    printf ("\t|                                                    |\n");
    printf ("\t======================================================\n\n");
    printf ("\t..::: Escolha uma das opções:  ");

}

void cadastros_clientes_menu2_tela()
{
    int tamanhoCPF;
    int tamanhoCodigoDoCliente;
    system ("cls");
    printf ("\n\n\t======================================================\n"); //tela onde será feito o cadastro dos dados de clientes
    printf ("\t|                                                    |\n");
    printf ("\t|              1.1 Cadastro de clientes              |\n");
    printf ("\t|                                                    |\n");
    printf ("\t======================================================\n\n");

    printf ("\t..::: NOME COMPLETO:  ");
    fflush(stdin);
    fgets(clientes_salvos[contador_clientes].nome_completo, 200, stdin);

    clientes_salvos[contador_clientes].nome_completo[strcspn(clientes_salvos[contador_clientes].nome_completo, "\n")] = 0; //tira o ENTER do nome do cliente, assim não bugando o menu de relatório -> lista de clientes

    printf ("\n\n\t..::: NOME SOCIAL:  ");
    fflush(stdin);
    fgets(clientes_salvos[contador_clientes].nome_social, 50, stdin);

    do
    {
        printf ("\n\n\t..::: CPF [xxx.xxx.xxx-xx] :  ");
        scanf("%s",&clientes_salvos[contador_clientes].cpf);
        getchar();
        tamanhoCPF=strlen(clientes_salvos[contador_clientes].cpf);
        if(tamanhoCPF!=14 || clientes_salvos[contador_clientes].cpf[3]!='.' || clientes_salvos[contador_clientes].cpf[7]!='.' || clientes_salvos[contador_clientes].cpf[11]!='-')
        {
            printf("\n\n\t..::: CPF invalido, siga este modelo [xxx.xxx.xxx-xx]!\n");
        }
        else
            break;
    }
    while(tamanhoCPF!=14 || clientes_salvos[contador_clientes].cpf[3]!='.' || clientes_salvos[contador_clientes].cpf!='.' || clientes_salvos[contador_clientes].cpf!='-');

    printf ("\n\n\t..::: RUA:  ");
    fflush(stdin);
    fgets(clientes_salvos[contador_clientes].rua, 200, stdin);

    printf ("\n\n\t..::: NÚMERO DA CASA:  ");
    scanf("%i", &clientes_salvos[contador_clientes].numero_da_casa);
    getchar();

    printf ("\n\n\t..::: BAIRRO:  ");
    fflush(stdin);
    fgets(clientes_salvos[contador_clientes].bairro, 200, stdin);


    printf ("\n\n\t..::: NÚMERO PARA CONTATO:  ");
    scanf("%lli", &clientes_salvos[contador_clientes].numero_para_contato);
    getchar();

repeticao_de_codigoClientes:  //repetição da colocação de código do cliente

    printf ("\n\n\t..::: CÓDIGO PARA O CLIENTE :  ");
    scanf("%s",&clientes_salvos[contador_clientes].codigoCliente);
    getchar();
    tamanhoCodigoDoCliente=strlen(clientes_salvos[contador_clientes].codigoCliente);

    if(tamanhoCodigoDoCliente<4 || tamanhoCodigoDoCliente>4)
    {
        printf("\n\n\t..::: CÓDIGO INCORRETO! Insira um código de 4 digitos!\n\n\n");
        goto repeticao_de_codigoClientes; //comando goto, presente para repetir
    }

    if( clientes_salvos[contador_clientes].codigoCliente[0] != '1' )
    {
        printf("\n\n\t..::: O codigo do cliente deve inicializar com o numero 1!\n\n\n");
        goto repeticao_de_codigoClientes; //comando goto, presente para repetir
    }

    for(int i = 0; i < contador_clientes; i ++)
    {
        if (strcmp(clientes_salvos[contador_clientes].codigoCliente, clientes_salvos[i].codigoCliente) == 0)  //não deixa o atual codigo ser igual a de outro cliente
        {
            printf("\n\n\t..::: CÓDIGO INCORRETO! Mesmo código que outro cliente!\n\n\n");
            goto repeticao_de_codigoClientes;  //comando goto, presente para repetir
        }
    }

    printf ("\n\n\t===============================================\n"); //CONFIRMAÇAO de cadastro
    printf ("\t|                                             |\n");
    printf ("\t|             Confirmar cadastro?             |\n");
    printf ("\t|                                             |\n");
    printf ("\t|            1- Sim         2- Não            |\n");
    printf ("\t|                                             |\n");
    printf ("\t===============================================\n\n");
    printf ("\t..::: Escolha uma das opções:  ");

    scanf("%i", &operador[12]);
    getchar();

    if(operador[12]==1) //se o cadastro for confirmado
    {
        clientes_salvos[contador_clientes].id = contador_clientes + 1; //atribui um código ao cliente
        contador_clientes++;  //o contador de clientes sobe (para conseguir salvar mais um cliente
        clientes_salvar_em_arquivo();  //o cliente é salvo em um arquivo (função presente no arquivo ARQUIVOS)
        clientes_salvos = (d_clientes *) realloc (clientes_salvos, ( (contador_clientes + 1) * sizeof(*clientes_salvos) ) ); //a memória do ponteiro de struct é realocada, para assim conseguirem ser salvos mais clientes
    }
}

void clientes_salvar_em_arquivo() //função de salvar clientes no arquivo, usado no arquivo TELA
{
    setlocale(LC_ALL,"Portuguese");
    FILE *arq = fopen ("clientes.txt", "w");      //FILE: função de arquivo          //fopen: file open (abrir arquivo)
    if(arq)                                       //*arq: referencia o local da memória onde vai ser armazenado o aquivo,  clientes.txt: nome do arquivo
    {
        //w: write (escrever), escrever no arquivo (w apaga tudo oque está escrito e escreve de novo)
        for(int i = 0; i<contador_clientes; i++)
        {
            fprintf(arq, "%i\n", contador_clientes);
            fprintf(arq, "%i\n", clientes_salvos[i].id);
            fprintf(arq, "%s\n", clientes_salvos[i].nome_completo);
            fprintf(arq, "%s", clientes_salvos[i].nome_social);
            fprintf(arq, "%s\n", clientes_salvos[i].cpf);
            fprintf(arq, "%s", clientes_salvos[i].rua);
            fprintf(arq, "%s", clientes_salvos[i].bairro);
            fprintf(arq, "%i\n", clientes_salvos[i].numero_da_casa);
            fprintf(arq, "%lli\n", clientes_salvos[i].numero_para_contato);
            fprintf(arq, "%4s", clientes_salvos[i].codigoCliente);
        }
        fclose(arq); //fclose: FILEclose (fechar arquivo), é necessário fechar um arquivo sempre após que ele for aberto
    }
    else  //caso não for possível criar o arquivo ou salvar dentro do arquivo, este erro aparece
    {
        printf("\n\tErro ao salvar cadastros! (ERRO 4)\n");
        system("pause");
    }
}


void clientes_ler_do_arquivo()  //função de ler o arquivo para utilizar produtos ja salvos antes, utilizado sempre que a bere for aberta
{
    setlocale(LC_ALL, "Portuguese");
    FILE *arq = fopen ("clientes.txt", "r");   //FILE: função de arquivo          //fopen: file open (abrir arquivo)
    if(arq)                                    //*arq: referencia o local da memória onde vai ser armazenado o aquivo,  produtos.txt: nome do arquivo
    {
        //r: read (ler), função de ler o arquivo e passar as informações dele para as variáveis do programa

        clientes_temp = (d_clientes *) malloc (sizeof(*clientes_temp));  //alocação de memória para os clientes carregados
        contador_clientes = 1;  //contador de clientes recebe o valor 1, para o for conseguir rodar
        clientes_salvos = (d_clientes *) malloc ((contador_clientes + 1) * sizeof(*clientes_salvos)); //alocação de memória para os clientes salvos (aonde serão inseridos todos os clientes)

        for(int i=0; i<=contador_clientes; i++)
        {
            fscanf(arq, "%i\n", &contador_clientes);
            fscanf(arq, "%i\n", &clientes_temp->id);
            fgets(clientes_temp->nome_completo, 200, arq);
            fgets(clientes_temp->nome_social, 50, arq);
            fscanf(arq, "%s\n", &clientes_temp->cpf);
            fgets(clientes_temp->rua, 200, arq);
            fgets(clientes_temp->bairro, 200, arq);
            fscanf(arq, "%i\n", &clientes_temp->numero_da_casa);
            fscanf(arq, "%lli\n", &clientes_temp->numero_para_contato);
            fscanf(arq, "%4s\n", &clientes_temp->codigoCliente);
            clientes_salvos[i] = *clientes_temp;
            clientes_salvos = (d_clientes *) realloc (clientes_salvos, ( (contador_clientes + 1) * sizeof(*clientes_salvos) ) );
        }
        fclose(arq); //fclose: FILEclose (fechar arquivo), é necessário fechar um arquivo sempre após que ele for aberto
    }
    else //se o cliente.txt não existir, isso acontece
    {
        clientes_temp = (d_clientes *) malloc (sizeof(*clientes_temp)); //é alocada memória para os clientes carregados
        clientes_salvos = (d_clientes *) malloc ( 1 * sizeof(*clientes_salvos));    //é alocada memória para os clientes salvos (para assim conseguir salvar novos clientes)
    }
}

void nao_ha_clientes_cadastrados_tela()
{
    system("cls");
    printf ("\n\n\t========================================\n");
    printf ("\t|                                      |\n");
    printf ("\t|     Não há clientes cadastrados!     |\n");
    printf ("\t|                                      |\n");
    printf ("\t========================================\n\n\n\t");
    system ("pause");
    system ("cls");
}

void lista_clientes_tela()
{
    if(contador_clientes >= 1)
    {
        system("cls");
        printf ("\n\n\t======================================\n");  //lista de clientes cadastrados
        printf ("\t|                                    |\n");
        printf ("\t|        Clientes cadastrados        |\n");
        printf ("\t|                                    |\n");
        printf ("\t======================================");

        for(int i = 0; i < contador_clientes; i++)
        {

            clientes_salvos[i].nome_completo[strcspn(clientes_salvos[i].nome_completo, "\n")] = 0;  //tira o ENTER do nome do cliente, para não bugar o menu

            printf("\n\n\n\t..::: [%i] %s :::..",clientes_salvos[i].id, clientes_salvos[i].nome_completo);

            printf("\n\n\t..::: Nome social: %s ", clientes_salvos[i].nome_social);

            printf("\n\t..::: CPF: %s", clientes_salvos[i].cpf);

            printf("\n\n\t..::: Rua: %s", clientes_salvos[i].rua);

            printf("\n\t..::: Bairro: %s", clientes_salvos[i].bairro);

            printf("\n\t..::: Número da casa: %i", clientes_salvos[i].numero_da_casa);

            printf("\n\n\t..::: Número para contato: %lli\n\n", clientes_salvos[i].numero_para_contato);

            printf("\t..::: Codigo cliente: %s", clientes_salvos[i].codigoCliente);

            printf("\n\n");

            system("pause");
        }
    }
    else
    {
        nao_ha_clientes_cadastrados_tela();
    }
}


void lista_clientes_para_atribuicao()
{
    if(contador_clientes >= 1)
    {
        int op,op2;
        system("cls");
        printf ("\n\n\t=====================================\n");  //lista de clientes cadastrados
        printf ("\t|                                   |\n");
        printf ("\t|         Lista de clientes         |\n");
        printf ("\t|                                   |\n");
        printf ("\t=====================================\n");

        for(int i = 0; i < contador_clientes; i++)
        {
            clientes_salvos[i].nome_completo[strcspn(clientes_salvos[i].nome_completo, "\n")] = 0;  //tira o ENTER do nome do cliente, para não bugar o menu

            printf("\n\n\t..::: [%i] %s :::..",clientes_salvos[i].id, clientes_salvos[i].nome_completo);
        }

        printf("\n\n\n\t..::: Selecione um cliente para atribuir:  ");
        scanf("%i", &op);

        for(int i = 0; i < contador_clientes; i++)
        {
            if(op == clientes_salvos[i].id)
            {
                system("cls");
                printf("\n\n\t..::: Cliente selecionado: %s :::..\n", clientes_salvos[i].nome_completo);
                printf("\n\t..::: Digite 1 para confimar:  ");
                scanf("%i", &op2);
                if(op2 == 1)
                {
                    for(int ii = 0; ii<contador_produtos; ii++)
                    {
                        produtos_carrinho[ii].cod_cliente = clientes_salvos[i].id;
                    }
                }
            }
        }

    }
    else
    {
        nao_ha_clientes_cadastrados_tela();
    }
}

void pesquisarClienteCodigo(){
int codigoEncontradoCliente=0;
char procuraCodigo[5];
int tamanhoprocuraCodigo;
system("cls");
repeticao_procuraCodigo:
printf("..::: Informe o codigo do cliente desejado : ");
scanf("%s",&procuraCodigo);
tamanhoprocuraCodigo=strlen(procuraCodigo);
if(tamanhoprocuraCodigo<4 || tamanhoprocuraCodigo>4){
    printf("\n..::: CÓDIGO INCORRETO! Insira um código de 4 digitos!\n\n\n");
    goto repeticao_procuraCodigo; //comando goto, presente para repetir
    system("pause");
}
if(procuraCodigo[0]!='1'){
    printf("\n..::: O codigo do cliente deve inicializar com o numero 1!\n\n\n");
    goto repeticao_procuraCodigo; //comando goto, presente para repetir
    system("pause");
}

for(int i = 0; i < contador_clientes; i ++){
    if(strcmp(clientes_salvos[i].codigoCliente, procuraCodigo) == 0){
            codigoEncontradoCliente=1;
            printf("\n..::: Cliente encontrado!");
            clientes_salvos[i].nome_completo[strcspn(clientes_salvos[i].nome_completo, "\n")] = 0;  //tira o ENTER do nome do cliente, para não bugar o menu
            printf("\n\n\n..::: [%i] %s :::..",clientes_salvos[i].id, clientes_salvos[i].nome_completo);
            printf("\n\n..::: Nome social: %s ", clientes_salvos[i].nome_social);
            printf("\n..::: CPF: %s", clientes_salvos[i].cpf);
            printf("\n\n..::: Rua: %s", clientes_salvos[i].rua);
            printf("\n..::: Bairro: %s", clientes_salvos[i].bairro);
            printf("\n..::: Número da casa: %i", clientes_salvos[i].numero_da_casa);
            printf("\n\n..::: Número para contato: %lli\n", clientes_salvos[i].numero_para_contato);
            printf("\n..::: Codigo cliente: %s\n\n", clientes_salvos[i].codigoCliente);
            system("pause");
            break;
    }
}
if(!codigoEncontradoCliente){
    printf("\n..::: Nao existem clientes com esse codigo!\n\n\n");
    system("pause");
}

}
                                                                     // Indica que a função retorna um inteiro. Este inteiro indicará a ordem relativa entre os dois clientes
int compararClientes(const void *a, const void *b) {                 // **const void a, const void b São ponteiros genéricos para os dois elementos a serem comparados
    d_clientes *clienteA = (d_clientes *)a;                          // O uso de void * permite que a função seja usada para comparar qualquer tipo de dados
    d_clientes *clienteB = (d_clientes *)b;                          // const indica que a função não modificará os dados apontados por esses ponteiros
    return strcmp(clienteA->nome_completo, clienteB->nome_completo); // Compara os nomes completos dos dois clientes ai retorna um valor negativo se a primeira string (nome de clienteA) é lexicograficamente menor que a segunda (nome de clienteB)
}                                                                    //Zero se as strings são iguais ou um valor positivo se a primeira string é maior que a segunda

void listarClientesOrdemAlfabetica(d_clientes clientes[], int numClientes) { //d_clientes clientes[]: Um array de estruturas d_clientes. Representa a lista de clientes que será ordenada e exibida
    qsort(clientes, numClientes, sizeof(d_clientes), compararClientes);      //int numClientes: Um inteiro que representa o número de clientes no array
    system("cls");                                                           //qsort: Função da biblioteca padrão C stdlib.h que ordena um array genérico
    printf("\t..:::Lista de clientes em ordem alfabetica:\n");                 //clientes: Ponteiro para o início do array que será ordenado
    for (int i = 0; i < numClientes; i++) {                                    //numClientes: Número de elementos no array
        printf("\n..::: Nome Completo: %s", clientes[i].nome_completo);         //sizeof(d_clientes): Tamanho de cada elemento no array (em bytes)
        printf("..::: Nome Social: %s", clientes[i].nome_social);
        printf("..::: CPF: %s\n", clientes[i].cpf);
        printf("..::: Rua: %s", clientes[i].rua);
        printf("..::: Numero da Casa: %d\n", clientes[i].numero_da_casa);
        printf("..::: Bairro: %s", clientes[i].bairro);
        printf("..::: Numero para Contato: %lld\n", clientes[i].numero_para_contato);
        printf("..::: Codigo Cliente: %s\n", clientes[i].codigoCliente);
        printf("\n\n");
        system("pause");
    }
}
