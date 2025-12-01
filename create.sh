day=$1

if [ "$1" -lt "10" ]; then
	dir="day0$day"
else
	dir="day$day"
fi

cp -r template/ $dir/
cd $dir
curl --cookie "session=$AOC_SESSION" "https://adventofcode.com/2025/day/${day}" | html2markdown > README.md
cd input
curl --cookie "session=$AOC_SESSION" "https://adventofcode.com/2025/day/${day}/input" > input.txt
