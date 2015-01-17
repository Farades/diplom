package ru.mtplab.gui;

import ru.mtplab.logic.Drone;
import ru.mtplab.logic.Manager;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Артем on 17.01.2015.
 */
public class DronePanel extends WindowPanel {
    private Drone drone;
    JLabel test;

    private MainWindow mainWindow;

    public DronePanel(Manager manager, JFrame frame, Drone drone, final MainWindow mainWindow) {
        super(manager, frame);
        this.drone = drone;
        this.mainWindow = mainWindow;
        setLayout(new BorderLayout());

        JButton back = new JButton("Назад");
        back.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                mainWindow.setDronesTablePanel();
            }
        });
        test = new JLabel(drone.toString());
        add(BorderLayout.NORTH, test);
        add(BorderLayout.SOUTH, back);
    }

    @Override
    public void redraw() {
        test.setText(drone.toString());

        System.out.println(drone);
    }
}
