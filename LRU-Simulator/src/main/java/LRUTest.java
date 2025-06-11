import java.io.BufferedReader;
import java.io.FileReader;

public class LRUTest {
    public static void main(String[] args) {
        int hitCount = 0;
        LRU lru = new LRU(4);
        // 顺序读取/home/tycoon/code/408/LRU-Simulator/lru.txt路径文件，这个文件包含一行数据，每个数据用空格分隔，测试lru的get方法是否命中，get方法返回一个boolean
        try {
            BufferedReader br = new BufferedReader(new FileReader("lru.txt"));
            String line = br.readLine();
            String[] items = line.split(" ");
            for (String item : items) {
                int i = Integer.parseInt(item);
                boolean hit = lru.get(i);
                System.out.println(lru);
                System.out.println(!hit ? "未命中" : "命中");
                if (hit) hitCount++;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("共命中" + hitCount + "次");
    }
}
