### Tasks to work on:

- Define a class Figure with members x, y, color. Protect these members from beeing accessed by others, except derived classes.
- Use Figure as a base class for classes Circle (having a radius r) and Square (having its side length a)
- Define constructors for these three classes. Constructors for Circle and Square should accept four parameters: three to be passed to the base class and one used for Circle of Square.
- Implement a function Draw drawing the shape in all classes (the version for Figure may do nothing); if you want, use Allegro for graphics or just print a message on the screen ("drawing circle...")
- Create some objects of classes Square and Circle and call the method Draw for them.
- Use pointers to Figure to store pointers to created objects of the type Circle and Square.
- Call Draw using pointers.