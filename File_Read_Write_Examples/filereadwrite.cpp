#include "filereadwrite.h"
#include "ui_filereadwrite.h"
#include <QFile>
#include <QDir>
#include <QDataStream>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>
#include <QByteArray>

CFileReadWrite::CFileReadWrite(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileReadWrite)
{
    ui->setupUi(this);
}

CFileReadWrite::~CFileReadWrite()
{
    delete ui;
}

void CFileReadWrite::on_m_pbWrite_clicked()
{
   QString strData=ui->m_teDataWriteToFIle->toPlainText();

   if(strData.isEmpty())
   {
    QMessageBox::warning(this,"Alert", "Data is empty");
    return;
   }

   QString strFileName=ui->m_leWriteFileName->text();

   if(strFileName.isEmpty())
   {
    QMessageBox::warning(this,"Alert", "Filename is empty");
    return;
   }

   QFileInfo fileInfo(strFileName);
   if(fileInfo.completeSuffix() != "txt")
   {
        strFileName.append(".txt");
   }

   QFile file(QDir::currentPath()+"/"+strFileName);
   if(file.open(QFile::WriteOnly))
   {
      qInfo() << "file opened for writing" << endl;

      int nDataType=ui->m_cmbxWriteDataSaveType->currentIndex();
      if(0 == nDataType)//text format
      {
        QTextStream txtStr(&file);
        txtStr << strData;
      }else
      {
          QDataStream dataStr(&file);
          dataStr << strData;
      }
      file.close();
      QMessageBox::information(this,"Information", "File saved successfully at "+QDir::currentPath()+"/"+strFileName );
   }else
   {
       QMessageBox::critical(this,"Fatal Error", "Unable to open file to write data." );

   }


}

void CFileReadWrite::on_m_pbRead_clicked()
{
    QString strReadFileName=ui->m_leReadFileName->text();
    if(strReadFileName.isEmpty())
    {
        QMessageBox::warning(this,"Alert", "Filename is empty.");
        return;
    }

    QFile file(strReadFileName);
    if(file.open(QFile::ReadOnly))
    {
        qInfo() << "file opened for reading" << endl;

        int nDataType=ui->m_cmbxReadDataSaveType->currentIndex();

        QString strData;
        if(0 == nDataType)//text format
        {

              QTextStream txtStr(&file);
              strData = txtStr.readAll();


        }else
        {
                QByteArray ba;
                QDataStream dataStr(&ba,QFile::ReadWrite);
                dataStr <<  file.readAll();
                strData = ba.toHex();

        }

        ui->m_teDataReadFromFile->setPlainText(strData);

        file.close();
        QMessageBox::information(this,"Information", "File read successfully from "+strReadFileName );


    }else
    {
        QMessageBox::critical(this,"Fatal Error", "Unable to open file to read data" );

    }
}

void CFileReadWrite::on_m_pbSelectFile_clicked()
{
    QString selectedFileName = QFileDialog::getOpenFileName(this,
        tr("Select text file"), QDir::currentPath(), tr("Text Files (*.txt)"));

    if(selectedFileName.isEmpty())
    {
        QMessageBox::warning(this,"Alert", "Filename is empty");
        return;
    }
    ui->m_leReadFileName->setText(selectedFileName);
}
