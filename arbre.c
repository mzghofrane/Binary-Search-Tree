#define MAX(x, y) (((x) > (y)) ? (x) : (y))

//Construire Arbre Vide
TArbre arbreConsVide()
{
    return NULL;
}

//Retourne si l'arbre est vide
bool arbreEstVide(TArbre a)
{
    if (a == NULL)
    {
        return true;
    }
    return false;
}
//Construire noeud
TArbre arbreCons(char caractere, int entier, TArbre filsGauche, TArbre filsDroit)
{
    TArbre a = (Noeud *)malloc(sizeof(Noeud));
    a->caractere = caractere;
    a->nbrOccurrence = entier;
    a->filsGauche = filsGauche;
    a->filsDroit = filsDroit;
    return a;
}
//retorune le caractere du racine
char arbreRacineLettre(TArbre a)
{
    if (!arbreEstVide(a))
    {
        return a->caractere;
    }
    return '\0';
}

//retorune le nombre d'occurence du racine
int arbreRacineNbOcc(TArbre a)
{
    if (!arbreEstVide(a))
    {
        return a->nbrOccurrence;
    }
    return 0;
}
//Retourne fils Gauche
TArbre noeudFilsGauche(TArbre a)
{
    if (a != NULL)
    {
        return a->filsGauche;
    }
    return NULL;
}
//Retourne fils Droit
TArbre noeudFilsDroit(TArbre a)
{
    if (a != NULL)
    {
        return a->filsDroit;
    }
    return NULL;
}

//Permet de supprimer l'arbre
void arbreSuppr(TArbre *noeud)
{
    if (*noeud != NULL)
    {
        arbreSuppr(&((*noeud)->filsDroit));
        arbreSuppr(&((*noeud)->filsGauche));
        free(*noeud);
        *noeud = NULL;
    }
}


//Retroune l'hauteur de l'arbre
int hauteurArbre(TArbre a)
{
    if (a != NULL)
    {
        return 1 + MAX(hauteurArbre(a->filsGauche), hauteurArbre(a->filsDroit));
    }
    return -1;
}

// c'est une focntion récursive  pour faire affichage des fG et FD

void afficherNoeuds(TArbre noeud, int espace)
{
    if (noeud != NULL)
    {
    	int i;
        for (i = 0; i < espace; i++)
            printf("*");

        if (noeud->caractere != '\0')
        {
            
            if(noeud->caractere == ' '){
                printf("NULL\n");
            }else{
                printf("%c\n", noeud->caractere);
            }
        }
        else
        {
            printf("\\%d\n", noeud->nbrOccurrence); // on a changer \0 par le nbre d'occurence juste dans l'affichage 
        }
        if (noeud->filsGauche != NULL)
            printf("(FG)"); //Fils Gauche
        afficherNoeuds(noeud->filsGauche, espace + 1);
        if (noeud->filsDroit != NULL)
            printf("(FD)"); //Fils Droit
        afficherNoeuds(noeud->filsDroit, espace + 1);
    }
}

//Permet d'afficher l'arbre
void afficherArbre(TArbre a)
{
    if (a != NULL)
    {
        printf("\n*******************************ARBRE FORME 2*******************************\n");
        printf("\nHauteur de l'arbre : %i\n\n", hauteurArbre(a));
        printf("(R)"); //racine
        afficherNoeuds(a, 1);
        
    }
}

// Autre fonction qui permet d'afficher l'arbre parcours infixe (SAD, R, SAG)
void afficherArbre2(TArbre arbre, int espace)
{
    if (arbre == NULL)
        return;

    espace += 10;
    
    // Afficher le sous-arbre droit  
    afficherArbre2(arbre->filsDroit,espace);

    // Afficher le noeud courant
    if (arbre->caractere != '\0'){
    for (int i =0; i <espace ; i++)
       printf(" "); 
       printf("%c\n", arbre->caractere); 
      }
     else{
        for (int i =0; i < espace; i++)
        printf(" "); 
        printf("(%d)\n", arbre->nbrOccurrence);
     }
  
    // Afficher le sous-arbre gauche
    afficherArbre2(arbre->filsGauche, espace);


    
}








