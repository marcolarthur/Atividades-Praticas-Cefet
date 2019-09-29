/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula03;

import javax.swing.JOptionPane;

/**
 *
 * @author Aluno
 */
public class Aluno {
    private double nota;
    private int frequencia;
    private int naulasf;
    
    public void Aluno(){
        
    }    
    
    public void setNota(double nota){
        this.nota = nota;
    }
    public void setFrequencia(int frequencia){
        this.frequencia = frequencia;
    }
    public void setNaulasf(int naulasf){
        this.naulasf = naulasf;
    }
    public double getNota(double nota){
        return this.nota;
    }
    public int getFrequencia(int frequencia){
        return this.frequencia;
    }
    public int getNaulasf(int naulasf){
        return this.naulasf;
    }    
}

