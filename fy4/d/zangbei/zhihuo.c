inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
�����ӵ��ϰ���һ��޴����ʯ����ӥչ�ḩ�ˮ�������Ϊ��֪�����ɡ���
��Ϊ�����һ��������ס�ˡ����Ǵ�˵�й������ɹ������񡣺ӱ���Ƭʯ�ѳɵ���
�ضѱȱȽ��ǣ�ÿ�����´��ޣ������˶�Ҫ��ʯתɽ���ں�����ԡ���¡��ӵı���
�����۴��αȣ���һ��[33m��ԶС��[32m���ӵ��ϰ�ѭɽ�ƶ��ϣ��������ĺ���ɽ��
LONG
        );
        set("exits", ([ 
		"southup":  __DIR__"echu",
	]));
	set("item_desc", ([
		"river":	"ˮ���ļ������ǲ��������������ȥ(wade)��\n",
		"������":	"ˮ���ļ������ǲ��������������ȥ(wade)��\n",
	]) );
	
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2020);
        set("coor/y",640);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void init() {
	add_action("do_wade","wade");
	remove_call_out("greeting");
	call_out("greeting", 4, this_player());
}


void greeting(object me)
{
	object ob;
	ob=this_object();
	if( !me || environment(me) != this_object() ) return;
	message_vision(CYN"\n\n�԰����������ش���ϴ�¸����ǵ�˵Ц�������ź�ˮ������Ʈ��Զ��������\n\n"NOR,me);
	
}

int do_wade(string arg) {
	
	object me;
	
	me=this_player();
	if (!arg || arg == "С��" || arg== "river") {
		if (me->query_temp("zangbei/wade_2"))
			return notify_fail("���Ѿ��ں�ˮ�����ˡ�\n");
		message_vision("$N����ѥ�������ˮ�У����ѵ���԰���ȥ��\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/wade_2",1);
		return 1;
	}
	tell_object(me,"��Ҫ��ʲô��\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"bank");
	if (!objectp(room)) room=load_object(__DIR__"bank");
	tell_object(me,HIG"�������ߵ��˳����ӵĶ԰���\n"NOR);
	message("vision",HIG""+me->name()+"ˮ���ܵشӺ�������������\n"NOR,room);
	me->move(room);
	me->delete_temp("zangbei/wade_2");
	return 1;
}