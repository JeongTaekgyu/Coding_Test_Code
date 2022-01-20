public class 나머지가_1이_되는_수_찾기 {
    public int solution(int n) {
        int cnt = 1;

        while (n % cnt != 1){
            cnt++;
        }
        return cnt;
    }

    public static void main(String[] args) {
        나머지가_1이_되는_수_찾기 method = new 나머지가_1이_되는_수_찾기();
        System.out.println(method.solution(12));
    }
}
