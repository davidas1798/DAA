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

#ifndef RAMMACHINE_P2_DATAMEMORY_H_
#define RAMMACHINE_P2_DATAMEMORY_H_

#include <vector>

using namespace std;

class DataMemory {
    private:
        vector<int> registers_;
    public:
        DataMemory(int);
        void Store(unsigned int, int);
        int Load(unsigned int);
        int GetAcc();
};

#endif // RAMMACHINE_P2_DATAMEMORY_H_