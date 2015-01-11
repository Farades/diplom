package ru.mtplab.logic;

import jssc.SerialPort;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;

public class ComPort {
    private SerialPort serialPort;

    public ComPort(String port) {
        serialPort = new SerialPort(port);
        try {
            serialPort.openPort();
            serialPort.setParams(SerialPort.BAUDRATE_115200,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);
            serialPort.addEventListener(new PortReader(), SerialPort.MASK_RXCHAR);
            System.out.println("Create ComPort '" + port + "'");
            serialPort.writeString("DID=1;CMD=1;VAL=0");
        } catch (SerialPortException ex) {
            System.out.println("Create SerialPort Failed...");
            ex.printStackTrace();
        }
    }

    public void write(String query) {
        try {
            serialPort.writeString(query);
        } catch (SerialPortException ex) {
            ex.printStackTrace();
        }

    }

    private class PortReader implements SerialPortEventListener {
        public void serialEvent(SerialPortEvent event) {
            if (event.isRXCHAR() && event.getEventValue() > 0) {
                try {
                    Thread.sleep(10);
                    String data = serialPort.readString(event.getEventValue());
                    System.out.print("[BS]: " + data);
                } catch (SerialPortException ex) {
                    ex.printStackTrace();
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }
}
