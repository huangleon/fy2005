// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�����ഫ��Ů洲�ʯ������ȡ����ɽʯ�о�Ӣ���ڣ�ɽɫ���ɽ���죬������
��ɫ��ɽ����ľҲ����ï�ܣ�ɽ�����ƣ��������˵��ɹ��ֺ������ߣ���֮����
ɽ�ٻ��ƣ��������ߣ������������˵��ˡ�ԶԶ������ԯ�壬ȴ��������ȥ��
LONG
        );
	set("exits", ([ 
		"southdown" : __DIR__"sroad",
  		"north" : __DIR__"xuanyuan",
	]));
        set("objects", ([
        	__DIR__"npc/dizi2" : 1,
    	]) );
    
    	set("item_desc", ([
    		"vine": "ɽ�����ƣ�Ҳ�������ʲô������������chop��\n",
    		"ɽ��": "ɽ�����ƣ�Ҳ�������ʲô������������chop��\n",
    		"ɽʯ": "Ů洲�ʯ������ȡ����ɽʯ�о�Ӣ���ڣ�����г��ֵĹ��ߣ�
˵�����㻹���ڳ�Щʲô����dig��\n",
    		"rock": "Ů洲�ʯ������ȡ����ɽʯ�о�Ӣ���ڣ�����г��ֵĹ��ߣ�
˵�����㻹���ڳ�Щʲô����dig��\n",
    	]));
    	
        set("stone_amount", 2);
        set("outdoors", "huangshan");
		set("coor/x",-140);
		set("coor/y",-20);
		set("coor/z",40);
		setup();
}

void init()
{
	add_action("do_chop","chop");
}


int do_chop(string arg)
{
    object obj, me;
    if(!arg || arg=="") return notify_fail("��Ҫ����ʲô��\n");
    if( arg == "vine" || arg == "ɽ��")
	{
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj )
        {
        	write("������֣���ô����\n");
        	return 1;
        }
        if( obj->query("jungle"))
        {
        	if( !query("exits/north") ) {
        	set("exits/north", __DIR__"xuanyuan");
        	message_vision(sprintf("$N�����е�%s����һ���򱱵�·��\n",obj->name()),
                me);
        	me->perform_busy(1);
        	}
        	else
        		message_vision(sprintf("$N�����е�%s�����Ƶ�ɽ�٣�\n",obj->name()), me);
        }
        else
        	message_vision(sprintf("$N�����е�%s�����Ƶ�ɽ��һ���ҿ���̫��˳���ˣ�\n",obj->name()),me);
        }
    else
         write("��Ҫ����ʲô��\n");
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
			
		if( me->query_str() < 30) {
			write("������������һ�٣���Ӳ����������㻢�ڷ�ʹ(��30����)��\n");
			message("vision", me->name() + "����һ�٣�ֻ�����ϡ���������һ��������ȴ˿��δ��\n",
				environment(me), me);
		} else {
			if (random(10) > 7 && query("stone_amount") >= 0) {
				message_vision("$N����������һ�١�\n", me);
				write(HIW"�㷢��һ��������õ�ʯͷ��\n"NOR);
				if (random(10) > 7) {
					item = new(__DIR__"obj/xishi2");
					item->move(this_object());
				} else {
					item = new(__DIR__"obj/xishi");
					item->move(this_object());
				}
			   	if (!REWARD_D->check_m_success(me,"��¶��ʯ")	// �����˻����Ѿ���ʼ�˾Ͳ�Ӧ������mark
			   		 && !REWARD_D->riddle_check(me,"��¶��ʯ")) 
					REWARD_D->riddle_set(me,"��¶��ʯ",1);
				add("stone_amount", -1);
		} else {
				write("���ڵ������˸���ӣ�������ʲôҲû���ҵ�,�����ط�����������ڣ�\n");
		}	
	}
	me->start_busy(1);
}


void reset() {
	::reset();
	if (!random(4))	set("stone_amount", 2);
	delete("exits/north");
}
