#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> products;
vector<float> prices;

void LoadValues()
{
    string temp;
    float tval = 0.0;

    ifstream ProductInfo;
    ProductInfo.open("products.dat");

    if (ProductInfo.is_open())
    {
        while (ProductInfo >> temp)
        {
            products.push_back(temp);
            ProductInfo >> temp;

            tval = atof(temp.c_str());
            prices.push_back(tval);
        }
    }
    else
    {
        cout << "Fail To Load Data \n\n ";
    }
    ProductInfo.close();
}

void NewClient()
{
    int id = 0;
    int qty = 0;
    int itemqty = 0;
    float sum = 0.0;

    cout << "NEW SALE\n";
    cout << "INSTRUCTIONS:\n";
    cout << "Enter The ID of the product. After that, enter the quantity and press enter\n";
    cout << "If you have finished, enter -1  on product and will exit \n\n";

    while (true)
    {
        cout << "Enter Product ID: ";cin >> id;

        cout << "Enter Quantity: ";cin >> qty;

        if (id == -1)
        {
            break;
        }

        itemqty += qty;
        cout << endl;

        float value = prices[id] * qty;
        sum = sum + value;
    }

    float tax = (sum * 0.0825);
    float total = (sum + tax);

    cout << "\nYou have bought " << itemqty << " items\n";
    cout << "Subtotal: " << "$ " << sum << endl;
    cout << "Tax: " << "$" << tax << endl;
    cout << "Total: " << "$" << total << endl;

    float money = 0.0;

    cout << "Money: ";
    cin >> money;

    if (money >= total)
    {
        cout << "Your Change Is " << "$ " << (money - total) << endl;
        cout << "Thanks For Shopping. Returning To Main - - - ";
    }

    else
    {
        cout << "Not Enough Money.\n";
    }

    ofstream sales;
    sales.open("sales.dat", ios::app);

    if (sales.is_open())
    {
        sales << itemqty << "Items " << total << endl;
    }
    else
    {
        cout << "Sale's File Corrupted- - - ";
    }
    sales.close();
}

void ViewCatalog()
{
    cout << "Product Catalog\n\n";
    cout << "ID\tPRODUCT\t\tPRICE\n";
    cout << "----------------------------------\n";

    for (int i = 0; i != products.size(); i++)
    {
        cout << "[" << i << "]" << "\t" << products[i] << " " << "$" << prices[i] << endl;
        cout << "\n\n";
    }
}

void ViewSales()
{
    cout << "SUPERMARKET SALES \n\n";
    cout << "Stats\n";

    string temp;
    int salesCount = 0;
    int itemCount = 0;
    float sumCount = 0;
    float tval = 0.0;

    ifstream salesFile;
    salesFile.open("sales.dat");

    for (int i = 0; i != products.size(); i++)
    {
        if (salesFile.is_open())
        {
            cout << "[" << i << "]" << products[i] << "\n";

            while (salesFile >> temp)
            {

                tval = atof(temp.c_str());
                itemCount += tval;

                salesFile >> temp;
                tval = atof(temp.c_str());
                sumCount += tval;

                salesCount++;
            }
        }

        else
        {
            cout << "\nSALES FILE NOT FOUND! Data Cannot Be Generated \n\n";
        }
    }
    salesFile.close();

    cout << "Total Of Sales: " << salesCount << endl;
    cout << "Total Of Items Sold: " << itemCount << endl;
    cout << "Total Earnings: "
         << "$" << sumCount << endl;
    cout << "\n\n";
}

int main()
{
    LoadValues();
    int sel = 0;
    bool condition = true;

    while (condition)
    {
        cout << "SUPERMARKET SYSTEM\n\n";
        cout << "[1] New Clients\n";
        cout << "[2] View Catalogs\n";
        cout << "[3] View Sales\n";
        cout << "[4] Exit\n";
        cout << "Select >>";
        cin >> sel;

        switch (sel)
        {
        case 1:
            NewClient();
            break;

        case 2:
            ViewCatalog();
            break;

        case 3:
            ViewSales();
            break;

        case 4:
            return 0;
            break;

        default:
            break;
        }
    }
}

