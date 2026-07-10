_This project has been created as part of the 42 curriculum by yuknakas, kmitsuki._

# miniRT

My first RayTracer with MiniLibX

## Description

miniRT is a ray tracer coded in C, without any external 3D/rendering
library besides MiniLibX. Given a scene description file (`*.rt`), it
computes an image of that scene as seen from a camera, and displays it
in a window.

A scene is made of:

- one ambient light (`A`)
- one camera (`C`)
- one light source (`L`)
- any number of spheres (`sp`), planes (`pl`) and cylinders (`cy`)

For every pixel of the window, a ray is cast from the camera through
that pixel into the scene. The closest object hit by the ray
determines the pixel's color, computed from ambient + diffuse
lighting and hard shadows (the point of intersection is occluded from
the light by another object).

Implemented (mandatory part):

- Ray/sphere, ray/plane, ray/cylinder intersection, including the
  inside of each object.
- Translation of objects, lights and the camera (rotation as well,
  except for spheres and lights, which the subject excludes from
  rotation).
- Resizing: sphere diameter, cylinder diameter and height.
- Ambient + diffuse lighting, with hard shadows.
- ESC and the window's close button both quit cleanly.

Implemented (bonus, beyond the mandatory part):

- Keyboard controls to move the selected element and resize
  spheres/cylinders (see Controls below).
- Mouse controls to select an object, redirect the camera, and zoom
  in/out.

## Instructions

### Compilation

```sh
make        # builds the miniRT binary
make re     # fclean + all
make clean  # removes object files
make fclean # removes object files and the binary
```

MiniLibX (and its own dependencies, e.g. X11 libraries) is required.

### Running

```sh
./miniRT <scene.rt>
```

`tester/` contains scene files to try, including valid scenes and
scenes that are expected to be rejected with an error (see
`tester/README.md`).

### Scene file format

Each line starts with a one- or two-character identifier followed by
that element's parameters, separated by spaces. `A`, `C` and `L` may
each appear at most once in the file; `sp`, `pl` and `cy` may repeat.

```
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,0,30 0.6 10,0,255
sp 0,0,20.6 12.6 10,0,255
pl 0,0,-10 0,1,0 0,0,225
cy 50,0,20.6 0,0,1 14.2 21.42 10,0,255
```

| id | element | fields |
|----|---------|--------|
| `A` | ambient light | ratio [0,1], color |
| `C` | camera | coords, orientation (normalized), FOV [0,180] |
| `L` | light | coords, brightness [0,1], color (unused in mandatory part) |
| `sp` | sphere | coords, diameter, color |
| `pl` | plane | a point on the plane, normal (normalized), color |
| `cy` | cylinder | coords, axis (normalized), diameter, height, color |

Any misconfiguration causes the program to print `Error\n` followed
by an explanation, and exit.

### Controls

Left-click an object to select it, then:

| key | action |
|-----|--------|
| ESC | quit |
| W / A / S / D | move the selected element up / left / down / right, relative to the camera |
| P / O | grow / shrink the selected sphere or cylinder's diameter |
| L / K | grow / shrink the selected cylinder's height |
| C | select the camera |
| V | select the light |

Mouse:

| action | effect |
|--------|--------|
| left click | select the object under the cursor |
| right click | point the camera at the clicked point |
| scroll up / down | zoom in / out (changes the FOV) |

## Resources

- [Line-sphere intersection (Wikipedia)](https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection)
- [Line-plane intersection (Wikipedia)](https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection)
- [Computer Graphics from Scratch, ch. 2](https://www.gabrielgambetta.com/computer-graphics-from-scratch/02-basic-raytracing.html)
- the 42 miniRT subject PDF

### AI usage

AI (Claude) was used to translate this README, and to help write a
few of the edge-case test scenes in `tester/`.
