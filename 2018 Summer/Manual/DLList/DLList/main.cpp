#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        prev = NULL;
        next = NULL;
    }
    ~Node()
    {
        cout << "Destructing Node" << endl;
    }
};

class DLList
{
private:

    Node* head;
    Node* tail;
    int length;
public:
    DLList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void Add(int i, int data)
    {
        if(i >= 0 && i <= length)
        {
            if (i == 0)
            {
                if (length == 0)
                {
                    head = tail = new Node();
                    head->data = data;
                }
                else
                {
                    head->prev = new Node;
                    head->prev->next = head;
                    head = head->prev;
                    head->data = data;
                }

            }
            else if (i == length)
            {
                tail->next = new Node();
                tail->next->prev = tail;
                tail = tail->next;
                tail->data = data;
            }
            else
            {
                Node* temp;
                if (i <= length/2)
                {
                    temp = head;
                    for (int j = 0; j < i; j++)
                    {
                        temp=temp->next;
                    }
                }
                else
                {
                    temp = tail;
                    for (int j = 0; j < length-i-1; j++)
                    {
                        temp = temp->prev;
                    }
                }

                Node* newNode = new Node;
                newNode->data = data;
                newNode->prev = temp->prev;
                newNode->next = temp;
                temp->prev->next = newNode;
                temp->prev = newNode;

            }
            length++;
        }
        else
        {
            cout << "Index is out of range" << endl;
        }

    }

    int Remove(int i)
    {
        if(i >= 0 && i < length)
        {
            int data;
            if (i == 0)
            {
                data = head -> data;
                head = head -> next;
                delete head -> prev;
                head -> prev = NULL;
            }
            else if (i == length-1)
            {
                data = tail -> data;
                tail = tail -> prev;
                delete tail -> next;
                tail -> next = NULL;
            }
            else
            {
                Node* temp;
                if (i < length / 2)
                {
                    temp = head;
                    for ( int j = 0; j < i; j++ )
                    {
                        temp = temp -> next;
                    }
                }
                else
                {
                    temp = tail;
                    for (int j = 0; j < (length - i - 1); j++)
                    {
                        temp = temp -> prev;
                    }

                }
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
                data = temp -> data;
                delete temp;
            }
            return data;
        }

        else
        {
            cout << "Index is out of range" << endl;
        }
    }

    void Show()
    {

        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp -> data << endl;
            temp = temp -> next;
        }
    }

    void Append(int data)
    {
        //cout<<length<<endl;
        if (length == 0)
        {
            head = tail = new Node();
            head -> data = data;

        }
        else
        {
            tail -> next = new Node();
            tail -> next -> prev = tail;
            tail = tail -> next;
            tail -> data = data;
        }
        length++;
    }

    void Reverse()
    {
        Node* prev = head;
        Node* current = head->next;
        Node* next = NULL;
        while (current!=NULL)
        {
            next = current -> next;
            current -> next = prev;
            prev -> prev = current;
            prev = current;
            current = next;
        }
        head -> next = NULL;
        tail -> prev = NULL;
        Node* temp = head;
        head = tail;
        tail = temp;
    }
    ~DLList()
    {
        cout << "Destructing List" << endl;
        Node* temp = head;
        while(temp != NULL)
        {
            Node* prev = temp;
            temp = temp -> next;
            delete prev;
        }
    }

};
int main()
{
    DLList lst;

    lst.Append(5);
    lst.Append(10);
    lst.Append(11);
    lst.Add(1,3);
    lst.Add(1,5);
    lst.Add(0, 9);
    lst.Add(5,6);
    //a.Add(a.length,94);
    lst.Show();
    cout << "Removing at 6th index" << endl;
    lst.Remove(6);
    lst.Show();
    cout << "Removing at 0th index" << endl;
    lst.Remove(0);
    lst.Show();
    cout << "Removing at 1st index" << endl;
    lst.Remove(1);
    lst.Show();
    cout << "Removing at 2nd index" << endl;
    lst.Remove(2);
    lst.Show();
    lst.Reverse();
    cout << "Reversing" << endl;
    lst.Show();


    return 0;
}
