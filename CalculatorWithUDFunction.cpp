#include <iostream>
using namespace std;

void add(double num1, double num2){
    cout << "The sum is " << num1 + num2 << endl;
}
void subtract(double num1, double num2){
    cout << "The difference is " << num1 - num2 << endl;
}
void multiply (double num1, double num2){
    cout << "The product is " << num1 * num2 << endl;
}
void divide(double num1, double num2){
    cout << "The quotient is " << num1 / num2 << endl;
}

int main(){
    double num1, num2;
    char choice;

     do
     {
        cout << "Enter first number: ";
     cin >> num1;
     cout << "Enter second number: ";
     cin >> num2;

     cout << "Enter the operator (+, -, *, /): ";
     cin >> choice;

    
       switch (choice)
       {
        case '+':
            add(num1, num2);
        break;

         case '-':
            subtract(num1, num2);
        break;

         case '*':
            multiply(num1, num2);
        break;

         case '/':
            divide(num1, num2);
        break;
       
       default: cout << "Invalid operator! Try again!" << endl;
        continue;
       }

       cout << "Do you still want to use this? (Y/N): ";
     cin >> choice;
     
     if (choice == 'n' || choice == 'N')
     {
        cout << "K, bye.";
     }
     break;

     } while (true);
     
     return 0;
     

}