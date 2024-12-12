#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    const int paninda = 6;
    string goods[] = {"Hopia", "Mani", "Popcorn", "Chicharon", "Balut", "Penoy"};
    double prices[] = {6.00, 25.00, 20.00, 15.00, 25.00, 18.00};

    int choice = 0;
    int quantity = 0;
    double totalCost = 0;

    for (int i = 0; i < paninda ; i++)
    {
       cout << i + 1 << "." << goods[i] << " - $ " << fixed << setprecision(2) << prices[i] << endl;
    }
    while (true)
    {
       cout << "Ano po'ng bibilhin niyo? (Kung wala sa choices, press 0 then shoo): ";
       cin >> choice;

       if (choice == 0){
        cout << "Wala naman palang bibilhin, abala pa.";
        break;
       }
       else if (choice < 0 || choice > paninda)
       {
        cout << "Invalid choice. Ayusin mo naman." << endl;
        continue;
       }

       cout << "Ilan po?: ";
       cin >> quantity;

       if (quantity <= 0)
       {
        cout << "Mukha po ba akong nakikipagbiruan, Maem?" << endl;
         continue;
       }

       double totalCost = prices[choice - 1] * quantity;
       double bayad;
       

       cout << "So ang binili n'yo po ay " << goods[choice - 1] << ", at ang total po ay $ " << fixed << setprecision(2) << totalCost << endl;
       cout << "O akin na bayad mo! ";
       cin >> bayad;

       if (bayad < totalCost){
        cout << "Kupal ka ba? Kulang bonak!" << endl;
        continue;
       }
      double sukli = bayad - totalCost; if (bayad > totalCost) { 
        cout << "Oh eto sukli mo, $ " << fixed << setprecision(2) << sukli << endl;
      }
       cout << "Ge, thanks. Balik ka next life";
       break;
       
    
       
    }
    return 0;
}
