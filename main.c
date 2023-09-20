#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct date {
    int jour, mois, annee;
} T_date;

struct Tasks {
    int IdentifiantUnique;
    char titre[30];
    char description[100];
    T_date date; 
    int minutes; 
    int heures;  
    int jours;   
    int statut; 
};




int main() {
    int choix, choixMenu1 , choixMenu2 , choixMenu3 ,choixMenu4 , choixMenu5;
    int previousMenu = 0; 
    int n , i;
    while (1) { // Infini
        if (previousMenu == 0) {
           	printf("******************************************************************\n");
        	printf("                         MENU :                                  *\n");
        	printf("******************************************************************\n");
            printf("1 = Ajouter une nouvelle tache:                                  *\n");
            printf("11 = Ajouter plusieur nouvelle tache:                            *\n");
            printf("2 = Afficher la liste de toutes les taches :                     *\n");
            printf("3 = Modifier une tache:                                          *\n");
            printf("4 = Supprimer une tache par identifiant :                        *\n");
            printf("5 = Rechercher les Taches :                                      *\n");
            printf("6 = Statistiques :                                               *\n");
            printf("7 = Quitter                                                      *\n");
            printf("******************************************************************\n");
            printf("Choisissez un nombre 1-7 :                                       *\n");
            printf("******************************************************************\n");
            scanf("%d", &choix);
             if (choix == 7) {
                printf("Au revoir !\n"); break;
            }
            switch (choix) {
                case 1:
                  
                  break;
                case 11:
                  
                  break;
                case 2:
                   
                    previousMenu = 1; 
                    break;
                case 3:
                   previousMenu = 2; 
                   break;
                case 4:
                   
                    
                   
                    break;
                case 5:
                  
                   
                    previousMenu = 3; 
                    break;
                case 6:
                   previousMenu = 4; 
                   break;
                default:
                    printf("Invalid choice.\n");
            }
        } else if (previousMenu == 1) {
          	printf("******************************************************************\n");
            printf("1 = Trier les taches par ordre alphabetique.                     *\n");
	        printf("2 = Trier les taches par deadline.                               *\n");
	        printf("3 = Afficher taches dont le deadline est dans 3 jours ou moins.  *\n");
	        printf("4 = retour                                                       *\n");
	        printf("Choisissez un nombre 1-4 :                                       *\n");
	       	printf("******************************************************************\n");
            scanf("%d", &choixMenu2);
           
            switch (choixMenu2) {
                case 1:
                   
                   
                    break;
                case 2:
                    
                   
                    break;
                case 3:
                    
                   
                    break;
                case 4:
                    previousMenu = 0; 
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } else if (previousMenu == 2) {
          	printf("******************************************************************\n");
            printf("1 = Modifier la description d'une tâche.                         *\n");
	        printf("2 = Modifier le statut d’une tâche.                              *\n");
	        printf("3 = Modifier le deadline d’une tâche.                            *\n");
	        printf("4 = retour                                                       *\n");
	        printf("Choisissez un nombre 1-4 :                                       *\n");
	       	printf("******************************************************************\n");
            scanf("%d", &choixMenu3);
            

            switch (choixMenu3) {
                case 1:
                    
                   
                    break;
                case 2:
                  
                    break;
                case 3:
                    
                   
                    break;
                case 4:
                    previousMenu = 0; 
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }else if (previousMenu == 3) {
          	printf("******************************************************************\n");
            printf("1 = Rechercher une tâche par son Identifiant.                    *\n");
	        printf("2 = Rechercher une tâche par son Titre.                          *\n");
	        printf("3 = retour                                                       *\n");
	        printf("Choisissez un nombre 1-3 :                                       *\n");
	       	printf("******************************************************************\n");
            scanf("%d", &choixMenu4);

            switch (choixMenu4) {
                case 1:
                  
                   
                    break;
                case 2:
                    
                   
                    break;
               
                case 3:
                    previousMenu = 0; 
                    break;
                default:
                    printf("Invalid choice\n");
            }
        }else if (previousMenu == 4) {
          	printf("******************************************************************\n");
            printf("1 = Afficher le nombre total des taches.                         *\n");
	        printf("2 = Afficher le nombre de tâches completes et incompletes.       *\n");
	        printf("3 = le nombre de jours restants jusqu'au délai de chaque tche.  *\n");
	        printf("4 = retour                                                       *\n");
	        printf("Choisissez un nombre 1-4 :                                       *\n");
	       	printf("******************************************************************\n");
            scanf("%d", &choixMenu5);

            switch (choixMenu5) {
                case 1:
                    
                   
                    break;
                case 2:
                    
                   
                    break;
                case 3:
                    
                    break;
                case 4:
                    previousMenu = 0; 
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}

