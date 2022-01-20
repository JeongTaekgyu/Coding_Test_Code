import java.util.ArrayList;

public class 모의고사 {
    public static int[] solution(int[] answers) {
        int[] answer = {};
        int[] p1Answer = {1, 2, 3, 4, 5};
        int[] p2Answer = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] p3Answer = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int[] score = new int[3];

        // 각 수포자의 점수를 계산한다
        for(int i = 0; i < answers.length; i++){
            if(p1Answer[i % 5] == answers[i]) score[0]++;
            if(p2Answer[i % 8] == answers[i]) score[1]++;
            if(p3Answer[i % 10] == answers[i]) score[2]++;
        }

        // 가장 큰 점수를 maxScore에 담는다
        int maxScore = Math.max(score[0], Math.max(score[1], score[2]) );
        ArrayList<Integer> list = new ArrayList<>();

        // maxScore가 같으면 오름차순으로 정렬
        if(maxScore == score[0]) list.add(1);
        if(maxScore == score[1]) list.add(2);
        if(maxScore == score[2]) list.add(3);

        // list에 있는 값을 answer배열에 넣어준다
        answer = new int[list.size()];
        for(int i = 0; i < answer.length; i++){
            answer[i] = list.get(i);
        }

        return answer;
    }

    public static void main(String[] args){
        int[] answers = {1,3,2,4,2};
        int[] ans;

        ans = solution(answers);
        for(int tmp: ans){
            System.out.println(tmp);
        }
    }
}