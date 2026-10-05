#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Each node represents one property
struct Node {
    string name;
    int cost;
    string owner;
    Node* next;

    Node(string n, int c) {
        name = n;
        cost = c;
        owner = "None";
        next = nullptr;
    }
};

//Circular linked list
class LinkedList {
private:
    Node* first;
    Node* last;

public:
    LinkedList() {
        first = nullptr;
        last = nullptr;
    }

    //Add a property
    void add(string name, int cost) {
        Node* newNode = new Node(name, cost);

        if (first == nullptr) {
            first = newNode;
            last = newNode;
            last->next = first;
        }
        else {
            last->next = newNode;
            last = newNode;
            last->next = first;
        }
    }

    //Search for a property
    Node* search(string name) {
        if (first == nullptr)
            return nullptr;

        Node* current = first;

        do {
            if (current->name == name)
                return current;

            current = current->next;
        } while (current != first);

        return nullptr;
    }

    //Remove a property
    bool remove(string name) {
        if (first == nullptr)
            return false;

        Node* current = first;
        Node* previous = last;

        do {
            if (current->name == name) {

                //Only one node
                if (current == first && current == last) {
                    delete current;
                    first = nullptr;
                    last = nullptr;
                    return true;
                }

                //Removing first node
                if (current == first) {
                    first = first->next;
                    last->next = first;
                }
                else {
                    previous->next = current->next;

                    if (current == last)
                        last = previous;
                }

                delete current;
                return true;
            }

            previous = current;
            current = current->next;

        } while (current != first);

        return false;
    }

    //Print all properties
    void print() {
        if (first == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        Node* current = first;

        do {
            cout << current->name
                << " | Cost: $" << current->cost
                << " | Owner: " << current->owner << endl;

            current = current->next;

        } while (current != first);
    }

    Node* getFirst() {
        return first;
    }

    //Delete the circular list
    void clear() {
        if (first == nullptr)
            return;

        Node* current = first;

        for (int i = 0; i < 10; i++) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        first = nullptr;
        last = nullptr;
    }
};

//Player information
struct Player {
    string name;
    int money;
    Node* position;
};

//Move around the circular board
void movePlayer(Player& player, int spaces) {
    for (int i = 0; i < spaces; i++)
        player.position = player.position->next;
}

//Try to buy the property
void buyProperty(Player& player) {
    Node* property = player.position;

    if (property->owner != "None") {
        cout << property->name << " is already owned by "
            << property->owner << ".\n";
    }
    else if (player.money >= property->cost) {
        player.money -= property->cost;
        property->owner = player.name;

        cout << player.name << " bought "
            << property->name << " for $"
            << property->cost << ".\n";
    }
    else {
        cout << player.name << " cannot afford "
            << property->name << ".\n";
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    //Part 1

    LinkedList board;

    //Create 10 properties
    board.add("Boardwalk", 400);
    board.add("Park Place", 350);
    board.add("Pennsylvania Ave", 320);
    board.add("North Carolina Ave", 300);
    board.add("Pacific Ave", 300);
    board.add("Marvin Gardens", 280);
    board.add("Ventnor Ave", 260);
    board.add("Water Works", 150);
    board.add("Tennessee Ave", 180);
    board.add("New York Ave", 200);

    cout << "===== LINKED LIST TEST =====\n";

    cout << "\nAll properties:\n";
    board.print();

    cout << "\nSearching for Park Place...\n";

    if (board.search("Park Place") != nullptr)
        cout << "Park Place was found!\n";
    else
        cout << "Park Place was not found.\n";

    //Test removing an item
    cout << "\nRemoving New York Ave...\n";

    if (board.remove("New York Ave"))
        cout << "New York Ave was removed.\n";
    else
        cout << "Property was not found.\n";

    //Add it back so the Monopoly board still has 10 properties
    board.add("New York Ave", 200);

    //Part 2

    cout << "\n===== MONOPOLY GAME =====\n";

    Player player1 = {
        "Player 1",
        1500,
        board.getFirst()
    };

    Player player2 = {
        "Player 2",
        1500,
        board.getFirst()
    };

    //Simulate 10 turns
    for (int turn = 1; turn <= 10; turn++) {

        Player& player =
            (turn % 2 == 1) ? player1 : player2;

        int dice = rand() % 6 + 1;

        cout << "\nTurn " << turn << endl;
        cout << player.name << " rolled " << dice << ".\n";

        movePlayer(player, dice);

        cout << player.name << " landed on "
            << player.position->name << ".\n";

        buyProperty(player);

        cout << player.name << " has $"
            << player.money << " remaining.\n";
    }

    //Final Results

    cout << "\nFINAL RESULTS\n";

    cout << "Player 1 money: $" << player1.money << endl;
    cout << "Player 2 money: $" << player2.money << endl;

    cout << "\nProperties:\n";
    board.print();

    // Clean up 
    board.clear();

    return 0;
}

