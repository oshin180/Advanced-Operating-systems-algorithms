# Advanced-Operating-systems-algorithms
Bankers algorithm:
This algorithm is used for resource allocation and to avoid deadlocks. Bankers algorithm does this in the following way: 
1. it makes a simulation wherein it allocates maximum possible number of resources
2. checks for possible activities
3. based on the result, decides if a safe sequence exists.
Video explanation of the implementation of this algorithm in C is given here: 

Lamport's logical clock:
This algorithm is used in a distributed computer system to figure out in what order events occur.
However, processes in a system are not always synched perfectly, thereby giving a partial order (only gives order of entities that interact in the system) of events.
Video explanation for the implementation is given here: https://www.youtube.com/watch?v=vAMv5sQuObo
This algorithm serves as the foundation for understanding the more complex Lamport's vector clock.

Lamport's vector clock:
Lamport's vector clock overcomes the limitation of the logical clock by providing total order in the system (gives order of all the events in the system).
It tells us whether pairs of events in the systema re causally related.
For each event in the system, the timestamp of its occurence is produced and they are compared against timestamps of all the other events.
Video explanation of the implementation of this code in C is given here: https://www.youtube.com/watch?v=0t_baiwoIg0
