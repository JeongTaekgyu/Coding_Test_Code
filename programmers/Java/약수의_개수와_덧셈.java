public class 약수의_개수와_덧셈 {
    public static int solution(int left, int right) {
        int answer = 0;
        int cnt;

        for(int num = left; num <= right; num++){
            cnt = 0;
            for(int j = 1; j <= num; j++){
                if(num % j == 0){
                    cnt++;  // 약수이면 카운트한다
                }
            }
            if(cnt % 2 == 0) // 약수의 개수가 짝수면 더한다.
                answer += num;
            else    // 약수의 개수가 홀수면 뺸다
                answer -= num;
        }

        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution(24,27));
    }
}
