﻿# Capstone_Custom_Library
+---------+----------------+------------------------------------------+
| **void  |                | A function that controls the position of |
| move    |                | the tray. Takes in a position argument   |
| (int    |                | and moves the tray according to the      |
| targ    |                | position. Every time the tray hits the   |
| et_pos, |                | limit switch, that position will be      |
| int     |                | reset to the new neutral position.       |
| spd)**  |                | Outputs no argument                      |
+=========+================+==========================================+
| **      | target_pos     | The targeted position of the tray in mm, |
| Input** | (int)          | with a neutral position at value 0. The  |
|         |                | tray will move to this value's position. |
|         |                | The value ranges from 0-335.             |
+---------+----------------+------------------------------------------+
|         | spd (int)      | This argument controls the speed of the  |
|         |                | tray moving. No exact range of this      |
|         | Default value: | value but a default value of 500 is a    |
|         | 500            | good value to start with. [TAKE NOTE:    |
|         |                | Even though it says speed, but it is     |
|         |                | actually a delay variable.               |
|         |                | Counterintuitively, in short, the        |
|         |                | **higher** the value, the **slower** the |
|         |                | tray.]{.mark}                            |
+---------+----------------+------------------------------------------+
| **O     | current_pos    | Returns the updated position of the      |
| utput** | (int)          | tray.                                    |
+---------+----------------+------------------------------------------+

+---------+----------------+------------------------------------------+
| **void  |                | A function that resets the position of   |
| res     |                | the tray. This function moves the tray   |
| etFront |                | to the **front** and stops.              |
| (int    |                |                                          |
| spd)**  |                |                                          |
+=========+================+==========================================+
| **      | spd (int)      | This argument controls the speed of the  |
| Input** |                | tray moving. No exact range of this      |
|         | Default value: | value but a default value of 500 is a    |
|         | 500            | good value to start with. [TAKE NOTE:    |
|         |                | Even though it says speed, but it is     |
|         |                | actually a delay variable.               |
|         |                | Counterintuitively, in short, the        |
|         |                | **higher** the value, the **slower** the |
|         |                | tray]{.mark}                             |
+---------+----------------+------------------------------------------+
| **O     | current_pos    | Returns the updated position of the tray |
| utput** | (int)          |                                          |
+---------+----------------+------------------------------------------+

+---------+----------------+------------------------------------------+
| **void  |                | A function that resets the position of   |
| re      |                | the tray. This function moves the tray   |
| setBack |                | to the **back** and stops.               |
| (int    |                |                                          |
| spd)**  |                |                                          |
+=========+================+==========================================+
| **      | spd (int)      | This argument controls the speed of the  |
| Input** |                | tray moving. No exact range of this      |
|         | Default value: | value but a default value of 500 is a    |
|         | 500            | good value to start. [TAKE NOTE: Even    |
|         |                | though it says speed, but it is actually |
|         |                | a delay variable. Counterintuitively, in |
|         |                | short, the **higher** the value, the     |
|         |                | **slower** the tray]{.mark}              |
+---------+----------------+------------------------------------------+
| **O     | current_pos    | Returns the updated position of the tray |
| utput** | (int)          |                                          |
+---------+----------------+------------------------------------------+

  ---------------------------------------------------------------------------
  **float\*                        A function that cycles through each port
  readLuxs()**                     of the multiplexer, reads the light sensor
                                   values connected to individual ports and
                                   stores them inside an array. Outputs the
                                   pointer address of the array.
  -------------- ----------------- ------------------------------------------
  **Input**      \-                \-

  **Output**     array (float\*)   a pointer to an array of size 9, that
                                   contains the lux readings of the 9 light
                                   sensors
  ---------------------------------------------------------------------------
