package ru.mtplab.logic;

import java.util.Date;

/**
 * Created by Артем on 17.01.2015.
 */
public class DroneState {
    private float latitude;
    private float longitude;
    private byte  state;
    private byte job;

    private Date date;

    public DroneState(float latitude, float longitude, byte state, byte job) {
        this.latitude = latitude;
        this.longitude = longitude;
        this.state = state;
        this.job = job;
        this.date = new Date();
    }

    @Override
    public String toString() {
        return "Latitude: " + this.latitude + "   Logitude: " + this.longitude +
        "   State: " + this.state + "   Job: " + this.job;
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

    public Date getDate() {
        return date;
    }
}
