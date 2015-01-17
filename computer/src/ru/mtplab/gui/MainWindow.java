package ru.mtplab.gui;

import ru.mtplab.logic.ComObserver;
import ru.mtplab.logic.Drone;
import ru.mtplab.logic.Manager;

import javax.swing.*;
import java.awt.*;

/**
 * Created by Артем on 11.01.2015.
 */
public class MainWindow extends WindowPanel {
    private JTabbedPane tabbedPane;
    private DronesTablePanel dronesTablePanel;
    private TerminalPanel terminalPanel;
    private DronePanel dronePanel;

    public MainWindow(Manager manager, JFrame mainFrame) {
        super(manager, mainFrame);
        dronesTablePanel = new DronesTablePanel(manager, mainFrame, this);
        terminalPanel = new TerminalPanel(manager, mainFrame);
        setLayout(new BorderLayout());

        tabbedPane = new JTabbedPane();
        tabbedPane.addTab("Мониторинг группы", dronesTablePanel);
        tabbedPane.addTab("Терминал", terminalPanel);
        tabbedPane.addTab("Связь с группой", new JPanel());
        add(BorderLayout.CENTER, tabbedPane);
    }

    public void setDronePanel(Drone drone) {
        dronesTablePanel.removeAll();
        dronesTablePanel.revalidate();
        dronesTablePanel.repaint();
        dronePanel = new DronePanel(manager, mainFrame, drone, this);
        tabbedPane.setComponentAt(0, dronePanel);
        dronesTablePanel = null;
    }

    public void setDronesTablePanel() {
        dronePanel.removeAll();
        dronePanel.revalidate();
        dronePanel.repaint();
        dronesTablePanel = new DronesTablePanel(manager, mainFrame, this);
        tabbedPane.setComponentAt(0, dronesTablePanel);
        dronePanel = null;
    }

    public ComObserver getTerminalPanel() {
        return terminalPanel;
    }

    @Override
    public void redraw() {
        if (dronesTablePanel != null) {
            dronesTablePanel.redraw();
        }
        if (dronePanel != null) {
            dronePanel.redraw();
        }
    }
}
