public class 숫자_문자열과_영단어 {
    public static int solution(String str) {
        int answer = 0;
        String[] nums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        String[] words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        for(int i = 0; i < nums.length; i++){
            str = str.replace(words[i], nums[i]);
        }

        answer = Integer.parseInt(str);

        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution("one4seveneight"));
    }
}
