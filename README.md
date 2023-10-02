# Financial Transaction Control System in C

This is a project for developing a financial transaction control system in the C programming language. The system is designed to allow the registration of clients, accounts, and financial transactions, providing financial management functionalities. This was the final work proposed in a programming course at UFG. I had finished this work some time ago, but I only now created a README for it. I'm posting it the way it concluded at the time.

## Key Features

The system includes the following key features:

1. **Client Management**
   - Registration of clients with code, name, CNPJ/CPF, phone number, and address.
   - Listing of all registered clients in alphabetical order.
   - Searching for clients by name, code, or CPF/CNPJ.
   - Updating information for existing clients.
   - Deletion of registered clients.

2. **Account Management**
   - Registration of accounts linked to clients with agency and account number.
   - Listing of all registered accounts in alphabetical order of the client's name and in descending order of the account balance.
   - Listing accounts for a specific client.
   - Conducting withdrawals from accounts with transaction recording.
   - Conducting deposits into accounts with transaction recording.
   - Transferring funds between accounts with transaction recording.
   - Displaying an account's transaction history for a specified period.

## System Requirements

To run the system, you need a C development environment compatible with your operating system. Ensure you have a C compiler configured and ready for use.

## How to Run the System

1. Clone this repository to your local machine.
2. Navigate to the project directory
3. Compile the system's source code
4. Execute the system

The system will start, and you will be presented with the main menu. Follow the menu instructions to access different functionalities.

## Additional Notes

- The system allows the registration of up to 100 clients, 200 accounts, and 1,000 transactions.

This system was developed as part of an academic project and can serve as a foundation for future developments. Feel free to make improvements or customizations as needed.

If you have any questions or encounter problems, please don't hesitate to get in touch.

**Developed by: [Lucas Reis]**