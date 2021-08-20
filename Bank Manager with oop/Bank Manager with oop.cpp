#include <iostream>
#include <string>
#include<fstream>
using namespace std;



int balance = 0;
int account_number;
string name;
ofstream myfile("Account_info.txt");
class account_creation {
public:
    void create_account() {

        cout << "enter your account number" << endl;
        cin >> account_number;
        cout << "enter your name" << endl;
        cin >> name;
        cout << "enter your balance" << endl;
        cin >> balance;
        myfile << "Account number is..." << account_number << endl;
        myfile << "Name of the user is..." << name << endl;
        myfile << "User's starting balance is..." << balance << endl;
    };
};

    class balance_info : public account_creation {
    public:
        void balance_enquiry() {
            if (balance == 0) {
                cout << "You have no money on your account..." << endl;
            }
            else if (balance < 100 && balance>0) {
                cout << "Your account balance is..." << balance << " " << "which is very low and if you do not add more money, your account will be blocked" << endl;
            }
            else if (balance > 100 && balance <= 1000) {
                cout << "Your account balance is..." << balance << endl;
            }
            else if (balance > 1000 && balance <= 2000) {
                balance = balance + 100;
                cout << "Account Balance is..." << balance << " " << " with 100RS bonus" << endl;
            }
            else if (balance > 2000 && balance <= 3000) {
                balance = balance + 200;
                cout << "Account Balance is..." << balance << " " << "with 200RS bonus" << endl;
            }
            else if (balance > 3000 && balance <= 4000) {
                balance = balance + 300;
                cout << "Account Balance is..." << balance << " " << "with 300RS bonus" << endl;
            }
            else if (balance > 4000) {
                balance = balance + 400;
                cout << "Account Balance is..." << balance << " " << "with 400RS bonus" << endl;
            }
        };
        void print() {
            cout << "this is private" << endl;
        };
    };


    class calculations : public balance_info {
    public:

        void deposit(int* x, int* y) {

            balance = *x + *y;

        };

        void draw(int* x, int* y) {

            balance = *x - *y;

        };

        void show_account() {
            cout << "customer's account number is..." << account_number << endl;
            cout << "Customer's name is..." << name << endl;
        };
    };

    class staff :public calculations {
        private:
    
        void print(){
            cout << "this is for staff" << endl;

        };
    
    };


int main() {
    bool mybool = true;
    while (mybool == true) {
        cout << "= = = = = = = = = = = =" << endl;
        cout << "BANK MANAGEMENT SYSTEM" << endl;
        cout << "= = = = = = = = = = = =" << endl;
        cout << ":: MAIN MENU ::" << endl << endl;

        cout << "1. NEW ACCOUNT" << endl;
        cout << "2. BALANCE ENQUIRY" << endl;
        cout << "3. DEPOSIT AMOUNT" << endl;
        cout << "4. WITHDRAW AMOUNT" << endl;
        cout << "5. ALL ACCOUNT HOLDER'S LIST" << endl;
        cout << "6. CLOSE AN ACCOUNT" << endl;
        cout << "7. MODIFY AN ACCOUNT" << endl;
        cout << "8. EXIT" << endl << endl;

        cout << "Select Your Option (1-8)" << endl;
        int choice;
        cin >> choice;

        staff obj;

        switch (choice) {
        case 1:
            obj.create_account();
            break;

        case 2:
            obj.balance_enquiry();
            obj.balance_info::print();
            break;

        case 3:
            cout << "Enter the amount" << endl;
            int amount;
            cin >> amount;
            obj.deposit(&balance, &amount);
            break;

        case 4:
            cout << "Enter the amount" << endl;

            cin >> amount;
            obj.draw(&balance, &amount);
            break;

        case 5:
            obj.show_account();
            obj.print();
            break;

        case 8:
            myfile << "User's current balance is..." << balance << endl;

            mybool = false;
            cout << "THANK YOU FOR VISITING THE BANK MANAGER" << endl;
            break;


        }
    }
}