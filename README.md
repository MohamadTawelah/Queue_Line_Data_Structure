# 💥 Project 22 — QueueLine Data Structure

> Practical implementation of a Queue Line system built on top of the Queue data structure using C++ STL.

---

## 🚀 Project Overview

This project is a real-world simulation of a **Queue Management scenario**.

Imagine going to a telecom company or a government office:

- You select a service from a screen  
- A ticket is printed  
- The ticket contains:
  - Ticket number
  - Printing time
  - Number of waiting clients
  - Expected service time
- You wait until your number appears on the screen  

Each service has its own queue.

This project implements the **data structure** that makes such systems possible.

We are not building the full Queue Management System.

We are building the engine behind it.

---

## 🏗 Architecture Design

The project introduces a custom class:

### `clsQueueLine`

This class represents a complete service queue.

Inside it, there is a nested class:

### `clsTicket`

Each ticket contains:

- Full ticket number (Prefix + Number)
- Ticket issue time
- Number of waiting clients before it
- Expected serve time

All tickets are stored inside a standard STL queue.

This means:

QueueLine → manages many Tickets  
Ticket → holds all ticket-related information  

Clean separation.  
Clear responsibility.

---

## 🧠 Why STL Queue & Stack?

In this project, we used:

- `std::queue`
- `std::stack`

Instead of our custom implementations.

Why?

Because we did not yet extend our custom structures to fully support advanced data types like classes and structs.

Supporting complex data types properly requires:

- Copy constructors
- Casting concepts
- Deeper memory handling topics

And this is not the focus right now.

The goal here is to:

Play with data structures.
Connect ideas.
Understand behavior.
Apply concepts practically.

---

## ⚙ Core Functionalities

The QueueLine supports:

- Issuing new tickets
- Serving next client
- Checking who is next
- Printing queue information
- Printing tickets left-to-right
- Printing tickets right-to-left
- Printing full ticket details

---

## 🔄 Printing Strategy Insight

If we print directly from the original queue,
we would lose all tickets (because queue pops elements).

So we:

- Copy the queue into a temporary queue for safe printing.

For reverse printing:

- We copy the queue into a stack.
- Since stack reverses order naturally,
  we can print tickets in the opposite direction.

This demonstrates practical interaction between:

Queue → FIFO  
Stack → LIFO  

---

## 🎯 What This Project Teaches

- Real-world Queue application
- Nested classes design
- Managing service lines
- Combining Queue & Stack
- Safe data traversal using copies
- System-oriented thinking
- Clean code organization

More importantly:

It shows how to structure logic clearly and professionally.

---

## 🏁 Milestone Announcement

This is:

- The last project in C++
- The final project in  
  **Course 13 - Algorithms & Problem Solving - Level 5**
- The final project of Stage One  
  (The first 13 courses roadmap)

Alhamdulillah.

"الحمد لله الذي هدانا لهذا وما كنا لنهتدي لولا أن هدانا الله"

It has been a long journey.

Full of:

- Errors
- Debugging
- Confusion
- Challenges
- Persistence
- Growth

But we built strong foundations.

We struggled.
We learned.
We improved.

And most importantly,
we became stronger programmers.

---

## 🙏 Gratitude

Thank you to:

**Programming Advices Platform**  
**Dr. Mohammed Abu-Hadhoud**

**[ https://programmingadvices.com ]**

He was not just an instructor.

He was:

- A mentor
- A coach
- A guide
- A motivator
- A teacher who understands timing

Because the real secret of success in programming is:

- Proper progression
- Correct guidance
- The right timing to learn each concept

And that is exactly what we experienced.

---

## 🚀 What’s Next?

Stage Two begins.

It will be more exciting.
More advanced.
More powerful.

And easier.

Because now,
we are built correctly.

The foundation is solid.

The coming journey will be stronger, deeper, and greater — Insha’Allah.

---

## 🔥 Final Thought

We did not just learn C++.

We built engineering thinking.

And this is only the beginning.
