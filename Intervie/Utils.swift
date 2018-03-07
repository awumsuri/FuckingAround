//
//  Utils.swift
//  QuicksortSwift
//
//  Created by Suri on 5/24/15.
//  Copyright (c) 2015 Suri. All rights reserved.
//

import Foundation

class Utils {
    
    static func timeFunction(function:([Int], Int) -> [String: Int], arr: [Int], targetNumber: Int, description: String){
        var description = description
        let startT:TimeInterval?
        let endT:TimeInterval?
        startT = NSDate.timeIntervalSinceReferenceDate
        let result = function(arr, targetNumber)
        endT  = NSDate.timeIntervalSinceReferenceDate
        description.append(" " + result.description)
        printTime(description: description, time: (endT!-startT!))
    }
    
    static func timeFunction(function:(inout [Int], inout [Int: Int], Int, Int) -> [Int], arr: [Int], map: [Int: Int], targetNumber: Int, kNumber: Int, description: String){
        var arr = arr
        var map = map
        var description = description
        let startT:TimeInterval?
        let endT:TimeInterval?
        startT = NSDate.timeIntervalSinceReferenceDate
        let result = function(&arr, &map, targetNumber, kNumber)
        endT  = NSDate.timeIntervalSinceReferenceDate
        description.append(" " + result.description)
        printTime(description: description, time: (endT!-startT!))
    }
    
    static func printTime(description: String, time: Double)->(){
        print("********************************")
        print("* \(description)")
        print("* Computation Time(s): \((time))")
        print("********************************")
    }
}
