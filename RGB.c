#include<stdio.h>

typedef struct compte_bancaire{
	char prenom[50],nom[50],CIN[20];
	int solde;
}Client;
void traiter_choix(int c);
void startApplication();
int Menu_Principale();
void print_infos();
void Operation();
void add_clients(Client *client,int *n);
void add_client(Client *client);
void affiche_data(Client clients[],int n);
void affiche_client(Client client);

int main(){
	startApplication();
	return 0;
}

void startApplication(){
	int choix, a = -1,N = 4;
	Client clients[2000] ;
	client_data(&clients);
	affiche_data(clients,N);
	do{
		choix = Menu_Principale();
		traiter_choix(choix);
	}while (choix != 0);
	
}
void traiter_choix(int c){
	switch(c){
		case 1 :
		{
			print_infos();
			break;
		}
		case 2 :
		{
			Operation();
			break;
		}
		case 3 :
		{
			printf("\t3-Introduire un compte bancaire.\n");
			break;
		}
		case 4 :
		{
			printf("\t4-Introduire plusieurs comptes bancaires.\n");
			break;
		}
		case 5 :
		{
			printf("\t5-Affichage.\n");
			break;
		}
		case 6 :
		{
			printf("\t6-Fidélisation.\n");
			break;
		}
		case 7 :
		{
			printf("\t7-Chercher une client(CIN).\n");
			break;
		}
		case 8 :
		{
			printf("\t8-Supplémentaires.\n");
			break;
		}
		case 0 :
		{		
			printf("\t0-Quitter l’application.\n");
			break;
		}
		default :
		{
			printf("\tAttention, Error quelque par, essayez de nouveau !!!!");
			break;
		}	
	}
	fflush(stdin);
}
void client_data(Client *client){
	Client p1 = {"hasnaoui","said","DA90453",7000};
	Client p2 = {"Jabir","Moundhir","DA90453",50000};
	Client p3 = {"Grich","said","DA90453",19000};
	Client p4 = {"Hafssa","ghalbane","DA90453",8000};
	*(client) = p1;
	*(client + 1) = p2;
	*(client + 2) = p3;
	*(client + 3) = p4;
}
void add_client(Client *client){
	printf("Nom : "); scanf("%s", client->nom);
	printf("Prenom : "); scanf("%s", client->prenom);
	printf("CIN : "); scanf("%s", client->CIN);
	printf("Solde : "); scanf("%f", client->solde);
}
void add_clients(Client *client,int *n){
	int i;
	printf("Introduire de %d client :\n", *n);
	for (i=0; i<*n; i++)
	{
		printf("Client [%d]:\n", i+1);
		add_client(client+i);
	}
}
int Menu_Principale(){
	int c;
	printf("\n\n\tMenu_Principale:\n");
	printf("\t1-Infos.\n");
	printf("\t2-Operation.\n");
	printf("\t3-Introduire un compte bancaire.\n");
	printf("\t4-Introduire plusieurs comptes bancaires.\n");
	printf("\t5-Affichage.\n");
	printf("\t6-Fidelisation.\n");
	printf("\t7-Chercher une client(CIN).\n");
	printf("\t8-Supplementaires.\n");
	printf("\t0-Quitter l'application.\n");
	printf("\tVotre choix : ");
	scanf("%d", &c);
	fflush(stdin);
	return c;
}
void print_infos(){
	printf(
	"\t\tCette application permet de gerer les comptes bancaires de plusieurs clients.\n"
	"\t\tI- L'application faire des operations bancaires.\n"
    "\t\tII- L'application offrir un menu qui permet de choisir l'operationaà effectuer.\n"
	"\t\tIII- Vous pouvez retourner au menu principal apres chaque operation:\n");
}
void Operation(){
	int operation = menuOperation();
	if(operation == 1) retrait();
	else if(operation == 2) depot();
	else if(operation == 3) virement();
}
int menuOperation(){
	int c;
	printf("\n\n\tChoisir une operation:\n");
	printf("\t1-Retrait.\n");
	printf("\t2-Depot.\n");
	printf("\t3-Virement.\n");
	printf("\t-Menu principale tappez autre.\n");
	printf("\tVotre choix : ");
	scanf("%d", &c);
	fflush(stdin);
	return c;
}
void retrait(){
	printf("\nRetrait");
}
void depot(){
	printf("\nDepot");
}
void virement(){
	printf("\nVirement");
}
void affiche_data(Client clients[],int n){
	int i;
	for(i=0;i<n;i++){
		affiche_client(clients[i]);
		printf("\n");
	}
}
void affiche_client(Client client){
		printf("%s  || %s || %s || %d",client.nom,client.prenom,client.CIN,client.solde);
}





