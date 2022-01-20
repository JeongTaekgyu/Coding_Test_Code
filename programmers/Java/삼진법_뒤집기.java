public class 삼진법_뒤집기 {
    public static int solution(int n) {
        int answer = 0;
        String strSum = "";

        // 10진법에서 3진법으로 뒤집어 String에 넣기
        while (n > 0){
            strSum += (n % 3);
            n /= 3;
        }

        // 3진법을 10진법으로
        answer = Integer.parseInt(strSum,3);

        return answer;
    }

    public static void main(String[] args) {
        System.out.println(solution(45));
    }
}
