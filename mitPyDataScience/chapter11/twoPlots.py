import pylab

pylab.figure(1)
pylab.plot([1,2,3,4],[1,2,3,4])
pylab.figure(2)
pylab.plot([1,2,3,4],[5,6,7,8])
pylab.savefig("Figure-Addie") #saves figure 2 to Figure-Addie.png
pylab.figure(1)
pylab.plot([5,6,10,3])
pylab.savefig("Figure-Jane") #saves figure 1 to Figure-Jane.png
