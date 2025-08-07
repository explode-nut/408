# 排序算法
## 运行
- 编译:make all
- 测试:make test
- 检测内存泄漏(需安装Valgrind):make valgrind
- 清理:make clean或make clean-all

## 约定
### 返回值
- 失败： -1或NULL
- 成功： 0
### 测试
- 测试数据位于./data下
- 测试数据第一个为待排序序列个数n，之后n个数字代表待排序序列长度，接着n行代表n个待排序序列