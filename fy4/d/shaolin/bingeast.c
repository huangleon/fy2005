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
  "west" : __DIR__"luohan",
  "east" : __DIR__"yaoku",
]));
	set("coor/x",10);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
