#include <stdio.h>
#include <string.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Deadline;

typedef struct {
    int identifiant;
    char titre[100];
    char description[256];
    int status;
    Deadline deadline;
} Tache;

Tache e[100];
int len = 0;
int nextId = 1;

int main() {
    int choix;

    do {     // Menu
        printf("1-Ajouter une nouvelle tache : \n");
        printf("2-Afficher la liste de toutes les taches :\n");
        printf("3-Modifier une tache:\n");
        printf("4-Supprimer une tache par identifiant:\n");
        printf("5-Rechercher une tache par identifiant ou titre :\n");
        printf("6-Afficher des statistiques:\n");
        printf("Entrer votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {        // Saisir Les taches
            printf("Saisir les Taches :\n");
            e[len].identifiant = nextId;
            nextId++;

            printf("Title : ");
            scanf(" %[^\n]s", e[len].titre);
            printf("Description : ");
            scanf(" %[^\n]s", e[len].description);
            printf("Status : ");
            scanf("%d", &e[len].status);
            printf("Jour : ");
            scanf("%d", &e[len].deadline.jour);
            printf("Mois : ");
            scanf("%d", &e[len].deadline.mois);
            printf("Annee : ");
            scanf("%d", &e[len].deadline.annee);

            len++;
        } else if (choix == 2) {        // Affichage des taches

        int choix ;

        printf("1-Affichage Simple:\n");
        printf("2-Affichage Asc :\n");
        printf("3-Affichage Desc :\n");
        scanf("%d",&choix);

        switch(choix){
            case 1:     // Simple
                for (int i = 0; i < len; i++) {
                printf("Identifiant: %d\n", e[i].identifiant);
                printf("Title: %s\n", e[i].titre);
                printf("Description: %s\n", e[i].description);
                printf("Status: %d\n", e[i].status);
                printf("Date de Deadline: %d/%d/%d\n", e[i].deadline.jour, e[i].deadline.mois, e[i].deadline.annee);
                printf("_______________________________________________\n");
            }
            break;

            case 2:         // asc 
                for (int i = 0; i < len - 1; i++) {
                for (int j = i + 1; j < len; j++) {
                    if (strcmp(e[i].titre, e[j].titre) > 0) {
                        Tache tmp = e[i];
                        e[i] = e[j];
                        e[j] = tmp;
                    }
                }
            }

            for (int i = 0; i < len; i++) {
                printf("Identifiant: %d\n", e[i].identifiant);
                printf("Title: %s\n", e[i].titre);
                printf("Description: %s\n", e[i].description);
                printf("Status: %d\n", e[i].status);
                printf("Date de Deadline: %d/%d/%d\n", e[i].deadline.jour, e[i].deadline.mois, e[i].deadline.annee);
                printf("_______________________________________________\n");
            }
            break;
            case 3: // desc
            for (int i = 0; i < len - 1; i++) {
                for (int j = i + 1; j < len; j++) {
                    if (strcmp(e[i].titre, e[j].titre) < 0) {
                        Tache tmp = e[i];
                        e[i] = e[j];
                        e[j] = tmp;
                    }
                }
            }

            for (int i = 0; i < len; i++) {
                printf("Identifiant: %d\n", e[i].identifiant);
                printf("Title: %s\n", e[i].titre);
                printf("Description: %s\n", e[i].description);
                printf("Status: %d\n", e[i].status);
                printf("Date de Deadline: %d/%d/%d\n", e[i].deadline.jour, e[i].deadline.mois, e[i].deadline.annee);
                printf("_______________________________________________\n");
            }
            break;
        }
        } else if (choix == 3) {            // Modifier les Taches
            int id;
            printf("Entrez identifiant de la tache a modifier : ");
            scanf("%d", &id);

            int found = 0;
            for (int i = 0; i < len; i++) {
                if (e[i].identifiant == id) {
                    found = 1;
                    printf("1. Modifier la description\n");
                    printf("2. Modifier le statut\n");
                    printf("3. Modifier le deadline\n");
                    printf("Choisissez l'option (1-3) : ");
                    int option;
                    scanf("%d", &option);

                    if (option == 1) {
                        printf("Entrez la nouvelle description : ");
                        scanf(" %[^\n]s", e[i].description);
                    } else if (option == 2) {
                        printf("Entrez le nouveau statut : ");
                        scanf("%d", &e[i].status);
                    } else if (option == 3) {
                        printf("Entrez le nouveau jour : ");
                        scanf("%d", &e[i].deadline.jour);
                        printf("Entrez le nouveau mois : ");
                        scanf("%d", &e[i].deadline.mois);
                        printf("Entrez la nouvelle annee : ");
                        scanf("%d", &e[i].deadline.annee);
                    } else {
                        printf("Option invalide.\n");
                    }
                    break;
                }
            }

            if (!found) {
                printf("Tache avec identifiant %d non trouvee.\n", id);
            }
        } else if (choix == 4) {     // Supprimer des Taches
            int id;
            printf("Entrez identifiant de la tache a supprimer : ");
            scanf("%d", &id);

            int found = 0;
            for (int i = 0; i < len; i++) {
                if (e[i].identifiant == id) {
                    found = 1;
                    for (int j = i; j < len - 1; j++) {
                        e[j] = e[j + 1];
                    }
                    len--;
                    printf("Tache supprime.\n");
                    break;
                }
            }

            if (!found) {
                printf("Tache avec identifiant %d non trouve.\n", id);
            }
        } else if (choix == 5) {        // Recherche par id et titre
            int option;
            printf("Rechercher par :\n");
            printf("1. Identifiant\n");
            printf("2. Titre\n");
            scanf("%d", &option);

            if (option == 1) {
                int id;
                printf("Entrez identifiant : ");
                scanf("%d", &id);

                int found = 0;
                for (int i = 0; i < len; i++) {
                    if (e[i].identifiant == id) {
                        printf("Identifiant: %d\n", e[i].identifiant);
                        printf("Title: %s\n", e[i].titre);
                        printf("Description: %s\n", e[i].description);
                        printf("Status: %d\n", e[i].status);
                        printf("Date de Deadline: %d/%d/%d\n", e[i].deadline.jour, e[i].deadline.mois, e[i].deadline.annee);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Tache non trouve.\n");
                }
            } else if (option == 2) {
                char titre[100];
                printf("Entrez le titre : ");
                scanf(" %[^\n]s", titre);

                int found = 0;
                for (int i = 0; i < len; i++) {
                    if (strcmp(e[i].titre, titre) == 0) {
                        printf("Identifiant: %d\n", e[i].identifiant);
                        printf("Title: %s\n", e[i].titre);
                        printf("Description: %s\n", e[i].description);
                        printf("Status: %d\n", e[i].status);
                        printf("Date de Deadline: %d/%d/%d\n", e[i].deadline.jour, e[i].deadline.mois, e[i].deadline.annee);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Tache non trouve.\n");
                }
            } else {
                printf("Option invalide.\n");
            }
        } else if (choix == 6) {     // Affichage les Statistiques
            int total = len;
            int completes = 0, incompletes = 0;

            for (int i = 0; i < len; i++) {
                if (e[i].status == 1) { 
                    completes++;
                } else {
                    incompletes++;
                }
            }

            printf("Nombre total de taches : %d\n", total);
            printf("Nombre de taches completes : %d\n", completes);
            printf("Nombre de taches incompletes : %d\n", incompletes);
        } else {
            printf("Choix invalide.\n");
        }
    } while (1);

    return 0;
}
