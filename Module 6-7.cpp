/*Задание 7. Сокращение дроби * (дополнительное задание)
Что нужно сделать
Пользователь вводит числа M и N.Напишите программу, которая преобразует дробь M / N к несократимому виду и выдаёт получившийся результат.Обеспечьте контроль ввода.

Пример выполнения

Введите числитель : 4
Введите знаменатель : 6
Результат : 2 / 3
Введите числитель : 25
Введите знаменатель : 40 >
Результат: 5 / 8
Введите числитель : −6
Введите знаменатель : 12
Результат : −1 / 2
(При вводе отрицательных чисел в выводе должен быть только один ведущий минус.Неправильный вывод программы : 1 / −2, −1 / −2.)
Введите числитель : 896
Введите знаменатель : 3584
Результат : 1 / 4

Рекомендации по выполнению
Не забывайте о правилах деления чисел.Программа должна работать корректно и не должна «падать».

Что оценивается
Алгоритм оптимальный, не бесконечный и не очень большой.Программа не зависает.
Правильно определены критерии начала и конца цикла.*/

#include <iostream>

int main()
{
	std::cout << "Введите числитель: ";
	int fractionNumerator;
	std::cin >> fractionNumerator;

	while (fractionNumerator == 0) {
		std::cout << "\nПри числителе равном 0, дробь тоже равна 0 и сокращение не имеет смысла. Введите снова: ";
		std::cin >> fractionNumerator;
	}

	std::cout << "Введите знаменатель: ";
	int fractionDenumerator;
	std::cin >> fractionDenumerator;

	while (fractionDenumerator == 0) {
		std::cout << "\nЗнаменатель должен быть не равен 0. Введите снова: ";
		std::cin >> fractionDenumerator;
	}

	// определяем знак итоговой дроби
	std::string sign;
	if ((fractionDenumerator < 0 && fractionNumerator > 0) || (fractionDenumerator > 0 && fractionNumerator < 0)) sign = "-";
	else sign = "";

	int greatestCommonDivisor;

	// цикл DO длится пока НОД не станет 1
	do {
		// первичный НОД определяем как большее из числителяи знаменателя
		if (fractionNumerator < fractionDenumerator) greatestCommonDivisor = fractionNumerator;
		else greatestCommonDivisor = fractionNumerator;

		// находим ближайший НОД 
		while ((fractionNumerator % greatestCommonDivisor != 0 || fractionDenumerator % greatestCommonDivisor != 0) && greatestCommonDivisor > 1) {
			greatestCommonDivisor--;
		}

		//сокращаем числитель и знаменатель
		fractionNumerator /= greatestCommonDivisor;
		fractionDenumerator /= greatestCommonDivisor;

	} while (greatestCommonDivisor != 1);

	std::cout << "Результат : "<< sign << abs(fractionNumerator) << " / " << abs(fractionDenumerator) << "\n";
}
