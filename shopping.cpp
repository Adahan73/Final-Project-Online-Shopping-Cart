#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Define a structure for the item
struct Item {
    string name;
    float price;
    int quantity;
};

// Function to display the menu
void displayMenu() {
    cout << "1. Add item to cart" << endl;  // Add an item to the cart
    cout << "2. View cart" << endl;  // View the items in the cart
    cout << "3. Update item quantity" << endl;  // Update the quantity of an item in the cart
    cout << "4. Remove item from cart" << endl;  // Remove an item from the cart
    cout << "5. Exit" << endl;  // Save cart data to a file
    cout << "Enter your choice: ";  // Load cart data from a file

}

// Function to add an item to the cart
void addItem(vector<Item> &cart) {
    Item newItem;
    cout << "Enter item name: ";
    cin >> newItem.name;
    cout << "Enter item price: ";
    cin >> newItem.price;
    cout << "Enter item quantity: ";
    cin >> newItem.quantity;
    cart.push_back(newItem);
    cout << "Item added to cart successfully!" << endl;
}

// Function to display the cart
void viewCart(const vector<Item> &cart) {
    if (cart.empty()) {
        cout << "Cart is empty" << endl;
    } else {
        cout << "Items in cart:" << endl;
        for (const auto &item : cart) {
            cout << item.name << " - $" << item.price << " - Quantity: " << item.quantity << endl;
        }
    }
}

// Function to update item quantity in the cart
void updateItem(vector<Item> &cart) {
    string itemName;
    cout << "Enter the name of the item to update: ";
    cin >> itemName;
    for (auto &item : cart) {
        if (item.name == itemName) {
            cout << "Enter new quantity: ";
            cin >> item.quantity;
            cout << "Quantity updated successfully!" << endl;
            return;
        }
    }
    cout << "Item not found in cart!" << endl;
}

// Function to remove item from the cart
void removeItem(vector<Item> &cart) {
    string itemName;
    cout << "Enter the name of the item to remove: ";
    cin >> itemName;
    for (auto it = cart.begin(); it != cart.end(); ++it) {
        if (it->name == itemName) {
            cart.erase(it);
            cout << "Item removed from cart successfully!" << endl;
            return;
        }
    }
    cout << "Item not found in cart!" << endl;
}

// Function to save cart data to file
void saveCartToFile(const vector<Item> &cart) {
    ofstream file("cart.txt");
    if (file.is_open()) {
        for (const auto &item : cart) {
            file << item.name << "," << item.price << "," << item.quantity << endl;
        }
        file.close();
    } else {
        cout << "Error: Unable to save cart data to file!" << endl;
    }
}

// Function to load cart data from file
void loadCartFromFile(vector<Item> &cart) {
    ifstream file("cart.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Item newItem;
            size_t pos = line.find(',');
            newItem.name = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(',');
            newItem.price = stof(line.substr(0, pos));
            line.erase(0, pos + 1);
            newItem.quantity = stoi(line);
            cart.push_back(newItem);
        }
        file.close();
    } else {
        cout << "No existing cart data found." << endl;
    }
}

int main() {
    vector<Item> cart;
    loadCartFromFile(cart);  // Load existing cart data from file

    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addItem(cart);
                break;
            case 2:
                viewCart(cart);
                break;
            case 3:
                updateItem(cart);
                break;
            case 4:
                removeItem(cart);
                break;
            case 5:
                saveCartToFile(cart);
                cout << "Exiting..." << endl;  // Save cart data to file before exiting
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
