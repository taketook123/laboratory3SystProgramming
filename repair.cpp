#include <iostream>
#include "Repair.h"
#include <sstream>
using namespace std;

Repair::Repair()
    : break_code(0), done(false)
{
}

void Repair::setBreakCode(int code)
{
    break_code = code;
}

void Repair::setModelCode(const std::string& code)
{
    model_code = code;
}

void Repair::setDescription(const std::string& desc)
{
    description = desc;
}

void Repair::setSymptoms(const std::string& sym)
{
    symptoms = sym;
}

void Repair::setMethods(const std::string& methods)
{
    newMethods = methods;
}

void Repair::setScrapCode1(const std::string& code)
{
    scrap_code_1 = code;
}

void Repair::setScrapCode2(const std::string& code)
{
    scrap_code_2 = code;
}

void Repair::setScrapCode3(const std::string& code)
{
    scrap_code_3 = code;
}

void Repair::setPrice(int p)
{
    price = p;
}

void Repair::setDone(bool d)
{
    done = d;
}

std::string Repair::get_data_for_file() const
{
    std::stringstream ss;
    ss << "Model: " << model_code << ". Break code: " << break_code << ". Description: " << description << ". Price: " << price << ". ";
    if (done) {
        ss << "Done: Yes";
    } else {
        ss << "Done: No";
    }
    ss << "\n";
    return ss.str();
}

void Repair::get_data() const
{
    std::cout << "Model: " << model_code << ". Break code: " << break_code << ". Description: " << description << ". Price: " << price << ". ";
    if (done) {
        std::cout << "Done: Yes";
    } else {
        std::cout << "Done: No";
    }
    std::cout << std::endl;
}

int Repair::get_break_code() const
{
    return break_code;
}
