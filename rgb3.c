#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

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
Client *searsh(Client client[], int nb, char *nom){
	int i;
	for (i=0; i<nb; i++){
		if (strcmp(nom, client[i].CIN) == 0){
			return &client[i];
		}
	}
	return NULL;
}
void print_infos(){
	printf(
	"\t\tCette application permet de gerer les comptes bancaires de plusieurs clients.\n"
	"\t\tI- L'application faire des operations bancaires.\n"
    "\t\tII- L'application offrir un menu qui permet de choisir l'operationa? effectuer.\n"
	"\t\tIII- Vous pouvez retourner au menu principal apres chaque operation:\n");
}
void add_client(Client *nvClient, int *n){
	Client clt;
	int i;
	printf("Nom : "); scanf("%s", &clt.nom);
	printf("Prenom : "); scanf("%s", &clt.prenom);
	printf("CIN : "); 
	scanf("%s", &clt.CIN);
	Client *s;
	s = searsh(nvClient, *n, &clt.CIN);
	if(s != NULL){
		printf("CIN deja exist: \n");
		return;
	}
//		for (i=0; i<*n; i++)
//			if (strcmp(clt.CIN, nvClient[i].CIN) == 0){
//				printf("CIN deja exist: \n");
//				return;
//			}
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
	do{
	printf("\n\n\tChoisir une operation:\n");
	printf("\t1-Retrait.\n");
	printf("\t2-Depot.\n");
	printf("\t3-Virement.\n");
	printf("\t0-Menu principale.\n");
	printf("\tVotre choix : ");
	scanf("%d", &c);
	}while(c<=0 || c>4);
	//fflush(stdin);
	return c;
}
void retrait(Client client[], int *n_cpt){
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
void clear(){
        system("clear");
        system("cls");
		clear();
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
				char add_c[50];
//				do{
					add_c[50] = NULL;
					int operation = menuOperation();
					if(operation == 1){
						char tape[50];
						printf("\n\tIdentiter(CIN): ");
						scanf("%s", tape);
						Client *r = searsh(client, n_cpt, tape);
						if(r != NULL){
							float mt;
							do{
								printf("\n\tEntrer le montant: ");
								scanf("%f", &mt);
							}while(mt<=0);
							if(r->solde >= mt){
								r->solde -= mt;
								printf("\n\tMontant retrait: %.2f Dhs\n\tSolde: %.2f Dhs",mt, r->solde);
								printf("\n\tOperation terminer avec seccees.");
							}
							else 
								printf("\n\tSolde insiffusant!!");
						}
						else
							printf("\n\tAucune compte avec cette CIN: %s",tape);
					}
					else if(operation == 2){
						char tape[50];
						printf("\n\tTaper votre CIN: ");
						scanf("%s", tape);
						Client *r = searsh(client, n_cpt, tape);
						if(r != NULL){
							float mt;
							do{
								printf("\n\tEntrer le montant: ");
								scanf("%f", &mt);
							}while(mt<=0);
							r->solde += mt;
							printf("\n\tOperation terminer avec seccees.");
							printf("\n\tSolde: %.2f Dhs", r->solde - mt);
							printf("\n\tNouveau solde: %.2f Dhs", r->solde);
						}else
							printf("\n\tAucune compte avec cette CIN: %s",tape);
					}
					else if(operation == 3){
						char tape[50];
						printf("\n\tTaper votre CIN: ");
						scanf("%s", tape);
						Client *r = searsh(client, n_cpt, tape);
						char d[50];
						if(r != NULL){
							printf("\n\tEnter le CIN de destination: ");
							scanf("%s", d);
							Client *v = searsh(client, n_cpt, d);
							if(v != NULL){
								float mt;
								do{
									printf("\n\tEntrer le montant: ");
									scanf("%f", &mt);
								}while(mt<=0);
								if(r->solde >= mt){
									r->solde -= mt;
									v->solde += mt;
									printf("\n\tOperation terminer avec seccees.");
									printf("\n\tMontant retrait: %.2f Dhs\n\tSolde actuelle: %.2f Dhs",mt, r->solde);
								}
								else
									printf("\n\tMantant insuffisant\n",d);
							}
							else
								printf("\n\tDestination non trouver, CIN: %s errors\n",d);
						}else
							printf("\n\tAucune compte avec cette CIN: %s\n",tape);
					}
					else if(operation == 0)
						add_c[50] = "no";
					else 
						printf("\n\tAutre OperationSSSS (yes,no).... ");
					printf("\n\tAutre Operation (yes,no).... ");
					scanf("%s",add_c);
//				}while(strcmp(add_c, "yes") == 0 || strcmp(add_c, "YES") == 0);
				break;
			}
			case 3 : {
				char add_c[50];
				do{
					add_client(client, &n_cpt);
					printf("\n\tAjouter autre client(yes,no).... ");
					scanf("%s",add_c);
				}while(strcmp(add_c, "yes") == 0 || strcmp(add_c, "YES") == 0);
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
					char add_c[50];
					do{
						printf("\n\tChercher un client (yes,no).... ");
						scanf("%s",add_c);
						if(strcmp(add_c, "yes") == 0 || strcmp(add_c, "YES") == 0){	
							char add_v[50];
							printf("\n\tNon a rechercher.... ");
							scanf("%s",add_v);
							Client *s = searsh(client,n_cpt,add_v);
							if( s != NULL){
								print_client(*s);
							}else 
								printf("N'exist pas.\n");
						}
						
					}while(strcmp(add_c, "yes") == 0 || strcmp(add_c, "YES") == 0);
				}
				else if(KJ == 2){
					char nom[50];
					printf("Nom a rechercher : ");
			        scanf("%s", nom);
					Client *s = searsh(client,n_cpt,nom);
					if( s != NULL){
						print_client(*s);
					}else 
						printf("N'exist pas.\n");
				}else{
					printf("Hors services ......\n");
				}
				break;
			}
			case 6 : {
				
				break;
			}
			case 7 : {
				    char nom[50];
					printf("Nom a rechercher : ");
			        scanf("%s", nom);
					Client *s = searsh(client,n_cpt,nom);
					if( s != NULL){
						print_client(*s);
					}else 
						printf("N'exist pas.\n");
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
		char isOk[5] = "no";
		if(choix == 0){
			printf("\n\tQuiter l'application (yes,no)......  ");
			scanf("%s",isOk);
			if(strcmp(isOk, "no") == 0||strcmp(isOk, "NO") == 0) choix = 1;
		}
		else if(choix != 0){
			printf("\n\tFaire autre Operation:(yes,no).....  ");
			scanf("%s",isOk);
			if(strcmp(isOk, "yes") == 0 || strcmp(isOk, "YES") == 0);
			else choix = 0;
		}
	
	}while (choix != 0);
	
	
	return 0;
}





