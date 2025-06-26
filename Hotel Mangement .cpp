#include <iostream>
#include <vector>

using namespace std;

class Room {
public:
    int roomNumber;
    bool isBooked;
    string guestName;

    Room(int number) {
        roomNumber = number;
        isBooked = false;
        guestName = "";
    }

    void bookRoom(string name) {
        if (!isBooked) {
            isBooked = true;
            guestName = name;
            cout << "Room " << roomNumber << " booked successfully for " << guestName << ".\n";
        } else {
            cout << "Room " << roomNumber << " is already booked by " << guestName << ".\n";
        }
    }

    void cancelBooking() {
        if (isBooked) {
            cout << "Booking for room " << roomNumber << " (Guest: " << guestName << ") has been canceled.\n";
            isBooked = false;
            guestName = "";
        } else {
            cout << "Room " << roomNumber << " is not booked yet.\n";
        }
    }

    void checkStatus() {
        if (isBooked) {
            cout << "Room " << roomNumber << " is booked by " << guestName << ".\n";
        } else {
            cout << "Room " << roomNumber << " is available.\n";
        }
    }
};

vector<Room> hotelRooms;

void initializeRooms(int totalRooms) {
    for (int i = 1; i <= totalRooms; i++) {
        hotelRooms.push_back(Room(i));
    }
}

void displayRooms() {
    cout << "\n--- Available Rooms ---\n";
    for (auto &room : hotelRooms) {
        cout << "Room " << room.roomNumber << ": " << (room.isBooked ? "Booked" : "Available") << "\n";
    }
}

void bookRoom() {
    int roomNumber;
    string guestName;
    
    cout << "Enter room number to book: ";
    cin >> roomNumber;
    cin.ignore();
    cout << "Enter guest name: ";
    getline(cin, guestName);

    if (roomNumber > 0 && roomNumber <= hotelRooms.size()) {
        hotelRooms[roomNumber - 1].bookRoom(guestName);
    } else {
        cout << "Invalid room number!\n";
    }
}

void cancelRoom() {
    int roomNumber;
    cout << "Enter room number to cancel booking: ";
    cin >> roomNumber;

    if (roomNumber > 0 && roomNumber <= hotelRooms.size()) {
        hotelRooms[roomNumber - 1].cancelBooking();
    } else {
        cout << "Invalid room number!\n";
    }
}

void checkRoomStatus() {
    int roomNumber;
    cout << "Enter room number to check status: ";
    cin >> roomNumber;

    if (roomNumber > 0 && roomNumber <= hotelRooms.size()) {
        hotelRooms[roomNumber - 1].checkStatus();
    } else {
        cout << "Invalid room number!\n";
    }
}

int main() {
    int totalRooms = 5; // You can change the number of rooms
    initializeRooms(totalRooms);

    int choice;
    do {
        cout << "\n--- Hotel Reservation System ---\n";
        cout << "1. View Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Check Room Status\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                cancelRoom();
                break;
            case 4:
                checkRoomStatus();
                break;
            case 5:
                cout << "Thank you for using the Hotel Reservation System!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

