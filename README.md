# Chinese Chess 
Also known as xiangqi. Objective of the game is to capture the general. Further rules can be found
at [wiki](https://en.wikipedia.org/wiki/Xiangqi#Rules).

<p align="center">
	<img src="/graphics/examples/one.png" width="500" height="500" />
</p>

# Installation

Requirements: SFML graphics libary, more info here: [sfml download](https://www.sfml-dev.org/download.php)

1. Download or clone repo (and extract if needed)

	```
	git clone https://github.com/dchenmei/chinese-chess.git
	```

2. Enter root directory

	```
	cd chinese-chess
	```

3. Compile (optional, requires g++ compiler and c++ libraries)

	```
	make
	````

	or

	```
	make main
	```

4. Run

	```
	./main
	```
5. Enjoy!

# Gameplay 

Click on a piece to select then click on a spot to move it there. Red goes first!

<p align="center">
	<img src="/graphics/examples/two.gif" width="500" height="500" />
</p>

-- Few things to keep in mind
> selecting a piece is best done with mouse pointing at right bottom of the piece
> perpetual plays should be called by the player or judge as in the original!
> check should also be called by the player, in this version you can accidetally kill your general!!

# Contribution

The game is perfect for casual play but not very feature rich. Bugs can be located in the `bugs.md` file, any help or suggestions are welcome.

# Credits:

<b> Graphics Support </b>  
[SFML Library](https://www.sfml-dev.org/index.php)


<b> Chess Piece PNGs </b>  
By The original uploader was Mcy jerry at English Wikipedia.Later versions were uploaded by Michele Bini at en.wikipedia. - Transferred from en.wikipedia to Commons., CC BY-SA 3.0, https://commons.wikimedia.org/w/index.php?curid=1817343
