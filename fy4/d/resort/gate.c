#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"����ׯ��"NOR);
        set("long", @LONG
����һ�����ɵ�ɽׯ����ɽ��ˮ���ƺ��ۼ�����ؼ��������ǽ������������
�ģ����̾�Ө�����ӣ�����ȥ����ʯһ���⻬ϸ�塣Ժ��Ҳ���ô���Χ�ɣ����Ϲ�
��һ��ľ�ң�������ľ���ֵ�д���ĸ����֡���ѩɽׯ���������½����飺  
             ���������ڽ�����������Ī�����
LONG
        );
        set("exits", ([ 
	  "north" : __DIR__"front_yard",
	  "south" : __DIR__"small_river",
	]));
       	set("objects", ([
                __DIR__"npc/guard" : 1,
        ]) );

        set("indoors", "resort");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

