#include <iostream>

using namespace std;

// class that creates nodes in the linked list
class node
{
    char status;
    node *next;
    node *prev;

public:
    // constructor
    node()
    {
        status = '_';
        next = NULL;
        prev = NULL;
    }

    friend class DCLList;
};

class DCLList
{
    node *head;
public:
    // constructor creates 7 nodes
    DCLList()
    {
        node *temp;
        node *newnode = new node(); // first node
        head = newnode;
        temp = head;

        // remaining nodes
        for(int i = 1; i < 7; i++)
        {
            node *newnode = new node();
            temp->next = newnode;
            temp = temp->next;
        }

        temp->next = head;
        head->prev = temp;
    }

    void Book(int n, int x=1)
    {
        if(n > 7)
        {
            cout << "Invalid seat number!" << endl;
        }
        else
        {
            node *temp = head;
            int i = 1;
            while(i != n)
            {
                temp = temp->next;
                i++;
            }

            node *temp2 = temp;
            int flag = 0;
            for(int j = 0; j < x; j++)
            {
                if(temp2->status == 'B')
                {
                    cout<<"\nThese number of seats are not free consecutively. Please choose a different seat location with "<<x<<" consecutively empty seats."<<endl;
                    flag = 1;
                    break;
                }
                temp2 = temp2->next;
            }
            if (flag != 1)
            {
                for(int j = 0; j < x; j++)
                {
                    temp->status = 'B';
                    temp = temp->next;
                }
            }
        }
    }

    void Cancel(int n)
    {
        if(n > 7)
        {
            cout<<"Invalid seat number!"<<endl;
        }
        else
        {
            node *temp = head;
            int i = 1;
            while(i != n)
            {
                temp = temp->next;
                i++;
            }
            if(temp->status != 'B')
            {
                cout<<"This seat has not been booked and so cannot be cancelled!"<<endl;
            }
            else
            {
                temp->status = '_';
            }
        }
    }

    void Display()
    {
        node *temp = head;
        int i = 0;
        while(i < 7)
        {
            if(temp->status != 'B')
            {
                cout<<i+1<<"("<<temp->status<<")\t";
                i++;
                temp = temp->next;
            }
            else
            {
                cout<<i+1<<"("<<temp->status<<")\t";
                i++;
                temp = temp->next;
            }
        }
    }
};

int main() {
    DCLList *list[10];
    int n;
    for (int i = 0; i < 10; i++) {
        list[i] = new DCLList();
    }

    list[0]->Book(1);
    list[1]->Book(1);
    list[4]->Book(2);
    list[7]->Book(7);
    list[9]->Book(5);

    cout << "1. Display Cinemax hall layout \n2. Book a seat \n3. Cancel  a booked seat \n";

    while (true) {
        int ch;
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nCinemax seat layout : " << endl;
                for (int i = 0; i < 10; i++) {
                    if ((i + 1) == 10) {
                        cout << "Row " << i + 1 << ": ";
                    } else {
                        cout << "Row " << i + 1 << " : ";
                    }
                    list[i]->Display();
                    cout << "\n";
                }
                cout << "\n";
                break;

            case 2:
                int rowNumB, Bseat;
                cout << "\nHow many seats do you want to book? ";
                cin >> n;
                cout << "\nEnter the preferred row number for your seat : ";
                cin >> rowNumB;
                cout << "Enter preferred seat for BOOKING : ";
                cin >> Bseat;
                list[rowNumB - 1]->Book(Bseat, n);
                cout << "\n";
                break;

            case 3:
                int rowNumC, Cseat;
                cout << "\nHow many seats do you want to cancel? ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter the row number for your seat : ";
                    cin >> rowNumC;
                    cout << "Enter seat to be CANCELLED : ";
                    cin >> Cseat;
                    list[rowNumC - 1]->Cancel(Cseat);
                }
                cout << "\n";
                break;

            default:
                exit(0);
        }
    }
}