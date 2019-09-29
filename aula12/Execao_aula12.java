/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package execao_aula12;
import javax.swing.*;

/**
 *
 * @author Ingrid Lysei
 */
public class Execao_aula12 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ManipulaVetor vetor = new ManipulaVetor();
        int x = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite um número de 0 a 20"));
        System.out.println(vetor.toString());
        JOptionPane.showMessageDialog(null, vetor.toString() + "\n\n"+ "Número X: " + x + "\n\nTodas Ocorrencais: " + vetor.todasOcorrencia(x) + "\nNúmero de Ocorrencias: " + vetor.numOcorrencia(x) + "\nPosição do Maior Elemento: " + vetor.posMai() + "\nPosição do Menor Elemento: " + vetor.posMen() + "\nPrimeira Ocorrencia: " + vetor.primeiraOcorrencia(x));
        
    }
    
}
