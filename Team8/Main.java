import java.util.*;


class Grid {
    int n;
    Set<Integer> lifes = new HashSet<>();
    Set<Integer> bombs = new HashSet<>();
    Set<Integer> visited = new HashSet<>();
    int score = 0;
    int life = 1;

    Grid(int n) {
        this.n = n;
    }

    public void populateBomb() {
        while (bombs.size() < 34) {
            int num = (int) (Math.random() * n) + 1;
            bombs.add(num);
        }
    }

    public boolean check(int n) {
        return bombs.contains(n);
    }

    public void populateLife() {
        while (lifes.size() < 4) {
            int num = (int) (Math.random() * n) + 1;

            if (!bombs.contains(num)) {
                lifes.add(num);
            }
        }
    }

    public void checkGrid(int n) {
        if (n < 1 || n > this.n) {
            System.out.println("Please enter a number between 1 and " + this.n);
            return;
        }

        if (visited.contains(n)) {
            System.out.println("This cell has already been visited.");
            return;
        }

        if (bombs.contains(n)) {
            life--;
            visited.add(n);

            System.out.println("You landed on a Bomb!");
            System.out.println("Life remaining: " + life);
        }

        else if (lifes.contains(n)) {
            life++;
            score++;
            visited.add(n);

            System.out.println("You earned a Life!");
            System.out.println("Current lives: " + life);
            System.out.println("Current score: " + score);
        }

        else {
            visited.add(n);
            score++;

            System.out.println("You are safe!");
            System.out.println("Current score: " + score);
        }

        if (score >= 67) {
            System.out.println("\n*** YOU HAVE WON! ***");
        }

        else if (life <= 0) {
            System.out.println("\n*** GAME OVER! ***");
            System.out.println("Your final score: " + score);
        }
    }

    public void displayGrid() {
        int k = 1;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (visited.contains(k)) {
                    System.out.print("* ");
                } else {
                    System.out.printf("%2d ", k);
                }

                k++;
            }

            System.out.println();
        }
    }
}

public class Main {

    public static void main(String[] args) {
        Grid grid = new Grid(100);
        Scanner sc = new Scanner(System.in);
        grid.populateBomb();
        grid.populateLife();

        System.out.println("*** Welcome to the Grid Game ***");
        System.out.println("You have " + grid.life + " lives.");
        System.out.println();

        while (grid.life > 0 && grid.score < 67) {
            grid.displayGrid();
            System.out.println("\n*** Menu ***");
            System.out.println("1. Enter a Number (1 - 100)");
            System.out.println("2. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            if (choice == 2) {
                System.out.println("Thanks for playing!");
                break;
            }

            if (choice != 1) {
                System.out.println("Invalid choice.");
                continue;
            }

            System.out.print("Enter a number (1 - 100): ");
            int number = sc.nextInt();

            grid.checkGrid(number);

            System.out.println(
"Current score: " + grid.score + ", Current lives: " + grid.life
            );
        }

        if (grid.score >= 67) {
            System.out.println("Congratulations! You reached the winning score.");
        } else if (grid.life <= 0) {
            System.out.println("You lost all your lives.");
        }

        sc.close();
    }
}