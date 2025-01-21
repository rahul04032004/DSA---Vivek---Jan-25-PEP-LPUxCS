/*Write a program that accepts a list of integers and calculates the sum of the integers using different approaches to illustrate the growth of functions. Specifically, implement the following:
Naive Approach: Use a simple loop to calculate the sum of the list.
Recursive Approach: Write a recursive function to calculate the sum of the list.
Using Built-in Functions: Use built-in sum() function to calculate the sum.
Discuss how the time complexity aligns with the concepts of asymptotic notations (Big O, Omega, Theta).*/

import java.util.List;
import java.util.ArrayList;

public class SumCalculator {

    // Naive Approach: Using a simple loop
    public static int naiveSum(List<Integer> numbers) {
        int total = 0;
        for (int num : numbers) {
            total += num;
        }
        return total;
    }

    // Recursive Approach
    public static int recursiveSum(List<Integer> numbers) {
        // Base case: empty list
        if (numbers.isEmpty()) {
            return 0;
        }
        // Recursive case: sum first element and the rest
        return numbers.get(0) + recursiveSum(numbers.subList(1, numbers.size()));
    }

    // Using Built-in Stream (similar to Python's sum())
    public static int builtInSum(List<Integer> numbers) {
        return numbers.stream().mapToInt(Integer::intValue).sum();
    }

    public static void main(String[] args) {
        // Example list of integers
        List<Integer> numbers = new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        numbers.add(5);

        System.out.println("List of Numbers: " + numbers);

        // Naive approach
        int naiveResult = naiveSum(numbers);
        System.out.println("Naive Approach Result: " + naiveResult);

        // Recursive approach
        int recursiveResult = recursiveSum(numbers);
        System.out.println("Recursive Approach Result: " + recursiveResult);

        // Built-in sum function using Streams
        int builtInResult = builtInSum(numbers);
        System.out.println("Built-in Function Result: " + builtInResult);
    }
}
