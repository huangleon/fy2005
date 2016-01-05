#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��᣺�");
        set("long", @LONG
������ᣣ���̳�У������ŵģ���Ȼ��һ�������ӹ�ĸ������ڵ�ľ���ڵƹ�
�������ڹ⣬�Ÿ���״���죬��Ŀ�����Ĺ��ӣ������������Ŀ�Ĺ�ĸ���е��ڿޣ�
�е���Ц���еķ·�Ҫ���˶��ɣ���������������˱�Ź�ĸ�������鷿����̵���
������������������֡�
LONG
        );
        set("exits", ([ 
		"north":  __DIR__"songhouse",
	]));
        set("objects", ([
        	__DIR__"npc/songson": 1,
        	__DIR__"npc/ghost1": 1,
        ]));
        
        set("item_desc", ([
	
	 ]));
	set("guizi",5);
	set("coor/x",-60);
	set("coor/y",-65);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


void init(){
	add_action("do_kneel","kneel");
	add_action("do_kneel","ketou");
}




int do_kneel(){
	object song,guizi;
	if (this_player()->query_busy() || this_player()->is_fighting())
		return notify_fail("��������æ��\n");
	message_vision("$N���ڷ��ӹ�ĸ��ǰ�����������ؿ���������ͷ��\n",this_player());
	this_player()->start_busy(1);
	if (song=present("song saiyu",this_object()))
		song->ccommand("pat "+this_player()->get_id());
	if (query("guizi") && !present("guizi",this_object())) {
		tell_object(this_player(),BLU"һ�����紵���������ƺ���ЩЦ�����㲻���������˼�Ƥ���\n"NOR);
		guizi=new(__DIR__"npc/ghost2");
		guizi->move(this_object());
		add("guizi",-1);
	}
	return 1;
}


void reset(){
	::reset();
	set("guizi",5);
}