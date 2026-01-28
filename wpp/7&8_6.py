class BankAccount:
    def __init__(self, account_number, balance=0.0):
        self.account_number = account_number
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

    def display(self):
        print(f"Account Number: {self.account_number}, Balance: {self.balance}")

account_number = int(input("Enter account number: "))
initial_balance = float(input("Enter initial balance: "))
account = BankAccount(account_number, initial_balance)

while True:
    print("\n1. Deposit funds")
    print("2. Withdraw funds")
    print("3. Display account details")
    print("4. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        amount = float(input("Enter amount to deposit: "))
        if account.deposit(amount):
            print("Deposit successful!")
        else:
            print("Invalid amount. Please try again.")

    elif choice == 2:
        amount = float(input("Enter amount to withdraw: "))
        if account.withdraw(amount):
            print("Withdrawal successful!")
        else:
            print("Invalid amount or insufficient funds. Please try again.")

    elif choice == 3:
        account.display()

    elif choice == 4:
        break

    else:
        print("Invalid choice")
