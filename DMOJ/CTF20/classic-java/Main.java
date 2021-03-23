// Java 8 is the only good Java
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        String flag = args[0];
        String returnValue = doSomethingVeryNiceButMaybeNotYouShouldStopReadingThisPointlessMethodName(flag);
        for (int i = 0; i < returnValue.length(); i++) {
            System.out.print((int)returnValue.charAt(i));
            if (i < returnValue.length() - 1) {
                System.out.print(" ");
            }
        }
    }

    public static int chunkSize = 10;

    public static String doSomethingVeryNiceButMaybeNotYouShouldStopReadingThisPointlessMethodName(String s) {
        String ret = "";
        for (int index = 0; index < s.length(); index += chunkSize) {
            String t = "";
            for (int place = 0; place < chunkSize && index + place < s.length(); place++) {
                t += s.charAt(index + place);
            }
            if (Math.random() < 0.5) {
                t = doSomethingVeryNiceButMaybeNotSubpart1(t);
            } else {
                t = doSomethingVeryNiceButMaybeNotSubpart2(t);
            }
            ret += doSomethingVeryNiceButMaybeNotSubpart3(t);
        }
        return ret;
    }

    public static String doSomethingVeryNiceButMaybeNotSubpart1(String s) {
        if (s.length() == 0) {
            return "";
        }
        String ret = "" + s.charAt(0);
        for (int index = 1; index < s.length(); index++) {
            ret += (char)((int)s.charAt(index) ^ (int)s.charAt(index - 1));
        }
        return ret;
    }

    public static String doSomethingVeryNiceButMaybeNotSubpart2(String s) {
        if (s.length() == 0) {
            return "";
        }
        String ret = "";
        for (int index = 1; index < s.length(); index++) {
            ret += (char)((int)s.charAt(index) ^ s.charAt(0));
        }
        return doSomethingVeryNiceButMaybeNotSubpart2(ret) + s.charAt(0);
    }

    public static String doSomethingVeryNiceButMaybeNotSubpart3(String s) {
        if (s.length() == 0) {
            return "";
        }
        return s.substring(s.length() / 5, s.length()) + s.substring(0, s.length() / 2) + doSomethingVeryNiceButMaybeNotSubpart3(s.substring(0, s.length() / 2));
    }
}
