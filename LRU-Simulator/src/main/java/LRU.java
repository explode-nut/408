import java.util.Arrays;

public class LRU {
    private final int[] cache;
    private final int[] cacheAccumulator;
    private final int size;

    public LRU(int n) {
        cache = new int[n];
        cacheAccumulator = new int[n];
        size = n;
        for (int j = 0; j < size; j++) {
            cacheAccumulator[j] = -1;
        }
    }

    // 若包含i则返回数组下标，否则返回-1
    private int isContained(int i) {
        for (int j = 0; j < size; j++) {
            if (cache[j] == i) {
                return j;
            }
        }
        return -1;
    }

    private void addWhenHit(int item) {
        for (int j = 0; j < size; j++) {
            if (cacheAccumulator[j] != -1 && cacheAccumulator[j] < item) {
                cacheAccumulator[j]++;
            }
        }
    }

    // 若有空闲行返回数组下标，否则返回-1
    private int isFull() {
        for (int j = 0; j < size; j++) {
            if (cacheAccumulator[j] == -1) {
                return j;
            }
        }
        return -1;
    }

    public boolean get(int item) {
        int index;
        if ((index = isContained(item)) != -1) {
            addWhenHit(cacheAccumulator[index]);
            cacheAccumulator[index] = 0;
            return true;
        } else {
            put(item);
            return false;
        }
    }

    // index不用加
    private void addWhenNotHit(int index) {
        for (int j = 0; j < size; j++) {
            if (cacheAccumulator[j] != -1 && j != index) {
                cacheAccumulator[j]++;
            }
        }
    }

    private int maxIndex() {
        int max = cacheAccumulator[0];
        int res = 0;
        for (int j = 1; j < size; j++) {
            if (cacheAccumulator[j] > max) {
                max = cacheAccumulator[j];
                res = j;
            }
        }
        return res;
    }


    public void put(int item) {
        int emptyLine;
        if ((emptyLine = isFull()) != -1) {
            // 有空闲行
            addWhenNotHit(emptyLine);
            cacheAccumulator[emptyLine] = 0;
            cache[emptyLine] = item;
        } else {
            int maxIndex = maxIndex();
            addWhenNotHit(maxIndex);
            cacheAccumulator[maxIndex] = 0;
            cache[maxIndex] = item;
        }
    }

    @Override
    public String toString() {
        return "LRU{\n" +
                "cache=" + Arrays.toString(cache) + "\n" +
                "cacheAccumulator=" + Arrays.toString(cacheAccumulator) + "\n" +
                "size=" + size + "\n" +
                '}';
    }
}
