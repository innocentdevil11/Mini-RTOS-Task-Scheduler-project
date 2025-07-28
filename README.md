# 🧠 Mini RTOS Task Scheduler Simulator (C)

This project simulates a basic Real-Time Operating System (RTOS) task scheduler using C. It mimics how embedded systems manage tasks using priority-based preemptive scheduling.

## 🚀 Features

- Priority-based task scheduling (lower number = higher priority)
- Simulated task states: `READY → RUNNING → TERMINATED`
- Burst time tracking for each task
- Clean terminal output mimicking task logs
- Written in pure C — no external libraries

## 📄 How It Works

Each task is defined with:
- `ID`: Task number
- `Burst Time`: Duration the task runs
- `Priority`: Lower value = higher priority
- `State`: Tracks if the task is running, ready, or completed

The scheduler:
- Selects the highest-priority task that’s still incomplete
- Runs it for 1 simulated unit (`sleep(1)`)
- Logs every transition
- Marks task as completed when burst time is over

## 🧪 Sample Output

