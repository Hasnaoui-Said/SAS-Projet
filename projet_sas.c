#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct compte_bancaire{
	char prenom[50],nom[50],CIN[20];
	float solde;
}Client;
int Menu_Principale();
Client *searsh(Client client[], int nb, char *nom);
void print_infos();
void add_client(Client *nvClient, int *n);
void print_clients(Client c[], int nb);
void print_client(Client c);
void print_ascendants(Client client[], int nb);
void print_descendants(Client client[], int nb);
int menu_print();
void data(Client *client);
int menuOperation();
void retrait(Client client[], int *n_cpt);
void depot();
void virement();
void searsh_client(Client client[], int nb, char *nom);
void clear();


int main(){
	Client client[200];
	int choix, n_cpt = 0;
    FILE *fec = fopen("data.txt","r");
	while((fscanf(fec, "%s %s %s %f", &client[n_cpt].CIN,&client[n_cpt].nom,&client[n_cpt].prenom,&client[n_cpt].solde)) != -1)
		n_cpt++;
	fclose(fec);
	do{
		system("cls");
		do{
			choix = Menu_Principale();
			
		}while (choix < 0 || choix > 9);
		switch (choix){
			system("cls");
			case 1 : {
				system("cls");
				print_infos();
				break;
			}
			case 2 : {
				char add_c[50];
				do{
					system("cls");
					add_c[50] = NULL;
					int operation = menuOperation();
					if(operation == 1){
						system("cls");
						char tape[50];
						printf("\n\tIdentiter(CIN): ");
						scanf("%s", tape);
						Client *r = searsh(client, n_cpt, tape);
						if(r != NULL){
							float mt;
							do{
								system("cls");
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
						system("cls");
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
						system("cls");
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
					else 
						printf("\n\tAttention vous voulez quiter?!!.... ");
					printf("\n\n\tAutre Operation (yes,no).... ");
					scanf("%s",add_c);
				}while(strcmp(add_c, "yes") == 0 || strcmp(add_c, "YES") == 0);
				system("cls");
				break;
			}
			case 3 : {
				system("cls");
				char add_c[50];
				do{
					add_client(client, &n_cpt);
					printf("\n\tAjouter autre client(yes,no).... ");
					scanf("%s",add_c);
				}while(strcmp(add_c, "yes") == 0 || strcmp(add_c, "YES") == 0);
				break;
			}
			case 4 : {
				system("cls");
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
				char add_c[50];
				do{
					system("cls");
					int KJ = menu_print();
					if(KJ == 1){
						system("cls");
						print_clients(client,n_cpt);
					}
					else if(KJ == 3){
						system("cls");
						print_ascendants(client,n_cpt);
						printf("Affichage par ordre ascendant:\n");
						print_clients(client,n_cpt);
					}
					else if(KJ == 4){
						system("cls");
						float mt_sup;
						do{
							printf("\n\n\t\tMantant (Borne superieur): ... ");
							scanf("%f",&mt_sup);
						}while(mt_sup <= 0);
						Client sup_client[n_cpt];
						int i,j = 0;
						for(i=0;i<n_cpt;i++){
							if(client[i].solde > mt_sup){
								sup_client[j] = client[i];
								j++;
							}		 
						}
						printf("\n\t\t\tAffichage par ordre ascendant:\n");
						print_ascendants(sup_client,j);
						print_clients(sup_client,j);
					}
					else if(KJ == 5){
						system("cls");
						float mt_sup;
						do{
							printf("\n\n\t\tMantant (Borne superieur): ... ");
							scanf("%f",&mt_sup);
						}while(mt_sup <= 0);
						Client sup_client[n_cpt];
						int j = 0,i;
						for(i=0;i<n_cpt;i++){
							if(client[i].solde > mt_sup){
								sup_client[j] = client[i];
								j++;
							}		 
						}
						printf("\n\t\t\tAffichage par ordre descendant:\n");
						print_descendants(sup_client,j);
						print_clients(sup_client,j);
					}
					else if(KJ == 2){
						system("cls");
						print_descendants(client,n_cpt);
						printf("Affichage par ordre ascendant:\n");
						print_clients(client,n_cpt);
					}
					else if(KJ == 6){
						char add_c[50] = "no";
						do{
							system("cls");
							char add_v[50];
							printf("\n\tNon a rechercher.... ");
							scanf("%s",add_v);
							Client *s = searsh(client,n_cpt,add_v);
							if( s != NULL){
								print_client(*s);
							}
							else 
								printf("N'exist pas.\n");
							printf("\n\tChercher un autre client (yes,no).... ");
							scanf("%s",add_c);
							system("cls");
						}while(strcmp(add_c, "yes") == 0 || strcmp(add_c, "YES") == 0);
				}
				else 
					printf("Hors services ......\n");
				printf("\n\n\tAutre Afficahe (yes,no).... ");
				scanf("%s",add_c);
				}while(strcmp(add_c, "yes") == 0 || strcmp(add_c, "YES") == 0);
				system("cls");
				break;
			}
			case 6 : {
				system("cls");
				int i;
				print_descendants(client,n_cpt);
				Client sup_client[n_cpt];
				int j=0;
				for(i=0;i<3;i++){
		        	client[i].solde *= 1.013;
		        	sup_client[j] = client[i];
		        	j++;
				}
				print_clients(sup_client,j);
				break;
			}
			case 7 : {
					system("cls");
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
				system("cls");
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
			printf("\n\tMenu principale:(yes,no).....  ");
			scanf("%s",isOk);
			if(strcmp(isOk, "yes") == 0 || strcmp(isOk, "YES") == 0);
			else choix = 0;
		}
	}while (choix != 0);
	FILE *q = fopen("data.txt","w");
	int i;
    for(i=0;i<n_cpt;i++)
        fprintf(q,"%s %s %s %f\n",client[i].CIN,client[i].nom,client[i].prenom,client[i].solde);
    fclose(q);
	return 0;
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
Client *searsh(Client client[], int nb, char *nom){
	int i;
	for (i=0; i<nb; i++){
		if (strcmp(strupr(nom), strupr(client[i].CIN)) == 0){
			return &client[i];
		}
	}
	return NULL;
}
void print_infos(){
	printf(
	"\n\n\t\tCette application permet de gerer les comptes bancaires de plusieurs clients."
	"\n\n\t\tI- L'application faire des operations bancaires."
    "\n\n\t\tII- L'application offrir un menu qui permet de choisir l'operationaà effectuer."
	"\n\n\t\tIII- Vous pouvez retourner au menu principal apres chaque operation:\n\n");
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
	printf("\n\n\tAffichage\n");
	printf("%20s ........ %10s ........ %10s ........ %s\n", "Nom", "Prenom","CIN" ,"Solde");
	printf("%20s_________%10s_________%10s_________%s\n\n", "_____", "_______","______" ,"_______");
	for (i=0; i<nb; i++){
		print_client(c[i]);
	}
}
void print_client(Client c){
	printf("%20s -------- %10s -------- %10s -------- %.2f\n", c.nom, c.prenom,c.CIN ,c.solde);
}
void print_ascendants(Client client[], int nb){
	int i;
	for (i=0; i<nb-1; i++){
		if(client[i].solde > client[i+1].solde){
			Client cache = client[i];
			client[i] = client[i+1];
			client[i+1] = cache;
			i = -1;
		}
	}
}
void print_descendants(Client client[], int nb){
	int i;
	for (i=0; i<nb-1; i++){
		if(client[i].solde < client[i+1].solde){
			Client cache = client[i];
			client[i] = client[i+1];
			client[i+1] = cache;
			i = -1;
		}
	}
}
int menu_print(){
	int c;
	printf("\n\t\tAffichage:");
	printf("\n\t1-Aleatoire:");
	printf("\n\t2-Par Ordre Ascendant:");
	printf("\n\t3-Par Ordre Descendant:");
	printf("\n\t4-Par Ordre Ascendant:");
	printf("\n\t\t-les comptes bancaires ayant un montant supérieur a un chiffre introduit:");
	printf("\n\t5-Par Ordre Descendant:");
	printf("\n\t\t-les comptes bancaires ayant un montant supérieur a un chiffre introduit:");
	printf("\n\t6-Recherche par CIN:  ");
	printf("\n\tVotre choix:  ");
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
	}while(c<0 || c>3);
//	fflush(stdin);
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




