public class 로또의_최고_순위와_최저_순위 {
    public static int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int score = 0;
        int zeroCnt = 0;
        int maxScore = 0;

        // 0을 발견하면 zeroCnt 증가 시켜주고
        for(int i = 0; i < lottos.length; i++){
            if(lottos[i] == 0){
                zeroCnt++;
                continue;
            }
            // 당첨번호와 같은거 있으면 score를 증가시켜준다.
            for(int j = 0; j < lottos.length; j++ ){
                if(lottos[i] == win_nums[j]){
                    score++;
                    break;
                }
            }
        }

        // 0과 score를 합친게 최고순위가 되고
        // score만 있는게  최저 순위가 된다
        maxScore = zeroCnt + score;

        // 맞춘 개수에 따라 등수를 매긴다.
        if(maxScore == 6){
            answer[0] = 1;
        } else if(maxScore == 5){
            answer[0] = 2;
        } else if(maxScore == 4){
            answer[0] = 3;
        } else if(maxScore == 3){
            answer[0] = 4;
        } else if(maxScore == 2){
            answer[0] = 5;
        } else if(maxScore <= 1){
            answer[0] = 6;
        }

        // 0을 제외하고 하나도 못맞추면 최저 순위는 6등
        if( score == 0 )
            answer[1] = 6;
        else // 본인이 번호 하나라도 맞추면
            answer[1] = 6 - score + 1;

        return answer;
    }

    public static void main(String[] args){
        int[] lottos = {0, 0, 0, 0, 0, 0};
        int[] win_nums = {31, 10, 45, 1, 6, 19};
        int[] answer = new int[2];

        answer = solution(lottos, win_nums);

        for(int tmp: answer)
            System.out.println(tmp);
    }
}
