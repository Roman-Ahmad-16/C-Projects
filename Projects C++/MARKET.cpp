#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>
using namespace std;

/* ---------- PRODUCT CLASS (ENCAPSULATION) ---------- */
class Product
{
private:
    int code;
    string name;
    float price;
    float discount;
    int stock;

public:
    Product()
    {
        code = 0;
        price = 0;
        discount = 0;
        stock = 0;
    }

    void setData(int c, string n, float p, float d, int s)
    {
        code = c;
        name = n;
        price = p;
        discount = d;
        stock = s;
    }

    int getCode()
    {
        return code;
    }
    string getName()
    {
        return name;
    }
    float getPrice()
    {
        return price;
    }
    float getDiscount()
    {
        return discount;
    }
    int getStock()
    {
        return stock;
    }

    void reduceStock(int q)
    {
        stock -= q;
    }

    void display()
    {
        cout << code << " " << name << " " << price << " " << discount << "% " << stock << "\n";
    }

    string fileFormat()
    {
        stringstream ss;
        ss << code << " "
           << name << " "
           << price << " "
           << discount << " "
           << stock;
        return ss.str();
    }
};

/* ---------- SALES (STATIC) ---------- */
class Sales
{
public:
    static float total;
};
float Sales::total = 0;

/* ---------- FILE MANAGER ---------- */
class FileManager
{
public:
    static void save(vector<Product> &list)
    {
        ofstream f("database.txt");
        for (int i = 0; i < list.size(); i++)
        {
            f << list[i].getCode() << " "
              << list[i].getName() << " "
              << list[i].getPrice() << " "
              << list[i].getDiscount() << " "
              << list[i].getStock() << "\n";
        }
        f.close();
    }

    static void load(vector<Product> &list)
    {
        list.clear();
        ifstream f("database.txt");
        int c, s;
        float p, d;
        string n;
        while (f >> c >> n >> p >> d >> s)
        {
            Product x;
            x.setData(c, n, p, d, s);
            list.push_back(x);
        }
        f.close();
    }
};

/* ---------- ABSTRACT USER ---------- */
class User
{
public:
    virtual void menu() = 0;
};

/* ---------- RECEIPT (COMPOSITION) ---------- */
class Receipt
{
public:
    static float calc(float price, int q, float d)
    {
        float amt = price * q;
        return amt - (amt * d / 100);
    }
};

/* ---------- ADMIN ---------- */
class Admin : public User
{
private:
    vector<Product> products;

public:
    bool login()
    {
        string e, p, ee, pp;
        cout << "Email: ";
        cin >> e;
        cout << "Pass: ";
        cin >> p;
        ifstream f("admin.txt");
        while (f >> ee >> pp)
        {
            if (e == ee && p == pp)
                return true;
        }
        return false;
    }

    void add()
    {
        FileManager::load(products);
        int c, s;
        float p, d;
        string n;

        cout << "Code: ";
        cin >> c;
        for (int i = 0; i < products.size(); i++)
            if (products[i].getCode() == c)
            {
                cout << "Duplicate\n";
                return;
            }

        cout << "Name: ";
        cin >> n;
        cout << "Price: ";
        cin >> p;
        cout << "Discount %: ";
        cin >> d;
        cout << "Stock: ";
        cin >> s;

        Product x;
        x.setData(c, n, p, d, s);
        products.push_back(x);
        FileManager::save(products);
        cout << "Product Added\n";
    }

    void list()
    {
        FileManager::load(products);
        cout << "\nCode Name Price Disc Stock\n";
        for (int i = 0; i < products.size(); i++)
            products[i].display();
    }

    void report()
    {
        ifstream f("sales.txt");
        float x, t = 0;
        while (f >> x)
            t += x;
        cout << "Total Sales: " << t << "\n";
    }

    void menu()
    {
        while (true)
        {
            int ch;
            cout << "\nADMIN MENU\n1 Add Product\n2 List Products\n3 Report\n4 Back\nChoice: ";
            cin >> ch;
            if (ch == 1)
                add();
            else if (ch == 2)
                list();
            else if (ch == 3)
                report();
            else
                break;
        }
    }
};

/* ---------- BUYER ---------- */
class Buyer : public User
{
private:
    vector<Product> products;

public:
    void buy()
    {
        FileManager::load(products);

        int code, qty;
        cout << "Enter Product Code: ";
        cin >> code;
        cout << "Quantity: ";
        cin >> qty;

        float total = 0;

        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getCode() == code)
            {
                if (products[i].getStock() < qty)
                {
                    cout << "Out of Stock\n";
                    return;
                }
                float amt = Receipt::calc(
                    products[i].getPrice(),
                    qty,
                    products[i].getDiscount());
                products[i].reduceStock(qty);
                total += amt;
                break;
            }
        }

        float tax = total * 0.05;
        total += tax;

        time_t now = time(0);
        cout << "Date: " << ctime(&now);
        cout << "Total Amount (Including 5% Tax): " << total << "\n";

        FileManager::save(products);

        ofstream s("sales.txt", ios::app);
        s << total << "\n";
        s.close();
    }

    void menu()
    {
        while (true)
        {
            int ch;
            cout << "\nBUYER MENU\n1 Buy Product\n2 Back\nChoice: ";
            cin >> ch;
            if (ch == 1)
                buy();
            else
                break;
        }
    }
};

/* ---------- MAIN ---------- */
int main()
{
    while (true)
    {
        int ch;
        cout << "\nMAIN MENU\n1 Admin\n2 Buyer\n3 Exit\nChoice: ";
        cin >> ch;

        if (ch == 1)
        {
            Admin a;
            if (a.login())
                a.menu();
            else
                cout << "Wrong Login\n";
        }
        else if (ch == 2)
        {
            Buyer b;
            b.menu();
        }
        else
            break;
    }
    return 0;
}