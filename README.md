![cover-philosophers](https://github.com/user-attachments/assets/c64e97df-7758-46a5-bc91-f75ede5cedc4)

<div align="center">
<h1>Philosophers Documentation</h1>
<img src="https://img.shields.io/badge/42-%23000000.svg?&style=for-the-badge&logo=42&logoColor=white" /> 
<img src="https://img.shields.io/badge/c-%23A8B9CC.svg?&style=for-the-badge&logo=c&logoColor=black" /> 
<img src="https://img.shields.io/badge/markdown-%23000000.svg?&style=for-the-badge&logo=markdown&logoColor=white" />
<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
</div>


### Table of Contents

1. [Introduction](#introduction)
2. [📌 The Dining Philosophers Problem](#the-dining-philosophers-problem)
   - [🔹 Context](#context)
   - [◾️ Philosopher States](#philosopher-states)     
3. [📌 Project Rules in 42](#project-rules-in-42)
   - [🔹 Arguments](#arguments)
4. [✅ Permitted Functions](#permitted-functions)
5. [🌲Project Structure](#project-structure)
6. [📌 Data structure ](#data-structure)
7. [💡 My approach](#my-approach)
8. [📊 Flowchart](#flowchart)
9. [🔍 Test cases](#test-cases)
10. [🧰 Debugging tools](#debugging-tools)




### Introduction
<a name="introduction"></a>
The Dining Philosophers project is part of the **42 curriculum**, designed to teach threads, synchronization, and concurrency issues in C using pthread.

It is based on the classic Dining Philosophers Problem, described by **Edsger Dijkstra** in 1965, which models process synchronization in operating systems.


### 📌 The Dining Philosophers Problem
<a name="the-dining-philosophers-problem"></a>
#### 🔹 Context
<a name="context"></a>
Five philosophers are seated at a circular table, where each has:
   - A plate of spaghetti 🍝
   - A fork on the left and another on the right 🍴🍴

To eat, a philosopher must pick up two forks—one from their **right** and **left**. However, forks are shared with their neighbors.

#### ◾️ Philosopher States
<a name="philosopher-states"></a>
Each philosopher alternates between three states:
   1. Thinking 🤔
   2. Eating 🍝
   3. Sleeping 😴

![Dining Philosophers](https://github.com/user-attachments/assets/4c4e725b-24d4-4ca6-9d43-d924f7e8fdad)

The goal is to prevent deadlocks and race conditions while philosophers try to eat without conflicts.

### 📌 Project Rules in 42
<a name="project-rules-in-42"></a>

#### 🔹 Arguments
<a name="arguments"></a>
The program receives the following parameters:

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```sh
./philo 5 800 200 200
```

Explanation of parameters:
- **number_of_philosophers**: Number of philosophers (and forks).
- **time_to_die**: Time (ms) before a philosopher dies if they don’t eat.
- **time_to_eat**: Time (ms) a philosopher takes to eat.
- **time_to_sleep**: Time (ms) a philosopher sleeps after eating.
- **(Optional) number_of_times_each_philosopher_must_eat**: If provided, the program ends when all philosophers have eaten this many times.

#### ✅ Permitted functions
<a name="permitted-functions"></a>

| **Function**                           | **Header File**       
|----------------------------------------|------------------------------
| `memset`                               | `<string.h>`                 
| `printf`                               | `<stdio.h>`                  
| `malloc`, `free`                       | `<stdlib.h>`                  
| `write`                                | `<unistd.h>`                 
| `usleep`                               | `<unistd.h>`                 
| `gettimeofday`                         | `<sys/time.h>`               
| `pthread_create`, `pthread_detach`, `pthread_join` | `<pthread.h>` 
| `pthread_mutex_init`, `pthread_mutex_destroy` | `<pthread.h>`


### 🌲 Project Structure
<a name="project-structure"></a>

```sh
├── Makefile
├── includes
│   ├── define.h
│   ├── libraries.h
│   ├── message.h
│   ├── philo.h
│   ├── structs.h
│   └── used_functions.h
└── srcs
    ├── main.c
    ├── program
    │   ├── 0_check_input.c
    │   ├── 1_init_all.c
    │   ├── 2_start_simulation.c
    │   ├── 3_philo_routine.c
    │   ├── 4_philo_actions.c
    │   └── 5_monitor.c
    └── utils
        ├── check_input_utils.c
        ├── error_message.c
        ├── free_program.c
        ├── print_utils.c
        └── time_utils.c
```

### 📌 Data structure 
<a name="data-structure"></a>

The project uses two main structures to manage the philosophers and their shared resources.

#### 🟢 t_philo Structure (Philosopher)

This structure represents each individual philosopher and stores their state, behavior timings, and synchronization tools.
```sh
typedef struct s_philo
{
    pthread_t        thread;         // Thread managing this philosopher
    int             id;              // Unique philosopher ID (1 to num_of_philos)
    int             eating;          // Flag indicating if the philosopher is eating
    int             meals_eaten;     // Counter tracking the number of meals eaten
    size_t          last_meal;       // Timestamp of the last meal
    size_t          time_to_die;     // Maximum time a philosopher can go without eating
    size_t          time_to_eat;     // Time required for a philosopher to eat
    size_t          time_to_sleep;   // Time required for a philosopher to sleep
    size_t          start_time;      // Timestamp when the simulation started
    int             num_of_philos;   // Total number of philosophers
    int             num_times_to_eat;// Meal limit before the simulation ends (optional)
    int             *found_dead;     // Pointer to a shared flag indicating if a philosopher has died
    pthread_mutex_t *r_fork;         // Pointer to the right fork (mutex)
    pthread_mutex_t *l_fork;         // Pointer to the left fork (mutex)
    pthread_mutex_t *write_lock;     // Mutex for controlling console output
    pthread_mutex_t *dead_lock;      // Mutex for accessing the death flag
    pthread_mutex_t *meal_lock;      // Mutex for modifying meal-related data
} t_philo;
```

**🔹 Key Points**
   - Each philosopher runs as a separate thread.
   - Uses mutexes for synchronization (forks, writing, and meal updates).
   - Has access to its own eating and timing data.
   - Cannot access the main structure (t_dinner) directly.


#### 🔵 t_dinner Structure (Main Simulation Manager)

This structure manages all philosophers and the shared synchronization resources.

```sh
typedef struct s_dinner
{
    int             dead_flag;       // Shared flag indicating if a philosopher has died
    pthread_mutex_t write_lock;      // Mutex for synchronized console output
    pthread_mutex_t meal_lock;       // Mutex for meal-related synchronization
    pthread_mutex_t dead_lock;       // Mutex for checking and updating the death status
    t_philo         *philos;         // Array of philosopher structures
} t_dinner;
```

##### 🔗 Relationship Between t_dinner and t_philo
- `t_dinner` creates and manages the `t_philo` structures.
- Each `t_philo` only has access to its own state and shared mutexes.
- This design prevents direct modification of global state from individual threads, ensuring better synchronization and avoiding race conditions.


### 💡  My approach
<a name="my-approach"></a>

Imagine you’re in a restaurant… 🍽️

- The **Restaurant** (`t_dinner`): 🏛️ This central structure manages the entire environment, including philosophers and forks. It maintains control over all operations, ensuring proper synchronization and resource allocation.
- The **Waiter** (Host Thread): 🧑‍🍳 Acts as a supervisory entity, monitoring the status of each philosopher. The waiter ensures that philosophers adhere to the rules, preventing issues like deadlock and ensuring that each philosopher gets a chance to eat.
- The **Diners** (`t_philo` structures): 🧑‍🎓 Represent individual philosophers who do not have autonomous control over the system. Instead, they operate under the directives issued by the t_dinner structure and the host thread. Each philosopher has attributes such as ID, state, and references to the forks they use.

In this design, the `t_dinner` structure holds references to all `t_philo` instances, orchestrating their actions and managing resources. Philosophers (`t_philo`) do not have authority over the system; they perform actions as directed by the `t_dinner` structure and the host thread. This hierarchical control ensures organized management of resources and synchronization, effectively preventing issues like deadlock and ensuring fair resource distribution among philosophers.

### 📊 Flowchart
<a name="flowchart"></a>

This flowchart illustrates the logic behind a philosopher dining simulation, a well-known concurrency problem in computing. The simulation manages multiple philosopher threads competing for shared resources (forks) while ensuring synchronization and preventing deadlocks.

The flowchart breaks down the key processes, including input validation, initialization, thread management, and the philosopher’s routine (eating, sleeping, thinking). It also highlights the role of the monitor thread in detecting philosopher deaths and tracking meal limits when an optional argument is provided.

![Philo_flowchart excalidraw](https://github.com/user-attachments/assets/53601682-26be-4a10-b02c-8b904985c191)



### 🔍 Test cases 
<a name="test-cases"></a>

#### 🚨 Invalid input cases

These cases check how the program handles incorrect inputs.
```sh
./philo --> Expected: "Error: Invalid number of arguments"

./philo 5 800 -200 200 0 1 2 --> "Expected: "Error: Invalid number of arguments"

./philo 5 800 -200 200 --> Expected: "Error: Invalid argument - time values must be positive integers."

./philo 1- 800 200 200 --> Expected: "Error: Invalid argument - philosopher count must be a positive integer."

./philo -5 800 200 200 --> Expected: "Error: Invalid argument - philosopher count must be positive."

./philo 1 800a 200 200 --> Expected: "Error: Invalid argument - numeric values required."

./philo 0 800 200 200  --> Expected: "Error: Invalid number of philosophers."

./philo 2 60 60 60 -0 -->Expected: "Error: Invalid argument - unexpected value '-0'."

./philo 5 800 200 -->Expected: "Error: Missing required arguments."
```


#### 🟢 Valid Input Cases (Expected to Run Successfully)

These cases should run normally without errors.
```sh
./philo            1 800 200 200 --> Expected: Simulation starts successfully with 1 philosopher.

./philo            000000001 800 200 200 --> Expected: Simulation starts as if input was "1".

./philo +1 800 200 200 -->Expected: Simulation starts as if input was "1".

./philo 1 800 200 200 --> Expected: "Philosopher 1 has taken a fork", "Philosopher 1 is eating", etc (Should not deadlock but eventually die due to starvation.)

./philo 2 800 200 200 -->Expected: Two philosophers alternating fork use, no deadlocks.

./philo 2 800 200 200 0 --> Expected: Simulation starts and immediately ends. No output 

./philo 5 800 200 200 7 --> Expected: Simulation stops after each philosopher eats 7 times.

./philo 50 800 200 200 --> Expected: Successfully handles 50 philosophers, philosophers should eat, think, and sleep without deadlocks

./philo 200 400 200 200 --> Expected: Successfully handles 200 philosophers, philosophers should eat, think, and sleep without deadlocks and eventually, they may start dying **if the given times are insufficient** for sustained eating.  
```

#### ⏳ Edge Cases (Extreme Conditions)

These cases test the system’s behavior under extreme or unusual conditions.
```sh
./philo 5 200 800000 200 --> Expected: Long delay before eating again (checks starvation risk). Since the sleep time is extremely long (800000ms), they may **not wake up in time** to eat again, leading to starvation.

./philo 5 200 800 2000000 -->Expected: Runs for an extended period without issues. Philosophers **might die after 200ms** if they don’t eat in time.

./philo 199 401 200 200 --> Expected: Large-scale simulation, no deadlocks. Philosophers **might die if the given times are insufficient** for all to eat in time.

./philo 199 401 200 200 0 --> Expected: Simulation starts and stops instantly. No philosopher should die as the execution stops immediately.

./philo 5 800 800 800 --> Expected: Philosophers act in sync without deadlocks. **Might die** if the given times are insufficient for continuous eating.

./philo 5 60 60 60 --> Expected: **Maximum CPU load**, as philosophers constantly eat, think, and sleep. **Fast starvation likely**, as the times may be too short for sustained survival.
```

#### ⚖️ Starvation & Fairness Tests

These cases check if all philosophers get a chance to eat. 
```sh
./philo 2 170 60 60 -->  Expected: Philosophers should survive if eating in time.

./philo 2 150 60 60 --> Philosophers get a chance to eat before dying.

./philo 5 210 100 100 --> Expected: No starvation should occur; eating should be fairly distributed.

./philo 5 310 200 100 --> Philosophers get a chance to eat before dying.
```


### 🧰 Debugging tools
<a name="debbuging tools"></a>

**`Valgrind`** is a programming tool used for memory debugging, memory leak detection, and profiling. It helps developers identify memory management issues and improve code reliability, especially in languages like C and C++.

The **`--tool=helgrind`** option specifies that Valgrind should use the Helgrind tool, which is specifically designed for detecting threading issues, particularly race conditions in multi-threaded programs. Helgrind can identify situations where multiple threads access shared memory simultaneously, which can lead to unpredictable behavior or bugs that are difficult to reproduce.

#### Use of valgrind

```sh
valgrind ./philo 1 800 200 200
==2969716== Memcheck, a memory error detector
==2969716== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2969716== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==2969716== Command: ./philo 1 800 200 200
==2969716== 
56 1 has taken a fork
800 1 died
==2969716== 
==2969716== HEAP SUMMARY:
==2969716==     in use at exit: 0 bytes in 0 blocks
==2969716==   total heap usage: 3 allocs, 3 frees, 1,568 bytes allocated
==2969716== 
==2969716== All heap blocks were freed -- no leaks are possible
==2969716== 
==2969716== For lists of detected and suppressed errors, rerun with: -s
==2969716== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

#### Use of valgrind + --tool=helgrind

```sh
valgrind --tool=helgrind ./philo 1 800 200 200
==2969611== Helgrind, a thread error detector
==2969611== Copyright (C) 2007-2017, and GNU GPL'd, by OpenWorks LLP et al.
==2969611== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==2969611== Command: ./philo 1 800 200 200
==2969611== 
800 1 died
==2969611== 
==2969611== Use --history-level=approx or =none to gain increased speed, at
==2969611== the cost of reduced accuracy of conflicting-access information
==2969611== For lists of detected and suppressed errors, rerun with: -s
==2969611== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 7 from 7)
```









---
