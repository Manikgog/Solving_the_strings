#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>

std::string spaces_str(std::string& str);

bool spam_check(std::string str);

void print_email(std::string str);

std::string lowerCamelCase(std::string str);

int main() {
	//setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));
	
	//{
	///*
	//	The function accepts a string, and then returns a string consisting of the same characters with spaces between them.
	//Example of a function call:
	//std::cout << spaces_str("Hello!");
	////// on the Hello ! screen
	//
	//	Функция принимает строку, после чего возвращает строку, состоящую из тех же символов, между которыми стоят пробелы.
	//Пример вызова функции:
	//std::cout << spaces_str("Hello!");
	//// на экране H e l l o !
	//*/
	//
	//std::cout << "Exercise 1.\n";
	//std::string str = "Hello!";
	//std::cout << spaces_str(str) << std::endl;
	//}
	
	/*
		Write a function to check spam in the passed string. 
	The function returns true if the string contains spam. 
	The following phrases are considered spam: 100% free, sales increase, 
	only today. The function must be nonregister-dependent.
		
		Написать функцию для проверки спама в переданной строке. 
	Функция возвращает true, если строка содержит спам. Спамом 
	считать следующие словосочетания: 100% free, sales increase, 
	only today. Функция должна быть нерегистрозависимой.
	*/
	/*{
		std::string str = "Hello!sales increaseworld!";
		if(spam_check(str))
			std::cout << str << " - spam.\n";
		else
			std::cout << str << " - not a spam.\n";
	}*/

	/*
		The user string in the format of the URL of the site. The program outputs the protocol, domain name and path to the page to him.
	Input example:
	https://ekat.top-academy.ru/Programmer/buy
	Conclusion:
	https
	ekat.top-academy.ru
	Programmer/buy

		Пользователь строку в формате URL адреса сайта. Программа выводит ему протокол, доменное имя и путь к странице.
	Пример ввода:
	https://ekat.top-academy.ru/Programmer/buy
	Вывод:
	https
	ekat.top-academy.ru
	Programmer/buy
	*/

	//{
	//	//std::string str = "https://ekat.top-academy.ru/Programmer/buy";
	//	std::string str = "https://www.youtube.com/watch?v=W--Jn9h8feQ";
	//	print_email(str);
	//}

	/*
		Write a function that accepts a string that is the desired 
	variable name. The function should return a name converted to 
	the lowerCamelCase style.
	Examples of function calls:
	std::cout << lowerCamelCase("Hello World");
	// // on the screen hello World
	std::cout << lowerCamelCase("my old friend");
	// // on the screen my Old Friend
	std::cout << lowerCamelCase("Oranges");
	// on the oranges screen

		Напишите функцию, которая принимает строку, которая является 
	желаемым именем переменной. Функция должна возвращать имя, 
	переделанное в стиль lowerCamelCase.
	Примеры вызова функции:
	std::cout << lowerCamelCase("Hello World");
	// на экране helloWorld
	std::cout << lowerCamelCase("my old friend");
	// на экране myOldFriend
	std::cout << lowerCamelCase("Oranges");
	// на экране oranges
	*/
	{
		std::cout << lowerCamelCase("Hello   World") << std::endl;
		std::cout << lowerCamelCase("my old friend") << std::endl;
		std::cout << lowerCamelCase("Oranges") << std::endl;
	}



	return 0;
}

std::string lowerCamelCase(std::string str) {
	std::string new_str;
	bool flag = false;
	for (auto i : str) {
		if (i == ' ') {
			flag = true;
			continue;
		}
		if (flag) {
			flag = false;
			i = toupper(i);
		}
		new_str += i;
	}
	new_str[0] = tolower(str[0]);
	return new_str;
}


void print_email(std::string str) {
	std::string protocol;
	std::string domain_name;
	int i = 0;
	while(str[i] != ':') {
		protocol += str[i];
		i++;
	}
	std::cout << protocol << std::endl;
	i += 3;
	while (str[i] != '/') {
		domain_name += str[i];
		i++;
	}
	std::cout << domain_name << std::endl;
	i++;
	while (i < str.length()) {
		std::cout << str[i];
		i++;
	}
	std::cout << std::endl;
}

bool spam_check(std::string str) {
	std::string arr[3]{ "100% free", "sales increase", "only today" };
	for (size_t i = 0; i < str.length(); i++) {
		str[i] = std::tolower(str[i]);
	}
	//std::cout << str << std::endl;
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < str.length(); j++) {
			if (str[j] == arr[i][0]) {
				std::string word;
				for (size_t k = j; (k < arr[i].length() + j) && (k < str.length()); k++) {
					word += str[k];
				}
				if (word == arr[i])
					return true;
			}
		}
	}
	return false;
}

std::string spaces_str(std::string& str) {
	std::string str_new;
	for (size_t i = 0; i < str.length(); i++) {
		str_new += str[i];
		str_new += " ";
	}
	return str_new;
}


