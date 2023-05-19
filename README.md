# TestProject
<h3>Team Members:</h3>
<table>
  <tr>
<th>Name</th>
<th>BN</th>
  </tr>
    <tr>
<th>Mariam Medhat Mahnoud</th>
<th>48</th>
  </tr>
      <tr>
<th>Yomna Waleed Tawfeek</th>
<th>54</th>
  </tr>
<tr>
<th>Reem Mahmoud Saleh</th>
<th>21</th>
  </tr>
<tr>
<th>Mohamed Hosney Hegazy</th>
<th>35</th>
  </tr>
</table>

<h2>Obstacles Game</h2>
The game consists of enemies and a car which escape from the 
falling enemies by moving left and right. The user controls that 
car by two external switches that take control over the car by 
moving it across the x-axis of the screen. The player has three 
lives before the displaying of the game over screen. Each time 
the player escapes the enemy his score increases ; and each 
time the enemy hits the player he loses one of his lives.

<h3>Project description:</h3>
The project contains two drivers. The GPIO driver and the timer 
driver. The code contains raceGame file which includes functions 
of the game.


<h3>GPIO:</h3>
PORTB (PIN1,PIN2,PIN3) is used for the LEDs that represent the 
three lives if the player . PORTF(PIN0,PIN4) for enabling the two 
switches that control the player on the screen. 
<h3>Timer:</h3>
The game consists of three timers ( Timer0, Timer1, Timer2 ).
They are responsible for the movement of the three enemies 
across the y-axis of the screen. Each timer is responsible for the 
movement of one enemy.
<h3>Functions:</h3>
<h4>Start</h4>
Display the screen of the welcome window.
<h4>game_init</h4>
the main function that initialize the nokia LCD and calls portf, 
portb, and timer initializations
<h4>Control_Enemy</h4> 
This function checks the y-coordinate of the enemy if he 
reached the end of the screen it gives it a random value for x 
and y will be zero again. 
<h4>Check_en</h4>
The function the checks if the enemy hits the player.
<h4>Reset</h4>
Each time the enemy hits the player the reset function returns 
the player to the center of the screen x=32 and the enemy to 
the beginning of the screen y=0 with new random value for x.
<h4>Lifes</h4>
It controls the lives of the player on the LEDs.
<h4>Gameover</h4>
The function that displays the game over screen and the score 
of the player.
