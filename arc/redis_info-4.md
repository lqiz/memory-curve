1. evicted_keys 代表由于 maxmemory 限制,而被回收内存的 key 的总数
2. expired_keys:0 运行以来过期的 key 的数量，总数，库升级后清零。
3. keys expires avg_ttl 当前库总数，带有过期时间key总数，平均存活时间。
