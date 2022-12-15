public class Pair<K, V> {
    private K key;
    private V val;

    public Pair(K key, V val) {
        this.key = key;
        this.val = val;
    }

    public boolean isPrime() {
        int tmpK = Integer.parseInt(String.valueOf(key));
        int tmpV = Integer.parseInt(String.valueOf(val));
        if (tmpK < 2 || tmpV < 2)
            return false;
        for (int i = 2; i <= Math.sqrt(tmpK); i++) {
            if (tmpK % i == 0) {
                return false;
            }
        }
        for (int i = 2; i <= Math.sqrt(tmpV); i++) {
            if (tmpV % i == 0) {
                return false;
            }
        }
        return true;
    }

    @Override
    public String toString() {
        return key + " " + val;
    }
}
