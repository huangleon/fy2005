inherit ROOM;
#include <ansi.h>;

void create()
{
    object con, bot;

	set("short", "�ķ�");

	set("long", @LONG
������������һ����ڣ�����ܾ�����ľ���ڵ��⼸���������գ�ʱ��ʱ����
˸�ż���Ʈ�������Ĺ�𣬺��紵��ʱ��һ������ɫ�������ƺ��ӻ�ڣ������Զ
����ʱ����һ����Ұ���İ����������ǹ�ޡ�������ϸ�Ŀ�����ͷ�ƺ����˶�����
�ڷ���һ����ɫ�Ĵ�ƿ��
LONG);

	set("get_ciping",1);
	set("be_ambushed",1);
	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"tomb2",
	]) );
    	set("objects", ([
        	__DIR__"npc/hong" : 1,
        	__DIR__"npc/cui" : 1,
        	__DIR__"obj/fentou": 1,
        ]) );

	set("coor/x",-50);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_get","get");
}

void reset()
{
	object *inv;
	object item, fentou;
	::reset();
	set("be_ambushed",1);
	
	fentou = present("fentou", this_object());
	if (!fentou)	return;
	
	if (!present("ping", fentou)) {
		item = new(__DIR__"obj/ciping");
		item->move(fentou);
	}
}


int do_get(string arg)
{
	object chi, wu;
	int kee,sen,gin;
	
	object me, container;
	string *ban_location, *ban_item, arg1, arg2,what, where; 
	int num, i, ban;
					
	me=this_player();
	if(!arg) return notify_fail("������ʲô��\n");
	if (sscanf(arg,"%s from %s", what, where)!=2)		return 0;
	if (!objectp(container = present(where, this_object())))	return 0;

	if (base_name(container)!=AREA_FUGUI"obj/fentou")
		return 0;
	ban_item = ({ "ping", "ƿ" });				// well, you got to keep this right.
	
	if (what == "all")							ban = 1;
	if (member_array(what,ban_item)!=-1) 		ban = 1;
	if (present(what, container) && sscanf(what,"%s %d",arg2,num)==2)
		if (member_array(arg2,ban_item)!=-1) 	ban = 1;
		
	if (ban) {
		if (query("be_ambushed"))
		{
			kee = (int) me->query("max_kee")/4;
			gin = (int) me->query("max_gin")/4;
        	sen = (int) me->query("max_sen")/4;
        	message_vision(HIR"$N���������ͷ��׼���ö�����\n\nͻȻ....................\n\n"NOR, me);
			message_vision(HIR"һ˫��ͻȻ�ӷ�Ĺ���������������$Nϥ���ϵġ�����Ѩ������һ˫\n��ͬʱ�ӻ�ѩ�������������������ź�������$N�����ס�\n\n"NOR, me);
			if (me->query("combat_exp")<400000) {
				me->die();
				me->set_temp("last_damage_from","�а��������\n");
				message_vision(HIR"��˫��������Ϣ���������˷�Ĺ�\n"NOR, me);
				return 1;
			}
			me->receive_wound("kee", kee);
        	me->receive_wound("gin", gin);
        	me->receive_wound("sen", sen);
        	me->set_temp("last_damage_from","�а��������\n");
        	me->apply_condition("redsnake",5+random(10));
			set("be_ambushed",0);
			me->start_busy(2);
			chi = new(__DIR__"npc/chi");
			wu = new(__DIR__"npc/wu");
			chi->move(this_object());
			wu->move(this_object());
			chi->kill_ob(this_player());
			wu->kill_ob(this_player());
			return 1;     
		}
		return 0;
	}
	return 0;
}

