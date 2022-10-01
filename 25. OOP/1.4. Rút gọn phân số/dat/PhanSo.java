public class PhanSo {
    private long ts;
    private long ms;

    public long getTs() {
        return ts;
    }

    public void setTs(long ts) {
        this.ts = ts;
    }

    public long getMs() {
        return ms;
    }

    public void setMs(long ms) {
        this.ms = ms;
    }

    public PhanSo() {
    }

    public PhanSo(long ts, long ms) {
        this.ts = ts;
        this.ms = ms;
    }

    @Override
    public String toString() {
        return ts + "/" + ms;
    }

}