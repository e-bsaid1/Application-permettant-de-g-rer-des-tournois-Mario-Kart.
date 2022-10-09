#include <stdio.h>
#include <stdlib.h>
#define nb 9

struct profil//structure du profil
{
    char Nom[30];//nom du joueur
    char Prenom[20];//prenom du joueur
    char Personnage[50];//nom du personnage
};


struct circuit
{
     char circuit[50];
     int seconde;
     int minute;
     struct profil TempsJoueur;
};

void Ajouter_un_Joueur(struct profil *joueur,int NB);//prototype de la fonction ajouter_un_joueur. On veut retourner le profil du joueur
void Supprimer_un_Joueur(struct profil *joueur,int NB);
void Temps_du_Joueur(struct circuit *Tps,int b);

int i=1;
int main()
{
      // Afficher à l'écran le menu


   //Declaration de variables
    struct profil Joueur[nb];
    struct circuit Temps[nb];
    int choix;
    int quitter;
    int limite;
    int RepereJoueur;
    char confirmation;


   //Declaration de variables

        printf(" ---- Bienvenue dans Mario Kart Tournament. Veuillez entrer votre choix ----\n");
         printf("  [0] Quitter le programme\n");
         printf("  [1] Ajouter un joueur\n");
         printf("  [2] Supprimer un joueur\n");
         printf("  [3] Afficher l’etat du tournoi\n");
         printf("  [4] Saisir le temps d un joueur\n");
         printf("  [5] Declarer un joueur forfait\n");
         printf("  [6] Commencer un nouveau tournoi\n");





//tant que quitter est différent de 0, de scanf... au case


     do
    {
        scanf("%d",&choix);
        printf("--- Vous avez mis le choix numero %d---\n",choix);
     switch (choix)
     {


          case 0 :

          printf("---Etes-vous sur de quitter le menu ?--- (o/n)\n");
          fflush(stdin);
          scanf("%c",&confirmation);

                  if (confirmation != 'n')
                    {
                     printf("A bientot !\n");
                     quitter = 1;
                    }
          break;


          case 1 :
          Ajouter_un_Joueur(Joueur,2);
          printf("---Voulez-vous continuer ?--- (o/n)\n");
          scanf("%c",&confirmation);

            if(confirmation == 'o')
            {
             printf("---Ajouter combien d'autres joueurs ?---\n");
             fflush(stdin);
             scanf("%d",&limite);

            do
             {
              i++;
              Ajouter_un_Joueur(Joueur,i);
             }while(i<=limite);
            }



            break;




              case 2 :
              printf("---Tapez le numéro du joueur à effacer---\n");
              scanf("%d",&RepereJoueur);
              Supprimer_un_Joueur(Joueur,RepereJoueur);
              break;

              case 4 :
                  Temps_du_Joueur(Temps,RepereJoueur);




              default:
              printf("Selectionner un choix\n");
              scanf("&d",&choix);
              break;



     }
      }while(quitter!=1);
}



void Ajouter_un_Joueur(struct profil *joueur,int NB)
{

                    printf("Ecrire le nom du joueur %i \n",i);
                    fflush(stdin);
                    gets(joueur[i].Nom);



                    printf("Ecrire le prenom du joueur %d \n",i);
                    gets(joueur[i].Prenom);



                    printf("Ecrire le nom du personnage %d \n",i);
                    gets(joueur[i].Personnage);

                    printf("Joueur %d : %s %s, %s\n",i,joueur[i].Prenom,joueur[i].Nom,joueur[i].Personnage);



  }


    void Supprimer_un_Joueur(struct profil *joueur,int num)
{

                //Initialisation de la structure

                    fflush(stdin);
                    printf("Joueur %d : %s %s %s\n",i,joueur[i].Prenom,joueur[i].Nom,joueur[i].Personnage);

                    strcpy(joueur[num].Nom,"");
                    strcpy(joueur[num].Prenom,"");
                    strcpy(joueur[num].Personnage,"");

                    printf("Joueur %d : %s %s %s\n",i,joueur[i].Prenom,joueur[i].Nom,joueur[i].Personnage);
  }


     void Temps_du_Joueur(struct circuit *Tps,int num)
         {

         printf("Saisir le numero du joueur\n");

         scanf("%d",&num);

         printf("Joueur %d\n",num);
         fflush(stdin);
         printf("--- Saissisez le circuit du joueur ---\n");
         gets(Tps[num].circuit);
         printf("%s \n",Tps[num].circuit);

         printf("---Joueur %d.---\nSaissisez les secondes et minutes du joueur\n",num);

         printf("- Les secondes :\n");
         scanf("%d",&Tps[num].seconde);
         printf("- Les minutes :\n");
         scanf("%d",&Tps[num].minute);

         if(Tps[num].minute<=60 && Tps[num].seconde <=60)
         {
             printf("--- %s ---\n",Tps[num].circuit);
             printf("Le Joueur %d a fait un temps de %d minute(s) et %d secondes\n",num,Tps[num].minute,Tps[num].seconde);
         }

         }






