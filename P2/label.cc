/**
 * @file label.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "label.h"

Label::Label(string name, unsigned int address) {
    name_ = name;
    address_ = address;
}

string Label::GetName() const {
    return name_;
}

unsigned int Label::GetAddress() const {
    return address_;
}