#include "Phase1.h"
#include "InstructionFactory.h"
#include "ArrayList.h"
#include <string.h>
#include "stdio.h"

void mal_to_tal(struct ArrayList *mals, struct ArrayList *tals)
{
    int size = mals->size;
    for(int i = 0; i < size; i++)
    {
        struct Instruction cur = get(mals,i);
        if (cur.instruction_id == blt)
        {
            struct Instruction expect1 = CreateSlt(1,cur.rt, cur.rs);
            struct Instruction expect2 =  CreateBne(1,0,cur.label);
            addLast(tals,expect1);
            addLast(tals,expect2);
        }
        else if (cur.instruction_id == bge)
        {
            struct Instruction expect1 = CreateSlt(1,cur.rt, cur.rs);
            struct Instruction expect2 = CreateBeq(1,0,cur.label);
            addLast(tals,expect1);
            addLast(tals,expect2);
        }
        else if (cur.instruction_id == mov)
        {
            struct Instruction expect1 = CreateAddu(cur.rd, cur.rs, cur.rt);
            addLast(tals,expect1);
        }
        else if (cur.instruction_id == addiu)
        {
            int32_t num = cur.immediate;
            if(num>>16 == 0x00000000 || (num > -32768 && num>>16 == 0xFFFFFFFF))
            {
                if(strcmp(cur.label,"") == 0)
                {
                    addLast(tals,cur);
                }
                else
                {
                    struct Instruction expect1 = CreateAddiu_lab(cur.rt,cur.rs,cur.immediate,cur.label);
                    addLast(tals,expect1);
                }
            }else
            {
                struct Instruction expect1;
                if(strcmp(cur.label,"") == 0)
                {
                    expect1 = CreateLui(1,(num>>16) & 0x0000FFFF);
                }else
                {
                    expect1 = CreateLui_lab(1,num>>16,cur.label);
                }
                struct Instruction expect2 = CreateOri(1,1,num & 0x0000FFFF);
                struct Instruction expect3 = CreateAddu(cur.rt, cur.rs,1);
                addLast(tals,expect1);
                addLast(tals,expect2);
                addLast(tals,expect3);
            }
        }
        else if(cur.instruction_id == ori)
        {
            int32_t num = cur.immediate;
            if(num>>16 == 0x00000000)
            {
                if(strcmp(cur.label,"") == 0)
                {
                    addLast(tals,cur);
                }else
                {
                    struct Instruction expect1 = CreateOri_lab(cur.rt,cur.rs,cur.immediate,cur.label);
                    addLast(tals,expect1);
                }
            }
            else
            {
                struct Instruction expect1;
                if(strcmp(cur.label,"") != 0)
                {
                    expect1 = CreateLui_lab(1,(num>>16) & 0x0000FFFF,cur.label);
                }else
                {
                    expect1 = CreateLui(1,(num>>16) & 0x0000FFFF);
                }
                struct Instruction expect2 = CreateOri(1,1,num & 0x0000FFFF);
                struct Instruction expect3 = CreateOr(cur.rt, cur.rs,1);
                addLast(tals,expect1);
                addLast(tals,expect2);
                addLast(tals,expect3);
            }
        }
        else
        {
            addLast(tals,cur);
        }
    }
}
