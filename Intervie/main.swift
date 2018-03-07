//
//  main.swift
//  Intervie
//
//  Created by Suri on 3/6/18.
//  Copyright © 2018 Suri. All rights reserved.
//

import Foundation

let arr: [Int] =  {
    var a:[Int] = [Int]()
    for i in 1 ... 1000 {
        a.append(i)
    }
    
    return a
}()

var map: [Int: Int] = [:]

class findTargetNumber {
    private var map: [Int: Int] = [:]
    
    private func populateMap(map: [Int: Int], targetNumber: Int) -> [Int: Int] {
        var map = map;
        for n in arr {
            if n < targetNumber {
                map[n] = n
            } else if n > targetNumber {
                
                return map
                
            }
        }
        
        return map
    }
    
    public func findTarget2(arr: [Int], targetNumber: Int) -> [String: Int] {
       
        if map.isEmpty { map = populateMap(map: [:], targetNumber: targetNumber) }
        
        for i in 0...(arr.count-1) {
            
            let testNumber = arr[i]
            
            if testNumber >= targetNumber {
                return [:]
            }
            
            let numberToAdd = targetNumber  - testNumber;
            
            if map[numberToAdd] != nil && numberToAdd != testNumber {
               // map[numberToAdd] = nil
                return [
                    "1": testNumber,
                    "2": numberToAdd
                ]
            }
            
        }
        
        return [:]
    }
    
    public func findTarget3(arr: [Int], targetNumber: Int) -> [String: Int] {
        
        for i in 0...(arr.count-1) {
            
            let testNumber = arr[i]
            
            if testNumber >= targetNumber { return ["error": 0]}
            
            let newTarget = targetNumber - testNumber
            let newResult = findTarget2(arr: arr, targetNumber: newTarget)
            
            if !newResult.isEmpty && newResult["1"] != testNumber && newResult["2"] != testNumber {
                return [
                    "1": newResult["1"]!,
                    "2": newResult["2"]!,
                    "3": testNumber
                ]
            }
            
        }
        return [:]
    }
    
    public func findTarget4(arr: [Int], targetNumber: Int) -> [String: Int] {
        
        for i in 0...(arr.count-1) {
            
            let testNumber = arr[i]
            
            if testNumber >= targetNumber { return ["error": 0]}
            
            let newTarget = targetNumber - testNumber
            let newResult = findTarget3(arr: arr, targetNumber: newTarget)
            
            if !newResult.isEmpty && newResult["1"] != testNumber && newResult["2"] != testNumber && newResult["3"] != testNumber {
                return [
                    "1": newResult["1"]!,
                    "2": newResult["2"]!,
                    "3": newResult["3"]!,
                    "4": testNumber
                ]
            }
            
        }
        return [:]
    }
    
    public func findTarget5(arr: [Int], targetNumber: Int) -> [String: Int] {
        
        for i in 0...(arr.count-1) {
            
            let testNumber = arr[i]
            
            if testNumber >= targetNumber { return ["error": 0]}
            
            let newTarget = targetNumber - testNumber
            let newResult = findTarget4(arr: arr, targetNumber: newTarget)
            
            if !newResult.isEmpty && newResult["1"] != testNumber && newResult["2"] != testNumber && newResult["3"] != testNumber && newResult["4"] != testNumber {
                return [
                    "1": newResult["1"]!,
                    "2": newResult["2"]!,
                    "3": newResult["3"]!,
                    "4": newResult["4"]!,
                    "5": testNumber
                ]
            }
            
        }
        return [:]
    }
    
    public var count = 0
    
    public func findTarget(arr: inout [Int], map: inout [Int: Int], targetNumber: Int, numberOfNumbers: Int) -> [Int] {
        
        if map.isEmpty { map = populateMap(map: [:], targetNumber: targetNumber) }
        
        for i in 0...(arr.count-1) {
            
            count += 1
            let testNumber = arr[i]
            
            if testNumber >= targetNumber {
                return []
            }
            
            let newTargetNumber = targetNumber  - testNumber;
            
            if numberOfNumbers == 2 {
                
                if map[newTargetNumber] != nil && newTargetNumber != testNumber {
                    
                   return [testNumber,  newTargetNumber]
                    
                }
                continue
                
            }
                
            var newResult =  findTarget(arr: &arr, map: &map, targetNumber: newTargetNumber, numberOfNumbers: (numberOfNumbers - 1))
            if !newResult.isEmpty && !newResult.contains(testNumber) {
                
                newResult.append(testNumber)
                return newResult
               
            }
            
        }
        
        return []
        
    }
    
}

let test = findTargetNumber()
//Utils.timeFunction(function: test.findTarget5, arr: test.arr, targetNumber: 2543, description: "Timing findTarget func")
Utils.timeFunction(function: test.findTarget, arr: arr, map: map, targetNumber: 320, kNumber: 12, description: "Timing findTarget func")
print("count \(test.count)")
