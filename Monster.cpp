#include "Monster.h"

Monster::Monster(std::string name,int startingExperiencePoints, int startingHitPoints, int experiencePointsValue):
experiencePointsValue(experiencePointsValue), Character(name, startingExperiencePoints, startingHitPoints) {}


int Monster:: getExperienceReward()
{
    return experiencePointsValue;
}

int Monster:: attack()
{
    return Character::attack();

}

void Monster:: damage(int points)
{
    return Character::damage(points);
}

