#include "Rogue.h"

Rogue::Rogue(std::string name, int startingExperiencePoints, int startingHitPoints)
: Character(name, startingExperiencePoints, startingHitPoints), hidden(false) {}

int Rogue::attack()
{
    //reset the hidden state to false when the Rogue performs an attack
    if (hidden)
    {
        hidden = false;

        return ROGUE_ATTACK_SCALAR * getLevel(); // Attack value when hidden
    }

    return Character::attack();                 // Normal attack if not hidden
}


void Rogue::damage(int points)
{

    if (hidden)
    {
            points /= ROGUE_DAMAGE_SCALAR;      // Halve the damage if hidden
    }
     Character::damage(points);                // Call base class damage method with calculated points

}

void Rogue::hide()
{
    hidden = true; // Set hidden to true
}



bool Rogue::isHidden() const
{
    return hidden; // Return the hidden status
}
