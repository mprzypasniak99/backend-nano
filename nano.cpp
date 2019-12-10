#include "nano.hpp"
#include <ncurses.h>
#define ctrl(x) ((x)& 0x1f)

void Nano::bind(std::string str, std::function<void()> func, std::string help)
{
    BindingString new_bind;
    std::string id = "#nano", name, tmp;
    char c;
    if(str.find(id, 0) != -1 || str[0] != '#')
    {
        int l_bracket = str.find('<', 0), r_bracket = str.find('>', 0);
        if(l_bracket != -1 && r_bracket != -1)
        {
            tmp.assign(str, l_bracket + 1, r_bracket - l_bracket -1);
        }
        c = str[r_bracket + 1];
        for(int i = str.find('%', 0) + 1; i < str.size(); i++)
        {
            name.push_back(str[i]);
        }
        
        new_bind.func = func;
        new_bind.name=tmp;
        new_bind.name+='+';
        new_bind.name+=c;
        new_bind.name+='-';
        new_bind.name+=name;
        new_bind.name.shrink_to_fit();
        new_bind.help = help;
        this->bindings.push_back(new_bind);
    }
}

std::vector<char> Nano::GetBindTab()
{
    std::vector<char> tab;
    char tmp;
    for(int i = 0; i < bindings.size(); i++)
    {
        std::string key;
        int k = bindings[i].name.find('+');
        key.assign(bindings[i].name, 0, k);
        if(key == "CTRL")
        {
            tab.push_back(ctrl(bindings[i].name[k+1]));
        }
        else if (key == "SHIFT")
        {
            const int x = 32;
            tab.push_back(bindings[i].name[k+1] & ~x);
        }
        
    }
    return tab;
}

void Nano::start()
{
    initscr();
    int row, col;
    raw();
    keypad(stdscr, true);
    noecho();
    getmaxyx(stdscr, row, col);
    move(row-1, 1);
    refresh();

    std::vector<char> bindTab = GetBindTab();

    for(int i = 0; i < bindings.size(); i++)
    {
        printw(bindings[i].name.c_str());
        printw("\t");
    }
    refresh();
    char a = 0;
    while(a != 'f')
    {
        a = getch();
        for(int i = 0; i < bindTab.size(); i++)
        {
            if(a == bindTab[i])
            {
                bindings[i].func();
            }
        }
    }
    
    endwin();
}