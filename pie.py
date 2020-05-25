import random;
import math;

samples = 1000;
inside = 0;
x = 0;
y = 0;

for i in range (0, samples):
	x = random.random();
	y = random.random();

	if math.sqrt(x*x + y*y) <= 1:
		inside += 1;

pie = 4*inside/samples;

print(pie);
