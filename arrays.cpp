unsigned char cornermove[18][24] =  {	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
        	                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                        	        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
 					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                        	        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
        	                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                        	        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23}};
unsigned char edgemove[18][24] =  {	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
        	                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                        	        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
        	                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                        	        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
        	                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                        	        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
        	                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23}};
unsigned char centermove[36][24] =  {   {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,19,16,17,18,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,18,19,16,17,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,19,16,20,21,22,23},
                                        {12,1,2,15,0,5,6,3,4,9,10,7,8,13,14,11,16,17,18,19,20,21,22,23},
                                        {8,1,2,11,12,5,6,15,0,9,10,3,4,13,14,7,16,17,18,19,20,21,22,23},
                                        {4,1,2,7,8,5,6,11,12,9,10,15,0,13,14,3,16,17,18,19,20,21,22,23},
                                        {0,13,14,3,4,1,2,7,8,5,6,11,12,9,10,15,16,17,18,19,20,21,22,23},
                                        {0,9,10,3,4,13,14,7,8,1,2,11,12,5,6,15,16,17,18,19,20,21,22,23},
                                        {0,5,6,3,4,9,10,7,8,13,14,11,12,1,2,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,22,23,20},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,22,23,20,21},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,23,20,21,22},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,15,12,13,14,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,14,15,12,13,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,13,14,15,12,16,17,18,19,20,21,22,23},
                                        {20,21,2,3,4,5,6,7,8,9,16,17,12,13,14,15,0,1,18,19,10,11,22,23},
                                        {10,11,2,3,4,5,6,7,8,9,0,1,12,13,14,15,20,21,18,19,16,17,22,23},
                                        {16,17,2,3,4,5,6,7,8,9,20,21,12,13,14,15,10,11,18,19,0,1,22,23},
                                        {0,1,22,23,4,5,6,7,18,19,10,11,12,13,14,15,16,17,2,3,20,21,8,9},
                                        {0,1,8,9,4,5,6,7,2,3,10,11,12,13,14,15,16,17,22,23,20,21,18,19},
                                        {0,1,18,19,4,5,6,7,22,23,10,11,12,13,14,15,16,17,8,9,20,21,2,3},
                                        {0,1,2,3,5,6,7,4,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,6,7,4,5,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,7,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {3,0,1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {2,3,0,1,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {1,2,3,0,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,23,20,6,7,8,9,10,11,12,13,17,18,16,4,5,19,15,21,22,14},
                                        {0,1,2,3,14,15,6,7,8,9,10,11,12,13,4,5,16,23,20,19,18,21,22,17},
                                        {0,1,2,3,17,18,6,7,8,9,10,11,12,13,23,20,16,14,15,19,5,21,22,4},
                                        {0,1,2,3,4,5,21,22,8,9,10,11,19,16,14,15,7,17,18,6,20,12,13,23},
                                        {0,1,2,3,4,5,12,13,8,9,10,11,6,7,14,15,22,17,18,21,20,19,16,23},
                                        {0,1,2,3,4,5,19,16,8,9,10,11,21,22,14,15,13,17,18,12,20,6,7,23},
                                        {0,1,2,3,4,5,6,7,9,10,11,8,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,10,11,8,9,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,11,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23}};
