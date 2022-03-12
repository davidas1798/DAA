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

#include "program_memory.h"

ProgramMemory::ProgramMemory(string filename) {
    pc_ = 0;
    unsigned int instruction_counter = 0;
    ifstream input_file(filename);
    string line;
    // Read file line by line
    while(getline(input_file, line)) {
        istringstream iss(line);
        string word;
        bool is_comment = false;
        // Read line word by word
        while(iss >> word && !is_comment) {
            if(word[0] != '#') {
                if(word.back() == ':') {
                    word.pop_back();
                    labels_.push_back(Label(word, instruction_counter));
                }
                else if(word != "HALT") {
                    string operation, operand;
                    operation = word;
                    iss >> word;
                    operand = word;
                    instructions_.push_back(Instruction(operation + " " + operand));
                    instruction_counter++;
                }
                else {
                    instructions_.push_back(Instruction(word));
                    instruction_counter++;
                }
            }
            else {
                is_comment = true;
            }
        }
        is_comment = false;
    }
}

Instruction ProgramMemory::GetCurrentInstruction() const {
    return instructions_[pc_];
}

void ProgramMemory::IncrementPc() {
    pc_++;
}

unsigned int ProgramMemory::GetPc() const {
    return pc_;
}

void ProgramMemory::SetPc(unsigned int address) {
    pc_ = address;
}

unsigned int ProgramMemory::FindLabel(string label_name) {
    for(auto& label : labels_) {
        if(label.GetName() == label_name)
            return label.GetAddress();
    }
    return 404;
}