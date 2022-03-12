/**
 * @file alu.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RAMMACHINE_P2_RAM_H_
#define RAMMACHINE_P2_RAM_H_

#include "tape.h"
#include "program_memory.h"
#include "data_memory.h"

class Alu {
    private:
        unique_ptr<DataMemory> data_memory_;
        unique_ptr<ProgramMemory> program_memory_;
        unique_ptr<InputTape> input_tape_;
        unique_ptr<OutputTape> output_tape_;
    public:
        Alu(int, string, string, string);
        void Run();
    
};

#endif // RAMMACHINE_P2_RAM_H_