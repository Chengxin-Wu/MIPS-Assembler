#include "Phase3.h"
#include "math.h"
#include "ArrayList.h"
#include "stdio.h"

void translate_instructions(struct ArrayList *tals, uint32_t machineCode[]) {
    int size = tals->size;
    for (int i = 0; i < size; i++)
    {
        struct Instruction cur = get(tals,i);
        //R type
        if (cur.instruction_id == sll)
        {
            long result = 0 * pow(2,0) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.rd * pow(2,11) + cur.shift_amount * pow(2,6) + cur.jump_address * pow(2,26);
            machineCode[i] = (uint32_t)result;
        }
        else if (cur.instruction_id == addu)
        {
            long result = 33 * pow(2,0) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.rd * pow(2,11) + cur.immediate * pow(2,6) + cur.jump_address * pow(2,26);
            //printf("%ld\n",result);
            machineCode[i] = (uint32_t)result;
        }
        else if (cur.instruction_id == or)
        {
            long result = 37 * pow(2,0) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.rd * pow(2,11) + cur.immediate * pow(2,6) + cur.jump_address * pow(2,26);
            machineCode[i] = (uint32_t)result;
        }
        else if (cur.instruction_id == slt)
        {
            long result = 42 * pow(2,0) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.rd * pow(2,11) + cur.immediate * pow(2,6) + cur.jump_address * pow(2,26);
           machineCode[i] = (uint32_t)result;
        }
        //I type
        else if (cur.instruction_id == beq)
        {
            int result = 0;
            if(cur.immediate >= 0)
            {
                result = 4 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.immediate;
                
            }else
            {
                result = 4 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + 65536 + cur.immediate;
            }
            machineCode[i] = (uint32_t)result;
        }
        else if (cur.instruction_id == bne)
        {
            int result = 0;
            if(cur.immediate >= 0)
            {
                result = 5 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.immediate;
                
            }else
            {
                result = 5 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + 65536 + cur.immediate;
            }
            machineCode[i] = (uint32_t)result;
        }
        else if (cur.instruction_id == addi)
        {
            int result = 0;
            if(cur.immediate >= 0)
            {
                result = 8 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.immediate;
                
            }else
            {
                result = 8 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + 65536 + cur.immediate;
            }
            machineCode[i] = (uint32_t)result;
        }
        else if (cur.instruction_id == addiu)
        {
            int result = 0;
            if(cur.immediate >= 0)
            {
                result = 9 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.immediate;
                
            }else
            {
                result = 9 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + 65536 + cur.immediate;
            }
            machineCode[i] = (uint32_t)result;
        }
        else if (cur.instruction_id == ori)
        {
            int result = 0;
            if(cur.immediate >= 0)
            {
                result = 13 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.immediate;
                
            }else
            {
                result = 13 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + 65536 + cur.immediate;
            }
            machineCode[i] = (uint32_t)result;
        }
        else if (cur.instruction_id == lui)
        {
            int result = 0;
            if(cur.immediate >= 0)
            {
                result = 15 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + cur.immediate;
                
            }else
            {
                result = 15 * pow(2,26) + cur.rs * pow(2,21) + cur.rt * pow(2,16) + 65536 + cur.immediate;
            }
           machineCode[i] = (uint32_t)result;
        }
    }
}
