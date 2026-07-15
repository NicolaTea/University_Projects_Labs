import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class LogParser {
    public void parserLogFile(String path) throws IOException {
        Path filePath=Path.of(path);
        try(BufferedReader reader= Files.newBufferedReader(filePath)){
            System.out.println(reader.readLine());
        }




    }
}
