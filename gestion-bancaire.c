#include <stdio.h>
#include <string.h>

struct personne{
	char nom[20], numero[11];
};

typedef struct personne PERS;

void saisir_personne(PERS *pp);
void saisir_repertoire(PERS rep[], int nb);
void afficher_repertoire(PERS rep[], int nb);
char *chercher_personne(PERS rep[], int nb, char *nom);

int main(){
	PERS monRep[5];
	int choix;
	char nom[20], *pnum;
	saisir_repertoire(monRep, 5);
	do
	{
		do
		{
			printf("\nMenu_Principale_Principale:\n");
			printf("1-afficher le contenu du répertoire\n");
			printf("2-chercher le numéro d'une personne\n");
			printf("3-quitter le programme\n");
			printf("Votre choix : ");
			scanf("%d", &choix);
		}
		while (choix < 1 || choix > 3);
		switch (choix)
		{
			case 1 : afficher_repertoire(monRep, 5);
				 break;
			case 2 : printf("nom a rechercher : ");
			         scanf("%s", nom);
				 pnum = chercher_personne(monRep, 5, nom);
				 if (pnum == NULL)
				 {
				 	printf(" Personne inexistante\n");
				 }
				 else
				 {
				 	printf("--> Numero de %s: %s\n", nom, pnum);
				 }
				 break;
			default : break;
		}
	}
	while (choix != 3);
	return 0;
}

void saisir_personne(PERS *pp)
{
	printf("Nom : "); scanf("%s", pp->nom);
	printf("Numero : "); scanf("%s", pp->numero);
}

void saisir_repertoire(PERS rep[], int nb)
{
	int i;
	printf("Saisie du repertoire de %d personnes :\n", nb);
	for (i=0; i<nb; i++)
	{
		saisir_personne(&rep[i]);
	}
}

void afficher_repertoire(PERS rep[], int nb)
{
	int i;
	printf("Affichage du repertoire\n");
	printf("%20s ...... Numero\n", "Nom");
	for (i=0; i<nb; i++)
	{
		printf("%20s ...... %s\n", rep[i].nom, rep[i].numero);
	}
}

char *chercher_personne(PERS rep[], int nb, char *nom)
{
	int i;
	for (i=0; i<nb; i++)
	{
		if (strcmp(nom, rep[i].nom) == 0)
		{
			return rep[i].numero;
		}
	}
	return NULL;
}
