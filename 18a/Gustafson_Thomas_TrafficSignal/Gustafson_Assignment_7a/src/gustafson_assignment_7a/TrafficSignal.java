/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment_7a;

/**
 *
 * @author tgust
 */
public enum TrafficSignal {
    RED(40),
    GREEN (30),
    YELLOW (10),
    WALK(25),
    DONT_WALK(55);
    
    private final int duration;
    
    TrafficSignal(int duration){
        this.duration=duration;
        
    }
    
    public int getDuration(){
        return duration;
    }
}
