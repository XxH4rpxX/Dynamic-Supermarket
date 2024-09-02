
typedef struct
{
    int id;
    char login[20];
    char senha[20];
    int nivel_de_controle;
} d_usuarios; //struct de usuários

d_usuarios *usuarios;
d_usuarios usuario_atual;
int contador_usuarios = 0;
int logado = 0;



void salvarUsuarios()//função de salvar os usuários em arquivo
{
    FILE *arq = fopen("usuarios.txt", "w");
    if(arq)
    {
        for(int i = 0; i < contador_usuarios; i++)
        {
            fprintf(arq, "%i\n", contador_usuarios);
            fprintf(arq, "%i\n", usuarios[i].id);
            fprintf(arq, "%s\n", usuarios[i].login);
            fprintf(arq, "%s\n", usuarios[i].senha);
            fprintf(arq, "%i\n", usuarios[i].nivel_de_controle);
        }
        fclose(arq);
    }
    else
    {
        printf("\n\tErro ao salvar os usuarios!\n");
        system("pause");
    }
}

void lerSenha(char *senha)
{
    char ch; // Declaracao de variavel para armazenar o caractere lido
    int i=0; // Declaracao de indice para acompanhar a posicao atual do vetor de caracteres
    while(1)  // Inicia um loop infinito
    {
        ch=getch(); // Lê um caractere sem exibi-lo na tela
        if(ch==13)   // Se for a tecla Enter (código ASCII 13), termina a leitura
        {
            senha[i]='\0'; // adiciona o caractere nulo '\0' ao final da string para indicar o fim da senha
            break; // Sai do loop
        }
        else if(ch==8)  // Se for a tecla Backspace (código ASCII 8), apaga o último caractere
        {
            if(i>0)  // Se 'i' for maior que 0, ou seja, se já houver caracteres na senha
            {
                i--; // Decrementa 'i' para remover o último caractere
                printf("\b \b"); // Move o cursor para trás e apaga o asterisco
            }
        }
        else  // Se o caractere lido não for nem Enter nem Backspace
        {
            senha[i++]=ch; // Armazena o caractere lido na posição atual de 'senha' e incrementa 'i'
            printf("*"); // Exibe um asterisco no lugar do caractere digitado
        }
    }
}

void ValidarLoginSenha(int num_escolhido) //sistema de validar login e senha
{
    system("cls");
    printf("\n\n\t..::: Usuário selecionado: %s :::..\n", usuarios[num_escolhido].login);
    int cont = 4;
    char stringsenha[30];
    do
    {
        usuarios[num_escolhido].senha[strcspn(usuarios[num_escolhido].senha, "\n")] = 0;

        printf("\n\n\t..::: Senha:  ");
        fflush(stdin);
        lerSenha(stringsenha);
        if(strcmp(stringsenha,usuarios[num_escolhido].senha)==0)
        {
            usuario_atual = usuarios[num_escolhido];

            logado = 1;
            printf("\n\n\n\t..::: Acesso liberado! :::..\n\n\n\t"); //se a senha inserida for correta, o sistema abre
            system("pause");
            system("cls");
            main();
            break;
        }
        else
        {
            printf("\n\n\t..::: Senha incorreta! :::..\n");
            printf("\n\t..::: Tentativas restantes: %d :::..\n", cont - 1);
            cont--;
        }
    }
    while(cont>0 && !logado);
    if(!logado)
    {
        printf("\n\n\t..::: Acesso bloqueado! :::..\n\n\n");
        system("pause");
        exit(1);
    }
}

void menu_usuarios()
{
    int op;

    if(logado != 1)
    {
        do
        {
            system ("cls");
            printf ("\n\n\t=========================================\n"); //sistema de login da bere
            printf ("\t|                                       |\n");
            printf ("\t|            SISTEMA DA BERÊ            |\n");
            printf ("\t|                 Login                 |\n");
            printf ("\t|                                       |\n");
            printf ("\t|          1 Entrar no sistema          |\n");
            printf ("\t|                                       |\n");
            printf ("\t|          2 Cadastre-se                |\n");
            printf ("\t|                                       |\n");
            printf ("\t|                                       |\n");
            printf ("\t|          0 Sair                       |\n");
            printf ("\t|                                       |\n");
            printf ("\t=========================================\n\n\n");
            printf ("\t..::: Escolha uma das opções:  ");
            scanf("%i", &op);
            getchar();

            switch(op)
            {
            case 1:
                if(usuarios[0].id == 1)
                {
                    selecionar_usuario();
                    break;
                }
                else
                {
                    printf("\n\n\t..::: Não há usuários cadastrados! :::..\n\n\n");
                    system("pause");
                    break;
                }
            case 2:
                criar_usuario();
                break;

            case 0:
                exit(1);
            }
        }
        while(op < 3 || op > 0);
    }
}




void selecionar_usuario()
{
    int op;
    do
    {
        system("cls");
        printf("\n\n\t=================================\n");//menu de selecionar usuário para login
        printf("\t|                               |\n");
        printf("\t|     Selecionar um usuário     | \n");
        printf("\t|                               |\n");
        printf("\t=================================\n\n");
        for (int i = 0; i <= contador_usuarios; i++)
        {
            usuarios[i].login[strcspn(usuarios[i].login, "\n")] = 0;

            if(usuarios[i].nivel_de_controle == 1)
            {
                printf("\t..::: [%d] %s - Administrador\n\n", usuarios[i].id, usuarios[i].login);
            }
            if(usuarios[i].nivel_de_controle == 2)
            {
                printf("\t..::: [%d] %s - Usuário comum\n\n", usuarios[i].id, usuarios[i].login);
            }
        }
        printf("\t..::: [0] Voltar \n\n");

        printf("\t..::: Digite um número de usuario:  ");

        scanf("%d", &op);
        getchar();

        if (op < 0 || op > contador_usuarios)
        {
            printf("\n\n\t..::: Escolha invalida! :::..\n\n\n\t");
            system("pause");
        }
        else if (op > 0)
        {
            ValidarLoginSenha(op - 1);
            break;  // Sair do loop após a validação de login
        }
    }
    while (op != 0);
}

void acesso_negado()
{
    int op;
    system ("cls");
    printf ("\n\n\t=========================================\n"); //erro de entrar em um menu que não pode usuário comum
    printf ("\t|                                       |\n");
    printf ("\t|                  ERRO                 |\n");
    printf ("\t|                                       |\n");
    printf ("\t|        O usuário atual não é um       |\n");
    printf ("\t|             ADMINISTRADOR             |\n");
    printf ("\t|                                       |\n");
    printf ("\t|    Deseja logar com outro usuário?    |\n");
    printf ("\t|                                       |\n");
    printf ("\t|                1 - Sim                |\n");
    printf ("\t|                                       |\n");
    printf ("\t|                2 - Não                |\n");
    printf ("\t|                                       |\n");
    printf ("\t=========================================\n\n\n");
    printf ("\t..::: Escolha uma das opções:  ");
    scanf("%i", &op);
    getchar();

    if(op == 1)
    {
        selecionar_usuario();
    }
}

void criar_usuario()
{
    int tamanhoStringLogin, tamanhoStringSenha;

    system("cls");
    printf("\n\n\t=========================================\n");//criar um novo usuário
    printf("\t|                                       |\n");
    printf("\t|     Deseja criar um novo usuário?     |\n");
    printf("\t|                                       |\n");
    printf("\t=========================================\n\n");
    printf("\t..::: Digite 1 para SIM e 2 para NÃO:  ");
    int op;
    scanf("%i", &op);
    getchar();
    if(op >= 2 || op < 1)
    {
        menu_usuarios();
    }
    d_usuarios novo_usuario;

    do
    {
        system("cls");
        printf("\n\n\t================================\n");
        printf("\t|                              |\n");
        printf("\t|      Criar novo usuário      |\n");
        printf("\t|                              |\n");
        printf("\t================================\n\n");
        printf("\t..::: Digite um nome de usuario (entre 8 e 12 caracteres):  ");
        scanf("%s",&novo_usuario.login);
        tamanhoStringLogin=strlen(novo_usuario.login);
        if(tamanhoStringLogin<8 || tamanhoStringLogin>12)
        {
            printf("\n\n\t..::: Nome de usuario invalido! :::...\n\n\t");
            system("pause");
        }
    }
    while(tamanhoStringLogin<8 || tamanhoStringLogin>12);

    do
    {
        printf("\n\n\t..::: Digite uma senha (entre 6 e 8 caracteres):  ");
        scanf("%s",&novo_usuario.senha);
        tamanhoStringSenha=strlen(novo_usuario.senha);
        if(tamanhoStringSenha<6 || tamanhoStringSenha>8)
        {
            printf("\n\n\t..::: Senha invalida! :::..\n\n\t");
            system("pause");
        }
    }
    while(tamanhoStringSenha<6 || tamanhoStringSenha>8);

    do
    {
        printf("\n\n\t..::: Digite o tipo (1 para Administrador ou 2 para Usuario Comum):  ");
        int tipoUsuario;
        scanf("%i", &tipoUsuario);

        if(tipoUsuario == 1)
        {
            novo_usuario.nivel_de_controle = tipoUsuario;
        }

        else if(tipoUsuario == 2)
        {
            novo_usuario.nivel_de_controle = tipoUsuario;
        }

        else
        {
            printf("\n\n\n\t..::: Opcao invalida! :::..\n");
        }
    }
    while(novo_usuario.nivel_de_controle != 1 &&  novo_usuario.nivel_de_controle != 2);

    usuarios = (d_usuarios *) realloc (usuarios, ( (contador_usuarios + 1) * sizeof(*usuarios) ) );

    usuarios[contador_usuarios] = novo_usuario;

    usuarios[contador_usuarios].id = contador_usuarios + 1;

    usuarios[contador_usuarios].login[strcspn(usuarios[contador_usuarios].login, "\n")] = 0;

    usuarios[contador_usuarios].senha[strcspn(usuarios[contador_usuarios].senha, "\n")] = 0;

    contador_usuarios++;

    salvarUsuarios();

    printf("\n\n\t=======================================\n");
    printf("\t|                                     |\n");
    printf("\t|     Usuário criado com sucesso!     |\n");
    printf("\t|                                     |\n");
    printf("\t=======================================\n\n");
    system("pause");
    system("cls");
}





void lerUsuarios()
{
    FILE *arq = fopen("usuarios.txt", "r"); //ler usuários do arquivo
    if (arq)
    {
        usuarios = (d_usuarios *) malloc (1 * sizeof(*usuarios));

        contador_usuarios = 1;

        d_usuarios usuarios_temp;

        for(int i=0; i<contador_usuarios; i++)
        {
            fscanf(arq, "%i\n", &contador_usuarios);
            fscanf(arq, "%i\n", &usuarios_temp.id);
            fgets(usuarios_temp.login, sizeof(usuarios_temp.login), arq);
            fgets(usuarios_temp.senha, sizeof(usuarios_temp.senha), arq);
            fscanf(arq, "%i\n", &usuarios_temp.nivel_de_controle);

            usuarios[i] = usuarios_temp;
            usuarios = (d_usuarios *) realloc (usuarios, ( (contador_usuarios + 1) * sizeof(*usuarios) ) );
        }
        fclose(arq);
    }
    else
    {
        usuarios = (d_usuarios *) malloc (1 * sizeof(*usuarios));
    }
}



