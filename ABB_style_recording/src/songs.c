/*
 * songs.c
 *
 *  Created on: Jan 21, 2015
 *      Author: Anton
 */
#include "main.h"

void songTask()
{

	if(joy2_channel7 == 1)
	{
		//SMB2 win
		speakerPlayRtttl("Win:d=4,o=5,b=140:f,f,16d,16p,f,16d,16p,8f,8d,16c,16p,2f,8d,8c6,8d6,8c6,8d6,8c.6,16c,16a#,16a,8g,2f,p,16f6,2p");
	}
	else if(joy2_channel7 == 2)
	{
		//mario GAME OVER
		speakerPlayRtttl("MGO:d=4,o=5,b=63:16c6,8p,16g,8p,16e,16p,9a,9b,9a,8g#,8a#,6g#,18g,18f,g,2p");
	}
	else if(joy2_channel7 == 3)
	{
		//SMB2 life loss
		speakerPlayRtttl("Fail:d=4,o=5,b=125:16d#6,16e6,16d#6,16e6,16c6,16g,16g#,16a,16d#,16e,16c,16g4,16g#4,16a4,16d#4,16e4,8c4,2p");
	}
	else if(joy2_channel7 == 4)
	{
		//level up
		speakerPlayRtttl("LU:d=4,o=5,b=140:16e,16e,16e,8b,2p");
	}
	else if(joy2_channel7 == 5)
	{
		//1812 overture
		speakerPlayRtttl("1812:d=4,o=5,b=200:8c,16g,16g,8c6,8d6,8e6,8d6,8c6,8d6,8e6,8p,8c6,8p,c.6,8g,8c,16g4,16g4,8c,8d,8e,8d,8c,8d,8e,8p,8c,8p,2c,8p,16a,16a,8d6,8e6,8d6,8a,8f,8a,8d6,8a,8f,8a,d.6,8g,8c,16g,16g,8c6,8d6,8c6,8g,8e,8g,8c6,8g,8e,8g,c.6,8p,1g4,2a4,2a4,2g.4,e4,1c4,1c5,2b4,2a4,1g4,2a.4,p,1f4,2g4,2g4,2e.4,e4,f4,f4,g4,a4,2g4,g.4,8g4,2g,2g4,8c6,16g,16g,8c6,8d6,8e6,8d6,8c6,8d6,8c6,16g,16g,8c6,8d6,8c6,8g,8e,8g,1c6,1c4,1p");
	}
	else if(joy2_channel7 == 6)
	{
		//EVOLVE
		speakerPlayRtttl("Evolve:d=4,o=5,b=500:8c,8d,8e,8f,8g,8g#,2a.,2f.,1c.,a#,a#,a#,g,g,a#,1a.,f6,1p,1p");
	}
	else if(joy2_channel7 == 7)
	{
		//PACMAN
		speakerPlayRtttl("Pacman:d=4,o=5,b=135:8f,8f,8f,16d,16c,8f,8f,8f,16d,16c,8f,8f,8f,16d,16c,16f,16f,16p,8d.,8p,32e6,16f.6,32e6,16f.6,32e6,16f.6,16d6,16c6,32e6,16f.6,32e6,16f.6,32e6,16f.6,16d6,16c6,8g#6,8g#6,8g6,16f6,16d6,16g#6,16g#6,16p,8c.7,p,16f,16p,16c,16p,p,16c4,16p,16d4,16p,16e4,16p,16f,16f6,16c6,16a,32f6,32c6,16p,8a,16f#,16f#6,16c#6,16a#,32f#6,32c#6,16p,8a#,16f,16f6,16c6,16a,32f6,32c6,16p,8a,16f#,16f#6,16c#6,16a#,32f#6,32c#6,16p,8a#,16f,16f6,16c6,16a,32f6,32c6,16p,8a,16f#,16f#6,16c#6,16a#,32f#6,32c#6,16p,8a#,16f,16f6,16c6,16a,32f6,32c6,16p,8a,32g#,32a,32a#,32p,32a#,32b,32c6,32p,32c#6,32d6,32d#6,32p,8e6,16f,16f6,16c6,16a,32f6,32c6,16p,8a,16f#,16f#6,16c#6,16a#,32f#6,32c#6,16p,8a#,16f,16f6,16c6,16a,32f6,32c6,16p,8a,16f#,16f#6,16c#6,16a#,32f#6,32c#6,16p,8a#,16f,16f6,16c6,16a,32f6,32c6,16p,8a,16f#,16f#6,16c#6,16a#,32f#6,32c#6,16p,8a#,16f,16f6,16c6,16a,32f6,32c6,16p,8a,32c7,32b6,32a#6,32p,32a6,32g#6,32g6,32p,32g6,32f#6,32f6,32p,16e6,16p,32e,16f.,32e,16f.,32e,16f.,16d,16c,16e.,16e,32p,8a#.,8p,32e,16f.,32e,16f.,32e,16f.,16d,16c,16e.,16e,32p,8g#.,8p,32e,16f.,32e,16f.,32e,16f.,16d,16c,16f#,8f#,8a,8a#,8c.6,8f6,8a#,8f,8g#.,g,16p,32e,16f.,32e,16f.,32e,16f.,16d,16c,16e.,16e,32p,8a#.,8p,32e,16f.,32e,16f.,32e,16f.,16d,16c,16e.,16e,32p,8g#.,8p,32e,16f.,32e,16f.,32e,16f.,16d,16c,16f#,8f#,8a,8a#,8c.6,8b,8g#,8f,8g#,16g,8f.,p,8g#,32g,16g#.,16g,16f,8g#,16g,16f,8g#,16g,16f,16f4,16p,16a4,16p,16c,16p,16d,16p,16d#,16p,16d,16p,16c,16p,16a4,16p,16a#4,16p,32g,16g#.,32g,16g#.,16g,16f,8g#,16g,16f,16g#,16g#,16p,8c.6,16a4,16p,16c,16p,16d,16p,16d#,16p,16d,16p,16c,16p,16a4,16p,16a#4,16p,32g,16g#.,32g,16g#.,16g,16f,8g#,16g,16f,8g#,16g,8f.,16a4,16p,16c,16p,16d,16p,16d#,16p,8p,16f,16f,16p,8g#,16g#,2p,8p,16g#,16g#,16p,8c.6,16c6,16p,2p,16f,16f,16p,8g#,16g#,2p,8p,16g#,16g#,16p,8c.6,16c6,16p,p,8p,16f4,16p,16g4,16p,16a4,16p,16a#4,16p,32g6,16g#.6,32g6,16g#.6,16g6,16f6,8g#6,16g6,16f6,8g#6,16g6,8f.6,16a4,16p,16c,16p,16d,16p,16d#,16p,16d,16p,16c,16p,16a4,16p,16a#4,16p,32g6,16g#.6,32g6,16g#.6,16g6,16f6,8g#6,16g6,16f6,16g#6,16g#6,16p,8c.7,16a4,16p,16c,16p,16d,16p,16d#,16p,16d,16p,16c,16p,16a4,16p,16a#4,16p,32g6,16g#.6,32g6,16g#.6,16g6,16f6,8g#6,16g6,16f6,8g#6,16g6,8f.6,16a4,16p,16c,16p,16d,16p,16d#,16p,8p,16f6,16f6,16p,8g#6,16g#6,2p,8p,16g#6,16g#6,16p,8c.7,16c7,16p,2p,16f6,16f6,16p,8g#6,16g#6,2p,8p,16g#6,16g#6,16p,8c.7,16c7,16p,2p,p,16f6,16p,16d6,16p,16c6,16p,16d6,16p,16d#6,16d6,16p,8c.6,8p,16f#6,16p,16d#6,16p,16c#6,16p,16d#6,16p,16e6,16d#6,16p,8c#.6,8p,16f6,16p,16d6,16p,16c6,16p,16d6,16p,16d#6,16d6,16p,8c.6,8p,16f#6,16p,16d#6,16p,16c#6,16p,16d#6,16p,16e6,16d#6,16p,8c#.6,8p,16f6,16e6,16p,8d.6,8p,16f#6,16f6,16p,8d#.6,8p,16f6,16e6,16p,8d.6,8p,16f#6,16f6,16p,8d#.6,8p,32a,16a#.,32a,16a#.,32a,16a#.,16g,16f,16a#,16a#,16p,8d.6,8p,32a,16a#.,32a,16a#.,32a,16a#.,16g,16f,16a#,16a#,16p,8g.,8p,32a,16a#.,32a,16a#.,32a,16a#.,16g,16f,16a#,16a#,16p,8c#6,8d#6,8f.6,8d#6,8c#6,8a#,8c#6,16c6,8a#.,8p,8a#,8a#,8a#,16g#,16f#,16a#,16a#,16p,8d.6,8p,8a#,8a#,8a#,16g#,16f#,16a#,16a#,16p,8f.,8p,32a,16a#.,32a,16a#.,32a,16a#.,16g#,16f#,16a#,16a#,16p,8d6,8d#6,32f#6,8g6,32p,8d6,8c6,8a#,16a,8a#,8c.6,8p,16a#,8c6,8c#.6,8p,16c6,8c#6,8d#.6,8p,16d#6,8f6,1f#6,2p,24d4,24d#4,24e,16f6,16p,16d6,16p,16c6,16p,16d6,16p,16d#6,16d6,16p,8c.6,8p,16f#6,16p,16d#6,16p,16c#6,16p,16d#6,16p,16e6,16d#6,16p,8c#.6,8p,16f6,16p,16d6,16p,16c6,16p,16d6,16p,16d#6,16d6,16p,8c.6,8p,16f#6,16p,16d#6,16p,16c#6,16p,16d#6,16p,16e6,16d#6,16p,8c#.6,8p,16f6,16e6,16p,8d.6,8p,16f#6,16f6,16p,8d#.6,8p,16g6,16f#6,16p,8e.6,8p,16g#6,16g6,16p,8f.6,8p,8f6,16c6,16b,16a#,16f#,16f,16e,16p,8g#.,16a,16p,16f4,16p,2p");
	}
	else if(joy2_channel7 == 8)
	{
		//Meta knights revenge
		speakerPlayRtttl("Meta:d=4,o=5,b=160:8e,8e,8g,8g,a,16c6,16g,16a,8d#6,16p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e,d,16a,8c6,8c6,16c6,8d6,8e6,8g6,16e6,16d6,8c6,16g,16g#,16p,16a,16p,16d#,2d,8p,a,16c6,16g,16a,16d#6,8p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e,d,8a,8d6,16d#6,16e6,16p,16d6,16p,16c6,16p,16a,16p,16g,16e,16d#,2d.,p,b4,b,6f#,6g,6a,e,g,d,a4,b4,b,6f#,6g,6a,2e6,2a,6d#,6a,6d#,6d,6g#,6d,6g,6f,6c,6d#,6g,6c6,16d#,16f,g.,p,g#,16a#,16f,16f,16f,16f,16p,16f,16f,16f,16f,16f,16p,p,8a6,16a,16p,16g,16a,16p,16a,16p,16a,16p,16g,16a,16c6,16d6,16d#6,8p,16d6,16p,16a,16g,16p,16d#6,16p,16d6,16p,16c6,16a,16g,16a4,16g4,8a4,16a6,16p,16g6,16a6,16d#6,16d6,16c6,16d6,16p,16e6,16p,16a,16g,16g#,16a,16f#,16p,16e,16p,16d,8c,16e,16a,16b,8c6,16d#6,16g6,16a6,8a#6,16a#,16p,16g#,16a#,16p,16a#,16p,16a#,16p,16g#,16a#,16c#6,16d#6,16e6,8p,16d#6,16p,16a#,16g#,16p,16e6,16p,16d#6,16p,16c#6,16a#,16g#,16a#4,16g#4,8a#4,16a#6,16p,16g#6,16a#6,16f6,16d#6,16c#6,16d#6,16p,16f6,16p,16a#,16g#,16a,16a#,16g,16p,16f,16p,16d#,8c#,16a#,16c#6,16d#6,8e6,16f6,16g6,16a#6,8a6,16a,16p,16g,16a,16p,16a,16p,16a,16p,16g,16a,16c6,16d6,16d#6,8p,16d6,16p,16a,8g,16d#6,16p,16d6,16p,16c6,16a,16g,16a4,16c,8a,16a6,16p,16g6,16a6,16d#6,16d6,16c6,16d6,16p,16e6,16p,16a,16g,16g#,16a,16f#,16p,16e,16p,16d,8c,16e,16a,16b,8c6,16d#6,16g6,16a6,16a#6,16p,16a#,16p,16g#,16a#,16p,16a#,16p,16a#,16p,16g#,16a#,16c#6,16d#6,16e6,8p,16d#6,16p,16a#,8g#,16e6,16p,16d#6,16p,16c#6,16a#,16g#,16a#4,16g#4,8a#4,16a#,16p,16g#,16a#,16f,16d#,16c#,16d#,16p,16f,16p,16a#,16g#,16a,16a#,16g,16p,16f,16p,16d#,8c#,16a#4,16c#,16d#,8e,16f,16g,16a#,c,c6,6g,6g#,6a#,f,g#,d#,a#4,c,c6,6g,6g#,6a#,2f6,a#.,8p,6e,6a#,6e,6d#,6a,6d#,6g#,6f#,6c#,6e,6g#,6c#6,16e,16f#,g#.,p,a,16b,16f#,16f#,16f#,16p,16f#,8f#,8e6,8e6,8g6,8g6,16a6,8p,2a.,8p,8a.,2a,8p,16p,16a#,16b,8c.6,2c6,8p,16p,16d6,16d#6,8e.6,2e6,8p,16p,16g6,16p,8a6,16a,16p,16c6,16p,16a,16d#6,8p,16d6,16p,16c6,16a,16g,16p,16a,16c6,16p,16c6,16p,16a,16d6,16p,2p,16c6,16d#6,16p,16d#6,16p,16d#6,16f6,16p,16g6,16p,16a#6,16p,16g6,16f6,16d#6,16p,16d6,16e6,16p,16g#6,16p,16a6,2b6,p,8e6,16c6,16d6,16p,16e6,16a4,16p,16a4,16p,8c,16a4,16p,8p,16e6,16p,16c6,16d6,16p,16e6,8p,16d#,16p,16d,16c,16a4,16p,8p,16g,16p,16c6,16d#6,16p,16g6,16c,16p,16c,16p,8d#,16c,16p,8p,16g6,16p,16d#6,16f6,16p,16g6,8p,8g.,8g.,16a6,16p,16e6,16p,16c6,16d6,16p,16e6,16a4,16p,16a4,16p,8c,16a4,16p,8p,16e6,16p,16c6,16d6,16p,16e6,8p,8d#,16d,16c,16a4,16p,8p,8g,16c6,16d#6,16p,16g6,16c,16p,16c,16p,8d#,16c,16p,8p,16d#6,16p,16f6,8g6,8f6,16d#6,16g6,16f6,16d#6,16d6,16c6,16p,8p,16c6,16p,16c6,16d6,16p,8d#.6,16c6,16p,16a#,16c6,p,8g,16c6,16d#6,16p,8g.6,16d#6,16p,16d6,16d#6,p,16g#,16p,16b,16d#6,16p,8b.,16g#,16p,16f#,16g#,p,16g#,16p,16b,16d#6,16p,8f#.6,8d#6,16c#6,16d#6,16c#6,16b,16a#,g#,16p,16f#,16g#,6a#,6d#6,6a#,6c6,6f6,6c6,6e6,6f6,6g6,6f6,6d6,6f6,6g#6,6a6,6b6,c.6,16b,16c6,6d6,6b,6d6,8c.6,16b,2a.,c.6,16b,16c6,6d6,6b,6d6,2d#.6,p,c.6,16a#,16g#,8g,8f,8d#,8f,g,8f.,16g,c,8c.,16c,2d.,8d.,16d#,2d.,12c,12d#,12g,c.6,16a#,16g#,8g,8f,8d#,8f,g,8f.,16g,c,c,2d.,d,2d.,8d.,16d#,d.,8d#,d.,8d#,16d,16d#,16d,16d#,16d,16d#,16d,16d#,8e,8e,8g,8g,a,16c6,16g,16a,8d#6,16p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e,d,16a,8c6,8c6,16c6,8d6,8e6,8g6,16e6,16d6,8c6,16g,16g#,16p,16a,16p,16d#,2d,8p,a,16c6,16g,16a,16d#6,8p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e,d,8a,8d6,16d#6,16e6,16p,16d6,16p,16c6,16p,16a,16p,16g,16e,16d#,2d.,p,b4,b,6f#,6g,6a,e,g,d,a4,b4,b,6f#,6g,6a,2e6,2a,6d#,6a,6d#,6d,6g#,6d,6g,6f,6c,6d#,6g,6c6,16d#,16f,g.,p,g#,16a#,16f,16f,166,16f,16p,16f6,16f6,16f6,8e6,8e6,8g6,8g6,16a6,8p,16a6,16p,16a6,16g6,16g#6,8a6,8p,8a4,8p,2p");
	}
	else if(joy2_channel7 == 9)
	{
		//CRAZY frog
		speakerPlayRtttl("CrazyFrog:d=4,o=5,b=140:16d,8p,16p,16f,8p,16d,16p,16d,16g,16p,16d,16p,16c,16p,16d,8p,16p,16a,8p,16d,16p,16d,16a#,16p,16a,16p,16f,16p,16d,16p,16a,16p,16d6,16p,16d,16c,16p,16c,16a4,16p,8e,d.,p,8d6,8p,8d6,8p,16d,16d4,16d,16p,16f,16d,16f,16d,16p,16d,16g,16p,16d,32f,32d,16c,32f,32e,16d,16e,16f,16g,16a,16f,16e,16d,16d4,16d,16a#,16g,16a,16e,16f,16e,16d,16a4,16a,16f,16d6,16f,16d,16c,16p,16c,16a,16f,8e,d.,p,8d6,64c#6,64c6,64b,64a#,64a,64p,32p,8d6,64c#6,64c6,64b,64a#,64a,64p,32p,16d,16d4,16d,16p,16f,16d,16f,16d,16p,16d,16g,16p,16d,32f,32d,16c,32f,32e,16d,16e,16f,16g,16a,16f,16e,16d,16d4,16d,16a#,16g,16a,16e,16f,16e,16d,16a4,16a,16f,16d6,16f,16d,16c,16p,16c,16a,16f,8e,d.,p,8d6,64c#6,64c6,64b,64a#,64a,64p,32p,8d6,64c#6,64c6,64b,64a#,64a,64p,32p,16d,16p,16f,16d,16f,16d,16p,16d,16g,16p,16d,32f,32d,16c,32f,32e,16d,16e,16f,16g,16a,16f,16e,16d,16d4,16d,16a#,16g,16a,16e,16f,16e,16d,16a4,16a,16f,16d6,16f,16d,16c,16p,16c,16a,16f,8e,8a6,8a6,8f6,8e6,8d,8d6,64c#,64c,64b,64a#,64a,64g#,64g,64f#,p,8d6,16d6,16p,16c#6,16p,16c6,16p,b,8b.,16p,8d6,16d6,16p,16c#6,16p,16c6,16p,8b,8b,8b,16p,64p,64b,64c6,64c#6,8d6,16d6,16p,16c#6,16p,16c6,16p,b,8b.,16p,8d6,16d6,16p,16c#6,16p,16c6,16p,32c.,128a#4,128g#4,8g.4,32c.,128a#4,128g#4,8g.4,8d6,16d6,16p,16c#6,16p,16c6,16p,b,8b.,16p,8d6,16d6,16p,16c#6,16p,16c6,16p,8b,8b,8b,16p,64p,64b,64c6,64c#6,8d6,16d6,16p,16c#6,16p,16c6,16p,b,8b,8a6,8a6,8f6,8e6,8d,2d6,16d,8p,16p,16f,8p,16d,16p,16d,16g,16p,16d,16p,16c,16p,16d,8p,16p,16a,8p,16d,16p,16d,16a#,16p,16a,16p,16f,16p,16d,16p,16a,16p,16d6,16p,16d,16c,16p,16c,16a4,16p,8e,d.,p,8d6,64c#6,64c6,64b,64a#,64a,64p,32p,8d6,64c#6,64c6,64b,64a#,64a,64p,32p,16d4,16p,8p,1p");
	}
	else if(joy2_channel7 == 10)
	{
		//DeDeDe's theme
		speakerPlayRtttl("DDD:d=4,o=5,b=180:16d#,16e,16f,16f#,16g,16g#,16a,16a#,16b,16c6,16c#6,16d6,16d#6,16e6,16f6,16f#6,8a#6,g6,8a#6,g6,8a#6,g6,8p,p,2p,d#6,c6,8p,8a#,8c6,d#6,c.6,8p,8f6,g6,16d#6,16d6,c6,p,8g,8d#6,c6,8a#,c6,8a#,c6,8a#,8f6,d#.6,8p,8f6,d#6,8c6,d#6,8c6,8d#6,8f6,8f#6,8g6,8a#6,8g6,2p,8a#6,8g6,2p,8a#6,g.6,d#6,c6,8p,8a#,8c6,d#6,c.6,8p,8f6,g6,16d#6,16d6,c6,p,8g,8d#6,c6,8a#,c6,8a#,c6,8a#,8f6,d#.6,8p,8f6,d#6,8c6,d#6,8c6,8d#6,8f6,8f#6,8g6,8a#6,g.6,p,8a#6,g.6,p,8a#6,g6,16p,16a#,8c6,8c6,8c6,8d6,8d#6,8d#6,8d6,8c6,8a#,c6,g.,p,8c6,8c6,8c6,8d6,8d#6,8d#6,8f6,8d#6,8f6,g6,2g6,16d#6,16d6,8c6,8c6,8c6,8d6,8d#6,8d#6,8d6,8c6,8a#,c6,2g,16g,16a#,8c6,8c6,8c6,8d6,8c6,8c6,8a#,8g,8f,g,2c,8p,d.,16c,16d,8a#.4,8a.,8f,8d#.,16f,2g,8p,16c,16c#,d.,16c,16d,8a#.4,8a.,8f,2c6,8p,8e.,8g.,c.6,16a#,16g#,8g.,8f.,8g,a#.,16g#,16g,8f.,8d#,8f.,8d.,16g,2g.,b.,g,b.,8d#6,8c6,8p,c6,g,16d#,16d,8c,8c,8a#4,8c,2p");
	}
	else if(joy2_channel7 == 11)
	{
		//GERUDo ValLey
		speakerPlayRtttl("Gerudo:d=4,o=5,b=125:16c4,16g4,16a#4,8c#,8f,8g#,16e,16g,16a#,c6,16c,16c,16c,8c,8c,16c,16c,16c,16c,8c,8p,16p,16f,16f,16c,16f,16p,16f,16p,16c,16f,16f,16c,16f,16p,16f,16p,16c,16f,16f,16c#,16f,16p,16f,16p,16c#,16f,16c#,16d#,16f,16p,16f,16p,16g#,16g,16d#,16d#,16g,16p,16a#,16p,16g#,16g,16d#,16d#,16g,16p,16g,16g,16g,16f,16f,16c,16f,16p,16c,16f,2e,16p,16f,16p,16c,16f,16p,16c,16f,16g,g#,d#,8c#,16f,16p,16f,16p,16c#,16f,16p,16c#,8f,16c#,16f,16c#,16f,16d#,16d#,16g,16p,16a#,16p,16g#,16g,16d#,16d#,16g,16p,8a#4,8d#,8g#.,8g#,16g#,16g#,16g#,2g,16p,16c,16f,16g,8g#.,16c,16f,16g,g#,8p,16p,16c#,16f,16g,8g#.,16c#,16f,16p,16g,g#,8p,16a#4,16d#,16f,8g.,16a#4,16d#,16f,g.,16p,16f,16g,16f,e,16e,16e,16e,16e,32e,32e,32e,32e,32e,32e,32e,32e,16p,16c,16f,16g,8g#.,16c,16f,16g,g#.,16p,16c#,16f,16g,8g#.,16c#,16f,16c#,16g,c6,8p,16a#4,16d#,16f,8g.,16a#4,16d#,16f,a#.,16p,16g#,16a#,16g#,g,16g,16g,16g,16g,32g,32g,32g,32g,32g,32g,32g,32g,8p,16a#4,8c,16g,8g#,32g,32g#,8g,8f.,8c,d#,16d#,16f,16d#,2c#,16p,8p,16g#4,8a#4,8g.,8f.,8d#.,8c#,c,16c#,16d#,16c#,2c,16p,8p,16a#4,8c,16g,8g#,32g,32g#,8g,8f.,8c,d#,16d#,16f,16d#,c#.,16p,8a#4,a#.4,16d#,16f,d#.,8c#,c.,16c,16c,2c,8p,16f4,16g4,16g#4,16c,8p,16f4,16g4,16g#4,8c.,p,16f4,16g4,16g#4,16c#,8p,16f4,16g4,16g#4,8c#.,8p,a#.4,16f,16g,f.,8a#4,2c,2e4,8f,16g#,8g.,8g#,8f,16g#,8g.,8g#,8c#,16g#,16f,8g,8g#,8c#,16g#,16f,8g,8g#,8d#,16a#,8a.,8a#,8d#,16a#,8a.,8a#,8p,16c#6,16d#6,16c#6,2c6,8p,16p,16f,16f,16c,16f,16p,16f,16p,16c,16f,16f,16c,16f,16p,16f,16p,16c,16f,16f,16c#,16f,16p,16f,16p,16c#,16f,16c#,16d#,16f,16p,16f,16p,16g#,16g,16d#,16d#,16g,16p,16a#,16p,16g#,16g,16d#,16d#,16g,p,16f,16f,16c,16f,16p,16c,16f,2e,p,16p,16c,16f,16g,32g#,32a#,8g#.,8g,8f,p,16p,16c#,16f,16g,32g#,32a#,8g#.,8g,8f,p,16p,16a#4,16d#,16f,8g,8g#,8a#,c.6,32c6,32c#6,16c6,16a#,16g#,16g,16e,16f,16g,16g#,16a#,16c6,16c#6,16p,16c,16f,16g,8g#,16c,16f,16g,16g#,16a#,16c6,32f6,32g6,16f6,16a#,16g#,16p,16c#,16f,16g,8g#,16c#,16f,32g,32g#,16g,16a#,16c6,16f6,16c6,16a#,16g#,16p,16a#,16d#,16f,32g,32g#,16g,16a#,16d#,16f,16g,16g#,16a#,16c6,16a#,16g#,16g,16g#,16c,16d,16e,32f,32g,16f,16a#,16g#,16g,16e,16f,16g,16g#,16a#,16c6,16c#6,16p,16c,16f,16g,8g#.,16c,16f,16g,g#.,16p,16c#,16f,16g,8g#.,16c#,16f,16p,16g,g#,8p,16a#4,16d#,16f,8g.,16a#4,16d#,16f,g.,16p,16f,16g,16f,e,16e,16e,16e,16e,32e,32e,32e,32e,32e,32e,32e,32e,16p,16c,16f,16g,8g#.,16c,16f,16g,g#.,16p,16c#,16f,16g,8g#.,16c#,16f,16c#,16g,c6,8p,16a#4,16d#,16f,8g.,16a#4,16d#,16f,a#.,16p,16g#,16a#,16g#,g,16g,16g,16g,16g,32g,32g,32g,32g,32g,32g,32g,32g,8p,16f,16g,16g#,16c6,8p,16f,16g,16g#,8c.6,p,16f,16g,16g#,16c#6,8p,16f,16g,16g#,8c#.6,8p,a#.,16f6,16g6,f.6,8a#,2c.6,e,2f.,32g#,32a#,8g.,2g#.,c6,1a#,8p,16c#6,16d#6,16c#6,8c.6,16c6,16c6,16c6,32g,32c6,32g,32e,32g,32c6,32g,32e,32g,16c6,1f6,1p");
	}
	else if(joy2_channel7 == 12)
	{
		//
		speakerPlayRtttl("");
	}

}
