![cover-philosophers](https://github.com/user-attachments/assets/c64e97df-7758-46a5-bc91-f75ede5cedc4)

The Dining Philosophers project is part of the **42 curriculum**, designed to teach threads, synchronization, and concurrency issues in C using pthread.

It is based on the classic Dining Philosophers Problem, described by **Edsger Dijkstra** in 1965, which models process synchronization in operating systems.

![Dining Philosophers](https://github.com/user-attachments/assets/4c4e725b-24d4-4ca6-9d43-d924f7e8fdad)


📌 The Dining Philosophers Problem

🔹 Context

Five philosophers are seated at a circular table, where each has:
- A plate of spaghetti 🍝
- A fork on the left and another on the right 🍴🍴

To eat, a philosopher must pick up two forks—one from their right and left. However, forks are shared with their neighbors.

Each philosopher alternates between three states:
	1.	Thinking 🤔
	2.	Eating 🍝
	3.	Sleeping 😴

The goal is to prevent deadlocks and race conditions while philosophers try to eat without conflicts.


---
