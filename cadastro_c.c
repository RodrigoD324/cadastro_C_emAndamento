#include <stdio.h>
#include <conio2.h>
#define SIZE 200
#define STRTAM 30

char nome[SIZE][50];
char email[SIZE][50];
int cpf [SIZE];
int op;

void criaMenuLinhaSuperior(){
	int i;
	printf("%c", 201);
	for( i = 0 ; i < STRTAM ; i++ )
		printf("%c", 205);
	printf("%c\n", 187);	
}

void criaMenuLinhaRodape(int tamanhoX){
	int i;
	printf("%c", 200);
	for( i = 0 ; i < STRTAM ; i++ )
		printf("%c", 205);
	printf("%c\n", 188);	
}

void criaMenuItem(int tamanhoX , char str[]){
	int contaLetras = 0;
	int i;
	
	for ( i = 0 ; i < tamanhoX ; i++){
		if(str[i]=='\0')
			break;
		else
			contaLetras++;
	}
	
	printf("%c", 186);
	printf("%s", str);
	while(contaLetras < tamanhoX){
		printf("%c", 32);
		contaLetras++;
	}
	printf("%c\n", 186);
}

void criaMenuLinhaHorizontal (int tamanhoX){
	int i;
	printf("%c", 204);
	for( i = 0 ; i < tamanhoX ; i++ )
	printf("%c", 205);
	printf("%c\n", 185);
}

void montaMenu(){
	textcolor(YELLOW);
	criaMenuLinhaSuperior();
	criaMenuItem(STRTAM, "========MENU PRINCIPAL========");
	criaMenuLinhaHorizontal(STRTAM);
	criaMenuItem(STRTAM, "1 - Cadastrar");
	criaMenuItem(STRTAM, "2 - Listar todos");
	criaMenuItem(STRTAM, "3 - Pesquisar");
	criaMenuItem(STRTAM, "4 - Sair");
	criaMenuLinhaRodape(STRTAM);
	textcolor(WHITE);
}

int main (void) {
	
	do{
		system("cls");
		montaMenu();
		printf("\n\nDigite o que deseja: ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				cadastro();
				break;
			case 2:
				lista();
				break;
			case 3:
				pesquisa();
				break;
			case 4:
				system("exit");
				break;
			default:
				textcolor(RED);
				printf("\n*******VALOR INCORRETO*******");
				getchar();
				getchar();
				break;
		}
	}while(op!=4);
}

void lista(){
	int i;
	for(i=0 ; i<SIZE ; i++) {
		if(cpf[i]>0) {
			textcolor(LIGHTBLUE);
			printf("\nNOME:  %s \nEMAIL: %s \nCPF:   %d", nome[i], email[i], cpf[i]);
			textcolor(WHITE);
			printf("\n");
		}else{
			break;
		}
	}
	getchar();
	getchar();
}

void cadastro (){
	static int linha;
	do{
		printf("\nDigite o Nome: ");
		scanf("%s", &nome[linha]);
		printf("Digite o Email: ");
		scanf("%s", &email[linha]);
		printf("Digite o CPF: ");
		scanf("%d", &cpf[linha]);
		textcolor(GREEN);
		printf("\nDigite 1 para continuar | Digite 0 para sair: ");
		textcolor(WHITE);
		scanf("%d", &op);
		linha++;
	}while(op==1);
}

void pesquisa (){
	int cpfPesquisa;
	int i;
	char emailPesquisa[50];
	
	do{
		textcolor(GREEN);
		printf("\nDigite 1 para pesquisar por CPF | Digite 2 para pesquisar por EMAIL: ");
		textcolor(WHITE);
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\nDigite o CPF: ");
				scanf("%d", &cpfPesquisa);
				for( i=0 ; i<SIZE ; i++ ) {
					if(cpf[i]==cpfPesquisa) {
						textcolor(LIGHTBLUE);
						printf("\nNOME:  %s \nEMAIL: %s \nCPF:   %d", nome[i], email[i], cpf[i]);
						textcolor(WHITE);
					}
				}
				break;
			case 2:
				printf("\nDigite o Email: ");
				scanf("%s", &emailPesquisa);
				for( i=0 ; i<SIZE ; i++ ) {
					if(strcmp(email[i] , emailPesquisa)==0) {
						textcolor(LIGHTBLUE);
						printf("\nNOME:  %s \nEMAIL: %s \nCPF:   %d", nome[i], email[i], cpf[i]);
						textcolor(WHITE);
					}
				}
				break;
			default:
				textcolor(RED);
				printf("\n*******VALOR INCORRETO*******");
				textcolor(WHITE);
				break;
		}
		textcolor(GREEN);
		printf("\n\nDigite 1 para continuar pesquisando | Digite 0 para interromper pesquisa: ");
		textcolor(WHITE);
		scanf("%d", &op);
	}while(op==1);	
}
