#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	typedef struct{
		int jour;
		int mois;
		int annee;
	}date_d_echeance;
	typedef struct{
		char titre[20];
		char description[20];
		char preorite[20];
		date_d_echeance date;	
	}tache;
	tache ts[10];
	int taille=0;
	int ajouter1=0;
	void ajouter(){
		printf("donner le titre : ");
		scanf("%s",&ts[taille].titre);
		printf("donner la descriprion : ");
		scanf("%s",&ts[taille].description);
			int choix;
		do{
			printf("entrer preorite (1-high 2-low)");
			scanf("%d",&choix);
			switch(choix){
				case 1 :strcpy(ts[taille].preorite,"high");
				break;
				case 2 :strcpy(ts[taille].preorite,"low");
				break;
				default:printf("erreur!!\n");
			}
		}while(choix!=1 && choix!=2);
		
		do {
		printf("donner le jour (doit etre > � 31): ");
		scanf("%d",&ts[taille].date.jour);
		if(ts[taille].date.jour<1 || ts[taille].date.jour>31){
			printf("jour < � 31\n");
		}
	} while(ts[taille].date.jour<1 || ts[taille].date.jour>31);
	do {
		printf("donner le mois(doit etre > � 12): ");
		scanf("%d",&ts[taille].date.mois);
		if(ts[taille].date.mois<1 || ts[taille].date.mois>12){
			printf("mois < � 12\n");
		}
	} while(ts[taille].date.mois<1 || ts[taille].date.mois>12);
		do {
		printf("donner l annee (doit etre > � 2024): ");
		scanf("%d",&ts[taille].date.annee);
		if(ts[taille].date.annee<2024){
			printf("annee < � 2024\n");
		}
	} while(ts[taille].date.annee<2024);
	
	
		taille++;
		ajouter1=1;
	}
	void afficher(){
		int i;
		for(i=0;i<taille;i++){
			printf("le titre est :%s\n",ts[i].titre);
			printf("la description est :%s\n",ts[i].description);
			printf("la preorite est :%s\n",ts[i].preorite);
			printf("le jour est :%d\n",ts[i].date.jour);
			printf("le mois est :%d\n",ts[i].date.mois);
			printf("l'annee est :%d\n",ts[i].date.annee);
		}
	}
	void modifier(){
		int indice;
		printf("Enter indice :");
		scanf("%d",&indice);
		if(indice<0 || indice>taille){
			printf("indice invalide !");
		}else{
				printf("Entrer le nouveau titre (actuel: %s) : ",ts[indice].titre);
		scanf("%s",ts[indice].titre);
		printf("Entrer la nouvelle desrcription (actuel: %s) : ",ts[indice].description);
		scanf("%s",ts[indice].description);
		int choix;
		do{
			printf("entrer preorite (1- high  2-low)");
			scanf("%d",&choix);
			switch(choix){
				case 1 :strcpy(ts[indice].preorite,"high");
				case 2 :strcpy(ts[indice].preorite,"low");
				default:printf("erreur!!");
			}
		}while(choix!=1 || choix!=2);
		printf("Entrer le nouveau jour (actuel: %d) : ",ts[indice].date.jour);
		scanf("%d",&ts[indice].date.jour);
		printf("Entrer le nouveau mois (actuel: %d) : ",ts[indice].date.mois);
		scanf("%d",&ts[indice].date.mois);
		printf("Entrer le nouvelle (actuel: %d) : ",ts[indice].date.annee);
		scanf("%d",&ts[indice].date.annee);
			printf("modification reussite^^");
		}
	}
void Supprimer(){
int indice,i;
printf("Enter indice qui veux supprimer :");
scanf("%d",&indice);
	if(indice<0 || indice>taille){
			printf("indice invalide !");
		}else{
for(i=indice;i<taille;i++){
	ts[i]=ts[i+1];
}
taille--;
printf("suppresion reussite^^");
}
	
}
void filtrer(){
	int i;
	char filter[6];
	
	for(i=0;i<taille;i++){
		if(strcmp(ts[i].preorite,filter)==0){
		printf("le titre est :%s\n",ts[i].titre);
		printf("la description est :%s\n",ts[i].description);
		printf("la preorite est :%s\n",ts[i].preorite);
		printf("le jour est :%d\n",ts[i].date.jour);
		printf("le mois est :%d\n",ts[i].date.mois);
		printf("l'annee est :%d\n",ts[i].date.annee);
		printf("les titres filtr�s sont : %s",ts[i].titre);
		}else{
			printf("Aucune preorit� trouv�e!!");
		}
	}
}
int main() {
	int x;
	do {
	printf("\n Application de pointage \n");
	printf(" \n Menu \n");
	printf(" \n1- Ajouter une tache :\n");
	printf(" \n2- aficher une tache :\n");
	printf(" \n3- modifier une tache :\n");
	printf(" \n4- Supprimer une tache :\n");
	printf(" \n5- filtrer une tache :\n");
	printf(" \n6- Quitter. \n");
	printf("entrer votre choix : ");
	scanf("%d",&x);
	if(x==1){
		ajouter();
	}else if(ajouter1==1){
	switch(x){
		case 2: afficher();break;
		case 3: modifier();break;
		case 4: Supprimer();break;
		case 5: filtrer();break;
		case 6: printf("bonne journee");
		default: printf("Choix invalid !");
	}
		}else{
			printf("vous devez selectioner 'ajouter' pour accelerer aux autres options\n");
		}
	}while (x != 5 );
	return 0;
}