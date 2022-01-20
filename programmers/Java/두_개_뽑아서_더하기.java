import java.util.ArrayList;
import java.util.Collections;

public class 두_개_뽑아서_더하기 {
    public static int[] solution(int[] numbers) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();

        // 더할 때 마다 탐색해서 값을 찾으면 시간 낭비가 심할 듯
        // 어차피 배열의 크기가 2~100이고
        // 배열안의 값도 0~100 이기 때문에 두 개만 더하면 0~199 범위가 나오니까
        // 더한걸 넣는 배열의 크기는 최대 200이 될듯하다.
        for(int i = 0; i < numbers.length-1; i++){
            for(int j = i+1; j < numbers.length; j++){
                // 해당 값이 list에 없으면 list에 add한다.
                if(list.indexOf( numbers[i] + numbers[j] ) == -1 ){
                    list.add( numbers[i] + numbers[j] );
                }
            }
        }

        Collections.sort(list);

        answer = new int[list.size()];
        for(int i = 0; i < answer.length; i++ )
            answer[i] = list.get(i);

        return answer;
    }

    public static void main(String[] args) {
        int[] numbers = {2,1,3,4,1};
        int[] answer = {};
        answer = solution(numbers);

        for(int tmp : answer)
            System.out.println(tmp);

    }
}
