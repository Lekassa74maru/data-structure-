#include <iostream>
#include <string>
using namespace std;

// Class representing a student node
class Student {
	public:
		int id;        // vriable to store tudent ID
		string name;   //vriable to store  Student name
		int age;       //vriable to store  Student age
		Student *next; // Pointer to the next student node

		// Constructor to initialize a new student node
		Student() {
			id = 0;         //vriable to store and Initialize id
			age = 0;        //vriable to store and Initialize age
			next = nullptr; //vriable to store and Initialize next
		}
};

// Class to manage the  list of students
class Student_information {
	private:
		Student *head; //creat Pointer to the head of the list

	public:
		// Constructor to initialize an empty student list
		Student_information() : head(nullptr) {}

		// Function to create a new student node
		Student *createNode() {
			Student *st = new Student;
			cout << "Enter student name: ";
			cin >> st->name;          // Input name
			cout << "Enter age: ";
			cin >> st->age;           // Input age
			cout << "Enter ID: ";
			cin >> st->id;            // Input ID
			st->next = nullptr;       // Initialize next pointer to nullptr
			return st;
		}

		// Function to insert a new student at the beginning of the list
		void insert_at_first() {
			Student *st = createNode(); // Create new student node
			if (head == nullptr) {      // If list is empty
				head = st;
				st->next = head;        // Point new node to itself (circular list)
			} else {
				Student *temp = head;
				while (temp->next != head) { // Traverse to the last node
					temp = temp->next;
				}
				st->next = head;            // Link new node to the existing list
				temp->next = st;            // Update last node's next pointer
				head = st;                  // Update head to the new node
			}
		}

		// Function to insert a new student at the end of the list
		void insert_at_last() {
			Student *st = createNode(); // Create new student node
			if (head == nullptr) {      // If list is empty
				head = st;
				st->next = head;        // Point new node to itself (circular list)
			} else {
				Student *temp = head;
				while (temp->next != head) { // Traverse to the last node
					temp = temp->next;
				}
				temp->next = st;            // Link last node to the new node
				st->next = head;            // Point new node to the head
			}
		}

		// Function to insert a new student after a specific ID
		void insert_by_search(int id) {
			if (head == nullptr) {
				cout << "No data found!" << endl;
				return;
			}
			cout << "Enter ID to search: ";
			cin >> id;

			Student *temp = head;
			do {
				if (temp->id == id) { // Find node with the matching ID
					Student *newNode = createNode();//create new nod
					newNode->next = temp->next;//assingn new node next on temporary memory
					temp->next = newNode; // Link current node to the new node
					cout << "Successfully inserted!" << endl;
					return;
				}
				temp = temp->next;//pass to next node affter id is much
			} while (temp != head);
			cout << "ID not found!" << endl;
		}

		// Function to delete the first student node in the list
		void delete_at_first() {
			if (head == nullptr) {
				cout << "No data found to delete!" << endl;
				return;
			}
			Student *temp = head;
			if (head->next == head) { //if  Only one node exists
				head = nullptr;       // Set head to nullptr
				delete temp;          // Delete the node
			} else {
				Student *last = head;//creat pointer to store head
				while (last->next != head) { // Traverse to the last node
					last = last->next;//pass to next node up to the last to chacke last node is connected to the frist node scince it is circular
				}
				head = head->next; // Update head to the next node
				last->next = head; // Update last node's next pointer
				delete temp;       // Delete the original head node
			}
			cout << "Successfully deleted!" << endl;
		}

		// Function to delete the last student node in the list
		void delete_at_end() {
			if (head == nullptr) {
				cout << "No data to delete!" << endl;
				return;
			}
			if (head->next == head) { // Only one node exists
				delete head;          // Delete the node
				head = nullptr;       // Set head to nullptr
				return;
			}
			Student *temp = head;
			while (temp->next->next != head) { // Traverse to the second last node
				temp = temp->next;
			}
			delete temp->next;       // Delete the last node
			temp->next = head;       // Update second last node's next pointer
			cout << "Successfully deleted!" << endl;
		}

		// Function to delete a student node by ID
		void delete_by_search(int id) {
			if (head == nullptr) { // Check if the list is empty
				cout << "No data found!" << endl;
				return;
			}
			cout << " enter id to search delete id\n";
			cin >> id;

			Student *temp = head;
			Student *prev = nullptr;

			// Special case: head node matches the ID
			if (head->id == id) {
				if (head->next == head) { // Only one node exists
					delete head;
					head = nullptr; // Set head to null
				} else {
					Student *last = head;
					while (last->next != head) { // Traverse to the last node
						last = last->next;
					}
					last->next = head->next; // Update last node's next pointer
					delete head;             // Delete the head node
					head = last->next;       // Update head pointer
				}
				cout << "Successfully deleted!" << endl;
				return;
			}

			do { // Traverse the circular list
				if (temp->next->id == id) {
					Student *t2 = temp->next; // Temporarily store node to delete
					temp->next = t2->next;   // Update current node's next pointer
					delete t2;               // Delete the node
					cout << "Successfully deleted!" << endl;
					return;
				}
				temp = temp->next; // Move to the next node
			} while (temp != head); // Continue traversal until back at the head

			cout << "ID not found!" << endl; // If ID not found in the list
		}


		// Function to search for a student by their ID
		void search_by_id(int id) {
			if (head == nullptr) { // check for head is null
				cout << "No data found!" << endl;//if above if condtion is true
				return;
			}
			cout << "Enter ID to search: ";//if the list of data is inforce user to enter search key
			cin >> id;//input for search key

			Student *temp = head;//creat temporary pointer
			do {
				if (temp->id == id) { //check for id is much
					// Print the details of the found student
					cout << "Student found!" << endl;
					cout << "Name: " << temp->name << endl;
					cout << "ID: " << temp->id << endl;
					cout << "Age: " << temp->age << endl;
					return;
				}
				temp = temp->next;//go to next node
			} while (temp != head);//control the loop
			cout << "ID not found!" << endl;//if id is not much
		}

		// Function to display all student data
		void display_the_list() {
			if (head == nullptr) { //check head is null
				cout << "No data available!" << endl;//if no list of data is not present
				return;
			}
			Student *temp = head;//creat temporary memor to store head
			do {
				cout << "Name: " << temp->name << endl;
				cout << "ID: " << temp->id << endl;
				cout << "Age: " << temp->age << endl;
				temp = temp->next;
			} while (temp != head);//control the loop until head is equal to null
		}
};

int main() {
	Student_information IF;  // Create instance of StudentList
	int choice, id;        // Variable to store user's menu choice

	do {
		// Display menu options
		cout << " circular single linked list" << endl;
		cout << "1: Insert at beginning" << endl;
		cout << "2: Insert at end" << endl;
		cout << "3: Insert by search" << endl;
		cout << "4: Delete at beginning" << endl;
		cout << "5: Delete at end" << endl;
		cout << "6: Delete by search" << endl;
		cout << "7: Search by ID" << endl;
		cout << "8: Display" << endl;
		cout << "9: Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				IF.insert_at_first();
				break;
			case 2:
				IF.insert_at_last();
				break;
			case 3: {
				IF.insert_by_search(id = 0);
				break;
			}
			case 4:
				IF.delete_at_first();
				break;
			case 5:
				IF.delete_at_end();
				break;
			case 6:
				IF.delete_by_search(id);
				break;

			case 7:
				IF.search_by_id(id);
				break;

			case 8:
				IF.display_the_list();
				break;
			case 9:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid choice!" << endl;

		}


	} while (choice != 9); // Loop until user chooses to exit
	return 0; // Indicate successful program termination
}