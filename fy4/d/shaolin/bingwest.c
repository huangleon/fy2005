// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɮ��Ժ");
        set("long", @LONG
��������ɮ��������������Ķ������־�Ӣ�����г���Զʤ����Ժ���ϵ���ϯ��
��˿�񱻣����������ֻ���ÿ��ǰ���к�ľ��һ�ţ����и��м�λ����ɮ��רְ��
ɨ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"luohan",
  "west" : __DIR__"wuku",
]));
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
