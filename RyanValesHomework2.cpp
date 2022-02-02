// RyanValesHomework2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class customer {

public:
    string orderName;
    string orderDescription;
    string orderTotal;
    string orderTip;
    string orderDate;
};

queue<customer> customerQueue;

// Function enqueue adds a customer to the order queue
void enQueue() {
    
    customer customers;
    
    cout << "Please enter the Order Name: ";
    cin.ignore();
    getline(cin, customers.orderName);
    
    cout << "Please enter the Order Description: ";
    getline(cin, customers.orderDescription);
    
    cout << "Please enter the Order Total: ";
    cin >> customers.orderTotal;
    
    cout << "Please enter the Order Tip: ";
    cin >> customers.orderTip;
    
    cout << "Please enter the Order Date: ";
    cin.ignore();
    getline(cin, customers.orderDate);

    cout << "\n\n";
    
    customerQueue.push(customers);
}

// Function dequeue removes a customer from the order queue
customer deQueue() {
    
    customer customers;
    
    if (!customerQueue.empty()) {
        customers = customerQueue.front();
        customerQueue.pop();
    }
    return customers;
}

// Function peek returns the customer at the front of the queue
void peek() {
    
    if (!customerQueue.empty()) {
        customer currentOrder = customerQueue.front();
        cout << "The current Order Name is: " << currentOrder.orderName << endl;
        cout << "The current Order Description is: " << currentOrder.orderDescription << endl;
        cout << "The current Order Total is: " << currentOrder.orderTotal << endl;
        cout << "The current Order Tip is: " << currentOrder.orderTip << endl;
        cout << "The current Order Date is: " << currentOrder.orderDate << endl;
    }
}


int main() {
    
    bool exitMenu = false;
    int userChoice;
    
    customer lastOrder;

    while (!exitMenu) {
        
        //Prompts for Menu Selection while exitMenu is false
        cout << "Welcome to our locally owned restaurant!" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Pleese select one of the below menu options: " << endl;
        cout << "1. Add order" << endl; 
        cout << "2. Next order" << endl;
        cout << "3. Previous order" << endl;
        cout << "4. Delete order" << endl;
        cout << "5. Order size" << endl;
        cout << "6. View current order" << endl;
        cout << "7. Exit this menu" << endl;
        cout << "\n\n";
        cout << "Enter the number of the action you would like to perform: ";
        
        cin >> userChoice;
        
        if (userChoice == 1) {
            enQueue();
        } else if (userChoice == 2) {
            lastOrder = deQueue();
            peek();
        } else if (userChoice == 3) {
            cout << "The last Order Name is: " << lastOrder.orderName << endl;
            cout << "The last Order Description is: " << lastOrder.orderDescription << endl;
            cout << "The last Order Total is: " << lastOrder.orderTotal << endl;
            cout << "The last Order Tip is: " << lastOrder.orderTip << endl;
            cout << "The last Order Date is: " << lastOrder.orderDate << endl;
        } else if (userChoice == 4) {
            lastOrder = deQueue();
        } else if (userChoice == 5) {
            cout << "There are " << customerQueue.size() << " orders in the queue." << endl;
        } else if (userChoice == 6) {
            peek();
        } else if (userChoice == 7) {
            cout << "Thank you for visiting, please come again soon!" << endl;
            exitMenu = true;
        }
    }
}