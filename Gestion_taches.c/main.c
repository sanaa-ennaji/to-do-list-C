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
    char titre[50];
    char description[100];
    dates deadline;
    enum statut st;
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
// funtions for using
void tri_alpha();
void tri_deadline();
void tache_info();
void exit_program(int error);
void recherche_titre();
void recherche_Id();
void modifier_deadline();
void modifier_description();
void modifier_statut();
void nb_taches_statut();
void retn();
int main()
{
    menu();
    return 0;
}
void menu()
{
    system("cls");
    int choix;
   printf("________________________________________________________________________________________________________________________\n");
    printf("________________________________________________TO DO LIST______________________________________________________________\n\n\n");
    printf("1 - ajouter une nouvelle tache.");
    printf("                         2 - ajouter plusieurs nouvelles taches.\n\n");
    printf("3 - affichier la liste de toutes les taches.");
    printf("            4 - modifier une tache.\n\n");
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
void tache_info()
{
    printf("entrez l' identifiant: "); //id
    scanf("%d", &tache[compt].identifiant);
    printf("Entrez le titre de la tache: "); //title
    scanf(" %[^\n]", tache[compt].titre);
    printf("Entrez la description: "); // description
    scanf(" %[^\n]", tache[compt].description);
    printf("statut de la tache(1 - a realiser,2 - en cours de realisation,3 - finalisee)\nEntrez votre choix: "); // STATU
    scanf("%d", &n);
    tache[compt].st = n - 1;
    printf("Entrez la date de la deadline (jour/mois/annee): "); //date
    scanf("%d/%d/%d", &tache[compt].deadline.jour, &tache[compt].deadline.mois, &tache[compt].deadline.annee);
    printf("entrez l'heure de la deadline: "); //time
    scanf("%d", &tache[compt].deadline.heure);
    ++compt;
}
void ajouter_une_tache()
{
    system("cls");
    int choix;  // sous menu
   printf("\n________________________________AJOUTER UNE NOUVELLE TACHE ____________________________________________\n\n");
    tache_info();
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
            printf("nombre maximal de taches.\n");
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

        tache_info();
         printf("________________________________________________________________________\n");
    }
    int choix;
    system("cls");  // sous menu
    printf("\ntoutes les taches ont ete ajoutees avec succes.\n");
    printf("1 - ajouter quelques autres taches.\n");
    printf("2 - revenir au menu.\n");
    printf("3 - deconnexion.\n");
    printf("____________________________________________________________________________\n");
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
void affichage() // AFFICHAGE______________________
{
    system("cls");
    int tri_choix;  //sous menu
    printf("\n1 - lister toutes les taches par ordre alphabetique de titre.\n");
    printf("2 - lister toutes les taches par ordre de deadline.\n");         //decroissant
    printf("3 - revenir au menu.\n");
    printf("4 - deconnexion.\n");
    printf("_________________________________________________________________\n");

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
        exit_program(2);
    }
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
            if (strcmp(tache[j].titre, tache[j+1].titre) > 0)
            {
                temp = tache[j];
                tache[j] = tache[j+1];
                tache[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < compt; i++)
    {
        printf("identifiant: %d\n", tache[i].identifiant);
        printf("titre: %s\n", tache[i].titre);
        printf("description: %s\n", tache[i].description);
        printf("deadline: %d/%d/%d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("(1 - a realiser,2 - en cours de realisation ,3 - finalisee)\nStatut: %d\n", tache[i].st +1);
        printf("____________________________________________________________________________\n");
    }
     retn();
}
void tri_deadline()
{
    system("cls");
    int i, j;
    donnee temp;

    for (i = 0; i < compt - 1; i++)
    {
        for (j = 0; j < compt - i - 1; j++)
        {
        int deadline_j = tache[j].deadline.annee * 365 + tache[j].deadline.mois * 30 + tache[j].deadline.jour;
        int deadline_j1 = tache[j + 1].deadline.annee * 365 + tache[j + 1].deadline.mois * 30 + tache[j + 1].deadline.jour;

            if (deadline_j > deadline_j1)
            {
                temp = tache[j];
                tache[j] = tache[j+1];
                tache[j+1] = temp;
            }
        }
    }
    printf("Taches triees par ordre de deadline :\n");
    for (int i = 0; i < compt; i++)
    {
        printf("identifiant: %d\n", tache[i].identifiant);
        printf("titre: %s\n", tache[i].titre);
        printf("description: %s\n", tache[i].description);
        printf("deadline: %d/%d/%d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("(1 - a realiser, 2 - en cours de realisation, 3 - finalisee)\nStatut: %d\n", tache[i].st+1);
    }
     retn();
}
void recherche()
{
    system("cls");
    int choix;
     // SOUS MENU
     printf("\n____________________________________RECHERCHE UNE TACHE_______________________________________________\n");
    printf("\n1 _ rechercher une tache par son Identifiant:");
    printf("\n2 _ rechercher une tache par son Titre:");
    printf("\n3 - revenir au menu.\n");
    printf("4 - deconnexion.\n");
    printf("\n_______________________________________________________________________________________________________\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        recherche_Id(); // appel dyal fonction
        break;
    case 2:
        recherche_titre(); // appl dyal fonction
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
// Rechercher tache par Identifiant---------------------------------
void recherche_Id()
{
     int id;
    printf("Entrez l'identifiant de la tache a rechercher: ");
        scanf("%d", &id);
    int choix;
    int av = 0;
    for (int i = 0; i < compt; i++)
    {
        if (tache[i].identifiant == id)
        {
            printf("tache trouvee par identifiant:\n");
            printf("identifiant: %d\n", tache[i].identifiant);
            printf("titre: %s\n", tache[i].titre);
            printf("description: %s\n", tache[i].description);
            printf("deadline: %d/%d/%d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
            printf("statut: %d\n", tache[i].st);
            av= 1;
            break;
        }
    }

    if (!av)
    {
        printf("tache non trouvee avec l'identifiant %d.\n", id);
    }
 retn();
}
// Rechercher une tache par Titre--------------------------------------------
void recherche_titre()
{
  char titre_rech[50];
   printf("Entrez le titre de la tache a rechercher: ");
   scanf(" %[^\n]", titre_rech);
    int av = 0;
    for (int i = 0; i < compt; i++)
    {
        if (strcmp(tache[i].titre, titre_rech) == 0)
        {
            printf("tache trouvee par titre:\n");
            printf("identifiant: %d\n", tache[i].identifiant);
            printf("titre: %s\n", tache[i].titre);
            printf("description: %s\n", tache[i].description);
            printf("deadline: %d/%d/%d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
            printf("statut: %d\n", tache[i].st);
            av = 1;
        }
    }
    if (!av)
    {
        printf("aucune tache trouvee avec le titre :%s.\n", titre_rech);
    }
     retn();
}
void modification()
{
    system("cls");
    int choix; // SOUS MENU
    printf("\n_________________________Modifier une tache___________________________________\n");
    printf("1 - modifier la description d'une tache.\n");
    printf("2 - modifier le statut d'une tache.\n");
    printf("3 - modifier le deadline d'une tache.\n");
    printf("4 - revenir au menu.\n");
    printf("5 - deconnexion.\n");
    printf("_______________________________________________________________________________\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        modifier_description();
        break;
    case 2:
        modifier_statut();
        break;
    case 3:
        modifier_deadline();
        break;
    case 4:
        menu();
        break;
    case 5:
        exit_program(0);
        break;
    default:
        exit_program(1);
    }
}
void modifier_description()
{
    int id;
    char nv_description[400];
    printf("Entrez l'identifiant de la tache dont vous souhaitez modifier la description: ");
    scanf("%d", &id);
    int av = 0;
    for (int i = 0; i < compt; i++)
    {
        if (tache[i].identifiant == id)
        {
            printf("entrez la nouvelle description: ");
            scanf(" %[^\n]", nv_description);
            strcpy(tache[i].description, nv_description);
            printf("description de la tache a ete modifiee avec succes.\n");
            av = 1;
            break;
        }
    }
if (!av)
    {
        printf("aucune tache trouvee avec l'identifiant %d.\n", id);
    }
   retn();
}
void modifier_statut()
{
    int id, nv_statut;
    printf("Entrez l'identifiant de la tache dont vous souhaitez modifier le statut: ");
    scanf("%d", &id);
    int av = 0;
    for (int i = 0; i < compt; i++)
    {
        if (tache[i].identifiant == id)
        {
            printf("Entrez le nouveau statut (1 - a realiser, 2 - en cours de realisation, 3 - finalisee): ");
            scanf("%d", &nv_statut);
            tache[i].st = nv_statut -1;
            printf("Le statut de la tache a ete modifie avec succes.\n");
            av = 1;
            break;
            }
    }
   if (!av)
    {
        printf("Aucune tache trouvee avec l'identifiant %d.\n", id);
    }

 retn();
}
void modifier_deadline()
{
    int id;
    printf("Entrez l'identifiant de la tache dont vous souhaitez modifier le deadline: ");
    scanf("%d", &id);

    int av = 0;
    for (int i = 0; i < compt; i++)
    {
        if (tache[i].identifiant == id)
        {
            printf("Entrez la nouvelle date de la deadline (jour/mois/annee): ");
            scanf("%d/%d/%d", &tache[i].deadline.jour, &tache[i].deadline.mois, &tache[i].deadline.annee);
            printf("Entrez la nouvelle heure de la deadline: ");
            scanf("%d", &tache[i].deadline.heure);
            printf("Le deadline de la tache a ete modifie avec succes.\n");
            av = 1;
            break;
        }
    }

    if (!av)
    {
        printf("Aucune tache trouvee avec l'identifiant %d.\n", id);
    }
     retn();
}
void supprimer()  //Supprimer une tache par identifiant ======================================
{
    system("cls");
    int id, choix;
    printf("\n________________________________________Supprimer une tache__________________________________________________\n");
    printf("Entrez l'identifiant de la tache que vous souhaitez supprimer: ");
    scanf("%d", &id);
   int av = 0;
    for (int i = 0; i < compt;i++)
    {
        if (tache[i].identifiant == id)
        {
            for (int j = i; j < compt - 1; j++)
            {
                tache[j]=tache[j + 1];
            }
            compt--;
            av = 1;
            break;
        }
    }
    if (av)
    {
        printf("Tache avec l'identifiant %d a ete supprimee avec succes.\n", id);
    }
    else
    {
        printf("Aucune tache trouvee avec l'identifiant %d.\n", id);
    }
   retn();
}
void statistique()
{
    system("cls");
    int choix; // SOUS MENU
     printf("\n____________________________Statistique_____________________________________\n");
    printf("\n1 - Afficher le nombre total des taches\n");
    printf("2 - Afficher le nombre de taches completes et incompletes.\n");
    printf("3 - Retour au menu\n");
    printf("4 - Deconnexion.\n");
    printf("_____________________________________________________________________________\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        system("cls");
        printf("Le nombre total de taches est : %d\n", compt);
        retn();
        break;
    case 2:
        nb_taches_statut();
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
void nb_taches_statut()
{
    int cor = 0, fin = 0;
    for (int i = 0; i < compt; i++)
    {
        if (tache[i].st == en_cours_realisation || tache[i].st == a_realiser)
        {
            cor++;
        }
        else if (tache[i].st == finalisee)
        {
            fin++;
        }
    }
    printf("Le nombre des taches  sont incomplet : %d\n", cor);
    printf("Le nombre de taches finalisees est : %d\n", fin);
     retn();
}

void exit_program(int error)
{
    system("cls");
    printf("vous etes deconnecte\n");
    exit(error);
}
   void retn()
{
    int choix;
    printf("_________________________________________________________________________\n");
    printf("\n1 - revenir au menu.\n");
    printf("2 - deconnexion.\n");
    printf("entrez votre choix: ");
    scanf("%d", &choix);

    if (choix == 1)
    {
        menu();
    }
    else if (choix == 2)
    {
        exit_program(0);
    }
}