while true; do   # 注释
    ./makeI    # 运行数据生成器
    ./I        #运行要提交的程序
    ./checkI   # 运行暴力检查程序
    if diff iq.out iqstd.out; then # 比较
        echo "AC"
    else
        echo "WA"
        exit 0
    fi
done
