// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�ߵ������ֻ����ɫ��Ȼһ��������ƻ�է�١�̧ͷ��ȥ��ȴԭ����ǧ��
���񴱴�����ס�˰�Ļ��ա���������������͸��һ˿�����ĺ�ɫ���ֱ�Ѱ
������߳��������࣬������ƺ�����������˵���������֣�һʱ��ȴ���ǿ�
˼���á�
LONG
        );
	set("objects", ([
		__DIR__"obj/bamboo" : 1,
		__DIR__"npc/xx" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"qishi",
  		"south" : __DIR__"qingxi",
	]) );

   	set("shoots_amount", 3);
	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",-10);
	setup();
}


void init(){
	if(NATURE_D->get_season() == 1 && NATURE_D->get_weather() == "С��") {
		tell_object(this_player(), "���У�ֻ��������֮�в��ϴ��������ࣵ�������\n");
	}
	add_action("do_search", "search");
}

int do_search(){
	message_vision("$N��ϸ�������ֵ���Ѱ�ҡ�\n", this_player());
	if(NATURE_D->get_season() == 1 && query("shoots_amount") >= 0) {
		tell_object(this_player(), "�㷢��һ�����۵�����ոչ������档���԰����ٳ�����\n");
		this_player()->set_temp("marks/found_shoot", 1);
	} else {
		tell_object(this_player(), "��ʲôҲû�з��֡�\n");
	}
	return 1;
}

int dig_notify() {
	object me, item;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	if(me->is_busy()) { 
	    write("����������æ��\n");
	    return 1;
	}
	if(me->is_fighting()) return 0;
	if(NATURE_D->get_season() != 1 || !me->query_temp("marks/found_shoot")) {
	    message_vision("$N����������һ�٣������������Ƶ������ʲôҲû�з��֡�\n", me);
	} else {
		if (query("shoots_amount") >= 0) {
    		message_vision("$N����������һ�١�\n", me);
        	message_vision("һ�����۵�����¶�˳�����\n", me);
        	me->delete_temp("marks/found_shoot");
        	item = new(__DIR__"obj/bshoot");
        	if(objectp(item)) {
        		item->move(this_object());
        		add("shoots_amount", -1);
			}
		}
	}
	me->start_busy(1);
}

void reset(){
	::reset();
	set("shoots_amount", 3);
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
