## Documentation

An online shopping cart is software that makes it possible for customers to select products and buy them online.

### Purpose
The purpose of an online shopping cart system is to facilitate and streamline the process of purchasing goods or services over the internet.
### Main Function:
Creates an empty vector cart to hold the items.
Calls loadCartFromFile(cart) to load any existing cart data from the file into the vector.
Enters a loop to display the menu, get user input, and execute the corresponding action until the user chooses to exit.
Inside the loop, based on the user's choice, it calls the appropriate function (addItem, viewCart, updateItem, removeItem, saveCartToFile) or displays an error message for invalid choices.
Once the user chooses to exit (option 5), it saves the cart data to the file using saveCartToFile(cart) and exits the program.

### Data Structures Employed
- The saveCartToFile() function writes the item details (name, price, quantity) from the cart vector to a text file named cart.txt.
The loadCartFromFile() function reads item details from the cart.txt file and populates the cart vector with these details, if the file exists.

### How to Use the Software
1. **Compilation and Setup**:
   - Clone the repository.
   - Compile the source code using a C++ compiler.
2. **Running the Program**:
   - Execute the compiled program.
3. **Menu Options**:
   - **Adds an item to the cart. (1)**
   - **Displays the items in the cart. (2)**
   - **Updates the quantity of an item in the cart (3)**
   - **Removes an item from the cart. (4)**
   - **Saves the cart data to a file. (5)**

