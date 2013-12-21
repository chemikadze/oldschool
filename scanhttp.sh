i=1;
while [ $i -le 6 ];
do
	j=1;
	while [ $j -lt 254 ];
	do
		lynx 192.168.7$i.$j
		j=$[ $j + 1 ]
	done
	i=$[ $i + 1 ]
done;
