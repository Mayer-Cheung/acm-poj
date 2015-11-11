import java.util.Scanner;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));

		BigInteger a;
		BigInteger b = new BigInteger("0");
		BigInteger c = new BigInteger("0");
		while (cin.hasNextBigInteger())
		{
			a = cin.nextBigInteger();
			if (a.compareTo(c) == 0)
				break;
			b= b.add(a);
		}
		System.out.println(b);
	}
}