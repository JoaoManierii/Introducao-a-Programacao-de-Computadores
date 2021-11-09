#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct cliente{
	char nome[50];
	char cpf[20];
	char numconta[10];
	float saldo;
	char email[30];
	char senha[20];
	char agencia[5];
	char operadora[10];
	int numcel;
	float cad;

};




// Função Cadastro
void cadastro(struct cliente us[]){
    int p;
    p = us[1].cad;
    printf("Cliente %d\n",p+1);
    printf("Digite seu nome: ");
    fflush(stdin);
    scanf("%[^\n]s",us[p+1].nome);
    printf("Digite seu cpf: ");
    scanf("%s",us[p+1].cpf);
    printf("Digite seu email: ");
    scanf("%s",us[p+1].email);
    printf("Digite sua conta: ");
    scanf("%s",us[p+1].numconta);
    printf("Digite sua agencia: ");
    scanf("%s",us[p+1].agencia);
    printf("Digite sua senha: ");
    scanf("%s",us[p+1].senha);
    us[p+1].saldo=0;
    p++;
    us[1].cad = p;

}

// Função Depósito
void deposito(struct cliente us[]){
    char conta[10],senha[20];
    int tent=4;
    int i;
    float dep;
    while(tent--){
    printf("Escolha o cliente que deseja fazer o deposito: ");
    scanf("%d",&i);
    printf("Digite sua conta: ");
    scanf("%s",conta);
    printf("Digite sua senha: ");
	scanf("%s",senha);
	int a = strcmp(conta,us[i].numconta);
	int b = strcmp(senha,us[i].senha);
	if(a==0 && b==0){
        printf("Digite o valor que sera depositado: ");
        printf("\n");
        scanf("%f",&dep);
        us[i].saldo += dep;
        printf("Operacao realizada com sucesso!\n");
        printf("*******************************\n\n");
        break;
	}
	else{
        printf("Conta e/ou senha invalido(s)\n");
        printf("*******************************\n\n");
        continue;
	}
    }


}

// Função ver perfil
void perfil(struct cliente us[]){
	int i;
	printf("Escolha o cliente que deseja ver o perfil: ");
    scanf("%d",&i);
	printf("Nome: %s\n",us[i].nome);
	printf("CPF: %s\n",us[i].cpf);
	printf("E-mail: %s\n",us[i].email);
	printf("Conta: %s\n",us[i].numconta);
	printf("Agencia: %s\n",us[i].agencia);
	printf("Senha: %s\n",us[i].senha);
	printf("*******************************\n\n");

}


// Função Ver Saldo
void versaldo(float *sald, struct cliente us[]){
    int i;
    printf("Escolha o cliente que deseja ver o saldo: ");
    scanf("%d",&i);
    *sald = us[i].saldo;
    printf("Saldo: R$%.2f\n",*sald);
    printf("*******************************\n");
    printf("\n\n");

}


// Função Saque
void saque(float *sald, struct cliente us[]){
    int i;
    printf("Escolha o cliente que deseja fazer o saque: ");
    scanf("%d",&i);
    float saque;


    printf("Valor Do Saque: \n");
    scanf("%f", &saque);
    *sald = us[i].saldo;
    if (saque <= *sald && saque>0)
    {
        us[i].saldo -= saque;
        printf("Operacao realizada com sucesso!\n");
        printf("Saldo: R$%.2f\n", us[i].saldo);
        printf("*******************************\n\n");

    }
    else
    {
        printf("Valor indisponivel para saque\n");
          printf("*******************************\n\n");

    }
}


// Função Transferência
void transferencia(float *sald, struct cliente us[]){
    int i,i2;
    printf("Digite o cliente que vai transferir: ");
    scanf("%d",&i);
    printf("Digite o cliente que vai receber: ");
    scanf("%d",&i2);
    printf("Digite o valor que sera transferido: ");
    float valor;
    scanf("%f",&valor);
    *sald = us[i].saldo;
     if (valor <= *sald && valor>0)
    {

    us[i].saldo -= valor;
    us[i2].saldo += valor;
    printf("Operação realizada com sucesso!\n");
    printf("*******************************\n\n");

    }
    else{
        printf("Valor indisponivel para transferencia\n");
        printf("*******************************\n\n");

    }


}


// Função recarga de celular
void recargacel(float *sald,struct cliente us[]){
    int i;
    printf("Escolha o cliente que deseja fazer a recarga: ");
    scanf("%d",&i);
    printf("Digite sua operadora:");
    scanf("%s",us[i].operadora);
    printf("Digite seu numero: ");
    scanf("%d",&us[i].numcel);
    float valrecarga;
    printf("Digite o valor desejado: ");
    scanf("%f",&valrecarga);
    *sald = us[i].saldo;
    if(valrecarga<=*sald && valrecarga>0){
    us[i].saldo -= valrecarga;
    printf("Operacao realizada com sucesso!\n");
    printf("*******************************\n\n");
    }
    else{
        printf("Valor indisponivel para recarregar\n");
        printf("*******************************\n\n");
    }
}

// Função Recuperar Senha
void recuperarSenha(struct cliente us[])
{
    int nIdenti;
    char email[30];
    char nPassword[20];
    char nPasswordAt[20];

    int tent = 3;
    printf("Bem vindo ao recuperar senha\n");
    printf("Digite o numero de identificacao\n");
    scanf("%d", &nIdenti);

    printf("Digite o seu email para confirmacao do cliente: %d\n", nIdenti);
    scanf("%s", email);
    int attempt = strcmp(email, us[nIdenti].email);
    if (attempt == 0)
    {

        while (tent--)
        {
            printf("Digite a nova senha\n");
            scanf("%s", nPassword);
            printf("Confirme e a nova senha\n");
            scanf("%s", nPasswordAt);

            int a = strcmp(nPasswordAt, nPassword);

            if (a == 0)
            {
                strcpy(us[nIdenti].senha, nPassword);
                printf("Operacao realizada com sucesso!\n");
                printf("*******************************\n\n");
                break;
            }
            else
            {
                printf("As senhas nao sao as mesmas, tente novamente!\n");
                printf("*******************************\n\n");
                continue;
            }
        }
    }
    else
    {
        printf("A verificacao falhou!\n");
        printf("*******************************\n\n");
    }
}

// Menu
void menu(){
	int opcao;
	struct cliente P[30];
	float sald;

	while(1){
		printf("\nBem vindo ao UFU Bank");
		printf("\n1- Cadastrar");
		printf("\n2- Deposito");
		printf("\n3- Ver perfil");
		printf("\n4- Ver saldo ");
		printf("\n5- Saque");
		printf("\n6- Transferencia");
        printf("\n7- Recarga de celular");
        printf("\n8- Recuperar senha: ");
		printf("\n9- Sair");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
		printf("\n");

		if(opcao == 1) cadastro(P);
		if(opcao == 2) deposito(P);
		if(opcao == 3) perfil(P);
		if(opcao == 4) versaldo(&sald,P);
		if(opcao == 5) saque(&sald,P);
		if(opcao == 6) transferencia(&sald,P);
		if(opcao == 7) recargacel(&sald,P);
		if(opcao == 8) recuperarSenha(P);
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}