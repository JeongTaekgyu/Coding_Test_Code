import java.util.ArrayList;

public class 소수_만들기 {
    public static int solution(int[] nums) {
        int sum = 0;
        ArrayList<Integer> numlist = new ArrayList<>();

        // i, j, k 시작을 이렇게 하면 인덱스가 겹칠일이 없다.
        for(int i =0; i < nums.length-2; i++){
            for(int j = i+1; j < nums.length - 1; j++){
                for(int k = j+1; k < nums.length; k++){
                    numlist.add( nums[i] + nums[j] + nums[k] );
                }
            }
        }

        // 소수의 개수 체크
        boolean chk;

        for(int i = 0; i < numlist.size(); i++){
            chk = true; // 초기값 소수체크 = true 셋팅
            for(int j = 2; j < numlist.get(i); j++){
                if(numlist.get(i) % j == 0){
                    // 소수가 아니다
                    chk = false;
                    break;
                }
            }
            if(chk) // 소수이면
                sum++;
        }

        return sum;
    }

    public static void main(String[] args){
        int[] arr = {1,2,3,4};
        System.out.println(solution(arr));
    }
}
