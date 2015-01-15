package ru.mtplab.logic;

import jssc.SerialPort;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;

import java.util.ArrayList;

public class ComPort {
    private SerialPort serialPort;
    private ArrayList<ComObserver> comObservers;
    private String readyRecieveString;

    /**
     * Конструктор ComPort. Конфигурирует и устанавливает соединение с портом.
     * @param port Название порта(COM3, COM1)
     */
    public ComPort(String port) {
        comObservers = new ArrayList<ComObserver>();
        serialPort = new SerialPort(port);
        try {
            serialPort.openPort();
            serialPort.setParams(SerialPort.BAUDRATE_115200,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);
            serialPort.addEventListener(new PortReader(), SerialPort.MASK_RXCHAR);
            System.out.println("Create ComPort '" + port + "'");
        } catch (SerialPortException ex) {
            System.out.println("Create SerialPort Failed...");
            ex.printStackTrace();
        }
    }

    /**
     * Запись строки в Com порт.
     * @param query Строка для записи
     */
    public void write(String query) {
        try {
            serialPort.writeString(query);
        } catch (SerialPortException ex) {
            ex.printStackTrace();
        }
    }


    //Оповещение наблюдателей с передачей сформированной строки.
    public void notification() {
        for (ComObserver obs : comObservers) {
            obs.onComRecieve(readyRecieveString);
        }
    }

    /**
     * Добавить наблюдателя в список для последующего оповещения
     * @param obs Наблюдатель
     */
    public void addComListener(ComObserver obs) {
        comObservers.add(obs);
    }

    /**
     * Класс PortReader. Необходим для прослушки порта.
     */
    private class PortReader implements SerialPortEventListener {
        public void serialEvent(SerialPortEvent event) {
            if (event.isRXCHAR() && event.getEventValue() > 0) {
                try {
                    String data = serialPort.readString(event.getEventValue());
                    readyRecieveString += data;
                    if (readyRecieveString.contains("\n")) {
                        notification();
                        readyRecieveString = "";
                    }
                } catch (SerialPortException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }
}
