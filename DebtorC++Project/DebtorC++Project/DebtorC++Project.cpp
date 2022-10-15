#include <iostream>
using namespace std;

class Debtor {
	int objectId;
	char* name = nullptr;
	char* surname = nullptr;
	char* workAddress = nullptr;
	long salary = 0;
	long phoneNumber;
	bool hasLatePayment;
	char* liveAddress = nullptr;
	long debt = 0;
	static int Id;

public:

	Debtor() : name(nullptr), surname(nullptr), workAddress(nullptr), salary(0), phoneNumber(0), hasLatePayment(1), liveAddress(nullptr), debt(0) { objectId = Id++; }

	Debtor(const char* name) :Debtor() {
		SetName(name);
	}

	Debtor(const char* name, const char* surname) :Debtor(name) {
		SetSurname(surname);
	}

	Debtor(const char* name, const char* surname, const char* workAddress) : Debtor(name, surname) {
		SetWorkAddress(workAddress);
	}

	Debtor(const char* name, const char* surname, const char* workAddress, long salary) : Debtor(name, surname, workAddress) {
		SetSalary(salary);
	}

	Debtor(const char* name, const char* surname, const char* workAddress, long salary, long phoneNumber) : Debtor(name, surname, workAddress, salary) {
		SetPhoneNumber(phoneNumber);
	}

	Debtor(const char* name, const char* surname, const char* workAddress, long salary, long phoneNumber, bool hasLatePayment) : Debtor(name, surname, workAddress, salary, phoneNumber) {
		SetHasLatePayment(hasLatePayment);
	}

	Debtor(const char* name, const char* surname, const char* workAddress, long salary, long phoneNumber, bool hasLatePayment, const char* liveAddress) : Debtor(name, surname, workAddress, salary, phoneNumber, hasLatePayment) {
		SetLiveAddress(liveAddress);
	}

	Debtor(const char* name, const char* surname, const char* workAddress, long salary, long phoneNumber, bool hasLatePayment, const char* liveAddress, long debt) : Debtor(name, surname, workAddress, salary, phoneNumber, hasLatePayment, liveAddress) {
		SetDebt(debt);
	}

	void ShowDebtor() {
		cout << "Id: " << objectId << endl << "Name: " << name << endl << "Surname: " << surname << endl << "Work Address: " << workAddress << endl << "Salary: " << salary << endl << "PhoneNumber: " << phoneNumber << endl << "Has late payment: " << hasLatePayment << endl << "Live Address: " << liveAddress << endl << "Debt: " << debt << endl << endl;
	}



	Debtor(const Debtor& o) {
		SetObjectId(o.objectId);
		SetName(o.name);
		SetSurname(o.surname);
		SetWorkAddress(o.workAddress);
		SetSalary(o.salary);
		SetHasLatePayment(o.hasLatePayment);
		SetLiveAddress(o.liveAddress);
		SetDebt(o.debt);
		SetPhoneNumber(o.phoneNumber);
	}

#pragma region Setters
	void SetObjectId(int objectId) {
		this->objectId = objectId > 0 ? objectId : 1;
	}

	void SetName(const char* name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void SetSurname(const char* surname) {
		delete[] this->surname;
		this->surname = new char[strlen(surname) + 1];
		strcpy_s(this->surname, strlen(surname) + 1, surname);
	}

	void SetWorkAddress(const char* workAddress) {
		delete[] this->workAddress;
		this->workAddress = new char[strlen(workAddress) + 1];
		strcpy_s(this->workAddress, strlen(workAddress) + 1, workAddress);
	}

	void SetSalary(long salary) {
		this->salary = salary > 0 ? salary : 100;
	}

	void SetPhoneNumber(long phoneNumber) {
		this->phoneNumber = phoneNumber > 0 ? phoneNumber : 555555555;
	}

	void SetHasLatePayment(bool hasLatePayment) {
		this->hasLatePayment = hasLatePayment == true ? true : false;
	}

	void SetLiveAddress(const char* liveAddress) {
		delete[] this->liveAddress;
		this->liveAddress = new char[strlen(liveAddress) + 1];
		strcpy_s(this->liveAddress, strlen(liveAddress) + 1, liveAddress);
	}

	void SetDebt(long debt) {
		this->debt = debt > 0 ? debt : 100;
	}
#pragma endregion


#pragma region Getters
	int GetObjectId() { return objectId; }
	const char* GetName() { return name; }
	const char* GetSurname() { return surname; }
	const char* GetWorkAddress() { return workAddress; }
	double GetSalary() { return salary; }
	double GetPhoneNumber() { return phoneNumber; }
	bool GetHasLatePayment() { return hasLatePayment; }
	const char* GetLiveAddress() { return liveAddress; }
	double GetDebt() { return debt; }
#pragma endregion


	~Debtor() {
		delete[] name;
		delete[] surname;
		delete[] workAddress;
		delete[] liveAddress;
	}


};
int Debtor::Id = 1;


class Bank {
	char* name = nullptr;
public:
	int size = 2;
	Debtor* debtors = new Debtor[2];

	Bank(const char* name) {
		SetName(name);
	}

	void ShowAllDebtors() {
		for (int i = 0; i < size; i++) {
			debtors[i].ShowDebtor();
		}
	}

	void MoreThousand() {
		for (int i = 0; i < size; i++) {
			if (debtors[i].GetDebt() > 1000) {
				debtors[i].ShowDebtor();
			}
		}
	}

	void ShowHasLatePayment() {
		for (int i = 0; i < size; i++) {
			if (debtors[i].GetHasLatePayment() == true) {
				debtors[i].ShowDebtor();
			}
		}
	}


	void SetName(const char* name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	const char* GetName() { return name; }

	~Bank() {
		delete[] name;
	}

};




void main() {
	Debtor d = Debtor("Elon", "Musk", "Tesla", 100000000, 777777777, 0, "USA", 20000000);
	Debtor d1 = Debtor("Bill", "Gates", "Microsoft", 157000000, 555555555, 1, "USA", 232000000);

	Bank b = Bank("Kapital Bank");
	b.debtors = new Debtor[2]{ d,d1 };
	cout << "All Debtors: \n" << endl;
	b.ShowAllDebtors();
	cout << "*****************************\n" << endl;
	cout << "DEBT MORE THAN A THOUSAND: \n" << endl;
	b.MoreThousand();
	cout << "*****************************\n" << endl;
	cout << "HAS LATE PAYMENT: \n" << endl;
	b.ShowHasLatePayment();

}