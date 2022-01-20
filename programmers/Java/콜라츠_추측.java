public class 콜라츠_추측 {
    public static int solution(int num) {
        int cnt = 0;

        while (num != 1){
            if(num % 2 == 0)
                num /= 2;
            else if(num % 2 == 1){
                // 이게 else이면 int형을 넘어갈 수 있다.
                num = num * 3 + 1;
            }

            cnt++;
            if(cnt == 500){
                return -1;
            }
        }

        return cnt;
    }

    public static void main(String[] args) {
        System.out.println(solution(1));
    }

}
