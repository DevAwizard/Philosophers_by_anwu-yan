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


### Introduction

The Dining Philosophers project is part of the **42 curriculum**, designed to teach threads, synchronization, and concurrency issues in C using pthread.

It is based on the classic Dining Philosophers Problem, described by **Edsger Dijkstra** in 1965, which models process synchronization in operating systems.


### 📌 The Dining Philosophers Problem

#### 🔹 Context

Five philosophers are seated at a circular table, where each has:
   - A plate of spaghetti 🍝
   - A fork on the left and another on the right 🍴🍴

To eat, a philosopher must pick up two forks—one from their **right** and **left**. However, forks are shared with their neighbors.

#### ◾️ Philosopher States
Each philosopher alternates between three states:
   1. Thinking 🤔
   2. Eating 🍝
   3. Sleeping 😴

![Dining Philosophers](https://github.com/user-attachments/assets/4c4e725b-24d4-4ca6-9d43-d924f7e8fdad)

The goal is to prevent deadlocks and race conditions while philosophers try to eat without conflicts.

### 📌 Project Rules in 42

#### 🔹 Arguments

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

  


---
