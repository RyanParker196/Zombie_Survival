# FinalProject-DARKWHITE
##Audio:
For audio to be working the user requires an updated version of python stored in %PATH% and must move the audio.py and
Thriller.mp3 into cmake-build-debug or whatever the main.exe is run.  If it cant run the game should work fine without it.

system("python audio.py"); needs to be added to the init function if not already included.
# Description
The Zombie Survival is an arcade game, the gist of this game is to survive the
attacks of zombies. The man has a gun and whenever he kills 1 zombies, another
appears on the screen, if he killed 10 zombies within 4 seconds, 10 zombies 
appear on the scrren for attack. The zombies chase the man and when they make 
contact, the man's health begins to drop. Health begin at 300. Yet you can have more
than 300 health. After every 10 seconds, a health pack drops on the road
and the man has to somehow get to it to grab it. 


# Keys To Play
Controls used to play this game is very simple, a player will have to use the 
up, down, letf and right arrow keys to control the man with the gun. the key 
f will be used to fire the gun and g to explode a grenade

| Key / Button | Effect                    |
|--------------|---------------------------|
| Up arrow     | Move man up               |
| Down arrow   | Move man down             |
| f            | Fire Gun                  |
| g            | Throw/Fire Grenade        |
| s            | Pause the game            |


# Three Screens
This game comprises of three main screen, but there are quite some other screen
that helps the user. The main screens include the start screen which has 3 buttons;
Play, Results and Instructions. 
The second screen, is the game screen. This screen holds a city which is a road,
and some houses, a man with a gun and zombies chasing him.
The last screen, the end screen which is known as the Result screen, provides 
some information from the game, such as the number of zombies killed, and the 
number of zombies that were on the screen. It also includes a button that allows
the user to play the game again if interested.

# Polymorphism
Polymorphism was introduced in the drawing of the man and the zombies, these
characters consist of Rect and circle class, which are stored in a vector of shape
pointers. Polymorphism is then used to draw all the shapes using a for loop being able
to call the appropriate draw method depending on the class of the shape.

# Group Members
* Nana Nimako
 * Harry Makovsky
 * Tyler Ehrlich
 *Ryan Parker