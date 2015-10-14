Description
============
This is the Attack Simulation Framework ++ (aka ASF++ or asfpp).
It is composed by three elments:
 + an Attack Description Language (ADL);
 + an Attack Description Interpreter (ADI);
 + an Attack Simulator.

ASF++ allows the user to simulate the effects of cyber-physical attacks against WSNs, collect data and, at the end, rank attacks.


Attack Description Language
===========================
The ADL is a real high-level description language that is independent from the underlying simulator.
By using the ADL, the user can describe cyber-physical attacks against WSNs.

The ADL allows the user to describe cyber-physical attacks in a very rapid and simple manner, avoiding him to actually implement the attacks.

In other words, the user must only describe attacks by editing a simple text file, he does not need neither to know how attacks are actually performed nor to implement them (by writing a lot of code).

The text file contains the description of the attacks, according to the ADL. Its format is '.adl'.


Attack Description Interpreter
==============================
The ADI is the 'glue' between the ADL (the high-level Attack Description Language) and the underlying simulator (ASF++).

The ADI interprets the '.adl' file (which contains the description of the attacks) and produces as output a  well-structured '.xml' file.


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
Produce an ADL file by using a simple text editor (and the ADL, of course). The ADL file, e.g. 'attacks.adl', contains the description of the attacks.

Step 3
Invoke the ADI. The interpreter take the ADL file 'attacks.adl' as input and produces the xml file 'attacks.xml'.

Step 4
Launch the simulation.


Build the simulator
===================
After building OMNeT++ 4.6 type:

``` sh
$ ./makemake
$ make
```

Designed and tested
===================
ASF++ is based on Castalia 3.2. It was succesfully tested with:
 + Ubuntu 14.04
 + OMNeT++ 4.5, OMNeT++ 4.6


User manual
===========
The user manual contains a lot of details about the installation process and the use of the simulator.


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>
+ Alessandro Pischedda	<alessandro.pischedda@gmail.com>
+ Marco Tiloca			<marco.tiloca84@gmail.com>
