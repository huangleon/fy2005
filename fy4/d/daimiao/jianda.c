#include <room.h>
inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
������ų�Ϊ�����󡱣���˼����ɽ�¿���̩ɽ��֮�ָߣ���Ŀ���������
�����о�������Ľ�¥�������������ģ��ʻ�������������ûʣ����ƷǷ�����
���������֮�ơ�
LONG
  );
  	set("exits",([
        	 "north":__DIR__"w_wall_1",
         	 "east":  __DIR__"w_yemen",
         	 "up":	__DIR__"jiaolou1",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-30);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  	
}
