Description
============
Example of use of the primitive 'destroy'.

The primitive 'destroy' destroies a node.

It is a physical primitive.


Sintax
======
destroy(nodeId, occurrenceTime)

args:
 + nodeId is the Id of the node to destroy
 + occurenceTime is the start time of the action


Usage of the interpreter
========================
$ python <relative_path/interpreter.py> -i <file_input> -o <file_output>

or you can use the bash script for conveniente (if present, else you can build it):

$ ./bash_script.sh

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ASL description in the input file.


Example
=======
$ python ../../interpreter.py -i destroy-one.asl -o destroy-one.xml

or

$ python ../../interpreter.py -i destroy-one.asl

or you can use the pre-built bash script

$ ./destroy-one.sh


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
