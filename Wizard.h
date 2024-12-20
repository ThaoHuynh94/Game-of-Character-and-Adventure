#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"

const int WIZARD_ATTACK_SCALAR  = 20;   //The attack scalar for the Wizard's fireball spell.
const int MANA_POINT_LOST       = 25;   //The amount of mana points consumed per fireball cast.
const int ATTACK_WITHOUT_MANA   = 10;   //The damage dealt by the Wizard when out of mana.

/**
 * @class Wizard
 * @brief to represent a magic-wielding character capable of casting spells.
 *
 * Wizards can attack using powerful fireball spells as long as they have mana.
 * They can also  regenerate their mana points.
 * When out of mana, they can only deal limited damage using their wand.
 */
class Wizard : public Character{
private:
    int mana;   //Holds the current mana points of the Wizard.
public:
    /**
    * @brief Parameterized Constructor to initialize the Wizard with a name, starting experience points,
    * starting hit points, and mana points.
    *
    * Initializes the Wizard character with specified attributes.
    * The Wizard starts with a defined amount of mana, allowing them to cast spells.
    *
    * @param name The name of the Wizard.
    * @param startingExperiencePoints The initial experience points of the Wizard
    * @param startingHitPoints The initial hit points of the Wizard.
    * @param startingManaPoints The initial mana points of the Wizard.
    */
    Wizard(std::string name,  int startingExperiencePoints, int startingHitPoints, int startingManaPoints);

    /**
    * @brief to add mana points to the Wizard.
    *
    * Increases the Wizard's mana points by the specified amount.
    * This can be used to regenerate mana after casting spells.
    *
    * @param points The number of mana points to add.
    */
    void addMana(int points);

    /**
    * @brief Override of the virtual attack method for the Wizard class.
    *
    * Wizards cast fireball spells that deal significant damage.
    * If the Wizard has enough mana, they attack for 20 * their level in damage.
    * If mana is insufficient, they deal reduced damage by bonking the opponent with their wand.
    *
    * @return The attack damage dealt by the Wizard.
    */
    int attack() override;

    /**
    * @brief Override of the virtual damage method for the Wizard class.
    *
    * Applies damage to the Wizard by calling the base class method.
    * This method manages the health points when damage is received.
    *
    * @param points The number of damage points inflicted on the Wizard.
    */
    void damage(int points) override;


};


#endif //WIZARD_H
