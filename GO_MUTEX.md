#Mutex
Mutual exclusion
1. 避免死锁，追求公平
2. Unlock 未加锁 Mutex 会panic
3. 加锁Mutex 不和goroutinue 相关
4. 非重入锁。（可重入锁：每个锁关联一个线程持有者和计数器，当计数器为0时表示该锁没有被任何线程持有，那么任何线程都可能获得该锁而调用相应的方法；当某一线程请求成功后，JVM会记下锁的持有线程，并且将计数器置为1；此时其它线程请求该锁，则必须等待；而该持有锁的线程如果再次请求这个锁，就可以再次拿到这个锁，同时计数器会递增；当线程退出同步代码块时，计数器会递减，如果计数器为0，则释放该锁）

互斥锁状态：正常状态和饥饿状态，等待的 goroutinue 超过1ms没有获取锁。

RWMutex
1. 读写锁，不同其他语言特点，写的WLock优先级相对RLock优先级高?
2. 禁止递归读锁，注意重入和递归的区别：问题?
3. 为啥32位，怕不支持其他处理器

WaitGroup
1. 可以复用，但是一定要知道它的计数重新被设置了0，建议不要复用

Once
1. 即便 f panic Once 也认为它执行完成了。

实现单例多种方式
1. package 级别常量
2. package 变量
3. init函数
4. sync.Once
5. io.EOF, http.DefaultClient 修改后，其他协作者可能会受影响。

锁是有状态的，拷贝会拷贝状态。通过go vet可以检查此类错误。定义 noCopy  
  

Pool
1. 无泛型，不同类型装入，装箱/拆箱，即：和interface的类型转换，带来些许性能损失
2. 容易造成内存泄漏

sync.Map
为了提高性能，dirty 有锁，readonly 无锁。无新增数据从readonly里读，有冗余双份数据，但是是指针指向相同时数据。

context.Context
1. 传递上下文
2. 取消goroutinue的运行。
3. 官方建议：不要嵌入 struct中，做copy持久化。
Context 问题还比较多，需要继续了解下

扩展同步原语：
Semaphore ?
SingleFlight ? 单飞，避免对后台资源雪崩的访问。感觉缓存可以用这里改善，避免雪崩。
ErrGroup 出现错误就返回
SpinLock 有些场景比较高效，处理器忙等待。
FileLock 跨进程的Mutex
concurrent-map：第三方分片shared map 的功能，继续提高性能

分布式同步原语框架：
redis redis lock
etcd：
Leader election，直接利用etcd提供的功能
PriorityQueue 队列，一致性队列，性能损失还是挺大
STM 软事务内存
micro/go-sync 没有etcd 使用的广泛


Channel:
1. 传递数据的owner
2. 分发任务单元
3. 交流异步结果
4. 任务编排
空值、满、关闭等，容易出错，获取channel 时候，可以通过ok来判断是否空。
Mutex
1. cache
2. 状态
3. 临界区

Channel 使用模型
Fan In 扇入，递归扇入。整合数据。
Fan Out 扇出
管道，以观察者的模式实现流水线的控制。
Stream-Skip、Take、Map-Reduce模型

内存模型

sync.Pool 可能有内存回收问题，一定要检查放入的是否太大。
slice append 进行append扩容，会有线程问题。 


golang question?
1. itoa
2. atomic
3. unsafe.Pointer
4. 



问题：
1. 读写锁，不同其他语言特点，写的WLock优先级相对RLock优先级高?
2. 禁止递归读锁，注意重入和递归的区别：问题?
3. 和java 不同，不等待

