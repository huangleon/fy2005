
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ƺ");
        set("long", @LONG
������һƬ���̵Ĳ�ƺ��һЩ�޴�����������ڲ�ƺ���ܡ���ƺ��ɢ׺��һЩ
��֪����Ұ�����к�ģ��Ƶģ����ģ��׵ġ���ЩҰ���ѱ��̵Ĳ�ƺ��׺�ĳ�����
��������ͷС¹���е�������ȥ��͸�����ɵĿ�϶������Լ�������Ե�ˮ����
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"stonelin",
  "south" : __DIR__"river",
]));
        set("objects", ([
        __DIR__"obj/flower" : 1,
                        ]) );

        set("outdoors", "palace");
	set("coor/x",-80);
	set("coor/y",70);
	set("coor/z",10);
	setup();
}
int valid_leave(object me, string dir)
{
	message_vision( HIG "һ�󵭵��Ļ���Ʈ����$N���ɵ�������һ������\n\n\n"NOR,me);
	if(!me->query_condition("green_blood"))
		me->apply_condition("green_blood",random(10)+10);

	return 1;
}
void reset()
{
	object *inv;
	object con, item, flower;
	::reset();
	flower= present("flower", this_object());
        inv = all_inventory(flower);
        if( !sizeof(inv)) {
	con = new(__DIR__"obj/wanghua");
	item = new(__DIR__"obj/wangguo");
	item->move(con);
	con->move(flower);
	}
}
