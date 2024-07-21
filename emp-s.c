/**
 * C program that illustrates an Employee payroll system
 * that calculates employees salaries based on hours worked, 
 * hourly rate and taxes 
 *
 * Upon success return 0 with final result else, -1 with error message
 */

// payroll system data structure
Payroll system struct {
	Employee employees;
	int num employees;
}

// employee data structure
Employee struct {
	employee_id int;
	name char[100];
	hourly_rate float;
	hours_worked double;
	salary float;
}

//Tax rate data structure
Tax rate struct {
	tax_rate float;
}

Payroll system payr_sys;

//function prototypes
void addEmployee();
void calculate_hours_worked();
void calculate_salary();
void display_employee_details();


void addEmployee() {
	Employee employee;
	printf("Enter the employee's ID: \n");
	scanf("%d", &employee.employee_id);
	printf("Enter employee's name: \n");
	scanf("%s", employee.name);
	printf("Enter his agreed hourly rate per contract: \n");
	scanf("%f", &employee.hourly_rate);
	employee.hours_work = 0.0;
	employee.salary = 0.0;
}

void calculate_hours_worked() {
	int employee_id;
	float hours_worked;
	printf("Enter employee ID: \n");
	scanf("%d", &employee_id);
	printf("Enter hours worked: \n");
	scanf("%f", &hours_worked);

	for (int i = 0; i < payr_sys.num_employees; i++) {
		if (payr_sys.employees[i].employee_id == employee_id) {
			payr_sys.empoyees[i].hours_worked == hours_worked;
			break;
		}
	}
}

void calculate_salary() {
	int employee_id;
	float hours_worked;
	float salary;
	printf("Enter your employee ID: \n");
	scanf("%d", &employee_id);
	printf("Enter total hours worked: \n");
	scanf("%f", &hours_worked);
	
	if (int i = 0; i < payr_sys.num.employees; i++) {
		if (payr_sys.employees[i].employee_id == employee_id) {
			payr_sys.employees[i].salary == payr_sys.employees[id].hours_worked * payr_sys.employees[i].hourly_rate;
			break;
		}
	}
}

void display_employee_details() {
	int employee_id;

	for (int i = 0; i < payr_sys.num.employees; i++) {
		if (payr_sys.employees[i].employee_id == employee_id) {
			printf("Employee ID: %d, Name: %s, Salary: %f\n", payr_sys.employees[i].employee_id, payr_sys.employees[i].name, payr_sys.employees[i].salary);
		}
	}
}

int main() {
	payr_sys.employees = 0;

	while (true) {
		int choice;
		printf("Enter your preffered choice: \n");
		printf("1. Add employee\n");
		printf("2. Calculate Hours worked \n");
		printf("3. Calculate your employee's pay \n");
		printf("4. Display employee's salary details \n");
		printf("5. Exit \n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				addEmployee();
				break;
			case 2:
				calculate_hours_worked();
				break;
			case 3:
				calculate_salary();
				break;
			case 4:
				display_employee_details();
				break;
			case 5:
				exit(0);
			default:
				printf("Error: Please Enter a valid choice. Number from 1 - 5!...\n");
		}
		break;
	}
	return 0;
}
