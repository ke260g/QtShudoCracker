#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include "shudocracker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bindMazeGUI();
    initMazeGUI();

    setMazeType();

    // this is demo, std type
    int maze[9][9] = {
        {4, 0, 9, 5, 0, 8, 7, 0, 3},
        {5, 6, 0, 0, 9, 1, 0, 8, 4},
        {0, 0, 8, 6, 0, 0, 0, 0, 0},
        {9, 0, 0, 4, 0, 6, 8, 0, 0},
        {2, 8, 0, 0, 0, 0, 0, 1, 9},
        {0, 0, 1, 2, 0, 9, 0, 0, 5},
        {0, 0, 0, 0, 0, 5, 4, 0, 0},
        {1, 4, 0, 8, 3, 0, 0, 9, 6},
        {8, 0, 6, 9, 0, 4, 1, 0, 2},
    };
    setMazeGUI(maze);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::bindMazeGUI() {
    MazeGUI[0][0] = ui->box00;
    MazeGUI[0][1] = ui->box01;
    MazeGUI[0][2] = ui->box02;
    MazeGUI[0][3] = ui->box03;
    MazeGUI[0][4] = ui->box04;
    MazeGUI[0][5] = ui->box05;
    MazeGUI[0][6] = ui->box06;
    MazeGUI[0][7] = ui->box07;
    MazeGUI[0][8] = ui->box08;
    MazeGUI[1][0] = ui->box10;
    MazeGUI[1][1] = ui->box11;
    MazeGUI[1][2] = ui->box12;
    MazeGUI[1][3] = ui->box13;
    MazeGUI[1][4] = ui->box14;
    MazeGUI[1][5] = ui->box15;
    MazeGUI[1][6] = ui->box16;
    MazeGUI[1][7] = ui->box17;
    MazeGUI[1][8] = ui->box18;
    MazeGUI[2][0] = ui->box20;
    MazeGUI[2][1] = ui->box21;
    MazeGUI[2][2] = ui->box22;
    MazeGUI[2][3] = ui->box23;
    MazeGUI[2][4] = ui->box24;
    MazeGUI[2][5] = ui->box25;
    MazeGUI[2][6] = ui->box26;
    MazeGUI[2][7] = ui->box27;
    MazeGUI[2][8] = ui->box28;
    MazeGUI[3][0] = ui->box30;
    MazeGUI[3][1] = ui->box31;
    MazeGUI[3][2] = ui->box32;
    MazeGUI[3][3] = ui->box33;
    MazeGUI[3][4] = ui->box34;
    MazeGUI[3][5] = ui->box35;
    MazeGUI[3][6] = ui->box36;
    MazeGUI[3][7] = ui->box37;
    MazeGUI[3][8] = ui->box38;
    MazeGUI[4][0] = ui->box40;
    MazeGUI[4][1] = ui->box41;
    MazeGUI[4][2] = ui->box42;
    MazeGUI[4][3] = ui->box43;
    MazeGUI[4][4] = ui->box44;
    MazeGUI[4][5] = ui->box45;
    MazeGUI[4][6] = ui->box46;
    MazeGUI[4][7] = ui->box47;
    MazeGUI[4][8] = ui->box48;
    MazeGUI[5][0] = ui->box50;
    MazeGUI[5][1] = ui->box51;
    MazeGUI[5][2] = ui->box52;
    MazeGUI[5][3] = ui->box53;
    MazeGUI[5][4] = ui->box54;
    MazeGUI[5][5] = ui->box55;
    MazeGUI[5][6] = ui->box56;
    MazeGUI[5][7] = ui->box57;
    MazeGUI[5][8] = ui->box58;
    MazeGUI[6][0] = ui->box60;
    MazeGUI[6][1] = ui->box61;
    MazeGUI[6][2] = ui->box62;
    MazeGUI[6][3] = ui->box63;
    MazeGUI[6][4] = ui->box64;
    MazeGUI[6][5] = ui->box65;
    MazeGUI[6][6] = ui->box66;
    MazeGUI[6][7] = ui->box67;
    MazeGUI[6][8] = ui->box68;
    MazeGUI[7][0] = ui->box70;
    MazeGUI[7][1] = ui->box71;
    MazeGUI[7][2] = ui->box72;
    MazeGUI[7][3] = ui->box73;
    MazeGUI[7][4] = ui->box74;
    MazeGUI[7][5] = ui->box75;
    MazeGUI[7][6] = ui->box76;
    MazeGUI[7][7] = ui->box77;
    MazeGUI[7][8] = ui->box78;
    MazeGUI[8][0] = ui->box80;
    MazeGUI[8][1] = ui->box81;
    MazeGUI[8][2] = ui->box82;
    MazeGUI[8][3] = ui->box83;
    MazeGUI[8][4] = ui->box84;
    MazeGUI[8][5] = ui->box85;
    MazeGUI[8][6] = ui->box86;
    MazeGUI[8][7] = ui->box87;
    MazeGUI[8][8] = ui->box88;
}

void MainWindow::initMazeGUI() {
    QRegExp rx("[1-9]");
    QValidator *validator = new QRegExpValidator(rx, this);

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j ) {
            QLineEdit * each = MazeGUI[i][j];
            each->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            each->setFrame(false);
            each->setValidator(validator);
        }
    }
}

void MainWindow::getMazeGUI(int (&maze)[9][9]) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            int value = MazeGUI[i][j]->text().toInt();
            if(1 <= value && value <= 9)
                maze[i][j] = value;
            else
                maze[i][j] = 0;
        }
    }
}

void MainWindow::setMazeGUI(const int (&maze)[9][9]) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            int value = maze[i][j];
            if(1 <= value && value <= 9)
                MazeGUI[i][j]->setText(QString::asprintf("%d", maze[i][j]));
            else
                MazeGUI[i][j]->setText("");
        }
    }
}

int MainWindow::getMazeType() {
    QString StrMazeType = ui->qCBoxMazeType->currentText();
    for(unsigned int i = 0; i < ShudoCracker::mazeTypes.size(); ++i) {
        if(StrMazeType == QString::fromStdString(ShudoCracker::mazeTypes[i]))
            return i;
    }
    return -1;
}

void MainWindow::setMazeType() {
    for(const auto elem : ShudoCracker::mazeTypes)
        ui->qCBoxMazeType->addItem(QString::fromStdString(elem));
}

void MainWindow::on_qBtnStart_clicked() {
    int src_maze[9][9];
    int dst_maze[9][9];
    getMazeGUI(src_maze);
    bool retval;
    int mazeType = getMazeType();

    if(mazeType >= 0) {
        retval = ShudoCracker::crack(src_maze, dst_maze, mazeType);
        if(retval) {
            setMazeGUI(dst_maze);
            QMessageBox msgBox;
            msgBox.setText("Finish but not sure to be succeeded");
            msgBox.exec();
        }
    }
}

void MainWindow::on_qBtnReest_clicked()
{
    int maze[9][9];
    memset(maze, 0, sizeof(int)*9*9);
    setMazeGUI(maze);
}

void MainWindow::on_qCBoxMazeType_currentIndexChanged(int index) {
    QPalette palNormal;
    palNormal.setColor(QPalette::Base, QColor(Qt::white));
    QPalette palX;
    palX.setColor(QPalette::Base, QColor(Qt::cyan));

    QColor color[9] = {
        QColor(Qt::white),
        QColor(192, 239, 255),
        QColor(Qt::yellow),
        QColor(Qt::cyan),
        QColor(171, 130, 255),
        QColor(Qt::green),
        QColor(Qt::magenta),
        QColor(255, 62, 150),
        QColor(255, 165, 0),
    };
    QPalette palColors[9];
    for(int i = 0; i < 9; ++i) {
        palColors[i].setColor(QPalette::Base,
                              color[i]);
    }

    switch(index) {
    case ShudoCracker::mazeTypeStd:
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j) {
                QLineEdit *each = MazeGUI[i][j];
                each->setPalette(palNormal);
                each->update();
            }
        break;
    case ShudoCracker::mazeTypeX:
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j) {
                QLineEdit *each = MazeGUI[i][j];
                if(i == j) {
                    each->setPalette(palX);
                } else if (i + j == 8){
                    each->setPalette(palX);
                } else {
                    each->setPalette(palNormal);
                }
                each->update();
            }
        break;
    case ShudoCracker::mazeTypeColor:
        for(int n = 0; n < 7;  n += 3) {
            for(int m = 0; m < 7; m += 3) {
                for(int i = 0; i < 3; ++i)
                    for(int j = 0; j < 3; ++j) {
                        QLineEdit * each = MazeGUI[i+n][j+m];
                        each->setPalette(palColors[i*3 + j]);
                    }
            }
        }
        break;
    case ShudoCracker::mazeTypeHyper:
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j) {
                QLineEdit *each = MazeGUI[i][j];
                if((j != 0) && (j != 4) && (j != 8) \
                        && (i != 0) && (i != 4) && (i != 8)) {
                    if(((j - 1)/3 == 0) || ((j + 1)/3 == 2) \
                            || ((i - 1)/3 == 0) || ((i + 1)/3 == 2)) {
                        each->setPalette(palX);
                    } else {
                        each->setPalette(palNormal);
                    }
                } else {
                    each->setPalette(palNormal);
                }
                each->update();
            }

        break;
    case ShudoCracker::mazeTypePercent:
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j) {
                QLineEdit *each = MazeGUI[i][j];
                if(i + j == 8)
                    each->setPalette(palX);
                else if((j != 0) && (j != 4) && (j != 8) \
                        && (i != 0) && (i != 4) && (i != 8)) {
                    if((((j - 1)/3 == 0) && ((i - 1)/3 == 0)) \
                            || (((j + 1)/3 == 2) && ((i + 1)/3 == 2))) {
                        each->setPalette(palX);
                    } else {
                        each->setPalette(palNormal);
                    }
                } else
                    each->setPalette(palNormal);
                each->update();
            }
        break;
    }
}
