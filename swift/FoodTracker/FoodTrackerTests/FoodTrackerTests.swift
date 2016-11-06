//
//  FoodTrackerTests.swift
//  FoodTrackerTests
//
//  Created by HEESIK SHIN on 8/20/15.
//  Copyright © 2015 HEESIK SHIN. All rights reserved.
//

import XCTest
@testable import FoodTracker

class FoodTrackerTests: XCTestCase {
    // MARK: Foodtracker Tests
    
    // Tests to confirm the meal initializer returns when no name or a negative rating number is provided.
    func testMealInitialization(){
        // Success case.
        let potentialItem = Meal(name: "Newest meal", photo: nil, rating: 5)
        XCTAssertNotNil(potentialItem)
        
        // Failure cases.
        let noName = Meal(name: "", photo: nil, rating: 0)
        XCTAssertNil(noName, "Empty Name is invalid")
        let badRating = Meal(name: "Really bad rating", photo: nil, rating: -1)
        XCTAssertNil(badRating, "Negative ratings are invalid, be positive")
        
    }
    
}
