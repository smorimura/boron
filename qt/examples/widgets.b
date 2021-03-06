/*
   Show all widgets.
*/

text:
{<h2>Text-Edit Widget</h2>
<p>Text-edit can show basic <i>HTML</i>.</p>
<hr>
<h3>A List</h3>
<ul>
<li>Item one</li>
<li>Item two</li>
</ul>
}

exec widget [
    vbox [
        tab [
            "Basic" [
                vbox [
                    hbox [button "Button" [print "Button pressed"] spacer]
                    hbox [
                        label "Combo"
                        combo ["Item one" "Item two" "Last Item"]
                            [print ["Combo activated:" index]]  ; Optional
                        spacer
                    ]
                    checkbox "Checkbox"
                    list ["Name" "Age"] [
                        "Chris"  32
                        "Abe"    51
                        "Sara"   28
                    ]
                        [print ["List activated:" index]]   ; Optional
                    spacer
                ]
            ]
            "Text" [
                vbox [
                    hbox [label "Line-edit" line-edit]
                    text-edit :text
                ]
            ]
            "Dialogs" [
                vbox [
                    button "Message" [
                        message "Message"
                                "This was invoked by the 'message word."
                    ]

                    button "Question" [
                        answer: question "Question"
                                         "Do you like vanilla yogurt?"
                                         "Yes" "Umm, not so much"
                        message "Answer" join "Question returned: " answer
                    ]

                    button "Request-file" [
                        file: request-file "Select a file"
                        message "File Selected" file
                    ]

                    spacer
                ]
            ]
        ]

        spacer
        hbox [spacer button "Quit" [quit]]
    ]
]
