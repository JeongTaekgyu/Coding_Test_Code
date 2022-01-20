import java.util.ArrayList;

public class 같은_숫자는_싫어 {
    public static int[] solution(int []arr) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<Integer>();

        for(int i = 0; i < arr.length - 1; i++){
            if( arr[i] == arr[i+1] ){
                continue;
            } else{
                list.add(arr[i]);
            }
        }
        // 위에서 arr의 마지막 인덱스에 있는 값은 list에 add 하지 못해서
        // arr의 마지막 인덱스에 있는 값을 list에 넣어준다.
        list.add(arr[arr.length-1]);

        answer = new int[list.size()];
        for(int i = 0; i < answer.length; i++)
            answer[i] = list.get(i);

        return answer;
    }

    public static void main(String[] args) {
        int[] arr = {4, 4, 4, 3, 3};
        int[] tmp = {};

        tmp = solution(arr);
        for(int t : tmp){
            System.out.println(t);
        }
    }
}
