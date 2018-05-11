# QtShudoCracker
Crack Shudo in Stupid Recursive Algorithm, written in Qt5
### Brief
+ After finished, not sure to succeeded
+ If the input maze is not valid, cracker may not detect smartly
+ Besides standard mode, supports another 4 types of shudo

### Development Details
+ class-`ShudoCracker` is only method that should not be instantiated
+ class-`ShudoCracker` can be used seperately in pure console program
+ each input-number-box is a QLineEdit without its QFrame
+ as QtDesign does not support widget-array,</br>
  then I bind the 9x9 input-number-box in c++ code with a ugly method.</br>
  see scripts/bindMazeGUI.sh and MainWindow::bindMazeGUI
