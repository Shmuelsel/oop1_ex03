Student details
Shmuel Seltzer ID 207861535

General explanation of the exercise
The exercise involves working with an image data structure, where each pixel in the image is represented by a Pixel object. Each image represents a two-dimensional structure of pixels, with support for a variety of advanced operations such as comparison, addition, Boolean operations, and more. The image is represented by the Image class, which is based on the ImageDataStructure class.

The code also includes support for generic image data structures (such as addition of images, operations on pixels, and multiplication by scalar), and also performing advanced operations on pixels, including Boolean operations such as |, &, and color inversion (using the ~ operator).

List of files
1. Pixel.cpp – Implementation of the Pixel class that describes a pixel in an image, including support for equality, Boolean operations, and printing to the screen.
Represents a pixel in an image. Each pixel is represented by a single color (in the format of a single character). Boolean operations on pixels (such as |, &), and equality between pixels are implemented.

2. ImageDataStructure.cpp – Implementation of the ImageDataStructure class that represents the image as a two-dimensional array of pixels.
Represents the image as a two-dimensional array of pixels. Allows managing images of a given size, performing calculations on images, and printing the image to the screen.

3. Image.cpp – Implementation of the Image class, which represents the image as a file based on ImageDataStructure.
Represents a high-level image, and includes all the functions for working with images, such as combining images, pixel operations, and comparing images.

Notable algorithms
Pixel equality (operator==): Checks if the two pixels have the same color.

Image concatenation (operator+): Combines two images to create a new image, unifying their dimensions.

Boolean operations on pixels (operator|, operator&): Performs operations on pixel colors in a Boolean manner, such as adding or cutting between colors.

Assignment operator – implementing the operator using the swap function so that there is no problem with memory allocations.

Color reversal (operator~): reverses the colors in the image (black to white, white to black).
High School (Design)

The functions interact between the objects in a smart way, so that each object clearly realizes its responsibilities.

Known bugs - No critical problems have been found in the code as of this date.
Other comments - None