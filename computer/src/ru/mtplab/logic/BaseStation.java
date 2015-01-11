package ru.mtplab.logic;

/**
 * Created by Артем on 11.01.2015.
 */
public class BaseStation {
    private ComPort port;

    public BaseStation() {
    }

    public void setComPort(String portName) {
        port = new ComPort(portName);
    }

    public ComPort getPort() {
        return port;
    }
}
