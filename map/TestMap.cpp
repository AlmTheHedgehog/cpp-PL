#include "Employee.h"													// Defines class Employee
#include "Map.h"
#include "Book.h"												// Defines template Map<Key, Value>
#include <iostream>

//  check all EXCEPTIONS!

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees
typedef Map<ID, Book> BooksDB; 	

using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);

void addBooks(BooksDB& booksSh);
void modifyBooks(BooksDB& booksSh);

void checkEmpDB(Database& database);
void checkBooksDB(BooksDB& booksSh);

int main() {
	Database database;
	checkEmpDB(database);

	BooksDB newDB;
	checkBooksDB(newDB);
};

void checkEmpDB(Database& database){
	addEmployees(database);

	Database newDatabase = database;
	try{									// Make a copy of database
		newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	}catch(ElementAlreadyExistsException&){
		cout << "element 830505432 already exicts" << endl;
	}

	modifyEmployees(newDatabase);
	
	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:" << endl << database << endl;
}

void checkBooksDB(BooksDB& booksSh){
	
	cout << "New DB with main numbers:" << endl << booksSh << endl;

	try{									// Make a copy of database
		addBooks(booksSh);
	}catch(ElementAlreadyExistsException&){
		cout << "some of adding func in modifyEmployees return unhandelled exception" << endl;
	}

	try{
		modifyBooks(booksSh);
	}catch(ElementAlreadyExistsException&){
		cout << "some of elements exist" << endl;
	}

	cout << "Modified database:" << endl << booksSh << endl;
}

void addEmployees(Database& database) {
	try{
		database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	}catch(ElementAlreadyExistsException&){
		cout << "761028073 - EXISTS ALREADY" << endl;
	}
	try{
		database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	}catch(ElementAlreadyExistsException&){
		cout << "510212881 - EXISTS ALREADY" << endl;
	}
	try{
		database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
	}catch(ElementAlreadyExistsException&){
		cout << "730505129 - EXISTS ALREADY" << endl;
	}

	try{
		database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
	}catch(ElementAlreadyExistsException&){
		cout << "730505129 - EXISTS ALREADY" << endl;
	}
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	try{
		employeePtr = database.find(510212881);								// Find employee using its ID
		employeePtr->position = "salesman";									// Modify the position of employee
	}catch(ElementNotFoundException&){
		cout << "Can`t find 510212881" << endl;
	}

	try{
		employeePtr = database.find(761028073);								// Find employee using its ID
		employeePtr->age = 29;											// Modify the age of employee
	}catch(ElementNotFoundException&){
		cout << "Can`t find 761028073" << endl;
	}
}

void addBooks(BooksDB& booksSh){
	try{
		booksSh.add(345687654, Book("Runner", "New Author", "Horror", 52, false ));
	}catch(ElementAlreadyExistsException&){
		cout << "345687654 - EXISTS ALREADY" << endl;
	}
	try{
		booksSh.add(324855547, Book("The bed is bad", "Bob Dealan", "Strange", 265, true ));
	}catch(ElementAlreadyExistsException&){
		cout << "345687654 - EXISTS ALREADY" << endl;
	}
	try{
		booksSh.add(545874518, Book("My journey", "Jiin", "Searcher", 85, true ));
	}catch(ElementAlreadyExistsException&){
		cout << "345687654 - EXISTS ALREADY" << endl;
	}
}

void modifyBooks(BooksDB& booksSh){
	Book* bookPtr;
	try{	
		bookPtr = booksSh.find(324855547);								// Find employee using its ID
		bookPtr->category = "Other";									// Modify the position of employee
	}catch(ElementNotFoundException&){
		cout << "Can`t find 324855547" << endl;
	}

	try{	
		bookPtr = booksSh.find(485485454);								// Find employee using its ID
		bookPtr->category = "Horror";									// Modify the position of employee
	}catch(ElementNotFoundException&){
		cout << "Can`t find 485485454" << endl;
	}

	try{
		bookPtr = booksSh.find(545874518);								// Find employee using its ID
		bookPtr->author = "Gigin";											// Modify the age of employee
	}catch(ElementNotFoundException&){
		cout << "Can`t find 545874518" << endl;
	}
}