# Simulation of special operation - rescue mission

## Project description

Simulation of a special operation, the goal of which is to free hostages without detection until they exit the building. Guards' routes are generated based on a text map, and the commando must tactically eliminate enemies and use available items to complete the mission successfully.

---

## Input parameters

- Number of commandos  
- Number of guards (maximum 10)  
- Items that the commando can use:  
  - Silencer (increases silent kill area)  
  - Smoke grenade (reduces the visibility of the guard)  
  - Stun grenade (stuns the guard for 1s)

---

## Output parameters

- Mission status: success or failure  
- Mission duration  
- Number of guards killed

---

## Behavior of the commandos

- Sneaking - slower, but inaudible to guards  
- Possibility to use objects  
- Silent kills - if a commando sneaks close to a guard, he can eliminate him silently

---

## Behavior of guards

- Spotting a commando - sounding an alarm, resulting in mission failure

---

## Limits

- Maximum of 10 guards  
- 1 commando

---

## The course of the simulation

The commando enters the building and begins the mission. Along the way he encounters guards, whom he must quietly eliminate, avoiding triggering an alarm. Various items are at his disposal to help him get to the hostages. All events are logged to a CSV file.

---


Translated with DeepL.com (free version)
