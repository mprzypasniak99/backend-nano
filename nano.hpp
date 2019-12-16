#ifndef NANO_HPP_INCLUDED_
#define NANO_HPP_INCLUDED_

#include "shared.hpp"

class Nano : public Backend
{
    private:
    std::vector<char> GetBindTab();
    
    public:
    void quit();
    void help();
    void bind(std::string str, std::function<void()> func, std::string help);
    void start();

};

#endif