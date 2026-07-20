#include <iostream>
#include <string>

#include "Food.h"
#include "FoodLinkedList.h"
#include "Order.h"
#include "OrderQueue.h"
#include "UndoStack.h"
#include "FoodHashTable.h"

using namespace std;

// ======================================================
// PLACE ORDER
// ======================================================

void placeOrder(
    FoodHashTable &foodTable,
    FoodLinkedList &foodList,
    OrderQueue &orderQueue,
    int orderID,
    int foodID,
    int quantity)
{
    Food *food = foodTable.search(foodID);

    if (food == nullptr)
    {
        cout << "Food not found.\n";
        return;
    }

    if (quantity <= 0)
    {
        cout << "Invalid quantity.\n";
        return;
    }

    if (food->getQuantity() < quantity)
    {
        cout << "Insufficient stock.\n";
        return;
    }

    double total = food->getPrice() * quantity;

    if (foodList.reduceQuantity(foodID, quantity))
    {
        Order newOrder(
            orderID,
            food->getId(),
            food->getName(),
            quantity,
            total);

        orderQueue.enqueue(newOrder);

        cout << "Order placed successfully.\n";
        cout << "Total Bill: $" << total << endl;
    }
    else
    {
        cout << "Unable to update stock.\n";
    }
}

// ======================================================
// ADD FOOD
// ======================================================

void addFoodToSystem(
    FoodLinkedList &foodList,
    FoodHashTable &foodTable,
    Food food)
{
    if (foodList.addFood(food))
    {
        Food *pointer =
            foodList.searchFood(food.getId());

        foodTable.insert(pointer);

        cout << "Food added successfully.\n";
    }
    else
    {
        cout << "Food ID already exists.\n";
    }
}

// ======================================================
// CUSTOMER PANEL
// ======================================================

void customerPanel(
    FoodLinkedList &foodList,
    FoodHashTable &foodTable,
    OrderQueue &orderQueue,
    int &nextOrderID)
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "           CUSTOMER PANEL\n";
        cout << "========================================\n";
        cout << "1. View Food Menu\n";
        cout << "2. Search Food\n";
        cout << "3. Place Order\n";
        cout << "4. View Order Queue\n";
        cout << "0. Back\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n===== FOOD MENU =====\n";

            foodList.displayFoods();

            break;
        }

        case 2:
        {
            int foodID;

            cout << "\nEnter Food ID: ";
            cin >> foodID;

            Food *food =
                foodTable.search(foodID);

            if (food != nullptr)
            {
                cout << "\n===== FOOD FOUND =====\n";
                food->display();
            }
            else
            {
                cout << "Food not found.\n";
            }

            break;
        }

        case 3:
        {
            int foodID;
            int quantity;

            cout << "\nEnter Food ID: ";
            cin >> foodID;

            cout << "Enter Quantity: ";
            cin >> quantity;

            placeOrder(
                foodTable,
                foodList,
                orderQueue,
                nextOrderID,
                foodID,
                quantity);

            // Increment only after a valid attempt.
            // This is acceptable for a simple system.
            nextOrderID++;

            break;
        }

        case 4:
        {
            cout << "\n===== ORDER QUEUE =====\n";

            if (orderQueue.isEmpty())
            {
                cout << "No pending orders.\n";
            }
            else
            {
                orderQueue.displayOrders();

                cout << "\nTotal Orders: "
                     << orderQueue.size()
                     << endl;
            }

            break;
        }

        case 0:
            cout << "Returning to main menu...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ======================================================
// ADMIN PANEL
// ======================================================

void adminPanel(
    FoodLinkedList &foodList,
    FoodHashTable &foodTable,
    UndoStack &undoStack)
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "             ADMIN PANEL\n";
        cout << "========================================\n";
        cout << "1. Add Food\n";
        cout << "2. Delete Food\n";
        cout << "3. Update Food\n";
        cout << "4. Search Food\n";
        cout << "5. Display All Food\n";
        cout << "6. Sort Food\n";
        cout << "7. Undo Last Delete\n";
        cout << "8. Display Statistics\n";
        cout << "0. Back\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            // ==================================================
            // 1. ADD FOOD
            // ==================================================

        case 1:
        {
            int id;
            string name;
            int quantity;
            double price;

            cout << "\nEnter Food ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Food Name: ";
            getline(cin, name);

            cout << "Enter Quantity: ";
            cin >> quantity;

            cout << "Enter Price: ";
            cin >> price;

            Food newFood(
                id,
                name,
                quantity,
                price);

            addFoodToSystem(
                foodList,
                foodTable,
                newFood);

            break;
        }

            // ==================================================
            // 2. DELETE FOOD
            // ==================================================

        case 2:
        {
            int foodID;

            cout << "\nEnter Food ID to delete: ";
            cin >> foodID;

            Food deletedFood(
                0,
                "",
                0,
                0);

            bool listRemoved =
                foodList.removeFood(
                    foodID,
                    deletedFood);

            if (listRemoved)
            {
                // Remove the pointer node from hash table
                foodTable.remove(foodID);

                // Save deleted food for undo
                undoStack.push(deletedFood);

                cout << "Food deleted successfully.\n";
            }
            else
            {
                cout << "Food not found.\n";
            }

            break;
        }

            // ==================================================
            // 3. UPDATE FOOD
            // ==================================================

        case 3:
        {
            int foodID;

            cout << "\nEnter Food ID to update: ";
            cin >> foodID;

            Food *food =
                foodTable.search(foodID);

            if (food == nullptr)
            {
                cout << "Food not found.\n";
                break;
            }

            int newQuantity;
            double newPrice;

            cout << "Current Food:\n";
            food->display();

            cout << "\nEnter New Quantity: ";
            cin >> newQuantity;

            cout << "Enter New Price: ";
            cin >> newPrice;

            food->setQuantity(newQuantity);
            food->setPrice(newPrice);

            cout << "Food updated successfully.\n";

            break;
        }

            // ==================================================
            // 4. SEARCH FOOD
            // ==================================================

        case 4:
        {
            int foodID;

            cout << "\nEnter Food ID: ";
            cin >> foodID;

            Food *food =
                foodTable.search(foodID);

            if (food != nullptr)
            {
                cout << "\n===== FOOD FOUND =====\n";
                food->display();
            }
            else
            {
                cout << "Food not found.\n";
            }

            break;
        }

            // ==================================================
            // 5. DISPLAY ALL FOOD
            // ==================================================

        case 5:
        {
            cout << "\n===== ALL FOOD =====\n";

            foodList.displayFoods();

            break;
        }

            // ==================================================
            // 6. SORT FOOD
            // ==================================================

        case 6:
        {
            int sortChoice;

            do
            {
                cout << "\n========================================\n";
                cout << "              SORT FOOD\n";
                cout << "========================================\n";
                cout << "1. Sort by ID\n";
                cout << "2. Sort by Name\n";
                cout << "3. Sort by Price\n";
                cout << "4. Sort by Quantity\n";
                cout << "0. Back\n";
                cout << "========================================\n";

                cout << "Enter your choice: ";
                cin >> sortChoice;

                switch (sortChoice)
                {
                case 1:

                    foodList.sortByID();

                    cout << "\nFood sorted by ID successfully.\n";

                    foodList.displayFoods();

                    break;

                case 2:

                    foodList.sortByName();

                    cout << "\nFood sorted by Name successfully.\n";

                    foodList.displayFoods();

                    break;

                case 3:

                    foodList.sortByPrice();

                    cout << "\nFood sorted by Price successfully.\n";

                    foodList.displayFoods();

                    break;

                case 4:

                    foodList.sortByQuantity();

                    cout << "\nFood sorted by Quantity successfully.\n";

                    foodList.displayFoods();

                    break;

                case 0:

                    cout << "Returning to Admin Panel...\n";

                    break;

                default:

                    cout << "Invalid choice.\n";
                }

            } while (sortChoice != 0);

            break;
        }

            // ==================================================
            // 7. UNDO LAST DELETE
            // ==================================================

        case 7:
        {
            cout << "\n===== UNDO LAST DELETE =====\n";

            Food *restoredFood =
                undoStack.pop();

            if (restoredFood == nullptr)
            {
                cout << "Nothing to undo.\n";
                break;
            }

            int restoredID =
                restoredFood->getId();

            bool restored =
                foodList.addFood(*restoredFood);

            if (restored)
            {
                Food *restoredPointer =
                    foodList.searchFood(restoredID);

                foodTable.insert(restoredPointer);

                cout << "Food restored successfully.\n";
            }
            else
            {
                cout << "Food could not be restored.\n";
            }

            delete restoredFood;

            break;
        }

            // ==================================================
            // 8. DISPLAY STATISTICS
            // ==================================================

        case 8:
        {
            cout << "\n===== DATA STRUCTURE STATISTICS =====\n";

            cout << "Total Food Items: "
                 << foodList.countFoods()
                 << endl;

            cout << "Hash Table Size: 10"
                 << endl;

            cout << "Hash Function: ID % 10"
                 << endl;

            break;
        }

        case 0:
            cout << "Returning to main menu...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ======================================================
// PROCESS ORDERS
// ======================================================

void processOrders(
    OrderQueue &orderQueue)
{
    cout << "\n===== PROCESS ORDERS =====\n";

    if (orderQueue.isEmpty())
    {
        cout << "No pending orders.\n";
        return;
    }

    while (!orderQueue.isEmpty())
    {
        Order *nextOrder =
            orderQueue.peek();

        if (nextOrder != nullptr)
        {
            cout << "\nProcessing Order:\n";
            nextOrder->display();
        }

        orderQueue.dequeue();

        cout << "Order processed successfully.\n";
    }

    cout << "\nAll orders processed.\n";
}

// ======================================================
// DISPLAY STATISTICS
// ======================================================

void displayStatistics(
    FoodLinkedList &foodList,
    FoodHashTable &foodTable,
    OrderQueue &orderQueue)
{
    cout << "\n========================================\n";
    cout << "       DATA STRUCTURE STATISTICS\n";
    cout << "========================================\n";

    cout << "Total Food Items: "
         << foodList.countFoods()
         << endl;

    cout << "Pending Orders: "
         << orderQueue.size()
         << endl;

    cout << "Hash Table Size: 10"
         << endl;

    cout << "Hash Function: ID % 10"
         << endl;

    cout << "\nHash Table Contents:\n";

    foodTable.display();
}

// ======================================================
// MAIN MENU
// ======================================================

void displayMainMenu()
{
    cout << "\n========================================\n";
    cout << "     RESTAURANT MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Customer Panel\n";
    cout << "2. Admin Panel\n";
    cout << "3. Process Orders\n";
    cout << "4. Search Food\n";
    cout << "5. Undo Last Delete\n";
    cout << "6. Display Data Structure Statistics\n";
    cout << "7. Save Data\n";
    cout << "0. Exit\n";
    cout << "========================================\n";
}

// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    FoodLinkedList foodList;
    OrderQueue orderQueue;
    UndoStack undoStack;
    FoodHashTable foodTable;

    int nextOrderID = 1;

    // ==================================================
    // LOAD DATA
    // ==================================================

    if (foodList.loadFromFile("food_data.txt"))
    {
        cout << "Food data loaded successfully.\n";

        foodList.buildHashTable(foodTable);

        cout << "Hash table built successfully.\n";
    }
    else
    {
        cout << "Failed to load food data.\n";
    }

    int choice;

    do
    {
        displayMainMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            // ==================================================
            // 1. CUSTOMER PANEL
            // ==================================================

        case 1:
        {
            customerPanel(
                foodList,
                foodTable,
                orderQueue,
                nextOrderID);

            break;
        }

            // ==================================================
            // 2. ADMIN PANEL
            // ==================================================

        case 2:
        {
            adminPanel(
                foodList,
                foodTable,
                undoStack);

            break;
        }

            // ==================================================
            // 3. PROCESS ORDERS
            // ==================================================

        case 3:
        {
            processOrders(orderQueue);

            break;
        }

            // ==================================================
            // 4. SEARCH FOOD
            // ==================================================

        case 4:
        {
            int foodID;

            cout << "\nEnter Food ID: ";
            cin >> foodID;

            Food *food =
                foodTable.search(foodID);

            if (food != nullptr)
            {
                cout << "\n===== FOOD FOUND =====\n";
                food->display();
            }
            else
            {
                cout << "Food not found.\n";
            }

            break;
        }

            // ==================================================
            // 5. UNDO LAST DELETE
            // ==================================================

        case 5:
        {
            cout << "\n===== UNDO LAST DELETE =====\n";

            Food *restoredFood =
                undoStack.pop();

            if (restoredFood == nullptr)
            {
                cout << "Nothing to undo.\n";
                break;
            }

            int restoredID =
                restoredFood->getId();

            if (foodList.addFood(*restoredFood))
            {
                Food *restoredPointer =
                    foodList.searchFood(restoredID);

                foodTable.insert(restoredPointer);

                cout << "Food restored successfully.\n";
            }
            else
            {
                cout << "Food could not be restored.\n";
            }

            delete restoredFood;

            break;
        }

            // ==================================================
            // 6. STATISTICS
            // ==================================================

        case 6:
        {
            displayStatistics(
                foodList,
                foodTable,
                orderQueue);

            break;
        }

            // ==================================================
            // 7. SAVE DATA
            // ==================================================

        case 7:
        {
            if (foodList.saveToFile(
                    "food_data.txt"))
            {
                cout << "Food data saved successfully.\n";
            }
            else
            {
                cout << "Failed to save food data.\n";
            }

            break;
        }

            // ==================================================
            // 0. EXIT
            // ==================================================

        case 0:
        {
            cout << "\nSaving data before exit...\n";

            if (foodList.saveToFile(
                    "food_data.txt"))
            {
                cout << "Food data saved successfully.\n";
            }

            cout << "Thank you for using the system.\n";

            break;
        }

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}