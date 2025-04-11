#include <iostream>
#include <string>
using namespace std;

// Define a struct to represent a employee (No changes required)
struct employee {
	int id;            // Stores employee ID
	string name;       // Stores employee name
	int age;           // Stores employee age
	employee *next;     // Pointer to the next employee node
	employee *prev;     // Pointer to the previous employee node
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
	st->prev = NULL; // Set prev pointer to NULL
	return st; // Return the created node
}

// Function to insert a employee node at the beginning
void insert_at_first() {
	employee *st = createNode(); // Create a new employee node
	if (head == NULL) { // Check if the list is empty
		head = st; // Set the new node as the head
		head->next = head; // Make the list circular by pointing to itself
		head->prev = head; // Make the list circular by pointing to itself
	} else {
		employee *tail = head->prev; // Get the last node
		st->next = head; // Link the new node's next pointer to the current head
		st->prev = tail; // Link the new node's prev pointer to the tail
		tail->next = st; // Update the tail's next pointer
		head->prev = st; // Update the head's prev pointer
		head = st; // Set the new node as the head
	}
}

// Function to insert a student node at the end
void insert_at_last() {
	employee *st = createNode(); // Create a new employee node
	if (head == NULL) { // Check if the list is empty
		head = st; // Set the new node as the head
		head->next = head; // Make the list circular by pointing to itself
		head->prev = head; // Make the list circular by pointing to itself
	} else {
		employee *tail = head->prev; // Get the last node
		tail->next = st; // Link the last node's next pointer to the new node
		st->prev = tail; // Link the new node's prev pointer to the last node
		st->next = head; // Link the new node's next pointer to the head
		head->prev = st; // Update the head's prev pointer to the new node
	}

	void insert_by_search(int id) {
		if (head == NULL) { // Check if the list is empty
			cout << "No data found!" << endl; // Inform the user that the list is empty
			return; // Exit the function
		}
		cout << " enter  id to sarech\n";
		cin >> id;

		employee *temp = head; // Start traversal from the head

		do {

			if (temp->id == id) { // Check if the current node's ID matches the search ID
				employee *newNode = createNode(); // Create a new student node
				newNode->next = temp->next; // Link the new node's next pointer to the current node's next
				newNode->prev = temp; // Link the new node's previous pointer to the current node
				temp->next->prev = newNode; // Update the next node's previous pointer
				temp->next = newNode; // Link the current node to the new node
				cout << "Successfully inserted!" << endl; // Confirm insertion
				return; // Exit the function
			}
			temp = temp->next; // Move to the next node
		} while (temp != head); // Continue until we circle back to the head

		cout << "ID not found!" << endl; // Inform the user if the ID is not found
	}


// Function to delete the first student node
	void delete_at_first() {
		if (head == NULL) { // Check if the list is empty
			cout << "No data found to delete!" << endl; // Inform the user
			return; // Exit the function
		}
		employee *temp = head; // Temporarily store the head node
		if (head->next == head) { // Check if there is only one node
			head = NULL; // Set head to NULL (list becomes empty)
		} else {
			employee *tail = head->prev; // Get the last node
			head = head->next; // Move the head pointer to the next node
			head->prev = tail; // Update the head's prev pointer to the tail
			tail->next = head; // Update the tail's next pointer to the head
		}
		delete temp; // Delete the original head node
		cout << "Successfully deleted!" << endl; // Confirm deletion
	}

// Function to delete the last employee node
	void delete_at_end() {
		if (head == NULL) { // Check if the list is empty
			cout << "No data to delete!" << endl; // Inform the user
			return; // Exit the function
		}
		employee *temp = head->prev; // Get the last node
		if (head->next == head) { // Check if there is only one node
			head = NULL; // Set head to NULL
		} else {
			employee *second_last = temp->prev; // Get the second-to-last node
			second_last->next = head; // Update the second-to-last node's next pointer to head
			head->prev = second_last; // Update the head's prev pointer to the second-to-last node
		}
		delete temp; // Delete the last node
		cout << "Successfully deleted!" << endl; // Confirm deletion
	}

// Function to delete a student by ID
	void delete_by_search(int id) {

		if (head == NULL) { // Check if the list is empty
			cout << "No data found!" << endl; // Inform the user
			return; // Exit the function
		}
		cout << "Enter ID to delete: ";
		cin >> id;
		employee *temp = head; // Start traversal from the head
		do {

			if (temp->id == id) { // Check if the current node's ID matches the search ID
				if (temp == head && temp->next == head) { // Handle case where the single node is to be deleted
					head = NULL; // Empty the list
				} else {
					employee *prev = temp->prev; // Get the previous node
					employee *next = temp->next; // Get the next node
					prev->next = next; // Update the previous node's next pointer
					next->prev = prev; // Update the next node's prev pointer
					if (temp == head) { // If the head is to be deleted
						head = next; // Update head pointer
					}
				}
				delete temp; // Delete the node
				cout << "Successfully deleted!" << endl; // Confirm deletion
				return; // Exit the function
			}
			temp = temp->next; // Move to the next node
		} while (temp != head); // Continue traversal in a circular manner
		cout << "ID not found!" << endl; // Inform the user if the ID is not found
	}


	void search_by_id(int id) {
		if (head == NULL) { // Check if the list is empty
			cout << "No data found!" << endl;
			return;
		}
		cout << "Enter ID to  to sarech from the list: ";
		cin >> id;

		employee *temp = head; // Start from the head of the list
		do {


			if (temp->id == id) { // Check if the current node's ID matches
				// Print the details of the found employee
				cout << "employee found!" << endl;
				cout << "Name: " << temp->name << endl;
				cout << "ID: " << temp->id << endl;
				cout << "Age: " << temp->age << endl;
				return; // Exit the function once the employee is found
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
		do {
			cout << "Name: " << temp->name << endl; // Display employee name
			cout << "ID: " << temp->id << endl; // Display employee ID
			cout << "Age: " << temp->age << endl; // Display employee age
			temp = temp->next; // Move to the next node
		} while (temp != head); // Continue traversal in a circular manner
	}

// Main function with all menu options implemented
	int main() {
		int choice, id; // Variable to store user choice
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

			switch (choice) {
				// Execute code based on user choice
				case 1:
					insert_at_first(); // Call insert-at-first function

					break;
				case 2:
					insert_at_last(); // Call insert-at-last function
					break;
				case 3:
					// Read user input for ID
					insert_by_search(id);// Call insert by search function
					break;
				case 4:
					delete_at_first(); // Call delete-at-first function
					break;
				case 5:
					delete_at_end(); // Call delete-at-last function
					break;
				case 6:

					delete_by_search(id); // Call delete-by-search function
					break;
				case 7:

					search_by_id(id);
					break;
				case 8:
					display(); // Call display function
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
