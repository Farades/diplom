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
    private Map<Integer, Drone> drones;
    private ArrayList<DronesUpdateObserver> dronesUpdateObservers;
    private ComPort port;

    public BaseStation() {
        drones = new HashMap<Integer, Drone>();
        dronesUpdateObservers = new ArrayList<DronesUpdateObserver>();
    }

    public Map<Integer, Drone> getDrones() {
        return drones;
    }

    public void setComPort(String portName) {
        port = new ComPort(portName);
        port.addComListener(this);
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
    public void onComRecieve(String recieveString) {
        String[] dronesState = recieveString.split("&");

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
            Drone drone = new Drone(id, latitude, longitude, state, job);
            drones.put(id, drone);
        }
        dronesUpdateObsNotification();
        System.out.println(drones);
    }
}
