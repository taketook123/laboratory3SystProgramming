#include "mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <fstream>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setStyleSheet("background-color: lightblue;");
    QLabel *descriptionLabel = new QLabel("Laboratory 3. IO-11 Khusainov Dmytro", this);
    QPushButton *createButton = new QPushButton("Create Repair", this);
    QPushButton *displayButton = new QPushButton("Display Repair", this);
    QPushButton *markDoneButton = new QPushButton("Mark Repair Done", this);
    QPushButton *displayBreakCodeButton = new QPushButton("Save Repairs To File", this);



    // Встановлюємо макет для розміщення віджетів
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(descriptionLabel);
    layout->addWidget(createButton);
    layout->addWidget(displayButton);
    layout->addWidget(markDoneButton);
    layout->addWidget(displayBreakCodeButton);


    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Підключаємо сигнали до слотів
    connect(createButton, &QPushButton::clicked, this, &MainWindow::on_pushButtonCreateRepair_clicked);
    connect(displayButton, &QPushButton::clicked, this, &MainWindow::on_pushButtonDisplayRepair_clicked);
    connect(markDoneButton, &QPushButton::clicked, this, &MainWindow::on_pushButtonMarkRepairDone_clicked);
    connect(displayBreakCodeButton, &QPushButton::clicked, this, &MainWindow::on_pushButtonDisplayBreakCode_clicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_pushButtonCreateRepair_clicked()
{
    int breakCode = QInputDialog::getInt(this, "Enter Break Code", "Break Code:", 100, 100, 600);
    QString modelCode = QInputDialog::getText(this, "Enter Model Code", "Model Code:");
    QString description = QInputDialog::getText(this, "Enter Description", "Description:");
    QString symptoms = QInputDialog::getText(this, "Enter Symptoms", "Symptoms:");
    QString methods = QInputDialog::getText(this, "Enter Methods", "Methods:");
    QString scrapCode1 = QInputDialog::getText(this, "Enter 1st Detail Serial Number", "1st Detail Serial Number:");
    QString scrapCode2 = QInputDialog::getText(this, "Enter 2nd Detail Serial Number", "2nd Detail Serial Number:");
    QString scrapCode3 = QInputDialog::getText(this, "Enter 3rd Detail Serial Number", "3rd Detail Serial Number:");
    int price = QInputDialog::getInt(this, "Enter Repair Price", "Price:");

    repair.setBreakCode(breakCode);
    repair.setModelCode(modelCode.toStdString());
    repair.setDescription(description.toStdString());
    repair.setSymptoms(symptoms.toStdString());
    repair.setMethods(methods.toStdString());
    repair.setScrapCode1(scrapCode1.toStdString());
    repair.setScrapCode2(scrapCode2.toStdString());
    repair.setScrapCode3(scrapCode3.toStdString());
    repair.setPrice(price);

    repairs.push_back(repair);
}

void MainWindow::on_pushButtonDisplayRepair_clicked()
{
    QString data; // змінна для збереження стрококвих даних
    for (const Repair& repair : repairs) {
        data += QString::fromStdString(repair.get_data_for_file().c_str()) + "\n";
    }

    QMessageBox::information(this, "Repair Data", data);
}

void MainWindow::on_pushButtonMarkRepairDone_clicked()
{
    int targetBreakCode = QInputDialog::getInt(this, "Enter Break Code", "Break Code:");

    // Перебор списка repairs
    for (Repair& repair : repairs) {
        if (repair.get_break_code() == targetBreakCode) {
            // Потрібний об'єкт знайдено
            repair.setDone(true);
            QMessageBox::information(this, "Repair Marked Done", "Repair marked as done.");
            return; // Завершуємо пошук так як об'єкт знайдено
        }
    }

    QMessageBox::warning(this, "Repair Not Found", "Repair with the specified Break Code not found.");
}

void MainWindow::on_pushButtonDisplayBreakCode_clicked()
{
    std::ofstream file("repairs.txt");
    if (file.is_open()) {
        for (const Repair& repair : repairs) {
            file << repair.get_data_for_file(); // Запис даних у файл
        }
        file.close();
        QMessageBox::information(this, "Data Exported", "Data exported to 'repairs.txt'");
    } else {
        QMessageBox::warning(this, "File Error", "Unable to open 'repairs.txt' for writing.");
    }
}

