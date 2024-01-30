#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DEFINITION DE struct date
struct date {
    int jour;
    int mois;
    int annee;
};
//DEFINITION DE struct note
struct note {
    char description[100];
    struct date date;
    int priorite;
} liste_note[100];  // "En supposant un maximum de 100 notes."
int taille_note = 0;

// Fonction pour ajouter un note
void ajouter_un_note() {
    if (taille_note < 100) {  // "Vérifiez s'il y a de l'espace dans le tableau."
        // Description de note
        printf("Entrez la description de la note :\n");
        scanf("%s", liste_note[taille_note].description);

        // Date DE note
        printf("Entrez la date de la note (jour mois annee) :\n");
        scanf("%d%d%d", &liste_note[taille_note].date.jour, &liste_note[taille_note].date.mois, &liste_note[taille_note].date.annee);

        // Priorite de note
        printf("Entrez la priorite de la note :\n");
        scanf("%d", &liste_note[taille_note].priorite);

        taille_note++;
        printf("Note ajoutee avec succes!\n");
    } else {
        printf("La liste de notes est pleine. Impossible d'ajouter plus de notes.\n");
    }
}

// "Fonction pour afficher une seule note.
void afficher_note(struct note *une_note) {
    printf("Description : %s\n", une_note->description);
    printf("Date : %d/%d/%d\n", une_note->date.jour, une_note->date.mois, une_note->date.annee);
    printf("Priorite : %d\n", une_note->priorite);
}

// fonction pour afficher liste notes
void afficher_liste() {
    for (int i = 0; i < taille_note; i++) {
        printf("Note %d:\n", i + 1);
        afficher_note(&liste_note[i]);
        printf("\n");
    }
}

//  fonction pour modifier un note
void modifier_note() {
    int choix;
    afficher_liste();

    printf("Entrez le numero de la note a modifier : ");
    scanf("%d", &choix);

    if (choix > 0 && choix <= taille_note) {
        printf("Entrez la nouvelle description de la note :\n");
        scanf("%s", liste_note[choix - 1].description);

        printf("Entrez la nouvelle date de la note (jour mois annee) :\n");
        scanf("%d%d%d", &liste_note[choix - 1].date.jour, &liste_note[choix - 1].date.mois, &liste_note[choix - 1].date.annee);

        printf("Entrez la nouvelle priorite de la note :\n");
        scanf("%d", &liste_note[choix - 1].priorite);

        printf("Note modifiee avec succes!\n");
    } else {
        printf("Numero de note invalide!\n");
    }
}
// Fonction pour supprimer une note
void supprimer_note() {
    int choix;
    afficher_liste();

    printf("Entrez le numero de la note a supprimer : ");
    scanf("%d", &choix);

    if (choix > 0 && choix <= taille_note) {
        // Décalage des éléments suivants pour remplir l'emplacement supprimé
        for (int i = choix - 1; i < taille_note - 1; i++) {
            liste_note[i] = liste_note[i + 1];
        }

        taille_note--;
        printf("Note supprimee avec succes!\n");
    } else {
        printf("Numero de note invalide!\n");
    }
}


int main() {
    int choix;

    do {
        printf("\n1. Ajouter une note\n");
        printf("2. Afficher une note\n");
        printf("3. Afficher la liste des notes\n");
        printf("4. Modifier une note\n");
        printf("5.supprimer un note :\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_un_note();
                break;
            case 2:
                afficher_note(&liste_note[taille_note - 1]);  // Display the last added note
                break;
            case 3:
                afficher_liste();
                break;
            case 4:
                modifier_note();
                break;
            case 5:
                supprimer_note();
                break;
            case 6:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix non valide!\n");
        }

    } while (choix != 5);

    return 0;
}

