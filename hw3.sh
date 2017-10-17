#! /bin/bash
# filename:hw3
echo -n "您要输入几个整数？"
read num
# 简单粗暴地定义一个“最大值”max和“最小值”min
# 输入的数字在这个范围内是有效的
max=-999999999999999999999999
min=999999999999999999999999
sum=0
sort=()
i=1
while ((i<=num))
do
	sort[$i]=999999999999999999999999
	i=$((i+1))
done
i=1
# 完成num次until输入循环，每次输入一个整数，进行相应处理
until ((i>num))
do
	echo -n "请输入第$i个整数："
	read n
	# 获取最大值
	if ((n>max)); then
		max=$n
	fi
	# 获取最小值
	if ((n<min)); then
		min=$n
	fi
	# 获取总和
	sum=$((sum+n))
	#### 对输入的整数进行排序 ####
	j=1
	while ((j<=i))
	do
		if ((n<sort[$j])); then
			break
		fi
		j=$((j+1))
	done
	ii=$i
	while ((ii>j))
	do
		sort[$ii]=$((sort[$ii-1]))
		ii=$((ii-1))
	done
	sort[$j]=$n
	#############################
	i=$((i+1))
done
echo "最大值是"$max
echo "最小值是"$min
echo "总和为"$sum
echo -n "从小到大排序："${sort[*]}
echo
