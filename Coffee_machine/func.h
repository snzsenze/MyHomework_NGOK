#ifndef _FUNC_H
#define _FUNC_H

//////////////////////////////////////////////////

void menu();
void espresso(int coffee, int water);
void latte(int coffee, int milk);
void cocoa(int cocoa, int milk);
void pay(int number_cup);
void pay_card(int number_cup);
void pay_nal(int number_cup);
int check_nal(int bill, int price);
void print();
void system_menu();

#endif