/**
 * @file label.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RAMMACHINE_P2_LABEL_H_
#define RAMMACHINE_P2_LABEL_H_

#include <string>

using namespace std;

class Label {
    private:
        string name_;
        unsigned int address_;
    public:
        Label(string, unsigned int);
        string GetName() const;
        unsigned int GetAddress() const;

};

#endif // RAMMACHINE_P2_LABEL_H_