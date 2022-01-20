import java.util.Arrays;
import java.util.Collections;

public class 문자열_내림차순으로_배치하기 {
    public static String solution(String str) {
        String answer = "";
        String[] tmpStr = str.split("");    // str을 문자 하나씩 배열에 넣어준다.
        // 이렇게 split 해서 넣는게
        // for문 돌려서 넣는거 보다 실행시간이 빠르다.

        // 아래 처럼 미리 배열의 크기 구하고 for문으로 돌려주면 실행시간이 오래 걸린다.
        /*String[] tmpStr = new String[str.length()];

        for(int i = 0; i < str.length(); i++){
            tmpStr[i] = str.charAt(i) + "";
            // 둘이 뭐가 달라?
            //strArr[i] = String.valueOf(str.charAt(i));
        }*/

        Arrays.sort(tmpStr, Collections.reverseOrder());

        for(String tmp : tmpStr)
            answer += tmp;

        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution("KLJGkzgjKGJa"));
    }
}
