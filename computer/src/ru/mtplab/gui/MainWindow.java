package ru.mtplab.gui;

import ru.mtplab.logic.Drone;
import ru.mtplab.logic.Manager;

import javax.swing.*;
import java.awt.*;
import java.util.Map;

/**
 * Created by Артем on 11.01.2015.
 */
public class MainWindow extends WindowPanel {
    DefaultListModel<Drone> droneModel;

    public MainWindow(Manager manager, JFrame mainFrame) {
        super(manager, mainFrame);
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

        droneModel = new DefaultListModel<Drone>();
        JList droneJList = new JList(droneModel);

        this.add(droneJList);


//        JButton test = new JButton("test");
//        add(test);
//        test.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                //manager.getBs().getPort().write("DID=1;CMD=1;VAL=0");
//            }
//        });
    }

    public void setDroneModel(Map<Integer, Drone> drones) {
        for (Map.Entry<Integer, Drone> pair: drones.entrySet()) {
            droneModel.addElement(pair.getValue());
        }
    }
}
