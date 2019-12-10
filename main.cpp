#include "shared.hpp"
#include "nano.hpp"
#include <ncurses.h>

int main()
{
    // initscr();
    // int row, col;
    // raw();
    // keypad(stdscr, true);
    // noecho();
    // getmaxyx(stdscr, row, col);
    // mvprintw(row/2, col/2, "Hello World!");
    // char tmp = getch();
    // mvprintw(row/2 + 1, col/2, keyname(tmp));
    // refresh();
    // getch();
    // endwin();

    Nano nano;
    nano.bind("<CTRL>Q%Quit", []() {printw("Exit?");}, "Help");
    nano.bind("#nano<SHIFT>T%Say Hi", []() {mvprintw(3, 5, "HI!");}, "Help");
    nano.start();
    return 0;
}