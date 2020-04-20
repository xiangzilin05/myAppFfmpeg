//
//  ViewController.swift
//  myApp
//
//  Created by 林祥辉 on 2020/4/19.
//  Copyright © 2020 林祥辉. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        self.view.setFrameSize(NSSize(width: 320, height: 240))
        
        let btn = NSButton.init(title: "button", target: nil, action: nil)
        btn.frame=NSRect(x: 320/2-40, y: 240/2-15, width: 80, height: 30)
        btn.bezelStyle = .rounded
//        btn.setButtonType(.pushOnPushOff)
        btn.target = self
        btn.action = #selector(myfunc)
        
        self.view.addSubview(btn)
    }
    
    @objc
    func myfunc() {
        haha()
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

