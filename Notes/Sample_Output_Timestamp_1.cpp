/***********  First-Come, First Served Algorithm ***********/

t = 0
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 1
Servicing FCFS job 0: CPU burst(4) IO burst(4)
current state of ready queue: 1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 2
Servicing FCFS job 0: CPU burst(3) IO burst(4)
current state of ready queue: 1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 3
Servicing FCFS job 0: CPU burst(2) IO burst(4)
current state of ready queue: 1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 4
Servicing FCFS job 0: CPU burst(1) IO burst(4)
current state of ready queue: 1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 5
JOB 0 finished CPU burst
CPU loading job 1: CPU burst(4) IO burst(2)
current state of ready queue: 1-2-3-4-5-6-7-8-9
current state of device queue: 0

t = 6
Servicing FCFS job 1: CPU burst(3) IO burst(2)
current state of ready queue: 2-3-4-5-6-7-8-9
current state of device queue: 0

t = 7
Servicing FCFS job 1: CPU burst(2) IO burst(2)
current state of ready queue: 2-3-4-5-6-7-8-9
current state of device queue: 0

t = 8
Servicing FCFS job 1: CPU burst(1) IO burst(2)
current state of ready queue: 2-3-4-5-6-7-8-9
current state of device queue: 0

t = 9
JOB 1 finished CPU burst
CPU loading job 2: CPU burst(12) IO burst(0)
current state of ready queue: 2-3-4-5-6-7-8-9-0
Job 0 finished I/O burst
current state of device queue: 1

t = 10
Servicing FCFS job 2: CPU burst(11) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0
current state of device queue: 1

t = 11
Servicing FCFS job 2: CPU burst(10) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
Job 1 finished I/O burst
current state of device queue: EMPTY

t = 12
Servicing FCFS job 2: CPU burst(9) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 13
Servicing FCFS job 2: CPU burst(8) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 14
Servicing FCFS job 2: CPU burst(7) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 15
Servicing FCFS job 2: CPU burst(6) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 16
Servicing FCFS job 2: CPU burst(5) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 17
Servicing FCFS job 2: CPU burst(4) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 18
Servicing FCFS job 2: CPU burst(3) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 19
Servicing FCFS job 2: CPU burst(2) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 20
Servicing FCFS job 2: CPU burst(1) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 21
JOB 2 DONE
CPU loading job 3: CPU burst(1) IO burst(4)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 22
JOB 3 finished CPU burst
CPU loading job 4: CPU burst(4) IO burst(3)
current state of ready queue: 4-5-6-7-8-9-0-1
current state of device queue: 3

t = 23
Servicing FCFS job 4: CPU burst(3) IO burst(3)
current state of ready queue: 5-6-7-8-9-0-1
current state of device queue: 3

t = 24
Servicing FCFS job 4: CPU burst(2) IO burst(3)
current state of ready queue: 5-6-7-8-9-0-1
current state of device queue: 3

t = 25
Servicing FCFS job 4: CPU burst(1) IO burst(3)
current state of ready queue: 5-6-7-8-9-0-1
current state of device queue: 3

t = 26
JOB 4 finished CPU burst
CPU loading job 5: CPU burst(3) IO burst(4)
current state of ready queue: 5-6-7-8-9-0-1-3
Job 3 finished I/O burst
current state of device queue: 4

t = 27
Servicing FCFS job 5: CPU burst(2) IO burst(4)
current state of ready queue: 6-7-8-9-0-1-3
current state of device queue: 4

t = 28
Servicing FCFS job 5: CPU burst(1) IO burst(4)
current state of ready queue: 6-7-8-9-0-1-3
current state of device queue: 4

t = 29
JOB 5 finished CPU burst
CPU loading job 6: CPU burst(4) IO burst(0)
current state of ready queue: 6-7-8-9-0-1-3-4
Job 4 finished I/O burst
current state of device queue: 5

t = 30
Servicing FCFS job 6: CPU burst(3) IO burst(0)
current state of ready queue: 7-8-9-0-1-3-4
current state of device queue: 5

t = 31
Servicing FCFS job 6: CPU burst(2) IO burst(0)
current state of ready queue: 7-8-9-0-1-3-4
current state of device queue: 5

t = 32
Servicing FCFS job 6: CPU burst(1) IO burst(0)
current state of ready queue: 7-8-9-0-1-3-4
current state of device queue: 5

t = 33
JOB 6 DONE
CPU loading job 7: CPU burst(8) IO burst(7)
current state of ready queue: 7-8-9-0-1-3-4-5
Job 5 finished I/O burst
current state of device queue: EMPTY

t = 34
Servicing FCFS job 7: CPU burst(7) IO burst(7)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: EMPTY

t = 35
Servicing FCFS job 7: CPU burst(6) IO burst(7)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: EMPTY

t = 36
Servicing FCFS job 7: CPU burst(5) IO burst(7)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: EMPTY

t = 37
Servicing FCFS job 7: CPU burst(4) IO burst(7)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: EMPTY

t = 38
Servicing FCFS job 7: CPU burst(3) IO burst(7)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: EMPTY

t = 39
Servicing FCFS job 7: CPU burst(2) IO burst(7)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: EMPTY

t = 40
Servicing FCFS job 7: CPU burst(1) IO burst(7)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: EMPTY

t = 41
JOB 7 finished CPU burst
CPU loading job 8: CPU burst(14) IO burst(0)
current state of ready queue: 8-9-0-1-3-4-5
current state of device queue: 7

t = 42
Servicing FCFS job 8: CPU burst(13) IO burst(0)
current state of ready queue: 9-0-1-3-4-5
current state of device queue: 7

t = 43
Servicing FCFS job 8: CPU burst(12) IO burst(0)
current state of ready queue: 9-0-1-3-4-5
current state of device queue: 7

t = 44
Servicing FCFS job 8: CPU burst(11) IO burst(0)
current state of ready queue: 9-0-1-3-4-5
current state of device queue: 7

t = 45
Servicing FCFS job 8: CPU burst(10) IO burst(0)
current state of ready queue: 9-0-1-3-4-5
current state of device queue: 7

t = 46
Servicing FCFS job 8: CPU burst(9) IO burst(0)
current state of ready queue: 9-0-1-3-4-5
current state of device queue: 7

t = 47
Servicing FCFS job 8: CPU burst(8) IO burst(0)
current state of ready queue: 9-0-1-3-4-5
current state of device queue: 7

t = 48
Servicing FCFS job 8: CPU burst(7) IO burst(0)
current state of ready queue: 9-0-1-3-4-5-7
Job 7 finished I/O burst
current state of device queue: EMPTY

t = 49
Servicing FCFS job 8: CPU burst(6) IO burst(0)
current state of ready queue: 9-0-1-3-4-5-7
current state of device queue: EMPTY

t = 50
Servicing FCFS job 8: CPU burst(5) IO burst(0)
current state of ready queue: 9-0-1-3-4-5-7
current state of device queue: EMPTY

t = 51
Servicing FCFS job 8: CPU burst(4) IO burst(0)
current state of ready queue: 9-0-1-3-4-5-7
current state of device queue: EMPTY

t = 52
Servicing FCFS job 8: CPU burst(3) IO burst(0)
current state of ready queue: 9-0-1-3-4-5-7
current state of device queue: EMPTY

t = 53
Servicing FCFS job 8: CPU burst(2) IO burst(0)
current state of ready queue: 9-0-1-3-4-5-7
current state of device queue: EMPTY

t = 54
Servicing FCFS job 8: CPU burst(1) IO burst(0)
current state of ready queue: 9-0-1-3-4-5-7
current state of device queue: EMPTY

t = 55
JOB 8 DONE
CPU loading job 9: CPU burst(1) IO burst(10)
current state of ready queue: 9-0-1-3-4-5-7
current state of device queue: EMPTY

t = 56
JOB 9 finished CPU burst
CPU loading job 0: CPU burst(5) IO burst(0)
current state of ready queue: 0-1-3-4-5-7
current state of device queue: 9

t = 57
Servicing FCFS job 0: CPU burst(4) IO burst(0)
current state of ready queue: 1-3-4-5-7
current state of device queue: 9

t = 58
Servicing FCFS job 0: CPU burst(3) IO burst(0)
current state of ready queue: 1-3-4-5-7
current state of device queue: 9

t = 59
Servicing FCFS job 0: CPU burst(2) IO burst(0)
current state of ready queue: 1-3-4-5-7
current state of device queue: 9

t = 60
Servicing FCFS job 0: CPU burst(1) IO burst(0)
current state of ready queue: 1-3-4-5-7
current state of device queue: 9

t = 61
JOB 0 DONE
CPU loading job 1: CPU burst(4) IO burst(0)
current state of ready queue: 1-3-4-5-7
current state of device queue: 9

t = 62
Servicing FCFS job 1: CPU burst(3) IO burst(0)
current state of ready queue: 3-4-5-7
current state of device queue: 9

t = 63
Servicing FCFS job 1: CPU burst(2) IO burst(0)
current state of ready queue: 3-4-5-7
current state of device queue: 9

t = 64
Servicing FCFS job 1: CPU burst(1) IO burst(0)
current state of ready queue: 3-4-5-7
current state of device queue: 9

t = 65
JOB 1 DONE
CPU loading job 3: CPU burst(1) IO burst(0)
current state of ready queue: 3-4-5-7
current state of device queue: 9

t = 66
JOB 3 DONE
CPU loading job 4: CPU burst(4) IO burst(0)
current state of ready queue: 4-5-7-9
Job 9 finished I/O burst
current state of device queue: EMPTY

t = 67
Servicing FCFS job 4: CPU burst(3) IO burst(0)
current state of ready queue: 5-7-9
current state of device queue: EMPTY

t = 68
Servicing FCFS job 4: CPU burst(2) IO burst(0)
current state of ready queue: 5-7-9
current state of device queue: EMPTY

t = 69
Servicing FCFS job 4: CPU burst(1) IO burst(0)
current state of ready queue: 5-7-9
current state of device queue: EMPTY

t = 70
JOB 4 DONE
CPU loading job 5: CPU burst(3) IO burst(0)
current state of ready queue: 5-7-9
current state of device queue: EMPTY

t = 71
Servicing FCFS job 5: CPU burst(2) IO burst(0)
current state of ready queue: 7-9
current state of device queue: EMPTY

t = 72
Servicing FCFS job 5: CPU burst(1) IO burst(0)
current state of ready queue: 7-9
current state of device queue: EMPTY

t = 73
JOB 5 DONE
CPU loading job 7: CPU burst(8) IO burst(0)
current state of ready queue: 7-9
current state of device queue: EMPTY

t = 74
Servicing FCFS job 7: CPU burst(7) IO burst(0)
current state of ready queue: 9
current state of device queue: EMPTY

t = 75
Servicing FCFS job 7: CPU burst(6) IO burst(0)
current state of ready queue: 9
current state of device queue: EMPTY

t = 76
Servicing FCFS job 7: CPU burst(5) IO burst(0)
current state of ready queue: 9
current state of device queue: EMPTY

t = 77
Servicing FCFS job 7: CPU burst(4) IO burst(0)
current state of ready queue: 9
current state of device queue: EMPTY

t = 78
Servicing FCFS job 7: CPU burst(3) IO burst(0)
current state of ready queue: 9
current state of device queue: EMPTY

t = 79
Servicing FCFS job 7: CPU burst(2) IO burst(0)
current state of ready queue: 9
current state of device queue: EMPTY

t = 80
Servicing FCFS job 7: CPU burst(1) IO burst(0)
current state of ready queue: 9
current state of device queue: EMPTY

t = 81
JOB 7 DONE
CPU loading job 9: CPU burst(1) IO burst(0)
current state of ready queue: 9
current state of device queue: EMPTY

Final report for FCFS algorithm.

THROUGHPUT = 0.12195122

Process ID	Wait Time
    0     	    47
    1     	    55
    2     	     9
    3     	    60
    4     	    59
    5     	    63
    6     	    29
    7     	    58
    8     	    41
    9     	    70
AVERAGE WAITING TIME = 49.1

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 0-1-2-3-4-5-6-7-8-9-0-1-3-4-5-7-9

Process ID	Turnaround Time
    0    	      61
    1    	      65
    2    	      21
    3    	      66
    4    	      70
    5    	      73
    6    	      33
    7    	      81
    8    	      55
    9    	      82
AVERAGE TURNAROUND TIME = 60.7

/***********  Shortest-Job-First Algorithm ***********/

t = 0
CPU loading job 3: CPU burst(1) IO burst(4)
current state of ready queue: 3-9-5-1-4-6-0-7-2-8
current state of device queue: EMPTY

t = 1
JOB 3 finished CPU burst
CPU loading job 9: CPU burst(1) IO burst(10)
current state of ready queue: 9-5-1-4-6-0-7-2-8
current state of device queue: 3

t = 2
JOB 9 finished CPU burst
CPU loading job 5: CPU burst(3) IO burst(4)
current state of ready queue: 5-1-4-6-0-7-2-8
current state of device queue: 3-9

t = 3
Servicing SJF job 5: CPU burst(2) IO burst(4)
current state of ready queue: 1-4-6-0-7-2-8
current state of device queue: 3-9

t = 4
Servicing SJF job 5: CPU burst(1) IO burst(4)
current state of ready queue: 1-4-6-0-7-2-8
current state of device queue: 3-9

t = 5
JOB 5 finished CPU burst
CPU loading job 3: CPU burst(1) IO burst(0)
current state of ready queue: 3-1-4-6-0-7-2-8
Job 3 finished I/O burst
current state of device queue: 9-5

t = 6
JOB 3 DONE
CPU loading job 1: CPU burst(4) IO burst(2)
current state of ready queue: 1-4-6-0-7-2-8
current state of device queue: 9-5

t = 7
Servicing SJF job 1: CPU burst(3) IO burst(2)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: 9-5

t = 8
Servicing SJF job 1: CPU burst(2) IO burst(2)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: 9-5

t = 9
Servicing SJF job 1: CPU burst(1) IO burst(2)
current state of ready queue: 5-4-6-0-7-2-8
Job 5 finished I/O burst
current state of device queue: 9

t = 10
JOB 1 finished CPU burst
CPU loading job 5: CPU burst(3) IO burst(0)
current state of ready queue: 5-4-6-0-7-2-8
current state of device queue: 9-1

t = 11
Servicing SJF job 5: CPU burst(2) IO burst(0)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: 9-1

t = 12
Servicing SJF job 5: CPU burst(1) IO burst(0)
current state of ready queue: 9-1-4-6-0-7-2-8
Job 9 finished I/O burst
current state of device queue: EMPTY

t = 13
JOB 5 DONE
CPU loading job 9: CPU burst(1) IO burst(0)
current state of ready queue: 9-1-4-6-0-7-2-8
current state of device queue: EMPTY

t = 14
JOB 9 DONE
CPU loading job 1: CPU burst(4) IO burst(0)
current state of ready queue: 1-4-6-0-7-2-8
current state of device queue: EMPTY

t = 15
Servicing SJF job 1: CPU burst(3) IO burst(0)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: EMPTY

t = 16
Servicing SJF job 1: CPU burst(2) IO burst(0)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: EMPTY

t = 17
Servicing SJF job 1: CPU burst(1) IO burst(0)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: EMPTY

t = 18
JOB 1 DONE
CPU loading job 4: CPU burst(4) IO burst(3)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: EMPTY

t = 19
Servicing SJF job 4: CPU burst(3) IO burst(3)
current state of ready queue: 6-0-7-2-8
current state of device queue: EMPTY

t = 20
Servicing SJF job 4: CPU burst(2) IO burst(3)
current state of ready queue: 6-0-7-2-8
current state of device queue: EMPTY

t = 21
Servicing SJF job 4: CPU burst(1) IO burst(3)
current state of ready queue: 6-0-7-2-8
current state of device queue: EMPTY

t = 22
JOB 4 finished CPU burst
CPU loading job 6: CPU burst(4) IO burst(0)
current state of ready queue: 6-0-7-2-8
current state of device queue: 4

t = 23
Servicing SJF job 6: CPU burst(3) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: 4

t = 24
Servicing SJF job 6: CPU burst(2) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: 4

t = 25
Servicing SJF job 6: CPU burst(1) IO burst(0)
current state of ready queue: 4-0-7-2-8
Job 4 finished I/O burst
current state of device queue: EMPTY

t = 26
JOB 6 DONE
CPU loading job 4: CPU burst(4) IO burst(0)
current state of ready queue: 4-0-7-2-8
current state of device queue: EMPTY

t = 27
Servicing SJF job 4: CPU burst(3) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 28
Servicing SJF job 4: CPU burst(2) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 29
Servicing SJF job 4: CPU burst(1) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 30
JOB 4 DONE
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 31
Servicing SJF job 0: CPU burst(4) IO burst(4)
current state of ready queue: 7-2-8
current state of device queue: EMPTY

t = 32
Servicing SJF job 0: CPU burst(3) IO burst(4)
current state of ready queue: 7-2-8
current state of device queue: EMPTY

t = 33
Servicing SJF job 0: CPU burst(2) IO burst(4)
current state of ready queue: 7-2-8
current state of device queue: EMPTY

t = 34
Servicing SJF job 0: CPU burst(1) IO burst(4)
current state of ready queue: 7-2-8
current state of device queue: EMPTY

t = 35
JOB 0 finished CPU burst
CPU loading job 7: CPU burst(8) IO burst(7)
current state of ready queue: 7-2-8
current state of device queue: 0

t = 36
Servicing SJF job 7: CPU burst(7) IO burst(7)
current state of ready queue: 2-8
current state of device queue: 0

t = 37
Servicing SJF job 7: CPU burst(6) IO burst(7)
current state of ready queue: 2-8
current state of device queue: 0

t = 38
Servicing SJF job 7: CPU burst(5) IO burst(7)
current state of ready queue: 2-8
current state of device queue: 0

t = 39
Servicing SJF job 7: CPU burst(4) IO burst(7)
current state of ready queue: 0-2-8
Job 0 finished I/O burst
current state of device queue: EMPTY

t = 40
Servicing SJF job 7: CPU burst(3) IO burst(7)
current state of ready queue: 0-2-8
current state of device queue: EMPTY

t = 41
Servicing SJF job 7: CPU burst(2) IO burst(7)
current state of ready queue: 0-2-8
current state of device queue: EMPTY

t = 42
Servicing SJF job 7: CPU burst(1) IO burst(7)
current state of ready queue: 0-2-8
current state of device queue: EMPTY

t = 43
JOB 7 finished CPU burst
CPU loading job 0: CPU burst(5) IO burst(0)
current state of ready queue: 0-2-8
current state of device queue: 7

t = 44
Servicing SJF job 0: CPU burst(4) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 45
Servicing SJF job 0: CPU burst(3) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 46
Servicing SJF job 0: CPU burst(2) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 47
Servicing SJF job 0: CPU burst(1) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 48
JOB 0 DONE
CPU loading job 2: CPU burst(12) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 49
Servicing SJF job 2: CPU burst(11) IO burst(0)
current state of ready queue: 8
current state of device queue: 7

t = 50
Servicing SJF job 2: CPU burst(10) IO burst(0)
current state of ready queue: 7-8
Job 7 finished I/O burst
current state of device queue: EMPTY

t = 51
Servicing SJF job 2: CPU burst(9) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 52
Servicing SJF job 2: CPU burst(8) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 53
Servicing SJF job 2: CPU burst(7) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 54
Servicing SJF job 2: CPU burst(6) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 55
Servicing SJF job 2: CPU burst(5) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 56
Servicing SJF job 2: CPU burst(4) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 57
Servicing SJF job 2: CPU burst(3) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 58
Servicing SJF job 2: CPU burst(2) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 59
Servicing SJF job 2: CPU burst(1) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 60
JOB 2 DONE
CPU loading job 7: CPU burst(8) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 61
Servicing SJF job 7: CPU burst(7) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 62
Servicing SJF job 7: CPU burst(6) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 63
Servicing SJF job 7: CPU burst(5) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 64
Servicing SJF job 7: CPU burst(4) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 65
Servicing SJF job 7: CPU burst(3) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 66
Servicing SJF job 7: CPU burst(2) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 67
Servicing SJF job 7: CPU burst(1) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 68
JOB 7 DONE
CPU loading job 8: CPU burst(14) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 69
Servicing SJF job 8: CPU burst(13) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 70
Servicing SJF job 8: CPU burst(12) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 71
Servicing SJF job 8: CPU burst(11) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 72
Servicing SJF job 8: CPU burst(10) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 73
Servicing SJF job 8: CPU burst(9) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 74
Servicing SJF job 8: CPU burst(8) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 75
Servicing SJF job 8: CPU burst(7) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 76
Servicing SJF job 8: CPU burst(6) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 77
Servicing SJF job 8: CPU burst(5) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 78
Servicing SJF job 8: CPU burst(4) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 79
Servicing SJF job 8: CPU burst(3) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 80
Servicing SJF job 8: CPU burst(2) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 81
Servicing SJF job 8: CPU burst(1) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

Final report for SJF algorithm.

THROUGHPUT = 0.12195122

Process ID	Wait Time
    0     	    34
    1     	     8
    2     	    48
    3     	     0
    4     	    19
    5     	     3
    6     	    22
    7     	    45
    8     	    68
    9     	     2
AVERAGE WAITING TIME = 24.9

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 3-9-5-3-1-5-9-1-4-6-4-0-7-0-2-7-8

Process ID	Turnaround Time
    0    	      48
    1    	      18
    2    	      60
    3    	       6
    4    	      30
    5    	      13
    6    	      26
    7    	      68
    8    	      82
    9    	      14
AVERAGE TURNAROUND TIME = 36.5

/***********  Shortest-Job-Remaining Algorithm ***********/

t = 0
CPU loading job 3: CPU burst(1) IO burst(4)
current state of ready queue: 3-9-5-1-4-6-0-7-2-8
current state of device queue: EMPTY

t = 1
JOB 3 finished CPU burst
CPU loading job 9: CPU burst(1) IO burst(10)
current state of ready queue: 9-5-1-4-6-0-7-2-8
current state of device queue: 3

t = 2
JOB 9 finished CPU burst
CPU loading job 5: CPU burst(3) IO burst(4)
current state of ready queue: 5-1-4-6-0-7-2-8
current state of device queue: 3-9

t = 3
Servicing SJR job 5: CPU burst(2) IO burst(4)
current state of ready queue: 1-4-6-0-7-2-8
current state of device queue: 3-9

t = 4
Servicing SJR job 5: CPU burst(1) IO burst(4)
current state of ready queue: 1-4-6-0-7-2-8
current state of device queue: 3-9

t = 5
JOB 5 finished CPU burst
CPU loading job 3: CPU burst(1) IO burst(0)
current state of ready queue: 3-1-4-6-0-7-2-8
Job 3 finished I/O burst
current state of device queue: 9-5

t = 6
JOB 3 DONE
CPU loading job 1: CPU burst(4) IO burst(2)
current state of ready queue: 1-4-6-0-7-2-8
current state of device queue: 9-5

t = 7
Servicing SJR job 1: CPU burst(3) IO burst(2)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: 9-5

t = 8
Servicing SJR job 1: CPU burst(2) IO burst(2)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: 9-5

t = 9
Servicing SJR job 1: CPU burst(1) IO burst(2)
current state of ready queue: 5-4-6-0-7-2-8
Job 5 finished I/O burst
current state of device queue: 9

t = 10
JOB 1 finished CPU burst
CPU loading job 5: CPU burst(3) IO burst(0)
current state of ready queue: 5-4-6-0-7-2-8
current state of device queue: 9-1

t = 11
Servicing SJR job 5: CPU burst(2) IO burst(0)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: 9-1

t = 12
Servicing SJR job 5: CPU burst(1) IO burst(0)
current state of ready queue: 9-1-4-6-0-7-2-8
Job 9 finished I/O burst
current state of device queue: EMPTY

t = 13
JOB 5 DONE
CPU loading job 9: CPU burst(1) IO burst(0)
current state of ready queue: 9-1-4-6-0-7-2-8
current state of device queue: EMPTY

t = 14
JOB 9 DONE
CPU loading job 1: CPU burst(4) IO burst(0)
current state of ready queue: 1-4-6-0-7-2-8
current state of device queue: EMPTY

t = 15
Servicing SJR job 1: CPU burst(3) IO burst(0)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: EMPTY

t = 16
Servicing SJR job 1: CPU burst(2) IO burst(0)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: EMPTY

t = 17
Servicing SJR job 1: CPU burst(1) IO burst(0)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: EMPTY

t = 18
JOB 1 DONE
CPU loading job 4: CPU burst(4) IO burst(3)
current state of ready queue: 4-6-0-7-2-8
current state of device queue: EMPTY

t = 19
Servicing SJR job 4: CPU burst(3) IO burst(3)
current state of ready queue: 6-0-7-2-8
current state of device queue: EMPTY

t = 20
Servicing SJR job 4: CPU burst(2) IO burst(3)
current state of ready queue: 6-0-7-2-8
current state of device queue: EMPTY

t = 21
Servicing SJR job 4: CPU burst(1) IO burst(3)
current state of ready queue: 6-0-7-2-8
current state of device queue: EMPTY

t = 22
JOB 4 finished CPU burst
CPU loading job 6: CPU burst(4) IO burst(0)
current state of ready queue: 6-0-7-2-8
current state of device queue: 4

t = 23
Servicing SJR job 6: CPU burst(3) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: 4

t = 24
Servicing SJR job 6: CPU burst(2) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: 4

t = 25
Servicing SJR job 6: CPU burst(1) IO burst(0)
current state of ready queue: 4-0-7-2-8
Job 4 finished I/O burst
current state of device queue: EMPTY

t = 26
JOB 6 DONE
CPU loading job 4: CPU burst(4) IO burst(0)
current state of ready queue: 4-0-7-2-8
current state of device queue: EMPTY

t = 27
Servicing SJR job 4: CPU burst(3) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 28
Servicing SJR job 4: CPU burst(2) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 29
Servicing SJR job 4: CPU burst(1) IO burst(0)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 30
JOB 4 DONE
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-7-2-8
current state of device queue: EMPTY

t = 31
Servicing SJR job 0: CPU burst(4) IO burst(4)
current state of ready queue: 7-2-8
current state of device queue: EMPTY

t = 32
Servicing SJR job 0: CPU burst(3) IO burst(4)
current state of ready queue: 7-2-8
current state of device queue: EMPTY

t = 33
Servicing SJR job 0: CPU burst(2) IO burst(4)
current state of ready queue: 7-2-8
current state of device queue: EMPTY

t = 34
Servicing SJR job 0: CPU burst(1) IO burst(4)
current state of ready queue: 7-2-8
current state of device queue: EMPTY

t = 35
JOB 0 finished CPU burst
CPU loading job 7: CPU burst(8) IO burst(7)
current state of ready queue: 7-2-8
current state of device queue: 0

t = 36
Servicing SJR job 7: CPU burst(7) IO burst(7)
current state of ready queue: 2-8
current state of device queue: 0

t = 37
Servicing SJR job 7: CPU burst(6) IO burst(7)
current state of ready queue: 2-8
current state of device queue: 0

t = 38
Servicing SJR job 7: CPU burst(5) IO burst(7)
current state of ready queue: 2-8
current state of device queue: 0

t = 39
Servicing SJR job 7: CPU burst(4) IO burst(7)
current state of ready queue: 0-2-8
Job 0 finished I/O burst
current state of device queue: EMPTY

t = 40
Servicing SJR job 7: CPU burst(3) IO burst(7)
current state of ready queue: 0-2-8
current state of device queue: EMPTY

t = 41
Servicing SJR job 7: CPU burst(2) IO burst(7)
current state of ready queue: 0-2-8
current state of device queue: EMPTY

t = 42
Servicing SJR job 7: CPU burst(1) IO burst(7)
current state of ready queue: 0-2-8
current state of device queue: EMPTY

t = 43
JOB 7 finished CPU burst
CPU loading job 0: CPU burst(5) IO burst(0)
current state of ready queue: 0-2-8
current state of device queue: 7

t = 44
Servicing SJR job 0: CPU burst(4) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 45
Servicing SJR job 0: CPU burst(3) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 46
Servicing SJR job 0: CPU burst(2) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 47
Servicing SJR job 0: CPU burst(1) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 48
JOB 0 DONE
CPU loading job 2: CPU burst(12) IO burst(0)
current state of ready queue: 2-8
current state of device queue: 7

t = 49
Servicing SJR job 2: CPU burst(11) IO burst(0)
current state of ready queue: 8
current state of device queue: 7

t = 50
JOB 2 finished CPU burst
CPU loading job 7: CPU burst(8) IO burst(0)
current state of ready queue: 7-2-8
Job 7 finished I/O burst
current state of device queue: EMPTY

t = 51
Servicing SJR job 7: CPU burst(7) IO burst(0)
current state of ready queue: 2-8
current state of device queue: EMPTY

t = 52
Servicing SJR job 7: CPU burst(6) IO burst(0)
current state of ready queue: 2-8
current state of device queue: EMPTY

t = 53
Servicing SJR job 7: CPU burst(5) IO burst(0)
current state of ready queue: 2-8
current state of device queue: EMPTY

t = 54
Servicing SJR job 7: CPU burst(4) IO burst(0)
current state of ready queue: 2-8
current state of device queue: EMPTY

t = 55
Servicing SJR job 7: CPU burst(3) IO burst(0)
current state of ready queue: 2-8
current state of device queue: EMPTY

t = 56
Servicing SJR job 7: CPU burst(2) IO burst(0)
current state of ready queue: 2-8
current state of device queue: EMPTY

t = 57
Servicing SJR job 7: CPU burst(1) IO burst(0)
current state of ready queue: 2-8
current state of device queue: EMPTY

t = 58
JOB 7 DONE
CPU loading job 2: CPU burst(10) IO burst(0)
current state of ready queue: 2-8
current state of device queue: EMPTY

t = 59
Servicing SJR job 2: CPU burst(9) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 60
Servicing SJR job 2: CPU burst(8) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 61
Servicing SJR job 2: CPU burst(7) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 62
Servicing SJR job 2: CPU burst(6) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 63
Servicing SJR job 2: CPU burst(5) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 64
Servicing SJR job 2: CPU burst(4) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 65
Servicing SJR job 2: CPU burst(3) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 66
Servicing SJR job 2: CPU burst(2) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 67
Servicing SJR job 2: CPU burst(1) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 68
JOB 2 DONE
CPU loading job 8: CPU burst(14) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 69
Servicing SJR job 8: CPU burst(13) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 70
Servicing SJR job 8: CPU burst(12) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 71
Servicing SJR job 8: CPU burst(11) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 72
Servicing SJR job 8: CPU burst(10) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 73
Servicing SJR job 8: CPU burst(9) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 74
Servicing SJR job 8: CPU burst(8) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 75
Servicing SJR job 8: CPU burst(7) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 76
Servicing SJR job 8: CPU burst(6) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 77
Servicing SJR job 8: CPU burst(5) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 78
Servicing SJR job 8: CPU burst(4) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 79
Servicing SJR job 8: CPU burst(3) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 80
Servicing SJR job 8: CPU burst(2) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 81
Servicing SJR job 8: CPU burst(1) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

Final report for SJR algorithm.

THROUGHPUT = 0.12195122

Process ID	Wait Time
    0     	    34
    1     	     8
    2     	    56
    3     	     0
    4     	    19
    5     	     3
    6     	    22
    7     	    35
    8     	    68
    9     	     2
AVERAGE WAITING TIME = 24.7

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 3-9-5-3-1-5-9-1-4-6-4-0-7-0-2-7-2-8

Process ID	Turnaround Time
    0    	      48
    1    	      18
    2    	      68
    3    	       6
    4    	      30
    5    	      13
    6    	      26
    7    	      58
    8    	      82
    9    	      14
AVERAGE TURNAROUND TIME = 36.3

/***********  Round-Robin Algorithm (time quantum 3)  ***********/

t = 0
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 1
Servicing RR job 0: CPU burst(4) IO burst(4)
current state of ready queue: 1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 2
Servicing RR job 0: CPU burst(3) IO burst(4)
current state of ready queue: 1-2-3-4-5-6-7-8-9
current state of device queue: EMPTY

t = 3
JOB 0 finished CPU burst
CPU loading job 1: CPU burst(4) IO burst(2)
current state of ready queue: 1-2-3-4-5-6-7-8-9-0
current state of device queue: EMPTY

t = 4
Servicing RR job 1: CPU burst(3) IO burst(2)
current state of ready queue: 2-3-4-5-6-7-8-9-0
current state of device queue: EMPTY

t = 5
Servicing RR job 1: CPU burst(2) IO burst(2)
current state of ready queue: 2-3-4-5-6-7-8-9-0
current state of device queue: EMPTY

t = 6
JOB 1 finished CPU burst
CPU loading job 2: CPU burst(12) IO burst(0)
current state of ready queue: 2-3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 7
Servicing RR job 2: CPU burst(11) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 8
Servicing RR job 2: CPU burst(10) IO burst(0)
current state of ready queue: 3-4-5-6-7-8-9-0-1
current state of device queue: EMPTY

t = 9
JOB 2 finished CPU burst
CPU loading job 3: CPU burst(1) IO burst(4)
current state of ready queue: 3-4-5-6-7-8-9-0-1-2
current state of device queue: EMPTY

t = 10
JOB 3 finished CPU burst
CPU loading job 4: CPU burst(4) IO burst(3)
current state of ready queue: 4-5-6-7-8-9-0-1-2
current state of device queue: 3

t = 11
Servicing RR job 4: CPU burst(3) IO burst(3)
current state of ready queue: 5-6-7-8-9-0-1-2
current state of device queue: 3

t = 12
Servicing RR job 4: CPU burst(2) IO burst(3)
current state of ready queue: 5-6-7-8-9-0-1-2
current state of device queue: 3

t = 13
JOB 4 finished CPU burst
CPU loading job 5: CPU burst(3) IO burst(4)
current state of ready queue: 5-6-7-8-9-0-1-2-4
current state of device queue: 3

t = 14
Servicing RR job 5: CPU burst(2) IO burst(4)
current state of ready queue: 6-7-8-9-0-1-2-4-3
Job 3 finished I/O burst
current state of device queue: EMPTY

t = 15
Servicing RR job 5: CPU burst(1) IO burst(4)
current state of ready queue: 6-7-8-9-0-1-2-4-3
current state of device queue: EMPTY

t = 16
JOB 5 finished CPU burst
CPU loading job 6: CPU burst(4) IO burst(0)
current state of ready queue: 6-7-8-9-0-1-2-4-3
current state of device queue: 5

t = 17
Servicing RR job 6: CPU burst(3) IO burst(0)
current state of ready queue: 7-8-9-0-1-2-4-3
current state of device queue: 5

t = 18
Servicing RR job 6: CPU burst(2) IO burst(0)
current state of ready queue: 7-8-9-0-1-2-4-3
current state of device queue: 5

t = 19
JOB 6 finished CPU burst
CPU loading job 7: CPU burst(8) IO burst(7)
current state of ready queue: 7-8-9-0-1-2-4-3-6
current state of device queue: 5

t = 20
Servicing RR job 7: CPU burst(7) IO burst(7)
current state of ready queue: 8-9-0-1-2-4-3-6-5
Job 5 finished I/O burst
current state of device queue: EMPTY

t = 21
Servicing RR job 7: CPU burst(6) IO burst(7)
current state of ready queue: 8-9-0-1-2-4-3-6-5
current state of device queue: EMPTY

t = 22
JOB 7 finished CPU burst
CPU loading job 8: CPU burst(14) IO burst(0)
current state of ready queue: 8-9-0-1-2-4-3-6-5-7
current state of device queue: EMPTY

t = 23
Servicing RR job 8: CPU burst(13) IO burst(0)
current state of ready queue: 9-0-1-2-4-3-6-5-7
current state of device queue: EMPTY

t = 24
Servicing RR job 8: CPU burst(12) IO burst(0)
current state of ready queue: 9-0-1-2-4-3-6-5-7
current state of device queue: EMPTY

t = 25
JOB 8 finished CPU burst
CPU loading job 9: CPU burst(1) IO burst(10)
current state of ready queue: 9-0-1-2-4-3-6-5-7-8
current state of device queue: EMPTY

t = 26
JOB 9 finished CPU burst
CPU loading job 0: CPU burst(2) IO burst(4)
current state of ready queue: 0-1-2-4-3-6-5-7-8
current state of device queue: 9

t = 27
Servicing RR job 0: CPU burst(1) IO burst(4)
current state of ready queue: 1-2-4-3-6-5-7-8
current state of device queue: 9

t = 28
JOB 0 finished CPU burst
CPU loading job 1: CPU burst(1) IO burst(2)
current state of ready queue: 1-2-4-3-6-5-7-8
current state of device queue: 9-0

t = 29
JOB 1 finished CPU burst
CPU loading job 2: CPU burst(9) IO burst(0)
current state of ready queue: 2-4-3-6-5-7-8
current state of device queue: 9-0-1

t = 30
Servicing RR job 2: CPU burst(8) IO burst(0)
current state of ready queue: 4-3-6-5-7-8
current state of device queue: 9-0-1

t = 31
Servicing RR job 2: CPU burst(7) IO burst(0)
current state of ready queue: 4-3-6-5-7-8-1
Job 1 finished I/O burst
current state of device queue: 9-0

t = 32
JOB 2 finished CPU burst
CPU loading job 4: CPU burst(1) IO burst(3)
current state of ready queue: 4-3-6-5-7-8-1-0-2
Job 0 finished I/O burst
current state of device queue: 9

t = 33
JOB 4 finished CPU burst
CPU loading job 3: CPU burst(1) IO burst(0)
current state of ready queue: 3-6-5-7-8-1-0-2
current state of device queue: 9-4

t = 34
JOB 3 DONE
CPU loading job 6: CPU burst(1) IO burst(0)
current state of ready queue: 6-5-7-8-1-0-2
current state of device queue: 9-4

t = 35
JOB 6 DONE
CPU loading job 5: CPU burst(3) IO burst(0)
current state of ready queue: 5-7-8-1-0-2
current state of device queue: 9-4

t = 36
Servicing RR job 5: CPU burst(2) IO burst(0)
current state of ready queue: 7-8-1-0-2-4-9
Job 9 finished I/O burst
current state of device queue: EMPTY

t = 37
Servicing RR job 5: CPU burst(1) IO burst(0)
current state of ready queue: 7-8-1-0-2-4-9
current state of device queue: EMPTY

t = 38
JOB 5 DONE
CPU loading job 7: CPU burst(5) IO burst(7)
current state of ready queue: 7-8-1-0-2-4-9
current state of device queue: EMPTY

t = 39
Servicing RR job 7: CPU burst(4) IO burst(7)
current state of ready queue: 8-1-0-2-4-9
current state of device queue: EMPTY

t = 40
Servicing RR job 7: CPU burst(3) IO burst(7)
current state of ready queue: 8-1-0-2-4-9
current state of device queue: EMPTY

t = 41
JOB 7 finished CPU burst
CPU loading job 8: CPU burst(11) IO burst(0)
current state of ready queue: 8-1-0-2-4-9-7
current state of device queue: EMPTY

t = 42
Servicing RR job 8: CPU burst(10) IO burst(0)
current state of ready queue: 1-0-2-4-9-7
current state of device queue: EMPTY

t = 43
Servicing RR job 8: CPU burst(9) IO burst(0)
current state of ready queue: 1-0-2-4-9-7
current state of device queue: EMPTY

t = 44
JOB 8 finished CPU burst
CPU loading job 1: CPU burst(4) IO burst(0)
current state of ready queue: 1-0-2-4-9-7-8
current state of device queue: EMPTY

t = 45
Servicing RR job 1: CPU burst(3) IO burst(0)
current state of ready queue: 0-2-4-9-7-8
current state of device queue: EMPTY

t = 46
Servicing RR job 1: CPU burst(2) IO burst(0)
current state of ready queue: 0-2-4-9-7-8
current state of device queue: EMPTY

t = 47
JOB 1 finished CPU burst
CPU loading job 0: CPU burst(5) IO burst(0)
current state of ready queue: 0-2-4-9-7-8-1
current state of device queue: EMPTY

t = 48
Servicing RR job 0: CPU burst(4) IO burst(0)
current state of ready queue: 2-4-9-7-8-1
current state of device queue: EMPTY

t = 49
Servicing RR job 0: CPU burst(3) IO burst(0)
current state of ready queue: 2-4-9-7-8-1
current state of device queue: EMPTY

t = 50
JOB 0 finished CPU burst
CPU loading job 2: CPU burst(6) IO burst(0)
current state of ready queue: 2-4-9-7-8-1-0
current state of device queue: EMPTY

t = 51
Servicing RR job 2: CPU burst(5) IO burst(0)
current state of ready queue: 4-9-7-8-1-0
current state of device queue: EMPTY

t = 52
Servicing RR job 2: CPU burst(4) IO burst(0)
current state of ready queue: 4-9-7-8-1-0
current state of device queue: EMPTY

t = 53
JOB 2 finished CPU burst
CPU loading job 4: CPU burst(4) IO burst(0)
current state of ready queue: 4-9-7-8-1-0-2
current state of device queue: EMPTY

t = 54
Servicing RR job 4: CPU burst(3) IO burst(0)
current state of ready queue: 9-7-8-1-0-2
current state of device queue: EMPTY

t = 55
Servicing RR job 4: CPU burst(2) IO burst(0)
current state of ready queue: 9-7-8-1-0-2
current state of device queue: EMPTY

t = 56
JOB 4 finished CPU burst
CPU loading job 9: CPU burst(1) IO burst(0)
current state of ready queue: 9-7-8-1-0-2-4
current state of device queue: EMPTY

t = 57
JOB 9 DONE
CPU loading job 7: CPU burst(2) IO burst(7)
current state of ready queue: 7-8-1-0-2-4
current state of device queue: EMPTY

t = 58
Servicing RR job 7: CPU burst(1) IO burst(7)
current state of ready queue: 8-1-0-2-4
current state of device queue: EMPTY

t = 59
JOB 7 finished CPU burst
CPU loading job 8: CPU burst(8) IO burst(0)
current state of ready queue: 8-1-0-2-4
current state of device queue: 7

t = 60
Servicing RR job 8: CPU burst(7) IO burst(0)
current state of ready queue: 1-0-2-4
current state of device queue: 7

t = 61
Servicing RR job 8: CPU burst(6) IO burst(0)
current state of ready queue: 1-0-2-4
current state of device queue: 7

t = 62
JOB 8 finished CPU burst
CPU loading job 1: CPU burst(1) IO burst(0)
current state of ready queue: 1-0-2-4-8
current state of device queue: 7

t = 63
JOB 1 DONE
CPU loading job 0: CPU burst(2) IO burst(0)
current state of ready queue: 0-2-4-8
current state of device queue: 7

t = 64
Servicing RR job 0: CPU burst(1) IO burst(0)
current state of ready queue: 2-4-8
current state of device queue: 7

t = 65
JOB 0 DONE
CPU loading job 2: CPU burst(3) IO burst(0)
current state of ready queue: 2-4-8
current state of device queue: 7

t = 66
Servicing RR job 2: CPU burst(2) IO burst(0)
current state of ready queue: 4-8-7
Job 7 finished I/O burst
current state of device queue: EMPTY

t = 67
Servicing RR job 2: CPU burst(1) IO burst(0)
current state of ready queue: 4-8-7
current state of device queue: EMPTY

t = 68
JOB 2 DONE
CPU loading job 4: CPU burst(1) IO burst(0)
current state of ready queue: 4-8-7
current state of device queue: EMPTY

t = 69
JOB 4 DONE
CPU loading job 8: CPU burst(5) IO burst(0)
current state of ready queue: 8-7
current state of device queue: EMPTY

t = 70
Servicing RR job 8: CPU burst(4) IO burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 71
Servicing RR job 8: CPU burst(3) IO burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 72
JOB 8 finished CPU burst
CPU loading job 7: CPU burst(8) IO burst(0)
current state of ready queue: 7-8
current state of device queue: EMPTY

t = 73
Servicing RR job 7: CPU burst(7) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 74
Servicing RR job 7: CPU burst(6) IO burst(0)
current state of ready queue: 8
current state of device queue: EMPTY

t = 75
JOB 7 finished CPU burst
CPU loading job 8: CPU burst(2) IO burst(0)
current state of ready queue: 8-7
current state of device queue: EMPTY

t = 76
Servicing RR job 8: CPU burst(1) IO burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 77
JOB 8 DONE
CPU loading job 7: CPU burst(5) IO burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 78
Servicing RR job 7: CPU burst(4) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 79
Servicing RR job 7: CPU burst(3) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 80
JOB 7 finished CPU burst
CPU loading job 7: CPU burst(2) IO burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 81
Servicing RR job 7: CPU burst(1) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

Final report for RR algorithm.

THROUGHPUT = 0.12195122

Process ID	Wait Time
    0     	    51
    1     	    53
    2     	    56
    3     	    28
    4     	    58
    5     	    28
    6     	    31
    7     	    59
    8     	    63
    9     	    45
AVERAGE WAITING TIME = 47.2

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 0-1-2-3-4-5-6-7-8-9-0-1-2-4-3-6-5-7-8-1-0-2-4-9-7-8-1-0-2-4-8-7-8-7-7

Process ID	Turnaround Time
    0    	      65
    1    	      63
    2    	      68
    3    	      34
    4    	      69
    5    	      38
    6    	      35
    7    	      82
    8    	      77
    9    	      57
AVERAGE TURNAROUND TIME = 58.8

/***********  Priority-Scheduling Algorithm ***********/

t = 0
CPU loading job 4: CPU burst(4) IO burst(3)
current state of ready queue: 4-1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 1
Servicing PS job 4: CPU burst(3) IO burst(3)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 2
Servicing PS job 4: CPU burst(2) IO burst(3)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 3
Servicing PS job 4: CPU burst(1) IO burst(3)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 4
JOB 4 finished CPU burst
CPU loading job 1: CPU burst(4) IO burst(2)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: 4

t = 5
Servicing PS job 1: CPU burst(3) IO burst(2)
current state of ready queue: 8-9-0-5-3-2-6-7
current state of device queue: 4

t = 6
Servicing PS job 1: CPU burst(2) IO burst(2)
current state of ready queue: 8-9-0-5-3-2-6-7
current state of device queue: 4

t = 7
JOB 1 finished CPU burst
CPU loading job 4: CPU burst(4) IO burst(0)
current state of ready queue: 4-1-8-9-0-5-3-2-6-7
Job 4 finished I/O burst
current state of device queue: EMPTY

t = 8
Servicing PS job 4: CPU burst(3) IO burst(0)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 9
Servicing PS job 4: CPU burst(2) IO burst(0)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 10
Servicing PS job 4: CPU burst(1) IO burst(0)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 11
JOB 4 DONE
CPU loading job 1: CPU burst(1) IO burst(2)
current state of ready queue: 1-8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 12
JOB 1 finished CPU burst
CPU loading job 8: CPU burst(14) IO burst(0)
current state of ready queue: 8-9-0-5-3-2-6-7
current state of device queue: 1

t = 13
Servicing PS job 8: CPU burst(13) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: 1

t = 14
JOB 8 finished CPU burst
CPU loading job 1: CPU burst(4) IO burst(0)
current state of ready queue: 1-8-9-0-5-3-2-6-7
Job 1 finished I/O burst
current state of device queue: EMPTY

t = 15
Servicing PS job 1: CPU burst(3) IO burst(0)
current state of ready queue: 8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 16
Servicing PS job 1: CPU burst(2) IO burst(0)
current state of ready queue: 8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 17
Servicing PS job 1: CPU burst(1) IO burst(0)
current state of ready queue: 8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 18
JOB 1 DONE
CPU loading job 8: CPU burst(12) IO burst(0)
current state of ready queue: 8-9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 19
Servicing PS job 8: CPU burst(11) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 20
Servicing PS job 8: CPU burst(10) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 21
Servicing PS job 8: CPU burst(9) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 22
Servicing PS job 8: CPU burst(8) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 23
Servicing PS job 8: CPU burst(7) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 24
Servicing PS job 8: CPU burst(6) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 25
Servicing PS job 8: CPU burst(5) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 26
Servicing PS job 8: CPU burst(4) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 27
Servicing PS job 8: CPU burst(3) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 28
Servicing PS job 8: CPU burst(2) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 29
Servicing PS job 8: CPU burst(1) IO burst(0)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 30
JOB 8 DONE
CPU loading job 9: CPU burst(1) IO burst(10)
current state of ready queue: 9-0-5-3-2-6-7
current state of device queue: EMPTY

t = 31
JOB 9 finished CPU burst
CPU loading job 0: CPU burst(5) IO burst(4)
current state of ready queue: 0-5-3-2-6-7
current state of device queue: 9

t = 32
Servicing PS job 0: CPU burst(4) IO burst(4)
current state of ready queue: 5-3-2-6-7
current state of device queue: 9

t = 33
Servicing PS job 0: CPU burst(3) IO burst(4)
current state of ready queue: 5-3-2-6-7
current state of device queue: 9

t = 34
Servicing PS job 0: CPU burst(2) IO burst(4)
current state of ready queue: 5-3-2-6-7
current state of device queue: 9

t = 35
Servicing PS job 0: CPU burst(1) IO burst(4)
current state of ready queue: 5-3-2-6-7
current state of device queue: 9

t = 36
JOB 0 finished CPU burst
CPU loading job 5: CPU burst(3) IO burst(4)
current state of ready queue: 5-3-2-6-7
current state of device queue: 9-0

t = 37
Servicing PS job 5: CPU burst(2) IO burst(4)
current state of ready queue: 3-2-6-7
current state of device queue: 9-0

t = 38
Servicing PS job 5: CPU burst(1) IO burst(4)
current state of ready queue: 3-2-6-7
current state of device queue: 9-0

t = 39
JOB 5 finished CPU burst
CPU loading job 3: CPU burst(1) IO burst(4)
current state of ready queue: 3-2-6-7
current state of device queue: 9-0-5

t = 40
JOB 3 finished CPU burst
CPU loading job 0: CPU burst(5) IO burst(0)
current state of ready queue: 0-2-6-7
Job 0 finished I/O burst
current state of device queue: 9-5-3

t = 41
JOB 0 finished CPU burst
CPU loading job 9: CPU burst(1) IO burst(0)
current state of ready queue: 9-0-2-6-7
Job 9 finished I/O burst
current state of device queue: 5-3

t = 42
JOB 9 DONE
CPU loading job 0: CPU burst(4) IO burst(0)
current state of ready queue: 0-2-6-7
current state of device queue: 5-3

t = 43
Servicing PS job 0: CPU burst(3) IO burst(0)
current state of ready queue: 5-2-6-7
Job 5 finished I/O burst
current state of device queue: 3

t = 44
Servicing PS job 0: CPU burst(2) IO burst(0)
current state of ready queue: 5-3-2-6-7
Job 3 finished I/O burst
current state of device queue: EMPTY

t = 45
Servicing PS job 0: CPU burst(1) IO burst(0)
current state of ready queue: 5-3-2-6-7
current state of device queue: EMPTY

t = 46
JOB 0 DONE
CPU loading job 5: CPU burst(3) IO burst(0)
current state of ready queue: 5-3-2-6-7
current state of device queue: EMPTY

t = 47
Servicing PS job 5: CPU burst(2) IO burst(0)
current state of ready queue: 3-2-6-7
current state of device queue: EMPTY

t = 48
Servicing PS job 5: CPU burst(1) IO burst(0)
current state of ready queue: 3-2-6-7
current state of device queue: EMPTY

t = 49
JOB 5 DONE
CPU loading job 3: CPU burst(1) IO burst(0)
current state of ready queue: 3-2-6-7
current state of device queue: EMPTY

t = 50
JOB 3 DONE
CPU loading job 2: CPU burst(12) IO burst(0)
current state of ready queue: 2-6-7
current state of device queue: EMPTY

t = 51
Servicing PS job 2: CPU burst(11) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 52
Servicing PS job 2: CPU burst(10) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 53
Servicing PS job 2: CPU burst(9) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 54
Servicing PS job 2: CPU burst(8) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 55
Servicing PS job 2: CPU burst(7) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 56
Servicing PS job 2: CPU burst(6) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 57
Servicing PS job 2: CPU burst(5) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 58
Servicing PS job 2: CPU burst(4) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 59
Servicing PS job 2: CPU burst(3) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 60
Servicing PS job 2: CPU burst(2) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 61
Servicing PS job 2: CPU burst(1) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 62
JOB 2 DONE
CPU loading job 6: CPU burst(4) IO burst(0)
current state of ready queue: 6-7
current state of device queue: EMPTY

t = 63
Servicing PS job 6: CPU burst(3) IO burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 64
Servicing PS job 6: CPU burst(2) IO burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 65
Servicing PS job 6: CPU burst(1) IO burst(0)
current state of ready queue: 7
current state of device queue: EMPTY

t = 66
JOB 6 DONE
CPU loading job 7: CPU burst(8) IO burst(7)
current state of ready queue: 7
current state of device queue: EMPTY

t = 67
Servicing PS job 7: CPU burst(7) IO burst(7)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 68
Servicing PS job 7: CPU burst(6) IO burst(7)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 69
Servicing PS job 7: CPU burst(5) IO burst(7)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 70
Servicing PS job 7: CPU burst(4) IO burst(7)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 71
Servicing PS job 7: CPU burst(3) IO burst(7)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 72
Servicing PS job 7: CPU burst(2) IO burst(7)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 73
Servicing PS job 7: CPU burst(1) IO burst(7)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 74
CPU WAITING...
current state of ready queue: EMPTY
current state of device queue: 7

t = 75
CPU WAITING...
current state of ready queue: EMPTY
current state of device queue: 7

t = 76
CPU WAITING...
current state of ready queue: EMPTY
current state of device queue: 7

t = 77
CPU WAITING...
current state of ready queue: EMPTY
current state of device queue: 7

t = 78
CPU WAITING...
current state of ready queue: EMPTY
current state of device queue: 7

t = 79
CPU WAITING...
current state of ready queue: EMPTY
current state of device queue: 7

t = 80
CPU WAITING...
current state of ready queue: EMPTY
current state of device queue: 7

t = 81
JOB 7 finished CPU burst
CPU loading job 7: CPU burst(8) IO burst(0)
current state of ready queue: 7
Job 7 finished I/O burst
current state of device queue: EMPTY

t = 82
Servicing PS job 7: CPU burst(7) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 83
Servicing PS job 7: CPU burst(6) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 84
Servicing PS job 7: CPU burst(5) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 85
Servicing PS job 7: CPU burst(4) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 86
Servicing PS job 7: CPU burst(3) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 87
Servicing PS job 7: CPU burst(2) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

t = 88
Servicing PS job 7: CPU burst(1) IO burst(0)
current state of ready queue: EMPTY
current state of device queue: EMPTY

Final report for PS algorithm.

THROUGHPUT = 0.11235955

Process ID	Wait Time
    0     	    32
    1     	     8
    2     	    50
    3     	    44
    4     	     0
    5     	    39
    6     	    62
    7     	    66
    8     	    16
    9     	    30
AVERAGE WAITING TIME = 34.7

CPU UTILIZATION = 92%

SEQUENCE OF PROCESSES IN CPU: 4-1-4-1-8-1-8-9-0-5-3-0-9-0-5-3-2-6-7-7

Process ID	Turnaround Time
    0    	      46
    1    	      18
    2    	      62
    3    	      50
    4    	      11
    5    	      49
    6    	      66
    7    	      89
    8    	      30
    9    	      42
AVERAGE TURNAROUND TIME = 46.3

/***********  Multilevel-Feedback-Queue Algorithm ***********/

t = 0
CPU loading job 0: CPU burst(5) IO burst(4)
Order of queue 1 -> 1 2 3 4 5 6 7 8 9
Order of queue 2 -> EMPTY
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 1
Servicing MFQ job 0: CPU burst(4) IO burst(4)
Order of queue 1 -> 1 2 3 4 5 6 7 8 9
Order of queue 2 -> EMPTY
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 2
Servicing MFQ job 0: CPU burst(3) IO burst(4)
Order of queue 1 -> 1 2 3 4 5 6 7 8 9
Order of queue 2 -> EMPTY
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 3
JOB 0 finished CPU burst
CPU loading job 1: CPU burst(4) IO burst(2)
Order of queue 1 -> 2 3 4 5 6 7 8 9
Order of queue 2 -> 0
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 4
Servicing MFQ job 1: CPU burst(3) IO burst(2)
Order of queue 1 -> 2 3 4 5 6 7 8 9
Order of queue 2 -> 0
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 5
Servicing MFQ job 1: CPU burst(2) IO burst(2)
Order of queue 1 -> 2 3 4 5 6 7 8 9
Order of queue 2 -> 0
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 6
JOB 1 finished CPU burst
CPU loading job 2: CPU burst(12) IO burst(0)
Order of queue 1 -> 3 4 5 6 7 8 9
Order of queue 2 -> 0 1
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 7
Servicing MFQ job 2: CPU burst(11) IO burst(0)
Order of queue 1 -> 3 4 5 6 7 8 9
Order of queue 2 -> 0 1
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 8
Servicing MFQ job 2: CPU burst(10) IO burst(0)
Order of queue 1 -> 3 4 5 6 7 8 9
Order of queue 2 -> 0 1
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 9
JOB 2 finished CPU burst
CPU loading job 3: CPU burst(1) IO burst(4)
Order of queue 1 -> 4 5 6 7 8 9
Order of queue 2 -> 0 1 2
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 10
JOB 3 finished CPU burst
CPU loading job 4: CPU burst(4) IO burst(3)
Order of queue 1 -> 5 6 7 8 9
Order of queue 2 -> 0 1 2
Order of queue 3 -> EMPTY
Order of I/O queue-> 3

t = 11
Servicing MFQ job 4: CPU burst(3) IO burst(3)
Order of queue 1 -> 5 6 7 8 9
Order of queue 2 -> 0 1 2
Order of queue 3 -> EMPTY
Order of I/O queue-> 3

t = 12
Servicing MFQ job 4: CPU burst(2) IO burst(3)
Order of queue 1 -> 5 6 7 8 9
Order of queue 2 -> 0 1 2
Order of queue 3 -> EMPTY
Order of I/O queue-> 3

t = 13
JOB 4 finished CPU burst
CPU loading job 5: CPU burst(3) IO burst(4)
Order of queue 1 -> 6 7 8 9
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> EMPTY
Order of I/O queue-> 3

t = 14
Servicing MFQ job 5: CPU burst(2) IO burst(4)
Order of queue 1 -> 6 7 8 9 3
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> EMPTY
Job 3 finished I/O burst
Order of I/O queue-> EMPTY


t = 15
Servicing MFQ job 5: CPU burst(1) IO burst(4)
Order of queue 1 -> 6 7 8 9 3
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 16
JOB 5 finished CPU burst
CPU loading job 6: CPU burst(4) IO burst(0)
Order of queue 1 -> 7 8 9 3
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> EMPTY
Order of I/O queue-> 5

t = 17
Servicing MFQ job 6: CPU burst(3) IO burst(0)
Order of queue 1 -> 7 8 9 3
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> EMPTY
Order of I/O queue-> 5

t = 18
Servicing MFQ job 6: CPU burst(2) IO burst(0)
Order of queue 1 -> 7 8 9 3
Order of queue 2 -> 0 1 2 4
Order of queue 3 -> EMPTY
Order of I/O queue-> 5

t = 19
JOB 6 finished CPU burst
CPU loading job 7: CPU burst(8) IO burst(7)
Order of queue 1 -> 8 9 3
Order of queue 2 -> 0 1 2 4 6
Order of queue 3 -> EMPTY
Order of I/O queue-> 5

t = 20
Servicing MFQ job 7: CPU burst(7) IO burst(7)
Order of queue 1 -> 8 9 3 5
Order of queue 2 -> 0 1 2 4 6
Order of queue 3 -> EMPTY
Job 5 finished I/O burst
Order of I/O queue-> EMPTY


t = 21
Servicing MFQ job 7: CPU burst(6) IO burst(7)
Order of queue 1 -> 8 9 3 5
Order of queue 2 -> 0 1 2 4 6
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 22
JOB 7 finished CPU burst
CPU loading job 8: CPU burst(14) IO burst(0)
Order of queue 1 -> 9 3 5
Order of queue 2 -> 0 1 2 4 6 7
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 23
Servicing MFQ job 8: CPU burst(13) IO burst(0)
Order of queue 1 -> 9 3 5
Order of queue 2 -> 0 1 2 4 6 7
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 24
Servicing MFQ job 8: CPU burst(12) IO burst(0)
Order of queue 1 -> 9 3 5
Order of queue 2 -> 0 1 2 4 6 7
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 25
JOB 8 finished CPU burst
CPU loading job 9: CPU burst(1) IO burst(10)
Order of queue 1 -> 3 5
Order of queue 2 -> 0 1 2 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 26
JOB 9 finished CPU burst
CPU loading job 3: CPU burst(1) IO burst(0)
Order of queue 1 -> 5
Order of queue 2 -> 0 1 2 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9

t = 27
JOB 3 DONE
CPU loading job 5: CPU burst(3) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 0 1 2 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9

t = 28
Servicing MFQ job 5: CPU burst(2) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 0 1 2 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9

t = 29
Servicing MFQ job 5: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 0 1 2 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9

t = 30
JOB 5 DONE
CPU loading job 0: CPU burst(2) IO burst(4)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 2 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9

t = 31
Servicing MFQ job 0: CPU burst(1) IO burst(4)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 2 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9

t = 32
JOB 0 finished CPU burst
CPU loading job 1: CPU burst(1) IO burst(2)
Order of queue 1 -> EMPTY
Order of queue 2 -> 2 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9 0

t = 33
JOB 1 finished CPU burst
CPU loading job 2: CPU burst(9) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9 0 1

t = 34
Servicing MFQ job 2: CPU burst(8) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> 9 0 1

t = 35
Servicing MFQ job 2: CPU burst(7) IO burst(0)
Order of queue 1 -> 1 0
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> EMPTY
Job 0 finished I/O burst
Order of I/O queue-> 9

t = 36
Servicing MFQ job 2: CPU burst(6) IO burst(0)
Order of queue 1 -> 1 0 9
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> EMPTY
Job 9 finished I/O burst
Order of I/O queue-> EMPTY


t = 37
Servicing MFQ job 2: CPU burst(5) IO burst(0)
Order of queue 1 -> 1 0 9
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 38
Servicing MFQ job 2: CPU burst(4) IO burst(0)
Order of queue 1 -> 1 0 9
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 39
JOB 2 finished CPU burst
CPU loading job 1: CPU burst(4) IO burst(0)
Order of queue 1 -> 0 9
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 40
Servicing MFQ job 1: CPU burst(3) IO burst(0)
Order of queue 1 -> 0 9
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 41
Servicing MFQ job 1: CPU burst(2) IO burst(0)
Order of queue 1 -> 0 9
Order of queue 2 -> 4 6 7 8
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 42
JOB 1 finished CPU burst
CPU loading job 0: CPU burst(5) IO burst(0)
Order of queue 1 -> 9
Order of queue 2 -> 4 6 7 8 1
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 43
Servicing MFQ job 0: CPU burst(4) IO burst(0)
Order of queue 1 -> 9
Order of queue 2 -> 4 6 7 8 1
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 44
Servicing MFQ job 0: CPU burst(3) IO burst(0)
Order of queue 1 -> 9
Order of queue 2 -> 4 6 7 8 1
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 45
JOB 0 finished CPU burst
CPU loading job 9: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 4 6 7 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 46
JOB 9 DONE
CPU loading job 4: CPU burst(1) IO burst(3)
Order of queue 1 -> EMPTY
Order of queue 2 -> 6 7 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 47
JOB 4 finished CPU burst
CPU loading job 6: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 7 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> 4

t = 48
JOB 6 DONE
CPU loading job 7: CPU burst(5) IO burst(7)
Order of queue 1 -> EMPTY
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> 4

t = 49
Servicing MFQ job 7: CPU burst(4) IO burst(7)
Order of queue 1 -> EMPTY
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> 4

t = 50
Servicing MFQ job 7: CPU burst(3) IO burst(7)
Order of queue 1 -> 4
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2
Job 4 finished I/O burst
Order of I/O queue-> EMPTY


t = 51
Servicing MFQ job 7: CPU burst(2) IO burst(7)
Order of queue 1 -> 4
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 52
Servicing MFQ job 7: CPU burst(1) IO burst(7)
Order of queue 1 -> 4
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 53
JOB 7 finished CPU burst
CPU loading job 4: CPU burst(4) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> 7

t = 54
Servicing MFQ job 4: CPU burst(3) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> 7

t = 55
Servicing MFQ job 4: CPU burst(2) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 8 1 0
Order of queue 3 -> 2
Order of I/O queue-> 7

t = 56
JOB 4 finished CPU burst
CPU loading job 8: CPU burst(11) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2
Order of I/O queue-> 7

t = 57
Servicing MFQ job 8: CPU burst(10) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2
Order of I/O queue-> 7

t = 58
Servicing MFQ job 8: CPU burst(9) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2
Order of I/O queue-> 7

t = 59
Servicing MFQ job 8: CPU burst(8) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2
Order of I/O queue-> 7

t = 60
Servicing MFQ job 8: CPU burst(7) IO burst(0)
Order of queue 1 -> 7
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2
Job 7 finished I/O burst
Order of I/O queue-> EMPTY


t = 61
Servicing MFQ job 8: CPU burst(6) IO burst(0)
Order of queue 1 -> 7
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2
Order of I/O queue-> EMPTY


t = 62
JOB 8 finished CPU burst
CPU loading job 7: CPU burst(8) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 63
Servicing MFQ job 7: CPU burst(7) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 64
Servicing MFQ job 7: CPU burst(6) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 1 0 4
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 65
JOB 7 finished CPU burst
CPU loading job 1: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 0 4 7
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 66
JOB 1 DONE
CPU loading job 0: CPU burst(2) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 4 7
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 67
Servicing MFQ job 0: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 4 7
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 68
JOB 0 DONE
CPU loading job 4: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> 7
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 69
JOB 4 DONE
CPU loading job 7: CPU burst(5) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 70
Servicing MFQ job 7: CPU burst(4) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 71
Servicing MFQ job 7: CPU burst(3) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 72
Servicing MFQ job 7: CPU burst(2) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 73
Servicing MFQ job 7: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> 2 8
Order of I/O queue-> EMPTY


t = 74
JOB 7 DONE
CPU loading job 2: CPU burst(3) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> 8
Order of I/O queue-> EMPTY


t = 75
Servicing MFQ job 2: CPU burst(2) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> 8
Order of I/O queue-> EMPTY


t = 76
Servicing MFQ job 2: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> 8
Order of I/O queue-> EMPTY


t = 77
JOB 2 DONE
CPU loading job 8: CPU burst(5) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 78
Servicing MFQ job 8: CPU burst(4) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 79
Servicing MFQ job 8: CPU burst(3) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 80
Servicing MFQ job 8: CPU burst(2) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


t = 81
Servicing MFQ job 8: CPU burst(1) IO burst(0)
Order of queue 1 -> EMPTY
Order of queue 2 -> EMPTY
Order of queue 3 -> EMPTY
Order of I/O queue-> EMPTY


Final report for MFQ algorithm.

THROUGHPUT = 0.12195122

Process ID	Wait Time
    0     	    55
    1     	    56
    2     	    65
    3     	    21
    4     	    58
    5     	    20
    6     	    44
    7     	    51
    8     	    68
    9     	    34
AVERAGE WAITING TIME = 47.2

CPU UTILIZATION = 100%

SEQUENCE OF PROCESSES IN CPU: 0-1-2-3-4-5-6-7-8-9-3-5-0-1-2-1-0-9-4-6-7-4-8-7-1-0-4-7-2-8

Process ID	Turnaround Time
    0    	      68
    1    	      66
    2    	      77
    3    	      27
    4    	      69
    5    	      30
    6    	      48
    7    	      74
    8    	      82
    9    	      46
AVERAGE TURNAROUND TIME = 58.7

/************************************************************/
/******************  Algorithm Comparison  ******************/
/************************************************************/

Throughput Comparison:
   1.  Multi-Level Feedback Queue:   0.12
   2.  First-Come, First-Served:   0.12
   3.  Round-Robin:   0.12
   4.  Shortest-Job-Remaining:   0.12
   5.  Shortest-Job-First:   0.12
   6.  Priority Scheduling:   0.11


Wait Time Comparison:
   1.  Shortest-Job-Remaining:  24.70
   2.  Shortest-Job-First:  24.90
   3.  Priority Scheduling:  34.70
   4.  Round-Robin:  47.20
   5.  Multi-Level Feedback Queue:  47.20
   6.  First-Come, First-Served:  49.10


Turnaround Time Comparison:
   1.  Shortest-Job-Remaining:  36.30
   2.  Shortest-Job-First:  36.50
   3.  Priority Scheduling:  46.30
   4.  Multi-Level Feedback Queue:  58.70
   5.  Round-Robin:  58.80
   6.  First-Come, First-Served:  60.70


CPU Utilization Comparison:
   1.  Multi-Level Feedback Queue:  100.00%
   2.  First-Come, First-Served:  100.00%
   3.  Round-Robin:  100.00%
   4.  Shortest-Job-Remaining:  100.00%
   5.  Shortest-Job-First:  100.00%
   6.  Priority Scheduling:  92.13%


Context Switch Comparison:
   1.  First-Come, First-Served:  17
   2.  Shortest-Job-First:  17
   3.  Shortest-Job-Remaining:  18
   4.  Priority Scheduling:  20
   5.  Multi-Level Feedback Queue:  30
   6.  Round-Robin:  35




/********************Our Recommendations********************/
To optimize Throughput for this input data set, we recommend: The Multi-Level Feedback Queue Algorithm.
To optimize Waiting Time for this input data set, we recommend: The Shortest-Job-Remaining Algorithm.
To optimize Turnaround Time for this input data set, we recommend: The Shortest-Job-Remaining Algorithm.
To optimize CPU Utilization for this input data set, we recommend: The Multi-Level Feedback Queue Algorithm.
To optimize the number of Context Switches for this input data set, we recommend: The First-Come, First-Served Algorithm.

To optimize our grade for this project, we recommend: Giving our group an A+.