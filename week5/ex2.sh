while :
do
err=$(ln text.txt text.txt.lock 2>&1)
if [[ "$err" == "" ]]; then
echo $(($(tail -1 "text.txt") + 1)) >> text.txt
wait
rm text.txt.lock
fi
done
