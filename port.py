import serial
import xlrd
from os import startfile
from numpy import zeros
from pyautogui import click
from pygetwindow import getWindowsWithTitle
from keyboard import press_and_release
from time import sleep


def readExcel(loc):
    workbook = xlrd.open_workbook(loc)
    worksheet = workbook.sheet_by_name('1')
    dataMatrix = zeros(((worksheet.nrows - 1), 7))

    x = 0
    for row in range(1, worksheet.nrows):
        y = 0
        for col in range(2, 8):
            dataMatrix[x][y] = worksheet.cell(row, col).value
            y +=1
        if row > 1:
            dataMatrix[x][6] = worksheet.cell(row, 1).value - worksheet.cell((row - 1), 1).value
        x +=1

    return dataMatrix


def serialCom(loc, com):
    ser = serial.Serial()
    ser.baudrate = 115200
    ser.port = com
    ser.open()
    matrix = readExcel(loc)
    count = 0
    for i in matrix:
        for j in range(6):
            if int(i[j]) == 1:
                ser.write(1111)
            elif int(i[j]) == 0:
                ser.write(0000)
        count +=1
        if count == 2:
            break
    return 0


def startMovie(videoLoc):
    startfile(videoLoc)
    sleep(0.5)
    getWindowsWithTitle(videoLoc)[0].activate()
    press_and_release('space')
    click(1000,500)
    click(1000,500)
    press_and_release("space")

spreadsheet = "data.xls"
serialCom(spreadsheet, 'COM9')