# Rogue ASCII Game

### About this project

This is Rogue ASCII CLI Game suggested by the [MakingGamesWithBen channel](https://www.youtube.com/@makinggameswithben) and [here](https://www.youtube.com/watch?v=tVWckBaB5xo&list=PLSPw4ASQYyynKPY0I-QFHK0iJTjnvNUys&index=29) is his implementation of it.


### Challenge Requirements

In this game challenge, you will be making an ASCII Roguelike RPG game! Here's some of the features you should include, but be sure to go above and beyond!

1. Load the ASCII levels from a level file! Like level1.txt, level2.txt -- Done

2. Allow player movement using <wasd>. (getch() can be used). -- Done

3. Have some enemies that randomly move around, and allow the player to attack them! -- Done

4. Make sure the player can't walk through walls! -- Done

### What to do Next:

- Create different types of monsters -- Done

- Make it so that when the level is loaded, it creates respective monster Objects for their positions and insert them in the m_monsters vector

- Create save feature

- Display Player current status -- Done

##### Optional Objectives:

5. Make it so that you can save the game and load it!

6. Add items and money to the game, and an item shop!

7. Allow the player to level up when he gets experience!

8. Have multiple levels!

You could use '#' for walls, '.' for air, '@' for player, and letters for monsters!


### Tools used

- Git (for Version Management)
- GitHub (Remote Repository)
- Meson with Ninja (Build System)
- C++ (Main Programming Language)
- Trello (Task Tracker)
- [AsciiFlow](https://asciiflow.com) (Map Drawing)


### My Approach to it

The player and monsters are gonna have basic stats.

##### Stats

- Atk
- Def
- HP
- Speed

The Damage calculation will be playerATK - monsterDEF and the same the other way around.

Battles will be taken in turns, and that who has the highest Speed attacks first.

Player will spawn in a default position in level1.txt. Each level is gonna have 24x7.

##### Map Legend

- @ (Player)
- \# (Wall)
- . (Empty Walkable Space)
- G (Green goblin)
- B (Boss)
- % (Staircase to the next level)

Player status will be at the right of the level representation all times.
Player can Level up and gain stats.
Thinking of implementing Equipment, Actual Battle, Different enemies.
