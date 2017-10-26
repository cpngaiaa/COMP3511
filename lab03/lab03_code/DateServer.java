import java.net.*;
import java.io.*;
import java.util.Date;

public class DateServer {
	public static void main(String[] args) {
		try {
			ServerSocket sock = new ServerSocket(6013);

			// Now, listen for connections 
			while (true) {
				Socket client = sock.accept();
				PrintWriter out = new PrintWriter(client.getOutputStream(), true);

				out.println( new Date() ); // print the dates to the socket
				client.close();  // close the socket and resume listening for connections
			}
		} catch (IOException e) {
			System.err.println(e);
		}
	}
}
