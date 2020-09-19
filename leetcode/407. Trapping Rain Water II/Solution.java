import java.util.PriorityQueue;
import java.util.Arrays;

public class Solution {
    public static int trapRainWater(int[][] heightMap) {
        int len = heightMap.length;
        int width = heightMap[0].length;
        int result = 0;
        if(len <= 2 || width <= 2) {return 0;}
        int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};

        boolean[][] status = new boolean[len][width];
        
        // PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[2]-b[2]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);  //pass a customized comparator
                                                                                //item in the priority queue is int list
                                                                                //order by the third element(height) in each list
        
        for (int i = 0; i < len; ++i) {
            status[i][0] = status[i][width-1] = true;
            pq.add(new int[] {i,0,heightMap[i][0]});
            pq.add(new int[] {i,width-1,heightMap[i][width-1]});
        }
        
        for (int i = 0; i < width; ++i) {
            status[0][i] = status[len-1][i] = true;
            pq.add(new int[] {0,i,heightMap[0][i]});
            pq.add(new int[] {len-1,i,heightMap[len-1][i]});
        }

        // while(!pq.isEmpty()) {
        //     int[] cell = pq.poll();
        //     System.out.println(Arrays.toString(cell));
        // }
        while(!pq.isEmpty()) {
            int[] cell = pq.poll();
            int nei_x, nei_y = 0;
            for (int[] d : dir) {
                nei_x = cell[0] + d[0];
                nei_y = cell[1] + d[1];
                if(nei_x < 0 || nei_x >= len || nei_y < 0 || nei_y >=width || status[nei_x][nei_y]) {
                  continue; 
                }
                result += Math.max(0, cell[2] - heightMap[nei_x][nei_y]);
                pq.add(new int[] {nei_x,nei_y,Math.max(heightMap[nei_x][nei_y]},cell[2])});
                status[nei_x][nei_y] = true;
            }
        }
        return result;
    }
    
    public static void main(String args[]) {
        
        int[][] input = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};

        System.out.println(trapRainWater(input));
 
    }
}