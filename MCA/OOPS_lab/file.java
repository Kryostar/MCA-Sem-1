
// importing the FileReader class
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

class file {
	public static void main(String[] args) {
		System.out.print("Menu:\n1.Create File\n2.Read File\n3.Write to File\n4.Delete Files\n0.Exit\nEnter Choice: ");
		Scanner sc = new Scanner(System.in);
		int Choice = sc.nextInt();
		sc.close();
		file obj = new file();
		do {
			switch (Choice) {
				case 1:
					obj.create();
					break;
				case 2:
					obj.read();
					break;
				case 3:
					obj.write();
					break;
				case 4:
					obj.deletef();
					break;
				case 0:
					System.out.print("~EXIT~");
					break;
			}
		} while (Choice != 0);
	}

	void create() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter name of file: ");
		String fname = sc.nextLine();
		File file = new File(fname);
		try {
			// trying to create a file based on the object
			boolean value = file.createNewFile();
			if (value) {
				System.out.println("The new file is created.");
			} else {
				System.out.println("The file already exists.");
			}
		} catch (Exception e) {
			e.getStackTrace();
		}
		sc.close();
	}

	void read() {
		char[] array = new char[100];

		try {
			// Creates a reader using the FileReader
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter name of file: ");
			FileReader input = new FileReader(sc.nextLine());

			// Reads characters
			input.read(array);
			System.out.println("Data in the file:");
			System.out.println(array);

			// Closes the reader
			input.close();
			sc.close();
		} catch (Exception e) {
			e.getStackTrace();
		}
	}

	void write() {

		try {
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter Data to be written in File");
			String data = sc.nextLine();
			// Creates a Writer using FileWriter
			FileWriter output = new FileWriter("output.txt");

			// Writes string to the file
			output.write(data);
			System.out.println("Data is written to the file.");

			// Closes the writer
			output.close();
			sc.close();
		} catch (Exception e) {
			e.getStackTrace();
		}

	}

	void deletef() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the name of the file to be Deleted! : ");
		// creates a file object
		File file = new File(sc.nextLine());

		// deletes the file
		boolean value = file.delete();
		if (value) {
			System.out.println("The File is deleted.");
		} else {
			System.out.println("The File is not deleted.");
		}
		sc.close();
	}
}