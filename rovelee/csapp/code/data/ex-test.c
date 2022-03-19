#include "ex-code.c"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < argc; ++i)
    {
        switch (atoi(argv[i]))
        {
        case 213:
            ex213();
            break;
        case 214:
            ex214();
            break;
        case 215:
            ex215();
            break;
        case 220:
            ex220();
            break;
        case 221:
            ex221();
            break;
        case 222:
            ex222();
            break;

        default:
            break;
        }
    }

    return 0;
}
