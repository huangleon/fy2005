inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����ɽ��");
        set("long", @LONG
����ǰ�ߣ���·��Ϊ��������������ϡ��������ż�����ܼ������е�������
�����˼�����ɱ֮��������Ҳ�ɶ�ǧ�׼�����������ǧ���ף����¡���ѹ��֮���͡�
һʱ�䣬�ƺ��ӿ���ͻȻ���뵽�϶���ԶԶ��ȥ������������������֮�С�
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"yuzhu",
		"east" : __DIR__"kunlun2",
	]));
        set("item_desc", ([
        	"����":"�����������һ�����͵�����λ�ϣ������Ѿ�û���ˡ�\n",
        ]));
        set("objects", ([
		__DIR__"obj/mache": 1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-900);
        set("coor/y",500);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}


void	reset() {
	object mache, drum, trumpet;
	:: reset();
	if (!mache = present("mache", this_object()))	return;
	if (!drum = present("drum", mache)) {
		drum = new(__DIR__"obj/drum");
		drum ->move(mache);
	}
	if (!trumpet = present("trumpet", mache)) {
		trumpet = new(__DIR__"obj/trumpet");
		trumpet ->move(mache);
	}
}
	
		