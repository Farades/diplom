package ru.mtplab.gui;

import jssc.SerialPortList;
import ru.mtplab.logic.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * ManagerGUI - главное окно(JFrame) приложения.
 * Для перехода внутри приложения меняются JPanel внутри данного JFrame.
 */
public class ManagerGUI extends JFrame {
    private Manager manager;

    public final static String TITLE = "Manager";
    public final static int WIDTH = 600;
    public final static int HEIGHT = 600;

    public ManagerGUI() {
        manager = new Manager();
        setMenu();
        setTitle(TITLE);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(300, 300, WIDTH, HEIGHT);
        setVisible(true);
        setResizable(false);
        add(new MainWindow(manager, this));
    }

    /**
     * Установка верхнего меню "Настройка"
     */
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
                }
            });
        }
        this.setJMenuBar(menuBar);
    }
}
