g++ -std=c++20 -o 标准 A1026-AC.cpp
g++ -std=c++20 -o 测试 A1026.cpp
g++ -std=c++20 -o 数据 A1026-Data.cpp

while true; do
	./数据 >in.txt                  # 出数据
	./测试 <in.txt >out.txt         # 被测程序
	./标准 <in.txt >std.txt         # 正确（暴力）程序
	if diff out.txt std.txt; then # 比较两个输出文件
		printf "AC\n"                # 结果相同显示AC
	elif diff -B -b out.txt std.txt; then
		printf "PE\n"
	else
		printf "WA\n" # 结果不同显示WA，并退出
		exit 0
	fi
done
