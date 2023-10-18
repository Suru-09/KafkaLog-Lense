import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Random;

public class JavaProducer {

    private static final Logger LOGGER = LogManager.getLogger(JavaProducer.class);
    private static final String INFO_LOG = "Java INFO Log: ";
    private static final String ERROR_LOG = "Java ERROR Log: ";
    private static final String WARN_LOG = "Java WARN Log: ";


    public static void main(String[] args) throws InterruptedException {
        createLogs();
    }

    private static void createLogs() throws InterruptedException {
        int k = 0;
        boolean b = true;
        while (b) {
            LogSender();
            k++;
            b = k < Integer.MAX_VALUE;
            Thread.sleep(1000);
        }
    }

    private static void LogSender() {
        var random = new Random();
        var randomNumber = random.nextInt();
        switch (randomNumber % 10) {
            case 0:
            case 1:
            case 2:
                LOGGER.info(INFO_LOG + DateTimeFormatter.ofPattern("HH:mm:ss").format(LocalDateTime.now()));
                break;
            case 3:
            case 4:
            case 5:
                LOGGER.info(ERROR_LOG + DateTimeFormatter.ofPattern("HH:mm:ss").format(LocalDateTime.now()));
                break;
            case 6:
            case 7:
            case 8:
            case 9:
                LOGGER.info(WARN_LOG + DateTimeFormatter.ofPattern("HH:mm:ss").format(LocalDateTime.now()));
                break;
        }
    }

}