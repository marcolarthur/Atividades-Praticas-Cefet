/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula03;

/**
 *
 * @author Aluno
 */

import javax.swing.JOptionPane;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;


public class Aula03 {
       
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        double nota;
        int aulas;
        int frequencia;
        int x;            
        JFrame f = new JFrame();
        JTextArea CaixaSaida = new JTextArea(11, 20);
        do{
        aulas = Integer.parseInt(JOptionPane.showInputDialog(null, "Em quantas aulas o aluno foi?", "Conceitos", JOptionPane.INFORMATION_MESSAGE));
        nota = Double.parseDouble(JOptionPane.showInputDialog(null, "Qual a nota do aluno?", "Conceitos", JOptionPane.INFORMATION_MESSAGE));
        frequencia = Integer.parseInt(JOptionPane.showInputDialog(null, "Qual a frequencia do aluno?", "Conceitos", JOptionPane.INFORMATION_MESSAGE));
        Object[] options = { "Inserir mais alunos", "Continuar" };
        x = JOptionPane.showOptionDialog(null, "Escolha:", "Informação", JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE, null, options, options[0]);
        Aludno luno = new Aludno(aulas, nota, frequencia);
        if(luno.getNota() >= 90){
            luno.setConceito('A');
        }
        if(luno.getNota() < 90 && luno.getNota() >= 80){
            luno.setConceito('B');
        }
        if(luno.getNota() < 70 && luno.getNota() >= 50){
            luno.setConceito('C');
        }
        if(luno.getNota() < 60 && luno.getNota() >= 40){
            luno.setConceito('D');
        }
        if(luno.getNota() < 40){
            luno.setConceito('E');
        }
        
        }while(x != 1); 
        
        System.exit( 0 ); // termina programa
    }
    
}
