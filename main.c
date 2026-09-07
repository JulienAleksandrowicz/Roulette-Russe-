#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HIGH 6
#define LOW 1

int main() {
    char name[15];
    int active = 1;
    int rdn;
    int u_rdn;
    int points = 0;
    int lost = 0;
    srand(time(NULL));

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s\n", name);

    while (active){
        rdn = (rand()%6)+1 ; //génération du nombre piège
        lost = 0;
        //printf("Number: %d\n", rdn);   debug
        int choice;
        while (lost==0){
            printf("0-Tirer 1-Arreter maintenant\n");
            scanf("%d",&choice);
            if (choice == 0) {
                points+=1;
                u_rdn = (rand()%6)+1;
                if (u_rdn==rdn){
                    printf("Dommage %s ! Tu as perdu après %d Balles tirés\n",name,points);
                    lost = 1;
                    points = 0;
                    break;
                }
                else{
                    printf("Oufff ! Aucun balle tiree");
                }
            }
            else if (choice == 1) {
                printf("Bravo %s ! Tu as eu le courage de tirer %d Balles\n",name,points);
                lost = 1;
            }
        }
        printf("Play again ? (0-no  1-yes)\n--------------------");
        scanf("%d", &active);
    }
    return 0;
}