#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��Ұ");
        set("long", @LONG
���������ǻ�Ұ�ˣ�������ׯ԰������ߡ�̫ƽ���ʮ�����˼ң�һ������
��ɽ����ү�ģ���һ������������ġ�û����֪������������ʲô��Ҳû��֪��
����������ֻ֪��������ǰ����������ׯ԰�����ׯ���������ɸ�ǽ��ǽ�ϵ�����
���С���ǽ�������ţ����Ϲ���һ���Ѿ�����һ���ͭ����
LONG
        );
        set("exits", ([ 
		"northwest": __DIR__"mroad8",
		"west": __DIR__"swamp1",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"door": "һ�����ţ����Ϲ���һ���Ѿ�����һ���ͭ����\n",
		"����": "һ�����ţ����Ϲ���һ���Ѿ�����һ���ͭ����\n",
		"ͭ��": "���������֣�û�����ף�ֻ��һ��СС��ת�̡�\n",  
		"lock": "���������֣�û�����ף�ֻ��һ��СС��ת�̡�\n",  
		"ת��": "���ת��Ҳ���ǿ��ŵĻ��أ������תת����\n",
		
	]));
	set("coor/x",-10);
	set("coor/y",-90);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


void init() {
	add_action("do_turn","turn");
	add_action("do_open","open");
}

int do_open(string arg) {
	if (arg=="door" || arg =="����" || arg=="��"){
		tell_object(this_object(),"���������ţ�һ�㶯��û�С�\n");
		return 1;
	}
	return 0;	
}

int do_turn(string arg){
	object me,room, paper;
	me=this_player();
	
	if (arg=="ת��" || arg == "lock" || arg == "ͭ��") {
		if (!REWARD_D->check_m_success(me,"�Ѫ���ׯ")) {
			message_vision("$N����ͭ����ת��ת��һ�㶯��û�У�����û�ҵ����š�\n",me);
			if (REWARD_D->riddle_check(me,"�Ѫ����")==7)	{
				REWARD_D->riddle_set(me,"�Ѫ����",8);
				tell_object(me,BLU"��Ȼһ����Ӱ��������ӹ����㼱ת��ȴֻ�з���������\n"NOR);
				tell_object(me,BLU"һ��СֽƬ���ƺ��Ƶ�Ʈ������ϡ�\n"NOR);
				paper= new(__DIR__"obj/paper");
				if (!paper->move(me))
					paper->move(environment(me));
			}				
			
			return 1;
		}
		tell_object(me,"������ͭ������ת������ת��������ת��\n");
		tell_object(me,"����û�п�����Ľ���ȴ��ʼҡ��������\n");
		message_vision(YEL"���ؾ���Ȼ���˿�����¶���˸��ض���$Nһ�������Խ��˶��\n"NOR,me);
		room = find_object(__DIR__"pond");
        	if(!objectp(room))
                 	room = load_object(__DIR__"pond");
        	me->move(room);
        	return 1;
	}
	return 0;
}