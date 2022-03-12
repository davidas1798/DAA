/**
 * @file data_memory.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief Class that initializes the data memory of the RAM machine
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "data_memory.h"

DataMemory::DataMemory(int size = 100) {
    registers_.resize(size);
}

void DataMemory::Store(unsigned int position, int value) {
    registers_[position] = value;
}

int DataMemory::Load(unsigned int position) {
    return registers_[position];
}

int DataMemory::GetAcc() {
    return registers_[0];
}