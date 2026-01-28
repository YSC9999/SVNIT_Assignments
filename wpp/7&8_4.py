class Employee:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

    def __add__(self, other):
        return self.salary + other.salary

    def __sub__(self, other):
        return self.salary - other.salary

    def __str__(self):
        return f"Employee(Name: {self.name}, Salary: {self.salary})"

employees = []
while True:
    print("\n1. Add Employee")
    print("2. Combine Salaries")
    print("3. Compare Salaries")
    print("4. Display Employees")
    print("5. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        name = input("Enter employee name: ")
        salary = float(input("Enter employee salary: "))
        employee = Employee(name, salary)
        employees.append(employee)
        print(f"Employee {name} added successfully!")

    elif choice == 2:
        if len(employees) < 2:
            print("At least two employees are required to combine salaries.")
        else:
            emp1_index = int(input("Enter index of first employee (0-based): "))
            emp2_index = int(input("Enter index of second employee (0-based): "))
            if emp1_index < len(employees) and emp2_index < len(employees):
                combined_salary = employees[emp1_index] + employees[emp2_index]
                print(f"Combined Salary: {combined_salary}")
            else:
                print("Invalid employee indices!")

    elif choice == 3:
        if len(employees) < 2:
            print("At least two employees are required to compare salaries.")
        else:
            emp1_index = int(input("Enter index of first employee (0-based): "))
            emp2_index = int(input("Enter index of second employee (0-based): "))
            if emp1_index < len(employees) and emp2_index < len(employees):
                salary_difference = employees[emp1_index] - employees[emp2_index]
                print(f"Salary Difference: {salary_difference}")
            else:
                print("Invalid employee indices!")

    elif choice == 4:
        for i, employee in enumerate(employees):
            print(f"{i}: {employee}")

    elif choice == 5:
        break

    else:
        print("Invalid choice")