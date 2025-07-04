#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Medicine Class
class Medicine {
private:
    int id;
    string name;
    int salesPrice;
    int quantity;
    int purchasePrice;

public:
    Medicine(int id, const string& name, int salesPrice, int purchasePrice)
        : id(id), name(name), salesPrice(salesPrice), purchasePrice(purchasePrice), quantity(0) {}

    void setId(int id) { this->id = id; }
    int getId() const { return id; }

    void setName(const string& name) { this->name = name; }
    string getName() const { return name; }

    void setSalesPrice(int price) { salesPrice = price; }
    int getSalesPrice() const { return salesPrice; }

    void setPurchasePrice(int price) { purchasePrice = price; }
    int getPurchasePrice() const { return purchasePrice; }

    void setQuantity(int qty) { quantity = qty; }
    int getQuantity() const { return quantity; }

    void display() const {
        cout << "Id: " << id << endl;
        cout << "Medicine Name: " << name << endl;
        cout << "Sales Price: " << salesPrice << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

// Inventory Class
class Inventory {
private:
    vector<Medicine> medicines;

public:
    void addMedicine(const Medicine& med, int qty) {
        for (size_t i = 0; i < medicines.size(); ++i) {
            if (medicines[i].getId() == med.getId()) {
                medicines[i].setQuantity(medicines[i].getQuantity() + qty);
                return;
            }
        }
        Medicine newMed = med;
        newMed.setQuantity(qty);
        medicines.push_back(newMed);
    }

    void removeMedicine(int id) {
        for (size_t i = 0; i < medicines.size(); ++i) {
            if (medicines[i].getId() == id) {
                medicines.erase(medicines.begin() + i);
                cout << "Medicine removed." << endl;
                return;
            }
        }
        cout << "Medicine not found!" << endl;
    }

    void updateMedicine(int id) {
        for (size_t i = 0; i < medicines.size(); ++i) {
            if (medicines[i].getId() == id) {
                medicines[i].display();
                cout << "What do you want to update?" << endl;
                cout << "1. Id\n2. Name\n3. Sales Price\n4. Purchase Price" << endl;
                int choice;
                cin >> choice;

                if (choice == 1) {
                    int newId;
                    cout << "Enter new id: ";
                    cin >> newId;
                    medicines[i].setId(newId);
                    cout << "Id updated." << endl;
                } else if (choice == 2) {
                    string newName;
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, newName);
                    medicines[i].setName(newName);
                    cout << "Name updated." << endl;
                } else if (choice == 3) {
                    int newPrice;
                    cout << "Enter new sales price: ";
                    cin >> newPrice;
                    medicines[i].setSalesPrice(newPrice);
                    cout << "Sales price updated." << endl;
                } else if (choice == 4) {
                    int newPrice;
                    cout << "Enter new purchase price: ";
                    cin >> newPrice;
                    medicines[i].setPurchasePrice(newPrice);
                    cout << "Purchase price updated." << endl;
                } else {
                    cout << "Invalid choice!" << endl;
                }
                return;
            }
        }
        cout << "Medicine not found!" << endl;
    }

    void display() const {
        for (size_t i = 0; i < medicines.size(); ++i) {
            medicines[i].display();
            cout << "---------------------" << endl;
        }
    }
};

// Main Function
int main() {
    Inventory inventory;

    Medicine m1(1, "Panadol", 30, 20);
    Medicine m2(2, "Xiga-5mg", 300, 210);
    Medicine m3(3, "Xyster", 230, 160);

    inventory.addMedicine(m1, 20);
    inventory.addMedicine(m2, 15);
    inventory.addMedicine(m3, 10);

    char choice;
    while (true) {
        cout << "1. Display Inventory\n2. Update Medicine\n3. Remove Medicine\n0. Exit" << endl;
        cin >> choice;

        if (choice == '1') {
            inventory.display();
        } else if (choice == '2') {
            int id;
            cout << "Enter Medicine ID to update: ";
            cin >> id;
            inventory.updateMedicine(id);
        } else if (choice == '3') {
            int id;
            cout << "Enter Medicine ID to remove: ";
            cin >> id;
            inventory.removeMedicine(id);
        } else if (choice == '0') {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
