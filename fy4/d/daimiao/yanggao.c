#include <room.h>
inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
������ų�Ϊ�����ߡ�����˼����ɽ�¿���̩ɽ��֮�ָߣ���Ŀ���������
�����о�������Ľ�¥�������������ģ��ʻ�������������ûʣ����ƷǷ�����
���������֮�ơ�
LONG
  );
  	set("exits",([
        	 "north":__DIR__"e_wall_1",
         	 "west":  __DIR__"e_yemen",
         	 "up":	__DIR__"jiaolou2",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",30);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  	
}

