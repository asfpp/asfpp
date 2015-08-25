Description
============
Example of use of the primitive 'fakeread'.

The primitive 'fakeread' tampers the measurements of a sensor of a node.

It is a physical primitive.
It is an overloaded primitive.

Sintax
======
fakeread(nodeId, time, sensorId, noise, alpha, beta)
fakeread(nodeId, time, sensorId, noise, alpha, beta, gamma)
fakeread(nodeId, time, sensorId, noise, alpha, deltaH, deltaL, gamma)
fakeread(nodeId, time, sensorId, noise, alpha, beta, tau, phi, gamma)

args:
 + nodeId is the Id of the target node
 + occurenceTime is the start time of the action
 + sensorId is the Id of the sensor of the target node
 + noise is the noise function to apply to sensor measurements
 + alpha, beta, gamma, deltaL, deltaH, tau, phi are parameters of the noise functions
  

Usage of the interpreter
========================
``` sh
$ python path/interpreter.py -i inputfile -o outputfile
```

or you can use the bash script for conveniente (if present, else you can build it):

``` sh
$ ./bash_script.sh
```

Example
=======
``` sh
$ python ../../interpreter.py -i fakeread-simple.asl -o fakeread-simple.xml
```

or

``` sh
$ python ../../interpreter.py -i fakeread-simple.asl
```

or you can use the pre-built bash script

``` sh
$ ./fakeread-simple.sh
```


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
