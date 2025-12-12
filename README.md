# ASCII Parking Simulation
## Review

We have created and implemented cooperatively a terminal-based ASCII Parking Simulation in this project. It dynamically models autonomous cars entering, negotiating, parking, and leaving a parking lot. By using only ASCII characters, the software shows cars, parking places and traffic interactions in a lightweight but active simulation environment.

The main objective of this project is to simulate automobile behavior in a limited parking environment, including route finding, collision avoidance and dynamic parking management. This simulation also has a Busy Mode, that adds more complexity and uncertainty to the system by making different types of crashes.

 ## Qualities
 ### Simulated Setting

 - A completely enclosed ASCII-based parking lot with borders at the top, bottom, left, and right

 - The car entry and exit doors are clearly marked in the image
   
 - Automatic creation of several parking spaces each able to monitor reservations and occupancy

 - runtime adjustable dynamic number of autonomous cars

### Vehicle Response

In the parking, every car has several states:

 - Moving (M): Looking for a parking spot or getting out of the lot

 - Looking for/reserving (R): For moving toward a parking spot that is reserved
   
 - Parked (P): Briefly parked for an unknown length of time

 - Leaving (L): Leaving the parking area

 - Waiting (W): Time it takes for a spawn to appear before it can enter the lot

 - Despawned (D): Left the simulation

 - Damage (S): Reduced speed momentarily as a result of a small accident

 - Crashed/Broken (C): A vehicle that has crashed completely, shown in red

We have used a simple pathfinding method that can prevent contacts with walls, other cars and parking spaces, cars can automatically move around the parking lot.

Every car choose the closest open parking spot and drive toward it, so that they reserve the spot during navigation.

### Damage and Collision Mechanism

An all-encompassing collision detection system looks for:

 - The vehicle-to-vehicle collisions

 - The vehicle-to-wall impact

 - The collisions between cars and parking spaces

Busy Mode mimics high-traffic circumstances by offering the chance of random crashes (two possibilities):

 - 1 in 3 probability of a serious collision (car turns red and stops)

 - 2 in 3 probability of moderate injury (orange, sluggish movement)

The cars that crash open their reserved spots and change their motion in response.

### User Engagement

Hello Menu:

 - Adjustable car count (1–20)

 - Choice to turn Busy Mode ON or OFF

Real-time Information:

Vehicles in use, parked, and damaged in accidents

 - The time spent in simulation

 - The total of cars versus completed cars

End Menu:

 - Some summary data including whole simulation time and damaged vehicles

## Technical Information
### Implementation

The project is written in C, using ANSI escape codes for the terminal graphics.

Raw mode terminal can control enables smooth rendering and also real-time input handling.

Cars and parking slots using structs and arrays in modular design:

 - Every car in VEHICULE has his own characteristics (speed, state, position and assigned parking spot)

 - The PARKING_SLOT records reservation, position, size, and occupancy as well as each parking spot's dimensions

Utilizing ANSI codes for dynamic color coding:

 - Green: The car is moving or is parked

 - Orange: The car is slowed or damaged

 - Red: The vehicle is wrecked/broken

Thanks to the generation of autonomous vehicles we can guarantee non-overlapping spawn locations and a staggered arrival so that we can avoid a rapid congestion.

 ### Simulating Logic

Cars keep moving towards their target or leave to avoid hitting each other.

Stuck cars change their behavior dynamically --> re-setting reservations if they can't reach their goal.

To create seamless movement, the main loop refreshes positions (about 60 frames per second), clearing and redrawing the screen.

Parking habits behaves random:

 - The time the car spent in parking spot

 - Select closest free slot somewhat randomly

 ### Input and Output

Input:

 - The quantity of automobiles

 - Activating Busy Mode

 - The exit command (q) during simulation

Output:

 - The live ASCII parking lot, car, and slot visualization

 - The status bar showing the current simulation metrics

## Guidelines for our proyect

 1. How to assemble the project with any typical C compiler:
 gcc parking_simulation.c -o parking_sim

 2. We have to make sure the ASCII car model is in the same directory
 
 3. Simulate it by writing: ./parking_sim

 4. You can set the number of cars and activate Busy Mode by following the on-screen menu

 5. Press Enter to run the simulation

 6. Quit early by pressing q at any time

 7. See at last the simulation summary including crash and performance data

## Project Relevance

 Understanding traffic dynamics and parking lot management is made easier with this simulation, which is a teaching tool. It shows:

 - C object-oriented concepts with structs

 - Methods of real-time simulation in terminal settings

 - Collision detection and pathfinding in limited environments

 - Probability-based results and randomized occurrences for greater realism

Simulating autonomous vehicles in a small parking lot lets us examine how the vehicle behaves, the decision-making and congestion patterns under controlled conditions. Adding Busy Mode helps the simulation reflect densely packed parking situations, which sheds light on traffic flow improvement and crash avoidance.

## Author
 Dimitri Odinot and Jose Jurado
