# Fractol

With this program you can:

-adjust iteration with "</>"

-Get random color with "c"

-Adjust Red with "e/r"

-Adjust Green with "f/g"

-Adjust Blue with "v/b"

-Zoom at center of window with "-/+" left of backspace

-Zoom with "scroll wheels"

-Set a position with "right click"

-Activate motion with "left click"

-Reset fractal with "o"

-Calculate fractal with OpenCL

How to launch :

git clone http://github.com/Remaii/Fractol.git

cd Fractol

make

No OpenCL = ./fractol (with name of fractal, Mandelbrot, Julia, Burningship | you can use just first letter of fractal name)

          example : ./fractol m -> launch Mandelbrot
                    ./fractol j -> launch Julia
                    ./fractol b -> launch Burningship

With OpenCL = ./fractol [name of fractal] cl

          example : ./fractol m cl -> launch Mandelbrot with OpenCL
                    ./fractol j cl -> launch Julia with OpenCL
                    ./fractol b cl -> launch Burningship with OpenCL
