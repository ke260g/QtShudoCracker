# QtShudoCracker
Crack Shudo in Stupid Recursive Algorithm, written in Qt5
![Standard Type](screenshots/No.1 Standard Type.png?raw=true "")

### Brief
+ After finished, not sure to succeeded
+ If the input maze is not valid, cracker may not detect smartly
+ Besides standard mode, supports another 4 types of shudo

### Another 4 Types
![X Type](screenshots/No.2\ X\ Type.png)
![Color Type](screenshots/No.3\ Color\ Type.png)
![Hyper Type](screenshots/No.4\ Hyper\ Type.png)
![Percent Type](screenshots/No.5\ Percent\ Type.png)

### Development Details
+ class-`ShudoCracker` is only method that should not be instantiated
+ class-`ShudoCracker` can be used seperately in pure console program
+ each input-number-box is a QLineEdit without its QFrame
+ as QtDesign does not support widget-array,</br>
  then I bind the 9x9 input-number-box in c++ code with a ugly method.</br>
  see scripts/bindMazeGUI.sh and MainWindow::bindMazeGUI
