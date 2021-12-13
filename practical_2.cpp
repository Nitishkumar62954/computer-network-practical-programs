#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
using namespace std;
#define time 5
#define max_seq 1
#define tot_pack 5
intrandn(int n)
{
return rand()%n + 1;
}
typedefstruct
{
int data;
}packet;
typedefstruct
{
int kind;
intseq;
intack;
packet info;
}frame;
typedefenum{ frame_arrival,error,time_out}event_type;
frame data1;
//creating prototype
voidfrom_network_layer(packet *);
voidto_physical_layer(frame *);
voidto_network_layer(packet *);
voidfrom_physical_layer(frame*);
void sender();
void receiver();
voidwait_for_event_sender(event_type *);
voidwait_for_event_receiver(event_type *);
//end


#define inc(k) if(k<max_seq)k++;else k=0;


inti=1;
char turn;
int disc=0;
int main()
{
while(!disc)
{  sender();
     // delay(400);
receiver();
   }
getchar();
}
void sender()
{
staticintframe_to_send=0;
static frame s;
packet buffer;
event_type event;
staticint flag=0;       //first place
if (flag==0)
     {
from_network_layer(&buffer);
   s.info=buffer;
s.seq=frame_to_send;
cout<<"\nsender information \t"<<s.info.data<<"\n";
cout<<"\nsequence no. \t"<<s.seq;


turn='r';
to_physical_layer(&s);
flag=1;
     }


wait_for_event_sender(&event);
if(turn=='s')
 {
if(event==frame_arrival)
      {
from_network_layer(&buffer);
inc(frame_to_send);
      s.info=buffer;
s.seq=frame_to_send;
cout<<"\nsender information \t"<<s.info.data<<"\n";
cout<<"\nsequence no. \t"<<s.seq<<"\n";


getch();
turn='r';
to_physical_layer(&s);
      }


 }


}                   //end of sender function


voidfrom_network_layer(packet *buffer)
{
     (*buffer).data=i;
i++;
}                            //end of from network layer function


voidto_physical_layer(frame *s)
{


     data1=*s;
}             //end of to physical layer function


voidwait_for_event_sender(event_type *e)
{
staticint timer=0;
if(turn=='s')
      {   timer++;
    //timer=0;
return ;
  }


else                          //event is frame arrival
    {
timer=0;
       *e=frame_arrival;
    }


}              //end of wait for event function


void receiver()
{
staticintframe_expected=0;
frames,r;
event_type event;
wait_for_event_receiver(&event);
if(turn=='r')
{  if(event==frame_arrival)
    {
from_physical_layer(&r);
if(r.seq==frame_expected)
    {
to_network_layer(&r.info);
inc (frame_expected);
    }
else
cout<<"\nReceiver :Acknowledgement resent \n";
getch();
turn='s';
to_physical_layer(&s);
      }


     }
}                     //end of receiver function




voidwait_for_event_receiver(event_type *e)
{
if(turn=='r')
     {
   *e=frame_arrival;
     }
}


voidfrom_physical_layer(frame *buffer)
{
    *buffer=data1;
}


voidto_network_layer(packet *buffer)
{

cout<<"\nReceiver : packet received \t"<< i-1;

cout<<"\n Acknowledgement  sent \t";

getch();

if(i>tot_pack)
      {
disc=1;

cout<<"\ndiscontinue\n";

      }

}       
 //end of network layer function

