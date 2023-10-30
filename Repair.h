#ifndef REPAIR_H
#define REPAIR_H

#include <string>

class Repair {
public:
    Repair();
    void setBreakCode(int code);
    void setModelCode(const std::string& code);
    void setDescription(const std::string& desc);
    void setSymptoms(const std::string& sym);
    void setMethods(const std::string& methods);
    void setScrapCode1(const std::string& code);
    void setScrapCode2(const std::string& code);
    void setScrapCode3(const std::string& code);
    void setPrice(int price);
    void setDone(bool done);
    void get_data() const;
    int get_break_code() const;
    std::string get_data_for_file() const;
private:
    int break_code;
    std::string model_code;
    std::string description;
    std::string symptoms;
    std::string newMethods;
    std::string scrap_code_1;
    std::string scrap_code_2;
    std::string scrap_code_3;
    int price;
    bool done;
};


#endif // REPAIR_H
