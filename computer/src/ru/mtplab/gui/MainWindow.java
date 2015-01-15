package ru.mtplab.gui;

import ru.mtplab.logic.Manager;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Артем on 11.01.2015.
 */
public class MainWindow extends WindowPanel {

    public MainWindow(Manager manager, JFrame mainFrame) {
        super(manager, mainFrame);

        JButton test = new JButton("test");
        add(test);
        test.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //manager.getBs().getPort().write("DID=1;CMD=1;VAL=0");
            }
        });
    }
}
