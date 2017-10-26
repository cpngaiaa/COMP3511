class Sum {
	private int sum;
	public int getSum() { return sum; } // getter
	public void setSum(int sum) { this.sum = sum; } // setter
}

class Runner implements Runnable {
	private int upper;
	private Sum  sumValue;

	public Runner(int upper, Sum sumValue) {
		this.upper = upper;
		this.sumValue = sumValue;
	}

	public void run() {
		int sum = 0;
		for (int i=1; i <= upper; i++)
			sum += i;
		sumValue.setSum(sum);
	}
}


public class JavaThreadDemo {
	public static void main(String[] args) {
		int upper = 2; // change this value 
		Sum sumObj = new Sum();
		Thread t = new Thread( new Runner(upper, sumObj));
		t.start();
		try {
			t.join();
			System.out.println(String.format("Sum of 1..%d = %d\n", upper, sumObj.getSum()));
		} catch (InterruptedException e) {
			System.err.println(e);
		}
	}
}


