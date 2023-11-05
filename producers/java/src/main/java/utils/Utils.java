package utils;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import org.apache.commons.lang3.RandomStringUtils;
import uuid.Uid;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Date;

public class Utils {
    private static final int STRING_LENGTH = 32;

    private static String generateUuid() {
        try {
            String input = RandomStringUtils.random(STRING_LENGTH, true, true);
            Date date = new Date();
            input += (date.getTime() / 1000);
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] digest = md.digest(input.getBytes());

            StringBuilder hexString = new StringBuilder();
            for (byte b : digest) {
                hexString.append(String.format("%02x", b));
            }

            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static String readOrCreateUid(String name) {

        Path filePath = Paths.get( name);
        File file = new File(String.valueOf(filePath));
        Uid uid = null;

        if (file.exists()) {
            Gson gson = new Gson();
            try (FileReader fileReader = new FileReader(file)) {
                uid = gson.fromJson(fileReader, Uid.class);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            Gson gson = new GsonBuilder().setPrettyPrinting().create();
            uid = new Uid();
            uid.setUuid(generateUuid());
            try (FileWriter writer = new FileWriter(name) ){
                gson.toJson(uid, writer);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return uid.getUuid();
    }
}