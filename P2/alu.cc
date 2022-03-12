/**
 * @file alu.cc
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "alu.h"

Alu::Alu(int memory_size, string program_file, string input_file, string output_file) {
    data_memory_ = make_unique<DataMemory>(memory_size);
    program_memory_ = make_unique<ProgramMemory>(program_file);
    input_tape_ = make_unique<InputTape>(input_file);
    output_tape_ = make_unique<OutputTape>(output_file);
}

void Alu::Run() {
    while(program_memory_->GetCurrentInstruction().GetOpcode() != Opcode::Halt) {
        Instruction current_instruction = program_memory_->GetCurrentInstruction();
        if(current_instruction.IsJump()) {
            switch(current_instruction.GetOpcode()) {
                case Opcode::Jump: {
                    string label_name = current_instruction.GetLabel();
                    unsigned int new_pc = program_memory_->FindLabel(label_name);
                    program_memory_->SetPc(new_pc);
                    break;
                }
                case Opcode::Jzero: {
                    if(data_memory_->GetAcc() == 0) {
                        string label_name = current_instruction.GetLabel();
                        unsigned int new_pc = program_memory_->FindLabel(label_name);
                        program_memory_->SetPc(new_pc);
                    }
                    else
                        program_memory_->IncrementPc();
                    break;
                }
                case Opcode::Jgtz: {
                    if(data_memory_->GetAcc() > 0) {
                        string label_name = current_instruction.GetLabel();
                        unsigned int new_pc = program_memory_->FindLabel(label_name);
                        program_memory_->SetPc(new_pc);
                    }
                    else
                        program_memory_->IncrementPc();
                    break;
                }
            }
        }
        else {
            string operand = current_instruction.GetOperand();
            int final_operand;
            string auxiliar = operand;
            if(auxiliar[0] == '*' || auxiliar[0] == '=')
                auxiliar.erase(0, 1);
            int numeric_operand = stoi(auxiliar);
            if(current_instruction.GetOpcode() != Opcode::Store && current_instruction.GetOpcode() != Opcode::Read) {
                if(operand[0] == '='){
                    final_operand = numeric_operand;
                }
                else if(operand[0] == '*'){
                    numeric_operand = data_memory_->Load(numeric_operand);
                    final_operand = data_memory_->Load(numeric_operand);
                }
                else 
                    final_operand = data_memory_->Load(numeric_operand);
            
                if(current_instruction.GetOpcode() == Opcode::Load) {
                    data_memory_->Store(0, final_operand);
                }
                else if(current_instruction.GetOpcode() == Opcode::Add) {
                    int result = data_memory_->GetAcc();
                    result += final_operand;
                    data_memory_->Store(0, result);
                }
                else if(current_instruction.GetOpcode() == Opcode::Sub) {
                    int result = data_memory_->GetAcc();
                    result -= final_operand;
                    data_memory_->Store(0, result);
                }
                else if(current_instruction.GetOpcode() == Opcode::Mul) {
                    int result = data_memory_->GetAcc();
                    result *= final_operand;
                    data_memory_->Store(0, result);
                }
                else if(current_instruction.GetOpcode() == Opcode::Add) {
                    int result = data_memory_->GetAcc();
                    result /= final_operand;
                    data_memory_->Store(0, result);
                }
                else if(current_instruction.GetOpcode() == Opcode::Write) {
                    output_tape_->Write(final_operand);
                }
            }
            else {
                if(operand[0] == '*') {
                    auxiliar = operand;
                    auxiliar.erase(0, 1);
                    numeric_operand = stoi(auxiliar);
                    final_operand = data_memory_->Load(numeric_operand);
                }
                else {
                    final_operand = stoi(operand);
                }
                if(current_instruction.GetOpcode() == Opcode::Store) {
                    data_memory_->Store(final_operand, data_memory_->GetAcc());
                }
                else if(current_instruction.GetOpcode() == Opcode::Read) {
                    data_memory_->Store(final_operand, input_tape_->Read());
                }
            }
            program_memory_->IncrementPc();
        }
    }
    output_tape_->WriteFile();
}