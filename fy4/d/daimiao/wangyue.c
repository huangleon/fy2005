#include <room.h>
inherit ROOM;

void create()
{
  set("short","����¥");
  set("long",@LONG
����¥�������ŵ����¥��ʽ��ͬ���������ȣ��������ȣ����ƶ����ڡ�վ��
����¥�ϣ�������ΡΡ̩������룬����հ������������ʡ�
LONG
  );
  	set("exits",([
        	"down":__DIR__"houzai",
        	"west" :__DIR__"jiaolou3.c",
         	"east" :__DIR__"jiaolou4.c",       	
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",10);
	setup();
  	
}
