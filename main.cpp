#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct shoppingItem
{
    string name;
    int amount;
    double price;
};

void printShoppingList()
{

    // Open the file stream
    ifstream file("shopping-list.txt", ios::in | ios::app);

    // Check if the file was opened successfully
    if (!file.is_open())
    {
        cerr << "Error: Failed to open file!" << endl;
        return;
    }
}

void printTotalPrice() {}

void removeByName()
{
    printf("Please Input Name of Item You Want to Remove\n");
}

void addByName()
{
    fstream file;
    file.open("shopping-list.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error" << endl;
        return;
    }
    string itemName;
    int itemAmount;
    double itemPrice;

    printf("Please Type Name of Item\n");
    cin >> itemName;

    printf("Please Type Amount of Item\n");
    cin >> itemAmount;

    printf("Please Type Price of Item\n");
    cin >> itemPrice;

    file << itemName << " ";
    file << itemAmount << " ";
    file << itemPrice << endl;
}

int main()
{
    char primary_input;

    do
    {
        // print menu
        cout << "*******************************************" << endl;
        cout << "*    Welcome the your Shopping List!      *" << endl;
        cout << "*    Please chose  an option:             *" << endl;
        cout << "*    - l: Lists the whole Shopping List   *" << endl;
        cout << "*    - t: Gets total price of the List    *" << endl;
        cout << "*    - r: Removes item by name            *" << endl;
        cout << "*    - a: Add item into list              *" << endl;
        cout << "*    - q: quit                            *" << endl;
        cout << "*******************************************" << endl;
        // get user input
        cin >> primary_input;

        // choose a branch depending on the input
        switch (primary_input)
        {
        case 'l':
        case 'L':
            printShoppingList();
            break;
        case 't':
        case 'T':
            printTotalPrice();
            break;
        case 'r':
        case 'R':
            removeByName();
            break;
        case 'a':
        case 'A':
            addByName();
            break;
        case 'q':
        case 'Q':
            cout << "Bye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a character from the list" << endl;
            break;
        }

    } while (primary_input != 'q' && primary_input != 'Q');

    return 0;
}