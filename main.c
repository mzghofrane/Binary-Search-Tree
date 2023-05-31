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
   int number ;  int i=0; 
   int result1;
   char c;
   char *mot= malloc( 255 );

	dico = arbreConsVide();  // Construction de l'arbre dico
	printf("Ceci la liste des mots choisis a partir du dictionnaire \n");
   while(i<3) // choisir 6 mot {i:0,1,2,3,4,5}
   {

      int x=piocherMot(mot);// choisi 6 mots au hasard et à chaque fois tjr le x est 1 
         if(x==1){
         dicoInsererMot(mot,&dico); //  elle insére ces 5 mots dans l'arbre 
         i++;
      }

   }

printf("Voulez vous ajouter un mot \n" );
while ( scanf("%c", &c) )
{ 
  if ( c=='o')    
   {
   printf("Taper le mot a inserer\n");
        
   scanf("%s", mot) ;
   dicoInsererMot(mot,&dico);
   printf("Voici l'arbre apres l'insertion \n");
   afficherArbre2(dico,0);
   break;
   }
   else if ( c == 'n') break; 

}
  // dicoInsererMot("cas",&dico);
printf("\n*******************************ARBREF FORME 1*******************************\n");
afficherArbre2(dico,0); // afficher la structure
afficherArbre(dico);  // **********Arbre****************
dicoAfficher(dico);// **********Dico ****************

printf("\n\nArbre est vide ou rempli ?) : %i \n",arbreEstVide(dico));
printf("Racine lettre : %c \n",arbreRacineLettre(dico));
//printf("Racine Nombre Occurrence : %i \n",arbreRacineNbOcc(dico));
TArbre racineFilsDroit = noeudFilsDroit(dico);
TArbre racineFilsGauche = noeudFilsGauche(dico);
printf("Racine fils gauche lettre : %c \n",arbreRacineLettre(racineFilsGauche ));
printf("Racine fils droit lettre  : %c \n",arbreRacineLettre(racineFilsDroit));
printf("Nbr Mots Total : %i \n",dicoNbMotsTotal(dico));
printf("Nbr Mots different : %i \n",dicoNbMotsDifferents(dico));
printf("Voulez-vous afficher le nombre de occurrence du quel mot?\n" );

int result ;
while ( result=scanf("%s", mot) )
{ 
  if ( result!=0)    
   {
   number=dicoNbOccMot(mot,dico);
      if (number !=0){
      
      printf("le nombre d'occurence de  %s est : %d \n", mot,number);
      break;
     }
      else { printf("le mot n'exite pas dans dictionnaire\n");
             break;
      }

   }

}

lettrespercentage(dico);
arbreSuppr(&dico);
printf("Arbre est vide ? : %i \n",arbreEstVide(dico));
afficherArbre2(dico,0); // afficher la structure
return 0;    
}

