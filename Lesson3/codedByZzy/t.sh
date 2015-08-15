while true; do
   ./data
   ./zkwtree
   ./make
   if diff zkw.out zkw1.out; then
     echo "AC"
   else
	 echo "WA"
	 exit 0
   fi
done
