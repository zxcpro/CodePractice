import java.util.Random;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * Created by xuanchen.zhao on 16-3-30.
 */
public class CyclicBarrierDemo {

    public static void main(String[] args) throws BrokenBarrierException, InterruptedException {

        LinkedBlockingQueue<Integer> results = new LinkedBlockingQueue<Integer>();

        StatisticRunnable statisticRunnable = new StatisticRunnable(results);

        CyclicBarrier barrier = new CyclicBarrier(4, statisticRunnable);

        ExecutorService threadPool = Executors.newFixedThreadPool(4);
        for (int i = 1; i < 5; i++) {
            Worker worker = new Worker(i, barrier, results);
            threadPool.submit(worker);
        }

        System.out.println("done");
        threadPool.shutdown();
    }

    public static class Worker implements Runnable {

        private LinkedBlockingQueue<Integer> results;

        private String name;
        private int result;
        private CyclicBarrier barrier;

        public Worker(int value, CyclicBarrier barrier, LinkedBlockingQueue<Integer> results) {
            this.name = "Thread"+value;
            this.result = value;
            this.barrier = barrier;
            this.results = results;
        }

        @Override
        public void run() {
            int sleep = new Random().nextInt(4000) + 1000;
            try {
                System.out.println(name + " working for:" + sleep);
                Thread.sleep(sleep);
                System.out.println(name + " done working");
                results.add(result);

                barrier.await();
                System.out.println(name +" wait done");
            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }

    public static class StatisticRunnable implements Runnable {

        LinkedBlockingQueue<Integer> results;

        public StatisticRunnable(LinkedBlockingQueue<Integer> results) {
            this.results = results;
        }

        @Override
        public void run() {
            int sum = 0;
            for (Integer result : results) {
                sum += result;
            }
            System.out.println("All the sum is:"+sum);
        }
    }


}
