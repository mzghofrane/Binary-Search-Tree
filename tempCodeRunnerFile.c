//Pour Tester les Fonctions Primitives de l'Arbre et de Dictionnaire
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "arbre.h"
#include "arbre.c"
#include "dico.h"
#include "dico.c"

int main(){
   TArbre dico;
   int number ;
	dico = arbreConsVide();  // dico est l'arbre vide

   int i=0;
   //srand(time(NULL)); // choose a random number 

	char *mot= malloc( 255 );
   while(i<6)
   {

      int x=piocherMot(mot);// choisi 5 mots au hasard et à chaque fois tjr le x est 1 
      
      if(x==1){
         dicoInsererMot(mot,&dico); //  elle insére ces 5 mots(boucle while ) dans l'arbre w inserer heya l3adya mte3na taw nemchiw lel dicoInsererMot
         i++;
      }

   }
   dicoInsererMot("cas",&dico);
  
   

/*
dicoInsererMot("cas",&dico);
dicoInsererMot("ce",&dico);
dicoInsererMot("ces",&dico);
dicoInsererMot("ci",&dico);
dicoInsererMot("de",&dico);
dicoInsererMot("des",&dico);
dicoInsererMot("do",&dico);
*/
afficherArbre2(dico,0);
afficherArbre(dico);
//dicoAfficher(dico);
printf("\n\nArbre est vide? : %i \n",arbreEstVide(dico));
printf("Racine lettre : %c \n",arbreRacineLettre(dico));
//printf("Racine Nombre Occurrence : %i \n",arbreRacineNbOcc(dico));
TArbre racineFilsDroit = noeudFilsDroit(dico);
TArbre racineFilsGauche = noeudFilsGauche(dico);
printf("Racine fils gauche lettre : %c \n",arbreRacineLettre(racineFilsGauche ));
printf("Racine fils droit lettre  : %c \n",arbreRacineLettre(racineFilsDroit));
printf("Nbr Mots Total : %i \n",dicoNbMotsTotal(dico));
printf("Nbr Mots different : %i \n",dicoNbMotsDifferents(dico));
printf("Tu veux afficher le nombre de occurrence mot du quel mot?\n" );
int result ;
while ( result=scanf("%s", mot) )
{ 
  if ( result!=0)    
   {
   number=dicoNbOccMot(mot,dico);
      if (number !=0){
      printf(" %s existe dans le dictionnaire , ", mot );
      printf("le nombre d'occurence de ce mot est %d \n",number);
     }
      else { printf("le mot n'exite pas dans dico\n");
             break;
      }
      
     

   }

}

lettrespercentage(dico);
arbreSuppr(&dico);
printf("Arbre est vide ? : %i \n",arbreEstVide(dico));
    
    
return 0;    
}

