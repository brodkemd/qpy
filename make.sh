echo `pwd`"/"$1 > ~/Documents/C++/qpy/file_names.txt
echo "moving"
cur_dir=`pwd`
cd ~/Documents/C++/qpy/
echo "running"
./qpy
cd $cur_dir
