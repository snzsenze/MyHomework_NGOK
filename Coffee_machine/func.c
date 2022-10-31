#include "func.h"
#include <stdio.h>
#include <stdlib.h>

static int tank_coffee = 10000; // Бак с кофе //
static int tank_water = 10000;  // Бак с водой //
static int tank_milk = 10000;   // Бак с молоком //
static int tank_cocoa = 10000;  // Бак с какао //

static int espresso_water = 50;
static int espresso_coffe = 25;
static int espresso_price = 100;

static int latte_coffe = 50;
static int latte_milk = 100;
static int latte_price = 200;

static int cocoa_cocoa = 50;
static int cocoa_milk = 100;
static int cocoa_price = 150;

static int money_cash = 0; // Деньги с карты
static int money_card = 0; // Деньги наличными

void system_menu()
{
    int dop_res = 0;
    while (dop_res != 3) {
        printf("Добро пожаловать в доп меню\n");
        printf("| 1 | чтобы проверить баки\n");
        printf("| 2 | чтобы проверить банк кофемашины\n");
        printf("| 3 | чтобы пополнить баки\n");
        scanf("%d", &dop_res);
        setbuf(stdin, NULL);
        switch (dop_res) {
        case 1:
            printf("Бак с кофе - %d\n", tank_coffee);
            printf("Бак с водой - %d\n", tank_water);
            printf("Бак с молоко - %d\n", tank_milk);
            printf("Бак с какао - %d\n", tank_cocoa);
            break;
        case 2:
            printf("Банк кофемашины - %d\n", money_cash);
            printf("Банк кофемашины - %d\n", money_card);
            printf("Ссума - %d\n", money_cash + money_card);
            break;
        case 3:
            int add_tank = 0;
            printf("| 1 | - Пополнить бак с коффе\n");
            printf("| 2 | - Пополнить бак с водой\n");
            printf("| 3 | - ПОполнить бак с молоком\n");
            printf("| 4 | - Пополнить бак с кокао\n");
            scanf("%d", &add_tank);
            if (add_tank == 1) {
                int tank_coffee_max = 10000;
                tank_coffee_max -= tank_coffee;
                printf("Бак пополнен на - %d \n", tank_coffee_max);
                tank_coffee += tank_coffee_max;
            } else if (add_tank == 2) {
                int tank_water_max = 10000;
                tank_water_max -= tank_water;
                printf("Бак пополнен на - %d \n", tank_water_max);
                tank_water += tank_water_max;
            } else if (add_tank == 3) {
                int tank_milk_max = 10000;
                tank_milk_max -= tank_milk;
                printf("Бак пополнен на - %d \n", tank_milk_max);
                tank_milk += tank_milk_max;
            } else if (add_tank == 4) {
                int tank_cocoa_max = 10000;
                tank_cocoa_max -= tank_cocoa;
                printf("Бак пополнен на - %d \n", tank_cocoa_max);
                tank_cocoa += tank_cocoa_max;
            }
            break;
        default:
            break;
        }
    }
}
void print() {}

int check_nal(int bill, int price)
{
    int res = 0;
    if (bill > price) {
        res = 1;
        printf("Ваша сдача=%d\n", bill - price);
    } else if (bill == price) {
        res = 1;
    } else if (bill < price) {
        printf("Недостаточно средств\n");
    }

    return res;
}

void pay_nal(int number_cup)
{
    int bill = 0;
    printf("Внесите купюру\n");
    scanf("%d", &bill);

    if (number_cup == 1) {
        if (check_nal(bill, espresso_price)) {
            tank_coffee -= espresso_coffe;
            tank_water -= espresso_water;
            money_cash += espresso_price;
            printf("Ваш кофе готов\n");
        }
    } else if (number_cup == 2) {

        if (check_nal(bill, latte_price)) {
            tank_coffee -= latte_coffe;
            tank_milk -= latte_milk;
            money_cash += latte_price;
            printf("Ваш кофе готов\n");
        }

    } else if (number_cup == 3) {

        if (check_nal(bill, latte_price)) {
            tank_cocoa -= cocoa_cocoa;
            tank_milk -= cocoa_milk;
            money_cash += cocoa_price;
            printf("Ваш кофе готов\n");
        }

        setbuf(stdin, NULL);
    }
}

void pay_card(int number_cup)
{
    if (number_cup == 1) {
        tank_coffee -= espresso_coffe;
        tank_water -= espresso_water;
        money_card += espresso_price;
        printf("Ваш кофе готов\n");
    } else if (number_cup == 2) {
        tank_coffee -= latte_coffe;
        tank_milk -= latte_milk;
        money_card += latte_price;
        printf("Ваш кофе готов\n");
    } else if (number_cup == 3) {
        tank_cocoa -= cocoa_cocoa;
        tank_milk -= cocoa_milk;
        money_card += cocoa_price;
        printf("Ваш кофе готов\n");
    }
}

void pay(int number_cup)
{
    int result = 0;
    printf("Выберите способ оплаты \n\n");
    printf("Нажмите 1 Способ оплаты - Карта \n");
    printf("Нажмите 2 Способ оплаты - Наличные \n");
    scanf("%d", &result);

    if (result == 1) { // Оплата картой //
        pay_card(number_cup);
    } else if (result == 2) { //Оплата наличными //
        pay_nal(number_cup);
    }
    setbuf(stdin, NULL);
}

void espresso(int coffee, int water)
{
    if (tank_coffee >= coffee && tank_water >= water) {
        pay(1);
    }
}

void latte(int coffee, int milk)
{
    if (tank_coffee >= coffee && tank_milk >= milk) {
        pay(2);
    }
}

void cocoa(int cocoa, int milk)
{
    if (tank_cocoa >= cocoa && tank_milk >= milk) {
        pay(3);
    }
}

void menu()
{
    char res = 0;
    while (res != 'q') {
        printf("--------Меню кофе машины--------\n\n");
        printf("| 1 | чтобы приготовить espresso\n");
        printf("| 2 | чтобы приготовить latte\n");
        printf("| 3 | чтобы приготовить cocoa\n");
        printf("| 4 | чтобы перейти в доп.меню\n");
        scanf("%c", &res);
        setbuf(stdin, NULL);

        switch (res) {
        case '1':
            print();
            espresso(25, 100);
            print();
            break;
        case '2':
            print();
            latte(50, 100);
            print();
            break;
        case '3':
            print();
            cocoa(50, 100);
            print();
            break;
        case '4':
            system_menu();
            break;
        default:
            break;
        }
        setbuf(stdin, NULL);
    }
}