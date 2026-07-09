# tester

Test scenes for manual/regression checking.

- `simple_sphere.rt`, `simple_cylinder.rt`, `oriented_plane.rt`, `multi_plane.rt`, `complex.rt`, `mirror_room.rt` — basic valid scenes (adapted from https://github.com/Pastifier/miniRT scenes/, MIT license; bonus-only syntax like SL/co/cu/M removed since this project only implements the mandatory part)
- `edge_*.rt` — edge cases: camera inside a sphere, camera very far away, light inside an object, touching spheres, camera on a diagonal axis, huge coordinate values
- `err_*.rt` — cases that should be rejected with an Error: duplicate A/C/L, missing camera, undefined element, malformed vector, negative diameter, blank line
