public class 최소직사각형 {
    public static int solution(int[][] sizes) {
        int answer = 0;
        int tmp;
        int max0 = 0;    // max0 = size[0][0];
        int max1 = 0;    // max1 = size[0][1]; 이런식으로 하면 안되는 이유가 아래 반복문에서 바뀌는 경우 있어서

        for(int i = 0; i < sizes.length ; i++){
            // 각 행에서 큰 것을 0열로 작은 것을 1열로 옮긴다.
            if(sizes[i][0] <  sizes[i][1]){
                tmp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = tmp;
            }

            // 각 열에서 가장 큰 값을 구한다.
            if(sizes[i][0] > max0)
                max0 = sizes[i][0];
            if(sizes[i][1] > max1)
                max1 = sizes[i][1];
        }

        answer = max0 * max1;
        return answer;
    }

    public static void main(String[] args) {
        int[][] sizes = { {10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15} };

        System.out.println(solution(sizes));
    }
}
