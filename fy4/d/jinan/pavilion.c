#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", WHT"��ˮ����"NOR);
	set("long", @LONG
����ʯ������ӣ������軨�ķ�����������·���ɢ��ǳǳ���������
�㡣�������ϼ��ã�������ˮͤ������һ����ů���λƣ�ֻ�Ƿ������ã���
�����꣬СС��̨ͤ���ڣ��������С�ã�����������������ˣ�ȴ����ɢ��
��ȥ�������ں��������ˡ�
LONG
	);
	set("exits", ([ 
  "out" : __DIR__"bridge4",
]));
	set("no_fight",1);
        set("objects", ([
//        __DIR__"npc/zhou" : 1,
//        __DIR__"npc/song" : 1,
// �ؼ���..
//        __DIR__"npc/thief" : 1,
// �����..
        __DIR__"npc/zhuxiang" : 1,

                        ]) );
	set("coor/x",100);
	set("coor/y",120);
	set("coor/z",10);
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
