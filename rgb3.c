#include <stdio.h>
#include<string.h>

typedef struct compte_bancaire{
	char prenom[50],nom[50],CIN[20];
	float solde;
}Client;
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
void add_client(Client *nvClient, int *n){
	Client clt;
	int i;
	printf("Nom : "); scanf("%s", &clt.nom);
	printf("Prenom : "); scanf("%s", &clt.prenom);
		printf("CIN : "); 
		scanf("%s", &clt.CIN);
		for (i=0; i<*n; i++)
			if (strcmp(clt.CIN, nvClient[i].CIN) == 0){
				printf("CIN deja exist: \n");
				return;
			}
	printf("Solde : "); scanf("%f", &clt.solde);
	*(nvClient + (*n)) = clt;
	(*n)++;
}
void print_clients(Client c[], int nb){
	int i;
	printf("Affichage du repertoire\n");
	printf("%20s ...... Numero\n", "Nom");
	for (i=0; i<nb; i++)
	{
		print_client(c[i]);
	}
}
void print_client(Client c){
	printf("%20s -------- %s------- %s ------ %.2f\n", c.nom, c.prenom,c.CIN ,c.solde);
}
int menu_print(){
	int c;
	printf("\n\t1-Affichage:");
	printf("\n\t2-chercher un client:");
	printf("\n\t3-Trie:");
	printf("\n\t  Votre choix: ");
	scanf("%d",&c);
	return c;
}
void data(Client *client){
	Client p1 = {"hasnaoui","said","DA12",7000};
	Client p2 = {"Jabir","Moundhir","D13",50000};
	Client p3 = {"Grich","said","db13",19000};
	Client p4 = {"Hafssa","ghalbane","DA77",8000};
	*(client) = p1;
	*(client + 1) = p2;
	*(client + 2) = p3;
	*(client + 3) = p4;
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
void searsh_client(Client client[], int nb, char *nom){
	int i;
	for (i=0; i<nb; i++){
		if (strcmp(nom, client[i].CIN) == 0){
			print_client(client[i]);
			return;
		}
	}
	printf("\nN'existe pas !!\n");
}

int main(){
	Client client[200];
	int choix, n_cpt = 4;
	data(&client);
	do{
		do{
			choix = Menu_Principale();
			
		}while (choix < 0 || choix > 9);
		switch (choix){
			case 1 : {
				print_infos();
				break;
			}
			case 2 : {
				int operation = menuOperation();
				if(operation == 1) retrait();
				else if(operation == 2) depot();
				else if(operation == 3) virement();
				break;
			}
			case 3 : {
				add_client(client, &n_cpt);
				break;
			}
			case 4 : {
				int x,i;
				do{ 
					printf("Combient de compte vous voulez cree: ");
					scanf("%d",&x);
				}while(x <= 0);
				for(i=0;i<x;i++)
					add_client(client, &n_cpt);
				break;
			}
			case 5 : {
				int KJ = menu_print();
				if(KJ == 1){
					print_clients(client,n_cpt);
				}else if(KJ == 2){
					char nom[50];
					printf("Nom a rechercher : ");
			        scanf("%s", nom);
					searsh_client(client, &n_cpt, nom);
				}else{
					printf("Hors services ......\n");
				}
				break;
			}
			case 6 : {
				
				break;
			}
			case 7 : {
				print_infos();
				break;
			}
			case 8 : {
				print_infos();
				break;
			}
			default :{
				break;
			}
		}
	}while (choix != 0);
	
	
	return 0;
}





