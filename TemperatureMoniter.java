import java.util.Scanner;
import java.util.Random;

public class TemperatureMonitor {
    private static int count = 0;
    private static Scanner scanner = new Scanner(System.in);
    private static Random random = new Random();

    public static void main(String[] args) {
        System.out.println("Press ENTER to simulate a button press and read temperature...");
        
        while (true) {
            scanner.nextLine(); // Wait for user to press Enter
            count++;

            double temperatureC = simulateTemperature();

            System.out.println("Button Press Count: " + count);
            System.out.printf("Temperature: %.2f °C\n", temperatureC);
            System.out.println("---------------------------");
        }
    }
    private static double simulateTemperature() {
        return 20.0 + (15.0 * random.nextDouble());
    }
}
