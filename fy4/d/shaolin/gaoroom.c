// annie 07.2003
// dancing_faery@hotmail.com

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ߺ���");
        set("long", @LONG
���Ƹߴ���ʤ�����������������������ܵ����֮��������ȥ�������������
ɮ�����ܶ����������£������ȴ���ⲻ�˿�����ƹŷ𣬼�įһ������ʹ������
˽����ɽ�������Ϊ�¹����ȣ��ط����֣�����ľ�㣬�������С�
��������������Ͽ���һ�����֣����޼������⣬���ݣ��ߺ�������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"kuoran",
]));
        set("objects", ([
                __DIR__"npc/gao" : 1,
       ]) );

//	set("no_fly",1);	able to fly; annie.
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();

}


void reset()
{
	if (present("gao meng",this_object()))
		return;
	::reset();

}
