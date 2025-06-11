#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Player structure
typedef struct {
    char name[50];
    int health;
    int attack;
    int defense;
    int hasAmulet;
    char weapon[20];
    int weaponAttack;
} Player;

// Function to display introduction
void introduction(Player *player) {
    printf("\nWelcome, traveler! You have entered the village of Chitrawan.\n");
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
void selectWeapon(Player *player) {
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

// Function for Tharu food encounter
void eatTharuFood(Player *player) {
    printf("\nYou find a vendor selling traditional Tharu food. The smell is intoxicating!\n");
    printf("The vendor offers you a hearty meal, saying it will rejuvenate your strength.\n");
    printf("Do you want to eat the food?\n");
    printf("1. Yes, eat the food.\n");
    printf("2. No, decline the offer.\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nYou devour the Tharu food, and you feel your strength returning!\n");
        player->health += 15;  // Increase health
        player->attack += 3;   // Increase attack power
        player->defense += 2;  // Increase defense
        printf("Your health increases by 15, attack by 3, and defense by 2!\n");
    } else {
        printf("\nYou decline the food, feeling cautious.\n");
    }
}

// Function for combat with Tharu food during battle
void combatWithFood(Player *player, char *enemyName, int enemyHealth, int enemyAttackPower) {
    printf("\nA fierce %s appears!\n", enemyName);
    while (player->health > 0 && enemyHealth > 0) {
        // Option to eat Tharu food during combat
        printf("\nDuring the battle, you feel hunger creeping in. Do you want to eat Tharu food?\n");
        printf("1. Yes, eat the food.\n");
        printf("2. No, continue fighting.\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            eatTharuFood(player);  // Increase health and stats
        }

        int playerAttack = rand() % (player->attack + player->weaponAttack) + 1;
        int enemyAttack = rand() % enemyAttackPower + 1;
        printf("\nYou attack %s with your %s for %d damage!\n", enemyName, player->weapon, playerAttack);
        enemyHealth -= playerAttack;
        if (enemyHealth <= 0) {
            printf("You defeated %s!\n", enemyName);
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

// Function to explore a hidden temple
void exploreTemple(Player *player) {
    printf("\nAs you journey deeper into the jungle, you discover an ancient temple covered in vines.\n");
    printf("Inside, you see two paths:\n");
    printf("1. Enter the dark chamber where strange noises echo.\n");
    printf("2. Follow the glowing symbols along the walls.\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nYou enter the dark chamber and suddenly a mighty giant named Leltaha appears!\n");
        printf("Leltaha, with glowing red eyes, massive muscles, and a spiked club, lets out a thunderous roar!\n");
        printf("The ground shakes as he swings his club toward you, breaking stones and sending debris flying!\n");
        printf("Leltaha's abilities include: \n");
        printf("- Earthquake Smash (Massive AoE damage)\n");
        printf("- Roaring Shockwave (Stuns for one turn)\n");
        printf("- Regeneration (Heals every 3 turns)\n");
        combatWithFood(player, "Leltaha", 60, 12);  // Combat with the option to eat Tharu food
        printf("\nAfter an intense battle, Leltaha drops a mystical amulet, increasing your defense and attack!\n");
        player->defense += 7;
        player->attack += 5;
    } else {
        printf("\nYou follow the glowing symbols and discover an enchanted sword! Attack power increases significantly!\n");
        player->weaponAttack += 6;
    }
}

int main() {
    srand(time(NULL));
    Player player = {"Traveler", 30, 10, 5, 0, "", 0};
    introduction(&player);
    selectWeapon(&player);
    combatWithFood(&player, "Gaidu Bagh (Were-Tiger)", 20, 5);
    exploreTemple(&player);
    printf("\nYour journey through the legend continues...\n");
    return 0;
}
