#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_health = 100;
    int enemy_health = 100;
    int player_damage, enemy_damage;
    char action;

    srand(time(NULL));

    printf("Welcome to the Text-Based RPG Game!\n");

    while (player_health > 0 && enemy_health > 0) {
        printf("\nPlayer Health: %d\n", player_health);
        printf("Enemy Health: %d\n", enemy_health);
        printf("\nChoose your action:\n");
        printf("1. Attack (A)\n");
        printf("2. Defend (D)\n");
        printf("3. Escape (E)\n");
        printf("Enter your choice: ");
        scanf(" %c", &action);

        switch (action) {
            case 'A':
            case 'a':
                player_damage = rand() % 21 + 10;
                enemy_damage = rand() % 11 + 5;
                printf("You attack the enemy and deal %d damage.\n", player_damage);
                printf("The enemy counterattacks and deals %d damage.\n", enemy_damage);
                player_health -= enemy_damage;
                enemy_health -= player_damage;
                break;
            case 'D':
            case 'd':
                player_damage = rand() % 11 + 5;
                printf("You defend against the enemy's attack and take %d damage.\n", player_damage / 2);
                player_health -= player_damage / 2;
                break;
            case 'E':
            case 'e':
                printf("You try to escape from the enemy!\n");
                if (rand() % 2 == 0) {
                    printf("You successfully escaped!\n");
                    return 0;
                } else {
                    printf("Escape failed! The enemy attacks you.\n");
                    enemy_damage = rand() % 21 + 10;
                    printf("The enemy deals %d damage.\n", enemy_damage);
                    player_health -= enemy_damage;
                }
                break;
            default:
                printf("Invalid action! Please choose again.\n");
        }

        if (player_health <= 0) {
            printf("Game over! You have been defeated by the enemy.\n");
            return 0;
        } else if (enemy_health <= 0) {
            printf("Congratulations! You have defeated the enemy.\n");
            return 0;
        }
    }

    return 0;
}
