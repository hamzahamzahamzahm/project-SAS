#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition de 'date' structure
struct date {
    int jour;
    int mois;
    int annee; 
};

// Definition de 'tache' structure
struct tache {
    char description[100];
    struct date date;
    int priorite;
};

// FONCTION POUR CREER UNE TACHE
struct tache creer_tache() {
    struct tache tache;

    // entrer la description de tache
    printf("Entrez la description de la tache :\n");
    scanf("%s", tache.description);

    // entrer la date de tache
    printf("Entrez la date de la tache (jour mois annee) :\n");
    scanf("%d%d%d", &tache.date.jour, &tache.date.mois, &tache.date.annee);

    // entrer la priorite de tache
    printf("Entrez la priorite de la tache :\n");
    scanf("%d", &tache.priorite);

    return tache;
}

// FONCTION POUR CREER UNE LISTE DE TACHES
void liste_tache(struct tache liste[], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        // entrer la priorite de la tache
        printf("Entrez la priorite de la tache :\n");
        scanf("%d", &liste[i].priorite);
    }
}

// FONCTION POUR MODIFIER UNE TACHE
void modifier_tache(struct tache *tache) {
    printf("Entrez la nouvelle description de la tache :\n");
    scanf("%s", tache->description);
    printf("Entrez la nouvelle date de la tache (jour mois annee) :\n");
    scanf("%d%d%d", &tache->date.jour, &tache->date.mois, &tache->date.annee);
    printf("Entrez la nouvelle priorite de la tache :\n");
    scanf("%d", &tache->priorite);
}

int main() {
    int choix;
    struct tache ma_tache;

    // Création d'une liste de taches
    struct tache liste_taches[4];
    liste_tache(liste_taches, 4);
    printf("BENVENUE DANS ONE___HAND:\n");

    do {
        // Menu d'options
        printf("1. Creer une tache individuelle\n");
        printf("2. Creer une liste de taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // utilisation de la fonction pour creer tache
                ma_tache = creer_tache();

                // affichage des informations de la tache creee
                printf("\nTache creee :\n");
                printf("Description : %s\n", ma_tache.description);
                printf("Date : %d/%d/%d\n", ma_tache.date.jour, ma_tache.date.mois, ma_tache.date.annee);
                printf("Priorite : %d\n", ma_tache.priorite);
                break;
            case 2:
                // Affichage des informations de la liste de taches
                printf("\nListe de taches :\n");
                for (int i = 0; i < 4; i++) {
                    printf("Priorite : %d\n", liste_taches[i].priorite);
                }
                break;
            case 3:
                // Modifier une tache
                printf("Entrez l'indice de la tache que vous souhaitez modifier :\n");
                int indice;
                scanf("%d", &indice);

                if (indice >= 0 && indice < 4) {
                    modifier_tache(&liste_taches[indice]);
                    printf("Tache modifiee avec succes!\n");
                } else {
                    printf("Indice invalide!\n");
                }
                break;
            default:
                printf("MERCI \n");
        }

    } while (choix != 4);

    return 0;
}
