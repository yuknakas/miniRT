# TO-DO
1. Setup screen
2. Convert pixel on window -> coord in 3d world
3. Get vector camera->coord
4. Find if it intersects with object
5. Find closest object
6. Show on screen...

Line-sphere intersection  
[wikipedia](https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection)  

Line-plane intersection  
[wiki](https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection)  

Lin-cylinder intersection  
[wiki](https://en.wikipedia.org/wiki/Line-cylinder_intersection)  

all points of intersetion should be noted down for transparent objects


parser
1. check filetype
1.1 Initialize
2. read line
3. make object from line
4. if invalid free


Flow  
input  
->Parse  
->Setup Display  

for every pixel  
-> make ray  
-> find obj  
-> return color  
*add light/reflection to this

[Valuable Source](https://www.gabrielgambetta.com/computer-graphics-from-scratch/02-basic-raytracing.html)  

Returning Color  
Info needed  
- Point of intersection
- Light types
-> Amb light simply add  
-> Point light needs normal to suface


Data types
1. x, y of pixel and all relavant display info
2. vector to pixel, min distance
3. closest object id, distance
4. point of intersection, normal  


Bugs  
- A makes the whole color change