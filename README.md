# imagemanipulation

This program uses openCV, C++, and python.

in the c++ file images from the sloth file is taken, read, and compressed one by one.  To optimize this I used multithreaded programming to run it all at the same time.

In the python file I rotate the compressed image using opencv then store it in another directory.  

Main.cpp connects to the python file using a socketed virtual environment, in my case jupyter.  Once the files are compressed and saved the file connects to the virtual environment where jupyter is set to run, the new rotated images are then populated in my rotate directory.  This part was new for me so hopefully it's correct, it does seem to populate for me though. 
