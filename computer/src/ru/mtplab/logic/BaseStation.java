package ru.mtplab.logic;

import java.util.ArrayList;

/**
 * Created by Артем on 11.01.2015.
 */
public class BaseStation implements ComObserver {
    private ArrayList<Drone> drones;
    private ComPort port;
    private static int comRecieve = 0;

    public BaseStation() {
        drones = new ArrayList<Drone>();
    }

    public ArrayList<Drone> getDrones() {
        return drones;
    }

    public void setComPort(String portName) {
        port = new ComPort(portName);
        port.addComListener(this);
    }

    public ComPort getPort() {
        return port;
    }

    @Override
    public void onComRecieve(String recieveString) {
        //System.out.print("[" + comRecieve++ + "] "+ recieveString);
        String[] dronesState = recieveString.split("&");

    }
}
