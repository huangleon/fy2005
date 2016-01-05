#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", HIR"�����"NOR);
    set("long", @LONG
�����Ħ��ʯ������һ�������Ƿ��Ƴ��������֡�Ҳ�������������ĵط�����
��ԭ��ֻ��һ������ͨͨ��С¥���Դ���һ������һ������ͨͨ����ͷ����һ��
��ȫ���ˣ������������µ�С��̽�����۰��ķ����Ϲٽ�磬������Ҳ�ǹ���������
��Ϊ�������ǰ�������������������һ��������ˣ������������ߣ�����������
Χ����ɫ������ʿ�����鶼���������[0;37m��quest��[0;32m���š�

  	����Ұ�� [0;1;33m�������[0;32m(Tian ji)

LONG
    );
    set("exits", ([ /* sizeof() == 4 */
		"down" : __DIR__"fysquare",
      ]));
		set("tianji_square",1);
	
    set("objects", ([
			__DIR__"npc/half_god" : 1,
//			__DIR__"npc/center_soldier" : 1,
      ]) );

    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",10);
    set("no_fly",1);
    set("no_dazuo",1);
    set("no_study",1);
    set("no_fight",1);
    set("no_magic",1);
    set("brief_objects",0);
    setup();
}

int valid_leave(object who, string dir) {
	if (dir == "down") {
		if (who->query("env/checkbrief") == 0) { 
			who->set("env/brief",0);
		}
	}
	return ::valid_leave(who,dir);
}