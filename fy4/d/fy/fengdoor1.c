#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"��̳"NOR);
        set("long", @LONG
		
      	       .
              /=\\		
             /===\ \	            ��̳�˽�Ǯ��������̳��������ʣ����
            /=[0;1;37m��[0m==\' \	   	�Իͣ�����ķ����е����Ϲ��������绽��
           /=======\'' \	Ȩ�㳯Ұ��Ұ�ġ���ʹ�ڷ��Ƴ����������ۡ�
          /=========\ '  \	���˱����ĵط����Ϲٽ�����ɿ���˵���Ϲ�
         /====[0;1;37m̳[0m=====\' /	������ɿ���˵�����������еİ�����������
        /=============\/	�Ļʵۡ�
                   
LONG);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wcloud1",
  "east" : __DIR__"fysquare",
  "north" : __DIR__"qcyzdian",
  "south" : __DIR__"pxhdian",
]));
        set("outdoors", "fengyun");
        set("objects", ([
//        __DIR__"npc/mei": 1,
                        ]) );

	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
//	replace_program(ROOM);
}


/*
void init() {
	  add_action("do_dazuo","dazuo");
	}
	
int do_dazuo(string arg) {
	object me;
	me=this_player();
	tell_object(me,"�˵ز��ܴ�����\n");
	return 1;
}*/

