ASCII Parking Lot Simulation
Overview

This project is a terminal-based ASCII Parking Lot Simulation, designed and implemented collaboratively by two developers. It simulates autonomous vehicles entering, navigating, parking, and exiting a parking lot in real time. The program visualizes cars, parking slots, and traffic interactions entirely using ASCII characters, creating a lightweight yet dynamic simulation environment.

The primary goal of this project is to model vehicle behavior in a constrained parking environment, including pathfinding, collision detection, and dynamic parking management. Additionally, the simulation incorporates a “Busy Mode”, which introduces variable crash scenarios, adding unpredictability and complexity to the system.

Features
Simulation Environment

- Fully enclosed ASCII-based parking lot with top, bottom, left, and right borders.

- Entry and exit doors for cars, clearly indicated in the visualization.

- Automatic generation of multiple parking slots, each capable of tracking occupancy and reservations.

- A dynamic number of autonomous cars, configurable at runtime.

Vehicle Behavior

Each vehicle has multiple states:

- Moving (M): Searching for a parking slot or leaving the lot.

- Reserved/Seeking (R): Heading toward a reserved parking slot.

- Parked (P): Temporarily parked for a random duration.

- Leaving (L): Exiting the parking lot.

- Waiting (W): Spawn delay before entering the lot.

- Despawned (D): Exited the simulation.

- Slowed/Damaged (S): Temporarily slowed due to minor collision.

- Crashed/Broken (C): Fully crashed vehicle, visualized in red.

Vehicles can autonomously navigate the parking lot using a simple pathfinding algorithm that avoids collisions with walls, other cars, and parking slots.

Cars select the nearest available parking slot and move toward it, reserving the slot during navigation.

Collision and Damage System

A comprehensive collision detection system checks for:

- Vehicle-to-vehicle collisions

- Vehicle-to-wall collisions

- Vehicle-to-parking-slot collisions

Busy Mode introduces the possibility of random crashes, simulating high-traffic conditions:

- 1/3 chance of a severe crash (car becomes red and inactive)

- 2/3 chance of minor damage (orange, slower movement)

Vehicles that collide free up their reserved slots and adjust their movement accordingly.

User Interaction

Welcome Menu:

- Configurable number of cars (1–20)

- Option to enable or disable Busy Mode

Real-time Information:

- Active, parked, and crashed vehicles

- Elapsed simulation time

- Completed vs total cars

End Menu:

- Summary statistics including crashed cars and total simulation duration

Technical Details
Implementation

Written in C, leveraging ANSI escape codes for terminal graphics.

Raw mode terminal control allows real-time input handling and smooth rendering.

Modular design using structs and arrays for cars and parking slots:

- VEHICULE struct represents each car with attributes for position, speed, state, and target parking slot.

- PARKING_SLOT struct tracks each parking spot’s position, dimensions, occupancy, and reservation.

Dynamic color coding using ANSI codes:

- Green: Moving or parked cars

- Orange: Slowed/Damaged cars

- Red: Crashed/Broken cars

Autonomous vehicle generation ensures non-overlapping spawn points and staggered entry to prevent immediate congestion.

Simulation Logic

Vehicles continuously move towards their assigned target or exit while avoiding collisions.

Stuck vehicles dynamically adjust their behavior, resetting reservations if they cannot reach their target.

The main loop updates positions at ~60 frames per second, clearing and redrawing the screen to simulate smooth movement.

Parking behavior is randomized:

- Duration in parking slot

- Selection of nearest free slot with slight random bias

Input and Output

Input:

- Number of vehicles

- Busy Mode activation

- Quit command (q) during simulation

Output:

- Real-time ASCII visualization of parking lot, cars, and slots

- Status bar with current simulation metrics

Usage Instructions

1. Compile the project using any standard C compiler:
gcc parking_simulation.c -o parking_sim

2. Ensure carmodelfront.txt is in the same directory, containing the ASCII car model.

3. Run the simulation:
./parking_sim

4. Follow the on-screen menu to configure the number of cars and enable Busy Mode.

5. Press ENTER to start the simulation.

6. Press q at any time to quit early.

7. At the end, view the simulation summary with performance and crash statistics.

Project Significance

This simulation serves as a pedagogical tool for understanding traffic dynamics and parking lot management. It demonstrates:

- Object-oriented thinking in C using structs

- Real-time simulation techniques in terminal environments

- Collision detection and pathfinding in constrained spaces

- Randomized events and probability-based outcomes for enhanced realism

By simulating autonomous vehicles in a simplified parking lot, we can explore vehicle behavior, decision-making, and congestion scenarios in a controlled environment. The addition of Busy Mode allows the simulation to mimic high-density parking conditions, providing insight into crash prevention and traffic flow optimization.

Authors
Dimitri Odinot and Jose Jurado
