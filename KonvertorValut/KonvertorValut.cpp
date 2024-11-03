#include <iostream>
#include <iomanip>

const double BANK_COMMISSION_RATE = 0.05; // 5% комиссия
const double DOLLAR_RATE = 0.013; // Курс доллара
const double EURO_RATE = 0.012; // Курс евро
const double YUAN_RATE = 0.087; // Курс юаня
const double YEN_RATE = 1.45;   // Курс йены
const double FARIT_RATE = 0.37;   // Курс фарита

void showCurrencyOptions() {
    std::cout << "Выберите валюту для обмена:\n";
    std::cout << "1. Доллар\n";
    std::cout << "2. Евро\n";
    std::cout << "3. Юань\n";
    std::cout << "4. Фарит\n";
    std::cout << "5. Йена\n";
}

double exchangeCurrency(double rublesAmount, int currencyOption) {
    double rate = 0.0;

    switch (currencyOption) {
    case 1:
        rate = DOLLAR_RATE;
        break;
    case 2:
        rate = EURO_RATE;
        break;
    case 3:
        rate = YUAN_RATE;
        break;
    case 4:
        rate = FARIT_RATE;
        break;
    case 5:
        rate = YEN_RATE;
        break;
    default:
        std::cout << "Некорректный выбор валюты.\n";
        return 0.0;
    }

    double commissionAmount = rublesAmount * BANK_COMMISSION_RATE;
    double netAmount = rublesAmount - commissionAmount;
    double exchangedAmount = netAmount * rate;

    std::cout << "Сумма комиссии: " << std::fixed << std::setprecision(2) << commissionAmount << " рублей\n";
    return exchangedAmount;
}

int main() {
    setlocale(LC_ALL, "RU");
    double rublesAmount;
    int currencyOption;
    char continueExchange;

    do {
        std::cout << "Введите сумму в рублях для обмена: ";
        std::cin >> rublesAmount;

        showCurrencyOptions();
        std::cout << "Введите номер валюты для обмена: ";
        std::cin >> currencyOption;

        double result = exchangeCurrency(rublesAmount, currencyOption);
        if (result > 0) {
            std::cout << "Вы получили: " << std::fixed << std::setprecision(2) << result << " валюты.\n";
        }

        std::cout << "Хотите выполнить обмен снова? (y/n): ";
        std::cin >> continueExchange;

    } while (continueExchange == 'y' || continueExchange == 'Y');

    std::cout << "Спасибо за использование нашего конвертера валют!\n";
    return 0;
}