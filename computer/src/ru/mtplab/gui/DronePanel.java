package ru.mtplab.gui;

import ru.mtplab.logic.Drone;
import ru.mtplab.logic.DroneState;
import ru.mtplab.logic.Manager;

import javax.swing.*;
import javax.swing.event.TableModelListener;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.DefaultTableCellRenderer;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.ArrayList;

/**
 * Created by Артем on 17.01.2015.
 */
public class DronePanel extends WindowPanel {
    private Drone drone;
    private JLabel title;
    private JTable stateTable;
    private DroneStatesModel stateModel;
    private JScrollPane scrollPane;
    private JScrollBar vertical;
    private JPanel mainPanel;
    private JPanel sendPanel;

    private MainWindow mainWindow;

    public DronePanel(final Manager manager, JFrame frame, final Drone drone, final MainWindow mainWindow) {
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
        title = new JLabel("Мониторинг БПЛА#" + drone.getId(), SwingConstants.CENTER);
        title.setFont(new Font("Arial", Font.BOLD, 14));
        add(BorderLayout.NORTH, title);
        add(BorderLayout.SOUTH, back);

        stateModel = new DroneStatesModel(this.drone.getDroneStates());
        stateTable = new JTable(stateModel);
        stateTable.setRowHeight(25);
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment(SwingConstants.CENTER);
        stateTable.getColumnModel().getColumn(0).setCellRenderer(centerRenderer);
        stateTable.getColumnModel().getColumn(1).setCellRenderer(centerRenderer);
        stateTable.getColumnModel().getColumn(2).setCellRenderer(centerRenderer);
        stateTable.getColumnModel().getColumn(3).setCellRenderer(centerRenderer);
        stateTable.getColumnModel().getColumn(4).setCellRenderer(centerRenderer);
        scrollPane = new JScrollPane(stateTable);
        vertical = scrollPane.getVerticalScrollBar();
        vertical.setValue(vertical.getMaximum());

        mainPanel = new JPanel(new BorderLayout());
        mainPanel.add(BorderLayout.CENTER, scrollPane);
        sendPanel = new JPanel();
        JLabel sendCmdLabel = new JLabel("CMD: ");
        final JTextField sendCmdField = new JTextField(10);
        JLabel sendValueLabel = new JLabel("VAL: ");
        final JTextField sendValueField = new JTextField(10);
        JButton sendButton = new JButton("Отправить");
        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                DID=1;CMD=1;VAL=0
                String sendStr = "DID=" + drone.getId() + ";CMD=" + sendCmdField.getText() + ";VAL=" + sendValueField.getText();
                sendCmdField.setText("");
                sendValueField.setText("");
                try {
                    manager.getBs().getPort().write(sendStr);
                    System.out.println(sendStr);
                } catch (NullPointerException ex) {
                    // TODO сделать диалоговое окно
                    //System.out.println("Сначала откройте соединение");
                }
            }
        });
        sendPanel.add(sendCmdLabel);
        sendPanel.add(sendCmdField);
        sendPanel.add(sendValueLabel);
        sendPanel.add(sendValueField);
        sendPanel.add(sendButton);
        add(BorderLayout.CENTER, mainPanel);
        mainPanel.add(BorderLayout.SOUTH, sendPanel);
    }

    @Override
    public void redraw() {
        stateTable.repaint();
        scrollPane.getViewport().revalidate();
        vertical.setValue(vertical.getMaximum());
    }

    private class DroneStatesModel extends AbstractTableModel {
        private ArrayList<DroneState> droneStates;

        public DroneStatesModel(ArrayList<DroneState> droneStates) {
            this.droneStates = droneStates;
        }

        @Override
        public int getRowCount() {
            return droneStates.size();
        }

        @Override
        public int getColumnCount() {
            return 5;
        }

        @Override
        public String getColumnName(int columnIndex) {
            switch (columnIndex) {
                case 0:
                    return "Time";

                case 1:
                    return "Latitude";

                case 2:
                    return "Longitude";

                case 3:
                    return "Состояние";

                case 4:
                    return "Задание";
            }
            return null;
        }

        @Override
        public Class<?> getColumnClass(int columnIndex) {
            return String.class;
        }

        @Override
        public boolean isCellEditable(int rowIndex, int columnIndex) {
            return false;
        }

        @Override
        public Object getValueAt(int rowIndex, int columnIndex) {
            DroneState droneState = droneStates.get(rowIndex);
            switch (columnIndex) {
                case 0:
                    SimpleDateFormat dateFormat = new SimpleDateFormat("dd.MM HH:mm:ss");
                    return dateFormat.format(droneState.getDate());

                case 1:
                    return droneState.getLatitude();

                case 2:
                    return droneState.getLongitude();

                case 3:
                    return droneState.getState();

                case 4:
                    return droneState.getJob();
            }
            return null;
        }

        @Override
        public void setValueAt(Object aValue, int rowIndex, int columnIndex) {

        }

        @Override
        public void addTableModelListener(TableModelListener l) {

        }

        @Override
        public void removeTableModelListener(TableModelListener l) {

        }
    }
}
