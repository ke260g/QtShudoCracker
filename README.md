# QtShudoCracker
Crack Shudo in Stupid Recursive Algorithm, written in Qt5

### Brief
+ After finished, not sure to succeeded
+ If the input maze is not valid, cracker may not detect smartly
+ Besides standard mode, supports another 4 types of shudo

### Screenshot
![Standard Type](screenshots/No.1-Standard-Type.png?raw=true "")

### Another 4 Types
+ X Type</br>
![X Type](screenshots/No.2-X-Type.png?raw=true "")
+ Color Type</br>
![Color Type](screenshots/No.3-Color-Type.png?raw=true "")
+ Hyper Type</br>
![Hyper Type](screenshots/No.4-Hyper-Type.png?raw=true "")
+ Percent Type</br>
![Percent Type](screenshots/No.5-Percent-Type.png?raw=true "")

### Development Details
+ class-`ShudoCracker` is only method that should not be instantiated
+ class-`ShudoCracker` can be used seperately in pure console program
+ each **input-number-box** is a QLineEdit without its QFrame
+ using QValidator to control user-input.
+ as QtDesign does not support widget-array,</br>
  then I bind the 9x9 **input-number-box** in c++ code with a ugly method.</br>
  see `scripts/bindMazeGUI.sh` and `MainWindow::bindMazeGUI`
