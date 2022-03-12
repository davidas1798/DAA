/**
 * @file instruction.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief Class that stablish the instructions of the RAM machine
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef RAMMACHINE_P2_INSTRUCTION_H_
#define RAMMACHINE_P2_INSTRUCTION_H_

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

enum class Opcode {
    Load, Store, Add, Sub, Mul, Div, Read, 
    Write, Jump, Jzero, Jgtz, Halt
};

class Instruction {
    private:
        string instruction_;
        Opcode opcode_;
        string operand_;
        string label_;
        bool is_jump_;
        void CreateInstruction(string);
    public:
        Instruction(string);
        string GetInstruction() const;
        Opcode GetOpcode() const;
        string GetOperand() const;
        string GetLabel() const;
        bool IsJump() const;

};

#endif // RAMMACHINE_P2_INSTRUCTION_H_