sudo apt update && sudo apt upgrade
sudo apt install default-jre
sudo apt install default-jdk


echo "Installing c analyzer in Java"
chmod +x ./c_analyzer.sh
cp ./c_analyzer.sh /usr/local/bin


echo "\nDone...\n"
