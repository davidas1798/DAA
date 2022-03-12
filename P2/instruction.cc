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

#include "instruction.h"

Instruction::Instruction(string instruction) {
    CreateInstruction(instruction);
}

void Instruction::CreateInstruction(string instruction) {
    istringstream iss(instruction);
    iss >> instruction_;
    if(instruction_ == "LOAD" || instruction_ == "load") {
        opcode_ = Opcode::Load;
        iss >> operand_;
        is_jump_ = false;
    }
    else if(instruction_ == "STORE" || instruction_ == "store" ) {
        opcode_ = Opcode::Store;
        iss >> operand_;
        is_jump_ = false;
    }
    else if(instruction_ == "ADD" || instruction_ == "add") {
        opcode_ = Opcode::Add;
        iss >> operand_;
        is_jump_ = false;
    }
    else if(instruction_ == "SUB" || instruction_ == "sub") {
        opcode_ = Opcode::Sub;
        iss >> operand_;
        is_jump_ = false;
    }
    else if(instruction_ == "MUL" || instruction_ == "mul") {
        opcode_ = Opcode::Mul;
        iss >> operand_;
        is_jump_ = false;
    }
    else if(instruction_ == "DIV" || instruction_ == "div") {
        opcode_ = Opcode::Div;
        iss >> operand_;
        is_jump_ = false;
    }
    else if(instruction_ == "READ" || instruction_ == "read") {
        opcode_ = Opcode::Read;
        iss >> operand_;
        is_jump_ = false;
    }
    else if(instruction_ == "WRITE" || instruction_ == "write") {
        opcode_ = Opcode::Write;
        iss >> operand_;
        is_jump_ = false;
    }
    else if(instruction_ == "JUMP" || instruction_ == "jump") {
        opcode_ = Opcode::Jump;
        iss >> label_;
        is_jump_ = true;
    }
    else if(instruction_ == "JZERO" || instruction_ == "jzero") {
        opcode_ = Opcode::Jzero;
        iss >> label_;
        is_jump_ = true;
    }
    else if(instruction_ == "JGTZ" || instruction_ == "jgtz") {
        opcode_ = Opcode::Jgtz;
        iss >> label_;
        is_jump_ = true; 
    }
    else if(instruction_ == "HALT" || instruction_ == "halt") {
        opcode_ = Opcode::Halt;
        is_jump_ = false;
    }
    else {
        cerr << instruction_;
        throw invalid_argument("Instruction not found");
    }
}

string Instruction::GetInstruction() const {
    return instruction_;
}

Opcode Instruction::GetOpcode() const {
    return opcode_;
}

string Instruction::GetOperand() const {
    return operand_;
}

string Instruction::GetLabel() const {
    return label_;
}

bool Instruction::IsJump() const {
    return is_jump_;
}