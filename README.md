[![Progress](https://img.shields.io/badge/Progress-In%20Progress-yellow)](https://github.com/DevAwizard/Exams_42) 


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

### Flowchart
<a name="flowchart"></a>


### 🔍 Test cases 
<a name="test-cases"></a>

#### 🚨 Invalid input cases

These cases check how the program handles incorrect inputs.
```sh
./philo --> Expected: "Error: Invalid number of arguments"

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

---
