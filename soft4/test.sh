#!/bin/bash

#运行方式：./test.sh program txt      
#program为所需测试的程序名  txt 为该程序所需的输入
#输出：程序所需的输入个数
result=0
num=(`cat $2 | sed "s/ /\n/g"`)
echo ${num[*]}
timeout 1 $1 >/dev/null 2>&1
if [ $? == 124 ];then
	result=1
fi
for (( i=1;i<=${#num[*]};i++))
	do 
		echo ${num[@]:0:$i} > tmp.txt 
		timeout 1 $1 < tmp.txt >/dev/null 2>&1
		echo "result:$?"
		if [ $? == 124 ];then
	        result=`expr $i + 1`
			echo "result=$result"
        fi
	done
rm tmp.txt
echo $result
