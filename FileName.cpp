#include <iostream>
#include <iomanip>  // برای std::setprecision و std::fixed

using namespace std;

// ساختارها برای غذا، نوشیدنی و پیش غذا
struct Food {
    int code;
    string name;
    double price;
};

struct Drink {
    int code;
    string name;
    double price;
};

struct Appetizer {
    int code;
    string name;
    double price;
};

// تعریف ارزش افزوده به صورت ثابت
const double VAT = 0.09;

// تعریف منوی رستوران به صورت آرایه‌های Global
Food menuFoods[] = {
    {1, "Pizza", 8.99},
    {2, "Burger", 5.49},
    {3, "Pasta", 7.99}
};

Drink menuDrinks[] = {
    {1, "Coke", 1.99},
    {2, "Water", 0.99},
    {3, "Juice", 2.49}
};

Appetizer menuAppetizers[] = {
    {1, "Salad", 3.99},
    {2, "Soup", 2.99},
    {3, "Fries", 1.99}
};

// تابع برای پیدا کردن قیمت بر اساس کد
double findPrice(int code, Food menu[], int size) {
    for (int i = 0; i < size; ++i) {
        if (menu[i].code == code) {
            return menu[i].price;
        }
    }
    return 0;
}

double findPrice(int code, Drink menu[], int size) {
    for (int i = 0; i < size; ++i) {
        if (menu[i].code == code) {
            return menu[i].price;
        }
    }
    return 0;
}

double findPrice(int code, Appetizer menu[], int size) {
    for (int i = 0; i < size; ++i) {
        if (menu[i].code == code) {
            return menu[i].price;
        }
    }
    return 0;
}

int main() {
    int foodCode, drinkCode, appetizerCode;

    cout << "Enter food code: ";
    cin >> foodCode;

    cout << "Enter drink code: ";
    cin >> drinkCode;

    cout << "Enter appetizer code: ";
    cin >> appetizerCode;

    // پیدا کردن قیمت‌ها بر اساس کدهای وارد شده
    double foodPrice = findPrice(foodCode, menuFoods, 3);
    double drinkPrice = findPrice(drinkCode, menuDrinks, 3);
    double appetizerPrice = findPrice(appetizerCode, menuAppetizers, 3);

    // محاسبه مبلغ نهایی با ارزش افزوده
    double subtotal = foodPrice + drinkPrice + appetizerPrice;
    double vatAmount = subtotal * VAT;
    double total = subtotal + vatAmount;

    // چاپ مبلغ نهایی
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "VAT (9%): $" << vatAmount << endl;
    cout << "Total: $" << total << endl;

    return 0;
}
