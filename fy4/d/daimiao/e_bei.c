#include <room.h>
inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
���ܵ������л��Ȱټ䣬���ʰ�������Ķ����������������»���ʮ��������
ʮ��˾���������ɱ����ϳ�������������ʮ�ſ飬����������������ʱ����̩ɽ��
ʯ���ĸ��Ʊ�����������ξ��⸮��֮�����������ʹȳǳ��������ž����̡���
�����γ�̫�ط�������֮��������̫��ͼ���͡�����ʫ�����ȡ�
LONG
  );
  	set("exits",([
        	 "west":__DIR__"dongbei",
         	 "south": __DIR__"chuihua",
        ]));
        set("objects", ([
        	__DIR__"npc/weaponer":	1,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  	
}
