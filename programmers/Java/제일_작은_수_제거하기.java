import java.util.ArrayList;

public class 제일_작은_수_제거하기 {
    public static int[] solution(int[] arr) {
        int[] answer = new int[arr.length - 1];
        int min = arr[0];

        // 배열에 값이 하나밖에 없으면 -1을 반환한다.
        if(arr.length == 1) {
            answer = new int[1];
            answer[0] = -1;
            return answer;
        }

        // min을 구한다.
        for(int i = 1; i < arr.length; i++){
            if(arr[i] < min){
                min = arr[i];
            }
        }

        // min을 빼고 배열에 담는다.
        int cnt = 0;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] != min){
                answer[cnt++] = arr[i];
            }
        }

        return answer;
    }

    public static void main(String[] args){
        int[] arr = {7, 3, -2, 5, -3, 4};
        int[] tmp;

        tmp = solution(arr);
        System.out.println("tmp.length : "+arr.length);
        for (int tt : tmp ) {
            System.out.print(" "+tt);
        }

    }
}
