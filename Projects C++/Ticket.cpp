#include <iostream>
#include <string>
using namespace std;

// ===== Ticket System Class =====
class TicketSystem
{
public:
    bool seats[10];       
    string bookedBy[10];  

    TicketSystem()
    {
        for(int i=0;i<10;i++)
        {
            seats[i] = false;
            bookedBy[i] = "";
        }
    }

    void viewSeats()
    {
        cout << "\n--- Seat Status ---\n";
        for(int i=0;i<10;i++)
        {
            if(seats[i])
                cout << "Seat " << i+1 << " - Booked by " << bookedBy[i] << endl;
            else
                cout << "Seat " << i+1 << " - Available" << endl;
        }
    }
};

// ===== User Class =====
class User
{
private:
    string username;
    string password;
    string name;

public:
    void registerUser()
    {
        cout << "\n--- User Registration ---\n";
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Registration Successful!\n";
    }

    bool loginUser()
    {
        string u, p;
        cout << "\n--- User Login ---\n";
        cout << "Enter Username: ";
        cin >> u;
        cout << "Enter Password: ";
        cin >> p;

        if(u==username && p==password)
        {
            cout << "Login Successful!\n";
            return true;
        }
        else
        {
            cout << "Wrong Username or Password!\n";
            return false;
        }
    }

    void userMenu(TicketSystem &system)
    {
        int choice;
        do
        {
            cout << "\n--- User Menu ---\n";
            cout << "1. View Seats\n";
            cout << "2. Book Ticket\n";
            cout << "3. Cancel Ticket\n";
            cout << "4. View My Tickets\n";
            cout << "5. Change Password\n";
            cout << "6. Logout\n";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    system.viewSeats();
                    break;

                case 2:
                    bookTicket(system);
                    break;

                case 3:
                    cancelTicket(system);
                    break;

                case 4:
                    viewMyTickets(system);
                    break;

                case 5:
                    changePassword();
                    break;

                case 6:
                    cout << "Logging out...\n";
                    break;

                default:
                    cout << "Invalid choice!\n";
            }

        }while(choice != 6);
    }

    void bookTicket(TicketSystem &system)
    {
        int s;
        cout << "Enter Seat Number (1-10) to Book: ";
        cin >> s;

        if(s<1 || s>10)
        {
            cout << "Invalid Seat Number!\n";
            return;
        }

        if(system.seats[s-1])
        {
            cout << "Seat Already Booked!\n";
        }
        else
        {
            system.seats[s-1] = true;
            system.bookedBy[s-1] = name;
            cout << "Ticket Booked Successfully!\n";
        }
    }

    void cancelTicket(TicketSystem &system)
    {
        int s;
        cout << "Enter Seat Number (1-10) to Cancel: ";
        cin >> s;

        if(s<1 || s>10)
        {
            cout << "Invalid Seat Number!\n";
            return;
        }

        if(system.seats[s-1] && system.bookedBy[s-1]==name)
        {
            system.seats[s-1] = false;
            system.bookedBy[s-1] = "";
            cout << "Your Ticket Cancelled Successfully!\n";
        }
        else
        {
            cout << "You cannot cancel this seat!\n";
        }
    }

    void viewMyTickets(TicketSystem &system)
    {
        cout << "\n--- My Tickets ---\n";
        bool hasTicket = false;

        for(int i=0;i<10;i++)
        {
            if(system.seats[i] && system.bookedBy[i]==name)
            {
                cout << "Seat " << i+1 << " - Booked by you\n";
                hasTicket = true;
            }
        }

        if(!hasTicket)
            cout << "No Tickets Booked.\n";
    }

    void changePassword()
    {
        string oldPass, newPass;
        cout << "Enter Old Password: ";
        cin >> oldPass;

        if(oldPass==password)
        {
            cout << "Enter New Password: ";
            cin >> newPass;
            password = newPass;
            cout << "Password Changed Successfully!\n";
        }
        else
        {
            cout << "Incorrect Old Password!\n";
        }
    }
};

// ===== Admin Class =====
class Admin
{
private:
    string adminUsername = "admin";
    string adminPassword = "1234";

public:
    bool adminLogin()
    {
        string u, p;
        cout << "\n--- Admin Login ---\n";
        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;

        if(u==adminUsername && p==adminPassword)
        {
            cout << "Admin Login Successful!\n";
            return true;
        }
        else
        {
            cout << "Wrong Admin Credentials!\n";
            return false;
        }
    }

    void adminMenu(TicketSystem &system)
    {
        int choice;
        do
        {
            cout << "\n--- Admin Menu ---\n";
            cout << "1. View All Seats\n";
            cout << "2. Cancel Any Booking\n";
            cout << "3. Search Booking\n";
            cout << "4. Logout\n";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    system.viewSeats();
                    break;

                case 2:
                    cancelAnyBooking(system);
                    break;

                case 3:
                    searchBooking(system);
                    break;

                case 4:
                    cout << "Logging out...\n";
                    break;

                default:
                    cout << "Invalid choice!\n";
            }

        }while(choice != 4);
    }

    void cancelAnyBooking(TicketSystem &system)
    {
        int s;
        cout << "Enter Seat Number (1-10) to Cancel: ";
        cin >> s;

        if(s<1 || s>10)
        {
            cout << "Invalid Seat Number!\n";
            return;
        }

        if(system.seats[s-1])
        {
            system.seats[s-1] = false;
            system.bookedBy[s-1] = "";
            cout << "Booking Cancelled Successfully!\n";
        }
        else
        {
            cout << "Seat is Already Available!\n";
        }
    }

    void searchBooking(TicketSystem &system)
    {
        int s;
        cout << "Enter Seat Number (1-10) to Search: ";
        cin >> s;

        if(s<1 || s>10)
        {
            cout << "Invalid Seat Number!\n";
            return;
        }

        if(system.seats[s-1])
            cout << "Seat Booked by: " << system.bookedBy[s-1] << endl;
        else
            cout << "Seat is Available.\n";
    }
};

// ===== Main Function =====
int main()
{
    TicketSystem system;  
    User user;
    Admin admin;

    int choice;

    do
    {
        cout << "\n--- Ticket Reservation System ---\n";
        cout << "1. User Register\n";
        cout << "2. User Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                user.registerUser();
                break;

            case 2:
                if(user.loginUser())
                    user.userMenu(system);
                break;

            case 3:
                if(admin.adminLogin())
                    admin.adminMenu(system);
                break;

            case 4:
                cout << "Exiting System...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    }while(choice != 4);

    return 0;
}
