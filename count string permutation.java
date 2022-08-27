import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;


class Result {

    /*
     * Complete the 'countPerms' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER n as parameter.
     */

    public static int countPerms(int n) {
    // Write your code here
    if (n == 1) return 5;

    long mod = 1000000007L;

    //aeiou corresponds to 01234
    long[] previous = new long[5];
    long[] current = new long[5];

    long sumPrevious = 4;
    for (int j = 0; j < 5; j++) previous[j] = 1;

    for (int i = 2; i <= n; i++)
    {
      //a
      current[0] = previous[1];
      //e
      current[1] = (previous[0] + previous[2]) % mod;
      //i
      current[2] = sumPrevious;
      //o
      current[3] = (previous[2] + previous[4]) % mod;
      //u
      current[4] = previous[0];

      sumPrevious = 0;
      for (int j = 0; j < 5; j++)
      {
        previous[j] = current[j];
        if (j != 2) sumPrevious += previous[j];
      }
      sumPrevious %= mod;
    }

    long result = (current[0] + current[1] + current[2] + current[3] + current[4]) % mod;

    return (int)result;

    }

}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        int result = Result.countPerms(n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
