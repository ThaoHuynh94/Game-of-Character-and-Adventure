#include "Character.h"

//parameterized constructor

Character:: Character (std::string name, int startingExperiencePoints, int startingHitPoints)
        : name(name), experiencePoints(startingExperiencePoints), hitPoints(startingHitPoints)
{
    // Calculate max hit points based on the level
    maxHitPoints = getLevel() * MAX_HIT_POINTS_SCALAR;
}



//setters-mutators

void Character::gainExperience(int points)
{
    //update experience points
    experiencePoints += points;


    // update max hit points based on the number of levels gained
    maxHitPoints = getLevel() * MAX_HIT_POINTS_SCALAR;

}

void Character::heal(int points)
{
    //A dead character can not be healed
    if (isDead())
    {
        return;
    }
    else if (health() > PERCENTAGE_CONVERT)
    {
        std::cout<<"The character whose health is more than 100% can not be healed!"<<std::endl;
        return;
    }
    else
    {
        //update the hit points

        hitPoints += points;

        //A character hit points can not go beyond max hitPoints

        if (hitPoints >maxHitPoints)
        {
            hitPoints = maxHitPoints;
        }
    }

}


void Character::damage(int points)
{

    //check if the character is still alive
    if (!isDead())
    {
        // decrease current hit points
        hitPoints -= points;

        //a character's hit points can not go below zero
        if (hitPoints< 0)
        {
            hitPoints = 0;
        }
    }
}



//getters-accessors


std::string Character::getName() const
{
    return  name;
}



int Character::getLevel() const
{
    return (experiencePoints/EXPERIENCE_POINTS_PER_LEVEL);
}


int Character::getMaxHitPoints() const
{
    return  maxHitPoints;
}


double Character::health() const
{
    // Dead characters should return 0.00%
    if (isDead()) {
        return DEATH_HEALTH_PERCENTAGE;
    }

    // Handle cases where maxHitPoints is 0 to avoid division by zero.
    if (maxHitPoints == 0) {
        return 0.0;
    }

    return (static_cast<double>(hitPoints) / maxHitPoints) * PERCENTAGE_CONVERT;

}


bool Character::isDead() const
{
    // Check if hitPoints is zero : the character is dead

    return (hitPoints == 0);
}


int Character::attack()
{
    //attack value should be DAMAGE_SCALAR (5) * the character's level
    return (getLevel() * DAMAGE_SCALAR);
}


