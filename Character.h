#ifndef CHARACTER_H
#define CHARACTER_H

static const int DAMAGE_SCALAR                  = 5;         //Damage scalar used to calculate damage inflicted by characters.
static const int EXPERIENCE_POINTS_PER_LEVEL    = 100;      // Number of experience points required to level up a character.
static const int MAX_HIT_POINTS_SCALAR          = 150;      //Represent the highest possible hit points for a character.
static const double PERCENTAGE_CONVERT          = 100.00;   // This constant is used in calculations that require percentage representations.
static const double DEATH_HEALTH_PERCENTAGE     = 0.0;      //Represent the threshold for a character being considered dead.

#include <string>
#include <iostream>


/**
 * @class Character
 * Base class representing a character in the game.
 * Each character has a name, level, hit points, and can perform actions such as attacking and taking damage.
 */
class Character {
private:
    std::string name;       //hold the name of the character
    int experiencePoints;   //hold the experience points
    int hitPoints;          //hold the hit points
    int maxHitPoints;       //hold the max hit points
public:
    /**
    * @brief Parameterized Constructor
    *       to initialize the character's name, level, and starting hit points.
    *
    * @param name The character's name.
    * @param startingExperiencePoints The character's starting experience points.
    * @param startingHitPoints The character's initial hit points.
    */
    Character(std::string name, int startingExperiencePoints, int startingHitPoints);


    /**
    * @brief Returns the character's name.
    * @return The character's name.
    */
    std::string getName() const;

    /**
    * @brief to return the character's current level.
    *
    * @return The level of the character.
    */
    int getLevel() const;


    /**
    * @brief to return the character's maximum hit points.
    *
    * @return The maximum hit points of the character.
    */

    int getMaxHitPoints() const;

    /**
     * @brief to return the character's current health as a percentage (0-100).
    * If the character is dead, returns 0.00%.
    *
    * @return The character's health percentage.
    */
    double health() const;

    /**
    * @brief to increase the character's experience points and levels up if needed.
    *
    * @param points The amount of experience points to be added.
    */
    void gainExperience(int points);



    /**
    * @brief to heal the character by adding hit points, but does not exceed max hit points.
    * If the character is dead or has more than 100% health, healing is not allowed.
    *
    * @param points The amount of hit points to add.
    */
    void heal(int points);


    /**
     * @brief Virtual function representing the character's attack.
     * By default, the attack value is 5 * the character's level.
     * This function is virtual and can be overridden by derived classes for custom attack behavior.
     *
     * @return int The attack damage dealt by the character.
     */
    virtual int attack() ;


    /**
     * @brief Virtual function for applying damage to the character.
     * This function can be overridden in derived classes to provide custom damage behavior.
     *
     * Reduces the character's current hit points by the specified number of damage points.
     *
     * @note A character's hit points cannot drop below zero, and a dead character cannot receive any more damage.
     *
     * @param points The number of damage points inflicted on the character.
     */
    virtual void damage(int points);

    /**
     * @brief Checks if the character is dead.
     * @note A character is dead if his hit points are 0.
     * @return true if the character is dead, false otherwise.
     */

    bool isDead() const;


    /**
     * @brief Virtual destructor for the Character class.
     *
     * Ensures that destructors of derived classes are called correctly when a Character object is deleted.
     *
     * @note Using a virtual destructor is important in base classes to prevent memory leaks and
     * undefined behavior when deleting derived class objects through a base class pointer.
     */

    virtual ~Character(){}


};


#endif //CHARACTER_H
