#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_qBtnStart_clicked();

    void on_qBtnReest_clicked();

    void on_qCBoxMazeType_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QLineEdit *MazeGUI[9][9];
    void bindMazeGUI();
    void initMazeGUI();
    void getMazeGUI(int (&maze)[9][9]);
    void setMazeGUI(const int (&maze)[9][9]);

    int getMazeType();
    void setMazeType();
};

#endif // MAINWINDOW_H
