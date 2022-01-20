import java.util.Arrays;

public class 문자열_내_마음대로_정렬하기 {
    public static String[] solution(String[] strings, int n) {
        String[] answer = {};
        String[] tmpStr = new String[strings.length];

        for(int i = 0; i < strings.length; i++){
            // char + String 이기때문에 String 타입 배열에 삽입된다
            tmpStr[i] = strings[i].charAt(n) +strings[i];
        }

        Arrays.sort(tmpStr);

        answer = new String[strings.length];
        for(int i = 0; i < answer.length; i++){
            answer[i] = tmpStr[i].substring(1);
        }

        return answer;
    }

    public static void main(String[] args){
        String[] str = {"sun", "bed", "car"};
        String[] answer = {};
        answer = solution(str, 1);

        for(String tmp : answer)
            System.out.println(tmp);
    }
}
