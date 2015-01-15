package ru.mtplab.logic;

/**
 * Created by Артем on 11.01.2015.
 */
public class Drone {
    private int id;
    private float latitude;
    private float longitude;
    private byte  state;
    private byte job;

    public Drone(int id, float latitude, float longitude, byte state, byte job) {
        this.id = id;
        this.latitude = latitude;
        this.longitude = longitude;
        this.state = state;
        this.job = job;
    }
    
    @Override
    public String toString() {
        return "[" + this.id + "]   Latitude: " + this.latitude + "   Logitude: " + this.longitude +
                "   State: " + this.state + "   Job: " + this.job;
    }
}
