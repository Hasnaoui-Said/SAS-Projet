#include <stdio.h>

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
	Client client;
	printf("Nom : "); scanf("%s", &client.nom);
	printf("Prenom : "); scanf("%s", &client.prenom);
	printf("CIN : "); scanf("%s", &client.CIN);
	printf("Solde : "); scanf("%f", &client.solde);
	*(nvClient + (*n)) = client;
	(*n)++;
}
void print_clients(Client c[], int nb){
	int i;
	printf("Affichage du repertoire\n");
	printf("%20s ...... Numero\n", "Nom");
	for (i=0; i<nb; i++)
	{
		afficher_client(c[i]);
	}
}
void print_client(Client c){
	printf("%20s -------- %s------- %s ------ %.2f\n", c.nom, c.prenom,c.CIN ,c.solde);
}


int main(){
	Client client[200];
	int choix, n_cpt = 0;
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
				print_infos();
				break;
			}
			case 3 : {
				add_client(client, &n_cpt);
				break;
			}
			case 4 : {
				print_infos();
				break;
			}
			case 5 : {
				print_infos();
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





