#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Employee {
    int id;
    string name;
    float basicsalary;
    float ta;
    float incometax;
    float netsalary;
};

// Function to calculate Income Tax
float calcIncomeTax(float basicsalary, float ta) {
    if (basicsalary > 15000) {
        return (basicsalary + ta) * 0.35;
    } else if (basicsalary > 10000) {
        return (basicsalary + ta) * 0.3;
    } else if (basicsalary > 5000) {
        return (basicsalary + ta) * 0.2;
    } else {
        return 0;
    }
}

// Function to get Employee Data and Write to File
void getData() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    ofstream file("employee2.txt"); // Open file to write data
    file << "ID\tName\tBasic Salary\tTransport Allowance\tIncome Tax\tNet Salary\n";

    for (int i = 0; i < n; ++i) {
        Employee emp;
        string has_ta;
        cout << "\nEnter details for employee " << i + 1 << ":\n";

        cout << "Enter ID: ";
        cin >> emp.id;

        cout << "Enter Name: ";
        cin >> emp.name;

        cout << "Enter Basic Salary: ";
        cin >> emp.basicsalary;

        cout << "Does the employee have Transport Allowance (yes/no)? ";
        cin >> has_ta;

        if (has_ta == "yes" || has_ta == "Yes") {
            cout << "Enter Transport Allowance: ";
            cin >> emp.ta;
        } else {
            emp.ta = 0;
        }

        // Calculate Income Tax and Net Salary
        emp.incometax = calcIncomeTax(emp.basicsalary, emp.ta);
        emp.netsalary = (emp.basicsalary + emp.ta) - emp.incometax;

        // Write data to file
        file << emp.id << "\t" << emp.name << "\t"
             << fixed << setprecision(2) << emp.basicsalary << "\t"
             << emp.ta << "\t"
             << emp.incometax << "\t"
             << emp.netsalary << "\n";
    }

    file.close(); // Close the file
    cout << "Employee data has been saved to 'employee2.txt'.\n";
}

// Function to Read Employee Data from File
void readData() {
    ifstream file("employee2.txt"); // Open file to read data
    if (!file) {
        cout << "File not found.\n";
        return;
    }

    cout << "\nEmployee Data from File:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close(); // Close the file
}

int main() {
    int choice;
    cout << "1. Enter Employee Data\n2. Read Employee Data\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        getData();
    } else if (choice == 2) {
        readData();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
