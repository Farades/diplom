package ru.mtplab.logic;

/**
 * Created by Артем on 11.01.2015.
 */
public class Manager {
    private BaseStation bs;

    public Manager() {
        bs = new BaseStation();
    }

    public BaseStation getBs() {
        return bs;
    }
}
