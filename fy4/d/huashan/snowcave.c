#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"ѩ����"NOR);
        set("long", @LONG
�±�����һ���˹���̵�ɽ����������û����֪������ΪʲôҪ����ɽ����
��������ϰϰ����ʹ�������ȵ��ļ���ֻҪһ�붴�ڣ����⾡����������ȥ�����
ƺ�������ڣ����Ͽ�������ʯ�ưߵ��ʾ�Ө����ѩ������Ʈ�䡣
LONG
        );
    set("exits", ([ 
  		"southwest" : __DIR__"qingke",
	]));

	set("objects", ([
		__DIR__"npc/bailong" : 1,
		__DIR__"npc/fang": 1,
	]) );  
	set("doing_rescue", 0);
    set("indoors", "huashan");
	set("no_lu_letter",1);
	set("coor/x",-11);
	set("coor/y",-28);
	set("coor/z",0);
	setup();
}

void init(){
	if (REWARD_D->riddle_check(this_player(),"��ɽ����"))
	{
//	if(this_player()->query("marks/���������")) {
		call_out("save_me", 1, this_player());
	}
	add_action("do_rescue", "rescue");
}

void save_me(object me){
	object sun, fang;
	sun = present("sun yuanchao", this_object());
	fang = present("fang girl", this_object());
	if(objectp(sun) && objectp(fang) && !query("doing_rescue")) {
		message_vision("\n$Nԭ����Ȼ���˵����񿴵�$n��Ȼһ�����̶�����һ˿���۸��ӵĹ�â��\n", fang, me);
		message_vision("$N���ܵ�$n��ǰȴ����Զ�����裬ֻ�ýе��������ң���\n��Թ�����������������̡�\n", fang, me);
		tell_object(me, "���������塡�������\n", me);
		me->set_temp("marks/hs_in_rescue",1);
		set("doing_rescue", 1);
//		call_out("reluctant", 40, me); // Silly, what if I killed sun but didn't say yes ?
	}
}

int do_rescue(string arg){
	object me;
	me = this_player();
	if(!arg || (arg != "yes" && arg != "no")){
		return 0;
	}	
	if (!query("doing_rescue"))		return 0;
	if (!me->query_temp("marks/hs_in_rescue"))	return 0;
		
	if(arg == "yes")
	{
		remove_call_out("reluctant");
        	me->ccommand("kill sun yuanchao");
        	me->delete_temp("marks/hs_in_rescue");
	} else if(arg == "no"){
		remove_call_out("reluctant");
		message("vision", me->name() + "�۹���һɨ�������Ϻ��ޱ��顣\n", environment(me), me);
		tell_object(me, "������²��ؼ������ǲ�Ҫ���ֵĺá�\n");
		me->delete_temp("marks/hs_in_rescue");
		me->delete("riddle/��ɽ����");
	}
	return 1;
}

/*
void reluctant(object me){
	if(!interactive(me) || environment(me) != this_object())
	{
		return;
	}
	message_vision("��Ů�����г�����ʧ����ĬĬ�ĵ�����ͷ��\n", me);
	if (!REWARD_D->check_m_success(me,"��ɽ����"))			
	{
		REWARD_D->riddle_done(me,"��ɽ����",-100,2);
	}
	return;
}*/

void check_rescue(object me){
	object fang;
	fang = present("fang girl", this_object());
	if(objectp(fang)){
		call_out("rescued", 2, me);
	}
}

void rescued(object me){
	object fang;
	if(!me || !interactive(me) || environment(me) != this_object()) {
		return;
	}
	fang = present("fang girl", this_object());
	if(objectp(fang)){
		if(me->query("age") < 25){
			message_vision("$N����$nǳǳһЦ��һ����Ʒ�����գ�����л��λ��������֮������\n", fang, me);
			message_vision("�Ա���Ůת��������ȥ���ߵ����ڣ���Ů���������������תͷ����$Nһ�ۡ�\n", me);
		} else {
			message_vision("$N��������л��λ��������֮������\n", fang, me);
			message_vision("�Ա���Ůת��������ȥ��\n", me);
		}
		
		if (REWARD_D->riddle_check(me,"��ɽ����"))
		{
			if (!REWARD_D->check_m_success(me,"��ɽ����"))			
			{
				REWARD_D->riddle_done(me,"��ɽ����",100,1);
			}
			if(!REWARD_D->imbue_check(me,"��ɽ����")){
				me->start_busy(3);
				call_out("imbue_event", 2, me);
			}
		} else
			me->delete("riddle/��ɽ����");
		destruct(fang);
	}
}

int imbue_event(object me){
	object weapon, ob, *inv, obj;
	string prop;
	int i;
	mapping data;
	
	if(!interactive(me) || environment(me) != this_object()) {
		return 0;
	}

	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(HIW"\nһ���ɫ��ӫ��Ӷ�������Ʈ�䣬���綬����ѩ����\n"NOR, me);
		} else {
			message_vision(HIW"\nһ���ɫ��ӫ��Ӷ�������Ʈ����$N��" + obj->name() +
					HIW"�ϣ�ת�ۼ�����ȥ��\n"NOR, me);
		}
	}else{
		message_vision(HIW"\nһ���ɫ��ӫ��Ӷ�������Ʈ����$N��" + weapon->name() + HIW"�ϡ�����\n"NOR,
				me);
		message_vision(HIW"ӫ���һ�Ӵ�" + weapon->name()+ HIW"һ��ҫ�۵Ĺ�âէ��Ѹ��һ���ֻع�ƽ����\n"NOR, me);
	}
	
	data = ([
		"name":		"��ɽ����",
		"target":	me,
		"att_1":	"kar",
		"att_1c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);	
	return 1;
}
