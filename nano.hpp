#ifndef NANO_HPP_INCLUDED_
#define NANO_HPP_INCLUDED_

#include "shared.hpp"

class Nano : public Backend
{
    private:
    std::vector<BindingString> bindings;
    std::vector<char> GetBindTab();
    
    public:
    Nano();
    void quit();
    void help();
    void bind(std::string str, std::function<void()> func, std::string help);
    void start();

};

#endif