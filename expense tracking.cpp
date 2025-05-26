#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// Node for each expense
struct ExpenseNode {
    int id;
    string productName;
    string date; // Format: DD-MM-YYYY
    float amount;
    ExpenseNode* next;
};

// Main list to manage all expenses
class ExpenseList {
private:
    ExpenseNode* head;
    int nextID; // For auto ID generation

    int stringToInt(string str) {
        int result = 0;
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i])) {
                result = result * 10 + (str[i] - '0');
            }
        }
        return result;
    }

    string getMonthYear(string date) {
        stringstream ss(date);
        string day, month, year;
        getline(ss, day, '-');
        getline(ss, month, '-');
        getline(ss, year, '-');
        return month + "-" + year;
    }

    int getWeek(string date) {
        stringstream ss(date);
        string dayStr;
        getline(ss, dayStr, '-');
        int day = stringToInt(dayStr);
        return (day - 1) / 7 + 1;
    }

public:
    ExpenseList() {
        head = NULL;
        nextID = 1;
    }

    void addExpense(string name, string date, float amount) {
        ExpenseNode* newNode = new ExpenseNode();
        newNode->id = nextID++;
        newNode->productName = name;
        newNode->date = date;
        newNode->amount = amount;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            ExpenseNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "? Expense added successfully with ID: " << newNode->id << endl;
    }

    void deleteExpenseByName(string name) {
        if (head == NULL) {
            cout << "?? List is empty.\n";
            return;
        }

        ExpenseNode* current = head;
        ExpenseNode* previous = NULL;

        while (current != NULL && current->productName != name) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "? Product with name '" << name << "' not found.\n";
            return;
        }

        if (current == head) {
            head = head->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        cout << "??? Product '" << name << "' deleted.\n";
    }

    void updateExpense(string name) {
        if (head == NULL) {
            cout << "?? List is empty.\n";
            return;
        }

        ExpenseNode* temp = head;
        while (temp != NULL && temp->productName != name) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "? Product with name '" << name << "' not found.\n";
            return;
        }

        cout << "Enter new product name: ";
        getline(cin, temp->productName);
        cout << "Enter new date (DD-MM-YYYY): ";
        getline(cin, temp->date);
        cout << "Enter new amount: ";
        cin >> temp->amount;
        cin.ignore();
        cout << "? Product details updated successfully.\n";
    }

    void displayExpenses() {
        if (head == NULL) {
            cout << "?? No expenses to display.\n";
            return;
        }

        ExpenseNode* temp = head;

        cout << "\n?? All Expenses:\n";
        cout << "----------------------------------------------------------------------------\n";
        cout << "| " << setw(5) << left << "ID"
             << "| " << setw(20) << left << "Product Name"
             << "| " << setw(15) << left << "Date"
             << "| " << setw(10) << left << "Amount"
             << "|\n";
        cout << "----------------------------------------------------------------------------\n";

        while (temp != NULL) {
            cout << "| " << setw(5) << left << temp->id
                 << "| " << setw(20) << left << temp->productName
                 << "| " << setw(15) << left << temp->date
                 << "| " << setw(10) << left << temp->amount
                 << "|\n";
            temp = temp->next;
        }

        cout << "----------------------------------------------------------------------------\n";
    }

    void totalByMonth(string monthYear) {
        if (head == NULL) {
            cout << "?? No expenses to calculate.\n";
            return;
        }

        ExpenseNode* temp = head;
        float total = 0;
        while (temp != NULL) {
            if (getMonthYear(temp->date) == monthYear) {
                total += temp->amount;
            }
            temp = temp->next;
        }

        cout << "?? Total expenses for " << monthYear << ": " << total << endl;
    }

    void totalByWeek(string monthYear, int weekNum) {
        if (head == NULL) {
            cout << "?? No expenses to calculate.\n";
            return;
        }

        ExpenseNode* temp = head;
        float total = 0;
        while (temp != NULL) {
            if (getMonthYear(temp->date) == monthYear && getWeek(temp->date) == weekNum) {
                total += temp->amount;
            }
            temp = temp->next;
        }

        cout << "?? Total expenses for " << monthYear << " (Week " << weekNum << "): " << total << endl;
    }
};

// Main Function
int main() {
    ExpenseList tracker;
    int choice, weekNum;
    string name, date, monthYear;
    float amount;

    do {
        cout << "\n===== Expense Tracker Menu =====\n";
        cout << "1. Add Expense\n";
        cout << "2. Delete Expense by Product Name\n";
        cout << "3. Update Expense by Product Name\n";
        cout << "4. Display All Expenses\n";
        cout << "5. Total Expense for a Month (MM-YYYY)\n";
        cout << "6. Total Expense for a Week (MM-YYYY + Week)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter Product Name: ";
            getline(cin, name);
            cout << "Enter Date (DD-MM-YYYY): ";
            getline(cin, date);
            cout << "Enter Amount: ";
            cin >> amount;
            cin.ignore();
            tracker.addExpense(name, date, amount);
            break;

        case 2:
            cout << "Enter Product Name to delete: ";
            getline(cin, name);
            tracker.deleteExpenseByName(name);
            break;

        case 3:
            cout << "Enter Product Name to update: ";
            getline(cin, name);
            tracker.updateExpense(name);
            break;

        case 4:
            tracker.displayExpenses();
            break;

        case 5:
            cout << "Enter Month-Year (MM-YYYY): ";
            getline(cin, monthYear);
            tracker.totalByMonth(monthYear);
            break;

        case 6:
            cout << "Enter Month-Year (MM-YYYY): ";
            getline(cin, monthYear);
            cout << "Enter Week Number (1-4): ";
            cin >> weekNum;
            tracker.totalByWeek(monthYear, weekNum);
            cin.ignore();
            break;

        case 7:
            cout << "?? Exiting... Goodbye!\n";
            break;

        default:
            cout << "?? Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}



