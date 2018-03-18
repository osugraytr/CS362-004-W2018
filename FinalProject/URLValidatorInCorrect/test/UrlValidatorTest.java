

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
	
	   
   }
   


}
