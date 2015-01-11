package ru.mtplab.gui;

import jssc.SerialPortList;
import ru.mtplab.logic.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Артем on 11.01.2015.
 */
public class ManagerGUI extends JFrame {
    private Manager manager;

    public final static String TITLE = "Manager";
    public final static int WIDTH = 400;
    public final static int HEIGHT = 600;

    public ManagerGUI() {
        manager = new Manager();
        setMenu();
        setTitle(TITLE);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(300, 300, WIDTH, HEIGHT);
        setVisible(true);
        setResizable(false);

        JButton test = new JButton("test");
        add(test);
        test.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                manager.getBs().getPort().write("DID=1;CMD=1;VAL=0");
            }
        });
    }

    private void setMenu() {
        JMenuBar menuBar = new JMenuBar();
        JMenu menuSettings = new JMenu("Настройка");
        JMenu menuCom = new JMenu("COM порт");
        menuSettings.add(menuCom);
        menuBar.add(menuSettings);

        final String[] allPorts = SerialPortList.getPortNames();
        for (int i = 0; i < allPorts.length; i++) {
            JMenuItem menuPort = new JMenuItem(allPorts[i]);
            menuCom.add(menuPort);
            menuPort.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    manager.getBs().setComPort(e.getActionCommand());
                        //manager.getBs().getPort().write("DID=1;CMD=1;VAL=0");
                }
            });
        }
        this.setJMenuBar(menuBar);
    }
}
