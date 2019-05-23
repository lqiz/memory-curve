#!/bin/sh
cPath=$HOME/coding
cd $cPath
h=3600
tpot=(0 $h `expr 12 \* $h` `expr 24 \* $h` `expr 48 \* $h` `expr 96 \* $h` `expr 168 \* $h` `expr 360 \* $h` 525600)

#use it for filter
files_array=()
function collectExisted() {
	for file in *.cpp *.md; do
		[ -f "$file" ] || break
		fname=`echo $file | awk -F'[.]' '{print $1}'`
		files_array[${#files_array[*]}]=$fname
	done
}

#collect file name existed.
collectExisted
cd $cPath/arc
collectExisted

function checkNotExisted() {
    for i in ${files_array[*]}; do
	    if [[ "$i" == "$1" ]]; then 
		    return
	    fi
    done
    return 200
}

# create revise files from dep by EH curve
now=`date +%s` 
cd $cPath/dep
for file in *.cpp *.md; do
    [ -f "$file" ] || break
    ctime=`stat -f %c $file`
    for idx in ${!tpot[@]}; do
	    eval $(echo $file | awk -F'[.]' '{printf("cfname=%s; sux=%s;", $1, $2);}')
	    if [[ $(($now-$ctime)) -lt ${tpot[$idx]} ]] 
	    then
		    if [ $idx -le 1 ]
		    then
			    # 0 1 不再生成。
			    continue
		    fi
		    #echo "interval is  "$(($now-$ctime))" pot is "$i" "${tpot[$i]}
	            ret=$(checkNotExisted $cfname-$idx)
		    if [[ $? == 200 ]]; then
			  echo "\033[31mHello ruiyi, pls redo $cfname \033[0m"
			  if [ "$sux" = "cpp" ]
			  then 
				  touch ../$cfname-$(($idx-1)).exp0.$sux
			  elif [ "$sux" = "md" ]
			  then
				  cp $file ../$cfname-$(($idx-1)).exp0.$sux
		          fi
		    fi
		    break
	    fi
     done 
done


cd $cPath
#update the expire time
for file in *.cpp *.md; do
    [ -f "$file" ] || break
    ctime=`stat -f %c $file`
    #name-1.exp0.cpp
    eval $(echo $file | awk -F'[.]' '{printf("fname=%s; exp=%s; sux=%s", $1,$2,$3);}')
    name=`echo $fname- | cut -d \- -f 1`
    ver=`echo $fname- | cut -d \- -f 2`
    # sort-1.exp0.cpp if -1 is not null and .exp0 is null, mv to arc 
    if [[ ! -z $ver ]] && [[ -z $sux ]]; then
	    mv $file ./arc
    fi
    #only exp0 is not null, we update it.
    if [[ $ver ]]; then
	   let duration=${tpot[$ver]}-${tpot[`expr $ver-1`]}
	   exp=$((($ctime-$now - $duration) / 60))
	   if [ $exp -gt 0  ]; then
		   mv $file $fname.exp$exp.$sux
		   file=$fname.exp$exp.$sux
	   fi
	   echo "\033[31m$file\033[0m"
    else
	   echo "\033[36m$file\033[0m"
    fi

done

