# Game of Character and Adventure

## Description

This project is a **text-based adventure game** written in C++. The player controls a character who can navigate through different rooms, interact with NPCs, and complete quests. The game is built using **object-oriented programming** principles and features a flexible design to allow easy additions and modifications.

## Features:
- **Character Creation**: Customize your character's name, attributes, and inventory.
- **Room Navigation**: Move between different rooms in the game world.
- **NPC Interaction**: Interact with NPCs to learn about quests and complete them.
- **Inventory Management**: Collect items and use them to solve puzzles or progress in quests.
- **Game Loop**: A text-based interface allows players to input commands and progress through the game.

## Files:
- **Character.cpp**: Implements the `Character` class, responsible for player attributes and actions.
- **Room.cpp**: Implements the `Room` class, representing the different locations in the game.
- **NPC.cpp**: Implements NPC behavior and interactions.
- **main.cpp**: The entry point that runs the game loop and handles user input.

## Requirements:
- C++11 or later
- A C++ compiler (e.g., g++)

## How to Run:
1. Clone the repository to your local machine:
    ```
    git clone https://github.com/yourusername/GameOfCharacterAndAdventure.git
    ```
2. Navigate to the project directory:
    ```
    cd GameOfCharacterAndAdventure
    ```
3. Compile the code:
    ```
    g++ main.cpp Character.cpp Room.cpp NPC.cpp -o game
    ```
4. Run the game:
    ```
    ./game
    ```

## Example Gameplay:
