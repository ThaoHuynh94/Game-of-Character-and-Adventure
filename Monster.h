#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

/**
 * @class Monster
 * @brief The Monster class represents an enemy that characters fight.
 *
 * The monster behaves similarly to a base character in terms of attack and damage,
 * but when defeated, it gives an experience points reward to the characters.
 */
class Monster: public Character{

private:
    int experiencePointsValue;  // The experience points reward that the monster gives upon defeat.
public:

    /**
     * @brief Parameterized constructor to initialize the monster's attributes.
     *
     * Initializes the monster with a name, starting experience points, starting hit points,
     * and experience points value.
     *
     * @param name The name of the monster.
     * @param startingExperiencePoints The monster's initial starting experience points.
     * @param startingHitPoints The monster's initial hit points.
     * @param experiencePointsValue The experience points that the monster rewards when defeated.
     */
    Monster(std::string name, int startingExperiencePoints, int startingHitPoints, int experiencePointsValue);

    /**
    * @brief to return the experience points reward for defeating the monster.
    *
    * This method provides the experience points that characters will receive after defeating the monster.
    *
    * @return The experience points value as an integer.
    */
    int getExperienceReward();


    /**
    * @brief Virtual function representing the monster's attack.
    *
    * By default, the monster's attack is the same as the base `Character` class.
    * This method overrides the base class's attack method but uses the same behavior.
    *
    * @return The attack damage dealt by the monster.
    */
    int attack() override;


    /**
     * @brief Virtual function for applying damage to the monster.
     *
     * The monster takes damage similarly to the base `Character` class.
     * This method overrides the base class damage method but uses the same behavior.
     *
     * @param points The number of damage points inflicted on the monster.
     */
    void damage(int points) override;

};

#endif //MONSTER_H


