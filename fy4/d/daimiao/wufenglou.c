#include <room.h>
inherit ROOM;

void create()
{
  set("short","���¥");
  set("long",@LONG
�����Χ��ǽ���а��ţ��������Ҵ���⣬�������ϽԽ�����¥���������ϵ�
�����¥�����߸Ƕ������ʻ棬�����ûʣ�����Ρ�롣
LONG
  );
  	set("exits",([
        	 "down":__DIR__"zhengyan",       
        	 "east": __DIR__"jiaolou2",  	
        	 "west": __DIR__"jiaolou1",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",10);
	setup();
  	
}
