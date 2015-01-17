package ru.mtplab.logic;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Created by Артем on 11.01.2015.
 */
public class BaseStation implements ComObserver {
    // HashMap для хранения drone. Ключом является уникальный идентификатор приемопередающих устройств БПЛА.
    private ArrayList<Drone> drones;
    private ArrayList<DronesUpdateObserver> dronesUpdateObservers;
    private ComPort port;

    public BaseStation() {
        drones = new ArrayList<Drone>();
        dronesUpdateObservers = new ArrayList<DronesUpdateObserver>();
    }

    public ArrayList<Drone> getDrones() {
        return drones;
    }

    public void setComPort(String portName) {
        port = new ComPort(portName);
        port.addComListener(this);
    }

    public void closeComPort() {
        port.close();
    }

    public ComPort getPort() {
        return port;
    }

    public void addDronesUpdateListener(DronesUpdateObserver obs) {
        dronesUpdateObservers.add(obs);
    }

    private void dronesUpdateObsNotification() {
        for (DronesUpdateObserver obs : dronesUpdateObservers) {
            obs.onDronesUpdate();
        }
    }

    @Override
    public void onComReceive(String receiveString ) {
        String[] dronesState = receiveString.split("&");

        for (String droneStr : dronesState) {
            StringTokenizer st = new StringTokenizer(droneStr, "=;");
            int i = 0;
            int id = 0;
            float latitude = .0f;
            float longitude = .0f;
            byte state = 0;
            byte job = 0;
            while (st.hasMoreTokens()) {
                String temp = st.nextToken();
                switch (i) {
                    case 1:
                        id = Integer.parseInt(temp);
                        break;
                    case 3:
                        latitude = Float.parseFloat(temp);
                        break;
                    case 5:
                        longitude = Float.parseFloat(temp);
                        break;
                    case 7:
                        state = Byte.parseByte(temp);
                        break;
                    case 9:
                        job = Byte.parseByte(temp);
                        break;
                }
                i++;
            }
            DroneState droneState = new DroneState(latitude, longitude, state, job);
            Drone drone = new Drone(id, droneState);
            if (drones.contains(drone)) {
                int index = drones.indexOf(drone);
                drones.get(index).update(droneState);
            } else {
                drones.add(drone);
            }
        }
        dronesUpdateObsNotification();
    }
}
