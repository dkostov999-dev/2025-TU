import java.util.Scanner;

public class zad_1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = scanner.nextInt();

        String[] facultyNumbers = new String[n];
        int[] grades = new int[n];

        
        System.out.println("Enter faculty number and grade:");
        readResults(scanner, facultyNumbers, grades);

        System.out.println("\nExam results:");
        
        printResults(facultyNumbers, grades);

        
        int failedCount = countFailedStudents(grades);
        System.out.println("\nNumber of failed students: " + failedCount);
        System.out.print("Faculty numbers of failed students: ");
        printFailedStudents(facultyNumbers, grades);

        
        double average = calculateAverageGrade(grades);
        System.out.printf("Average grade: %.1f\n", average);

        
        printTopStudents(facultyNumbers, grades);

        scanner.close();
    }

    
    public static void readResults(Scanner scanner, String[] facultyNumbers, int[] grades) {
        for (int i = 0; i < facultyNumbers.length; i++) {
            facultyNumbers[i] = scanner.next();
            grades[i] = scanner.nextInt();
        }
    }

    
    public static void printResults(String[] facultyNumbers, int[] grades) {
        for (int i = 0; i < facultyNumbers.length; i++) {
            System.out.println("Faculty No: " + facultyNumbers[i] + ", grade: " + grades[i]);
        }
    }

    
    public static int countFailedStudents(int[] grades) {
        int count = 0;
        for (int i = 0; i < grades.length; i++) {
            if (grades[i] == 2) {
                count++;
            }
        }
        return count;
    }

    
   public static void printFailedStudents(String[] facultyNumbers, int[] grades) {
    int printedCount = 0; 

    for (int i = 0; i < grades.length; i++) {
        if (grades[i] == 2) {
            
            if (printedCount > 0) {
                System.out.print(", ");
            }
            System.out.print(facultyNumbers[i]);
            printedCount++;
        }
    }
    System.out.println();
}
    
    public static double calculateAverageGrade(int[] grades) {
        if (grades.length == 0) {
            return 0.0;
        }
        int sum = 0;
        for (int i = 0; i < grades.length; i++) {
            sum += grades[i];
        }
        return (double) sum / grades.length;
    }

    
  public static void printTopStudents(String[] facultyNumbers, int[] grades) {
    if (grades.length == 0) {
        return;
    }

    
    int maxGrade = grades[0];
    for (int i = 1; i < grades.length; i++) {
        if (grades[i] > maxGrade) {
            maxGrade = grades[i];
        }
    }

    System.out.println("Highest grade: " + maxGrade);
    System.out.print("Students with highest grade: ");

    
    int printedCount = 0;

    for (int i = 0; i < grades.length; i++) {
        if (grades[i] == maxGrade) {

            if (printedCount > 0) {
                System.out.print(", ");
            }
            System.out.print(facultyNumbers[i]);
            printedCount++; 
        }
    }
    System.out.println();
}
}

