import java.util.*;
// Add two arrays of the same size (size)// Each array is a representation of a natural number// The returned array will have the size of (size + 1) elements
public class Fibonacci
{
private static String arrToString(int[] arr) {
          String s = "";
          for (int i = 0; i < arr.length; i++) {
              s = s + arr[i];}
          return s;
      }
private static String getStringOfIntArrayNum(int[] num) {
          String result = arrToString(num); // Might contain leading zeros
          result = removeLeadingZeros(result);      
          return result;}
private static int[] addTwoArrays(int[] arr1, int[] arr2) {
int size = arr1.length;
int[] arrTotal = new int[size + 1];
for (int i = 0; i < size; i++) {
    arrTotal[i] = 0;}
int remaider = 0;
for (int i = size - 1; i >= 0; i--) {
    int temp = arr1[i] + arr2[i] + remaider;
    arrTotal[i + 1] = temp % 10;
    remaider = temp / 10;}
arrTotal[0] = remaider;
return arrTotal;}
private static int[] getFibArray(int n, int size) {// Return F(n) in the form of an array, with (size + 1) elements
      int[] fibArr1 = new int[size];
      int[] fibArr2 = new int[size];
      int[] fibResultArr = new int [size + 1];
      // Initially set up
      for (int i = 0; i < size; i++) {
        fibArr1[i] = fibArr2[i] = fibResultArr[i] = 0;
      }
      if (n == 0) {// return fibArr1;
        return (addTwoArrays(fibArr1, fibArr1));
      }
      if (n == 1) {
        fibArr2[size - 1] = 1;// return fibArr2;
        return (addTwoArrays(fibArr1, fibArr2));
      }
      /*// Do the Recursive way
      fibResultArr = addTwoArrays(getFibArray(n - 1, size - 1),
          getFibArray(n - 2, size - 1));*/
      // Do the Iterative way
      fibArr2[size - 1] = 1;
      for (int i = 0; i < n - 1; i++) {
        fibResultArr = addTwoArrays(fibArr1, fibArr2);
        fibArr1 = fibArr2;
        int[] fibArr2Temp = new int[fibArr2.length];
        for (int j = 0; j < fibArr2.length; j++) {
          fibArr2Temp[j] = fibResultArr[j + 1];
        }
        fibArr2 = fibArr2Temp;
      }
      return fibResultArr;
    }
    private static String removeLeadingZeros(String s) {// "0" returns "0", "0012" returns "12"
      if (s.length() < 2)
        return s;
      int i;
      for (i = 0; i < s.length() - 1; i++) {
        char c = s.charAt(i);
        if (c != '0')
          break;
      }
      if (i == 0) {
        return s;
      }
      return s.substring(i);}
private static String getBiggestFib(int size) {// Return the biggest F(n) that has less than (size) character.
String result = ""; int n = 0; // could have started with a 'near' value, such as 400
int[] fib; // getFibArray(n, size) has (size + 1) = 99 digits
if (size == 2)
    return "8";
while (true) {
    fib = getFibArray(n, size - 2);
    if (fib[0] != 0)
      break;
    n++;}
int low = n;// System.out.println("Low index is: " + low);// low = 472 = min F(n) that has 99 digits
int[] fibAbove;
while (true) {
    fibAbove = getFibArray(n, size - 1);

    if (fibAbove[0] != 0)
      break;
    n++;}
int high = n;
for (int i = low; i <= high; i++) {
    int[] f = getFibArray(i, size - 1);
    if (getStringOfIntArrayNum(f).length() >= size) {
      n = i - 1; // right before i that makes F(n) 100 digits
      break;}}
result = getStringOfIntArrayNum(getFibArray(n, size - 1));
return result;
}
public static void main(String args[])
{
System.out.println("Biggest Fibonacci number that has less than 100 digits : " + getBiggestFib(100));}}