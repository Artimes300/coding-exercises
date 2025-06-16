#include <iostream>
using namespace std;
struct Node{
    int data;
	Node* next, * prev; //Pointer to next and previous node
};
void addNewNode(Node*& head, Node*& tail, int value) { //Yeni node oluşturma, başa ve sona ekleme...
	Node* newNode = new Node();
	newNode->data = value;
	
	if (head == nullptr) {
		tail = head = newNode; // If the list is empty, set both head and tail to the new node
		newNode->next = newNode->prev = nullptr; // Next and previous pointers are null
	}
	else{
		cout << "Adding value at the beggining ->select 1" << endl;
		cout << "Adding value at the end ->select 2" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			head->prev = newNode; // Set the previous pointer of the current head to the new node
			newNode->next = head; // Set the next pointer of the new node to the current head
			newNode->prev = nullptr; // The new node's previous pointer is null
			head = newNode; // Update head to the new node
		}
		else if (choice == 2) {
			tail->next = newNode; // Set the next pointer of the current tail to the new node
			newNode->prev = tail; // Set the previous pointer of the new node to the current tail
			newNode->next = nullptr; // The new node's next pointer is null
			tail = newNode; // Update tail to the new node
		}
		else {
			cout << "Invalid choice. Please select 1 or 2." << endl;
			delete newNode; // Clean up the allocated memory if the choice is invalid
			return;
		}

	}

}
void delete_node(Node*& tail, Node *& head) {
	//Son node silme işlemi
	if (tail == nullptr) {
		cout << "There is no node at the doubly linked list!" << endl;
		return;
	}
	else if (head == tail) {
		delete head; // If there's only one node, delete it
		head = tail = nullptr;
	}
	else {
		Node* toDelete = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete toDelete;
	}
	cout << "Last node deleted successfully!" << endl;
}
void reverse(Node*& head, Node*& tail) {
	if (head == nullptr || head == tail) return; // If the list is empty or has only one node, no need to reverse
	Node* current = head;
	Node* temp = nullptr;

	while (current != nullptr) {
		// prev ve next'i yer değiştir
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;

		current = current->prev; // bir önceki düğüme git (önceki = eski next)
	}

	// temp en son NULL olduğu için temp->prev yeni head olur
	if (temp != nullptr)
		head = temp->prev;

	// tail'i yeniden bul
	tail = head;
	while (tail && tail->next != nullptr)
		tail = tail->next;
	
}


int main() {
	cout << "Doubly Linked List Example" << endl;
	Node* head = nullptr, * tail = nullptr;
	int choice, value;
	bool key = true;	
	while (key) {
		cout << "Enter your choice for 1:Adding, 2:Delete, 3:Display, 4:Reversing, 5:Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Enter value to add: ";
			cin >> value;
			addNewNode(head, tail, value);
		}
		else if (choice == 2) {
			cout << "Deleting the last node" << endl;
			delete_node(tail, head);
		}
		else if (choice == 3) {
			if (head == nullptr) {
				cout << "The list is empty!" << endl;
			}
			else {
				Node* current = head;
				cout << "Doubly Linked List: ";
				while (current != nullptr) {
					cout << current->data << " ";
					current = current->next;
				}
				cout << endl;
			}
		}
		else if (choice == 4) {
			if (head == nullptr) {
				cout << "The list is empty!" << endl;
			}
			else {
				cout << "Reversing the list..." << endl;
				reverse(head, tail);
			}
		}
		else {
			cout << "Exiting the program." << endl;
			key = false; // Exit the loop
		}
		// Program bitince tüm düğümleri sil
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
}
