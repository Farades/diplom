package ru.mtplab.gui;

import ru.mtplab.logic.Drone;
import ru.mtplab.logic.Manager;

import javax.swing.*;
import java.awt.*;
import java.util.Map;

/**
 * Created by tess on 15.01.2015.
 */
public class DronesListPanel extends WindowPanel {
    DefaultListModel<Drone> droneModel;

    public DronesListPanel(Manager manager, JFrame frame) {
        super(manager, frame);

        setLayout(new BorderLayout());

        droneModel = new DefaultListModel<Drone>();
        JList droneJList = new JList(droneModel);

        this.add(BorderLayout.CENTER, droneJList);
    }

    public void setDroneModel(Map<Integer, Drone> drones) {
        droneModel.clear();
        System.out.println("test");
        for (Map.Entry<Integer, Drone> pair: drones.entrySet()) {
            droneModel.addElement(pair.getValue());
        }
    }

    @Override
    public void redraw() {
        setDroneModel(manager.getBs().getDrones());
        System.out.println(manager.getBs().getDrones());
    }
}
