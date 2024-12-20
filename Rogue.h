#ifndef ROGUE_H
#define ROGUE_H
#include "Character.h"

const int ROGUE_ATTACK_SCALAR = 15; // The attack scalar for the Rogue when hidden.
const int ROGUE_DAMAGE_SCALAR = 2;  // The damage reduction scalar when the Rogue is hidden.


/**
 * @class Rogue
 * @brief to represent a sneaky attacker class in the game with special abilities to hide and deal extra damage.
 *
 * Rogues can hide from enemies, allowing them to perform a stronger attack.
 * When hidden, Rogues deal greater damage and take reduced damage.
 * Their stealth makes them dangerous and hard to hit effectively.
 */
class Rogue : public Character {

private:
        bool hidden; // Track whether the Rogue is hidden
public:
    /**
    * @brief Parameterized Constructor to initialize the Rogue with a name,
    * starting experience points, and starting hit points.
    *
    * To initialize a Rogue character with a specified name, level, and hit points.
    * The Rogue starts in an unhidden state.
    *
    * @param name The name of the Rogue.
    * @param startingExperiencePoints The initial experience points of the Rogue.
    * @param startingHitPoints The initial hit points of the Rogue.
    */
    Rogue(std::string name, int startingExperiencePoints, int startingHitPoints);

    /**
    * @brief to hide the Rogue.
    *
    * Sets the Rogue's hidden status to true, allowing the Rogue to perform a stronger attack
    * on their next move.
    */
    void hide();

    /**
    * @brief to check if the Rogue is hidden.
    *
    * @return True if the Rogue is hidden, false otherwise.
    */
    bool isHidden() const;

    /**
     * @brief to override of the virtual attack method for the Rogue class.
     *
     * If the Rogue is hidden, they deal 15 * their level in damage.
     * The hidden status is reset after attacking.
     * If not hidden, the Rogue performs a normal attack as defined by the base 'Character' class.
     *
     * @return The attack damage dealt by the Rogue.
     */
    int attack() override;

    /**
     * @brief to override of the virtual damage method for the Rogue class.
     *
     * If the Rogue is hidden, they only take 50% of the incoming damage.
     * This method calls the base class 'damage()' method to apply the calculated damage to the Rogue.
     *
     * @param points The number of damage points inflicted on the Rogue.
     */
    void damage(int points) override;
};


#endif //ROGUE_H
