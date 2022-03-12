#include "tape.h"
#include "program_memory.h"
#include "alu.h"

int main() {
    // InputTape prueba_in("prueba.ram");
    // OutputTape prueba_out("output");
    // size_t tape_length = prueba_in.GetTape().size();
    
    // for(int i = 0; i < tape_length; i++) {
    //     prueba_out.Write(prueba_in.Read());
    // }
    // prueba_out.WriteFile();

    Alu alu(50, "prueba.ram", "input", "output");
    alu.Run();

    return 0;
}