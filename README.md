# AIREngineerTest
----------------------------------------------

## Setup
Requirements: Unreal Engine 4.25.4, Visual Studio 2019

Fork this repository before cloning. Once forked, feel free to submit to it as much as you'd like. When completed, send us an email and a link to your fork of the repository.

## The Assignment
1. Create and implement a class of Robots that are capable of executing a series of Instructions given to them
2. Set up two Robots with differing behavior, the first a "Dropper" that randomly roams around a map dropping Spheres, and a "Grabber" that seeks those Spheres in order to properly document them (and then destroy the evidence). 

Both Robots should be derived from a base Robot class (parent class `APawn`) that you define and implement. Each Robot should be capable of ingesting a queue of Instructions (fed from itself or an external entity) and then execute them one after another. All Robots should be capable of correctly executing all types of Instructions.

## Robot Instructions
- At minimum, you must implement Instructions that enable a Robot to :
	- Move forward - Your Robots should **not** collide with each other or the map environment. There is no expectation of the Robots navigating vertically, only along the X and Y axes.
	- Rotate
	- Wait
	- Drop a Sphere - To be used by a Dropper Robot. 
	- Document a Sphere - To be used by the Grabber Robot. At minimum, this Instruction -must- 
		1. take a screenshot of the Sphere within a reasonable distance
		2. output a text file with a list of the actor names that are in the viewport when the image is taken. Each image should have a corresponding text file. (ie: image_1.png and image_1_actors.txt)
		3. destroy the Sphere

- All Instructions should be derived from the base `URobotInstruction` UObject class, the shell of which has been provided. Each Instruction child should only implement one general type of behavior. 
- The Instructions are intended to be leveraged by someone else on the team who cannot modify their logic (perhaps a level designer with limited Blueprint knowledge). Because of this, Instructions should have a reasonable about of parameters or inputs exposed. For example, an Instruction that instructs the Robot to move forward in a direction should probably have a "distance" parameter that can be set.
- You are encouraged to create as many additional Instruction types as you think would be useful for this scenario. Instructions should create, call and/or reference other Instructions where it makes sense to do so.

## The Project
We have provided the following content for this task:
- `Content/AIReverie/Robot_TestMap` : The level used for evaluating. This is the only part of the project that should not be modified in any way.
- `Content/AIReverie/BP_AIReverie_GameMode`: A game mode created and set as the default in the project.
- The provided `URobotInstruction` UObject class, and project base classes.


## Expectations
- When evaluating, both Robot types will be placed in a random location on the included map and then we will hit Play. Upon hitting Play, the viewport should be from the POV of the Grabber Robot, and the two Robots should immediately begin executing their instructions. The Robots should diligently continue their tasks until we exit the Play session.
- We are not expecting advanced AI logic or complex navigation. Feel free to make things as complicated as you like but keep in mind whatever you implement, the Robots and their Instructions should **function** above all else.
- Feel free to leverage both C++ and Blueprints where you think it would make the most sense to do so, given that these Robots should be able to be setup by a non-programmer. Please use UE4 conventions and frameworks for all C++ implementations. Add as many classes or structs you feel is necessary to accomplish the task, you must use the provided `URobotInstruction` UObject class and its included `ExecuteInstruction()` function, but these can be modified as you see fit.
- Using plugins or editing Project & Editor configuration files shouldn't be necessary. Please contact us if there's something you'd like to change or use.
- Online research, UE4 documentation, etc. are all fair game. Google to your heart's content!
- Performance is not a concern for this. Feel free to get all actors in the viewport as naively as you would like, and if you have ideas on how to make it more performant you can just let us know your thoughts when you submit your final project.

If you are unclear on **any** part of these instructions, please reach out and we will be more than happy to clarify what we are expecting.

Good luck, and have fun!