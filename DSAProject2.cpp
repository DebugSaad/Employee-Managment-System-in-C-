#include <iostream>
#include <cstdlib> // For system("cls")
#include <conio.h>
#include <string>

using namespace std;

class Employee
{
public:
    string name;
    string number;
    double salary;
    string employee_id;
    int cnic;
    Employee *prev;
    Employee *Next;

    Employee()
    {
        prev = NULL;
        Next = NULL;
    }

    Employee(string n, string nu, double salarys, string employee_ids, int cnics)
    {
        name = n;
        number = nu;
        salary = salarys;
        employee_id = employee_ids;
        cnic = cnics;
        prev = NULL;
        Next = NULL;
    }
};

class Queue
{
private:
    Employee *front;
    Employee *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    // Function Add value in the Queue
    void enqueue(string name, string number, double salary, string employee_id, int cnic)
    {
        Employee *newEmployee = new Employee(name, number, salary, employee_id, cnic);
        if (rear == NULL)
        {
            front = newEmployee;
            rear = newEmployee;
        }
        else
        {
            rear->Next = newEmployee;
            newEmployee->prev = rear;
            rear = newEmployee;
        }
        cout << "EMPLOYEE ADDED SUCCESSFULLY" << endl;
    }
    // Function to Check if Queue is Empty
    bool isEmpty()
    {
        return (front == NULL);
    }
    //  Function to Delete Value from Queue
    Employee *dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return NULL;
        }
        Employee *temp = front;
        front = front->Next;
        if (front == NULL)
        {
            rear = NULL;
        }
        else
        {
            front->prev = NULL;
        }
        return temp;
    }
    // Function to check Front Value
    Employee *peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return NULL;
        }
        return front;
    }
    // Function to Print whole data
    void print()
    {
        Employee *temp = front;
        if (temp == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << "NAME :                " << temp->name << endl;
            cout << "CONTACT :              " << temp->number << endl;
            cout << "SALARY :                " << temp->salary << endl;
            cout << "Employee-id :           " << temp->employee_id << endl;
            cout << "CNIC :                  " << temp->cnic << endl;
            cout << "---------------------------------------" << endl
                 << endl;
            temp = temp->Next;
        }
    }
    // Function For Bubble Sort
    void sortByName()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Employee *current = front;
        Employee *index = NULL;
        string tempName;
        double tempSalary;
        string tempEmployeeID;
        int tempCNIC;

        while (current != NULL)
        {
            index = current->Next;

            while (index != NULL)
            {
                if (current->name > index->name)
                {
                    tempName = current->name;
                    current->name = index->name;
                    index->name = tempName;

                    tempSalary = current->salary;
                    current->salary = index->salary;
                    index->salary = tempSalary;

                    tempEmployeeID = current->employee_id;
                    current->employee_id = index->employee_id;
                    index->employee_id = tempEmployeeID;

                    tempCNIC = current->cnic;
                    current->cnic = index->cnic;
                    index->cnic = tempCNIC;
                }
                index = index->Next;
            }
            current = current->Next;
        }
    }
    // Function For Insertion Sort
    void insertionSort()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Employee *current = front;
        Employee *index;
        string tempName;
        double tempSalary;
        string tempEmployeeID;
        int tempCNIC;

        while (current != NULL)
        {
            index = current;
            while (index->prev != NULL && index->prev->name > index->name)
            {
                tempName = index->prev->name;
                index->prev->name = index->name;
                index->name = tempName;

                tempSalary = index->prev->salary;
                index->prev->salary = index->salary;
                index->salary = tempSalary;

                tempEmployeeID = index->prev->employee_id;
                index->prev->employee_id = index->employee_id;
                index->employee_id = tempEmployeeID;

                tempCNIC = index->prev->cnic;
                index->prev->cnic = index->cnic;
                index->cnic = tempCNIC;

                index = index->prev;
            }
            current = current->Next;
        }
    }
    // Selection Sort Function
    void selectionSort()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Employee *start = front;
        while (start != NULL)
        {
            Employee *minNode = start;
            Employee *current = start->Next;
            while (current != NULL)
            {
                if (current->name < minNode->name)
                {
                    minNode = current;
                }
                current = current->Next;
            }
            // Swap data of start and minNode
            string tempName = start->name;
            start->name = minNode->name;
            minNode->name = tempName;

            double tempSalary = start->salary;
            start->salary = minNode->salary;
            minNode->salary = tempSalary;

            string tempEmployeeID = start->employee_id;
            start->employee_id = minNode->employee_id;
            minNode->employee_id = tempEmployeeID;

            int tempCNIC = start->cnic;
            start->cnic = minNode->cnic;
            minNode->cnic = tempCNIC;

            start = start->Next;
        }
    }

    // Function to partition the array of employees for quick sort
    int partition(Employee **arr, int low, int high)
    {
        string pivot = arr[high]->name;
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j]->name <= pivot)
            {
                i++;
                Employee *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        Employee *temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }

    // Function to perform quick sort on the array of employees
    void quickSort(Employee **arr, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Function to sort employees by name using quick sort
    void quickSortByName()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int count = 0;
        Employee *temp = front;
        while (temp != NULL)
        {
            count++;
            temp = temp->Next;
        }

        Employee **arr = new Employee *[count];
        temp = front;
        for (int i = 0; i < count; i++)
        {
            arr[i] = temp;
            temp = temp->Next;
        }

        quickSort(arr, 0, count - 1);
    
        front = arr[0];
        rear = arr[count - 1];
        for (int i = 0; i < count - 1; i++)
        {
            arr[i]->Next = arr[i + 1];
            arr[i + 1]->prev = arr[i];
        }
        arr[count - 1]->Next = NULL;

        delete[] arr; 
    }
};

int main()
{
    Queue e;
    double db;
    string n, s, employee_id;
    double salary;
    double cnic;
    string st;
    int choice;
    bool b;

    system("cls");
    system("Color 3B");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t*Welcome to Employee Management System*" << endl;
    getch();

    while (true)
    {
        system("cls");
        system("Color 03");
        cout << "PRESS 0  TO EXIT:" << endl;
        cout << "PRESS 1  TO ADD NEW Employee:" << endl;
        cout << "PRESS 2  TO PEEK AT THE FIRST EMPLOYEE:" << endl;
        cout << "PRESS 3  TO DEQUEUE THE FIRST EMPLOYEE:" << endl;
        cout << "PRESS 4  TO PRINT THE ALL EMPLOYEES:" << endl;
        cout << "PRESS 5  TO SORT THE EMPLOYEES BY NAME USING BUBBLE SORT:" << endl;
        cout << "PRESS 6  TO SORT THE EMPLOYEES BY NAME USING INSERTION SORT:" << endl;
        cout << "PRESS 7  TO SORT THE EMPLOYEES BY NAME USING SELECTION SORT:" << endl;
        cout << "PRESS 8  TO SORT THE EMPLOYEES BY NAME USING QUICK SORT:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "PROGRAM HAS BEEN ENDED" << endl;
            exit(0);
        case 1:
            system("cls");
            system("Color 03");
            cout << "ENTER THE NAME OF NEW EMPLOYEE:" << endl;
            cin >> s;
            cout << "ENTER THE CONTACT OF : " << s << endl;
            cin >> n;
            cout << "ENTER THE SALARY OF THE EMPLOYEE: " << endl;
            cin >> salary;
            cout << "ENTER THE EMPLOYEE ID OF THE EMPLOYEE: " << endl;
            cin >> employee_id;
            cout << "ENTER THE CNIC OF THE EMPLOYEE: " << endl;
            cin >> cnic;
            e.enqueue(s, n, salary, employee_id, cnic);
            break;
        case 2:
            system("cls");
            system("Color 03");
            Employee *firstEmployee;
            firstEmployee = e.peek();
            if (firstEmployee != NULL)
            {
                cout << "First Employee Details:" << endl;
                cout << "NAME :                " << firstEmployee->name << endl;
                cout << "CONTACT :             " << firstEmployee->number << endl;
                cout << "SALARY :              " << firstEmployee->salary << endl;
                cout << "Employee-id :         " << firstEmployee->employee_id << endl;
                cout << "CNIC :                " << firstEmployee->cnic << endl;
            }
            break;
        case 3:
            system("cls");
            system("Color 03");
            Employee *dequeuedEmployee;
            dequeuedEmployee = e.dequeue();
            if (dequeuedEmployee != NULL)
            {
                cout << "Dequeued Employee Details:" << endl;
                cout << "NAME :                " << dequeuedEmployee->name << endl;
                cout << "CONTACT :             " << dequeuedEmployee->number << endl;
                cout << "SALARY :              " << dequeuedEmployee->salary << endl;
                cout << "Employee-id :         " << dequeuedEmployee->employee_id << endl;
                cout << "CNIC :                " << dequeuedEmployee->cnic << endl;
            }
            break;
        case 4:
            system("cls");
            system("Color 03");
            e.print();
            break;
        case 5:
            system("cls");
            system("Color 03");
            e.sortByName();
            cout << "Employees sorted by name using bubble sort." << endl;
            break;
        case 6:
            system("cls");
            system("Color 03");
            e.insertionSort();
            cout << "Employees sorted by name using insertion sort." << endl;
            break;
        case 7:
            system("cls");
            system("Color 03");
            e.selectionSort();
            cout << "Employees sorted by name using selection sort." << endl;
            break;
        case 8:
            system("cls");
            system("Color 03");
            e.quickSortByName();
            cout << "Employees sorted by name using quick sort." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        cout << "Press any key to continue...";
        getch();
    }

    return 0;
}
