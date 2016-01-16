#include <vector>  
#include <string>  
#include <iostream> 

namespace algorithm {

	template <typename T>
	void LongestCommonSubsequence(const T& s1, const T& s2, T& s3)  
	{
		const size_t len1 = s1.size();  
    	const size_t len2 = s2.size();  
    	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));
    	std::vector<std::vector<unsigned int>> b(len1 + 1, std::vector<unsigned int>(len2 + 1));
    	const int w = 1;  
	    const int n = 2;  
	    const int nw = 3;  
	    for(int i = 1; i <= len1; ++i)  
	    {  
	        for(int j = 1; j <= len2; ++j)  
	        {     
	            if (s1[i-1] == s2[j-1])  
	            {  
	                d[i][j] = d[i-1][j-1]+1;  
	                b[i][j] = nw;  
	            }  
	            else  
	            {     
	                if (d[i-1][j] >= d[i][j-1])  
	                {  
	                    d[i][j] = d[i-1][j];  
	                    b[i][j] = n;  
	                }  
	                else  
	                {  
	                    d[i][j] = d[i][j-1];  
	                    b[i][j] = w;  
	                }  
	            }  
	        }  
	    }  
	    s3.resize(d[len1][len2]);  
	    int i=len1;  
	    int j=len2;  
	    int k=d[len1][len2]-1;  
	    while ( k>=0 && i>0 && j>0 )  
	    {  
	        if ( b[i][j] == nw )  
	        {  
	            s3[k--] = s1[i-1];  
	            i -- ;  
	            j -- ;  
	        }         
	        else if (b[i][j] == n)  
	            i -- ;  
	        else if (b[i][j] == w)  
	            j --;  
	        else  
	            break;  
	    }  

	}

	int main()
	{
		std::string s1("ABCBDAB");  
	    std::string s2("BDCABA");  
	    std::string s3;
	    LongestCommonSubsequence(s1, s2, s3);  
	    std::cout<< s3 <<std::endl; 
		return 0;
	}
}