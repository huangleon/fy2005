inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��¥");
        set("long", @LONG
��¥��¥���д�����ǰ���£������л���
��������Ǿޱ���������¡�
����΢΢�ĵƻ�������ҡ�����¹�Ӵ����ս��������������ϡ�
��������߲�����Ǿޱ�����и���Ǿޱ���˵��ˡ�
LONG
        );
        set("exits", ([ 
		"down" : __DIR__"teashop",
	]));
        set("objects", ([
	]) );
        set("coor/x",-20);
        set("coor/y",20);
        set("coor/z",10);
	set("map","zbwest");
	setup();
}



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

