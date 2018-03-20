

----------------------
Instructions and Notes
----------------------

To run the code the following libraries must be installed:
1. OpenCV 3.3 (later versions should also work)
2. Armadillo 3.920 or higher - http://arma.sourceforge.net

To Run:
g++ -o ForegroundSegmentation main.cpp input_preprocessor.cpp -fopenmp -DARMA_DONT_USE_WRAPPER -lopenblas -llapack -larmadillo -std=c++11 `pkg-config opencv --cflags --libs'


./ForegroundSegmentation /home/user/Downloads/foreground_detection_code/seq/ seqs


where: ./ForegroundSegmentation  <set input path sequence>   <sequence name>
<set input path sequence> is location of frames from the video
<sequence name> is the sequence name


Installation Instructions:

https://solarianprogrammer.com/2017/03/24/getting-started-armadillo-cpp-linear-algebra-windows-mac-linux/


Points to note:

1.
Supported input formats: png, jpeg, bmp and tif.

2.
Internally, the code sorts the input image files of a given folder in ascending order.
Hence, the file names must contain a constant number of digits in their suffixes
(eg. test_0001, test_0002, test_0100, test_1000,...).

3.
Initially, the algorithm uses first 200 frames to build a model of the background
before producing foreground mask for each frame. 

4.
To save the masks, WRITEMASK must be defined in main.hpp (by default, this is defined).
An output folder is automatically created to store all the generated foreground masks.
The output masks are stored as png images.

5.
The code is currently not optimised for speed.


