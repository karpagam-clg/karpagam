# TEAM - 10

## PROBLEM

The game is a bomb-avoidance challenge played on an `N × N` matrix. The player must select safe boxes while avoiding randomly placed bombs.

- Each level contains an `N × N` matrix with randomly positioned bombs.
- Each player starts with **3 lives**.
- Every level has a predefined **maximum score** that the player must achieve to progress.
- The player selects a box by entering its **position number**.
- If the selected box is safe, the player's **level score increases**.
- If the selected box contains a bomb:
  - The player's life decreases by **1**.
  - The current level restarts.
  - The **level score resets to 0**.
- When the player reaches the maximum score of the current level, the game moves to the **next level**.
- A **top score** is maintained to track the player's highest overall score/progress across levels.

## APPROACH

- **Level and Matrix Display**
  - Display the current level and its corresponding `N × N` matrix to the player.
  - Each level has a predefined maximum score.
  - The player starts the game with **3 lives**.

- **Random Bomb Allocation**
  - Use a random function to place bombs in different positions of the `N × N` matrix.
  - Bomb locations are generated for the game/level and stored in the backend.
  - The actual bomb locations are hidden from the player.

- **Position Selection**
  - The player provides a single number representing the selected box position.
  - Convert the position into matrix coordinates using:
    - `row = position / N`
    - `column = position % N`
  - This allows one integer to represent a specific box in the matrix.

- **Dual Matrix Management**
  - Maintain two matrices:
    - **Actual Matrix:** Stored internally in the backend and contains the true state of every box, including bomb locations.
    - **Player Matrix:** Displayed to the player and updated based on the player's selections and game status.
  - The actual matrix is used to verify whether a selected position is safe or contains a bomb.

- **Safe Box Selection**
  - If the player selects a safe box:
    - Mark the selected position as safe/visited in the player matrix.
    - Increase the **level score**.
    - Continue the game at the same level.
  - The player continues selecting boxes until the maximum score is reached or a bomb is selected.

- **Bomb Selection and Life System**
  - If the player selects a bomb:
    - Decrease the player's life by **1**.
    - Restart the current level.
    - Reset the **level score to 0**.
    - Generate a new bomb arrangement for the restarted attempt if required.
  - The game continues while the player has remaining lives.

- **Level Progression**
  - Each level has its own maximum score.
  - When the player reaches the maximum score:
    - Mark the current level as completed.
    - Move to the next level.
    - Continue with the remaining lives.

- **Score Management**
  - Maintain two scores:
    - **Level Score:** Tracks the player's score within the current level and resets to `0` whenever the level restarts.
    - **Top Score:** Stores the player's highest overall achievement across the game.
  - The top score is preserved while progressing through different levels.

- **Game Over**
  - If the player's lives reach `0`, the game ends.
  - Display the final **top score** to the player.
  - Provide an option to start a new game from the beginning.

  ## TEAM MEMBERS
- **Member 1:** [SANTHOSH P]
- **Member 2:** [VADAPATHIRASAI R]
- **Member 3:** [ANANTH M]
- **Member 4:** [AHAMED NAFEES M]
- **Member 5:** [KISHORE S]
- **Member 6:** [SIVA CHANDRA PRAKASH K]
- **Member 7:** [PRAMOTH B]
