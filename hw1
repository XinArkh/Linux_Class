#! /bin/bash
# filename:hw1
if (($#!=1)); then  # 双小括号(())可以在括号内直接使用逻辑符号，好处是不必
		    # 记忆逻辑表达式
	if (($#==0)); then
		echo "没有参数！"
	else
		echo "多个参数！分别是：$*"  # $*以一个字符串的形式输出所有位置
					     # 参数组成的字符串
	fi
else
	if test -f $1; then  # test -f $1测试文件属性，如果是普通文件则为真
		echo "所有者：$(ls --full-time $1 | awk '{print $3}')"  # ls在参数
		   # --full-time下输出文件详细信息，其中第三条和第六条是我们需要的
		   # ls的输出通过管道传送给awk，经过筛选分别输出所有者和修改时间
		echo "最后修改时间：$(ls --full-time $1 | awk '{print $6}')"
	fi
fi

