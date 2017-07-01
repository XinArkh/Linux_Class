#! /bin/bash
# filename:hw2
if (($#!=1)); then  # 双小括号(())可以在括号内直接使用逻辑符号，好处是不必
		    # 记忆逻辑表达式
	echo "参数输入错误！"
else
	# 用find找出各条件下符合的文件/文件夹个数，一行一个，然后用管道
	# 传入wc计数，有多少行就有多少个符合条件的文件/文件夹
	echo "普通文件："$(find $1 -type f | wc -l)  # $1需要放在控制符之前
	echo "目录文件："$(find $1 -type d | wc -l)  # 否则会报错，原因未知
	echo "可执行文件："$(find $1 -type f -executable | wc -l)
	
fi

