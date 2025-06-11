#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Character structure
typedef struct {
    char name[50];
    int health;
    int attack;
    int defense;
    int experience;
    int level;
    char weapon[20];
    int weaponAttack;
    char skill[20];   // A skill that can be selected by the player
    int skillPower;    // Skill's effectiveness
} Character;

// Function to display introduction
void introduction(Character *player) {
    printf("\nWelcome, %s! You have entered the village of Chitrawan.\n", player->name);
    printf("An elder approaches you and says:\n");
    printf("\"The jungle whispers of a spirit who guards the sacred stone. Will you seek it?\"\n");
    printf("1. Yes, I will find the spirit.\n");
    printf("2. No, I will ask the villagers for guidance.\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nYou venture into the deep jungle, prepared for the unknown.\n");
    } else {
        printf("\nYou seek advice from the villagers and hear rumors of a cursed tiger...\n");
    }
}

// Function to select a weapon
void selectWeapon(Character *player) {
    printf("\nChoose your weapon:\n");
    printf("1. Bow and Arrow (Attack +5)\n");
    printf("2. Tharu Axe (Attack +7)\n");
    printf("3. Mystic Dagger (Attack +6)\n");
    printf("4. Talwar (Attack +8)\n");
    printf("5. Khukhuri (Attack +9)\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            strcpy(player->weapon, "Bow and Arrow");
            player->weaponAttack = 5;
            break;
        case 2:
            strcpy(player->weapon, "Tharu Axe");
            player->weaponAttack = 7;
            break;
        case 3:
            strcpy(player->weapon, "Mystic Dagger");
            player->weaponAttack = 6;
            break;
        case 4:
            strcpy(player->weapon, "Talwar");
            player->weaponAttack = 8;
            break;
        case 5:
            strcpy(player->weapon, "Khukhuri");
            player->weaponAttack = 9;
            break;
        default:
            printf("\nInvalid choice, defaulting to Bow and Arrow.\n");
            strcpy(player->weapon, "Bow and Arrow");
            player->weaponAttack = 5;
    }
    printf("\nYou have chosen: %s (+%d Attack)\n", player->weapon, player->weaponAttack);
}

// Function to assign skill
void assignSkill(Character *player) {
    printf("\nChoose your character skill:\n");
    printf("1. Flame Strike (Power: 15)\n");
    printf("2. Healing Aura (Power: 10, Heal)\n");
    printf("3. Shield Bash (Power: 8, Defense Boost)\n");
    printf("4. Thunder Strike (Power: 18)\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            strcpy(player->skill, "Flame Strike");
            player->skillPower = 15;
            break;
        case 2:
            strcpy(player->skill, "Healing Aura");
            player->skillPower = 10;
            break;
        case 3:
            strcpy(player->skill, "Shield Bash");
            player->skillPower = 8;
            break;
        case 4:
            strcpy(player->skill, "Thunder Strike");
            player->skillPower = 18;
            break;
        default:
            printf("\nInvalid choice, defaulting to Flame Strike.\n");
            strcpy(player->skill, "Flame Strike");
            player->skillPower = 15;
    }
    printf("\nYou have chosen skill: %s (Power: %d)\n", player->skill, player->skillPower);
}

// Function for combat
void combat(Character *player, char *enemyName, int enemyHealth, int enemyAttackPower) {
    printf("\nA fierce %s appears!\n", enemyName);
    while (player->health > 0 && enemyHealth > 0) {
        // Option to use skill
        printf("\nDo you want to use your skill?\n");
        printf("1. Yes, use %s.\n", player->skill);
        printf("2. No, continue fighting with the weapon.\n");
        int choice;
        scanf("%d", &choice);
        
        int playerAttack = rand() % (player->attack + player->weaponAttack) + 1;
        if (choice == 1) {
            printf("\nYou use your %s for %d extra damage!\n", player->skill, player->skillPower);
            playerAttack += player->skillPower;
        }

        int enemyAttack = rand() % enemyAttackPower + 1;
        printf("\nYou attack %s with your %s for %d damage!\n", enemyName, player->weapon, playerAttack);
        enemyHealth -= playerAttack;
        if (enemyHealth <= 0) {
            printf("You defeated %s!\n", enemyName);
            player->experience += 10;  // Gain experience
            if (player->experience >= 50) {  // Level up condition
                player->level++;
                printf("Congratulations! You've leveled up to Level %d!\n", player->level);
                player->experience = 0;  // Reset experience for next level
            }
            return;
        }

        printf("%s attacks you for %d damage!\n", enemyName, enemyAttack);
        player->health -= enemyAttack;
        if (player->health <= 0) {
            printf("You have fallen in battle...\n");
            exit(0);
        }
    }
}

// Ending story function
void endingStory(Character *player) {
    printf("\nThe journey has been long and perilous, but you have made it to the final trial.\n");
    printf("With your strength, wisdom, and the mystical amulet from the defeated giant Leltaha, you stand at the gates of the Sacred Temple.\n");
    printf("The ancient guardian spirit appears, glowing in ethereal light. It speaks:\n");
    printf("\"You have faced the challenges and survived the trials. But only the worthy may claim the stone.\"\n");

    // Player's decision at the end
    printf("\nWill you claim the sacred stone?\n");
    printf("1. Yes, I will claim the stone.\n");
    printf("2. No, I will leave and return to my village.\n");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nWith one final step, you claim the stone and feel immense power coursing through you!\n");
        printf("Your health and strength are now unmatched. You are destined to protect the village and become a legend.\n");
        printf("The jungle whispers your name, and you return to the village, victorious and revered.\n");
    } else {
        printf("\nYou decide that the power of the stone is too great to control. You leave the temple, choosing the safety of your village over glory.\n");
        printf("The villagers celebrate your bravery, and your name becomes a story told for generations.\n");
    }
}

int main() {
    srand(time(NULL));
    
    Character player = {"", 30, 10, 5, 0, 1, "", 0, "", 0};  // Initialize player with empty name
    
    // Ask for player name
    printf("Enter your character's name: ");
    scanf("%s", player.name);
    
    introduction(&player);
    selectWeapon(&player);
    assignSkill(&player);
    
    combat(&player, "Gaidu Bagh (Were-Tiger)", 20, 5);  // Initial combat
    printf("\nYou've entered the jungle...\n");
    
    endingStory(&player);  // Ending story based on the player's choices
    
    return 0;
}
