#ifndef KNIGHT_H
#define KNIGHT_H
#include "Character.h"

const int KNIGHT_ATTACK_SCALAR = 5; // Attack scalar for calculating the knight's attack value.
const int KNIGHT_DAMAGE_SCALAR = 2; // Damage scalar for reducing damage received by the knight.

/**
 * @class Knight
 * @brief The Knight class represents a character wearing heavy armor in the game.
 *
 * The knight is a specialized type of character that deals moderate damage
 * but takes only 50% of the damage they would normally receive due to their heavy armor.
 */
class Knight :public Character{
public:

    /**
    * @brief Constructor to initialize the knight's name, starting experience points, and starting hit points.
    *
    * @param name The name of the knight.
    * @param startingExperiencePoints The knight's initial experience points.
    * @param startingHitPoints The knight's initial hit points.
    */
    Knight(std::string name, int startingExperiencePoints, int startingHitPoints);

    /**
    * @brief Virtual function representing the knight's attack.
    *
    * The attack value is calculated as 5 * the knight's level.
    * This method overrides the base class attack method to provide knight-specific behavior.
    *
    * @return The attack damage dealt by the knight.
    */
     int attack() override;

    /**
    * @brief Virtual function for applying damage to the knight.
    *
    * The knight takes only 50% of the incoming damage due to their heavy armor.
    * This method overrides the base class damage method to implement this behavior.
    *
    * @param points The number of damage points inflicted on the knight.
    */
     void damage(int points) override;

};


#endif //KNIGHT_H
