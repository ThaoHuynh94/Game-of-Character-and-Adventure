#include "Knight.h"

Knight:: Knight(std::string name, int startingExperiencePoints, int startingHitPoints)
: Character(name,startingExperiencePoints, startingHitPoints) {}


int Knight :: attack()
{
    // The attack value should be 5 * the knight's level

    return (KNIGHT_ATTACK_SCALAR * getLevel());
}


void Knight :: damage(int points)
{
    // Knights take only 50% of the damage
    int reducedDamage = points / KNIGHT_DAMAGE_SCALAR;

    // Call the base class damage method with reduced damage
    Character::damage(reducedDamage);
}