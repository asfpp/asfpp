Description
============
This is the Attack Simulation Framework ++ (aka ASF++ or asfpp).
It is composed by three elmeents:
 + an Attack Specification Language (ASL);
 + an interpreter;
 + an Attack Simulator.

It allows the user to simulate the effects of cyber-physical attacks against WSNs, collect data and, at the end, rank attacks.


Attack Specification Language
============================= 
The ASL is a real high-level specification language that is independent from the underlying simulator.
By using the ASL, the user can describe cyber-physical attacks against WSNs.

Note: the user only describes attacks, he does not implement them!

In other words, the user does not need to know how attack are actualy implemented and, of course, 
the user does not need to write a lot of code to implement attacks!


Interpreter
===========
The interpreter is the glue between the ASL (the high-level Attack Specification Language) and the underlying simulator (ASF++).
The interpreter interprets an input file that contains the description of the cyber-physical attacks (aka '.asl' files).
Its output is a well-structured '.xml' file (aka Attack Configuration File), which will be parsed by the real attack simulator. 


Attack Simulator
================
The attack simulator is the core of the ASF++. It simulates the effects of the attacks that are described in the xml file.

Note: the simulator does not performs attacks, it only simulates the final effects of them.

By running the simulations, the user can collect data and, by using them, rank attacks.


User manual
===========
The user manual contains a lot of details about the installation process and the use of the simulator.


Authors
=======
+ Alessandro Pischedda	<alessandro.pischedda@gmail.com>
+ Marco Tiloca			<marco.tiloca84@gmail.com>
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
