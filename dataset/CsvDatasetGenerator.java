import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

class CsvDatasetGenerator {

    private final Random random = new Random();
    private static int numOfTestData = 0;

    public static void main(String[] args) {
        System.out.println(new CsvDatasetGenerator().generateData());
    }

    private boolean generateInts(long count) throws IOException {
        File file = new File("C:\\Users\\user\\CLionProjects\\semester-work-graham-scan\\dataset\\data\\dataset" + (++numOfTestData) + ".csv");
        FileWriter fileWriter = new FileWriter(file);

        String data = "";
        for (int i = 0; i < count; i++) {
            data = data.concat(random.nextInt() + "," + random.nextInt() + ";");
        }
        fileWriter.append(data);
        fileWriter.flush();
        fileWriter.close();
        return file.exists();
    }

    public String generateData() {
        try {
            return
                    "100 nums: " + generateInts(100) +
                    "1000 nums: " + generateInts(1000) +
                    "5000 nums: " + generateInts(5000) +
                    "10000 nums: " + generateInts(10000) +
                    "50000 nums: " + generateInts(50000) +
                    "100000 nums: " + generateInts(100000) +
                    "500000 nums: " + generateInts(500000);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "something go wrong";
    }
}