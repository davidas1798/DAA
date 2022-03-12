/**
 * @file tape.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief Classes of the input and output tapes of the RAM machine
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "tape.h"

Tape::Tape(string filename):
    filename_(filename),
    head_(0) {}

unsigned short int Tape::GetHead() const {
    return head_;
}

vector<int> Tape::GetTape() const {
    return tape_;
}

InputTape::InputTape(string filename): 
    Tape(filename) 
{
    ReadFile(filename);
}

void InputTape::ReadFile(string filename) {
    input_file_.open(filename);
    string line;
    // Read file line by line
    while(getline(input_file_, line)) {
        istringstream iss(line);
        string word;
        // Read line word by word
        while(iss >> word) {
            tape_.push_back(stoi(word));
        }
    }
}

int InputTape::Read() {
    head_++;
    return tape_[head_ - 1];
}

OutputTape::OutputTape(string filename):
    Tape(filename) 
{}

void OutputTape::Write(int int_to_write) {
    tape_.push_back(int_to_write);
    head_++;
}

void OutputTape::WriteFile() {
    output_file_.open(filename_);
    for(auto& cell : tape_) {
        output_file_ << cell << " ";
    }
}

