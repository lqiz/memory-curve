#iptable
http://www.zsythink.net/archives/1199
三个关卡：PREROUTING FORWARD POSTROUTING
规则：根据指定的匹配条件来尝试匹配每个流经此处的报文
1. filter 表：负责过滤、防火墙、内核模块
2. nat表：网络地址转换
3. mangle表:拆解报文，修改，重新封装
4. raw表：关闭nat表上连接追踪机制

