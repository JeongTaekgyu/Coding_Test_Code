public class 시저_암호 {
    public static String solution(String str, int n) {
        String answer = "";
        char ch;

        for(int i = 0; i < str.length(); i++){
            ch = str.charAt(i);

            if(ch >= 'a' && ch <= 'z'){
                // (char)로 안바꿔주면 int형이다...
                ch = (char)((ch - 'a' + n )%26 + 'a');
            } else if(ch >= 'A' && ch <= 'Z') {
                ch = (char)((ch - 'A' + n) % 26 + 'A');
            }
            answer += ch;
        }

        return answer;
    }

    public static void main(String[] args){
        System.out.println(solution("a B zf", 3));
    }
}
