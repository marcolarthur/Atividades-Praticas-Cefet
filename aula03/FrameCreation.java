import javax.swing.*;
import java.awt.*;

public class FrameCreation
{
    public JFrame createFrame(int width, int height, String name)
    {
        JFrame frame = new JFrame(name);
        frame.setVisible(true);
        frame.setSize(width, height);
        frame.setLayout(new FlowLayout());
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.getContentPane().setBackground(Color.DARK_GRAY);
        return frame;
    }

    public JButton createButton(int width, int height, int xPos, int yPos, String text)
    {
        JButton button = new JButton(text);
        button.setBounds(xPos, yPos, width, height);
        button.setBackground(Color.GRAY);
        button.setForeground(Color.WHITE);
        return button;
    }

    public JTextArea createTextArea(int width, int height, int xPos, int yPos)
    {
        JTextArea txt = new JTextArea();
        txt.setBounds(xPos, yPos, width, height);
        txt.setText("Help this poor JTextArea to appear on the frame...");
        return txt;
    }
}