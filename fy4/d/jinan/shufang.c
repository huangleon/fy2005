inherit ROOM;
void create()
{
        set("short", "֪���鷿");
        set("long", @LONG
������ͥ���鳨�����й�һ������ɽˮ����һ����ͭ��¯��¯������Ʈ�졣��
����һ��������齣��ұ߼��϶�������ͼ�顣�ش�һֻ���ϣ������ķ��ı�������
ͥ����ֲ��໨ľ�������ʮ�����š������ƺ�����һ�����䣬������Ž����š�
LONG
        );
	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"govern",
		"east" : __DIR__"shufang2",
	]));
    set("objects", ([
        __DIR__"npc/governor" : 1,
    ]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object obj, string dir){
	object gov;
	if(dir == "east"){
		
			if (REWARD_D->riddle_check( obj, "�ݺ�����")){
				message_vision("$N��������ȥ��\n", obj);
				return 1;
			}else {
				if(gov = present("master yin", this_object())){
					message_vision("$N���������Ǳ�����⣬�����˵�Ī�롣��\n", gov);
					return notify_fail("");
				} else {
					message_vision("$N��������ȥ��\n", obj);
					return 1;
				} 
			}
	}	
	return :: valid_leave(obj, dir);
}
	
/*		
		if(NATURE_D->is_day_time()){
				if(obj->query("marks/����������ƽǹ��")){
				message_vision("$N��������ȥ��\n", obj);
				return 1;
			} else {
				return notify_fail("������Ŵ򲻿���\n");
			}
		} 
		if(obj->query("marks/���������ݺ�����") || obj->query("marks/����������ƽǹ��")){
			message_vision("$N��������ȥ��\n", obj);
			return 1;
		} else {
			if(gov = present("master yin", this_object())){
				message_vision("$N���������Ǳ�����⣬�����˵�Ī�롣��\n", gov);
				return notify_fail("");
			} else {
				message_vision("$N��������ȥ��\n", obj);
				return 1;
			}
		}
	}
	return 1;
}*/