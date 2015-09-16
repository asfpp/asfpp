# Tamper sensor reading of nodes 9 and 10.
#
# author: Francesco Racciatti <racciatti.francesco@gmail.com>


# tampers the sensor 0 of node 1 from time 50, it applies the noise 'sin'
fakeread(9, 200, 0, sin, 0.1, 5, 20, 0, 0)

# tampers the sensor 0 of node 2 from time 100, it applies the noise 'sin'
fakeread(10, 200, 0, sin, 0.1, 5, 20, 0, 0)
