package ru.mtplab.gui;

import ru.mtplab.logic.ComObserver;
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


    public MainWindow(Manager manager, JFrame mainFrame) {
        super(manager, mainFrame);
        dronesTablePanel = new DronesTablePanel(manager, mainFrame);
        terminalPanel = new TerminalPanel(manager, mainFrame);
        setLayout(new BorderLayout());

        tabbedPane = new JTabbedPane();
        tabbedPane.addTab("Список БПЛА", dronesTablePanel);
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

    public ComObserver getTerminalPanel() {
        return terminalPanel;
    }

    @Override
    public void redraw() {
        dronesTablePanel.redraw();
    }
}
