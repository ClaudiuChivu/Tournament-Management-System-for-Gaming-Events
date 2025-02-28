# Tournament Management System for Gaming Events

## Overview

This project is a **Tournament Management System** designed for organizing gaming tournaments. It leverages advanced data structures to manage teams, players, match rounds, rankings, and more. The system includes efficient algorithms for team management, scheduling, and ranking, enabling seamless operation of gaming tournaments from start to finish.

## Features

- **Team Management**: Allows the registration of teams with players, storing their information efficiently.
- **Tournament Scheduling**: Automatically handles the scheduling of matches between teams based on predefined tasks.
- **Rankings**: Computes and displays rankings for teams after each round based on their performance.
- **Advanced Data Structures**: Uses data structures like **Linked Lists**, **Binary Search Trees (BST)**, and **AVL Trees** for optimal storage and access.
- **File I/O Operations**: Reads tournament and team data from files and outputs the results into specified files.
  

## Files

- `fisier0`: Input file containing tasks for the tournament.
- `fisier1`: Input file containing team and player information.
- `fisier2`: Output file to display results such as rankings and match outcomes.

## Data Structures Used

- **Linked List**: Used for managing and organizing teams and players dynamically.
- **Binary Search Tree (BST)**: Used to rank the top-performing teams.
- **AVL Tree**: Used for advanced team ranking and level classification.
  
## How to Use

### Input Files

1. **fisier1**: Contains information about teams, including the number of players and player data (name and score).
   - Example format:
     ```
     3
     5
     TeamA
     John Doe 100
     Jane Smith 80
     ...
     4
     TeamB
     Alice Brown 120
     Bob Green 90
     ...
     ```

2. **fisier0**: Contains task instructions (e.g., whether to display teams, run a round of matches, rank teams, etc.).
   - Example format:
     ```
     1
     0
     1
     1
     0
     ```

3. **fisier2**: Output file for storing results (team list, rankings, etc.).


