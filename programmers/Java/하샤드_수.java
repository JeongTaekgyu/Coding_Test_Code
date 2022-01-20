public class 하샤드_수 {
    public static boolean solution(int x) {
        boolean answer = false;
        int sum = 0;
        int tmp = x;

        while (tmp > 0){
            sum += tmp % 10;
            tmp /= 10;
        }

        if(x % sum == 0)
            answer = true;

        // sum으로 나누어 떨어지지 않으면 false 리턴
        return answer;
    }

    public static void main(String[] args) {
        System.out.println(solution(12));
    }
}
