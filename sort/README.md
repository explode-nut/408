# 排序算法
> 考研涉及到的中排序算法的实现
## 已实现算法
- quick sort
- merge sort
- insrt sort

## 运行
- $编译$ :make all
- $测试$ :make test
- $检测内存泄漏(需安装Valgrind)$ :make valgrind
- $清理$ :make clean或make clean-all

## 约定
### 返回值
- $失败$ ： -1或NULL
- $成功$ ： 0
### 测试
- 测试数据位于./data下
- data中第一个数字为待排序序列个数n，之后n个数字代表待排序序列长度length，接着n行代表n个待排序序列
- 修改测试数据需要修改三项。即待排序序列个数n，待排序序列长度length，待排序序列
### 命名规范
- 测试文件需以源文件名后跟_test命名，例如源文件为quick_sort.c，测试文件必须命名为quick_sort_test.c
