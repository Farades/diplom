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
    private JTabbedPane tabbedPane;
    private DronesListPanel dronesListPanel;
    private TerminalPanel terminalPanel;


    public MainWindow(Manager manager, JFrame mainFrame) {
        super(manager, mainFrame);
        dronesListPanel = new DronesListPanel(manager, mainFrame);
        terminalPanel = new TerminalPanel(manager, mainFrame);
        setLayout(new BorderLayout());

        tabbedPane = new JTabbedPane();
        tabbedPane.addTab("Список БПЛА", dronesListPanel);
        tabbedPane.addTab("Терминал", terminalPanel);
        add(BorderLayout.CENTER, tabbedPane);
//        JButton test = new JButton("test");
//        add(test);
//        test.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                //manager.getBs().getPort().write("DID=1;CMD=1;VAL=0");
//            }
//        });
    }

    @Override
    public void redraw() {
        dronesListPanel.redraw();
    }
}
