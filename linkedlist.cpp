#include<iostream>
using namespace std;

 class node{
    public:
    
    int data;
    node *next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

 };

 class linkedList{
    node *head;

public:
linkedList(){
    head = NULL;
}

void insertAtHead(int data){
    node *newNode = new node(data);

    if (head == NULL)
    {
        head=newNode;
    }
    else{
    newNode->next=this->head;
    this->head=newNode;
    }

}

void print(){
    node *temp = head;
    if (temp == NULL)
    {
        cout<<"list is empty";
    }
    while (temp != NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    
}
    bool search(int value) {
        node *temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

void addNodeInMiddle(int data, int afterValue) {
        node *temp = head;
        while (temp != NULL && temp->data != afterValue) {
            temp = temp->next;
        }
        if (temp != NULL) {
            node *newNode = new node(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

void deleteNode(int value) {
        if (head == NULL) return;
        if (head->data == value) {
            node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        node *current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }
        if (current->next != NULL) {
            node *toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
    }
 };



int main(){

    linkedList l1;
    l1.insertAtHead(0);
    l1.insertAtHead(7);
    l1.insertAtHead(5);
    l1.print();
       cout << "\nSearching for 7: " << (l1.search(7) ? "Found" : "Not Found");
    
    l1.addNodeInMiddle(6, 7);
    cout << "\nList after adding 6 after 7: ";
    l1.print();
    
    l1.deleteNode(5);
    cout << "\nList after deleting 5: ";
    l1.print();

    return 0;
}