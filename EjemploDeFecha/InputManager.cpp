#include "InputManager.h"

InputManager::InputManager() {
	inDay = 0;
	inMonth = 0;
	inYear = 0;
	type = true;
	runControl = true;
	validation = false;
	date = nullptr;
}

void InputManager::OutputMenu() {
	cout << "Que accion desea realizar:" << endl;
	cout << "a) Incrementar fecha. \n";
	cout << "b) Decrementar fecha. \n";
	cout << "c) Obtener la fecha del sistema. \n";
	cout << "d) Salir" << endl;
}

void InputManager::setOption() {
	option = _getch();
}

void InputManager::SetDay() {
	cout << "Ingresa el dia (formato dd):";
	cin >> inDay;
}

void InputManager::SetMonth() {
	cout << "Ingresa el mes digitado en numeros (formato mm):";
	cin >> inMonth;
}

void InputManager::SetYear() {
	cout << "Ingresa el año (formato aaaa):";
	cin >> inYear;
}

void InputManager::SetType() {
	cout << "Elige el tipo de formato:"
		 << endl
		 << "0) mm/dd/aaaa"
		 << endl
		 << "1) dd/mm/aaaa"
		 << endl;
	cin >> type;
}

void InputManager::run() {
	while (runControl) {
		system("cls");
		OutputMenu();
		setOption();
		system("cls");
		switch (option) {
		case 'a':
			while (!validation) {
				SetDay();
				SetMonth();
				SetYear();
				SetType();
				system("cls");

				date = new Date(inDay, inMonth, inYear);

				date->setType(type);
			
				validation = date->validationDate();
			}

			cout << "Fecha ingresadan " << *date << endl;
			int dayCount;

			cout << "Cuantos dias deceas icrementar:" << endl;
			cin >> dayCount;

			for (int count = 0; count < dayCount; count++) {
				++*date;
			}

			cout << "Fecha incrementada " << *date << endl;

			cout << "Presione cualquier tecla para continuar..." << endl;
			_getch();

			delete date;
			break;
		case 'b':
			while (!validation) {
				SetDay();
				SetMonth();
				SetYear();
				SetType();
				system("cls");

				date = new Date(inDay, inMonth, inYear);

				date->setType(type);

				validation = date->validationDate();
			}

			cout << "Fecha ingresadan " << *date << endl;
			int dayCounter;

			cout << "Cuantos dias deceas decrementar:" << endl;
			cin >> dayCounter;

			for (int count = 0; count < dayCounter; count++) {
				--* date;
			}

			cout << "Fecha decrementada " << *date << endl;

			cout << "Presione cualquier tecla para continuar..." << endl;
			_getch();

			delete date;
			break;
		case 'c':
			system("cls");

			SetType();

			date = new Date();

			date->setType(type);
			date->getDateSystem();

			cout << "La fecha del sistema es: " << *date << endl;

			cout << "Presione cualquier tecla para continuar..." << endl;
			_getch();

			delete date;

			break;
		case 'd':
			runControl = false;
			break;
		}
	}
}