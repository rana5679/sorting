#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Dataset_button_clicked()
{
    srand(time(NULL));
    size = (ui->Dataset_setting->toPlainText()).toInt();

    for(int i = 0; i<size; i++){
        nums[i]=QString::number(rand()%1000+1);
    }

    for(int i = 0; i<size; i++){
        ui->array_display->setText(ui->array_display->toPlainText()+'\n'+nums[i]);
    }

    ui-> status_edit->setText("The Dataset size: " +QString::number(size));
}


void MainWindow::on_Normal_button_clicked()
{
    bool found =false;
    int count=0;
    if (ui->Find_enter->toPlainText()==""){
        ui->status_edit->setText(ui->status_edit->toPlainText()+'\n'+"Please enter a number to find");
    }
    else
    {
        ui->status_edit->setText(ui->status_edit->toPlainText()+'\n'+"Using normal search...");

        while ( found == false && count<size)
        {
            if(nums[count]==ui->Find_enter->toPlainText()){
                 found = true;
                indexfound=QString::number(count);
            }
            count ++;
        }

   }
}


void MainWindow::on_Binary_button_clicked()
{


    int l,r;
    l = 0;
    r = size-1;
    bool flag=false;

    QString x= ui->Find_enter->toPlainText();

    if (x==""){
        ui->status_edit->setText(ui->status_edit->toPlainText()+'\n'+"Please enter a number to find");
    }
    else{
    while (l <= r) {
            int m = l + (r - l) / 2;
            if ((nums[m]).toInt() == x.toInt())
            {
                indexfound=QString::number(m);
                flag=true;
            }

            if ((nums[m]).toInt() < x.toInt())
                l = m + 1;
            else
                r = m - 1;
        }
    ui->status_edit->setText(ui->status_edit->toPlainText()+'\n'+"Using binary search...");
    }
}


void MainWindow::on_Find_button_clicked()
{
    if (indexfound==""){
        ui->status_edit->setText(ui->status_edit->toPlainText()+'\n'+"The number was not found OR no search was chosen.");
    }
    else {ui->status_edit->setText(ui->status_edit->toPlainText()+'\n'+"The number is at position " + indexfound + " in the array.");}
}


void MainWindow::on_STL_button_clicked()
{
    ui->array_display->setText("");

    sort(nums , nums + size );

    for(int i = 0; i<size; i++){
        ui->array_display->setText(ui->array_display->toPlainText()+"\n"+nums[i]);
    }
    ui->arrayState_label->setText("Sorted Array");

}

