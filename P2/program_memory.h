/**
 * @file program_memory.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief Class with the memory of the program
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RAMMACHINE_P2_PROGRAMMEMORY_H_
#define RAMMACHINE_P2_PROGRAMMEMORY_H_

#include <vector>
#include <algorithm>
#include <fstream>
#include "instruction.h"
#include "label.h"


class ProgramMemory {
    private:
        vector<Instruction> instructions_;
        vector<Label> labels_;
        unsigned int pc_;
    public:
        ProgramMemory(string);
        Instruction GetCurrentInstruction() const;
        void IncrementPc();
        unsigned int GetPc() const;
        void SetPc(unsigned int);
        unsigned int FindLabel(string);
};

#endif // RAMMACHINE_P2_PROGRAMMEMORY_H_