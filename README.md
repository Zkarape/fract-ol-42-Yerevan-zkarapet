# Fract'ol

## 📖 Project Overview
Fract'ol is a 42 School graphical project focused on exploring and rendering fractals.
The project uses MiniLibX (a minimal graphics library) to open a window and render mathematical fractals in real time.
In addition to implementing the classic Mandelbrot and Julia sets, this version features a custom fractal designed from scratch!

## 🛠 Project Requirements
Only C programming language is allowed.

Use of MiniLibX for graphics.

Smooth and interactive user experience (mouse and keyboard controls).

Render at least Mandelbrot and Julia fractals.

Implement one custom fractal, invented personally.

Code must follow the 42 Norm coding style.

No memory leaks or crashes are allowed.

## 🖥 How to Use
1. Compilation
bash
make
This will compile the project and generate the fractol executable.

2. Running the Program
./fractol <fractal_name>

Fractal Name	Description
mandelbrot	Render the Mandelbrot set
julia	Render the Julia set
my_fractal	Render the custom invented fractal
Examples:

bash
./fractol mandelbrot
./fractol julia
./fractol my_fractal
## 🧩 Controls

Key / Mouse	Action
Arrow Keys	Move around the fractal
+ / -	Zoom in / Zoom out
Scroll Up / Down	Zoom in / Zoom out
Mouse Move (Julia)	Change Julia set parameters dynamically
C	Change color palette
ESC	Exit the program
## 🧠 Fractals Implemented
1. Mandelbrot Set
The classic and most iconic fractal.
Each point 
(𝑥,𝑦)
(x,y) is iteratively checked if it escapes to infinity.

2. Julia Set
A variation of Mandelbrot where the parameters are fixed and can be changed in real-time using the mouse position.

3. Custom Fractal: "My Fractal"
An original fractal design, bringing a new, unique, visually mesmerizing pattern.
It introduces:

New iterative formulas

Unique escape conditions

Distinctive aesthetic properties

Note:
This fractal is fully invented, making the project even more creative and personalized!

## 🏛 Project Structure
bash
fractol/
├── Makefile
├── fractol.h
├── main.c            # Program entry point
├── mandelbrot_set.c   # Mandelbrot set rendering
├── julia_set.c        # Julia set rendering
├── my_fractal.c       # Custom fractal rendering
├── draw.c             # Drawing functions
├── coloring.c         # Coloring and color palette functions
├── mouse_hook.c       # Mouse event handling
├── key_hook.c         # Keyboard event handling
├── utils.c            # Utility functions
├── ft_putendl.c       # Minimal I/O functions
## ✨ Features
Dynamic zooming and panning.

Real-time Julia parameter modification based on mouse position.

Multiple color palettes to create beautiful, vibrant images.

Original fractal creation demonstrating creativity beyond the mandatory part.

## 📚 References
Fractals - Wikipedia

Mandelbrot Set - Wikipedia

Julia Set - Wikipedia

MiniLibX Documentation (42 School)

## 🧙 Author
Project by zkarapet
42 School — Fract'ol
