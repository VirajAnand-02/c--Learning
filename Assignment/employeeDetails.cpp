#include <iostream>
#include <limits>
using namespace std;

#define MAX_EMPLOYEES 100

class Employee
{
public:
    static int count;
    string name;
    string post_name;
    string address;
    int salary;
    Employee(string name = "", string post_name = "", string address = "", int salary = 0)
    {
        this->name = name;
        this->post_name = post_name;
        this->address = address;
        this->salary = salary;
        count++;
    }
    void incrementSalary()
    {
        salary += salary * 0.1;
    }
};

int Employee::count = 0;

class Node
{
public:
    Employee employeeData;
    int id;
    Node *next;
    Node *prev;
    Node(Employee employeeData) : employeeData(employeeData), next(NULL), prev(NULL)
    {
        id = Employee::count;
    }
};

class EmployeeList
{
public:
    Node *head;
    EmployeeList() : head(NULL) {}

    void addNode(Employee employeeData)
    {
        Node *newNode = new Node(employeeData);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Add methods to access and display employees
    static void printEmployee(EmployeeList list)
    {
        Node *tmp = list.head;
        while (tmp != NULL)
        {
            cout << "ID: " << tmp->id << endl;
            cout << "Name: " << tmp->employeeData.name << endl;
            cout << "Address: " << tmp->employeeData.address << endl;
            cout << "Post: " << tmp->employeeData.post_name << endl;
            cout << "Salary: " << tmp->employeeData.salary << endl;
            tmp = tmp->next;
        }
    }

    static void yearTick(EmployeeList list)
    {
        Node *tmp = list.head;
        while (tmp != NULL)
        {
            tmp->employeeData.incrementSalary();
            tmp = tmp->next;
        }
    }
};

void menu()
{
    system("cls");
    cout << "Employee Management System" << endl
         << "Total employees: " << Employee::count << endl
         << "-----------------------" << endl;
    cout << "Select Option: " << endl;
    cout << "1) Insert Employee" << endl;
    cout << "2) Access Employee Details" << endl;
    cout << "3) Year Tick" << endl;
    cout << "4) Exit" << endl;
    cout << "> ";
}

Employee generateEmployee()
{
    string name, post_name, address;
    int salary;
    cout << "Employee Name: ";
    cin >> name;
    cout << "Employee Post: ";
    cin >> post_name;
    cout << "Employee Address: ";
    cin >> address;
    cout << "Employee Salary: ";
    cin >> salary;
    return Employee(name, post_name, address, salary);
}

void waitForEnter() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover newline character
    string enter;
    getline(cin, enter); // Then wait for Enter
}

int main()
{
    EmployeeList list;

    while (true)
    {
        menu();
        int input = 0;
        cin >> input;
        if (cin.fail())
        {                                                        // Check if input was not an integer
            cin.clear();                                         // Clears the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the invalid input
            cout << "Invalid input, please try again." << endl;
            continue; // Skips the rest of the loop and displays the menu again
        }
        switch (input)
        {
        case 1:
            list.addNode(generateEmployee());
            break;
        case 2:
            EmployeeList::printEmployee(list);
            waitForEnter();
            break;
        case 3:
            cout << "Tick" << endl;
            EmployeeList::yearTick(list);
            waitForEnter();
            break;
        case 4:
            cout << "Exiting...";
            return 0;
        }
    }

    return 0;
}
