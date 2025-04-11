#include <iostream>
#include <string>
using namespace std;
void insert_at_first();
void insert_last();
void display();
void insert_by_search(int id);
void delete_first();
void delete_end();
void delete_by_search(int id);
void search_by_id(int id);
void display();


// Define a struct to represent a employee (Modified for doubly linked list)
struct employee {
	int id;            // Stores employee ID
	string name;       // Stores employee name
	int age;           // Stores employee age
	employee *next;     // Pointer to the next employee node
	employee *prev;     // Pointer to the previous employee node (Added for doubly linked list)
};

employee *head = NULL; // Initialize head pointer to NULL, representing an empty list

// Function to create a new employee node
employee *createNode() {
	employee *st = new employee; // Allocate memory for a new employee node
	cout << "Enter employee name: "; // Prompt user for employee name
	cin >> st->name; // Input for name
	cout << "Enter age: "; // Prompt user for age
	cin >> st->age; // Input for age
	cout << "Enter ID: "; // Prompt user for ID
	cin >> st->id; // Input for ID
	st->next = NULL; // Set next pointer to NULL
	st->prev = NULL; // Set prev pointer to NULL (Added initialization)
	return st; // Return the created node
}

// Function to insert a employee node at the beginning
void insert_at_first() {
	employee *st = createNode(); // Create a new employee node
	st->next = head; // Link the new node's next pointer to the current head
	if (head != NULL) { // If the list is not empty
		head->prev = st; // Update the previous pointer of the current head
	}
	head = st; // Set the new node as the head of the list
}

// Function to insert a employee node at the end
void insert_last() {
	employee *st = createNode(); // Create a new student node
	if (head == NULL) { // Check if the list is empty
		head = st; // Set the new node as the head
	} else {
		employee *temp = head; // Start traversal from the head
		while (temp->next != NULL) { // Traverse to the last node
			temp = temp->next; // Move to the next node
		}
		temp->next = st; // Link the last node to the new node
		st->prev = temp; // Link the new node's previous pointer to the last node
	}
}

// Function to insert a student node after a specific ID
void insert_by_search(int id) {
	if (head == NULL) { // Check if the list is empty
		cout << "No data found!" << endl; // Inform the user that the list is empty
		return; // Exit the function
	}
	cout << "Enter ID to search: "; // Prompt user for ID
	cin >> id; // Read user input for ID

	employee *temp = head; // Start traversal from the head
	while (temp != NULL) { // Traverse the list
		if (temp->id == id) { // Check if the current node's ID matches the search ID

			employee *newNode = createNode(); // Create a new employee node
			newNode->next = temp->next; // Link the new node's next pointer to the current node's next
			newNode->prev = temp; // Link the new node's previous pointer to the current node
			if (temp->next != NULL) { // If inserting in the middle of the list
				temp->next->prev = newNode; // Update the next node's previous pointer
			}
			temp->next = newNode; // Link the current node to the new node
			cout << "Successfully inserted!" << endl; // Confirm insertion
			return; // Exit the function
		}
		temp = temp->next; // Move to the next node
	}
	cout << "ID not found!" << endl; // Inform the user if the ID is not found
}

// Function to delete the first student node
void delete_first() {
	if (head == NULL) { // Check if the list is empty
		cout << "No data found to delete!" << endl; // Inform the user
		return; // Exit the function
	}
	employee *temp = head; // Temporarily store the head node
	head = head->next; // Move the head pointer to the next node
	if (head != NULL) { // If the list is not empty after deletion
		head->prev = NULL; // Update the previous pointer of the new head
	}
	delete temp; // Delete the original head node
	cout << "Successfully deleted!" << endl; // Confirm deletion
}

// Function to delete the last student node
void delete_end() {
	if (head == NULL) { // Check if the list is empty
		cout << "No data to delete!" << endl; // Inform the user
		return; // Exit the function
	}
	if (head->next == NULL) { // Check if only one node exists
		delete head; // Delete the head node
		head = NULL; // Set head to NULL (list becomes empty)
		return; // Exit the function
	}
	employee *temp = head; // Start traversal from the head
	while (temp->next != NULL) { // Traverse to the last node
		temp = temp->next; // Move to the next node
	}
	temp->prev->next = NULL; // Update the second-to-last node's next pointer to NULL
	delete temp; // Delete the last node
	cout << "Successfully deleted!" << endl; // Confirm deletion
}

// Function to delete a student by ID
void delete_by_search(int id) {
	if (head == NULL) { // Check if the list is empty
		cout << "No data found!" << endl; // Inform the user
		return; // Exit the function
	}
	cout << "Enter ID to search: "; // Prompt user for ID
	cin >> id; // Read user input for ID // Check if the head node has the matching ID

	employee *temp = head; // Start traversal from the head
	if (temp->id == id) {

		head = temp->next; // Update the head pointer
		if (head != NULL) { // If the list is not empty after deletion
			head->prev = NULL; // Update the previous pointer of the new head
		}
		delete temp; // Delete the head node
		cout << "Successfully deleted!" << endl; // Confirm deletion
		return; // Exit the function
	}

	while (temp != NULL) { // Traverse the list
		if (temp->id == id) { // Check if the current node's ID matches the search ID
			temp->prev->next = temp->next; // Update the previous node's next pointer
			if (temp->next != NULL) { // If the node to delete is not the last node
				temp->next->prev = temp->prev; // Update the next node's previous pointer
			}
			delete temp; // Delete the node
			cout << "Successfully deleted!" << endl; // Confirm deletion
			return; // Exit the function
		}
		temp = temp->next; // Move to the next node
	}
	cout << "ID not found!" << endl; // Inform the user if the ID is not found
}



void search_by_id(int id) {
	if (head == NULL) { // Check if the list is empty
		cout << "No data found!" << endl;
		return;
	}
	cout << "Enter ID to  to sarech from the listy: ";
	cin >> id;

	employee *temp = head; // Start from the head of the list
	do {


		if (temp->id == id) { // Check if the current node's ID matches
			// Print the details of the found student
			cout << "employee found!" << endl;
			cout << "Name: " << temp->name << endl;
			cout << "ID: " << temp->id << endl;
			cout << "Age: " << temp->age << endl;
			return; // Exit the function once the student is found
		}
		temp = temp->next; // Move to the next node
	} while (temp != head); // Stop once we circle back to the head

	// If the loop ends without finding the ID, inform the user
	cout << "ID not found!" << endl;
}

// Function to display all student data
void display() {
	if (head == NULL) { // Check if the list is empty
		cout << "No data available!" << endl; // Inform the user
		return; // Exit the function
	}
	employee *temp = head; // Start traversal from the head
	while (temp != NULL) { // Traverse the list
		cout << "Name: " << temp->name << endl; // Display student name
		cout << "ID: " << temp->id << endl; // Display student ID
		cout << "Age: " << temp->age << endl; // Display student age
		temp = temp->next; // Move to the next node
	}
}

// Main function to execute the program
int main() {
	int choice, id = 0; // Variable to store user choice
	do {
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

		switch (choice) { // Execute code based on user choice
			case 1:
				insert_at_first();// Call display function
				break;
			case 2:
				insert_last(); // Call insert-at-first function
				break;
			case 3:
				insert_by_search(id); // Call insert-at-last function
				break;
			case 4:
				delete_first(); // Call delete-at-first function
				break;
			case 5:
				delete_end(); // Call delete-at-last function
				break;
			case 6:
				delete_by_search(id); // Call insert-by-search function
				break;
			case 7:
				search_by_id(id); // Call insert-by-search function
				break;
			case 8:
				display();//call founction to diplay the list
				break;
			case 9:
				cout << "Exiting..." << endl; // Inform user of program exit
				break;
			default:
				cout << "Invalid choice!" << endl; // Handle invalid choice
		}
	} while (choice != 9); // Continue until user chooses to exit

	return 0; // Indicate successful program termination
};
