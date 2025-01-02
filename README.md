This project implements an enhanced process scheduling system with novel features such as process color attributes, ticket-based CPU allocation, and detailed process status tracking. Below is a breakdown of the features and how they were implemented:

System Call: setColor(enum COLOR)

The setColor system call allows assigning a color attribute to processes. 

Each process’s color is stored in its Process Control Block (PCB). This system call ensures:

- Successful Execution: Returns 0 for valid inputs.

- Error Handling: Returns -1 for invalid color inputs.

By incorporating this functionality, process management is more intuitive and supports enhanced visibility during debugging and monitoring.

System Call: setTickets(int)

The setTickets system call adjusts the number of tickets allocated to a process, directly influencing the probability of the process being selected for execution. Key details include:

- Default Allocation: Each process is assigned 1 ticket at creation.

- Inheritance: Child processes inherit the parent’s ticket count upon creation.

- Range Enforcement: Valid ticket values range from 1 to 256.

- Successful Execution: Returns 0 for valid ticket values.

- Error Handling: Returns -1 for invalid values (e.g., less than 1).

This approach ensures fair and flexible CPU allocation, promoting workload prioritization when necessary.

System Call: getpinfo(struct pstat *)

The getpinfo system call provides detailed information about all running processes, facilitating the creation of user-space tools for monitoring. The pstat structure includes:

- Process names

- Process IDs (PIDs)

- Current state (e.g., SLEEPING, RUNNING)

- Tickets allocated

- Color attribute

- CPU ticks accumulated

- Careful handling of user-space pointers ensures security and reliability. This system call returns 0 on success and -1 for invalid or null pointers.

- Pseudo-Random Number Generator

To support ticket-based scheduling, a kernel-level pseudo-random number generator was implemented. This generator uses a simple and efficient algorithm to ensure uniform randomness while adhering to kernel constraints. The random number generator plays a critical role in fair process selection.

Command-Line Tool: ps

A custom ps command-line tool was developed to display process information:

NAME    PID     STATUS      COLOR    TICKETS
init    1       SLEEPING    RED      10    
sh      2       SLEEPING    ORANGE   2
test    4       SLEEPING    RED      4
ps      6       RUNNING     INDIGO   1

This tool leverages the getpinfo system call, providing an insightful view of the system’s current state and aiding in administrative tasks.


The scheduler was extended to incorporate a lottery-based system using process tickets:

- Ticket Allocation: Processes are selected for execution proportional to their ticket count.

- Inheritance: Children inherit the ticket count of their parent process.

- Color Integration: The setColor attribute provides an additional layer of process identification and management.

The implementation required modifications to proc.c and proc.h, ensuring seamless integration with the existing scheduler framework. Control flow adjustments were minimal yet impactful, focusing on ticket-based selection and process state tracking.
        

