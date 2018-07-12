#pragma once

#include <QToolBar>
#include "Cutter.h"
#include <QTemporaryFile>

class MainWindow;

class DebugToolbar : public QToolBar
{
    Q_OBJECT

public:
    explicit DebugToolbar(MainWindow *main, QWidget *parent = nullptr);

private:
    MainWindow *main;
    QAction *actionStart;
    QAction *actionStartEmul;
    QTemporaryFile *stdin = nullptr;
    QTemporaryFile *stdout = nullptr;
    QTemporaryFile *stderr = nullptr;

private slots:
    void continueUntilMain();
    void colorToolbar(bool p);
    void attachProcessDialog();
    void attachProcess(int pid);
    void printStdout();
    void printStderr();
};