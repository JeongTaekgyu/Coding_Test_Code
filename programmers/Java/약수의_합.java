public class 약수의_합 {
    public static int solution(int n) {
        int sum = 0;

        // 절반까지만 검사하고 return할때 자기자신 더하는게 시간 단축된다.
        for(int i = 1; i <= n/2; i++){
            if(n % i == 0){
                sum+= i;
            }
        }

        return sum + n;
    }

    public static void main(String[] args){
        System.out.println(solution(12));
    }
}
