package ru.mtplab.logic;

/**
 * Created by tess on 15.01.2015.
 */
public interface ComObserver {
    public abstract void onComReceive(String receiveString);
}
