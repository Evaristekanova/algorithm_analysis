#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

struct node {
  int data;
  node *next;
};

class LinkedList
{
    // Head and Tail pointers
    node* head;
    node* tail;

  public:
    // default constructor. Initializing head pointer
    LinkedList()
    {
      head = NULL;
      tail = NULL;
    }

    // Parameterized constructor
    LinkedList(int size, LinkedList &list){

    	srand(time(0));

    	for (int i=0; i < size; i++){
    	list.insertAtStart(rand() % 20);

		}

	}

	// Operator overloading
	void operator = (const LinkedList &li){
		this->head = li.head;
		this->tail = tail;
	}

    //Linked list destructor
    ~LinkedList(){
	node *current = new node;
	current = head;

	while(current != NULL){
		delete current;
		current = current->next;
	}
};


    //Inserting at the start of the list
    void insertAtStart(int val) {
      node* temp = new node();
      temp->data = val;
      temp->next = head;
      head = temp;
    }

    void insertAtEnd(int val){

      node *temp=new node ();
      temp->data=val;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      
      else{
      	node *newNode = head;
      	while(newNode->next != NULL){
      		newNode = newNode->next;
		  }
		  
		  newNode->next = temp;
		  tail = temp;
	  }

}

    // Search function, loop over function and return true if the value is found
    bool search(int val)
    {
      node* temp = head;
      while(temp != NULL)
      {
        if (temp->data == val){
          // return true;
          cout<<"Value "<<val<<" is available in the list"<<endl;
          return true;
          cout<<endl;
        }
        temp = temp->next;
      }
      // return false;
        cout<<"Value "<<val<<" is not available in the list"<<endl;

    }

        void deleteItem(int val)
    {
      // If the head is to be deleted
      if (head->data == val)
      {
        delete head;
        head = head->next;
        return;
      }

      // If there is only one element in the list
      if (head->next == NULL)
      {
        // If the head is to be deleted. Assign null to the head
        if (head->data == val)
        {
          delete head;
          head = NULL;
          return;
        }
        // else print, value not found
        cout << "Value not available!" << endl;
        return;
      }

      // Else loop over the list and search for the node to delete
      node* temp = head;
      while(temp->next!= NULL)
      {
        // When node is found, delete the node and modify the pointers
        if (temp->next->data == val)
        {
          node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          return;
        }
        temp = temp->next;
      }

      // Else, the value was neve in the list
      cout << "Value not available" << endl;
    }

    //List elements of the singly linked list
        void display()
{
	node* temp = head;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

    /* Function to reverse the linked list */
    void reverseList()
    {
        // Initialize current, previous and next pointers
        node* current = head;
        node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    //removeDuplicate() will remove duplicate nodes from the list
void removeDuplicate() {
    //Node current will point to head
    struct node *current = head, *index = NULL, *temp = NULL;

    if(head == NULL) {
        return;
    }
    else {
        while(current != NULL){
            //Node temp will point to previous node to index.
            temp = current;
            //Index will point to node next to current
            index = current->next;

            while(index != NULL) {
                //If current node's data is equal to index node's data
                if(current->data == index->data) {
                    //Here, index node is pointing to the node which is duplicate of current node
                    //Skips the duplicate node by pointing to next node
                    temp->next = index->next;
                }
                else {
                    //Temp will point to previous node of index.
                    temp = index;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
};


int main(){
	LinkedList listInit, list;
	int valSize, valStart, valEnd, valSearch,valDelete, i, c;

	cout<<"Please Enter the size of your linked list: ";
	cin>>valSize;
	LinkedList(valSize, list);
	list.display();
  cout<<"\n";
//	cout<<"We begin to manipulate our linkedlist!"<<endl;
 cout<"\n";
  cout<<"Enter number to be inserted at the start of list:";
	cin>>valStart;
	list.insertAtStart(valStart);
	cout<<"\nLinked list after inserting "<<valStart<<" at the start!: ";
	list.display();
	cout<"\n";
   cout<<"\nEnter number to be inserted at the end of list:";
   cin>>valEnd;
   list.insertAtEnd(valEnd);
	 cout<<"\nLinked list after inserting "<<valEnd<<" at the start!: ";
   list.display();
	cout<"\n";
  // searching if item is in the list
  cout<<"\nEnter number to search in the list:";
  cin>>valSearch;
  list.search(valSearch);
	cout<"\n";
  // DELETING ITEM IN THE LIST
  cout<<"\nEnter number to be deleted in the list:";
  cin>>valDelete;
  list.deleteItem(valDelete);
  list.display();
  cout<"\n";
  cout<<"\n Do you want to reverse linked list:"<<endl;
  cout<<"\nPress 1 to reverse or zero to skip:";
  cin>>i;
  if(i == 1){
    list.reverseList();
    cout<<"\nThe reversed lilnked list: ";
	list.display();
  }
  else{
    cout<<"\nUnrreversed linked list: ";
	list.display();
  }
  cout<"\n";
  cout<<"\nRemove duplicate in list:";
	cout<<"\nDo you want to remove duplicate?";
	cout<<"\nEnter 1 to remove duplicate:";
	cin>>c;
	if(c == 1){
	  list.removeDuplicate();
	  list.display();
	}
	else{
		list.display();
	}
	return 0;
}
