// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
����������⣬�����Դ�������������Ϊ�������й������Կ�����ӵɮ��������
��������������������������ʦ�䷢���֣�Э�����죬��������������Ŀ����ɫ����
����һӦ��ȫ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bingwest",
]));
        set("objects", ([
                "/obj/weapon/sword" : 1,
                "/obj/weapon/blade" : 1,
                "/obj/weapon/staff" : 2,
                "/obj/weapon/hammer": 1,
                "/obj/weapon/whip"  : 1,
                "/obj/weapon/axe"   : 2,
       ]) );
	set("coor/x",-20);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
