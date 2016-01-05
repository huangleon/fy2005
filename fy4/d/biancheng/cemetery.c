#include <ansi.h>
inherit ROOM;

void init(){
	add_action("do_leave","kneel");
}


int do_leave(string arg)
{
	object room, me;
	me = this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("��������æ���ء�\n");
		
	room=find_object(__DIR__"cemetery0");
	if(!room) room=load_object(__DIR__"cemetery0");
	
	message_vision("$N�����ع��ڵ��ϴ�У��ȿ���ѹ���������������·�ˣ����ҳ�ȥ�ɣ�\n", me);
	message_vision(WHT"\n�ص����Ȼ����һ��ַ磬��$N����������\n"NOR,me);
	
	tell_object(room,me->name()+"��ͨһ���Ӱ���е���������һ��ãȻ�����ӡ�\n");
	me->move(room);
	return 1;
}


int valid_leave(object obj, string dir){
	object another;
	int num;
	
	seteuid(getuid());
	
	if (!present("zombie", this_object()) && random(10)>7) {
		switch (obj->query("quest/quest")) {
			case "�Ͻ�ʬ":	another = new(__DIR__"npc/zombie4");
							break;
			
			case "�߽�ʬ":	another = new(__DIR__"npc/zombie3");
							break;
			
			case "�ݽ�ʬ":	another = new(__DIR__"npc/zombie2");
							break;
			
			case "С��ʬ":	another = new(__DIR__"npc/zombie1");
							break;
		}	
		
		if (!objectp(another)) {
			sscanf(file_name(this_object()),__DIR__"cemetery%d",num);
			switch (num) {
				case 1:
				case 2:
				case 3:
				case 4:	 another = new(__DIR__"npc/zombie1");
						 break;
				case 5:
				case 6:
				case 7:
				case 8:  another = new(__DIR__"npc/zombie2");
						 break;
				case 9:
				case 10:
				case 11:
				case 12: another = new(__DIR__"npc/zombie3");
						 break;
				default: another = new(__DIR__"npc/zombie4");
						 break;
			}
		}		
		another->move(environment(obj));
		message_vision(YEL"�ض�������վ��һ��������������!\n"NOR, obj);	
		return notify_fail(another->name()+"������צ�ص����������ǰ��\n");
	}	
	return 1;
}