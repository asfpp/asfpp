Description
============
Example of use of the primitive 'fakeread'.

The primitive 'fakeread' tampers the measurements of a sensor of a node.

It is a physical primitive.

Sintax
======
fakeread(nodeId, time, sensorId, function)noise, alpha, beta)

args:
 + nodeId is the Id of the target node
 + occurenceTime is the start time of the action
 + sensorId is the Id of the sensor of the target node
 + function is the function (STRING) to apply to sensor measurements
  

Usage of the interpreter
========================
``` sh
$ python path/interpreter.py -i inputfile -o outputfile
```

or you can use the bash script for convenience:

``` sh
$ ./bash_script.sh
```

Example
=======
``` sh
$ python ../../interpreter.py -i fakeread-simple.adl -o fakeread-simple.xml
```

or

``` sh
$ python ../../interpreter.py -i fakeread-simple.adl
```

or you can use the pre-built bash script

``` sh
$ ./fakeread-simple.sh
```


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>
