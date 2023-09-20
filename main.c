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


struct Tasks taskList[100]; 
int taskCount = 0;

void ajoutTask() {
   
    if (taskCount < 100) {
        struct Tasks newTask;
        newTask.IdentifiantUnique = taskCount + 1;
        newTask.statut=0;
        printf("\nVotre tache id est : %d\n", newTask.IdentifiantUnique);
        printf("\ndonnez le titre de tache :");
        scanf(" %29[^\n]", &newTask.titre);
        printf("\ndonnez le description  de tache :");
        scanf(" %99[^\n]", &newTask.description);
         
        printf("\ncombien des jours : ");
        scanf("%d", &newTask.jours);
        printf("\ncombien des heurs : ");
        scanf("%d", &newTask.heures);
        printf("\ncombien des minuet : ");
        scanf("%d", &newTask.minutes);
        printf("Entre la date de creation de tach ( 20 9 2023 ) : ");
        scanf("%d %d %d", &newTask.date.jour, &newTask.date.mois, &newTask.date.annee);

        taskList[taskCount] = newTask;
        taskCount++;
        printf("\n");
        printf("Tache ajoutee avec succes.\n");
        printf("\n");
	            printf("    *****    \n");
			    printf("  *       *  \n");
			    printf(" *  O   O  * \n");
			    printf(" *   \\_/   *\n");
			    printf(" *         * \n");
			    printf("  *       *  \n");
			    printf("    *****    \n");
			    printf("\n");
			    printf("\n");

    } else {
        printf("La liste de taches est pleine.\n");
    }
    
   
}



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
                printf("Au revoir !\n"); 
				printf("\n");
                printf("  ****   ****  \n");
			    printf("******* *******\n");
			    printf("***************\n");
			    printf(" ************* \n");
			    printf("  ***********  \n");
			    printf("    *******    \n");
			    printf("      ***      \n");
			    printf("       *       \n");
				break;
            }
            switch (choix) {
                case 1:
                   ajoutTask();
                  break;
                case 11:
                   printf("donner le nomber de tache que vous vous stock : \n");
                    scanf("%d", &n);
                    for(i=0;i<n;i++){
                    	ajoutTask();
					}
                  
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

