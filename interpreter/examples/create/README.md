Description
============
Example of use of the primitive 'create'.

The primitive 'create' creates a packet. The new packet must be filled by using the action 'change'.

It is a logical primitive, i.e. a primitive that can be used in conditional or unconditional attacks.


Sintax
======
create(newPacketName, layer.type, value)

args:
 + newPacketName is the name of the new packet
 + layer.type identifies the layer and the protocol
 + value identifies the particular packet of the protocol


Usage of the interpreter
========================
$ python <relative_path/interpreter.py> -i <file_input> -o <file_output>

or you can use the bash script for conveniente (if present, else you can build it):

$ ./bash_script.sh

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ASL description in the input file.


Example
=======
$ python ../../interpreter.py -i create-conditional.asl -o create-conditional.xml

or

$ python ../../interpreter.py -i create-conditional.asl

or you can use the pre-built bash script

$ ./create-conditional.sh


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
