#! /usr/bin/bash
arr=($(ps -axo pid | tail -n +2 | xargs))
vmsize=$((0))
vmrss=$((0))
for str in ${arr[@]}; do
   size=$(cat /proc/$str/status 2>errors.txt | egrep 'VmSize' | egrep -o '[0-9]+')
   rss=$(cat /proc/$str/status 2>errors.txt | egrep 'VmRSS' | egrep -o '[0-9]+')
   vmsize=$((vmsize+$((size))))
   vmrss=$((vmrss+$((rss))))
done

echo "Vmsize: $((vmsize))"
echo "Vmrss: $((vmrss))"
