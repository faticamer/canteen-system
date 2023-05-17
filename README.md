# canteen-system

The program implements a simple canteen system through a console. 

It consists of two modes. 
- S : Setting (manager) mode with 3 available operations
  - Update inventory (name, category, quantity, price) 
  - Generate inventory report (Console or .txt report)
  - Generate sales report (.txt report)

- B : Buyer mode with 3 available options
  - Single item purchase (buyer immediately goes to checkout window after a single purchase)
  - Multi-item purchase (buyer has an option to list all necessary items, then proceed to checkout by pressing 'C')
  - Search-by-category (this option lists all available items within a single category)

NOTE: Setting mode can only be accessed by entering a pre-defined credentials. (username and pass: 'admin')

Program is able to track the inventory in terms of available quantities. When item is out of stock, it is not removed from the list, it is simply unpurchaseable until admin updates the quantity. 

Program keeps track of items that are sold when buyer mode is activated. After each successive purchase in multi-item selection, the purchase details will be appended in .txt report, along with the total profit of all sales. When single item purchase is active, it is possible to inspect the details of .txt report only until the buyer enters new single item purchase session, after which sales report is truncated.

Directory that contains the reports is called canteen-reports. If .txt files are not present, there is no need to manually create them, the program will do it instead.

When buyer mode is activated, after each checkout buyer is asked for required amount for payment. If the amount is less than what the total cost is, the buyer will be returned to the buyer menu, and the quantity buyer took will be re-stocked.

Program is not tolerant on all wrong inputs. Special care should be taken when program expects a certain datatype, and user attempts to enter something else. 

Exceptions to handle these kind of attempts are to be added in the future.

This project is done entirely in C++ as a part of project-distribution period in college.
