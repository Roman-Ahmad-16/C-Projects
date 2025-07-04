#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to store item details
struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

// Global vector to store inventory items
vector<Item> inventory;

// Function to display all items in the inventory
void displayInventory() {
    if (inventory.empty()) {
        cout << "?? Inventory is empty!\n";
        return;
    }

    cout << "\n?? Inventory List:\n";
    cout << "-------------------------------------------------\n";
    cout << setw(5) << "ID" << setw(15) << "Name" << setw(10) << "Quantity" << setw(10) << "Price" << "\n";
    cout << "-------------------------------------------------\n";

    for (size_t i = 0; i < inventory.size(); i++) {  
        cout << setw(5) << inventory[i].id 
             << setw(15) << inventory[i].name 
             << setw(10) << inventory[i].quantity 
             << setw(10) << fixed << setprecision(2) << inventory[i].price << "\n";
    }
    cout << "-------------------------------------------------\n";
}

// Function to add a new item to the inventory
void addItem() {
    Item newItem;
    cout << "Enter Item ID: ";
    cin >> newItem.id;
    cout << "Enter Item Name: ";
    cin.ignore();
    getline(cin, newItem.name);
    cout << "Enter Quantity: ";
    cin >> newItem.quantity;
    cout << "Enter Price: ";
    cin >> newItem.price;

    inventory.push_back(newItem);
    cout << "? Item added successfully!\n";
}

// Function to search for an item by ID
void searchItem() {
    int searchID;
    cout << "Enter Item ID to search: ";
    cin >> searchID;

    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i].id == searchID) {
            cout << "?? Item Found!\n";
            cout << "ID: " << inventory[i].id << "\nName: " << inventory[i].name
                 << "\nQuantity: " << inventory[i].quantity << "\nPrice: " << inventory[i].price << "\n";
            return;
        }
    }
    cout << "? Item not found!\n";
}

// Function to update the quantity and price of an item
void updateItem() {
    int updateID;
    cout << "Enter Item ID to update: ";
    cin >> updateID;

    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i].id == updateID) {
            cout << "Enter new Quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter new Price: ";
            cin >> inventory[i].price;
            cout << "? Item updated successfully!\n";
            return;
        }
    }
    cout << "? Item not found!\n";
}

// Function to delete an item from the inventory
void deleteItem() {
    int deleteID;
    cout << "Enter Item ID to delete: ";
    cin >> deleteID;

    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i].id == deleteID) {
            inventory.erase(inventory.begin() + i);
            cout << "??? Item deleted successfully!\n";
            return;
        }
    }
    cout << "? Item not found!\n";
}

// Function to display the menu
void displayMenu() {
    cout << "\nInventory Management System\n";
    cout << "1. Add Item\n";
    cout << "2. View Inventory\n";
    cout << "3. Search Item\n";
    cout << "4. Update Item\n";
    cout << "5. Delete Item\n";
    cout << "6. Exit\n";
}

// Main function
int main() {
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                cout << "?? Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "?? Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

