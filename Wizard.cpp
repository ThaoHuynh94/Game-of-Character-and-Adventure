#include "Wizard.h"

Wizard:: Wizard(std::string name, int startingExperiencePoints, int startingHitPoints, int startingManaPoints):
Character (name, startingExperiencePoints, startingHitPoints), mana(startingManaPoints){}

void Wizard::addMana(int points)
{
    mana += points;
}

int Wizard::attack()
{
    if (mana >= MANA_POINT_LOST)
    {
        mana -= MANA_POINT_LOST; // Deduct mana points for casting

        return (getLevel()*WIZARD_ATTACK_SCALAR);
    }
    else
    {
        return (ATTACK_WITHOUT_MANA);
    }

}
void Wizard::damage(int points)
{
    Character::damage(points); // Call base class damage method
}