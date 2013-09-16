
#if 0

生产者-消费者模式实现概述
生产者与消费者模式是我们在编程过程中经常会遇到的，就像我们生活那样，生产者生产出
产品，消费者去购买产品。在这里我们创建三个线程，一个主控线程main，用于创建各辅
助线程；一个生产者线程，用于生产产品；一个消费者线程，用于购买产品。另外，我们创
建一个队列类Queue，生产线程生产的产品将放置到该队列中，然后消费者线程在该队列中
取走产品。
2.实现该模式的要点:
首先必须让生产者线程与消费者线程达到同步，也就是说，当生产者线程生产出产品后，消
费者才能去取，依此轮回。当生产者线程放置产品到队列中时，队列要检查队列是否已满，
如已满，则等待消费者线程将产品取走，否则放置产品到队列中。当消费者线程在队列中取
产品时，队列也要检查队列是否为空，如果为空，则等待生产者线程放置产品到队列，否则
在队列中取走产品。
3.源代码:


[java] view plaincopyprint?
1.  class M ainThread
2.
3.  {
4.
5.  public static void main(String[] args)
6.
7.  {
8.
9.  Queue queue=new Queue();
10.
11.  Producer producer=new Producer(queue);
12.
13.  Consumer consumer=new Consumer(queue);
14.
15.  new Thread(producer).start();
16.
17.  new Thread(consumer).start();
18.
19.  }
20.
21.  }
22.
23.  /*注意:wait notify notifyAll只能在同步方法或内步块中调用*/
24.
25.  class Queue
26.
27.  {
28.
29.  int product=0;
30.
31.  boolean bfull=false;
32.
33.  public synchronized void setProduct(int product)
34.


35.  {
36.
37.  if(bfull)//如果队列已满，则调用wait等待消费者取走产品
38.
39.  {
40.
41.  try
42.
43.  {
44.
45.  wait();
46.
47.  }
48.
49.  catch(Exception e)
50.
51.  {
52.
53.  e.printStackTrace();
54.
55.  }
56.
57.  }
58.
59.  /*开始放置产品到队列中*/
60.
61.  this.product=product;
62.
63.  System.out.println(Producer set product:+product);
64.
65.  bfull=true;
66.
67.  notify();//生产产品后通知消费者取走产品
68.
69.  }


70.
71.  public synchronized void getProduct()
72.
73.  {
74.
75.  if(!bfull)//如果队列是空的，则调用wait等待生产者生产产品
76.
77.  {
78.
79.  try
80.
81.  {
82.
83.  wait();
84.
85.  }
86.
87.  catch(Exception e)
88.
89.  {
90.
91.  e.printStackTrace();
92.
93.  }
94.
95.  }
96.
97.  /*开始从队列取走产品*/
98.
99.  System.out.println(Consumer get product:+product);
100.
101. bfull=false;
102.
103. notify();//取走产品后通知生产者继续生产产品
104.


105. }
106.
107. }
108.
109. class Producer implements Runnable
110.
111. {
112.
113. Queue queue;
114.
115. Producer(Queue queue)
116.
117. {
118.
119. this.queue=queue;
120.
121. }
122.
123. public void run()//生产线程
124.
125. {
126.
127. for(int i=1;i=10;i++)
128.
129. {
130.
131. queue.setProduct(i);
132.
133. }
134.
135. }
136.
137. }
138.
139. class Consumer implements Runnable


140.
141. {
142.
143. Queue queue;
144.
145. Consumer(Queue queue)
146.
147. {
148.
149. this.queue=queue;
150.
151. }
152.
153. public void run()//消费线程
154.
155. {
156.
157. for(int i=1;i=10;i++)
158.
159. {
160.
161. queue.getProduct();
162.
163. }
164.
165. }
166.
167. }


输出结果如下:
Producer set product:1
Consumer get product:1
Producer set product:2
Consumer get product:2


Producer set product:3
Consumer get product:3
Producer set product:4
Consumer get product:4
Producer set product:5
Consumer get product:5
Producer set product:6
Consumer get product:6
Producer set product:7
Consumer get product:7
Producer set product:8
Consumer get product:8
Producer set product:9
Consumer get product:9
Producer set product:10
Consumer get product:10
完。。。
#endif
