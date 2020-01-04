#ifndef FILEREADWRITE_H
#define FILEREADWRITE_H

#include <QMainWindow>

namespace Ui {
class FileReadWrite;
}

class CFileReadWrite : public QMainWindow
{
    Q_OBJECT

public:
    explicit CFileReadWrite(QWidget *parent = nullptr);
    ~CFileReadWrite();

private slots:
    void on_m_pbWrite_clicked();

    void on_m_pbRead_clicked();

    void on_m_pbSelectFile_clicked();

private:
    Ui::FileReadWrite *ui;
};

#endif // FILEREADWRITE_H
