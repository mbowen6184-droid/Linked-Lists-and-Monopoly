Part 1: Linked List

I created my own linked list that supports:

- Adding properties
- Searching for properties
- Removing properties
- Printing all properties

Each node contains:
- The property name
- The property cost
- The property owner
- A pointer to the next node

Part 2: Monopoly Game

The linked list is used to create a circular Monopoly board with 10 properties.

The board is circular, which means the last property points back to the first property. This allows players to move around the board and automatically wrap back to the beginning.

The game has two players. Each player:

1. Starts with $1500.
2. Rolls a random number from 1 to 6.
3. Moves that many spaces around the board.
4. Buys the property if it is unowned and the player has enough money.
5. Cannot buy a property that already belongs to another player.

The program simulates 10 turns and then displays the final amount of money for each player and the owner of each property.


How to compile and run Using Visual Studio:

	Open the "Linked Lists and Monopoly" project in Visual Studio.
	Open "Source.cpp"
	Build the project by selecting:

	Build → Build Solution

	If the build is successful, run the program without debugging by selecting:

    Debug → Start Without Debugging
 
	A console window will open and display the linked list tests and the Monopoly game results.

What the Program Tests

The program first tests the linked list by:

- Printing all properties
- Searching for "Park Place"
- Removing "New York Ave"
- Adding "New York Ave" back to the list

It then runs the Monopoly game for 10 turns.