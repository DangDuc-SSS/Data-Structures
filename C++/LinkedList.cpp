#include <iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node *next;
};
void printList(Node *head){
    // cout << head->data << endl;
    // printList(head->next);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout <<"\n-----------------------" << endl;
    
}
/*
 *=============================================
 * @fn: check value of element
 *=============================================
 */
// void insertAtBegining(Node *head, int value)
// {
//     cout << "in func -> value: " << head->data  << " address of data" << &head->data 
//             << " address of head" << &head << endl;
// }
void insertAtBegining(Node **head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(Node **head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        Node *tail = *head;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = newNode;

    }
}
int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;
    // cout << "out func -> value: " << head->data  << " address of data" << &head->data 
    //         << " address of head" << &head << endl;      // check value of element  
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;


    printList(head);
    insertAtBegining(&head,0);
    printList(head);
    insertAtEnd(&third,4);
    printList(head);
/*    
 *=======================================
 * @case: head node has null value
 *=======================================
 */ 
    // Node *four = NULL;
    // insertAtEnd(&four,4);
    // printList(four);
    delete head;
    delete second;
    delete third;
    return 0;
}