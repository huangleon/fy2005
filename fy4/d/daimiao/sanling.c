#include <room.h>
inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
���������������������ܳ��ɹ���巡���Ӻ���������ˡ���˵����
�ڶ���̩ɽʱ����᷶������ż���������λ���ˣ����Ǿͼӷ�Ϊ������������
�����ｨ�˴����롣
LONG
  );
  	set("exits",([
        	 "west":__DIR__"peitian",
         	 "east":__DIR__"hanbai",
         	 "south":__DIR__"guaying",
        ]));
        set("objects", ([

       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  	
}
