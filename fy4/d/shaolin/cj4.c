// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
ר���о�����а���书�������Ƕ���������ǿ����������Ϊа���书�����ٳ�
���������������ħ�����������һ�㲻������������������˵�о�а���书�ˣ�
���Ǽ����ⶾ������鼮���������о�����Ȼ��ѧ֮�������һ�ģ����������ˣ�
���������ô�о�а���书�����޺���
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj5",
  "down": __DIR__"cj3",
]));
        set("objects", ([
                __DIR__"obj/slayedman1" : 1,
                __DIR__"obj/slayedman2" : 2,
                __DIR__"obj/slayedman1" : 1,
                "/obj/weapon/sword":	2,
       ]) );
	set("no_fly",1);
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",50);
	set("no_lu_letter",1);
	setup();
	create_door("down", "door","ľ��", "up", DOOR_CLOSED);

}
void init()
{
	this_player()->apply_condition("unknown",
                (int)this_player()->query_condition("unknown")
                + random(3)+3);
}

