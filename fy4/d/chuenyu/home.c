inherit DOOR_ROOM;
#include <room.h>
void create()
{
        set("short", "����С��");
        set("long", @LONG
����һ�����ƾɵ�ľ�ݡ�ÿ��ɽ�紵�������ᷢ����֨֨ѽѽ�����������ϲ�
��һ��СС�ĳ�����ľ�ݵĺ�����һ�����ɵĻ�԰����԰�ﴩ���������֮����һ
�����̵�С��ƺ�������档��������һ��С·��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"smallstorage",
  		"north" : __DIR__"littlegarden",
  		"west" : __DIR__"smallyard",
  		"southwest" : __DIR__"dustyroad3",
		]));

        set("objects", ([
                __DIR__"npc/oldliu" : 1,
        ]) );
	
		set("coor/x",-10);
		set("coor/y",-10);
		set("coor/z",-20);
		setup();
}