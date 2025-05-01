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

https://en.wikipedia.org/wiki/Mandelbrot_set

https://www.youtube.com/playlist?list=PLiaHhY2iBX9g6KIvZ_703G3KJXapKkNaF

https://www.youtube.com/watch?v=MwjsO6aniig

https://realpython.com/mandelbrot-set-python/


https://docs.microsoft.com/en-us/cpp/cpp/event-handling-in-native-cpp?view=msvc-170

https://gontjarow.github.io/MiniLibX/

https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set


https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand

https://github.com/agavrel/42-fractol

https://github.com/BenSouchet/fractol

https://harm-smits.github.io/42docs/libs/minilibx/colors.html

MiniLibX Documentation (42 School)

## 🧙 Author
Project by zkarapet
42 School — Fract'ol



https://github.com/user-attachments/assets/2009b935-0332-4c9b-bd36-46b3dfa2bf9a



