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
      
    } else {
        printf("La liste de taches est pleine.\n");
    }
    
   
}

void afficherTaches() {
	int i;
    printf("\nListe de toutes les taches :\n");
    for ( i = 0; i < taskCount; i++) {
        printf("\nTache #%d :  \n", taskList[i].IdentifiantUnique);
        printf("Titre :            %s\n", taskList[i].titre);
        printf("Description :      %s\n", taskList[i].description);
        printf("Date de creation : %d/%d/%d \n", taskList[i].date.jour, taskList[i].date.mois, taskList[i].date.annee);
	    printf("Delai : %d jours %d heures %d minutes \n", taskList[i].jours, taskList[i].heures, taskList[i].minutes);
        if(taskList[i].statut==0){
        printf("statu :   a realiser  \n" );	
		} if(taskList[i].statut==1){
        printf("statu :   en cours de réalisation  \n" );	
		}if(taskList[i].statut==2){
        printf("statu :   finalisée  \n" );	
		}
        printf("\n");
    }
}

void afficherTachestries() {
    int i, j;
     struct Tasks temp;
    
    for (i = 0; i < taskCount - 1; i++) {
        for (j = 0; j < taskCount - 1; j++) {
            if (strcmp(taskList[j].titre, taskList[j + 1].titre) > 0) {
                temp = taskList[j];
                taskList[j] = taskList[j + 1];
                taskList[j + 1] = temp;
            }
        }
    }

    printf("\nListe de toutes les taches triees par ordre alphabetique :\n");
    afficherTaches(); 
}

void afficherTachestriesDelai() {
    int i, j;
    struct Tasks temp;
    
    for (i = 0; i < taskCount - 1; i++) {
        for (j = 0; j < taskCount - i - 1; j++) {
            if (taskList[j].jours > taskList[j + 1].jours) {
                temp = taskList[j];
                taskList[j] = taskList[j + 1];
                taskList[j + 1] = temp;
            } else if (taskList[j].jours == taskList[j + 1].jours) {
                if (taskList[j].heures > taskList[j + 1].heures) {
                    temp = taskList[j];
                    taskList[j] = taskList[j + 1];
                    taskList[j + 1] = temp;
                } else if (taskList[j].heures == taskList[j + 1].heures) {
                    if (taskList[j].minutes > taskList[j + 1].minutes) {
                        temp = taskList[j];
                        taskList[j] = taskList[j + 1];
                        taskList[j + 1] = temp;
                    }
                }
            }
        }
    }

    printf("\nListe de toutes les taches triees par deali :\n");
    afficherTaches();
}


void afficherTachestriesbydali() {
    int i; 

    printf("\nListe de toutes les taches triees deali :\n");
     for (i = 0; i < taskCount; i++) {
    	if (taskList[i].jours < 3  ) {
        printf("\nTache #%d :  \n", taskList[i].IdentifiantUnique);
        printf("Titre :            %s\n", taskList[i].titre);
        printf("Description :      %s\n", taskList[i].description);
        printf("Delai : %d jours %d heures %d minutes \n", taskList[i].jours, taskList[i].heures, taskList[i].minutes);
			        if(taskList[i].statut==0){
			        printf("statu :   a realiser  \n" );	
					} if(taskList[i].statut==1){
			        printf("statu :   en cours de réalisation  \n" );	
					}if(taskList[i].statut==2){
			        printf("statu :   finalisée  \n" );	
					}
					
	    printf("\n");
		}
        else  if (taskList[i].jours == 3 && taskList[i].heures==0 && taskList[i].minutes==0) {
        printf("\nTache #%d :  \n", taskList[i].IdentifiantUnique);
        printf("Titre :            %s\n", taskList[i].titre);
        printf("Description :      %s\n", taskList[i].description);
        printf("Delai : %d jours %d heures %d minutes \n", taskList[i].jours, taskList[i].heures, taskList[i].minutes);
			        if(taskList[i].statut==0){
			        printf("statu :   a realiser  \n" );	
					} if(taskList[i].statut==1){
			        printf("statu :   en cours de réalisation  \n" );	
					}if(taskList[i].statut==2){
			        printf("statu :   finalisée  \n" );	
					}
	    printf("\n");}
    }
   
}


void delId(int delet) {
    int i , j, found=0;
    
    for (i = 0; i < taskCount ; i++) {
            if (taskList[i].IdentifiantUnique==delet) {
               found = 1;
               for (j = 0; j < taskCount -1; j++){
               	taskList[j]=taskList[j+1];
			   }
			   taskCount--;
			   printf("la tache a ete suprimmer \n");
			   break;
            } 
    }
}


void searchTachebyTitre(char search[30]) {
    int i, foundd = 0;

    for (i = 0; i < taskCount; i++) {
        if (strcmp(taskList[i].titre, search) == 0) {
            foundd = 1;
            printf("\nTache #%d :  \n", taskList[i].IdentifiantUnique);
            printf("Titre :            %s\n", taskList[i].titre);
            printf("Description :      %s\n", taskList[i].description);
            printf("Delai : %d jours %d heures %d minutes \n", taskList[i].jours, taskList[i].heures, taskList[i].minutes);
            if (taskList[i].statut == 0) {
                printf("statu :   a realiser  \n");
            }
            if (taskList[i].statut == 1) {
                printf("statu :   en cours de réalisation  \n");
            }
            if (taskList[i].statut == 2) {
                printf("statu :   finalisee  \n");
            }
            printf("\n");
        }
    }

    if (!foundd) {
        printf("Aucune tache avec le titre '%s' n'a été trouvée.\n", search);
    }
}


void searchTache(int search){
	 int i , j, found=0;
    
    for (i = 0; i < taskCount ; i++) {
            if (taskList[i].IdentifiantUnique==search) {
               found = 1;
              
			    printf("\nTache #%d :  \n", taskList[i].IdentifiantUnique);
		        printf("Titre :            %s\n", taskList[i].titre);
		        printf("Description :      %s\n", taskList[i].description);
		        printf("Delai :            %d jours %d heures %d minutes \n", taskList[i].jours, taskList[i].heures, taskList[i].minutes);
		        if(taskList[i].statut==0){
		        printf("statu :             a realiser  \n" );	
				} if(taskList[i].statut==1){
		        printf("statu :             en cours de réalisation  \n" );	
				}if(taskList[i].statut==2){
		        printf("statu :             finalisée  \n" );	
				}
		        printf("\n");
			  
			   break;
            } 
    }
}


void searchTacheSpecifique(int search) {
    int i, found = 0;

    printf("\nListe de toutes les taches avec le statut %d :\n", search);
    for (i = 0; i < taskCount; i++) {
        if (taskList[i].statut == search) {
            found = 1;
            printf("\nTache #%d :  \n", taskList[i].IdentifiantUnique);
            printf("Titre :            %s\n", taskList[i].titre);
            printf("Description :      %s\n", taskList[i].description);
            printf("Delai : %d jours %d heures %d minutes \n", taskList[i].jours, taskList[i].heures, taskList[i].minutes);
            if (taskList[i].statut == 0) {
                printf("Statut :   a réaliser\n");
            } else if (taskList[i].statut == 1) {
                printf("Statut :   en cours de réalisation\n");
            } else if (taskList[i].statut == 2) {
                printf("Statut :   finalisée\n");
            }
            printf("\n");
        }
    }

    if (!found) {
        printf("Aucune tache avec le statut %d n'a été trouvée.\n", search);
    }
}


void displayTotalTasks() {
    printf("Le nombre total de taches est : %d\n", taskCount);
}

void incompleteComplet() {
	int i;
	int completeTaskCount = 0;
    int incompleteTaskCount = 0;
    for ( i = 0; i < taskCount; i++) {
       
        if(taskList[i].statut==0){
        	incompleteTaskCount++;	
		} if(taskList[i].statut==1){
		incompleteTaskCount++;	
		}if(taskList[i].statut==2){
        completeTaskCount++;
		}
		 printf("Nombre de taches completes : %d\n", completeTaskCount);
         printf("Nombre de taches incompletes : %d\n", incompleteTaskCount);
        printf("\n");
    }
}

void updateDescription(){
	 printf("Entrez l identifiant de la tache dont vous pouvez modifier la description : ");
    int id;
    int i;
    scanf("%d", &id);

    int found = 0;
    for ( i = 0; i < taskCount; i++) {
        if (taskList[i].IdentifiantUnique == id) {
            found = 1;
            printf("Nouvelle description pour la tache #%d : ", id);
            scanf(" %99[^\n]", taskList[i].description); 
            printf("La description a ete mise a jour.\n" );
            break;
        }
    }

    if (!found) {
        printf("Aucune tache avec l identifiant #%d n a ete trouvee.\n", id);
    }
   
}
void updateDeali(){
	 printf("Entrez l identifiant de la tache dont vous pouvez modifier la deali : ");
    int id;
    int i;
    scanf("%d", &id);

    int found = 0;
    for ( i = 0; i < taskCount; i++) {
        if (taskList[i].IdentifiantUnique == id) {
            found = 1;
            printf("combien de jour  pour la tache #%d : ", id);
            scanf(" %d",&taskList[i].jours); 
            printf("combien de heur pour la tache #%d : ", id);
            scanf(" %d",&taskList[i].heures); 
            printf("combien de minute pour la tache #%d : ", id);
            scanf(" %d",&taskList[i].minutes); 
            printf("Le deali a ete mise a jour.\n" );
            break;
        }
    }

    if (!found) {
        printf("Aucune tache avec l identifiant #%d n a ete trouvee.\n", id);
    }
   
}

void updateStatu(){
	 printf("Entrez l identifiant de la tache dont vous pouvez modifier la statu : ");
     int id;
     int i;
    scanf("%d", &id);

    int found = 0;
    for ( i = 0; i < taskCount; i++) {
        if (taskList[i].IdentifiantUnique == id) {
            found = 1;
            printf("Nouvelle statu pour la tache #%d : ", id);
            scanf(" %d",&taskList[i].statut); 
            printf("Le statu a ete mise a jour.\n" );
            break;
        }
    }

    if (!found) {
        printf("Aucune tache avec l identifiant #%d ne pas ete trouvee.\n", id);
    }
   
}


void nomberJour() {
   int i;
    printf(" \n");
    for (i = 0; i < taskCount; i++) {
        printf("\nTache #%d :  \n", taskList[i].IdentifiantUnique);
        printf("nomber de jour restant pour cette tache et : %d jours %d heures %d minutes \n", taskList[i].jours, taskList[i].heures, taskList[i].minutes);
        printf("\n");
    }
}



int main() {
    int choix, choixMenu1 , choixMenu2 , choixMenu3 ,choixMenu4 , choixMenu5;
    int previousMenu = 0; 
    int n , i;
    char input[10];
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
            scanf("%s", &input);
            choix = strtol(input, NULL, 10);
            system("cls");
             if (choix == 7) {
               exit(0);
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
                    afficherTaches();
                    previousMenu = 1; 
                    break;
                case 3:
                   previousMenu = 2; 
                   break;
                case 4:
                    printf("Entrez id de la tache pour supprimer : ");
				    int supId;
				    scanf("%d", &supId);
				    delId(supId);
                    
                   
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
                    afficherTachestries();
                   
                    break;
                case 2:
                    afficherTachestriesDelai();
                   
                    break;
                case 3:
                   afficherTachestriesbydali();
                   
                    break;
                case 4:
                    previousMenu = 0; 
                    break;
                default:
                    printf("Invalid \n");
            }
        } else if (previousMenu == 2) {
          	printf("******************************************************************\n");
            printf("1 = Modifier la description d une tache.                         *\n");
	        printf("2 = Modifier le statut d’une tache.                              *\n");
	        printf("3 = Modifier le deadline d’une tache.                            *\n");
	        printf("4 = retour                                                       *\n");
	        printf("Choisissez un nombre 1-4 :                                       *\n");
	       	printf("******************************************************************\n");
            scanf("%d", &choixMenu3);
            

            switch (choixMenu3) {
                case 1:
                   updateDescription();
                    break;
                case 2:
                   updateStatu();
                    break;
                case 3:updateDeali();                   
                    break;
                case 4:
                    previousMenu = 0; 
                    break;
                default:
                    printf("Invalid \n");
            }
        }else if (previousMenu == 3) {
          	printf("******************************************************************\n");
            printf("1 = Rechercher une tache par son Identifiant.                    *\n");
	        printf("2 = Rechercher une tahe par son Titre.                           *\n");
	        printf("3 = Rechercher specifique par statu de tache                     *\n");
	        printf("4 = retour                                                       *\n");
	        printf("Choisissez un nombre 1-3 :                                       *\n");
	       	printf("******************************************************************\n");
            scanf("%d", &choixMenu4);

            switch (choixMenu4) {
                case 1:
                     printf("Entrez id de la tache pour rechercher : ");
				    int searchId;
				    scanf("%d", &searchId);
				    searchTache(searchId);
                   
                    break;
                case 2:
                	printf("Entrez le titre de la tache pour rechercher : ");
				    char searchtitre[30];
				    scanf(" %29[^\n]", searchtitre);
				    searchTachebyTitre(searchtitre);
                    break;
                case 3:
                	printf("filter les tache par son statu ( a réalise :0  || en cours de réaliser :1 || finalisé : 2) : ");
				    int searchStatu;
				    scanf("%d",&searchStatu);
				    searchTacheSpecifique(searchStatu);
                    break;
               
                case 4:
                    previousMenu = 0; 
                    break;
                default:
                    printf("Invalid\n");
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
                   displayTotalTasks();
                   
                    break;
                case 2:
                   incompleteComplet();
                    break;
                case 3:
                   nomberJour();
                    break;
                case 4:
                    previousMenu = 0; 
                    break;
                default:
                    printf("Invalid .\n");
            }
        }
    }

    return 0;
}

