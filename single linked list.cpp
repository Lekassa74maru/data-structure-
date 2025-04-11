#include <iostream>
#include <string>
using namespace std;

// crate  Class to representing a student node
class Student {
	public:
		int id;        //variable to store  Student ID
		string name;      //variable to store Student name
		int age;          //variable to store Student age
		Student *next;    //variable to store Pointer to the next student node

		// Constructor to initialize a new student node
		Student() {
			id = 0;       // Initialize variable to store id
			age = 0;      // Initialize variable to store age
			next = nullptr; // Initialize  variable to store next pointer
		}

};

// Class to manage the linked list of students
class Student_iniformation {
	private:
		Student *head;    // Pointer to the head of the list

	public:
		// Constructor to initialize an empty student list
		Student_iniformation() : head(nullptr) {}

		// Function to create a new student node
		Student *createNode() {
			Student *st = new Student;
			cout << "Enter student name: ";   // Prompt user to enter name
			cin >> st->name;                  // Input from keybord
			cout << "Enter age: ";            // Prompt user to enter  age
			cin >> st->age;                   // Input from keybord age
			cout << "Enter ID: ";             // Prompt user to enter  ID
			cin >> st->id;                    // Input from keybord ID
			st->next = nullptr;               // Initialize next pointer to be  nullptr
			return st;//return the the enterd information
		}

		// Function to insert a new student at the beginning of the list
		void insert_at_first() {
			Student *st = createNode();       // Create new student node
			st->next = head;                  // Link new node to the existing list
			head = st;                        // Update head to the new node
		}

		// Function to insert a new student at the end of the list
		void insert_at_last() {
			Student *st = createNode();       // Create new student node
			if (head == nullptr) {            // If list is empty
				head = st;                    // Set head to the new node
			} else {
				Student *temp = head;         // Start from the head
				while (temp->next != nullptr) { // Traverse to the last node
					temp = temp->next;
				}
				temp->next = st;              // Link last node to the new node
			}
		}

		// Function to insert a new student after a specific ID
		void insert_by_search(int id) {
			if (head == nullptr) {            // Check if the list is empty
				cout << "No data found!" << endl;
				return;
			}
			cout << " enter id to search from the list\n";
			cin >> id;

			Student *st = head;
			while (st != nullptr) {           // check for while loop
				if (id == st->id) {           // Find node with the matching ID
					Student *newNode = createNode(); // Create new student node
					newNode->next = st->next; // Link new node to the next of current node
					st->next = newNode;       // Link current node to the new node
					cout << "Successfully inserted!" << endl;
					return;
				}
				st = st->next;
			}
			cout << "ID not found!" << endl;  // print this message for  user if ID not found
		}

		// Function to delete the first student node in the list
		void delete_at_first() {
			if (head == nullptr) {            // Check if the list is empty
				cout << "No data found to delete!" << endl;
				return;
			}
			Student *temp = head;             // Temporarily store head node
			head = head->next;                // Move head to the next node
			delete temp;                      // Delete the original head node
			cout << "Successfully deleted!" << endl;
		}

		// Function to delete the last student node in the list
		void delete_at_end() {
			if (head == nullptr) {            // Check if the list is empty
				cout << "No data to delete!" << endl;
				return;
			}
			if (head->next == nullptr) {      // If only one node exists
				delete head;                  // Delete the node
				head = nullptr;               // Set head to nullptr
				return;
			}
			Student *temp = head;             // Start from the head
			while (temp->next->next != nullptr) { // Traverse to the second last node
				temp = temp->next;
			}
			delete temp->next;                // Delete the last node
			temp->next = nullptr;             // Update second last node's next pointer
		}

		// Function to delete a student node by ID
		void delete_by_search(int id) {
			if (head == nullptr) {            // Check if the list is empty
				cout << "No data found!" << endl;
				return;
			}
			cout << "Enter ID to delete: ";
			cin >> id;

			Student *temp = head;// start from heade
			if (temp->id == id) {             // Check if head node has the matching ID
				head = temp->next;            // Update head to the next node
				delete temp;                  // Delete the head node
				cout << "Successfully deleted!" << endl;
				return;
			}

			while (temp->next != nullptr) {   // Traverse the list
				if (temp->next->id == id) {   // Check if next node has the matching with  ID
					Student *t2 = temp->next; // Temporarily store node to delete
					temp->next = t2->next;   // Update current node's next pointer
					delete t2;          // Delete the node
					cout << "Successfully deleted!" << endl;//print this message
					return;
				}
				temp = temp->next;
			}
			cout << "ID not found!" << endl;  // Inform user if ID not found
		}
		// Function to search for a student by their ID
		void search_by_id(int id) {
			if (head == nullptr) { // Check if the list is empty
				cout << "No data found!" << endl;
				return;
			}
			cout << "Enter ID to be delete: ";
			cin >> id;

			Student *temp = head; // Start from the head of the list
			while (temp != nullptr) { // Traverse the list

				if (temp->id == id) { // Check if the current node's ID matches
					// Print the details of the found student
					cout << "Student found!" << endl;
					cout << "Name: " << temp->name << endl;
					cout << "ID: " << temp->id << endl;
					cout << "Age: " << temp->age << endl;
					return;
				}
				temp = temp->next; // Move to the next node
			}
			// If the loop ends without finding the ID
			cout << "ID not found!" << endl;
		}


		// Function to display all student data
		void display_the_list() {
			if (head == nullptr) {            // Check if the list is empty
				cout << "No data available!" << endl;
				return;
			}
			Student *temp = head;   // Start display from the head
			while (temp != nullptr) {         // Traverse the list
				cout << "Name: " << temp->name << endl;// print name
				cout << "ID: " << temp->id << endl;//print id
				cout << "Age: " << temp->age << endl;//print age
				temp = temp->next;
			}
		}
};

int main() {
	Student_iniformation IF;  // Create object for class Student_iniformation
	int choice, id;        // Variable to store user's menu choice and id of student

	do {
		// Display menu options
		cout << "  single linked list" << endl;

		cout << "1: Insert at beginning" << endl;
		cout << "2: Insert at end" << endl;
		cout << "3: Insert by search" << endl;
		cout << "4: Delete at beginning" << endl;
		cout << "5: Delete at end" << endl;
		cout << "6: Delete by search" << endl;
		cout << "7: search for element" << endl;
		cout << "8: Display" << endl;
		cout << "9: Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				IF.insert_at_first();// Call function to insert at first
				break;

			case 2:
				IF.insert_at_last();// Call  function to insert at end of list
				break;
			case 3:

				IF.insert_by_search(id = 0); // Call function insert by search id

				break;
			case 4:
				IF.delete_at_first();      // Call  function to delete at beginning
				break;
			case 5:
				IF.delete_at_end();        // Call function delete at end of list
				break;
			case 6:

				IF.delete_by_search(id); // Call function to delete by search
				break;

			case 7:
				IF.search_by_id(id);        // Call function delete at end of list
				break;

			case 8:

				IF.display_the_list();// Call display function to disply the list
				break;

			case 9:
				cout << "Exiting..." << endl; // Exit program
				break;
			default:
				cout << "Invalid choice!" << endl; // Handle invalid choice
		}
	} while (choice != 9); // Loop until user chooses to exit

	return 0; // Indicate successful program termination
}
