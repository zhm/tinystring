{
  "targets": [
    {
      "target_name": "tinystring",
      "sources": [ "addon.cc", "tinystring.cc" ],
      "include_dirs" : [
 	 			"<!(node -e \"require('nan')\")"
			]
    }
  ],
}
