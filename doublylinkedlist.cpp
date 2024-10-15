#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node *prev;
    node *next;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class doublyLinkedList{
    node *head;
    public:
    doublyLinkedList(){
        head = NULL;
    } 

   void insertAthead(int data){
    node *newNode = new node(data);

    if(head == NULL)
    {
    head=newNode;
    }
    else{
    newNode->next = head;
    head->prev=newNode;
    head = newNode;
    }
        
   }


 void insertATend(int data){
    node *newNode = new node(data);

if (head == NULL)
{
head = newNode;
return;
}
node *temp = head;
while (temp->next  != NULL)
{
temp = temp->next;
}
temp->next = newNode;
newNode->prev=temp;

 }
   
   
void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
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
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }
    void deleteNode(int value) {
        if (head == NULL) return;
        if (head->data == value) {
            node *toDelete = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete toDelete;
            return;
        }
        node *current = head;
        while (current != NULL && current->data != value) {
            current = current->next;
        }
        if (current != NULL) {
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            delete current;
        }
    }

};




int main(){
    doublyLinkedList dll;
    dll.insertAthead(10);
    dll.insertAthead(20);
    dll.insertATend(30);
    dll.display();
    cout << "\nSearching for 20: " << (dll.search(20) ? "Found" : "Not Found");
    dll.addNodeInMiddle(25, 20);
    cout << "\nList after adding 25 after 20: ";
    dll.display();
    dll.deleteNode(10);
    cout << "\nList after deleting 10: ";
    dll.display();
return 0;


}