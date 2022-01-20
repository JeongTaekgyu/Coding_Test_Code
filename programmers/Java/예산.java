
import java.util.Arrays;


public class 예산 {
    public static int solution(int[] d, int budget) {
        int answer = 0;
        int sum = 0;

        Arrays.sort(d);

        for(int i = 0; i < d.length; i++){
            sum += d[i];
            if(sum <= budget)
                answer++;
            else
                break;
        }

        return answer;
    }

    public static void main(String[] args){
        int[] arr = {1,3,2,5,4};
        int budget = 9;
        System.out.println(solution(arr, budget));
    }
}
