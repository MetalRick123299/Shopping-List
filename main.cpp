#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct shoppingItem
{
    string name;
    int amount;
    double price;
};

bool updateTxtFile(vector<shoppingItem> &shoppingList)
{
    if (shoppingList.size() == 0)
        return true;

    fstream file;
    file.open("shopping-list.txt", ios::out | ios::binary);

    if (!file.is_open())
        return false;

    for (int i = 0; i < shoppingList.size(); i++)
    {
        shoppingItem curr = shoppingList.at(i);

        // cout << curr.name << "\n";
        // cout << curr.amount << "\n";
        // cout << curr.price << "\n";

        file << curr.name << " ";
        file << curr.amount << " ";
        file << curr.price << endl;
    }

    file.close();

    return true;
}

void getShoppingList(vector<shoppingItem> &shoppingList)
{
    fstream file;
    file.open("shopping-list.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Your Shopping List is empty" << endl;
        return;
    }

    string itemName;
    int itemAmount;
    double itemPrice;

    while (!file.eof())
    {
        file >> itemName;
        file >> itemAmount;
        file >> itemPrice;

        shoppingList.push_back({itemName, itemAmount, itemPrice});
    }

    shoppingList.pop_back();

    file.close();
    cout << "Shopping List has been imported" << endl;
}

void printShoppingList(vector<shoppingItem> shoppingList)
{
    if (shoppingList.size() == 0)
    {
        printf("Shopping List is Empty\n");
        return;
    }

    for (int i = 0; i < shoppingList.size(); i++)
    {
        shoppingItem current = shoppingList.at(i);

        cout << current.amount << " " << current.name << " for $" << current.price << " each." << endl;
    }
}

void printTotalPrice(vector<shoppingItem> &shoppingList) {}

void removeByName(vector<shoppingItem> &shoppingList)
{
    string input;
    bool inVector = false;
    int i;

    if (shoppingList.size() == 0)
    {
        printf("Shopping List is Empty\n");
        return;
    }

    do
    {
        printf("Please Input Item You Want To Remove\n");
        printf("Or q to Quit back to Main Menu\n");
        cin >> input;

        for (i = 0; i < shoppingList.size(); i++)
        {
            shoppingItem curr = shoppingList.at(i);
            if (curr.name == input)
            {
                inVector = true;
                break;
            }
        }
        if (!inVector)
        {
            cout << endl
                 << "Item isn't in List" << endl;
            cout << "Please Try Again" << endl;
            cout << endl;
        }

    } while (!inVector && input != "q" && input != "Q");
    if (input == "q" || input == "Q")
    {
        cout << "Returning to Main Menu..." << endl;
        return;
    }

    shoppingList.erase(shoppingList.begin() + i);

    if (!updateTxtFile(shoppingList))
    {
        printf("Error: unable to delete item\nTry Again");
    }
}

void addByName(vector<shoppingItem> &shoppingList)
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

    file.close();

    shoppingList.push_back({itemName, itemAmount, itemPrice});
}

int main()
{
    char primary_input;

    vector<shoppingItem> shoppingList;
    getShoppingList(shoppingList);

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
        cout << endl;

        // choose a branch depending on the input
        switch (primary_input)
        {
        case 'l':
        case 'L':
            printShoppingList(shoppingList);
            break;
        case 't':
        case 'T':
            printTotalPrice(shoppingList);
            break;
        case 'r':
        case 'R':
            removeByName(shoppingList);
            break;
        case 'a':
        case 'A':
            addByName(shoppingList);
            break;
        case 'q':
        case 'Q':
            updateTxtFile(shoppingList);
            cout << "Bye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a character from the list" << endl;
            break;
        }

    } while (primary_input != 'q' && primary_input != 'Q');

    return 0;
}