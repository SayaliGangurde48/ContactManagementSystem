#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Contact {
public:
    Contact(const string& name, const string& phone)
        : name(name), phone(phone) {}

    void display() const {
        cout << "Name: " << name << ", Phone: " << phone << endl;
    }

    string getName() const {
        return name;
    }

private:
    string name;
    string phone;
};

class ContactManager {
public:
    void addContact(const string& name, const string& phone) {
        contacts.emplace_back(name, phone);
        cout << "Contact added: " << name << endl;
    }

    void displayContacts() const {
        if (contacts.empty()) {
            cout << "No contacts available." << endl;
            return;
        }
        for (const auto& contact : contacts) {
            contact.display();
        }
    }

    void deleteContact(const string& name) {
        auto it = remove_if(contacts.begin(), contacts.end(),
            [&name](const Contact& contact) {
                return contact.getName() == name;
            });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact '" << name << "' deleted." << endl;
        } else {
            cout << "Contact '" << name << "' not found." << endl;
        }
    }

private:
    vector<Contact> contacts;
};

int main() {
    ContactManager manager;
    int choice;
    string name, phone;

    do {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Delete Contact\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone: ";
                cin >> phone;
                manager.addContact(name, phone);
                break;
            case 2:
                manager.displayContacts();
                break;
            case 3:
                cout << "Enter name of the contact to delete: ";
                cin >> name;
                manager.deleteContact(name);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
