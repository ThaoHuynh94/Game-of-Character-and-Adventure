# Game of Character and Adventure

This project is a simple text-based adventure game implemented in C++. Players control a character that can explore various locations, interact with NPCs (non-player characters), and complete quests. The game showcases core object-oriented programming (OOP) principles such as inheritance, polymorphism, and encapsulation.

## Features
- **Character Class**: The base class for creating player and NPC characters.
- **Rogue, Knight, Wizard**: Different character types, each with unique abilities and attributes.
- **Monster**: Represents hostile creatures the player can encounter.
- **Gameplay**: Basic interaction between the player character and NPCs, with quests and combat elements.
- **Object-Oriented Design**: Uses OOP principles like inheritance and polymorphism to structure the game.

## Files
- **Character.h / Character.cpp**: Defines the base character class with common properties and methods.
- **Rogue.h / Rogue.cpp**: Derived from `Character`, represents a Rogue character with unique abilities.
- **Knight.h / Knight.cpp**: Derived from `Character`, represents a Knight character with special traits.
- **Wizard.h / Wizard.cpp**: Derived from `Character`, represents a Wizard with magical abilities.
- **Monster.h / Monster.cpp**: Defines the Monster class, representing hostile creatures in the game.
- **Character.driver**: Main driver file that runs the game loop, handling player input, and simulating the gameplay.
