#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nums[5], player1[3], player2[3], s1 = 0, s2 = 0, temp, no;
    char name1[20], name2[20];
    int used[11] = {0};
    int present = 0;

    printf("Enter player1 Name: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = '\0';
    printf("\n");

    printf("Enter player2 Name: ");
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = '\0';
    printf("\n");

    srand(time(NULL));

    for (int i = 0; i < 5; ) {
        temp = rand() % 10 + 1;
        if (!used[temp]) {
            nums[i] = temp;
            used[temp] = 1;
            i++;
        }
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%s Enter your Guess Number: ", name1);
        scanf("%d", &no);
        player1[i] = no;
        printf("\n");
        present = 0;
        for (int i = 0; i < 5; i++) {
            if (nums[i] == no) {
                s1++;
                present = 1;
                break;
            }
        }
        if (present) {
            printf("%s: It's Correct\n\n", name1);
        } else {
            printf("%s: It's Wrong\n\n", name1);
        }

        printf("%s Enter your Guess Number: ", name2);
        scanf("%d", &no);
        player2[i] = no;
        printf("\n");
        present = 0;
        for (int i = 0; i < 5; i++) {
            if (nums[i] == no) {
                s2++;
                present = 1;
                break;
            }
        }
        if (present) {
            printf("%s: It's Correct\n\n", name2);
        } else {
            printf("%s: It's Wrong\n\n", name2);
        }
    }
    printf("\n");
    printf("Final Scores:\n");
    printf("\n");
    printf("%s has Scored %d\n", name1, s1);
    printf("\n");
    printf("%s has Scored %d\n", name2, s2);
    printf("\n\n");
    
    printf("The Numbers Generated by Computer is: [");
    for(int i = 0;i < 5;i++){
        printf("%d",player1[i]);
        if (i < 4){
            printf(", ");
        }
    }
    printf("]");
    printf("\n\n");
    
    printf("%s has Guessed Numbera are: [",name1);
    for(int i = 0;i < 3;i++){
        printf("%d",player1[i]);
        if (i < 2){
            printf(", ");
        }
    }
    printf("]");
    printf("\n\n");
    
    printf("%s has Guessed Numbera are: [",name2);
    for(int i = 0;i < 3;i++){
        printf("%d",player2[i]);
        if (i < 2){
            printf(", ");
        }
    }
    printf("]");
    printf("\n\n\n");
    
    if (s1 > s2) {
        printf("%s is the Winner!\n", name1);
    } else if (s2 > s1) {
        printf("%s is the Winner!\n", name2);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}
