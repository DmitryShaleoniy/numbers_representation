#include "Application.h"
#include <iostream>
#include "Calculator.h"

void Application::menu() {
	std::cout << "---------------------- Menu ----------------------" << std::endl;
	std::cout << "1. Ввести значение val1" << std::endl;
	std::cout << "2. Ввести значение val2" << std::endl;
	std::cout << "3. val1 + val2 " << std::endl;
	std::cout << "4. val1 - val2 " << std::endl;
	std::cout << "5. val1 * val2 " << std::endl;
	std::cout << "6. val1 / val2 " << std::endl;
	std::cout << "7. узнать количество созданных объектов " << std::endl;
	std::cout << "8. Выход " << std::endl;
	std::cout << "Введите номер той команды, которую желаете использовать " << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}

void Application::run() {
	int key = 0;
	Calculator val1, val2;
	while (key != 8) {
		menu();
		std::cin >> key;
		switch (key) {
		case 1: {
			double value;
			std::cin >> value;
			val1 = value;
		}
			  break;
		case 2: {
			double value;
			std::cin >> value;
			val2 = value;
		}
			  break;
		case 3: {
			std::cout << val1.Imag() << "+" << val2.Imag() << "=" << (val1 + val2).Imag() << std::endl;
		}
			  break;
		case 4: {
			std::cout << val1.Imag() << "-" << val2.Imag() << "=" << (val1 - val2).Imag() << std::endl;
		}
			  break;
		case 5: {
			std::cout << val1.Imag() << "*" << val2.Imag() << "=" << (val1 * val2).Imag() << std::endl;
		}
			  break;
		case 6: {
			std::cout << val1.Imag() << "/" << val2.Imag() << "=" << (val1 / val2).Imag() << std::endl;
		}
			  break;
		case 7: {
			std::cout << "количество созданных объектов: " << Calculator::m_counter << std::endl;
		}
			  break;
		default:
			key = 8;
		}
	}
}