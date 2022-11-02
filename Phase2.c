#include "Phase2.h"
#include <string.h>
#include "InstructionFactory.h"
#include "ArrayList.h"
#include "stdio.h"

void resolve_addresses(struct ArrayList *unresolved, uint32_t first_pc, struct ArrayList *resolved)
{
    int size = unresolved->size;
    for (int i = 0; i < size; i++)
    {
        struct Instruction cur = get(unresolved,i);
        if (strcmp(cur.branch_label,"") != 0)
        {
            for (int j = 0; j < size; j++)
            {
                struct Instruction cur2 = get(unresolved,j);
                if (strcmp(cur2.label, cur.branch_label) == 0)
                {
                    cur.immediate = j - i - 1;
                    break;
                }
            }
        }
        addLast(resolved,cur);
    }
}

