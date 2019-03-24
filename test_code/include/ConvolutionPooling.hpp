#ifndef ConvolutionPooling_hpp
#define ConvolutionPooling_hpp

#include <vector>

class ConvolutionPooling{
  private:
    const unsigned INPUTSIZE = 11;
    const unsigned FILTERSIZE = 3;
    const unsigned POOLSIZE = 3;
    const unsigned POOLOUTSIZE = 3;
    std::vector<std::vector<double>> 
  public:
    void conv()
  private:
};
#endif
void conv(double filter[][FILTERSIZE]
   ,double e[][INPUTSIZE]
   ,double convout[][INPUTSIZE]) ; /*ôÝÝÌvZ*/
double calcconv(double filter[][FILTERSIZE]
               ,double e[][INPUTSIZE],int i,int j) ;
                               /*  tB^ÌKp  */
void convres(double convout[][INPUTSIZE]) ;
              /*ôÝÝÌÊoÍ*/
void pool(double convout[][INPUTSIZE]
         ,double poolout[][POOLOUTSIZE]) ; 
             /*v[OÌvZ*/           
double maxpooling(double convout[][INPUTSIZE]
                 ,int i,int j) ;/* Åålv[O */
void poolres(double poolout[][POOLOUTSIZE]) ;/*ÊoÍ*/
void getdata(double e[][INPUTSIZE]) ;/*f[^ÇÝÝ*/ 
         
/*******************/ 
/*    main()Ö   */ 
/*******************/ 
int main()
{
 double filter[FILTERSIZE][FILTERSIZE]
//      ={{0,0,0},{1,1,1},{0,0,0}} ;/*¡tB^*/
        ={{0,1,0},{0,1,0},{0,1,0}} ;/*ctB^*/
 double e[INPUTSIZE][INPUTSIZE] ;/*üÍf[^*/
 double convout[INPUTSIZE][INPUTSIZE]={0} ;/*ôÝÝoÍ*/
 double poolout[POOLOUTSIZE][POOLOUTSIZE] ;/*oÍf[^*/
 int i,j ;/*JèÔµÌ§ä*/
 
 /*üÍf[^ÌÇÝÝ*/
 getdata(e) ;
 
 /*ôÝÝÌvZ*/
 conv(filter,e,convout) ;
 convres(convout) ;
 
 /*v[OÌvZ*/
 pool(convout,poolout) ;
 /*ÊÌoÍ*/
 poolres(poolout) ;
 
 return 0 ;
}

/**********************/
/*  poolres()Ö     */
/* @ÊoÍ         */
/**********************/
void poolres(double poolout[][POOLOUTSIZE]) 
{
 int i,j ;/*JèÔµÌ§ä*/
 
 for(i=0;i<POOLOUTSIZE;++i){
  for(j=0;j<POOLOUTSIZE;++j){
   printf("%.3lf ",poolout[i][j]) ;
  }
  printf("\n") ;
 }
 printf("\n") ;	
} 
 
/**********************/
/*  pool()Ö        */
/* v[OÌvZ   */
/**********************/
void pool(double convout[][INPUTSIZE]
         ,double poolout[][POOLOUTSIZE]) 
{
 int i,j ;/*JèÔµÌ§ä*/

 for(i=0;i<POOLOUTSIZE;++i)
  for(j=0;j<POOLOUTSIZE;++j)
   poolout[i][j]=maxpooling(convout,i,j) ;
}
 
/**********************/
/* maxpooling()Ö   */
/* Åålv[O   */
/**********************/
double maxpooling(double convout[][INPUTSIZE]
                 ,int i,int j)
{
 int m,n ;/*JèÔµÌ§äp*/
 double max ;/*Åål*/
 int halfpool=POOLSIZE/2 ;/*v[OÌTCYÌ1/2*/
 
 max
 =convout[i*POOLOUTSIZE+1+halfpool][j*POOLOUTSIZE+1+halfpool];
 for(m=POOLOUTSIZE*i+1;m<=POOLOUTSIZE*i+1+(POOLSIZE-halfpool);++m)
  for(n=POOLOUTSIZE*j+1;n<=POOLOUTSIZE*j+1+(POOLSIZE-halfpool);++n)
   if(max<convout[m][n]) max=convout[m][n] ;

 return max ;
}


/**********************/
/*  convres()Ö     */
/* ôÝÝÌÊoÍ */
/**********************/
void convres(double convout[][INPUTSIZE]) 
{
 int i,j ;/*JèÔµÌ§ä*/
 
 for(i=1;i<INPUTSIZE-1;++i){
  for(j=1;j<INPUTSIZE-1;++j){
   printf("%.3lf ",convout[i][j]) ;
  }
  printf("\n") ;
 }
 printf("\n") ;	
} 
              
/**********************/
/*  getdata()Ö     */
/*üÍf[^ÌÇÝÝ*/
/**********************/
void getdata(double e[][INPUTSIZE])
{
 int i=0,j=0 ;/*JèÔµÌ§äp*/

 /*f[^ÌüÍ*/
 while(scanf("%lf",&e[i][j])!=EOF){
  ++ j ;
  if(j>=INPUTSIZE){/*Ìf[^*/
   j=0 ;
   ++i ;
   if(i>=INPUTSIZE) break ;/*üÍI¹*/
  }
 }
}

/**********************/
/*  conv()Ö        */
/*  ôÝÝÌvZ    */
/**********************/
void conv(double filter[][FILTERSIZE]
         ,double e[][INPUTSIZE],double convout[][INPUTSIZE])
{
 int i=0,j=0 ;/*JèÔµÌ§äp*/
 int startpoint=FILTERSIZE/2 ;/*ôÝÝÍÍÌºÀ*/

 for(i=startpoint;i<INPUTSIZE-startpoint;++i)
  for(j=startpoint;j<INPUTSIZE-startpoint;++j)
   convout[i][j]=calcconv(filter,e,i,j) ;
}

/**********************/
/*  calcconv()Ö    */
/*  tB^ÌKp    */
/**********************/
double calcconv(double filter[][FILTERSIZE]
             ,double e[][INPUTSIZE],int i,int j)
{
 int m,n ;/*JèÔµÌ§äp*/
 double sum=0 ;/*aÌl*/
 
 for(m=0;m<FILTERSIZE;++m)
  for(n=0;n<FILTERSIZE;++n)
   sum+=e[i-FILTERSIZE/2+m][j-FILTERSIZE/2+n]*filter[m][n];
   
 return sum ;
}

