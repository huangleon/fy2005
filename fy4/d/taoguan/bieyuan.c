#include <room.h>

inherit ROOM;

void create()
{
    seteuid(getuid());
        set("short", "�����Ժ");
        set("long", @LONG
�����Ժ������������䣬�е��á������ʮ��䣬�γ�һ�����ɵ�СԺ����
��������֣���Ϫ��ˮ����������ɽʮ�����ġ�ε����Ȫ���������Ƕ������ó���
ǰ����֮�������ڸ�Ϊ�ÿ�����֮�˵������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "southeast" : __DIR__"stoneroad2",
       	]));
       	set("objects", ([
		__DIR__"npc/dingyunhe" : 1,
 	]) );
        set("outdoors", "taoguan");
     	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
