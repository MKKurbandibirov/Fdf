<h1 align="center">
🎨FdF
</h1>

## 💡 About the project:

> _This project is dedicated to representing the landscape as a three-dimensional object
in which all surfaces are outlined with lines._

	 It's time to create a basic computer graphics project!
	 You will be using the school's graphics library: MiniLibX!
	 This library was developed within the school and includes the basic necessary
	 tools to open windows, create images and work with keyboard
	 and mouse events.
	 This will be an opportunity for you to get acquainted with MiniLibX, to discover the basics of
	 graphics programming, in particular how to place points in space,
	 connect them and, most importantly, how to see a scene from a certain point of view.

More details about the project and the nuances can be found at  [**subject**](https://github.com/MKKurbandibirov/Fdf/blob/main/Subject.pdf).

## 🛠 Testing and usage:

    # !!! This project runs under LINUX !!!
	
	  # Clone the project and access the folder
	  git clone git@github.com:AYglazk0v/fdf.git && cd fdf/

	  # To build a project for Linux:
	  make
	
	  # To run the program, you need to give one of the cards located in the 
	  # test_maps directory, or create your own according to the rules specified in the subject.
	  
	  # Example team:
	  ./fdf test_maps/42.fdf
	
	  # You can clear the output files with
	  make fclean

### Managing:

| KEY           | Action        |
| ------------- |:-------------:|
| `ESC`         | Exit the program     |
| `SPACE BAR/TAB`| Change the gradient on the image       |
| `W/S`           | Rotation along the ОХ     |
| `Q/E`           | Rotation along the OY |
| `A/D`           | Rotation along the OZ  |
| `I`           | Use isometry |
| `P`           | Use perspective| 
| `←` `→` `↑` `↓`| Offset of the image in the appropriate direction|
|`+` `-`| Change of scale|
|`z` `x` | Changing the coefficient to illustrate height|

## 🎬 Demonstration(example):
[The image jerks only in animation (due to the limited number of frames per second)]
![Fdf](https://github.com/AYglazk0v/fdf/blob/master/additionally/fdf.gif)
