package ru.mtplab;

import jssc.SerialPort;
import jssc.SerialPortList;
import ru.mtplab.gui.ManagerGUI;

import javax.swing.*;


public class Main {

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ManagerGUI();
            }
        });
    }
}
