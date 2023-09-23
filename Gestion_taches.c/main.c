#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Projet Fin SAS: gestion des taches
enum statut {a_realiser, en_cours_realisation, finalisee};

typedef struct
{
    int heure;
    int jour;
    int mois;
    int annee;
} dates;

typedef struct
{
    int identifiant;
    char titre[100];
    char description[400];
    dates deadline;
    enum statut nvStatut;
} donnee;

int n, compt = 0;  // GLOBAL VARIABLES
donnee tache[300];
// PROTOTYPES DE FUNCTION======================================
void menu();
void ajouter_une_tache();
void ajouter_plus_taches();
void affichage();
void modification();
void supprimer();
void recherche();
void statistique();
// funtion for using
void tri_alpha();
void tri_deadline();
int tache_info(donnee tache[], int compt);
void exit_program(int error);
void recherche_titre(donnee tache[], int compt, const char *titre);
void recherche_Id(donnee tache[], int compt, int identifiant);
int tache_info(donnee tache[], int compt);
int main()
{
    menu();
    return 0;
}

void menu() //MENU
{
    system("cls");
    int choix;
    printf("________________________________________________________________________________________________________________________\n");
    printf("________________________________________________TO DO LIST______________________________________________________________\n\n\n");
    printf("1 - ajouter une nouvelle tache.");
    printf("                         2 - ajouter plusieurs nouvelles taches.\n\n");
    printf("3 - affichier la liste de toutes les taches.");
    printf("             4 - modifier une tache.\n\n");
    printf("5 - supprimer une taches.");
    printf("                               6 - rechercher une tache.\n\n");
    printf("7 - statistiques.");
    printf("                                       8 - exit.\n\n");
    printf("________________________________________________________________________________________________________________________\n");
    printf("________________________________________________________________________________________________________________________\n");
    printf("Entrez votre choix: ");

    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        ajouter_une_tache();
        break;
    case 2:
        ajouter_plus_taches();
        break;
    case 3:
        affichage();
        break;
    case 4:
        modification();
        break;
    case 5:
        supprimer();
        break;
    case 6:
        recherche();
        break;
    case 7:
        statistique();
        break;
    case 8:
        exit_program(0);
        break;
    default:
        system("cls");
        menu();
    }
}

int tache_info(donnee tache[], int compt)
{
    printf("entrez l' identifiant: "); //id
    scanf("%d", &tache[compt].identifiant);
    printf("Entrez le titre de la tache: "); //title
    scanf(" %[^\n]", tache[compt].titre);
    printf("Entrez la description: "); // description
    scanf(" %[^\n]", tache[compt].description);
    printf("statut de la tache\n1 - a realiser\n2 - en cours de realisation\n3 - finalisee\nEntrez votre choix: "); // STATU
    scanf("%d", &n);
    tache[compt].nvStatut = n - 1;
    printf("Entrez la date de la deadline (jour/mois/annee): "); //date
    scanf("%d/%d/%d", &tache[compt].deadline.jour, &tache[compt].deadline.mois, &tache[compt].deadline.annee);
    printf("entrez l'heure de la deadline: "); //time
    scanf("%d", &tache[compt].deadline.heure);
    return compt + 1; // Return compt  KAYTZAD BI 1
}
void ajouter_une_tache()
{
    system("cls");
    int choix;
    printf("\n________________________________AJOUTER UNE NOUVELLE TACHE ____________________________________________\n\n");
   compt = tache_info(tache, compt);
    system("cls");
    printf("\nVOTRE TACHE A ETE AJOUTEE AVEC SUCCES\n_________________________________________|\n\n"); //DONE
    printf("1 - ajouter une autre tache.\n");
    printf("2 - revenir au menu.\n");
    printf("3 - deconnexion.\n\n\n");

    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        ajouter_une_tache();
        break;
    case 2:
        menu();
        break;
    case 3:
        exit_program(0);
        break;
    default:
        exit_program(1); // EXIT  BI ERROR
    }
}

void ajouter_plus_taches()
{
    system("cls");
    int num_taches;
    printf("\n__________________________________Ajouter plusieurs nouvelles taches_________________________________________\n\n");
    printf("entrez le nombre de taches que vous souhaitez ajouter: ");
    scanf("%d", &num_taches);

    for (int i = 0; i < num_taches; i++)
    {
        if (compt >= 300)
        {
            printf("Nombre maximal de taches. Sortie...\n");
            exit_program(1);
        }

        if (i == 0)
        {
            printf("\n\nentrez les informations de la 1ere tache:\n");
        }
        else
        {
            printf("\n\nentrez les informations de la tache %d:\n", i + 1);
        }

        compt = tache_info(tache, compt);
    }

    int choix;
    system("cls");
    printf("\ntoutes les taches ont ete ajoutees avec succes.\n");
    printf("1 - ajouter quelques autres taches.\n");
    printf("2 - revenir au menu.\n");
    printf("3 - deconnexion.\n");
    printf("__________________________________________________________\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        ajouter_plus_taches();
        break;
    case 2:
        menu();
        break;
    case 3:
        exit_program(0);
        break;
    default:
        exit_program(0);
    }
}

void affichage()
{
    system("cls");
    int tri_choix;  //sous menu
    printf("\n1 - lister toutes les taches par ordre alphabetique de titre.\n"); //croissant
    printf("2 - lister toutes les taches par ordre de deadline.\n");         //decroissant
    printf("3 - revenir au menu.\n");
    printf("4 - deconnexion.\n");
    printf("__________________________________________________________________________\n");

    printf("Entrez votre choix: ");
    scanf("%d", &tri_choix);

    switch (tri_choix)
    {
    case 1:
        tri_alpha();
        break;
    case 2:
        tri_deadline();
        break;
    case 3:
        menu();
        break;
    case 4:
        exit_program(0);
        break;
    default:
        exit_program(0);
    }
    // Trier les taches par deadline.

//Afficher les taches dont le deadline est dans 3 jours ou moins.
}

void tri_alpha()
{
    system("cls");
    int i, j;
    donnee temp;

    for (i = 0; i < compt - 1; i++)
    {
        for (j = 0; j < compt - i - 1; j++)
        {
            if (strcmp(tache[j].titre, tache[j + 1].titre) > 0)
            {
                temp = tache[j];
                tache[j] = tache[j + 1];
                tache[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < compt; i++)
    {
        printf("Identifiant: %d\n", tache[i].identifiant);
        printf("Titre: %s\n", tache[i].titre);
        printf("Description: %s\n", tache[i].description);
        printf("Deadline: %d/%d/%d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("Statut: %d\n", tache[i].nvStatut);
        printf("___________________________________________________________\n");
    }
}
void recherche()
{
    system("cls");
    int choix;
     int id;
    char titre_rech[100];
     // sous menu
    printf("\n____________________________________RECHERCHE UNE TACHE_______________________________________________\n");
    printf("\n1 _ Rechercher une tache par son Identifiant:");
    printf("\n2 _ Rechercher une tache par son Titre:");
    printf("3 - revenir au menu.\n");
    printf("4 - deconnexion.\n");
    printf("\n______________________________________________________________________________________________\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("Entrez l'identifiant de la tache a rechercher: ");
        scanf("%d", &id);
        recherche_Id(tache, compt, id);
        break;
    case 2:
        printf("Entrez le titre de la tache a rechercher: ");
        scanf(" %[^\n]", titre_rech);
        recherche_titre(tache, compt, titre_rech);
        break;
        case 3:
        menu();
        break;
    case 4:
        exit_program(0);
        break;
    default:
        exit_program(1);
    }
 }
// Rechercher une tache par son Identifiant. LINEER SEARCH SEQEN---------------------------------
void recherche_Id(donnee tache[], int compt, int identifiant)
{
    int found = 0;
    for (int i = 0; i < compt; i++)
    {
        if (tache[i].identifiant == identifiant)
        {
            printf("Tache trouvee par identifiant:\n");
            printf("Identifiant: %d\n", tache[i].identifiant);
            printf("Titre: %s\n", tache[i].titre);
            printf("Description: %s\n", tache[i].description);
            printf("Deadline: %d/%d/%d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
            printf("Statut: %d\n", tache[i].nvStatut);
            found = 1; //  found
            break;     // Exit  found the task
        }
    }

    if (!found)
    {
        printf("Tache non trouvee avec l'identifiant %d.\n", identifiant);
    }
}

// Rechercher une tache par son Titre // LINEAR SEARCH --------------------------------------------
void recherche_titre(donnee tache[], int compt, const char *titre)
{
    int found = 0; // found
    // Linear search
    for (int i = 0; i < compt; i++)
    {
        if (strcmp(tache[i].titre, titre) == 0)
        {
            //  found
            printf("Tache trouvee par titre:\n");
            printf("Identifiant: %d\n", tache[i].identifiant);
            printf("Titre: %s\n", tache[i].titre);
            printf("Description: %s\n", tache[i].description);
            printf("Deadline: %d/%d/%d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
            printf("Statut: %d\n", tache[i].nvStatut);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Aucune tache trouvee avec le titre \"%s\".\n", titre);
    }
}
void tri_deadline()
{

}

void modification()
{

//Modifier la description d'une tache.

//Modifier le statut d'une tache.

//Modifier le deadline d'une tach
}
 //Supprimer une tache par identifiant ===================================================
void supprimer()
{
    system("cls");
    int id ;
    int choix;
    printf("\n____________________________Supprimer une taches_________________________________________\n");
    printf("Entrez l'identifiant de tache que vous souhaitez supprimer: ");
    scanf("%d", &id);
    recherche_Id(tache, compt, id);
    printf("\n1 - revenir au menu.\n");
    printf("2 - deconixion.\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    if( choix == 1 )
    {
        menu();
    }
    else if( choix== 2 )
    {
        exit_program(0);
    }
}
void statistique()
{
    system("cls");
    /*int choix;
    printf("\n_______________Statistique____________________\n");
    printf("\n\n\n");
    printf("1 - Afficher le nombre total des taches\n");
    printf("2 - Afficher le nombre de taches completes et incompletes.\n\n");
    printf("3 - Afficher le nombre de jours restants jusqu'au d'lai de chaque tache.\n");
    printf("4 - retour au menu\n");
    printf("5 - deconixion.\n");
    print("___________________________\n")
    printf("Entrez votre choix: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            system("cls");

            break;
        case 2:
            system("cls");
            break;
        case 3:
            system("cls");
            break;
        case 4:
            menu();
            break;
        case 5:
            exit_program(0);
            break;
    }
//Afficher le nombre total des taches.

//Afficher le nombre de taches completes et incompletes.

//Afficher le nombre de jours restants jusqu'au d lai de chaque tache.

*/
}
void exit_program(int error)
{
    system("cls");
    printf("Vous etes deconnecte\n");
    exit(error);
}
