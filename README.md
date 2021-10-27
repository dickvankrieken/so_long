# So_Long
This is a game that I made for my studies at Codam Coding College (42 education network). <br />
It involves a player that collects some coins and then exits the map.<br />
I coded a map parser that transforms this kind of map:<br />

<pre><code>111111111
1000C0001
1C1010101
1110000C1
1C001C101
11PE100C1
111111111
</code></pre>

into this:<br />

<img src="/image.png" width="400">

For the graphics I have used a graphical library that was build and provided by my school which is called MinilibX.<br />
MinilibX utilizes the X Window System to render a window in which graphical output can be displayed. 

## What I have learned in this project
* How to use a graphical library
* Writing a map parser that analyzes a given file, checks if the file is valid, and transforms the file's data to a graphical game
* Making X11 Event Handlers (e.g. key presses) so that the program reacts to user input (e.g. W, A, S, D for the player to move around)