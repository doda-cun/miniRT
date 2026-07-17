*This project has been created as part of the 42 curriculum by lderks, doda-cun*

# miniRT

## What is this?
A ray tracing engine built from scratch in C as part of the CODAM
(42 Network) curriculum by lderks and doda-cun. Renders 3D scenes
by simulating how light interacts with objects — the same fundamental
technique used in CGI and movie visual effects.

## How it works
miniRT reads a .rt scene file describing objects, lights and a camera,
then calculates for each pixel on screen whether and how a ray of light
intersects with objects in the scene. The result is a rendered 3D image
with realistic lighting and shadows.

## Features
- Supported objects: spheres, planes and cylinders
- Ambient lighting
- Diffuse shading
- Hard shadows
- Scene definition via .rt configuration files

## Usage
```bash
make
./miniRT scenes/(name of scene).rt
```
Scene requirements:
- Must have a camera, light, ambiance and at least one object
- Only .rt extension accepted
- All coordinates, normalized vectors, FOV and color values must be in range

![Ray traced scene] (images/miniRTscene1.png)
![ray traced scene 2] (images/miniRTscene2.png)
![ray traced scene 3] (images/miniRTscene3.png)

## What I learned
How ray tracing works mathematically — vector operations, dot products,
cross products, surface normals and how light behaves in 3D space.
Building this completely changed how I think about computer graphics
and rendering.

## Resources
- [HillsoftCode Ray Tracing YouTube series](https://www.youtube.com/watch?v=RIgc5J_ZGu8&t=17s)
  — helped organise code structure and understand the math
- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
  — foundational reference for ray tracing concepts
- Claude (Anthropic) — used as an AI assistant for debugging, explaining
  mathematical concepts (normals, dot products, cross products), fixing
  compilation errors, and understanding the rendering pipeline

## Personal note
This was a challenging. Understanding how light actually behaves in 3D space and translating that into math and code was unlike anything else in the curriculum. Doing a project this
math-heavy with no prior mathematics background was genuinely intense.
But, not going to lie, seeing a rendered scene appear for the first time after getting the math
right was a satisfying moment.


