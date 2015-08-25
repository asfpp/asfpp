Description
============
Example of use of the primitive 'send'.

The primitive 'send' sends a new packet (created or cloned) to the following layer in the communication stack.

It is a logical primitive, i.e. a primitive that can be used in conditional or unconditional attacks.


Sintax
======
send(packetName, delay)

args:
 + packetName is the name of the target packet
 + delay is the forwarding delay


Usage of the interpreter
========================
$ python <relative_path/interpreter.py> -i <file_input> -o <file_output>

or you can use the bash script for conveniente (if present, else you can build it):

$ ./bash_script.sh

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ASL description in the input file.


Example
=======
$ python ../../interpreter.py -i send.asl -o send.xml

or

$ python ../../interpreter.py -i send.asl

or you can use the pre-built bash script

$ ./send.sh


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
