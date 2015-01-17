package ru.mtplab.logic;

import java.util.ArrayList;

/**
 * Created by Артем on 11.01.2015.
 */
public class Drone {
    private DroneState currentState;

    private ArrayList<DroneState> droneStates;
    private int id;

    public Drone(int id, DroneState state) {
        this.id = id;
        this.currentState = state;
        droneStates = new ArrayList<DroneState>();
        droneStates.add(currentState);
    }

    public void update(DroneState state) {
        currentState = state;
        droneStates.add(currentState);
    }

    public ArrayList<DroneState> getDroneStates() {
        return droneStates;
    }

    public int getId() {
        return this.id;
    }

    public DroneState getCurrentState() {
        return this.currentState;
    }

    @Override
    public String toString() {
        return "[" + this.id + "]  " + this.currentState;
    }

    @Override
    public boolean equals(Object obj) {
        Drone drone = (Drone)obj;
        return (this.id == drone.getId());
    }
}
