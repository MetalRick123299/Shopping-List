#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct item
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

void removeByName(string userInput)
{
}

void addByName(string userInput)
{
}

void getInput(string text, string &userInput)
{
    cout << text << endl;
    cin >> userInput;
}

int main()
{

    char primary_input;

    string secondary_input;

    string inputStr;

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
            inputStr = "Please Input Name of Item You Want to Remove";
            getInput(inputStr, secondary_input);
            removeByName(secondary_input);
            break;
        case 'a':
        case 'A':
            inputStr = "Please Input Name of Item You Want to Add";
            getInput(inputStr, secondary_input);
            addByName(secondary_input);
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