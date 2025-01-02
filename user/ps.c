#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
enum COLOR
{
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    VIOLET,

};
#include "kernel/pstat.h"



int main(int argc, char* argv[])
{
    struct pstat a;
    getpinfo(&a);
    //printf("NAME\tPID\tSTATUS\t   COLOR   TICKETS\n");
    printf("Name\tPID\tSTATUS  \tCOLOR\tTICKETS\n");

    for(int i=0; i<NPROC; i++)
    {
        //char status[20];
        //char color[20];
        char *color = "";
        char *status = "";

        if(a.state[i] != UNUSED)
        {
        switch(a.state[i])
        {
            case UNUSED:
            status = "UNUSED  ";
            break;

            case USED:
            status = "USED    ";
            break;

            case SLEEPING:
            status = "SLEEPING";
            break;

            case RUNNABLE:
            status = "RUNNABLE";
            break;

            case RUNNING:
            status = "RUNNING";
            break;

            case ZOMBIE:
            status = "ZOMBIE  ";
            //strncpy(status, "ZOMBIE", 7);
            break;
        }

        switch(a.color[i])
        {
            case RED:
            color = "RED   ";
            break;

            case ORANGE:
            color = "ORANGE";
            break;

            case YELLOW:
            color = "YELLOW";
            break;

            case GREEN:
            color = "GREEN ";
            break;

            case BLUE:
            color = "BLUE  ";
            break;

            case INDIGO:
            color = "INDIGO";
            break;

            case VIOLET:
            color = "VIOLET";
            //strncpy(color,"VIOLET", 7);
            break;
        }
        //printf("%s\t%d\t%s   %s\t   %d\t\n", a.name[i], a.pid[i], status, color, a.tickets[i]);
        printf("%s\t%d\t%s  \t%s\t%d\t\n", a.name[i], a.pid[i], status, color, a.tickets[i]);
        }
    }
    
    return 0;
}

