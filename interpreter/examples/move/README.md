Description
============
Example of use of the primitive 'move'.

The primitive 'move' moves a node in the simulation field.

It is a physical primitive.


Sintax
======
move(nodeId, occurrenceTime, x, y, z)

args:
 + nodeId is the Id of the node to move
 + occurenceTime is the start time of the action
 + x is the 'x' coordinate of the simulation field
 + y is the 'y' coordinate of the simulation field
 + z is the 'z' coordinate of the simulation field


Usage of the interpreter
========================
$ python <relative_path/interpreter.py> -i <file_input> -o <file_output>

or you can use the bash script for conveniente (if present, else you can build it):

$ ./bash_script.sh

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ASL description in the input file.


Example
=======
$ python ../../interpreter.py -i move-one.asl -o move-one.xml

or

$ python ../../interpreter.py -i move-one.asl

or you can use the pre-built bash script

$ ./move-one.sh


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
