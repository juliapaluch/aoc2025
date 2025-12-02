day=$1

if [ "$1" -lt "10" ]; then
	dir="day0$day"
else
	dir="day$day"
fi

cp -r template/ $dir/
curl --cookie "session=$AOC_SESSION" "https://adventofcode.com/2025/day/${day}" | html2markdown > $dir/DIRECTIONS.md
curl --cookie "session=$AOC_SESSION" "https://adventofcode.com/2025/day/${day}/input" > $dir/input/input.txt
