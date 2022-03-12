/**
 * @file execute_instruction.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class Alu;

class ExecuteInstruction {
    public:
        virtual void Execute(Instruction&, Alu&) = 0;
};

class ExecuteInmediateInstruction: public ExecuteInstruction {
    public:
        void Execute(Instruction&, Alu&);
};

class ExecuteDirectInstruction: public ExecuteInstruction {
    public:
        void Execute(Instruction&, Alu&);
};

class ExecuteIndirectInstruction: public ExecuteInstruction {
    public:
        void Execute(Instruction&, Alu&);
};

class ExecuteJumpInstruction: public ExecuteInstruction {
    public:
        void Execute(Instruction&, Alu&);
};