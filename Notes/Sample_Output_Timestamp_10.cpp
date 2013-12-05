/********     FCFS Algorithm     ********/

t = 0
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 10
Servicing FCFS job 2: CPU_burst(11) IO_burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0
current state of device queue: 1

t = 20
Servicing FCFS job 2: CPU_burst(1) IO_burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 30
Servicing FCFS job 6: CPU_burst(3) IO_burst(0)
current state of ready queue: 7-8-9-0-1-3-4
current state of device queue: 5

t = 40
Servicing FCFS job 7: CPU_burst(1) IO_burst(7)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: EMPTY

t = 50
Servicing FCFS job 8: CPU_burst(5) IO_burst(0)
current state of ready queue: 9-0-1-3-4-5-7
current state of device queue: EMPTY

t = 60
Servicing FCFS job 0: CPU_burst(1) IO_burst(0)
current state of ready queue: 1-3-4-5-7
current state of device queue: 9

t = 70
JOB 4 DONE
CPU loading job 5: CPU burst(3) IO burst(0)
current state of ready queue: 5-7-9
current state of device queue: EMPTY

t = 80
Servicing FCFS job 7: CPU_burst(1) IO_burst(0)
current state of ready queue: 9
current state of device queue: EMPTY



Final report for FCFS algorithm.

THROUGHPUT = 0.12195122

PROCESS ID  WAIT TIME
    0       47
    1       55
    2        9
    3       60
    4       59
    5       63
    6       29
    7       58
    8       41
    9       70
AVERAGE WAITING TIME = 49.1

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 0-1-2-3-4-5-6-7-8-9-0-1-3-4-5-7-9

PROCESS ID  TURN AROUND TIME
    0       61
    1       65
    2       21
    3       66
    4       70
    5       73
    6       33
    7       81
    8       55
    9       82
AVERAGE TURN AROUND = 60.7



/********         SJF Algorithm        ********/

t = 0
CPU loading job 3: CPU burst(1) IO burst(4)
current state of ready queue: 3-9-5-1-4-6-0-7-2-8
current state of device queue: EMPTY

t = 10
Job 1 finished  CPU burst
CPU loading job 5: CPU burst(3) IO burst(0)
current state of ready queue: 5-4-6-0-7-2-8
current state of device queue: 9-1

t = 20
Servicing SJF job 4: CPU_burst(2) IO_burst(3)
current state of ready queue: 6-0-7-2-8
current state of device queue: EMPTY

t = 30
JOB 4 DONE
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 40
Servicing SJF job 7: CPU_burst(3) IO_burst(7)
current state of ready queue: 0-2-8
current state of device queue: EMPTY

t = 50
Servicing SJF job 2: CPU_burst(10) IO_burst(0)
current state of ready queue: 7-8
Job 7 finished  I/O burst
current state of device queue: EMPTY

t = 60
JOB 2 DONE
CPU loading job 7: CPU burst(8) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 70
Servicing SJF job 8: CPU_burst(12) IO_burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 80
Servicing SJF job 8: CPU_burst(2) IO_burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY



Final report for SJF algorithm.

THROUGHPUT = 0.12195122

PROCESS ID  WAIT TIME
    0       34
    1        8
    2       48
    3        0
    4       19
    5        3
    6       22
    7       45
    8       68
    9        2
AVERAGE WAITING TIME = 24.9

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 3-9-5-3-1-5-9-1-4-6-4-0-7-0-2-7-8

PROCESS ID  TURN AROUND TIME
    0ab 48
    1       18
    2       60
    3        6
    4       30
    5       13
    6       26
    7       68
    8       82
    9       14
AVERAGE TURN AROUND = 36.5



/********         SJR Algorithm          ********/

t = 0
CPU loading job 3: CPU burst(1) IO burst(4)
current state of ready queue: 3-9-5-1-4-6-0-7-2-8
current state of device queue: EMPTY

t = 10
Job 1 finished  CPU burst
CPU loading job 5: CPU burst(3) IO burst(0)
current state of ready queue: 5-4-6-0-7-2-8
current state of device queue: 9 1

t = 20
Servicing SJR job 4: CPU_burst(2) IO_burst(3)
current state of ready queue: 6-0-7-2-8
current state of device queue: EMPTY

t = 30
JOB 4 DONE
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 40
Servicing SJR job 7: CPU_burst(3) IO_burst(7)
current state of ready queue: 0-2-8
current state of device queue: EMPTY

t = 50
Job 2 finished  CPU burst
CPU loading job 7: CPU burst(8) IO burst(0)
current state of ready queue: 7-8
Job 7 finished  I/O burst
current state of device queue: EMPTY

t = 60
Servicing SJR job 2: CPU_burst(8) IO_burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 70
Servicing SJR job 8: CPU_burst(12) IO_burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 80
Servicing SJR job 8: CPU_burst(2) IO_burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY



Final report for SJR algorithm.

THROUGHPUT = 0.12195122

PROCESS ID  WAIT TIME
    0       34
    1        8
    2       56
    3        0
    4       19
    5        3
    6       22
    7       35
    8       68
    9        2
AVERAGE WAITING TIME = 24.7

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 3-9-5-3-1-5-9-1-4-6-4-0-7-0-2-7-2-8

PROCESS ID  TURN AROUND TIME
    0       48
    1       18
    2       68
    3        6
    4       30
    5       13
    6       26
    7       58
    8       82
    9       14
AVERAGE TURN AROUND = 36.3



/********         RR Algorithm  (time quantum 3)       ********/
t = 0
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 10
Job 3  finished  CPU burst
CPU loading job 4: CPU burst(4) IO burst(3)
current state of ready queue: 4-5-6-7-8-9-0-1-2
current state of device queue: 3

t = 20
Servicing RR job 7: CPU_burst(7) IO_burst(7)
current state of ready queue: 8-9-0-1-2-4-3-6-5
current state of device queue: EMPTY

t = 30
Servicing RR job 2: CPU_burst(8) IO_burst(0)
current state of ready queue: 4-3-6-5-7-8
current state of device queue: 9-0-1

t = 40
Servicing RR job 7: CPU_burst(3) IO_burst(7)
current state of ready queue: 8-1-0-2-4-9
current state of device queue: EMPTY

t = 50
Job 0 finished  CPU burst
CPU loading job 2: CPU burst(6) IO burst(0)
current state of ready queue: 2-4-9-7-8-1-0
current state of device queue: EMPTY

t = 60
Servicing RR job 8: CPU_burst(7) IO_burst(0)
current state of ready queue: 1-0-2-4
current state of device queue: 7

t = 70
Servicing RR job 8: CPU_burst(4) IO_burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 80
Servicing RR job 7: CPU_burst(2) IO_burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY



Final report for RR algorithm.

THROUGHPUT = 0.12195122

PROCESS ID  WAIT TIME
    0       51
    1       53
    2       56
    3       28
    4       58
    5       28
    6       31
    7       59
    8       63
    9       45
AVERAGE WAITING TIME = 47.2

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 0-1-2-3-4-5-6-7-8-9-0-1-2-4-3-6-5-7-8-1-0-2-4-9-7-8-1-0-2-4-8-7-8-7-7

PROCESS ID  TURN AROUND TIME
    0       65
    1       63
    2       68
    3       34
    4       69
    5       38
    6       35
    7       82
    8       77
    9       57
AVERAGE TURN AROUND = 58.8



/*********       Priority Algorithm         ********/

t = 0
CPU loading job 4: CPU burst(4) IO burst(3)
current state of ready queue: 4-1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 10
Servicing PS job 4: CPU_burst(1) IO_burst(0)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 20
Servicing PS job 8: CPU_burst(10) IO_burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 30
JOB 8 DONE
CPU loading job 9: CPU burst(1) IO burst(10)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 40
Job 3 finished  CPU burst
CPU loading job 0: CPU burst(5) IO burst(0)
current state of ready queue: 0-2-6-7
Job 0 finished  I/O burst
current state of device queue: 9-5-3

t = 50
JOB 3 DONE
CPU loading job 2: CPU burst(12) IO burst(0)
current state of ready queue: 2-6-7
current state of device queue: EMPTY

t = 60
Servicing PS job 2: CPU_burst(2) IO_burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 70
Servicing PS job 7: CPU_burst(4) IO_burst(7)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 80
CPU is waiting.
current state of ready queue: EMPTY
current state of device queue: 7



Final report for PS algorithm.

THROUGHPUT = 0.11235955

PROCESS ID  WAIT TIME
    0       32
    1       8
    2       50
    3       44
    4       0
    5       39
    6       62
    7       66
    8       16
    9       30
AVERAGE WAITING TIME = 34.7

CPU UTILIZATION = 92%

SEQUENCE OF PROCESSES IN CPU: 4-1-4-1-8-1-8-9-0-5-3-0-9-0-5-3-2-6-7-7

PROCESS ID  TURN AROUND TIME
    0       46
    1       18
    2       62
    3       50
    4       11
    5       49
    6       66
    7       89
    8       30
    9       42
AVERAGE TURN AROUND = 46.3


***** Multi-Level Feedback Queue Scheduling *****
t = 0   Loading job 0
Order of queue 1 -> 1 2 3 4 5 6 7 8 9
Order of queue 2 -> empty.
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 2   Processing job 0
Order of queue 1 -> 1 2 3 4 5 6 7 8 9
Order of queue 2 -> empty.
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 4   Processing job 1
Order of queue 1 -> 2 3 4 5 6 7 8 9
Order of queue 2 -> 0
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 6   Loading job 2
Order of queue 1 -> 3 4 5 6 7 8 9
Order of queue 2 -> 0 1
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 8   Processing job 2
Order of queue 1 -> 3 4 5 6 7 8 9
Order of queue 2 -> 0 1
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 10  Loading job 4
Order of queue 1 -> 5 6 7 8 9
Order of queue 2 -> 0 1 2
Order of queue 3 -> empty.

Order of I/O queue-> 3

t = 12  Processing job 4
Order of queue 1 -> 5 6 7 8 9
Order of queue 2 -> 0 1 2
Order of queue 3 -> empty.

Order of I/O queue-> 3

t = 14  Processing job 5
Order of queue 1 -> 6 7 8 9 3
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 16  Loading job 6
Order of queue 1 -> 7 8 9 3
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> empty.

Order of I/O queue-> 5

t = 18  Processing job 6
Order of queue 1 -> 7 8 9 3
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> empty.

Order of I/O queue-> 5

t = 20  Processing job 7
Order of queue 1 -> 8 9 3 5
Order of queue 2 -> 0 1 2 4 6
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 22  Loading job 8
Order of queue 1 -> 9 3 5
Order of queue 2 -> 0 1 2 4 6 7
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 24  Processing job 8
Order of queue 1 -> 9 3 5
Order of queue 2 -> 0 1 2 4 6 7
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 26  Loading job 3
Order of queue 1 -> 5
Order of queue 2 -> 0 1 2 4 6 7 8
Order of queue 3 -> empty.

Order of I/O queue-> 9

t = 28  Processing job 5
Order of queue 1 -> empty.
Order of queue 2 -> 0 1 2 4 6 7 8
Order of queue 3 -> empty.

Order of I/O queue-> 9

t = 30  Loading job 0
Order of queue 1 -> empty.
Order of queue 2 -> 1 2 4 6 7 8
Order of queue 3 -> empty.

Order of I/O queue-> 9

t = 32  Loading job 1
Order of queue 1 -> empty.
Order of queue 2 -> 2 4 6 7 8
Order of queue 3 -> empty.

Order of I/O queue-> 9,0

t = 34  Processing job 2
Order of queue 1 -> empty.
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> empty.

Order of I/O queue-> 9,0,1

t = 36  Processing job 2
Order of queue 1 -> 1 9 0
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 38  Processing job 2
Order of queue 1 -> 1 9 0
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 40  Processing job 1
Order of queue 1 -> 9 0
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> 2

Order of I/O queue-> empty


t = 42  Loading job 9
Order of queue 1 -> 0
Order of queue 2 -> 4 6 7 8 1
Order of queue 3 -> 2

Order of I/O queue-> empty


t = 44  Processing job 0
Order of queue 1 -> empty.
Order of queue 2 -> 4 6 7 8 1
Order of queue 3 -> 2

Order of I/O queue-> empty


t = 46  Loading job 4
Order of queue 1 -> empty.
Order of queue 2 -> 6 7 8 1 0
Order of queue 3 -> 2

Order of I/O queue-> empty


t = 48  Loading job 7
Order of queue 1 -> empty.
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2

Order of I/O queue-> 4

t = 50  Processing job 7
Order of queue 1 -> 4
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2

Order of I/O queue-> empty


t = 52  Processing job 7
Order of queue 1 -> 4
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2

Order of I/O queue-> empty


t = 54  Processing job 4
Order of queue 1 -> empty.
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2

Order of I/O queue-> 7

t = 56  Loading job 8
Order of queue 1 -> empty.
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2

Order of I/O queue-> 7

t = 58  Processing job 8
Order of queue 1 -> empty.
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2

Order of I/O queue-> 7

t = 60  Processing job 8
Order of queue 1 -> 7
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2

Order of I/O queue-> empty


t = 62  Loading job 7
Order of queue 1 -> empty.
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2 8

Order of I/O queue-> empty


t = 64  Processing job 7
Order of queue 1 -> empty.
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2 8

Order of I/O queue-> empty


t = 66  Loading job 0
Order of queue 1 -> empty.
Order of queue 2 -> 4 7
Order of queue 3 -> 2 8

Order of I/O queue-> empty


t = 68  Loading job 4
Order of queue 1 -> empty.
Order of queue 2 -> 7
Order of queue 3 -> 2 8

Order of I/O queue-> empty


t = 70  Processing job 7
Order of queue 1 -> empty.
Order of queue 2 -> empty.
Order of queue 3 -> 2 8

Order of I/O queue-> empty


t = 72  Processing job 7
Order of queue 1 -> empty.
Order of queue 2 -> empty.
Order of queue 3 -> 2 8

Order of I/O queue-> empty


t = 74  Loading job 2
Order of queue 1 -> empty.
Order of queue 2 -> empty.
Order of queue 3 -> 8

Order of I/O queue-> empty


t = 76  Processing job 2
Order of queue 1 -> empty.
Order of queue 2 -> empty.
Order of queue 3 -> 8

Order of I/O queue-> empty


t = 78  Processing job 8
Order of queue 1 -> empty.
Order of queue 2 -> empty.
Order of queue 3 -> empty.

Order of I/O queue-> empty


t = 80  Processing job 8
Order of queue 1 -> empty.
Order of queue 2 -> empty.
Order of queue 3 -> empty.

Order of I/O queue-> empty


*** Summary Statistics ***
Throughput = 10 jobs / 82 seconds = 0.121951 jobs/second

Wait times:
Process 0 wait time 54
Process 1 wait time 56
Process 2 wait time 65
Process 3 wait time 21
Process 4 wait time 58
Process 5 wait time 20
Process 6 wait time 44
Process 7 wait time 51
Process 8 wait time 68
Process 9 wait time 31
Average wait time: 46.80

Turnaround Times:
Process 0 turnaround time 68
Process 1 turnaround time 66
Process 2 turnaround time 77
Process 3 turnaround time 27
Process 4 turnaround time 69
Process 5 turnaround time 30
Process 6 turnaround time 48
Process 7 turnaround time 74
Process 8 turnaround time 82
Process 9 turnaround time 43
Average turnaround time: 58.40

CPU usage: 100.00

30 context switches

****** Algorithm Comparison *******

Thruput Comparison:
1. First Come First Served: 0.12
2. Shortest Job First: 0.12
3. Round Robin: 0.12
4. Shortest Job Remaining: 0.12
5. Multi-Level Feedback Queue Scheduling: 0.12
6. Priority Scheduling: 0.11

Wait Times Comparison:
1. Shortest Job Remaining: 24.70
2. Shortest Job First: 24.90
3. Priority Scheduling: 34.60
4. Multi-Level Feedback Queue Scheduling: 46.80
5. Round Robin: 46.90
6. First Come First Served: 49.10

Turnaround Time Comparison:
1. Shortest Job Remaining: 36.30
2. Shortest Job First: 36.50
3. Priority Scheduling: 46.20
4. Multi-Level Feedback Queue Scheduling: 58.40
5. Round Robin: 58.50
6. First Come First Served: 60.70

CPU Usage Comparison:
1. First Come First Served: 100.00
2. Shortest Job First: 100.00
3. Round Robin: 100.00
4. Shortest Job Remaining: 100.00
5. Multi-Level Feedback Queue Scheduling: 100.00
6. Priority Scheduling: 92.05

Context Switches Comparison:
1. First Come First Served: 17
2. Shortest Job First: 17
3. Shortest Job Remaining: 18
4. Priority Scheduling: 20
5. Multi-Level Feedback Queue Scheduling: 30
6. Round Robin: 34

/******   Make your comments and recommendations here   ******/
