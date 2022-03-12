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

#ifndef RAMMACHINE_P2_TAPE_H_
#define RAMMACHINE_P2_TAPE_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Tape {
    protected:
        string filename_;
        vector<int> tape_;
        unsigned short int head_;
    public:
        Tape(string);
        unsigned short int GetHead() const;
        vector<int> GetTape() const;

};

class InputTape: public Tape {
    private:
        ifstream input_file_;
    public:
        InputTape(string);
        int Read();
        void ReadFile(string);
};

class OutputTape: public Tape {
    private:
        ofstream output_file_;
    public:
        OutputTape(string);
        void Write(int);
        void WriteFile();
};

#endif // RAMMACHINE_P2_TAPE_H_