#include <room.h>
inherit ROOM;

void create()
{
  set("short","̫ξ��");
  set("long",@LONG
������������̫ξ���ר�ż����ƴ����˶ų�ġ������������ڵĻ��
�����������Ϊ�������ɡ������Χ���������б��ٶ�ʮ��顣�������������Ƕ�
�Ϸ����δ����������޶�����Ǳ��������Ϸ��ġ����ηⶫ��������ʥ�۱�������
���ᱮ�������ţ��ߴ���ΰ��������ף����ƷǷ���
LONG
  );
  	set("exits",([
        	 "east":__DIR__"peitian",
         	 "west":__DIR__"yuhua",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  	
}
