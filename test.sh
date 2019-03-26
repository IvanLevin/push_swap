check=0
sred=0

if [ "$#" -lt 3 ]
then
	printf "usage: test.sh [-c] arg1 arg2 arg3\n"
	printf "       arg1 - start number\n"
	printf "       arg2 - finish number\n"
	printf "       arg3 - how many times run a test\n"
	printf "       -с   - start testing push_swap and checker programs\n"
	exit
fi

if [ "$1" = "-c" ]
then
    check=1
    from=$2
    to=$3
    count=$4
elif [ "$1" != "-c" ]
then
    from=$1
    to=$2
    count=$3
fi

let "dif = $to - $from + 1"

i=0
sp=( Loading. lOading.. loAding... loaDing.... loadIng..... loadiNg...... loadinG....... DONE)
echo ' '
printf "Loading"
for i in "${sp[@]}\n"
do
    printf "\r\033[K\033[32m$i\033[m"
    sleep 0.2
done

for ((i = 0; i < $count; i++))
do
ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"` ; res=$(./push_swap $ARG | wc -l)
if [ $dif -eq 100 ]
then
if [ $res -gt 1500 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   0️⃣  ❕  5️⃣  ❗️"
let "sred += $res"
elif [ $res -gt 1300 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   1️⃣  ❕  5️⃣     ✅"
let "sred += $res"
elif [ $res -gt 1100 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   2️⃣  ❕  5️⃣     ✅  ✅"
let "sred += $res"
elif [ $res -gt 900 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   3️⃣  ❕  5️⃣     ✅  ✅  ✅"
let "sred += $res"
elif [ $res -gt 700 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   4️⃣  ❕  5️⃣     ✅  ✅  ✅  ✅"
let "sred += $res"
elif [ $res -gt 0 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   5️⃣  ❕  5️⃣     ✅  ✅  ✅  ✅  ✅"
let "sred += $res"
fi
elif [ $dif -eq 500 ]
then
if [ $res -gt 11500 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   0️⃣  ❕  5️⃣  ❗️"
let "sred += $res"
elif [ $res -gt 10000 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   1️⃣  ❕  5️⃣     ✅"
let "sred += $res"
elif [ $res -gt 8500 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   2️⃣  ❕  5️⃣     ✅  ✅"
let "sred += $res"
elif [ $res -gt 7000 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   3️⃣  ❕  5️⃣     ✅  ✅  ✅"
let "sred += $res"
elif [ $res -gt 5500 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   4️⃣  ❕  5️⃣     ✅  ✅  ✅  ✅"
let "sred += $res"
elif [ $res -gt 0 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m   5️⃣  ❕  5️⃣     ✅  ✅  ✅  ✅  ✅"
let "sred += $res"
fi
elif [ $dif -eq 5 ]
then
if [ $res -gt 12 ]
then
echo "Test result on $from..$to randoms: \033[36m$res\033[m    ❌"
else
echo "Test result on $from..$to randoms: \033[36m$res\033[m    ✅"
fi
else
echo "Test result on $from..$to randoms: \033[36m$res\033[m"
fi
done

if [ $check -eq 1 ]
then
    echo "\n\t\t\tCHECKER TEST"
    echo "Error management:"
    printf "test 1: "
    if [ "$(printf '' | ./checker kek)" = "Error" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker (non numeric parameter) (instr: none)"
    fi
    printf "test 2: "
    if [ "$(printf '' | ./checker 1 2 3 4 5 6 7 8 1)" = "Error" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker (duplicate numeric parameter) (instr: none)"
    fi
    printf "test 3: "
    if [ "$(printf '' | ./checker 2147483648)" = "Error" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker MAX_INT+1(2147483648) (instr: none)"
    fi
    printf "test 4: "
    if [ "$(printf '' | ./checker -2147483649)" = "Error" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker MIN_INT-1(2147483649) (instr: none)"
    fi
    printf "test 5: "
    if [ "$(printf '' | ./checker )" = "" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker none (instr: none)"
    fi
    printf "test 6: "
    if [ "$(printf 'kek' | ./checker 4 1 2 )" = "Error" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker (action doesn't exist) (instr: none)"
    fi
    printf "test 7: "
    if [ "$(printf 'ra  ' | ./checker 4 1 2 )" = "Error" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker (action with two space after) (instr: none)"
    fi
    printf "test 8: "
    if [ "$(printf '  ra' | ./checker 4 1 2 )" = "Error" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker (action with two space before) (instr: none)"
    fi

    echo "\nFalse tests:"
    printf "test 1: "
    if [ "$(echo "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5)" = "KO" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 0 9 1 8 2 7 3 6 4 5 (instr: sa pb rrr)"
    fi
    printf "test 2: "
    if [ "$(printf "pb\nra\nsa\npa\nrb\nrrb\nrra" | ./checker 4 1 6 2 7 3)" = "KO" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 4 1 6 2 7 3 (instr: pb ra sa pa rb rrb rra)"
    fi

    echo "\nRight tests:"
    printf "test 1: "
    if [ "$(printf '' | ./checker 0 1 2)" = "OK" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 0 1 2 (instr: sa pb rrr)"
    fi
    printf "test 2: "
    if [ "$(printf "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker 0 9 1 8 2)" = "OK" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 0 9 1 8 2 (instr: pb ra pb ra sa ra pa pa)"
    fi

    echo "\nRandom tests:"
    printf "test 1: "
    if [ "$(echo "pb\npb" | ./checker 1 2 3 4 5)" = "KO" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 1 2 3 4 5 (instr: pb pb)"
    fi
    printf "test 2: "
    if [ "$(echo "ra\nra\nrra\nrra" | ./checker 1 2 3 4 5)" = "OK" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 1 2 3 4 5 (instr: ra ra rra rra)"
    fi

    echo "\n\t\t\tPUSH_SWAP TEST"
    echo "Identity test:"
    printf "test 1: "
    if [ "$(./push_swap 42)" = "" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 42 (should display nothing)"
    fi
    printf "test 2: "
    if [ "$(./push_swap 0 1 2 3)" = "" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 0 1 2 3 (should display nothing)"
    fi
    printf "test 3: "
    if [ "$(./push_swap 0 1 2 3 4 5 6 7 8 9)" = "" ]
    then
        echo "✅"
    else
        echo "❌  - ./checker 0 1 2 3 4 5 6 7 8 9 (should display nothing)"
    fi
fi

let "koef = $sred / $count"
echo "\n💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠\n"
if [ $dif -eq 100 ]
    then
    if [ $koef -gt 1300 ]
    then
    echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  0️⃣     ❗️"
    elif [ $koef -gt 1300 ]
    then
    echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  1️⃣     ✅"
    elif [ $koef -gt 1100 ]
    then
    echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  2️⃣     ✅  ✅"
    elif [ $koef -gt 900 ]
    then
    echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  3️⃣     ✅  ✅  ✅"
    elif [ $koef -gt 700 ]
    then
    echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  4️⃣      ✅  ✅  ✅  ✅"
    elif [ $koef -gt 0 ]
    then
    echo "Middle value: \033[33m$koef\033[m   Grade is :  5️⃣      ✅  ✅  ✅  ✅  ✅"
    fi
elif [ $dif -eq 500 ]
    then
        if [ $koef -gt 11500 ]
        then
        echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  0️⃣     ❗️"
        elif [ $koef -gt 10000 ]
        then
        echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  1️⃣     ✅"
        elif [ $koef -gt 8500 ]
        then
        echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  2️⃣     ✅  ✅"
        elif [ $koef -gt 7000 ]
        then
        echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  3️⃣     ✅  ✅  ✅"
        elif [ $koef -gt 5500 ]
        then
        echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  4️⃣      ✅  ✅  ✅  ✅"
        elif [ $koef -gt 0 ]
        then
        echo "\nMiddle value: \033[33m$koef\033[m   Grade is :  5️⃣      ✅  ✅  ✅  ✅  ✅"
        fi
fi

leak=$(valgrind ./push_swap $ARG 2>&1 | grep "definitely lost" | cut -d ':' -f2 | cut -d ' ' -f2)
heap=$(valgrind ./push_swap $ARG 2>&1 | grep "heap usage" | cut -d ':' -f2 | cut -d ' ' -f2 | cut -d "," -f1)

if [ $heap -gt 0 ]
then
    if [ $leak -gt 0 ]
    then
    echo "Leaks: \033[31m$leak\033[m byte(s)"
    else
    echo "Leaks: \033[32m0\033[m bytes"
    fi
else
echo "Leaks: \033[31mvalgrind is unable, check your Makefile or SDL/MLX compilers\033[m"
fi
echo "\n💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠"



