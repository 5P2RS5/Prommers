for(int j = fy; j <= ly; j++)
        {
            for(int k = fx; k <= lx; k++)
            {
                if(arr[j][k] == 0)
                {
                    if(j == ly || k == lx || j == fy || k == fx)
                    { 
                        arr[j][k] = 1;
                    }
                    else
                    {
                        if(arr[j][k] == 1)
                            arr[j][k] = 7;
                        arr[j][k] = 7;
                    }
                }
                else
                {
                    if(arr[j][k] == 1)
                    {
                        if(j == ly || k == lx || j == fy || k == fx)
                        { 
                            arr[j][k] = 1;
                        }
                        else
                            arr[j][k] = 7;
                    }
                }
            }