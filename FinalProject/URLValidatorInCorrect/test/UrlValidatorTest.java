

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	  
	   String TestURLs [] = {"http://www.google.com/"
			   					,"http://www.yahoo.com/"
			   					,"http://www.youtube.com/"
			   					,"ftp://www.google.com/"
			   					,"https://www.google.com/"
			   					,"https://www.yahoo.com/"
			   					,"ftp://www.yahoo.com/"
			   					,"http://www.youtube.com/"
			   					,"https://www.youtube.com/"
			   					,"ftp://www.youtube.com/"
			   					,"http://www.oregonstate.edu/"
			   					,"badurl","badurl2","www..com"
			   					,".google.com","https://google"
			   					,"////////////////"
			   					,"qwertyqwerty"
			   					,"www.com"
			   					,"wwwgooglecom"
			   					,"com.google.www"
			   					,"''"};
	   int x = 0;
	   while(x<20) {
		   UrlValidator validator = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
		   System.out.print(validator.isValid(TestURLs[x]));
		   //System.out.print(validator.isValid(TestURLs[x]));
		   //System.out.print(TestURLs[x]);
		   //System.out.print("\n");
		   x = x+1;
	   }
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   
	   UrlValidator urlval = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	   String[] schemes = {"https","ftp"};
	   String[] hostname = {"","www.google.com"};
	   String[] port = {":3000"};
	   String[] path = {"final"};
	   String[] query = {"success"};
	   for(int i = 0;i < schemes.length;i++){
		   String url = (schemes[i] + "://" + hostname + port + "/" + path + "?" + query);
		   		if(urlval.isValid(url)) {
				System.out.print("\nPassed");
		   		} else {
				System.out.print("\nfailed: " + url);
		   		}
	   }
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   
	   UrlValidator urlval = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	   String[] schemes = {"http"};
	   String[] hostname = {"","www.google.com","www.facebook.com"};
	   String[] port = {":3000",""};
	   String[] path = {"","final","project"};
	   String[] query = {"","grade","A++","success"};
	   for(int i = 0;i < schemes.length;i++){
		   for(int j = 0; j < hostname.length;j++) {
			   for(int g = 0;g < port.length;g++) {
				   for(int k = 0;k < path.length;k++) {
					   for(int l = 0;l < query.length;l++) {
						   String url = (schemes[i] + "://" + hostname[j] + port[g] + "/" + path[k] + "?" + query[l]);
						   if(urlval.isValid(url)) {
							   System.out.print("\nPassed");
						   } else {
							   System.out.print("\nfailed: " + url);
						   }
					   }
				   }
			   }
		   }
	   }	
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
  	 
	   	// Verify the instance is working
	   	assertTrue(urlVal.isValid("http://www.myspace.com"));
	      	 
	   	/*
	   	if (urlVal.isValid("http://www.myspace.com/")) {
	          	System.out.println("url is valid");
	       	} else {
	          	System.out.println("url is invalid");
	       	}
	   	*/
	       
	   	System.out.println("---Unit Tester---");
	       
	   	/* Begin Unit Tester ---------------------------------------------*/
	   	int bugsFound = 0;
	   	int size = 100;	/* number of tests */
	   	int bug_itr = 0;

	    	/* Prepare valid url pieces.
	     	* The pieces were chosen from the URLValidatorCorrect UrlValidatorTest.java code
	     	*/
	    	String[] schemes_valid = {"http://", "ftp://", "h3t://", ""};
	    	String[] authority_valid = {"www.google.com", "go.com", "go.au", "0.0.0.0", "255.255.255.255", "255.com"};
	    	String[] port_valid = {":80", ":65535", ":0", ""};
	    	String[] path_valid = {"/test1", "t123", "/$23", "/test1/", "", "/test1/file"};
	    	String[] options_valid = {"/test1", "/t123", "/$23", "/test1/", "", "/test1/file", "/t123/file", "/$23/file", "/test1//file"};
	    	String[] queries_valid = {"?action=view", "?action=edit&mode=up", ""};
	   	 
	    	/* Create array to hold buggy urls */
	    	String[] buggyUrls = new String[size];

	    	/* Create a composite url out of the valid url pieces.
	     	* Loop through "size" times
	     	*/
	    	for(int i = 0; i < size; i++) {
	      	int scheme_random = (int) (Math.random() * 4);
	      	int authority_random = (int) (Math.random() * 6);
	      	int port_random = (int) (Math.random() * 4);
	      	int path_random = (int) (Math.random() * 6);
	      	int options_random = (int) (Math.random() * 9);
	      	int queries_random = (int) (Math.random() *3);

	      	/* Piece together the generated url parts in the correct format. */
	      	String test_url = schemes_valid[scheme_random] + authority_valid[authority_random] + port_valid[port_random] + path_valid[path_random] + queries_valid[queries_random];
	      	UrlValidator test_validator = new UrlValidator();

	      	/* Test url using the UrlValidator */
	      	boolean is_valid = test_validator.isValid(test_url);

	      	/* If invalid, store for later and increment bugs found */
	      	if(is_valid == false) {
	        	buggyUrls[bug_itr] = test_url;
	        	bug_itr++;
	        	bugsFound++;
	      	}
	     	 
	    	}
	   	 
	    	// print results
	    	System.out.println("Tests run: " + size);
	    	System.out.println("Expected bugs: " + 0);
	    	System.out.println("Actual Bugs: " + bugsFound);
	   	 
	    	// Uncomment to show invalid urls found
	    	System.out.println("\nBuggy URLs:");
	    	for (int j = 0; j < buggyUrls.length; j++) {
	      	if(buggyUrls[j] != null){
	   		 System.out.println(buggyUrls[j]);
	      	}
	     	 
	    	}
	     	 
   }
   


}
