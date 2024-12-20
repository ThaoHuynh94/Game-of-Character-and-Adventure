#include <iostream>
#include <vector>
#include <limits>
#include "Character.h"
#include "Knight.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Monster.h"
#include <iomanip> //for std::setw


// Constants for character options
const int OPTION_1 = 1;
const int OPTION_2 = 2;
const int OPTION_3 = 3;

// Function prototypes

/**
 * @brief to create a new character based on user input.
 *
 * @return A pointer to the newly created Character, or nullptr if creation fails.
 */
Character* createCharacter();

/**
 * @brief to create a new monster based on user input.
 *
 * @return A pointer to the newly created Monster.
 */
Monster* createMonster();


/**
 * @brief to simulate an attack from the monster on the character.
 *
 * @param character A pointer to the player Character.
 * @param monster A pointer to the Monster.
 */
void monsterAttack(Character* character, Monster* monster);

/**
 * @brief to display the character and monster statistics.
 *
 * @param character A pointer to the player Character.
 * @param monster A pointer to the Monster.
 */
void showCharacterStatistics(Character* character, Monster* monster);


/**
 * @brief to handle healing  for the character and mana restoration if the character is a Wizard
 *
 * @param character A pointer to the player Character.
 */
void handleHealingAndMana(Character* character);

/**
 * @brief to display the menu options for the player.
 *
 * @return The player's choice as an integer.
 */
int showMenu();


/**
 * @brief Main game loop that manages character creation and interactions.
 *
 * This function handles the flow of the game, including creating a player character and a monster
 * and allowing the player to choose actions until the game ends or the character is defeated.
 */
void gameRunning();


int main()
{
    gameRunning();  // Start the game
    return 0;
}

void gameRunning()
{
    std::vector<Character*> characters; //Vector to hold player characters
    char tryAgain;                      //Variable to check if player wants to retry character creation

    // Create a player character
    Character* player = createCharacter();

    // Loop until a valid character is created or the player chooses to quit
    while (player == nullptr)
    {
        std::cout << "Character creation failed or cancelled. Would you like to try again? (y/n): ";
        std::cin >> tryAgain;

        if (tryAgain == 'y' || tryAgain == 'Y')
        {
            player = createCharacter(); // Retry character creation
        }
        else
        {
            std::cout << "Exiting the game." << std::endl;
            return;                    // Exit the game if the player chooses not to retry
        }
    }

    characters.push_back(player);      //Add the player character to the list

    // Create a monster
    Monster* monster = createMonster();


    int choice;                        // Variable to store the player's menu choice
    do {
        choice = showMenu();          // Show menu options to the player

        switch (choice)
        {
            case 1: // Attack the monster
                monsterAttack(player, monster);
                break;
            case 2: // Show character statistics
                showCharacterStatistics(player, monster);
                break;
            case 3: // Exit the game
                std::cout << "Exiting the game!" << std::endl;
                break;
            default:
            {
                std::cout << "Invalid choice! Exiting the game!" << std::endl;
                break;
            }

        }

        // Check if the monster is defeated
        if (monster->health() <= 0)
        {
            std::cout << "The monster " << monster->getName() << " has been defeated!" << std::endl;
            break;  // Exit the game or restart
        }

        // Check if the player character is defeated
        if (player->health() <= 0)
        {
            std::cout << "You have been defeated by " << monster->getName() << "!" << std::endl;
            break;  // Exit the game
        }

    } while (choice != 3);   //Repeat until the player chooses to exit

    // Free allocated memory for the player and monster
    for (Character* character : characters) {
        delete character;   // Delete player characters to prevent memory leaks
    }
    delete monster;         // Delete the monster
}

// Function to show the menu
int showMenu()
{

    int choice;     //Variable to store user input
    std::cout << "\nMenu Options:\n";
    std::cout << "1. Attack the Monster\n";
    std::cout << "2. Show Character Stats\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";

        // Loop until valid input
        while (true)
        {
            std::cin >> choice;

            if (std::cin.fail() || choice < OPTION_1 || choice > OPTION_3)
            {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Please enter a number between " << OPTION_1 << " and " << OPTION_3 << ": ";
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break; // Valid input, exit the loop
            }
        }
        return choice; // Return the user's choice
}


// Function to create a new character
Character* createCharacter()
{
    std::string characterName;         // Variable for the character's name
    int experiencePoints, hitPoints;  // Variables for character attributes
    int manaPoints;                   // Variable to store Wizard's mana points
    int choice;                       // Variable to store character type choice

    std::cout << "Choose character type (Enter 1 for Knight, 2 for Wizard, 3 for Rogue): ";

    // Loop until valid choice for character type

    while (!(std::cin >> choice) || choice > OPTION_3 || choice < OPTION_1)
    {
        std::cout << "Invalid choice. Please enter your choice again: ";
        std::cin.clear();            //Clear input error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }

    std::cout << "Enter character name: ";
    std::cin >> characterName;      // Get character name

    std::cout << "Enter character starting experience points: ";
    // Loop until valid input for level

    while (!(std::cin >> experiencePoints) || experiencePoints < 0) {
        std::cout << "Invalid starting experience points. Please enter the character experience points again: ";
        std::cin.clear();        //Clear input error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }

    std::cout << "Enter character starting hit points: ";
    // Loop until valid input for hit points

    while (!(std::cin >> hitPoints) || hitPoints < 0) {
        std::cout << "Invalid starting hit points. Please enter the starting hit points again: ";
        std::cin.clear();        // Clear input error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }

    // Create the character based on the type chosen by the user

    if (choice == OPTION_1)
    {
        return new Knight(characterName, experiencePoints, hitPoints); // Create Knight
    }
    else if (choice == OPTION_2)
    {
        std::cout << "Enter starting mana points: ";
        std::cin >> manaPoints;  // Get starting mana for Wizard
        return new Wizard(characterName, experiencePoints, hitPoints, manaPoints); // Create Wizard
    }
    else if (choice == OPTION_3)
    {
        return new Rogue(characterName, experiencePoints, hitPoints);// Create Rogue
    }
    return nullptr; // Return nullptr if no valid character is created
}

// Function to create a new monster
Monster* createMonster()
{
    std::string monsterName; // Variable for the monster's name
    int experiencePoints, hitPoints, experiencePointValues;// Variables for monster attributes

    // Monster(std::string name, int startingExperiencePoints, int startingHitPoints, int experiencePointsValue);

    std::cout << "Enter monster name: "; // Get monster name
    std::cin >> monsterName;

    std::cout << "Enter monster starting experience points: ";
    // Loop until valid input for level

    while (!(std::cin >> experiencePoints) || experiencePoints < 0) {
        std::cout << "Invalid monster starting experience points. Please enter the monster experience points again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter monster starting hit points: ";
    // Loop until valid input for hit points
    while (!(std::cin >> hitPoints) || hitPoints < 0) {
        std::cout << "Invalid starting hit points. Please enter the monster starting hit points again: ";
        std::cin.clear();// Clear input error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignore invalid input
    }

    std::cout << "Enter experience point values for characters if monster defeated: ";
    // Loop until valid input for level

    while (!(std::cin >> experiencePointValues) || experiencePointValues < 0) {
        std::cout << "Invalid monster experience point values. Please enter the experience point values again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return new Monster(monsterName, experiencePoints, hitPoints, experiencePointValues);
}

// Function to show character stats
void showCharacterStatistics(Character* character, Monster* monster)
{
    std::cout << std::left; // Align to the left

    // Print character statistics
    std::cout << "\nCharacter Statistics:\n";
    std::cout << std::setw(20) << "Name:" << character->getName() << "\n";
    std::cout << std::setw(20) << "Level:" << character->getLevel() << "\n";
    std::cout << std::setw(20) << "Health:" << character->health() << "%\n";
    std::cout << std::setw(20) << "Max Hit Points:" << character->getMaxHitPoints() << "\n";
    std::cout << std::setw(20) << "Status:" << (character->isDead() ? "Dead" : "Alive") << "\n";

    // Print monster statistics
    std::cout << "\nMonster Statistics:\n";
    std::cout << std::setw(20) << "Name:" << monster->getName() << "\n";
    std::cout << std::setw(20) << "Level:" << monster->getLevel() << "\n";
    std::cout << std::setw(20) << "Health:" << monster->health() << "%\n";
    std::cout << std::setw(20) << "Max Hit Points:" << monster->getMaxHitPoints() << "\n";
    std::cout << std::setw(20) << "Status:" << (monster->isDead() ? "Dead" : "Alive") << "\n";

    // Call the new function to handle healing and mana restoration
    handleHealingAndMana(character);
}

// Function to simulate monster attacks
void monsterAttack(Character* character, Monster* monster)
{
    std::cout << std::left; // Align to the left

    // Print the attack action
    std::cout << std::setw(20) << "Action:" << "Monster " << monster->getName() << " attacks " << character->getName()
              << " for " << monster->attack() << " damage!" << std::endl;

    // Monster attacks the character
    int damage = monster->attack();
    character->damage(damage);
    std::cout << std::setw(20) << "Remaining Health:" << character->getName() << "'s remaining health: "
              << character->health() << "%" << std::endl;

    // Player attacks back
    int playerDamage = character->attack();
    std::cout << std::setw(20) << "Action:" << character->getName() << " attacks " << monster->getName()
              << " for " << playerDamage << " damage!" << std::endl;

    monster->damage(playerDamage);
    std::cout << std::setw(20) << "Remaining Health:" << "Monster " << monster->getName()
              << "'s remaining health: " << monster->health() << "%" << std::endl;

    // Check if the monster is defeated
    if (monster->health() <= 0) {
        std::cout << std::setw(20) << "Defeated:" << "The monster " << monster->getName() << " has been defeated!" << std::endl;
        int experienceGained = monster->getExperienceReward(); // Get experience reward
        std::cout << std::setw(20) << "Experience Gained:" << character->getName()
                  << " gains " << experienceGained << " experience points!" << std::endl;
        // Award experience to the character
        character->gainExperience(experienceGained);
    }
}


void handleHealingAndMana(Character* character) {
    char choice;    // Variable for user choice on healing and mana restoration

    // Ask if the player wants to heal the character
    std::cout << "Do you want to heal " << character->getName() << "? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int healAmount; // prompt the user for a specific heal amount if you like

        std::cout << "How much heal points for? ";

        // Loop until valid input for heal amount
        while (!(std::cin >> healAmount) || healAmount < 0) {
            std::cout << "Invalid heal points. Please enter heal points again: ";
            std::cin.clear();   //Clear input error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        }

        character->heal(healAmount);     // Heal the character
        std::cout << character->getName() << " has been healed by " << healAmount << " points!" << std::endl;
    }


    // If the character is a wizard, ask about mana restoration

    // Use dynamic_cast to check if character is a Wizard

    if (Wizard *wizard = dynamic_cast<Wizard *>(character))
    {
        std::cout << "Do you want to add mana to " << wizard->getName() << "? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            int manaAmount; // Variable to store the amount of mana requested

            std::cout << "How much mana points for?";

            // Loop until valid input for mana amount
            while (!(std::cin >> manaAmount) || manaAmount < 0)
            {
                std::cout << "Invalid mana amounts. Please enter mana again: ";
                std::cin.clear();// Clear input error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignore invalid input
            }
            wizard->addMana(manaAmount);// Restore mana to the wizard
            std::cout << wizard->getName() << " has gained " << manaAmount << " mana points!" << std::endl;

        }
    }
}
