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


    public void setLatitude(float latitude) {
        this.latitude = latitude;
    }

    public void setLongitude(float longitude) {
        this.longitude = longitude;
    }

    public void setState(byte state) {
        this.state = state;
    }

    public void setJob(byte job) {
        this.job = job;
    }

    public int getId() {
        return this.id;
    }

    public float getLatitude() {
        return latitude;
    }

    public float getLongitude() {
        return longitude;
    }

    public byte getState() {
        return state;
    }

    public byte getJob() {
        return job;
    }

    @Override
    public String toString() {
        return "[" + this.id + "]   Latitude: " + this.latitude + "   Logitude: " + this.longitude +
                "   State: " + this.state + "   Job: " + this.job;
    }

    @Override
    public boolean equals(Object obj) {
        Drone drone = (Drone)obj;
        return (this.id == drone.getId());
    }
}
