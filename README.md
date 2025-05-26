# expense-tracking-system
📊 Expense Tracker (C++ Linked List Project)
🚀 Overview
This project is a console-based Expense Tracker developed in C++, designed to manage personal or small-scale financial records using a singly linked list. Each expense record includes a product name, date, amount, and a unique ID (auto-generated). The program allows users to add, delete, update, and display expenses, as well as calculate total expenses by month or week.

The code is beginner-friendly and compatible with Dev C++ and other C++ compilers that support basic C++ features.

🧩 Features
✅ Add Expense: Enter product name, date, and amount. ID is generated automatically.
✅ Delete Expense: Remove an expense by product name.
✅ Update Expense: Modify product name, date, and amount for any entry.
✅ Display All Expenses: View all expenses in a neatly formatted table.
✅ Total by Month: Calculate total expense for a given month (e.g., 05-2025).
✅ Total by Week: Calculate total expense for a specific week (1–4) within a month.
✅ User-friendly Menu System: Interactive and easy to use.
✅ No External Libraries Needed: Fully compatible with Dev C++ (no C++11/14/17 features).

🛠️ How to Use
Compile & Run the code in your C++ compiler (e.g., Dev C++, Code::Blocks, Visual Studio).

The program will display a menu:

mathematica
Copy
Edit
1. Add Expense
2. Delete Expense by Product Name
3. Update Expense by Product Name
4. Display All Expenses
5. Total Expense for a Month (MM-YYYY)
6. Total Expense for a Week (MM-YYYY + Week)
7. Exit
Follow the prompts to manage your expenses.

🧮 Example
yaml
Copy
Edit
> Add Expense:
  Product Name: Tea
  Date: 15-05-2025
  Amount: 200

> Add Expense:
  Product Name: Milk
  Date: 18-05-2025
  Amount: 150

> Display All Expenses:
  ------------------------------------------------------------
  | ID   | Product Name      | Date           | Amount    |
  ------------------------------------------------------------
  | 1    | Tea               | 15-05-2025     | 200       |
  | 2    | Milk              | 18-05-2025     | 150       |
  ------------------------------------------------------------
📦 Requirements
✅ Basic C++ compiler (Dev C++, Code::Blocks, Visual Studio, or any C++98/03 compatible compiler)
✅ No external libraries required

📌 Future Improvements (Optional Ideas)
Export/Import expenses to a file (CSV support)

Filter by categories (e.g., Food, Transport)

Sort expenses by date or amount

Add user authentication for multiple users

📄 License
This project is open-source. Feel free to modify and improve it as needed!
