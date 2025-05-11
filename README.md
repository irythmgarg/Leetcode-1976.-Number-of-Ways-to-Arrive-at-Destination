# Leetcode-1976.-Number-of-Ways-to-Arrive-at-Destination
# 🚀 Count All Possible Shortest Paths using Dijkstra's Algorithm

This repository contains an efficient solution to **count the number of distinct shortest paths** from node `0` to node `n - 1` in a weighted undirected graph using **Dijkstra’s Algorithm**.

---

## 📌 Problem Statement

Given an undirected, weighted graph with `n` nodes (numbered `0` to `n-1`) and a list of roads, find the total number of **shortest paths** from node `0` to node `n - 1`. Since the answer can be large, return it modulo **1e9 + 7**.

---

## 🧠 Approach

- Use a **priority queue** (min-heap) to implement **Dijkstra’s algorithm**.
- Maintain:
  - `dist[i]`: the shortest distance from source node to node `i`.
  - `ways[i]`: the number of different shortest paths to node `i`.
- If a shorter path is found → update distance and reset `ways[i]`.
- If an equal-length path is found → add number of ways.

---

## 🛠️ Tech Stack

- Language: **C++**
- STL Structures used:
  - `vector`
  - `priority_queue`
  - `pair`
  - `modulo arithmetic`

---

## 📂 Example

### Input:
```cpp
n = 7
roads = {
    {0,6,7},
    {0,1,2},
    {1,2,3},
    {1,3,3},
    {6,3,3},
    {3,5,1},
    {6,5,1},
    {2,5,1},
    {0,4,5},
    {4,6,2}
}

output - 4

```
---


✅ Features
Handles graphs with up to 10^5 nodes and edges.

Uses Dijkstra with path counting optimization.

Efficient and competitive-programming ready.

---

📎 Related Topics
Graph Algorithms

Dijkstra’s Algorithm

Shortest Path Counting

Competitive Programming

---


👨‍💻 Author
Ridham Garg

B.Tech Computer Engineering

Thapar University, Patiala

Roll No: 102203014

📄 License
This project is open-source and available under the MIT License.

