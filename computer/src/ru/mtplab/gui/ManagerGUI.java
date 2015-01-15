package ru.mtplab.gui;

import jssc.SerialPortList;
import ru.mtplab.logic.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * ManagerGUI - главное окно(JFrame) приложения.
 * Для перехода внутри приложения меняются JPanel внутри данного JFrame.
 */
public class ManagerGUI extends JFrame implements DronesUpdateObserver {
    private Manager manager;
    private MainWindow mainWindow;


    public final static String TITLE = "Manager";
    public final static int WIDTH = 600;
    public final static int HEIGHT = 600;

    public ManagerGUI() {
        manager = new Manager();
        manager.getBs().addDronesUpdateListener(this);
        setMenu();
        setTitle(TITLE);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(300, 300, WIDTH, HEIGHT);
        setVisible(true);
        setResizable(false);

        mainWindow = new MainWindow(manager, this);
        add(BorderLayout.CENTER, mainWindow);
        //add(BorderLayout.SOUTH, new JLabel("dwa"));
    }

    /**
     * Установка верхнего меню "Настройка"
     */
    private void setMenu() {
        JMenuBar menuBar = new JMenuBar();
        JMenu menuSettings = new JMenu("Настройка");
        JMenu menuCom = new JMenu("COM порт");
        JMenuItem menuComClose = new JMenuItem("Закрыть порт");
        menuSettings.add(menuCom);
        menuSettings.add(menuComClose);
        menuBar.add(menuSettings);

        menuComClose.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    manager.getBs().closeComPort();
                    System.out.println("Close connection.");
                } catch (NullPointerException ex) {
                    // TODO диалоговое окно
                    System.out.println("Сначала откройте соединение");
                }
            }
        });

        final String[] allPorts = SerialPortList.getPortNames();
        for (int i = 0; i < allPorts.length; i++) {
            JMenuItem menuPort = new JMenuItem(allPorts[i]);
            menuCom.add(menuPort);
            menuPort.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    manager.getBs().setComPort(e.getActionCommand());
                }
            });
        }
        this.setJMenuBar(menuBar);
    }

    @Override
    public void onDronesUpdate() {
        mainWindow.redraw();
    }
}
