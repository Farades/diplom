package ru.mtplab.gui;

import ru.mtplab.logic.ComObserver;
import ru.mtplab.logic.Manager;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by tess on 15.01.2015.
 */
public class TerminalPanel extends WindowPanel implements ComObserver {
    private JTextArea textArea;
    private JScrollPane scrollPane;
    private JScrollBar vertical;
    private JTextField sendText;

    public TerminalPanel(final Manager manager, JFrame frame) {
        super(manager, frame);
        setLayout(new BorderLayout());

        textArea = new JTextArea();
        textArea.setEditable(false);
        Font font = new Font("Verdana", Font.PLAIN, 14);
        textArea.setFont(font);
        scrollPane = new JScrollPane(textArea);
        vertical = scrollPane.getVerticalScrollBar();
        add(BorderLayout.CENTER, scrollPane);

        JPanel sendPanel = new JPanel();

        sendText = new JTextField(40);
        JButton sendButton = new JButton("Отправить");
        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String sendStr = sendText.getText();
                sendText.setText("");
                try {
                    manager.getBs().getPort().write(sendStr);
                    textArea.append("[OUT] " + sendStr + "\n");
                    vertical.setValue(vertical.getMaximum());
                } catch (NullPointerException ex) {
                    // TODO сделать диалоговое окно
                    System.out.println("Сначала откройте соединение");
                }

            }
        });
        sendPanel.add(sendText);
        sendPanel.add(sendButton);
        add(BorderLayout.SOUTH, sendPanel);
    }

    @Override
    public void redraw() {

    }

    @Override
    public void onComReceive(String receiveString) {
        textArea.append("[IN] " + receiveString);
        vertical.setValue(vertical.getMaximum());
    }
}
