# QFile_QTextStream_QDataStream
Text/ Binary data reading and writing to file using QTextStream/ QDataStream

QFile -  (core module)
-----
QIODevice  <- QObject (https://doc.qt.io/qt-5/qiodevice.html)
QFileDevice  <- QIODevice (https://doc.qt.io/qt-5/qfiledevice.html)
QFile / QSaveFile  <- QFileDevice(https://doc.qt.io/qt-5/qfile.html / https://doc.qt.io/qt-5/qsavefile.html)
QTemporaryFile  <- QFile(https://doc.qt.io/qt-5/qtemporaryfile.html)
QTextStream (https://doc.qt.io/qt-5/qtextstream.html)
QDataStream (https://doc.qt.io/qt-5/qdatastream.html)
QFileInfo (https://doc.qt.io/qt-5/qfileinfo.html)
QDir(https://doc.qt.io/qt-5/qdir.html)

QObject:
----------
https://doc.qt.io/qt-5/threads-reentrancy.html
https://doc.qt.io/qt-5/qobject.html
The QObject class is the base class of all Qt objects.
QObject is the heart of the Qt Object Model. (https://sourcemaking.com/design_patterns/observer)
The central feature in this model is a very powerful mechanism for seamless object communication called signals and slots. 

QIODevice:
----------
The QIODevice class is the base interface class of all I/O devices in Qt.
QAbstractSocket, QBuffer, QFileDevice, QLocalSocket, QNetworkReply, and QProcess Inherited By QIODevice

QFileDevice:
-----------
The QFileDevice class provides an interface for reading from and writing to open files

QFile:
-----
The QFile class provides an interface for reading from and writing to files.

QFile is an I/O device for reading and writing text and binary files and resources. A QFile may be used by itself or, more conveniently, with a QTextStream or QDataStream.

The file name is usually passed in the constructor, but it can be set at any time using setFileName(). QFile expects the file separator to be '/' regardless of operating system. The use of other separators (e.g., '\') is not supported.

You can check for a file's existence using exists(), and remove a file using remove(). (More advanced file system related operations are provided by QFileInfo and QDir.)

The file is opened with open(), closed with close(), and flushed with flush(). Data is usually read and written using QDataStream or QTextStream, but you can also call the QIODevice-inherited functions read(), readLine(), readAll(), write(). QFile also inherits getChar(), putChar(), and ungetChar(), which work one character at a time.

The size of the file is returned by size(). You can get the current file position using pos(), or move to a new file position using seek(). If you've reached the end of the file, atEnd() returns true.

QSaveFile:
-----------
The QSaveFile class provides an interface for safely writing to files. 

QTemporaryFile:
----------------
The QTemporaryFile class is an I/O device that operates on temporary files.

QTextStream:
-------------
The QTextStream class provides a convenient interface for reading and writing text. 

QDataStream:
--------------
The QDataStream class provides serialization of binary data to a QIODevice.

QFileInfo:
-----------
The QFileInfo class provides system-independent file information. 

QDir:
-----
The QDir class provides access to directory structures and their contents. 

qDebug() is used for writing custom debug output.

qInfo() is used for informational messages.

qWarning() is used to report warnings and recoverable errors in your application.

qCritical() is used for writing critical error messages and reporting system errors.

qFatal() is used for writing fatal error messages shortly before exiting.

----------
