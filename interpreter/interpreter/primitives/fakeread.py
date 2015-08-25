"""

Fakeread class models the 'fakeread' primitive. It tampers the readings 
of the sensors.

Fakeread is an overloaded primitive
The sintaxes of the primitive are:
 1) fakeread(nodeId, time, sensorId, noise, alpha, beta)
 2) fakeread(nodeId, time, sensorId, noise, alpha, beta, gamma)
 3) fakeread(nodeId, time, sensorId, noise, alpha, deltaH, deltaL, gamma)
 4) fakeread(nodeId, time, sensorId, noise, alpha, beta, tau, phi, gamma)
 + node Id is the Id of the target node
 + time is the occurrence time
 + sensorId is the target sensor of the target node
 + noise is the additive noise function to apply to the sensor reading
 + alpha, beta, gamma, deltaH, deltaL, tau, phi are parameters related to the noise functions
 
NB: nodeId and occurrence time are not stored in this object.

Author:
 + Francesco Racciatti	<racciatti.francesco@gmail.com>

Maintainer:
 + Francesco Racciatti <racciatti.francesco@gmail.com>

"""


from utilities import wrong_argc


class Fakeread:
    """
    fakeread(nodeId, time, sensorId, noise, alpha, beta)
    fakeread(nodeId, time, sensorId, noise, alpha, beta, gamma)
    fakeread(nodeId, time, sensorId, noise, alpha, deltaH, deltaL, gamma)
    fakeread(nodeId, time, sensorId, noise, alpha, beta, tau, phi, gamma)
    nodeId and time are not stored in this object
    """
    
    argv = []
    name = "Fakeread"
    
    argc4 = 4 # sensorID, noise, alpha, beta
    argc5 = 5 # sensorID, noise, alpha, beta, gamma
    argc6 = 6 # sensorID, noise, aplha, deltaH, deltaL, gamma
    argc7 = 7 # sensorID, noise, alpha, beta, tau, phi, gamma
    argc4noises = ['con']
    argc5noises = ['sen', 'sat', 'fix' ,'min', 'max', 'avg', 'inf', 'sup', 'med', 'sgn', 'rnd', 'lin']
    argc6noises = ['shp', 'sym']
    argc7noises = ['sin', 'sqr', 'saw', 'tri']
    
    def __init__(self, args):
        self.argv = args.split(":")
    
    def __str__(self):
        
        # check the number of arguments
        if (len(self.argv) == self.argc4) and (self.argv[1] in self.argc4noises):
            sensorID = self.argv[0]
            noise = self.argv[1]
            alpha = self.argv[2]
            beta = self.argv[3]
            
            params = sensorID + ":" + noise + ":" + alpha + ":" + beta
            xml = "\n\t\t\t<action>"
            xml += "\n\t\t\t\t<name>Fakeread</name>"
            xml += "\n\t\t\t\t<parameters>" + params + "</parameters>"
            xml += "\n\t\t\t</action>"
            
            return xml
        
        elif (len(self.argv) == self.argc5) and (self.argv[1] in self.argc5noises):
            sensorID = self.argv[0]
            noise = self.argv[1]
            alpha = self.argv[2]
            beta = self.argv[3]
            gamma = self.argv[4]
            
            params = sensorID + ":" + noise + ":" + alpha + ":" + beta + ":" + gamma
            xml = "\n\t\t\t<action>"
            xml += "\n\t\t\t\t<name>Fakeread</name>"
            xml += "\n\t\t\t\t<parameters>" + params + "</parameters>"
            xml += "\n\t\t\t</action>"
            
            return xml
        
        elif (len(self.argv) == self.argc6) and (self.argv[1] in self.argc6noises):
            sensorID = self.argv[0]
            noise = self.argv[1]
            alpha = self.argv[2]
            gamma = self.argv[3]
            deltaH = self.argv[4]
            deltaL = self.argv[5]
            
            params = sensorID + ":" + noise + ":" + alpha + ":" + gamma + ":" + deltaH + ":" + deltaL
            xml = "\n\t\t\t<action>"
            xml += "\n\t\t\t\t<name>Fakeread</name>"
            xml += "\n\t\t\t\t<parameters>" + params + "</parameters>"
            xml += "\n\t\t\t</action>"
            
            return xml
        
        elif (len(self.argv) == self.argc7) and (self.argv[1] in self.argc7noises):		
            sensorID = self.argv[0]
            noise = self.argv[1]
            alpha = self.argv[2]
            beta = self.argv[3]
            tau = self.argv[4]
            phi = self.argv[5]
            gamma = self.argv[6]
            
            params = sensorID + ":" + noise + ":" + alpha + ":" + beta + ":" + tau + ":" + phi + ":" + gamma
            xml = "\n\t\t\t<action>"
            xml += "\n\t\t\t\t<name>Fakeread</name>"
            xml += "\n\t\t\t\t<parameters>" + params + "</parameters>"
            xml += "\n\t\t\t</action>"
            
            return xml
        
        
        else:
            wrong_argc(self.name, len(self.argv))
