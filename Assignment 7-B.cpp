#include <bits/stdc++.h>
using namespace std;

class node      /* a class node for defining a node of a doubly linked circular list */
{
    private:
        char status;
        node *next;
        node *prev;
    
    public:
        node()     /*constructor for node of doubly linked circular list*/
        {
            status = '_';
            next = NULL;
            prev = NULL;
        }
        friend class DCList;
};

class DCList          /* class DCList to define a doubly linked circular list */
{
    private:
        node *head;
    
    public:
        DCList()                   /* constructor to create a doubly linked circular list with 7 nodes */
        {
            node *temp;
            node *newnode = new node();
            head = newnode;
            temp = head;

            for(int i = 1; i < 7; i++)
            {
                node *newnode = new node();
                temp->next = newnode;
                newnode->prev = temp;
                temp = temp->next;
            }

            temp->next = head;
            head->prev = temp;
        }

        void Display()                 /* a function to display the status of seats of a row */
        {
            node *temp = head;
            int i = 0;
            while(i < 7)
            {
                cout << i+1 << "(" << temp->status << ")\t";
                i++;
                temp = temp->next;
            }
        }

        void Book(int n, int x=1)              /* a function to book seats of a row */
        {
            if(n > 7)
            {
                cout << "Invalid seat number!" << endl;
            }
            else
            {
                node *temp = head;
                int i = 1;
                while(i != n)     /* traversing to seat number */
                {
                    temp = temp->next;
                    i++;
                }

                node *temp2 = temp;                   
                int flag = 0;
                for(int j = 0; j < x; j++)                  /* for loop for checking if seats are already booked or not */
                {
                    if(temp2->status == 'B')
                    {
                        cout<<"\nThese number of seats are not free consecutively. Please choose a different seat location with "<< x <<" consecutively empty seats." << endl;
                        flag = 1;
                        break;
                    }
                    temp2 = temp2->next;
                }

                if(flag != 1)                    /* changing status of seats to book if seats are available */
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
};


int main()              /* main function */
{
    DCList *list[10];
    int n;
    for(int i = 1; i <= 10; i++)
    {
        list[i] = new DCList();
    }
    bool flag = true;
    while(flag)
    {
        int cnt;
        cout << "1. Display hall layout \n2. Book a seat \n3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> cnt;

        switch(cnt)
        {
            case 1:
                cout << "Seat layout : " << endl;
                for(int i = 1; i <= 10; i++)
                {
                    cout << "Row " << i << ": ";    
                    list[i]->Display();
                    cout << endl;
                }
                break;

            case 2:
                int rownum, seat;
                cout << "\nHow many seats do you want to book?: ";
                cin >> n;
                cout << "\nEnter the preferred row number for your seat: ";
                cin >> rownum;
                cout << "\nEnter preferred seat number: ";
                cin >> seat;
                list[rownum]->Book(seat, n);
                break;

            case 3:
                flag = false;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}