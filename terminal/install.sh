sudo apt install build-essential

echo
echo
echo

chmod +x ./main.bat
./main.bat


echo
echo
echo


make

sudo cp ./kst /usr/local/bin
echo "Intalling keystance editor..."
echo


cp -r help/ ~/kst/
echo "Creating the main directory for keystance"
echo


echo "Done... To run the program write kst [filepath]"
