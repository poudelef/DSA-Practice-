#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void appenditem(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = head;
            length++;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            length++;
        }
    }

    void deletelast()
    {
        if (length == 0)
        {
            return;
        }
        else if (length == 1)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = head;
            ;
            Node *pre = head;

            while (temp->next != nullptr)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
            delete temp;
        }
        length--;
    }

    void gethead()
    {
        cout << "Head: " << head->value << endl;
    }
    void gettail()
    {
        cout << "Tail: " << tail->value << endl;
    }
    void getlength()
    {
        cout << "Length: " << length << endl;
    }
};

int main()
{
    LinkedList *myLinkedList = new LinkedList(4);
    myLinkedList->appenditem(5);
    myLinkedList->appenditem(6);
    myLinkedList->printList();
    cout << "..........." << endl;
    myLinkedList->deletelast();
    myLinkedList->gethead();
    myLinkedList->gettail();
    myLinkedList->getlength();
    myLinkedList->printList();
}