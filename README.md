Description
============
This is the Attack Simulation Framework ++ (aka ASF++ or asfpp).
It is composed by three elments:
 + an Attack Specification Language (ASL);
 + an interpreter;
 + an Attack Simulator.

ASF++ allows the user to simulate the effects of cyber-physical attacks against WSNs, collect data and, at the end, rank attacks.


Attack Specification Language
============================= 
The ASL is a real high-level specification language that is independent from the underlying simulator.
By using the ASL, the user can describe cyber-physical attacks against WSNs.

The ASL allows the user to describe cyber-physical attacks in a very rapid and simple manner, avoiding him to actually implement the attacks.

In other words, the user must only describe attacks by editing a simple text file, he does not need neither to know how attacks are actually performed nor to implement them (by writing a lot of code).

The text file contains the description of the attacks, according to the ASL. Its format is '.asl'.


Interpreter
===========
The interpreter is the 'glue' between the ASL (the high-level Attack Specification Language) and the underlying simulator (ASF++).

The interpreter interprets the '.asl' file (which contains the description of the attacks) and produces as output a  well-structured '.xml' file.


Attack Simulator
================
The attack simulator is the core of the ASF++. It parses the '.xml' file produced by the interpreter and simulates the effects of the attacks.

Note: the simulator does not performs attacks, it only simulates the final effects of them.


Workflow
========
Step 0
Build the simulator.

Step 1
Build a simulation scenario (based on Castalia) by using the NED language.

Step 2
Produce an ASL file by using a simple text editor (and the ASL, of course). The ASL file, e.g. 'attacks.asl', contains the description of the attacks.

Step 3
Invoke the interpreter. The interpreter take the ASL file 'attacks.asl' as input and produces the xml file 'attacks.xml'.

Step 4
Launch the simulation.


Build the simulator
===================
``` sh
$ ./makemake
$ make
```


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
