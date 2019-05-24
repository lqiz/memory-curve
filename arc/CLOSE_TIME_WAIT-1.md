#TIME_WAIT CLOSE_WAIT
1. 主动关闭的一方，调动close(),协议层发送FIN包，并进入FIN_WAIT_1状态，等待ACK；
2. 被动关闭的一方，收到FIN，进入CLOSE_WAIT，回复ACK，主动关闭的一方收到后，进入FIN_WAIT_2状态，继续等待被动关闭一方调用close()；
3. 被动关闭一方发送完所有数据后，调用close()操作，此时协议层发送FIN包给主动关闭一方，等待对方ACK，被动关闭一方进入LAST_ACK状态。
4. 主动关闭一方收到FIN包，协议层回复ACK；此时主动关闭连接一方，进入TIME_WAIT;而被动关闭的一方，进入CLOSED状态
5. 等待2MSL时间，主动关闭的一方，结束TIME_WAIT，进入CLOSED状态。
