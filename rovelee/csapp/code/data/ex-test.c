#include "ex-code.c"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    /* 带参数输入题号，运行对应题号的程序 */
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
        case 237:
            ex237();
        case 238:
            ex238();
            break;
        case 240:
            ex240();
            break;
        case 241:
            ex241();
            break;
        case 242:
            ex242();
            break;
        case 243:
            ex243();
            break;
        case 244:
            ex244();
            break;
        case 245:
            ex245();
            break;
        case 246:
            ex246();
            break;
        default:
            break;
        }
    }

    return 0;
}
