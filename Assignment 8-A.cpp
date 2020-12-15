#include <iostream>
#include <string>

using namespace std;

class node
{
private:
    int roll_no;
    string name;
    node* next;

public:
    // Constructor of node used to initialize values
    node(int roll_no, string name)
    {
        this->name = name;
        this->roll_no = roll_no;
        next = NULL;
    }

    friend class linked_list;
    friend class Set;
};

class linked_list
{
private:
    node* head;

    // creates a new node and sets the value of roll_no and name
    node* get_NewNode(int roll_no, string name)
    {
        node* new_node = new node(roll_no, name);
        return new_node;
    }

public:
    // Constructor of linked_list used to initialize value
    linked_list()
    {
        head = NULL;
    }

    // adds a new node to the beginning of list
    void add_node(int roll_no, string name)
    {
        node* new_node = get_NewNode(roll_no, name);
        if (head == NULL) 
        {
            head = new_node;
        }
        else 
        {
            new_node->next = head;
            head = new_node;
        }
    }

    // used to check whether the roll_no is present in the list
    bool isPresent(int ele)
    {
        node *temp = head;
        while (temp)
        {
            if (temp->roll_no == ele) return true;
            temp = temp->next;
        }
        return false;
    }

    // displays roll_no and name of student from the list
    void display()
    {
        if (head == NULL)
        {
            cout << "Empty List.\n";
            return;
        }
        node* temp = head;
        while (temp)
        {
            cout << "Roll Number: " << temp->roll_no << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    friend class Set;
};

class Set
{
private:
    // creates a list of students using object of class linked_list
    linked_list students;

public:
    // reads the student input from the user and
    // adds the data to the list
    void read_input()
    {
        int n, roll_no;
        string name;
        cout << "Number of students: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter roll number: ";
            cin >> roll_no;
            cout << "Enter name: ";
            cin >> name;
            // makes sure to avoid duplicate entries based on roll_no
            if (!students.isPresent(roll_no)) 
            {
                students.add_node(roll_no, name);
            }
            else 
            {
                cout << "Roll number is already present in list. Enter again.\n";
                i--;
            }
        }
    }

    Set Union(Set B)
    {
        Set union_set;
        node* temp_A = students.head;
        while (temp_A)
        {
            union_set.students.add_node(temp_A->roll_no, temp_A->name);
            temp_A = temp_A->next;
        }

        node* temp_B = B.students.head;
        while (temp_B)
        {
            if (!students.isPresent(temp_B->roll_no)) 
            {
                union_set.students.add_node(temp_B->roll_no, temp_B->name);
            }
            temp_B = temp_B->next;
        }

        return union_set;
    }

    Set Intersection(Set B)
    {
        Set intersection_set;
        node* temp_a = students.head;
        while (temp_a)
        {
            if (B.students.isPresent(temp_a->roll_no)) 
            {
                intersection_set.students.add_node(temp_a->roll_no, temp_a->name);
            }
            temp_a = temp_a->next;
        }
        return intersection_set;
    }

    Set Difference(Set B)
    {
        Set difference_set;
        node* temp_a = students.head;
        while (temp_a)
        {
            if (!B.students.isPresent(temp_a->roll_no)) 
            {
                difference_set.students.add_node(temp_a->roll_no, temp_a->name);
            }
            temp_a = temp_a->next;
        }
        return difference_set;
    }

    void displayData()
    {
        students.display();
    }
};

int main()
{
    int choice;
    Set all_students, vanilla, butter;
    cout << "Enter Universal Data:\n";
    all_students.read_input();
    cout << "\nFor vanilla:\n";
    vanilla.read_input();
    cout << "\nFor butterscotch: \n";
    butter.read_input();

    cout << "\nStudents who like Vanilla: \n";
    vanilla.displayData();
    cout << "Students who like Butterscotch: \n";
    butter.displayData();

    Set vanilla_or_butter = vanilla.Union(butter);
    Set vanilla_and_butter = vanilla.Intersection(butter);

    while (true)
    {
        cout << "\nMENU\n";
        cout << "1. Students who like both vanilla and butterscotch\n";
        cout << "2. Students who like either vanilla or butterscotch but not both\n";
        cout << "3. Students who like neither vanilla nor butterscotch\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        Set result;

        if (choice == 1)
        {
            result = vanilla_and_butter;
            cout << "\nStudents who like both vanilla and butterscotch: \n";
        }

        else if (choice == 2)
        {
            result = vanilla_or_butter.Difference(vanilla_and_butter);
            cout << "\nStudents who like either vanilla or butterscotch but not both: \n";
        }

        else if (choice == 3)
        {
            result = all_students.Difference(vanilla_or_butter);
            cout << "\nStudents who like neither vanilla nor butterscotch: \n";
        }

        else break;

        result.displayData();
    }
    return 0;
}
