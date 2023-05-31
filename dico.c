
int nombreAleatoire(int nombreMax)
{
    //srand(time(NULL));
    return (rand() % nombreMax);
}

int piocherMot(char *motPioche)
{
	
 FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
 int nombreMots = 0, numMotChoisi = 0, i = 0;
 int caractereLu = 0;
 dico = fopen("Dictionnaire.txt", "r"); // On ouvre le dictionnaire en lecture seule
 // On v�rifie si on a r�ussi � ouvrir le dictionnaire
 
if (dico == NULL) // Si on n'a PAS r�ussi � ouvrir le fichier
 {
 printf("\nImpossible de charger le dictionnaire de mots");
 return 0; // On retourne 0 pour indiquer que la fonction a �chou�
 // � la lecture du return, la fonction s'arr�te imm�diatement.
 }

 // On compte le nombre de mots dans le fichier (il suffit de compter les
 // entr�es \n
 do
 {
 caractereLu = fgetc(dico);
 if (caractereLu == '\n')
 nombreMots++;
 } while(caractereLu != EOF); //EOF =-1 au cas d'erreur 

 numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard entre 0 et nombreMots-1 avec rand 
 // On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv� au bon mot
 
 rewind(dico); // retourne le pointeur  vers le debut de fichier  dico 

 while (numMotChoisi > 0)
 {

 caractereLu = fgetc(dico);
if (caractereLu == '\n')
 numMotChoisi--;
 }

 /* Le curseur du fichier est positionn� au bon endroit.
 On n'a plus qu'� faire un fgets qui lira la ligne */
fgets(motPioche,100, dico);
printf(motPioche);

 // On vire le \n � la fin

 motPioche[strlen(motPioche) - 1] = '\0';

 fclose(dico);
 return 1; // Tout s'est bien pass�, on retourne 1
}

//fction récursive 
void insererMot(char *mot, TArbre *noeud)
{
    if (*noeud != NULL)
    {
                if (mot[0] != '\0') //pas fin de mot                     mot ="alade"   ,mot ="lade"
                {
                        if ((*noeud)->caractere == mot[0])                   // r= b,r#a  donc cond faux 
                        {
                            mot++; // effacer premier caractere
                            insererMot(mot, &((*noeud)->filsGauche));//descendre gauche
                        }
                        else                   
                        {
                            if((*noeud)->caractere > mot[0]){ //ordre alphabetique    // comparer code asci b>a  codeasc(b)=98   ,   codeasc(a)=97 
                                    TArbre n = arbreCons(mot[0], 0, NULL, *noeud); //Null est le filsG , noeud est le FilsD inserer a f partie droite
                                    mot++;               //  mot="lade"
                                    *noeud = n;   // FilsD prend sous arbre construit n 
                                    insererMot(mot, &((*noeud)->filsGauche)); // la partie gauche celle du mot
                            }else{
                                if ((*noeud)->filsDroit != NULL)//descendre droite
                                {
                                    insererMot(mot, &((*noeud)->filsDroit));
                            
                                }
                                else //caractere n'existe pas
                                {
                                    (*noeud)->filsDroit = arbreCons(mot[0], 0, NULL, NULL);
                                    insererMot(mot, &(*noeud)->filsDroit);
                                }
                            }
                        }
                }
                
                else if (mot[0] == '\0' && (*noeud)->caractere != '\0')//cas particulier
                            {
                                        TArbre n = arbreCons('\0', 1, NULL, *noeud); 
                                        *noeud = n;
                            }
                else if (mot[0] == '\0' && (*noeud)->caractere == '\0') //fin de mot
                            {
                                (*noeud)->nbrOccurrence++;
                                 mot[0] == (*noeud)->nbrOccurrence;
                            }
            }
    else
    {
            if (mot[0]!= '\0')  // 3andi kelma 
            {
                *noeud = arbreCons(mot[0], 0, NULL, NULL);
                mot++;
                insererMot(mot, &((*noeud)->filsGauche)); // La suite du mot dans la partie gauche selon ennoncé 
            }
            else  // Si j'ai /0 c'est a dire j'ai un mot  donc  nbocc=1 
            {
                *noeud = arbreCons('\0', 1, NULL, NULL); 
            }
    }
}

//Permet d'ajouter un mot au dictionnaire
void dicoInsererMot(char *mot, TArbre*arbre)
{
    if (strlen(mot) > 0)
    {
        if (*arbre == NULL)            // au debut mon arbre est vide 
            *arbre = arbreConsVide();   // construire mon arbre

        insererMot(mot, arbre); // inserer mon mot

    }
}

void afficherMots(char *mot, Noeud *noeud)
{
    if (noeud != NULL)
    {
        if (noeud->caractere != '\0')
        {
            if (noeud->filsGauche != NULL) //ajouter caractere a mot
            {
                strcat(mot, (char[2]){noeud->caractere, '\0'});
                afficherMots(mot, noeud->filsGauche);
            }
            mot[strlen(mot) - 1] = '\0'; //supprimer le dernier caractere
            if (noeud->filsDroit != NULL) //fait rien et descendre droite
            {
                afficherMots(mot, noeud->filsDroit);
            }
        }
        else
        { 
            printf("(%i) %s\n", noeud->nbrOccurrence,mot);//aficher mot
            if (noeud->filsDroit != NULL)
                afficherMots(mot, noeud->filsDroit);
        }
    }
}

//Permet d'afficher le dictionnaire 
void dicoAfficher(TArbre a)
{
    printf("\n*******************************DICTIONNAIRE*******************************\n");
    char mot[100] = "";
    afficherMots(mot, a);
    printf("\n/*******************************DICTIONNAIRE*******************************/\n");
}




//retourne le nombre des mots diff�rents
int dicoNbMotsDifferents(TArbre a){

    if (a == NULL)
        return 0;
	int test=(a->caractere == '\0')?1:0; // condition ? value_if_true : value_if_false
    return  test+dicoNbMotsDifferents(a->filsGauche)  + dicoNbMotsDifferents(a->filsDroit);
}
//retourne le nombre des mots total
int dicoNbMotsTotal(TArbre a){

    if (a == NULL)
        return 0;
	int test=(a->caractere == '\0')?a->nbrOccurrence:0; // condition ? value_if_true : value_if_false
    return  test+dicoNbMotsTotal(a->filsGauche)  + dicoNbMotsTotal(a->filsDroit);
}
    //retourne le nombre d�apparitions d�un mot
int dicoNbOccMot(char mot[],TArbre noeud){
	
    
	  if(noeud != NULL){
        if(mot[0] == noeud->caractere ){
            if(mot[0] == '\0'){
                  return noeud->nbrOccurrence;
            }else{
                mot++;
                return dicoNbOccMot(mot,noeud->filsGauche);
            }
        }
        return dicoNbOccMot(mot,noeud->filsDroit);
      }
      
      return 0;
}




////////////
//retourne le nombre d'occurence d'une lettre
int occchar(TArbre a,char c){

    if (a == NULL)
        return 0;
	int test=(a->caractere == c)?1:0; 
    return  test+occchar(a->filsGauche,c)  + occchar(a->filsDroit,c);
}
//retourne le nombre des lettres

int totalchar(TArbre a){

    if (a == NULL)
        return 0;
	int test=(a->caractere != '\0')?1:0;
    return  test+totalchar(a->filsGauche)  + totalchar(a->filsDroit);
}

//retourne les fr�quences des lettres dans le dictionnaire
void lettrespercentage( TArbre a){
	 char c;
	
	         printf("_______________________________\nFrequence des lettres\n_______________________________\n");

    for (c = 'a'; c <= 'z'; ++c)
        printf("\t%c:%.1f%% \n", c,( (double)occchar(a,c)/ (double)totalchar(a))*100); // (nbocc (lettre)/ nbtotale )*100
	
}



