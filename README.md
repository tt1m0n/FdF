# FdF

This project is about creating a simplified graphic “wireframe” (“fils de fer” in french, hence the name of the project) representation of a relief landscape linking various points (x, y, z) via segments. The coordinates of this landscape are stored in a file passed as a parameter to your program. Here is an example:

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0 

0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0

0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0

0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0

0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0

0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0

0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0


Each number corresponds to a point in space:

• The horizontal position corresponds to its axis. 

• The vertical position corresponds to its ordinate. 

• The value corresponds to its altitude.

Remember to make optimum use of your libft! The use of get_next_line, ft_split and ft_getnbr will allow you to quickly and simply read data from the file.
Regarding the graphic representation:
• You can choose the type of projection: parallel, iso, conic.

• You must be able to quit the program by pressing ’esc’.

• The use of images from minilibX is strongly encouraged.

