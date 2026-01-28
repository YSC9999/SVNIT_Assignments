class Customer:
    def __init__(self, account_number, name, balance=0.0):
        self.account_number = account_number
        self.name = name
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            return True
        return False

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            return True
        return False

    def get_balance(self):
        return self.balance

    def __str__(self):
        return f"Account Number: {self.account_number}, Name: {self.name}, Balance: {self.balance}"


class Bank:
    def __init__(self):
        self.customers = {}

    def add_customer(self, account_number, name, balance=0.0):
        if account_number not in self.customers:
            self.customers[account_number] = Customer(account_number, name, balance)
            return True
        return False

    def remove_customer(self, account_number):
        if account_number in self.customers:
            del self.customers[account_number]
            return True
        return False

    def get_customer(self, account_number):
        return self.customers.get(account_number, None)

    def display_customers(self):
        for customer in self.customers.values():
            print(customer)

bank = Bank()
while True:
    print("\n1. Add Customer")
    print("2. Remove Customer")
    print("3. Deposit")
    print("4. Withdraw")
    print("5. Display Customers")
    print("6. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        account_number = int(input("Enter account number: "))
        name = input("Enter customer name: ")
        balance = float(input("Enter initial balance: "))
        if bank.add_customer(account_number, name, balance):
            print("Customer added successfully!")
        else:
            print("Account number already exists!")

    elif choice == 2:
        account_number = int(input("Enter account number to remove: "))
        if bank.remove_customer(account_number):
            print("Customer removed successfully!")
        else:
            print("Account number not found!")

    elif choice == 3:
        account_number = int(input("Enter account number: "))
        amount = float(input("Enter amount to deposit: "))
        customer = bank.get_customer(account_number)
        if customer and customer.deposit(amount):
            print("Deposit successful!")
        else:
            print("Deposit failed!")

    elif choice == 4:
        account_number = int(input("Enter account number: "))
        amount = float(input("Enter amount to withdraw: "))
        customer = bank.get_customer(account_number)
        if customer and customer.withdraw(amount):
            print("Withdrawal successful!")
        else:
            print("Withdrawal failed!")

    elif choice == 5:
        bank.display_customers()

    elif choice == 6:
        break

    else:
        print("Invalid choice")
